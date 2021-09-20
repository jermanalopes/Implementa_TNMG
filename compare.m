close all
clear all
clc


%%
pfolder = ('D:\Doutorado\SNR\Implementação_TNMG\Teste1_compara_Java_Matlab');
java = xlsread([pfolder '\resultado_SNR_JAVA_v2.csv']);
mat = xlsread([pfolder '\resultados_SNR_Matlab_v2.xls']);
lin=1;
lead = {};
dif = {};


%%
tam = size(mat(:,1));
for i=1:tam(1)
    id_mat = mat(i,1);
    amostra_mat = mat(i,2);
    teste_id = find(java(:,1) == id_mat);
    teste_amostra = find(java(teste_id,2) == amostra_mat);
    teste_amostra = teste_id(teste_amostra);

    for t=1:14
        lead{i,t} = (round(mat(lin,t+2))== round(java(teste_amostra,t+2))) || (round(mat(lin,t+2))== round(java(teste_amostra,t+2))+1);
        if(lead{i,t} == 1)
            dif{i,t} = 0;
        else
            dif{i,t} = (round(mat(lin,t+2)) - round(java(teste_amostra,t+2)));
    
        end
    end
    lin=lin+1;
end

arq_lead=cell2table(lead,'VariableNames',{ 'I', 'II', 'III',...
    'avL', 'avR', 'avF', 'V1','V2', 'V3', 'V4', 'V5', 'V6', 'SNR_Overall', 'SNR_Overall_Type'});
arq_dif=cell2table(dif,'VariableNames',{ 'I', 'II', 'III',...
    'avL', 'avR', 'avF', 'V1','V2', 'V3', 'V4', 'V5', 'V6', 'SNR_Overall', 'SNR_Overall_Type'});
%writetable(arq_total,['Teste1_SNR.xls']);
