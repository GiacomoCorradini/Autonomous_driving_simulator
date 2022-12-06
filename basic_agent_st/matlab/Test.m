clear 
close all
clc

T = 100;
dt = 0.5;
time = 1:dt:T;
v0 = 10;
a0 = 0.5;
sf = 100;

[m_star, tf, smax] = stop_primitive(v0,a0,sf);

%[] = pass_primitive(a0,v0,sf,3,13,)

velocity = zeros(1,length(time));
space = zeros(1,length(time));

for i = 1:length(time)+2
    t = i*dt - 1;
    space(:,i) = m_star(2)*t + 1/2*m_star(3)*t^2 + 1/6 * m_star(4) * t^3 + 1/24 * m_star(5) * t^4 + 1/120 * m_star(6) * t^5;
    velocity(:,i) = m_star(2) + m_star(3)*t + 1/2 * m_star(4) * t^2 + 1/6 * m_star(5) * t^3 + 1/24 * m_star(6) * t^4;
end

%% Plot

figure, clf, hold on;
plot(space, velocity');
