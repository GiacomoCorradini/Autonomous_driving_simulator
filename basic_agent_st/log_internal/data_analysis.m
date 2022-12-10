clc
clear
close all

%% Load data
data = readtable("Example.csv");

%% Read data
time = table2array(data(:, 2));
vel_0 = table2array(data(:, 3));
acc_0 = table2array(data(:, 4));
phase = table2array(data(:, 5));
vel_req = table2array(data(:, 6));
acc_req = table2array(data(:, 7));

figure
tiledlayout(2,4)
nexttile([2 2])
hold on
plot(time, vel_0)
plot(time, vel_req)
plot(time, phase, 'r')
xlabel 'time (s)'
ylabel 'velocity (km/h)'
title 'Velocity profile'
legend('velocity init','velocity req','TrafficLight')

% figure
%tiledlayout(2,1)
nexttile([2 2])
hold on
plot(time, acc_0)
plot(time, acc_req)
plot(time, phase, 'r')
xlabel 'time (s)'
ylabel 'acceleration (m/s^2)'
title 'Acceleration profile'
legend('acceleration init','acceleration req','TrafficLight')