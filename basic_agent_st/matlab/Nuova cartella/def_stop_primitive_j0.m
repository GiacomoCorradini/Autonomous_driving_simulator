%%
%           Agent Logic
%         Stop Primitive
%              2022
%
%
%% Stop primitive with j0 = 0 %%
syms j0;


%% Determine the optimal final position imposing j0
final_opt_pos_j0_var = solve(subs(sol_opt.j,t,0)==j0,sf);
final_opt_pos_j0_fun = matlabFunction(final_opt_pos_j0_var,'Vars',[v0,a0,j0,vf,af,T],'File','final_opt_pos_j0.m');


%% Determine the optimal time to stop with j0 = 0
final_opt_time_stop_j0_var = 1./solve(simplify(final_opt_time_stop_fun(v0,a0,final_opt_pos_j0_fun(v0,a0,0,0,0,1/z)))==1/z,z);
final_opt_time_stop_j0_fun = matlabFunction(final_opt_time_stop_j0_var(1),'Vars',[v0,a0],'File','final_opt_time_stop_j0.m');
