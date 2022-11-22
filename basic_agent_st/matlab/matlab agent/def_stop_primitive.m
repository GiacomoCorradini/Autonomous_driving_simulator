%%
%           Agent Logic
%         Stop Primitive
%              2022
%
%
%% Determine the optimal time to stop %%
syms z; % We create this variable for more stable solution of the equations

final_opt_time_stop_var = 1./solve(diff(subs(total_cost_var,[vf,af,T],[0,0,1/z]),z)==0,z);
final_opt_time_stop_fun = matlabFunction(final_opt_time_stop_var(1),'Vars',[v0,a0,sf],'File','final_opt_time_stop.m');

