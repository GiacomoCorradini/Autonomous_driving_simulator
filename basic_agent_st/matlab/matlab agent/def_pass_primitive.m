%%
%           Agent Logic
%         Pass Primitive
%              2022
%
%
%% Determine the optimal final velocity to pass %%
final_opt_vel_pass_var = solve(diff(subs(total_cost_var,af,0),vf)==0,vf)
final_opt_vel_pass_fun = matlabFunction(final_opt_vel_pass_var,'Vars',[v0,a0,sf,T],'File','final_opt_vel_pass.m');

%% Determine the optimal time to reach to final velocity
sym z; % We create this variable for more stable solution of the equations

final_opt_time_pass_var = 1./solve(subs(final_opt_vel_pass_var,T,1/z)==vf,z);
final_opt_time_pass_fun = matlabFunction(final_opt_time_pass_var(2),'Vars',[v0,a0,sf,vf],'File','final_opt_time_pass.m');

%% Determine the time to reach the minimum velocity
time_min_vel_var = solve(diff(final_opt_vel_pass_var,T)==0,T)
time_min_vel_fun = matlabFunction(time_min_vel_var(2),'Vars',[a0,sf],'File','time_min_vel.m');
