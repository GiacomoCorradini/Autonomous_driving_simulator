%% Stopping primitive

% Find the optimal time solution

Txf = 1./solve(diff(totalCost(v0,a0,sf,0,0,T),T)==0,T);
finalOptTimeStop_fun = matlabFunction(1./Txf(2),'Vars',[v0,a0,sf],'File','finalOptTimeStop.m');

%% Passing primitive

% Find the optimal final velocity in terms of tf

vf_bar = solve(diff(totalCost(v0,a0,sf,vf,0,T),vf)==0,vf);
finalOptVel_fun = matlabFunction(vf_bar,'Vars',[v0,a0,sf,T],'File','finalOptVel.m');

% Find the optimal time in terms of vf

T_vf = solve(diff(totalCost(v0,a0,sf,vf,0,T),vf)==0,T);
finalOptTime_fun = matlabFunction(T_vf(1),'Vars',[v0,a0,sf,vf],'File','finalOptTime.m');