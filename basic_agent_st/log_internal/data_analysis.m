clc
clear
close all

%% Load data
data = readtable("Example1.csv");

%% Read data
time = table2array(data(:,2));
vel_0 = table2array(data(:,3));
acc_0 = table2array(data(:,4));
phase = table2array(data(:,5));
vel_req = table2array(data(:,6));
acc_req = table2array(data(:,7));
t_green = table2array(data(:,8));
t_red = table2array(data(:,9));
TrfLightDist = table2array(data(1,12)) - table2array(data(:,12));

%% Time domain
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
nexttile([2 2])
hold on
plot(time, acc_0)
plot(time, acc_req)
plot(time, phase, 'r')
xlabel 'time (s)'
ylabel 'acceleration (m/s^2)'
title 'Acceleration profile'
legend('acceleration init','acceleration req','TrafficLight')

%% Space domain
figure
tiledlayout(2,4)
nexttile([2 2])
hold on
plot(TrfLightDist, vel_0)
plot(TrfLightDist, vel_req)
plot(TrfLightDist, phase, 'r')
xlabel 'time (s)'
ylabel 'velocity (km/h)'
title 'Velocity profile'
legend('velocity init','velocity req','TrafficLight')
nexttile([2 2])
hold on
plot(TrfLightDist, acc_0)
plot(TrfLightDist, acc_req)
plot(TrfLightDist, phase, 'r')
xlabel 'time (s)'
ylabel 'acceleration (m/s^2)'
title 'Acceleration profile'
legend('acceleration init','acceleration req','TrafficLight')