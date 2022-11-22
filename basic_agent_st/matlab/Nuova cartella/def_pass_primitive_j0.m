%%
%           Agent Logic
%          Pass Primitive
%               2022
%
%
%% Pass primitive with j0 = 0 %%
syms j0;


%% Determine the optimal final velocity to pass function of j0 = 0 %%
final_opt_vel_j0_pass_var = solve(subs(sol_opt.j,t,0)==j0,vf);
final_opt_vel_j0_pass_fun = matlabFunction(final_opt_vel_j0_pass_var,'Vars',[v0,a0,j0,sf,af,T],'File','final_opt_vel_j0_pass.m');


%% Determine the optimal time to reach to final velocity with j0 = 0 %%
final_opt_time_j0_pass_var = 1./solve(final_opt_time_pass_fun(v0,a0,sf,subs(final_opt_vel_j0_pass_var,[T,af,j0],[1/z,0,0]))==1/z,z);
final_opt_time_j0_pass_fun = matlabFunction(final_opt_time_j0_pass_var,'Vars',[v0,a0,sf],'File','final_opt_time_j0_pass.m');