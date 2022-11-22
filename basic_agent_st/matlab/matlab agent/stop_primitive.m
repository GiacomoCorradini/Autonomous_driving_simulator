%#codegen
%%
%          Agent Logic
%         Stop Primitive
%              2022
%
%
%%

function [coefs,maxsf,tf] = stop_primitive(v0,a0,sf)
    if v0 > 0
        maxsf = sf;
        if 4*v0^2 + 5*a0*sf < 0
            maxsf = -((4*v0^2)/(5*a0));
            tf = (5*maxsf)/v0;
        else
            tf = final_opt_time_stop(v0,a0,maxsf);
        end
        coefs = coef_list(v0, a0, maxsf, 0., 0., tf);
    else
        maxsf = 0.;
        tf = 0.;
        coefs = [0,0,0,0,0,0];
    end
end