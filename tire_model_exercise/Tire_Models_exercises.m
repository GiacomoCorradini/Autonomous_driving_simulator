clc
close all
clear

%% Exercise 1 - pure longitudinal slip
% Data

Dx = 2100;
Bx = 12.2;
Cx = 1.87;
Ex = 0.13;
Shx = 0.851 * 10e-3;
Svx = -77;

k = -1:0.01:1;
l = length(k);
Fx = zeros(1,l);

% Calculate the longitudinal force

for i = 1:l
    tmp = k(i);
    Fx(:,i) = MF(Dx,Cx,Bx,Shx,Ex,Svx,tmp);
end

% Plot the longitudinal force

figure
plot(k,Fx(1,:))
title('Longitudinal force Fx0')
xlabel('k')
ylabel('Fx0(k)')

syms k;
k_opt = abs(solve(diff(MF(Dx,Cx,Bx,Shx,Ex,Svx,k),k)==0,k))

% Calculate longitudianl slip and longitudinal force given data

omega = 70; % rad/s
Re = 0.2; % m
Vcx = 13; % m/s

k = (omega*Re - Vcx) / Vcx
Fx0_2 = MF(Dx,Cx,Bx,Shx,Ex,Svx,k)

% cornering stiffness
syms k;
Cfk = eval(subs(diff(MF(Dx,Cx,Bx,Shx,Ex,Svx,k),k),k,0))

%% Exercise 2 - combined slip

% calculate side slip and combined longitudinal force

Vcx = 15; % m/s
Vcy = -1.3; % m/s
k = 0.08;
alpha = -atan(Vcy/Vcx)

Shxa = -0.1257*10e-2;
Cxa = 0.926;

Bxa = 23.308 / sqrt((19.414*k)^2 + 1);
Dxa = 1/cos(Cxa*atan(Bxa*Shxa));


Gxa = Dxa*cos(Cxa*atan(Bxa*(alpha+Shxa)));
Fx0 = MF(Dx,Cx,Bx,Shx,Ex,Svx,k);

Fx = Gxa*Fx0

% plot combined longitudinal force for different values of alpha

k = -1:0.01:1;
lk = length(k);
al = [rad_to_pi(0), rad_to_pi(2), rad_to_pi(4), rad_to_pi(6), rad_to_pi(8)];
la = length(al);
Fx = zeros(la,l);

% Calculate the longitudinal force

for j = 1:la
    alpha = al(j);
    for i = 1:lk
        tmp = k(i);
        Bxa = 23.308 / sqrt((19.414*tmp)^2 + 1);
        Dxa = 1/cos(Cxa*atan(Bxa*Shxa));
        Gxa = Dxa*cos(Cxa*atan(Bxa*(alpha+Shxa)));
        Fx0 = MF(Dx,Cx,Bx,Shx,Ex,Svx,tmp);

        Fx(j,i) = Gxa*Fx0;
    end
end

figure
hold on
for j = 1:la
    plot(k,Fx(j,:))
end
title('Longitudinal force Fx')
legend('alpha = 0 deg','alpha = 2 deg','alpha = 4 deg','alpha = 6 deg','alpha = 8 deg')
xlabel('k')
ylabel('Fx(k)')
