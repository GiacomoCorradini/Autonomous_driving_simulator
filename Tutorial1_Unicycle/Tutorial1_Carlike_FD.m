clear all
close all
clc

%% TIME

Tmin = 0;
Tmax = 1;
Tsample = 1e-3;
vec_t = Tmin:Tsample:Tmax;


%% MODEL DATA INPUT

d = 0.135;      % distance between wheels
r = 0.11;       % radius
D = 0.5;
l = 3;

Qi = [3 3 pi/3 0];    % initail condition [x, y, theta]
Qf = [0 0 0 0];       % final condition [x, y, theta]




%% PATH PLANNING

x(1) = Qi(1);
y(1) = Qi(2);
theta(1) = Qi(3);
phi(1) = Qi(4);




% %%%%%%%%%%%%%%%%%%%%%%%%%%%%
% % PATHPLANNING 1 - INPUT DATA
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%
x_sample = 0.1; %m
y_sample = x_sample;
%theta_t = Qf(3)-Qi(3);

if Qi(1)>Qf(1), 
  x = fliplr(Qf(1):x_sample:Qi(1)); 
else x = Qi(1):x_sample:Qf(1);
end
if Qi(2)>Qf(2), 
  y = fliplr(Qf(2):y_sample:Qi(2)); 
else y = Qi(2):y_sample:Qf(2);
end
figure, hold on, grid on
plot(x,y,'.')
plot(x(end),y(end),'r*')

%Compute global RF velocities
xdot = [diff(x) 0];
ydot = [diff(y) 0];
%theta_dot = atan(ydot./xdot);
theta = atan2(y,x);
phi_dot = atan2(ydot,xdot);

v = sqrt(xdot.^2+ydot.^2);
omega = phi_dot;

vec_ud(:,1) = v; % linear velocity
vec_ud(:,2) = omega; %angular velocity

figure, hold on, grid on
plot(x,y,'.')
plot(x(end),y(end),'r*')

%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% PATHPLANNING 2 - INPUT DATA
%%%%%%%%%%%%%%%%%%%%%%%%%%%%

[vec_ud,x,y,phi] = ClotoidPath(Tmin, Tmax, Tsample, Qi, Qf);
%figure, plot(rad2deg(z2d)), axis equal
figure, hold on, grid on
plot(x,y,'.')
plot(x(end),y(end),'r*')





%% SIMULATION WITH THE MODEL
%(if available this inputs are inputs for the hardware)
%theta = Qf(3); %condizione iniziale 
% x_dot = [];
% y_dot = [];
% theta_dot = [];
% x_model = x(1);
% y_model = y(1);
% theta_model = theta(1); 
% v_model = [];
% w_model = [];

x_dot     = cos(theta(1))*cos(phi(1))*vec_ud(1,1);
y_dot     = sin(theta(1))*cos(phi(1))*vec_ud(1,1);
theta_dot = 1/l * sin(phi(1));
phi_dot   = vec_ud(1,2);

x_model = [x(1) x_dot(1)+x(1)];
y_model = [y(1) y_dot(1)+y(1)];
theta_model = [theta(1) theta_dot(1)+theta(1)];
phi_model = [phi(1) phi_dot(1)+phi(1)]; 

v_model = [];
w_model = [];

for i = 2:length(vec_ud)-2
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % NominalSTATE evolution
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %Unicycle Model
    %[   xdot   ]   [ cos(theta)     0 ]  [  v  ]
    %[   ydot   ] = [ sin(theta)     0 ]  [omega]
    %[ thetadot ]   [     0          1 ]
    %Equivalently:
    %[xdot, ydot, thetadot] = [cos(theta) sin(theta) 0]' * v + [0 0 1]' * omega;
    %Better...
    x_dot(i)     = cos(theta(i))*cos(phi(i))*vec_ud(i,1);
    y_dot(i)     = sin(theta(i))*cos(phi(i))*vec_ud(i,1);
    theta_dot(i) = 1/l * sin(phi(i))*vec_ud(i,1);
    phi_dot(i)   = vec_ud(i,2);

    
   

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %Time integration
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %Rectangular integration:
    x_model(i+1) = x_dot(i)*Tsample + x_model(i);
    y_model(i+1) = y_dot(i)*Tsample + y_model(i);
    theta_model(i+1) = theta_dot(i)*Tsample + theta(i); 
    phi_model(i+1) = phi_dot(i)*Tsample + phi_model(i);
    %Do you know a better integration approach?         
    %   What is written is the rectangular method. Runge-Kutta methods order 6 is better fro
    %   robotics
    
    %MOREOVER, it is possibile to integrate in the model the differential
    %drive:
    %
    % write it here...
    %
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % COMPUTE INVERSE INPUTS (CHECK): Nominal linear and angular velocity - Input
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%
    v_model(i) = sqrt(x_dot(i)^2+y_dot(i)^2);
    w_model(i) = theta_dot(i);
    
end

%% Vizualization

figure, hold on, grid on
plot(x_model,y_model,'.')
plot(x_model(end),y_model(end),'r*')
    
%% Viz Err


%% TRAJECTORY ERROR

e_t = [x(1:end-2-1) - x_model(3:end);...
       y(1:end-2-1) - y_model(3:end)];

figure, hold on, grid on
%subplot(1,2,1),
plot(e_t(1,:)); hold on
%subplot(1,2,1),
plot(e_t(2,:),'r');
legend('x Error','y Error','Location','Best')
title('Nominal Trajectory Error')



figure, hold on, grid on
%subplot(1,2,1),
plot(e_t(1,:),e_t(1,:));
legend('Scatter','Location','Best')
title('Position Error')


% vec_ud_error_t = [vec_ud(:,1) - v_model;...
%                   vec_ud(:,2) - w_model];
% figure, hold on, grid on, plot(vec_ud(:,1)),plot(v_model)
% figure, hold on, grid on, plot(vec_ud(:,2)),plot(w_model)


%% Rewrite the code and apply t to the case of a car-like !

