function vf_bar = finalOptVel(v0,a0,sf,T)
%finalOptVel
%    VF_BAR = finalOptVel(V0,A0,SF,T)

%    This function was generated by the Symbolic Math Toolbox version 9.1.
%    29-Nov-2022 16:34:32

vf_bar = ((sf.*-1.5e+1+T.*v0.*7.0+T.^2.*a0).*(-1.0./8.0))./T;
