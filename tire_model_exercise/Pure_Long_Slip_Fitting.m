%% Pure longitudinal slip conditions
% -------------------------------------

clc
clearvars 
close all   

% Set LaTeX as default interpreter for axis labels, ticks and legends
set(0,'defaulttextinterpreter','latex')
set(groot, 'defaultAxesTickLabelInterpreter','latex');
set(groot, 'defaultLegendInterpreter','latex');

set(0,'DefaultFigureWindowStyle','docked');
set(0,'defaultAxesFontSize',20)
set(0,'DefaultLegendFontSize',20)

% ------------------
%% Load the raw tyre data
% ------------------
load('B1464run30'); 

disp(testid)
disp(tireid)
%% Plot the data

%% Organize the data
%   1. create a vector of idxs dividing the dataset by parameters
for_mon = [FX FY FZ MZ];
slip = [SA SL];
%   2. Perfom some plot (es. k VS Fx for all Fz, with gamma = 0, alpha = 0)
figure
plot(SL,FX)
%% Execute the first fitting
%   1. Select the data alpha = 0, gamma = 0, Fz=Fz_nom
%   2. Write Pacejka MC and fit the data 
%   3. Get the parameter
%% Execute the second fitting
%   1. Select the data for Fz=change and gamma = 0
%   2. Fit the data using the previus parameters
%   4. Get the new parameters
%% Execute the third fitting
%   1. Select the data for Fz=change and gamma = change
%   2. Fit the data using the previus parameters
%   4. Get the last parameters