function [R_pos,SNR]=make_SNR(resolution_microV, fs, ecg) 
  A = cell(1, 4); 
  B = cell(1, 4); 
  ZI = cell(1, 4); 
  [B{1},A{1},ZI{1}] = my_butter_coeffs(1,300,'high');
  [B{2},A{2},ZI{2}] = my_butter_coeffs(1,500,'high');
  [B{3},A{3},ZI{3}] = my_butter_coeffs(1,600,'high');
  [B{4},A{4},ZI{4}] = my_butter_coeffs(1,1000,'high');
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
       ecg_tmp(der,:)= signal;
       ecg_tmp(der,:)=myfiltfilt(B{fltn},A{fltn},signal',ZI{fltn});
  end
  ecg_tmp(:,[mask_nan length(ecg_tmp)-mask_nan+1])=NaN; 
  [R_pos,vcg] = R_peak_implementa(ecg_tmp,fs); %calcula os picos em R
  [SNR]=average_beats_implementa(ecg_tmp,R_pos,fs); %calcula SNR
end

