function out1 = finalOptTime(v0,a0,sf,vf)
%finalOptTime
%    OUT1 = finalOptTime(V0,A0,SF,VF)

%    This function was generated by the Symbolic Math Toolbox version 9.1.
%    29-Nov-2022 16:34:33

out1 = (sf.*3.0e+1)./(v0.*7.0+vf.*8.0+sqrt(a0.*sf.*6.0e+1+v0.*vf.*1.12e+2+v0.^2.*4.9e+1+vf.^2.*6.4e+1));
