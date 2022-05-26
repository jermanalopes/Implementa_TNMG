close all
clear all
clc

%% Leitura dos dados
path = fileparts(mfilename('fullpath'));    
path_database = ('D:\Doutorado\SNR\Database\Base5_produçãoTNMG');    

for base=1:4
d{1}= load([path_database '\base_prod_' num2str(base) '.mat']);
xls_table = {};
       
%% Calcula coeficientes do filtro Butterworth
[ud.B{1},ud.A{1},ud.ZI{1}] = my_butter_coeffs(1,300,'high');
[ud.B{2},ud.A{2},ud.ZI{2}] = my_butter_coeffs(1,500,'high');
[ud.B{3},ud.A{3},ud.ZI{3}] = my_butter_coeffs(1,600,'high');
[ud.B{4},ud.A{4},ud.ZI{4}] = my_butter_coeffs(1,1000,'high');
ud.nr_leads=12;
xls_table={};

%%
for n_samples=1:length(d{1}.data)
   id_exam = d{1}.data{n_samples}.exam_nr
   resolution_microV = d{1}.data{n_samples}.resolution_MicroV;
   fs=d{1}.data{n_samples}.fs_Hz;
   fltn=(fs==500)+1;
   if (fs == 1000); fltn=4; end
   if (fs == 600); fltn=3; end
   nan_int=round(0.5*fs);
   mask_nan=1:nan_int; 
   for tam=1:length(d{1}.data{n_samples}.ecg)
   ecg_tmp = zeros(size(d{1}.data{n_samples}.ecg{1,1})); 
   for der=1:ud.nr_leads % Aplica o filtro Butterworth com os coef. calculados em my_butter_coeffs
       signal = double(d{1}.data{n_samples}.ecg{1,tam}(der, :));
       signal = signal*resolution_microV;
       ecg_tmp(der,:)=myfiltfilt(ud.B{fltn},ud.A{fltn},signal',ud.ZI{fltn});
   end
   ecg_tmp(:,[mask_nan length(ecg_tmp)-mask_nan+1])=NaN; 
   [R_pos,vcg] = R_peak_implementa(ecg_tmp,fs); %calcula os picos em R
   [SNR]=average_beats_implementa(ecg_tmp,R_pos,fs); %calcula SNR
   d{1}.data{n_samples}.SNR=SNR;
   xls_table=[xls_table; [d{1}.data{n_samples}.exam_nr d{1}.data{n_samples}.acquisition{1,tam} ... 
                          num2cell(d{1}.data{n_samples}.SNR.median)'...
                          d{1}.data{n_samples}.SNR.overall d{1}.data{n_samples}.SNR.overall_type]]; 
   end
end
%% Salvando valores em arquivo .xls
arq = cell2table(xls_table);
arq_total=cell2table(xls_table,'VariableNames',{'exam_id', 'acquisition', 'I', 'II', 'III',...
    'avR', 'avL', 'avF', 'V1','V2', 'V3', 'V4', 'V5', 'V6', 'SNR_Overall', 'SNR_Overall_Type'});
writetable(arq_total,['resultados_base_' num2str(base) '.xls']);
end

% for n=1:12
% r = (d{1, 1}.data{1, 1}.ecg{1, 1}(n,:))' 
% % r = (ecg_tmp(1,:));
% % r = round(y,0)
% teste = regexprep(num2str(r'),'\s+',',')
% % intstr = num2str(round(d{1, 1}.data{1, 3}.ecg{1, 1}(1,:)),0);
% hashcode(teste)
% end
%    for n=1:12
%      r = ecg(n,:)' 
% %     r = (ecg_tmp(n,:))';
%     % r = round(y,0)
%     teste = regexprep(num2str(r'),'\s+',',')
%     hashcode(teste)
%     end
% intstr = num2str(round(beats_av(1,:),0))
% teste = regexprep(num2str(round(beats_av(1,:),0)),'\s+',',')
% clear arq;
% clear xls_table;
% clear d;
% 
% beep


