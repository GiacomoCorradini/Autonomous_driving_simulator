function cost = totalCost(v0,a0,sf,vf,af,T)
%totalCost
%    COST = totalCost(V0,A0,SF,VF,AF,T)

%    This function was generated by the Symbolic Math Toolbox version 9.1.
%    29-Nov-2022 16:34:11

cost = 1.0./T.^5.*(T.^3.*(a0.*v0.*7.2e+1+a0.*vf.*4.8e+1-af.*v0.*4.8e+1-af.*vf.*7.2e+1)+T.^2.*(a0.*sf.*-1.2e+2+af.*sf.*1.2e+2+v0.*vf.*3.36e+2+v0.^2.*1.92e+2+vf.^2.*1.92e+2)+sf.^2.*7.2e+2+T.^4.*(a0.*af.*-6.0+a0.^2.*9.0+af.^2.*9.0)-T.*sf.*(v0+vf).*7.2e+2);
