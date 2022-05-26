

%% Leitura dos dados
pfolder = ['D:\Doutorado\SNR\Implementação_TNMG\Teste1_compara_Java_Matlab'];
load([pfolder '\exames_snr_teste1.mat']);   
xls_table = {};
for n_samples=1:length(data)
    id_exam = data{1, n_samples}.exam_nr;
    acquisition = data{n_samples}.acquisition(1);
    resolution_microV = data{1, n_samples}.resolution_MicroV;
    fs=data{n_samples}.fs_Hz;
    ecg = data{n_samples}.ecg{1};
    [R_pos,SNR] = make_SNR(resolution_microV, fs, ecg);
     xls_table=[xls_table; [id_exam acquisition num2cell(SNR.median)' SNR.overall ... 
                SNR.overall_type]]; 
end
arq_total=cell2table(xls_table,'VariableNames',{'exam_id', 'acquisition', 'I', 'II', 'III',...
    'avR', 'avL', 'avF', 'V1','V2', 'V3', 'V4', 'V5', 'V6', 'SNR_Overall', 'SNR_Overall_Type'});
writetable(arq_total,['resultados_SNR_Matlab_v4.xls']);


