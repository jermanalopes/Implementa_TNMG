function [converte] = hashcode(s) 

% s = '0'; 
md5hasher = System.Security.Cryptography.HashAlgorithm.Create('MD5');
md5 = uint8(md5hasher.ComputeHash(uint8(s)));
t = (dec2hex(md5));
k=1;
for j =1:16
    for i=1:2
converte(k) = (t(j,i));
k=k+1;
    end
end
end
