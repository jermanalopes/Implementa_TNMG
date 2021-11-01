function [b,a,zi] = my_butter_coeffs(fc,fs,filter_type)
% since the function to generate the coefficients for a butterworth filter
% is quite complex and computetionally expensive, I replaced it with a
% switch/case condition that selecte the right coefficients depending on
% the sampling frequency of the signal (fs). The coeffients represent a 3rd
% order high-pass Butterworth filter with a cutoff requency of 0.4Hz (2.5
% sec).
% switch fs
%     case 300
%         b=[0.991657389432111;  -2.974972168296334;   2.974972168296334;  -0.991657389432111];
%         a=[ 1.000000000000000;  -2.983244888175193;   2.966629849266392;  -0.983384378015305];
%         zi=[ -0.991657388816874;   1.983314777644058;  -0.991657388827097];
%     case 500
%         b = [  0.994986058442272 ; -2.984958175326816 ;  2.984958175326816;  -0.994986058442272];
%         a =[   1.000000000000000 ; -2.989946914091736 ;  2.979944296951953 ; -0.989997256494488];
%         zi = [ -0.994986057554526;   1.989972115117976;  -0.994986057563406];
%     case 1000
%         b =[   0.997489880846521;  -2.992469642539564;   2.992469642539564 ; -0.997489880846521];
%         a =[   1.000000000000000;  -2.994973453077183 ;  2.989959531303781;  -0.994986062391207];
%         zi= [ -0.997489885639811;   1.994979771255529;  -0.997489885615778];
%     otherwise
%         error(['filter coefficients not available for sampling frequency of ' num2str(fs) ' Hz'])
% end
if nargin<3
    filter_type='low';
end
%this is the code for a matlab implementation that works with all fs
[b,a]=butter(3,fc/fs*2,filter_type);
b=b(:); a=a(:);
nfilt=length(a);
zi = [( eye(nfilt-1) - [-a(2:nfilt), [eye(nfilt-2); zeros(1,nfilt-2)]] ) \ ( b(2:nfilt) - b(1)*a(2:nfilt));0]; % NOTE eye is a function that creates an identity matrix;

end