function [x_t,y_t] = clotoid_traj(x,y,theta,t,p,npts,tol)
%This function use the clotoid to interpolate the input data (x,y)
%
% USAGE: void = clotoid_traj(x,y,theta,t,tol,npts);
%                                                                            
% On input:
%                                                                             
%      x, y    = coodinate of point of the trajectory
%      theta0  = orientation (angle) of the clothoid                         
%      t       = time vector    
%      tol     = tolerance used to stop Newton Iterations
%      npts    = number of points along the clothoid
%      
%  On output: 
                                                                           

if nargin < 7
     tol = 1e-12 ;
end
if nargin < 6
       npts = 400 ;
end

pos_xy = [x; y];

if min(size(pos_xy)) < 2 %C
    disp('No move !!')
else

x_t  = [];
y_t  = [];
t2 = [];

for i = 1:length(t)-1
    % initial point with angle direction
    x0     = x(i) ;
    y0     = y(i)   ;
    theta0 = theta(i)  ;   % come faccio a determinare theta???
    
    % final point with angle direction
    x1     = x(i+1) ;
    y1     = y(i+1) ;
    theta1 = theta(i+1) ;
    
    % compute clothoid parameters
    [k,dk,L] = buildClothoid( x0, y0, theta0, x1, y1, theta1, tol ) ;
    
    % compute points on clothoid
    XY = pointsOnClothoid( x0, y0, theta0, k, dk, L, npts ) ;
    
    x_t = [x_t  XY(1,:)];
    y_t = [y_t  XY(2,:)];
    t2 = [t2 t(i) : (t(i+1)-t(i))/npts : t(i+1)];
    
    if p ~= 0
    
        plot( XY(1,:), XY(2,:), '-' ) ;
        hold on
        plot( x0, y0, '*r')
        hold on
        axis equal
        axis square
        grid on
    end
    
end

if p ~= 0
    plot( x1, y1, '*r' )
    title('Path Planning Using Clotoid')

    figure
    subplot(1,2,1)
    plot(t2,x_t,'-',t2,y_t,'-r')
    hold on
    plot(t,y,'om',t,x,'oc')
    axis equal
    axis square
    grid on
    legend('x(t)','y(t)','Location','Best')
    title('x(t) & y(t)')
    subplot(1,2,2)
    plot(x_t,y_t,'-g')
    axis equal
    axis square
    grid on
    title('Trajectory Using Clotoid')
end
end