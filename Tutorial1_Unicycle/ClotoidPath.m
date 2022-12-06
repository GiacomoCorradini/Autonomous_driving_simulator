function [vec_ud, x_d, y_d, theta_d] = ClotoidPath(Tmin, Tmax, Tsample, Qi, Qf)

addpath('Clotoid');

t = [Tmin Tmax];
x = [Qi(1) Qf(1)];
y = [Qi(2) Qf(2)];
theta = [Qi(3) Qf(3)];

[x_t, y_t] = clotoid_traj(x,y,theta,t,0);

x_d = interp1([1:length(x_t)],x_t,[1:400*Tsample:length(x_t)]);
y_d = interp1([1:length(x_t)],y_t,[1:400*Tsample:length(x_t)]);

theta_d = theta(1);
if theta_d(1)>= pi
        theta_d(1) = theta_d(1)-2*pi;
    elseif theta_d(1)< -pi
        theta_d(1) = theta_d(1)+2*pi;
    end

x_dot = 0;
y_dot = 0;
vec_ud = [0;0];

for i=1:length(x_d)-1
    % Velocities
    x_dot(i+1) = (x_d(i+1)-x_d(i))/Tsample;
    y_dot(i+1) = (y_d(i+1)-y_d(i))/Tsample;
    
    vec_ud(i+1,1) = sqrt(x_dot(i)^2+y_dot(i)^2);

    theta_d(i+1) = atan2(y_dot(i+1), x_dot(i+1));
    if abs(theta_d(i)-theta_d(i+1))>pi
        if theta_d(i)<theta_d(i+1)
            theta_d(i+1) = theta_d(i+1)-2*pi;
        else
            theta_d(i+1) = theta_d(i+1)+2*pi;
        end
    end
    g=i+1;
    vec_ud(g,2) = (theta_d(g)-theta_d(i))/Tsample;

end