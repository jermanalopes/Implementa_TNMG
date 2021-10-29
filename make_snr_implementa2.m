

%% Leitura dos dados
pfolder = ['D:\Doutorado\SNR\Implementação_TNMG\Teste1_compara_Java_Matlab'];
load([pfolder '\exames_snr_teste1.mat']);   

[ud.B{1},ud.A{1},ud.ZI{1}] = my_butter_coeffs(1,300,'high');
[ud.B{2},ud.A{2},ud.ZI{2}] = my_butter_coeffs(1,500,'high');
[ud.B{3},ud.A{3},ud.ZI{3}] = my_butter_coeffs(1,600,'high');
[ud.B{4},ud.A{4},ud.ZI{4}] = my_butter_coeffs(1,1000,'high');

for n_samples=1:length(data)
    id_exam = data{1, n_samples}.exam_nr;
    resolution_microV = data{1, n_samples}.resolution_MicroV;
    fs=data{n_samples}.fs_Hz;
    ecg = data{n_samples}.ecg{1};
    [R_pos,SNR] = make_SNR(resolution_microV, fs, ecg)
end

