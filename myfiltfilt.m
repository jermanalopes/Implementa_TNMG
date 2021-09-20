function y =myfiltfilt(b,a,y,zi)
% all inputs MUST be column vectors

nfact = 3*(length(a)-1);
y_or = y;
% Cria uma versão expandida em 2*nfact
%teste = [2*y(1)-y(nfact+1:-1:2); y; 2*y(end)-y(end-1:-1:end-nfact)];
y = [2*y(1)-y(nfact+1:-1:2); y; 2*y(end)-y(end-1:-1:end-nfact)];
y = double(y);
% Filtra, espelha os dados e filtra novamente
y = myfilter(b,a,y,round(zi,4)*y(1));
y = y(end:-1:1);
y = myfilter(b,a,y,round(zi,4)*y(1));

% Retorna o tamanho original de y - Elimina os nfact adiconados
y = y(end-nfact:-1:nfact+1);
end

function Y = myfilter(b, a, X, z)
% all inputs MUST be column vectors
n    = length(a);
z(n) = 0;      % Creates zeros if input z is omitted
Y    = zeros(size(X));
for m = 1:length(Y)
   Y(m) = round(b(1),4) * round(X(m),4) + round(z(1),4);
   for i = 2:n
      z(i - 1) = round(b(i),4) * round(X(m),4) + round(z(i),4) - round(a(i),4) * round(Y(m),4);
   end
end
end