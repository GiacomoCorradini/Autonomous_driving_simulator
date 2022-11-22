%%
%             Agent Logic
%       Optimal control solution
%                2022
%
%%
clear; clc; close all

%% plant equations
syms s(t) v(t) a(t) u(t) l1(t) l2(t) l3(t);
ode1 = diff(s) == v;
ode2 = diff(v) == a;
ode3 = diff(a) == u;
%% Cost function inside the integral
L = u^2;
%% Hamiltonian
H = L + l1*rhs(ode1) + l2*rhs(ode2) + l3*rhs(ode3);
% - rhs() function for the right hand side
%% Costate equations
Dl1 = diff(l1,t)==-functionalDerivative(H,s);
Dl2 = diff(l2,t)==-functionalDerivative(H,v);
Dl3 = diff(l3,t)==-functionalDerivative(H,a);
%% solve for control u
du = functionalDerivative(H,u);
syms opt_u;
opt_u = solve(subs(du,u(t),opt_u)==0,opt_u);
%% Substitute u to state equations
ode3s = diff(a) == subs(rhs(ode3), u, opt_u);
%% Initial conditions 
ICs = 's(0)=0, v(0)=v0, a(0)=a0';
FCs = 's(T)=sf, v(T)=vf, a(T)=af'; 
%% convert symbolic objects to strings for using 'dsolve'
sol_opt = dsolve([ode1,ode2,ode3s,Dl1,Dl2,Dl3],ICs, FCs);

disp('Optimal polynomial longitudinal position:');
pretty(sol_opt.s)

disp('Optimal polynomial velocity:');
pretty(sol_opt.v)

disp('Optimal polynomial acceleration:');
pretty(sol_opt.a)

%% assign to function

% obtain optimal control
sol_opt.j = subs(opt_u,l3(t),sol_opt.l3);

syms t v0 a0 sf vf af T             
s_opt_fun = matlabFunction(sol_opt.s,'Vars',[t,v0,a0,sf,vf,af,T],'File','s_opt.m');
v_opt_fun = matlabFunction(sol_opt.v,'Vars',[t,v0,a0,sf,vf,af,T],'File','v_opt.m');
a_opt_fun = matlabFunction(sol_opt.a,'Vars',[t,v0,a0,sf,vf,af,T],'File','a_opt.m');
j_opt_fun = matlabFunction(sol_opt.j,'Vars',[t,v0,a0,sf,vf,af,T],'File','j_opt.m');

% remember to add: %#codegen if you want to manually generate C++ code

%% Coefficent list export
% the coeffs are moltiplied by [1,2,6,24,120] to obtain the value of c1,
% c2, c3, c4, c5
coef_list_var = [0,coeffs(sol_opt.s,t) .* [1,2,6,24,120]];
coef_list_fun = matlabFunction(coef_list_var,'Vars',[v0,a0,sf,vf,af,T],'File','coef_list.m');

%% Total Cost
total_cost_var = simplify(int(sol_opt.j^2,t,0,T));
total_cost_fun = matlabFunction(total_cost_var,'Vars',[v0,a0,sf,vf,af,T],'File','total_cost.m');

%% inspect solution 

Tmax  = 4.;
t_list = linspace(0,Tmax,100);

v0val = 10;
a0val = 1;
xfval = 90;
vfval = 25;
afval = 0.;


%the functions work both for vector (t_list) or number (t)
s_list = s_opt_fun(t_list, v0val, a0val, xfval, vfval, afval, Tmax);
v_list = v_opt_fun(t_list, v0val, a0val, xfval, vfval, afval, Tmax);
a_list = a_opt_fun(t_list, v0val, a0val, xfval, vfval, afval, Tmax);
j_list = j_opt_fun(t_list, v0val, a0val, xfval, vfval, afval, Tmax);

figure(1)
% position
    subplot(2,4,1)
    plot(t_list, s_list)
    grid on
    xlabel('Time (s)','Interpreter','latex');
    ylabel('Position $(m)$','Interpreter','latex');
    
% velocity
    subplot(2,4,2)
    plot(t_list, v_list)
    grid on
    xlabel('Time (s)','Interpreter','latex'),
    ylabel('Velocity $(\frac{m}{s})$','Interpreter','latex'),
    
% acceleration
    subplot(2,4,3)
    plot(t_list, a_list)
    grid on
    xlabel('Time (s)','Interpreter','latex'),
    ylabel('Acceleration $(\frac{m}{s^2})$','Interpreter','latex'),

% control
    subplot(2,4,4)
    plot(t_list, j_list)
    grid on
    xlabel('Time (s)','Interpreter','latex'),
    ylabel('Control $(\frac{m}{s^3})$','Interpreter','latex')
    
% velocity on position
    subplot(2,4,6)
    plot(s_list, v_list)
    grid on
    xlabel('Position (m)','Interpreter','latex'),
    ylabel('Velocity $(\frac{m}{s})$','Interpreter','latex'),
    
% acceleration on position
    subplot(2,4,7)
    plot(s_list, a_list)
    grid on
    xlabel('Position (m)','Interpreter','latex'),
    ylabel('Acceleration $(\frac{m}{s^2})$','Interpreter','latex'),

% control on position
    subplot(2,4,8)
    plot(s_list, j_list)
    grid on
    xlabel('Position (m)','Interpreter','latex'),
    ylabel('Control $(\frac{m}{s^3})$','Interpreter','latex')


%% code generation 
% coder