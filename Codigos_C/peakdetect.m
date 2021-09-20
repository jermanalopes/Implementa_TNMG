function [pospeakind,negpeakind]=peakdetect(signal,pospeak_treshold_bigger_than,pospeak_treshold_smaller_than,negpeak_treshold_bigger_than,negpeak_treshold_smaller_than,plot_results)

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

if nargin<6
    plot_results=0;
    if nargin<5
        negpeak_treshold_smaller_than=[];
        if nargin<4
            negpeak_treshold_bigger_than=[];
            if nargin<3
                pospeak_treshold_smaller_than=[];
                if nargin<2
                    pospeak_treshold_bigger_than=[];
                end
            end
        end
    end
end

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

%remove peaks that do no match the tresholds
if ~isempty(pospeak_treshold_smaller_than)
    pospeakind(signal(pospeakind)>pospeak_treshold_smaller_than)=[];
end
if ~isempty(pospeak_treshold_bigger_than)
    pospeakind(signal(pospeakind)<pospeak_treshold_bigger_than)=[];
end
if ~isempty(negpeak_treshold_smaller_than)
    negpeakind(signal(negpeakind)>negpeak_treshold_smaller_than)=[];
end
if ~isempty(negpeak_treshold_bigger_than)
    negpeakind(signal(negpeakind)<negpeak_treshold_bigger_than)=[];
end

%create a cell array for the case of multiple signals
% if nr_channels>1
%     nr_samples=size(signal,2);
%     [pp_row,pp_col] = ind2sub(size(signal),pospeakind);
%     [np_row,np_col] = ind2sub(size(signal),negpeakind);
%     for n=1:nr_channels;
%         pp{n}=pp_col(pp_row==n);
%         np{n}=np_col(np_row==n);
%     end
%     pospeakind=pp;
%     negpeakind=np;
% end

% if plot_results
%     tt=1:length(signal);
%     figure
%     plot(tt,signal)
%     hold on
%     plot(tt,signal,'.')
%     if nr_chanels==1
%         plot(tt(pospeakind),signal(pospeakind),'r.')
%         plot(tt(negpeakind),signal(negpeakind),'k.')
%     else
%         for n=1:nr_channels
%             plot(tt(pospeakind{n}),signal(n,pospeakind{n}),'r.')
%             plot(tt(negpeakind{n}),signal(n,negpeakind{n}),'k.')
%         end
%     end
end
