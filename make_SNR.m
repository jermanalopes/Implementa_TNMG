function [R_pos,SNR]=make_SNR(resolution_microV, fs, ecg) 
   nr_leads=12;
   fltn=(fs==500)+1;
   if (fs == 1000); fltn=4; end
   if (fs == 600); fltn=3; end
   nan_int=round(0.5*fs);
   mask_nan=1:nan_int; 
   ecg_tmp = zeros(size(ecg)); 
   for der=1:nr_leads % Aplica o filtro Butterworth com os coef. calculados em my_butter_coeffs
       signal = double(ecg(der,:));
       signal = signal*resolution_microV; 
%        ecg_tmp(der,:)=myfiltfilt(ud.B{fltn},ud.A{fltn},signal',ud.ZI{fltn});
   end
   ecg_tmp(:,[mask_nan length(ecg_tmp)-mask_nan+1])=NaN; 
   R_pos = 0;
   SNR = 0;
%    [R_pos,thr,vcg] = ECG_peak_detect_mod_with_derivative(ecg_tmp,fs); %calcula os picos em R
%    [beats,beats_av,group,offset,beats_vcg,beats_vcg_av,SNR,R_pos]=average_beats_v5(ecg_tmp,R_pos,fs,vcg); %calcula SNR
end

