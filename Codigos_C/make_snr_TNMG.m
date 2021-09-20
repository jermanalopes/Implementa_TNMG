
%% Leitura dos dados
mfile=matlab.desktop.editor.getActiveFilename;%this m file folder(directory) with its m file name
[mfolder, ~, ~] = fileparts(mfile);% this m file directory
cd(mfolder)% change this m file directory

for N=1:1

pfolder = ('D:\Doutorado\SNR\Implementação_TNMG\Teste1_compara_Java_Matlab');
d{N}= load([pfolder '\exames_snr_teste1.mat']);
        
%% Calcula coeficientes do filtro Butterworth
%% Calcula coeficientes do filtro Butterworth
[ud.B{1},ud.A{1},ud.ZI{1}] = my_butter_coeffs(1,300,'high');
[ud.B{2},ud.A{2},ud.ZI{2}] = my_butter_coeffs(1,500,'high');
[ud.B{3},ud.A{3},ud.ZI{3}] = my_butter_coeffs(1,600,'high');
[ud.B{4},ud.A{4},ud.ZI{4}] = my_butter_coeffs(1,1000,'high');
ud.nr_leads=12;
xls_table={};
media_AVF = [];


%% Tratamento do sinal ecg por paciente (Filtro, picos, SNR)
value_SNR_type = 10*ones(length(d{N}.data), 4);
for n_samples=1:length(d{N}.data)
   %tic
   resolution_microV = d{N}.data{n_samples}.resolution_MicroV; %resolução do aparelho medição
   fs=d{1}.data{n_samples}.fs_Hz;
   fltn=(fs==500)+1;
   if (fs == 1000); fltn=4; end
   if (fs == 600); fltn=3; end
   nan_int=round(0.5*fs);
   mask_nan=1:nan_int; %Criação mascara para eliminação do sinal no início
   ecg_tmp = zeros(size(d{N}.data{n_samples}.ecg{1,1}));    
   for der=1:ud.nr_leads % Aplica o filtro Butterworth com os coef. calculados em my_butter_coeffs
       signal = double(d{N}.data{n_samples}.ecg{1,1}(der,:));
       signal = signal*resolution_microV; %Resolução do sinal
       ecg_tmp(der,:)=myfiltfilt(ud.B{fltn},ud.A{fltn},signal',ud.ZI{fltn});
   end
  ecg_tmp(:,[mask_nan length(ecg_tmp)-mask_nan+1])=NaN; %Elimina os 150 primeiros e ultimos valores
  [R_pos,thr,vcg] = ECG_peak_detect_mod_with_derivative(ecg_tmp,fs); %calcula os picos em R
  [SNR_overall, SNR_overall_type] = average_beats_tnmg(ecg_tmp,R_pos,fs,vcg);
end
end


