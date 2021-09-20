function [beats,beats_av,group,offset,beats_vcg,beats_vcg_av,SNR,R_pos]=average_beats_v5(ecg,R_pos,fs,vcg) 
if nargin<6, max_delay_correction=9; % [in ms] zero if you do not want to correct
if nargin<6, SNR_threshold=4.5; % threshold used to define if a lead signal is noisy or not
end
end
if length(R_pos)<2
    beats=[];
    beats_av=[];
    group=[];
    offset=[];
    beats_vcg=[];
    beats_vcg_av=[];
    SNR.overall=0;
%     SNR.overall_type=2
    SNR.overall_type=1;
    SNR.median=zeros(size(ecg,1),1);
    SNR.hrv=NaN;
    return
end

%% Seta valores iniciais de offset (baseado na mediana dos picos R)
tam_R=length(R_pos);
mediana_R=round(median(diff(R_pos))*1.1);
offset=round(mediana_R/3);
beats=NaN.*zeros(tam_R,size(ecg,1),mediana_R);
beats_vcg=NaN.*zeros(tam_R,2,mediana_R);
R_PosAtual=[R_pos length(ecg)]; %Acrescenta o length ao R_Pos
group=ones(1,tam_R);
int0 =0:(mediana_R-1);

%% Seleciona em torno das posições de Picos R, int intervalos (valores) para as 12 derivações - ECG e VCG
% Cálculo dos picos R para o sinal ECG e VCG de cada uma das 12 derivações
for i=1:tam_R
    int=R_PosAtual(i)+int0-offset+1; %Pega (int) valores de pos. em torno da pos. do R
    int(int>(R_PosAtual(i+1)-offset/20) | int<1)=[]; %coloca nan para valores maiores que o valor definido
    beats(i,:,1:length(int))=ecg(:,int); %Para cada R de cada derivação (pega int valores proximos a R) - ECG
    beats_vcg(i,:,1:length(int))=vcg(:,int); %Para cada R (pega int valores proximos para cada derivação) - VCG
end
%% Calcula beats_av - batimentos médios em relação a beats 
% Calcula o batimento médio do ECG
beats_av=zeros(size(ecg,1),mediana_R);
beats_vcg_av=zeros(2,mediana_R);
s=size(ecg);
for i=1:s(1)
     beats_av(i,:)=nanmedian(squeeze(beats(:,i,:)));
     %Calcula a mediana de cada derivação nos R picos detectados da derivação
     %mas em torno dos int valores do pico R 
end

%% check if there is an offset in beat detections
%%% Analisar a diferença entre a potência do sinal (beats - beats_av)
if max_delay_correction 
    beat_modified=false;
    mdc=round(max_delay_correction./fs*1000);
    for i=1:tam_R
        err=+inf;
        pos=0;
        for j=1:mdc %Calcula a diferença ao quadrado de beats e beats_av
            %err1 = Diferença ao ² entre beats e beats_av das 3 Derivações em um deslocamento de
            %janela tamanho mdc - Elimina os NaN iniciais e finais
%             errteste(j)= nanmean(nanmean((squeeze(beats(i,1:3,j:end))-beats_av(1:3,1:(end-j+1))).^2,2));
            err1=nanmean(nanmean((squeeze(beats(i,1:3,j:end))-beats_av(1:3,1:(end-j+1))).^2,2));
            %err2 = err1 - inverte o deslocamento da janela mdc
            err2=nanmean(nanmean((squeeze(beats(i,1:3,1:(end-j+1)))-beats_av(1:3,j:end)).^2,2));
            if err1<err, err=err1; pos=(j-1); end %Guarda a pos da janela mdc para o menor erro
            if err2<err, err=err2; pos=-(j-1); end 
        end
        if pos %atualiza o tamanho do int
        int=R_PosAtual(i)+pos+int0-offset;
        int(int>(R_PosAtual(i+1)-offset/20) | int<1)=[]; %coloca nan para valores maiores que o valor definido
        beats(i,:,1:length(int))=ecg(:,int);
        beats_vcg(i,:,1:length(int))=vcg(:,int);
        beat_modified=true;
        R_pos(i)=R_pos(i)+pos;
        end
    end
    if beat_modified  % Recalcular o valor da mediana dos batimentos para o novo intervalo
        for i=1:s(1)
           beats_av(i,:)=nanmedian(squeeze(beats(:,i,:)));
        end
    end
end

%% redefine average after discarding bad beats and define groups of beats

