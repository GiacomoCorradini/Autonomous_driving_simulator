%#codegen
%%
%          Agent Logic
%         Pass Primitive
%              2022
%
%
%%

function [coefsj0, vfj0, tfj0] = pass_primitive_j0( v0, a0, sf, vfmin, vfmax)
    tfj0_list = final_opt_time_j0_pass(v0, a0, sf);
    vfj0 = final_opt_vel_j0_pass(v0,a0,0,sf,0,tfj0_list(1));
    if vfmin < vfj0 && vfmax > vfj0
        tfj0 = tfj0_list(1);
        coefsj0 = coef_list(v0, a0, sf, vfj0, 0., tfj0);
    else
        vfj0 = final_opt_vel_j0_pass(v0,a0,0,sf,0,tfj0_list(2));
        if vfmin < vfj0 && vfmax > vfj0 
            tfj0 = tfj0_list(2);
            coefsj0 = coef_list(v0, a0, sf, vfj0, 0., tfj0);
        else
            coefsj0 = [0.,0.,0.,0.,0.,0.];
            tfj0 = 0.;
            vfj0 = 0.;
        end
    end
end