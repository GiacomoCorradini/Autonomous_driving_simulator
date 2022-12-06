function DrawUnicycle(X,Y,Theta)

   %Triangle-like unicycle
   s=0.1;
   line([X+s*cos(Theta+(3*pi/5)), X+s*cos(Theta-(3*pi/5))],[Y+s*sin(Theta+(3*pi/5)), Y+s*sin(Theta-(3*pi/5))], 'Color','k');
   line([X+s*cos(Theta+(3*pi/5)), X+1.5*s*cos(Theta)],[Y+s*sin(Theta+(3*pi/5)), Y+1.5*s*sin(Theta)], 'Color','k');
   line([X+1.5*s*cos(Theta), X+s*cos(Theta-(3*pi/5))],[Y+1.5*s*sin(Theta), Y+s*sin(Theta-(3*pi/5))],'Color','k');

   %Caster/castor.
   line([X+s*cos(Theta), X+s*cos(Theta)],[Y+s*sin(Theta), Y+s*sin(Theta)], 'Color','k');
   
   %Centre of the axis.
   line([X, X],[Y, Y],'Color','k');
   
   %Left wheel
   line([X+s*0.4*cos(Theta+(pi/4)), X+s*0.4*cos(Theta+(3*pi/4))],[Y+s*0.4*sin(Theta+(pi/4)), Y+s*0.4*sin(Theta+(3*pi/4))], 'LineWidth', 2,'Color','k');
   %Right wheel
   line([X+s*0.4*cos(Theta-(pi/4)), X+s*0.4*cos(Theta-(3*pi/4))],[Y+s*0.4*sin(Theta-(pi/4)), Y+s*0.4*sin(Theta-(3*pi/4))], 'LineWidth', 2,'Color','k');