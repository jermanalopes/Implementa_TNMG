function [pospeakind]=peakdetect(signal)

% find negative and positive peaks in a singal, and return their location
% the input can be a matrix of mutliple signal with each row corresponding
% to a singal. In this case the output is a cell vector with the output
% pospeak{i} and negpeak{i} being the location of positive and negative
% peaks in the signal corresponding to the i-th row of the input matrix

% TRESHOLD: a treshold can be set for the peaks: [bigger_than smaller_than].
% If only one value is inputed, this is taken as a "bigger_than for positive peaks
% and a "smaller_than" for negative peaks. If this paramter is
% missinng or set as empty, no treshold is applied

%NOTE - handling the case of a series of samples with the same value:
%an arbitrary choice is made to mark only the first sample of such series as a peak
if min(size(signal))==1
    signal=signal(:)';
    nr_channels=1;
else
    nr_channels=size(signal,1);
end
dsdx=[zeros(nr_channels,1) diff(sign(diff(signal,1,2)),1,2)];
ddsdx=[zeros(nr_channels,1) diff(dsdx,1,2)];

%peak detection
pospeakind=find(dsdx<0&~(ddsdx==0));
negpeakind=find(dsdx>0&~(ddsdx==0));
end
