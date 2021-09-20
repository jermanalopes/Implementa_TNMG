function [vcg_peaks_pos,peak_threshold,vcg,vcg2]=ECG_peak_detect_mod(ecg,Fs)%,vcg_type)

if nargin<3
    vcg_type='simplified';
end
switch vcg_type
    case 'simplified'
        %the input ECG is a 3xN matrix, where is line is one derivation (I,II,III)
        if size(ecg,1)>4
            vcg= [ecg(1,:); -ecg(6,:)];
        else
            vcg=   [ecg(1,:); -(ecg(2,:)+ecg(3,:))*sqrt(3)/4;];
        end
    otherwise %FRANK VCG
        vcg = [+0.057 -0.019 -0.106 -0.022 +0.041 +0.048 -0.227 +0.887 ; ...
            +0.172 +0.074 -0.122 -0.231 -0.239 -0.194 -0.156 +0.010] ...
            * ecg([7 8 9 10 11 12 1 2],:) ;
end

vcg2= vcg(1,:).^2 + vcg(2,:).^2;
vcgd= diff(vcg2).^2; % differentiate and square
ref_period=300;
rps=ref_period/1000*Fs;

[vcg_peaks_pos] = peakdetect(vcgd);

vcgd_tmp=vcgd;
vcgd_tmp(vcgd_tmp<10^-4)=NaN;
d=round(length(vcgd_tmp)/3);
peak_threshold=[nanstd(vcgd_tmp(1:d)),...
nanstd(vcgd_tmp(d:(2*d))),nanstd(vcgd_tmp((2*d):end))]*2;
peak_threshold=min(peak_threshold(peak_threshold>1000));
if isempty(peak_threshold)
    peak_threshold=1000;
end
vcg_peaks_pos(vcgd(vcg_peaks_pos)<peak_threshold)=[];

okp=1;
while okp~=0
    dt=diff(vcg_peaks_pos);
    dv=diff(vcgd(vcg_peaks_pos));
    mask1=dt<rps;
    mask2=dv>0;
    mask3=[0 mask1(1:end-1)]==1;
    mask4=[1 mask2(1:end-1)]==0;
    okp=sum((mask1 & mask2) | (mask3 & mask4));
    vcg_peaks_pos((mask1 & mask2) | (mask3 & mask4))=[];
end

% remove vey low peaks and peaks at the very beginning and end of aquisition
% peak_threshold=(nanmedian(vcgd(vcg_peaks_pos))-peak_threshold)/3+peak_threshold;
% mask=vcgd(vcg_peaks_pos)<peak_threshold ...
%     | vcg_peaks_pos < Fs*ref_period/1000 ...
%     | vcg_peaks_pos > (length(vcgd)-Fs*ref_period/1000); 
%peak_threshold=(nanmedian(vcgd(vcg_peaks_pos))-peak_threshold)/3+peak_threshold;
mask= vcg_peaks_pos < rps ...
    | vcg_peaks_pos > (length(vcgd)-rps); 

vcg_peaks_pos(mask)=[];

% check if there is a double peak at the end of the acquisition
if length(vcg_peaks_pos)>1 
if (vcg_peaks_pos(end)-vcg_peaks_pos(end-1))<rps
    if vcgd(vcg_peaks_pos(end-1))>vcgd(vcg_peaks_pos(end))
        vcg_peaks_pos(end)=[];
    else
        vcg_peaks_pos(end-1)=[];
    end
end

% recenter the peaks as the peaks in VCG (note: peaks were found as peaks in the drivative)
rps2=round(rps/2);
mask=-rps2+1:rps2-1;
for i=1:length(vcg_peaks_pos)
   [~,pos]=max(vcg2(vcg_peaks_pos(i)+mask));
   vcg_peaks_pos(i)=vcg_peaks_pos(i)+pos-rps2;
end


end
end
