clear all
close all
clc

%% DATA

d = 0.135;
r = 0.11;
D = 0.5;

Tmin = 0;
Tmax = 1;
Tsample = 1e-3;

vec_t = Tmin:Tsample:Tmax;

Qi = [3 3 pi/3];
Qf = [0 0 0];

% Perturbation Data
amplitude = 100;
variance = 250;
Hi = 100;
Hf = 150;

%% PLANNING

x(1) = Qi(1);
y(1) = Qi(2);
theta(1) = Qi(3);

x_pert(1) = Qi(1);
y_pert(1) = Qi(2);
theta_pert(1) = Qi(3);

% % Perturbation Vector
% vec_pert = amplitude.*rand(size(vec_t,2),2);

% Gaussian Noise
vec_pert = normrnd(0, sqrt(variance), size(vec_t,2), 2);

% % Hit
% vec_pert(1:Hi) = 0;
% vec_pert(Hf:end) = 0;

% Desired Inputs
[vec_ud,z1d,z3d,z2d] = ClotoidPath(Tmin, Tmax, Tsample, Qi, Qf);

for i = 1:length(vec_ud)
% Nominal ==========================================================================
    x_dot(i) = cos(z2d(i))*vec_ud(i,1);
    y_dot(i) = sin(z2d(i))*vec_ud(i,1);
    theta_dot(i) = vec_ud(i,2);
    
    x(i+1) = x_dot(i)*Tsample + x(i);               
    y(i+1) = y_dot(i)*Tsample + y(i);          
    theta(i+1) = theta_dot(i)*Tsample + theta(i); 
    
    % Nominal Input
    v_d(i) = sqrt(x_dot(i)^2+y_dot(i)^2);
    w_d(i) = theta_dot(i);
    
% Perturbated ======================================================================
    % Apply perturbation on velocities
    vec_up = vec_ud + vec_pert;
    
    x_dot_pert(i) = cos(z2d(i))*vec_up(i,1);
    y_dot_pert(i) = sin(z2d(i))*vec_up(i,1);
    theta_dot_pert(i) = vec_up(i,2);
    
    x_pert(i+1) = x_dot_pert(i)*Tsample + x_pert(i);          
    y_pert(i+1) = y_dot_pert(i)*Tsample + y_pert(i);          
    theta_pert(i+1) = theta_dot_pert(i)*Tsample + theta_pert(i);
    
    % Perturbated Inputs 
    v_d_pert(i) = sqrt(x_dot_pert(i)^2+y_dot_pert(i)^2);
    w_d_pert(i) = theta_dot_pert(i);
end

% Plot Trajectories
figure
subplot(1,2,1),plot(z1d,z3d,'--g',x,y,x_pert,y_pert,'r');
axis equal
legend('Desired Trajectory','Nominal Trajectory','Perturbed Trajectory','Location','Best')
subplot(1,2,2),
plot(z1d,z3d,'--m'); hold on

for i=1:length(vec_t)
    if mod(i-1,.05/Tsample)==0
        DrawUnicycle(z1d(i),z3d(i),z2d(i));
        pause(0.05)
    end
    plot(z1d(1:i),z3d(1:i),'g');
    axis equal
end
%% INPUT-OUTPUT LINEARIZATION VIA STATIC FEEDBACK

% Rate of convergence

% c0 = [1 1];
c0 = [10 10];
% c0 = [50 50];
% c0 = [100 100];
% c0 = [500 500];

for s = 1:2
    
    x_1d = z1d;
    x_2d = z3d;
    x_3d = z2d;

    z_io = [Qi(1) + D*cos(Qi(3));...
            Qi(2) + D*sin(Qi(3))];
        
    x_1(1) = z_io(1);
    x_2(1) = z_io(2);
    x_3(1) = Qi(3);


    for j = 1:length(vec_t)

        z_io_d = [x_1d(j) + D*cos(x_3d(j));...
                  x_2d(j) + D*sin(x_3d(j))];

        A = [cos(x_3d(j)), -D*sin(x_3d(j));... 
             sin(x_3d(j)), D*cos(x_3d(j))];
        
       switch s
           case 1
               % Nominal Input
               v_io_d = [v_d(j);...
                         w_d(j)];
                     
           case 2
               % Perturbated Input
               v_io_d = [v_d_pert(j);...
                         w_d_pert(j)];
       end

        z_dot_d = A*v_io_d;
       
        r_io = [z_dot_d(1)+c0(1)*(z_io_d(1)-z_io(1,j));...
                z_dot_d(2)+c0(2)*(z_io_d(2)-z_io(2,j))];

        % Closed-loop system
        z_dot_io = r_io;
        x_3_dot = (cos(x_3(j))*r_io(2) - sin(x_3(j))*r_io(1))/D;

        z_io(1,j+1) = z_dot_io(1)*Tsample + z_io(1,j);         
        z_io(2,j+1) = z_dot_io(2)*Tsample + z_io(2,j);        
        x_3(j+1) = x_3_dot*Tsample + x_3(j);       

    end

    for i = 1:length(z_io)
        x_1(i) = z_io(1,i)-D*cos(x_3(i));
        x_2(i) = z_io(2,i)-D*sin(x_3(i));
    end

    switch s
        case 1 
            figure
            plot(x_1,x_2,z1d,z3d,'--g'); hold on
            axis equal
            
            x_n = x_1;
            y_n = x_2;
        case 2
            plot(x_1,x_2,'r');
            legend('Nominal Trajectory','Desired Trajectory','Perturbed Trajectory','Location','Best')
            title('I/O Feedback Linearization')
            axis equal
    end 
end

%% TRAJECTORY ERROR

e_t = [z1d - x_n(1:end-1);...
       z3d - y_n(1:end-1)];

e_t_pert = [z1d - x_1(1:end-1);...
            z3d - x_2(1:end-1)];
 
figure
subplot(1,2,1),plot(e_t(1,:)); hold on
subplot(1,2,1),plot(e_t(2,:),'r');
legend('x Error','y Error','Location','Best')
title('Nominal Trajectory Error')

subplot(1,2,2),plot(e_t_pert(1,:)); hold on
subplot(1,2,2),plot(e_t_pert(2,:),'r');
legend('x Error','y Error','Location','Best')
title('Perturbed Trajectory Error')

