string = 'olamundo'; 
md5hasher = System.Security.Cryptography.HashAlgorithm.Create('MD5');
md5 = uint8(md5hasher.ComputeHash(uint8(string)));
t = (dec2hex(md5))
k=1
for j =1:16
    for i=1:2
converte(k) = (t(j,i))
k=k+1;
    end
end
M2Str = sprintf("%d, ",t(1:end-1)) + string(t(end))
