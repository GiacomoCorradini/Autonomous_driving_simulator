function res = resid_pure_Fx(X,FX,K,gamma,Fz)

    % ----------------------------------------------------------------------
    %% Compute the residuals - least squares approach - to fit the Fx curve 
    %  with Fz=Fz_nom, IA=0. Pacejka 1996 Magic Formula
    % ----------------------------------------------------------------------

    % Define MF coefficients

%     Fz0 = 890; % N
%     
%     pCx1 = X(1);
%     pDx1 = X(2);
      
%     ...
%      
    Dx = ...
    Bx = ...    
    Fx0 = Dx*...
    
    % Compute the residuals
    res = sum((FX - Fx0).^2)/sum(FX.^2);

end

