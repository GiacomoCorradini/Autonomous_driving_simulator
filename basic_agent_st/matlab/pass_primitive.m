%% Passing primitive algorithm

function [m1,m2] = pass_primitive(v0,a0,sf,v_min,v_max,t_min,t_max)
    if a0 >= 0
        tv_min = finalOptTime(v0,a0,sf,v_min);
        tv_max = finalOptTime(v0,a0,sf,v_max);
    else 
        t_bar = sqrt((15*sf)/(-a0));
        v_bar = 1/4*(sqrt(15-a0*sf)-(7*v0));
        if (v_bar < v_min) && (v_min < v_max)
            tv_min = finalOptTime(v0,a0,sf,v_min);
            tv_max = finalOptTime(v0,a0,sf,v_max);
        elseif (v_min < v_bar) && (v_bar < v_max)
            tv_min = t_bar;
            tv_max = finalOptTime(v0,a0,sf,v_max);
        else
            tv_min = 0;
            tv_max = 0;
        end
    end
    [t1, t2] = intersect([t_min, t_max],[tv_min, tv_max]);
    if (0 < t1) && (t1 <= t2)
        v_min = finalOptVel(v0,a0,sf,t1);
        v_max = finalOptVel(v0,a0,sf,t2);
        m1 = evalPrimitiveCoeffs(v0,a0,sf,v_max,0,t1);
        m2 = evalPrimitiveCoeffs(v0,a0,sf,v_min,0,t2);
    else
        m1 = 0;
        m2 = 0;
    end