function [vcg_peaks_pos,vcg]=R_peak_implementa(ecg,Fs)

if size(ecg,1)>4
   vcg= [ecg(1,:); -ecg(6,:)];
else
   vcg=   [ecg(1,:); -(ecg(2,:)+ecg(3,:))*sqrt(3)/4;];
end

vcg2= vcg(1,:).^2 + vcg(2,:).^2;
vcgd= diff(vcg2).^2; % differentiate and square
ref_period=300;
rps=ref_period/1000*Fs;

[vcg_peaks_pos] = peakdetect(vcgd);

vcgd_tmp=vcgd;
vcgd_tmp(vcgd_tmp<10^-4)=NaN;
d=round(length(vcgd_tmp)/3);
peak_threshold=[nanstd(vcgd_tmp(1:d)), nanstd(vcgd_tmp(d:(2*d))),nanstd(vcgd_tmp((2*d):end))]*2;
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
    mask3 = mask1(1:end-1);
    mask3 = [0 mask3];
    mask4 = ~mask2(1:end-1);
    mask4 = [1 mask4];
      
    part1 = zeros(1, length(mask1));
    part2 = zeros(1, length(mask1));
    part3 = zeros(1, length(mask1));
    for p=1:length(mask1)
        part1(p) = (mask1(p) && mask2(p));
        part2(p) = (mask3(p) & mask4(p));
        part3(p) = part1(p) || part2(p);
    end
    okp = sum(part3);
    o=1;
    for v=1:length(part3)
        if(part3(v) == 0)
            vcg_peaks_pos(o) = vcg_peaks_pos(v);
            o=o+1;
        else
            vcg_peaks_pos(o) = NaN;
            o=o+1;
        end
    end
    vcg_peaks_pos = vcg_peaks_pos(~isnan(vcg_peaks_pos));
end

% remove vey low peaks and peaks at the very beginning and end of aquisition
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
