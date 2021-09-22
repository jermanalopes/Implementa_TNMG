% LIB_AVERAGE_BEATS_TNMG_SCRIPT   Generate MEX-function average_beats_tnmg_mex
%  from average_beats_tnmg, ECG_peak_detect_mod_with_derivative, my_butter_coeffs,
%  myfiltfilt, peakdetect.
% 
% Script generated from project 'lib_average_beats_tnmg.prj' on 21-Sep-2021.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('mex');
cfg.GenerateReport = true;
cfg.EnableJIT = true;

%% Define argument types for entry-point 'average_beats_tnmg'.
ARGS = cell(5,1);
ARGS{1} = cell(4,1);
ARGS{1}{1} = coder.typeof(0,[12 Inf],[0 1]);
ARGS{1}{2} = coder.typeof(0,[1 Inf],[0 1]);
ARGS{1}{3} = coder.typeof(0);
ARGS{1}{4} = coder.typeof(0,[2 Inf],[0 1]);

%% Define argument types for entry-point 'ECG_peak_detect_mod_with_derivative'.
ARGS{2} = cell(2,1);
ARGS{2}{1} = coder.typeof(0,[12 Inf],[0 1]);
ARGS{2}{2} = coder.typeof(0);

%% Define argument types for entry-point 'my_butter_coeffs'.
ARGS{3} = cell(3,1);
ARGS{3}{1} = coder.typeof(0);
ARGS{3}{2} = coder.typeof(0);
ARGS{3}{3} = coder.typeof('X',[1 4]);

%% Define argument types for entry-point 'myfiltfilt'.
ARGS{4} = cell(4,1);
ARGS{4}{1} = coder.typeof(0,[4 1]);
ARGS{4}{2} = coder.typeof(0,[4 1]);
ARGS{4}{3} = coder.typeof(0,[Inf  1],[1 0]);
ARGS{4}{4} = coder.typeof(0,[3 1]);

%% Define argument types for entry-point 'peakdetect'.
ARGS{5} = cell(6,1);
ARGS{5}{1} = coder.typeof(0,[1 Inf],[0 1]);
ARGS{5}{2} = coder.typeof(0);
ARGS{5}{3} = coder.typeof(0);
ARGS{5}{4} = coder.typeof(0);
ARGS{5}{5} = coder.typeof(0);
ARGS{5}{6} = coder.typeof(0);

%% Invoke MATLAB Coder.
codegen -config cfg -o average_beats_tnmg_mex average_beats_tnmg -args ARGS{1} ECG_peak_detect_mod_with_derivative -args ARGS{2} my_butter_coeffs -args ARGS{3} myfiltfilt -args ARGS{4} peakdetect -args ARGS{5}

