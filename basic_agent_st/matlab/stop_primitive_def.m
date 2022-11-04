%% Find the optimal time solution

Txf = 1./solve(diff(totalCost_fun(v0,a0,sf,0,0,T),T)==0,T);
finalOptTimeStop_fun = matlabFunction(1./Txf(1),'Vars',[v0,a0,sf],'File','finalOptTimeStop.m');