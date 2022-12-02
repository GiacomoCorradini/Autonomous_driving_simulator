clear 
close all
clc

T = 10;
dt = 0.05;
time = 1:dt:T;
v0 = 10;
a0 = -0.05;
sf = 100;

[m_star, tf, smax] = stop_primitive(v0,a0,sf);

velocity = zeros(1,T);
for i = 1:T
    velocity(:,i) = v_opt(dt,v0,a0,smax,0,0,tf);
end
%% Plot

figure, clf, hold on;
plot(1:T, velocity);
