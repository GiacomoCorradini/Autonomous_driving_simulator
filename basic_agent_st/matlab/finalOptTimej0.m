function Tvf_j0 = finalOptTimej0(v0,a0,sf)
%finalOptTimej0
%    Tvf_j0 = finalOptTimej0(V0,A0,SF)

%    This function was generated by the Symbolic Math Toolbox version 9.1.
%    28-Nov-2022 14:21:17

t2 = v0.*5.0;
t3 = v0.^2;
t4 = a0.*sf.*8.0;
t6 = sqrt(5.0);
t5 = t2.*v0;
t7 = t4+t5;
t8 = sqrt(t7);
t9 = t6.*t8;
Tvf_j0 = [(sf.*1.0e+1)./(t2+t9);(sf.*1.0e+1)./(t2-t9)];
