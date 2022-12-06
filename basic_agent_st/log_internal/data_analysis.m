clc
clear
close all

%% Load data
data = readtable("Example.csv");

%% Read data
time = table2array(data(:, 2));
vel = table2array(data(:, 3));
acc = table2array(data(:, 4));
phase = table2array(data(:, 5));

figure
tiledlayout(2,4)
nexttile([2 2])
hold on
plot(time, vel)
plot(time, phase, 'r')
xlabel 'time (s)'
ylabel 'velocity (km/h)'
title 'Velocity profile'
legend('velocity','TrafficLight')

% figure
%tiledlayout(2,1)
nexttile([2 2])
hold on
plot(time, acc)
plot(time, phase, 'r')
xlabel 'time (s)'
ylabel 'acceleration (m/s^2)'
title 'Acceleration profile'
legend('acceleration','TrafficLight')