% Diferença entre 
beats_av_var=nanvar(beats_av,[],2); %Calcula variância de beats_av por derivação dos int valores
err=zeros(size(ecg,1),tam_R);
for i=1:tam_R
    b=squeeze(beats(i,:,:)); %Por pico R - Pega os int valores das 12 Derivações
    err(:,i)=nanmean((b-beats_av).^2,2);
    %in the following lines I am assuming that the ECG is in millivolts    
    %Analisa os 6 valores iniciais do erro e compara com os valores dos
    %beats_av_var. Se tiver mais de 3 valores maiores 
    group(i)= double(sum(err(1:6,i)<beats_av_var(1:6))>3 & sum(nanvar(b(1:6,2),[],2)<10^4)>3); %% testar b(1:6,2)
%     if(sum(nanvar(b(1:6,:),[],2)<10^4)>3)
%     teste=1;
%     end
    if(group(i)==0)
        group(i)
    end
end
for i=1:s(1)
     beats_av(i,:)=nanmedian(squeeze(beats(group==1,i,:)));
end

%% compute SNR 
% the overall_type field has the following meaninig:
% 0 = good ecg recording
% 1 = bad ecg recording due to overall poor quality
% 2 = bad 0ecg recording due to many leads having very poor quality 
% 3 = bad ecg recording due to large part of tracing being without signal

length_thr=0.35; % max fraction of the tracing that I accept to be a flat line 
%mudança
very_bad_lead_max_nr=3; % maximum number of VERY bad leads (i.e SNR<SNR_threshold/3) that I can accept

%% SNR.overall_type = 2 - Falta de tra�ado em algumas derivações
% A diferença do ultimo R com o primeiro divido pelo total < 0.35
if (R_pos(end)-R_pos(1))/sum(~isnan(ecg(1,:)))<length_thr
    SNR.median=zeros(size(beats_av,1),1);
    SNR.overall=0;
    SNR.overall_type=3;
    %SNR.overall_type=1; 
else
    err=zeros(size(ecg,1),tam_R);%Zera os erros e recalcula
    for i=1:tam_R %Calcula a média da diferença entre beats e beats_av
        err(:,i)=nanmean((squeeze(beats(i,:,:))-beats_av).^2,2);
    end
    %Calculo SNR 
    SNR.median=nanvar(beats_av,[],2)./nanmedian(err(:,group==1),2);
    SNR.median(isnan(SNR.median))=0; %NaN ? flat line
    der_nulas = (SNR.median<=0.20);
    if length(SNR.median)==12 %Verifica se o exame ta completo
        % compute median giving more weight to DI DII and AVf
        important_leads=[1; 2; 6];
    else
        important_leads=[];
    end

%% Cálculo SNR.overall type 0, 1 e 3
    SNR.overall=median([SNR.median; SNR.median(important_leads)]);% Coloca como relevante das derivações (1, 2, 6)
    SNR.overall_type=double(SNR.overall<SNR_threshold); %0 means good 1 means bad quality. SNR_threshold definido no inicio e = 7
    very_bad_lead=SNR.median<(SNR_threshold/3);
    if (sum(very_bad_lead)> very_bad_lead_max_nr || (very_bad_lead(2)) || (very_bad_lead(1) && very_bad_lead(6)) || sum(der_nulas)>=1)  
        SNR.overall=0;
        SNR.overall_type=2;  
        %SNR.overall_type=1; 
    end
end
SNR.hrv=std(diff(R_pos)./fs)*1000;

%% compute average vcg
beats_vcg_av(1,:)=nanmedian(squeeze(beats_vcg(:,1,:)));
beats_vcg_av(2,:)=nanmedian(squeeze(beats_vcg(:,2,:)));

end





% 
%% teste
% x = ecg(1,1:700);
% figure
% set(0,'defaulttextinterpreter','latex')
% subplot(2,2,[1,2]);
% plot(x, 'k')
% title('Lead I (700 samples)', 'FontSize',12);
% ylabel('Amplitude (uV)', 'FontSize',12);
% xlabel('Samples number', 'FontSize',12);
% 
% hold on
% R_pos1 = R_pos(1:2);
% plot(R_pos1, x(:,R_pos1), '*r')
% subplot(2,2,3);
% y = squeeze(beats(1,1,:))
% plot(y, '-k')
% title('Beat 1( 300 samples)', 'FontSize',12);
% ylabel('Amplitude (uV)', 'FontSize',12);
% xlabel('Samples number', 'FontSize',12);
% 
% subplot(2,2,4);
% y = squeeze(beats(2,1,:))
% plot(y, '-k')
% title('Beat 2( 300 samples)', 'FontSize',12);
% ylabel('Amplitude (uV)', 'FontSize',12);
% xlabel('Samples number', 'FontSize',12);
% 
% set(gcf,'renderer','Painters')
% print -depsc -tiff -r300 -painters beatselect.eps
% 
% 



