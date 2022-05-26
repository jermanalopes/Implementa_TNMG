close all
clear all
clc

%% Caminhos
path = fileparts(mfilename('fullpath'));
path_dados = [path '\v2_compara_C_Matlab'];

%% Ler dados
dados = readtable([path_dados '\derivacoes_snr.csv']);
tam = size(dados);
num =1;

%% converter dados para .mat
% for j=1:2500:tam(1)
% t = dados(j(1):j+2500-1,:);  
t = dados(47502:50330,:);  
num=20;
tam2 = size(t);
for n_samples=1:tam2(1)
    ecg = [];
    data{1, n_samples}.exam_nr = table2array(t(n_samples, 2));
    data{1, n_samples}.amp =  table2array(t(n_samples, 5));
    data{1, n_samples}.ecg_channel = {'I','II','III','avL','avR','avF','V1','V2','V3','V4','V5','V6'};
    data{1, n_samples}.resolution_MicroV = table2array(t(n_samples, 10));
    data{1, n_samples}.speed_mms = table2array(t(n_samples, 12));
    data{1, n_samples}.acquisition = table2array(t(n_samples, 8));
    data{1, n_samples}.fs_Hz = table2array(t(n_samples, 11));
    for der=1:12
    split_der = regexp(table2array(t(n_samples, der+12)), ';', 'split');
    ecg(der,:) = str2double(split_der{:});
    end
    data{1, n_samples}.ecg = ecg;
% end
beep
end
save(['base_prod_' num2str(num) '.mat'], 'data');
% num =num+1;
% end