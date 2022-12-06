%=============================================================================%
%  intXY:  Compute Fresnel sine and cosine integrals momenta                  %
%                                                                             %
%  USAGE: [X,Y] = GeneralizedFresnelCS( nk, a, b, c ) ;                       %
%                                                                             %
%  Integrals are defined as:                                                  %
%                                                                             %
%  X_k(a,b,c) = \int_0^1 t^k * cos( (a/2)*t^2 + b*t + c ) dt                  %
%  Y_k(a,b,c) = \int_0^1 t^k * sin( (a/2)*t^2 + b*t + c ) dt                  %
%                                                                             %
%  On input:                                                                  %
%                                                                             %
%       nk      = number of momentae to be computed                           %
%       a, b, c = the parameters of the integrals                             %
%                                                                             %
%  On output:                                                                 %
%                                                                             %
%       X = vector with Fresnel cosine momenta [X_0,X_1,...,X_{nk-1}]         %
%       Y = vector with Fresnel sine momenta   [Y_0,Y_1,...,Y_{nk-1}]         %
%                                                                             %
%=============================================================================%
%                                                                             %
%  Autors: Enrico Bertolazzi and Marco Frego                                  %
%          Department of Industrial Engineering                               %
%          University of Trento                                               %
%          enrico.bertolazzi@unitn.it                                         %
%          m.fregox@gmail.com                                                 %
%                                                                             %
%=============================================================================%
function [X,Y] = GeneralizedFresnelCS( nk, a, b, c )

  absa = abs(a) ;
  epsi = 0.01   ; % best thresold

  X = zeros( nk, 1 ) ;
  Y = zeros( nk, 1 ) ;

  if absa < epsi % case `a` small
    [X,Y] = evalXYaSmall( nk, a, b, 5 ) ;
  else
    [X,Y] = evalXYaLarge( nk, a, b ) ;
  end

  cc = cos(c) ;
  ss = sin(c) ;

  for k=1:nk
    xx = X(k) ;
    yy = Y(k) ;
    X(k) = xx*cc-yy*ss ;
    Y(k) = xx*ss+yy*cc ;
  end

end
%
%
%
function [C,S] = FresnelCSk( nk, t )
  C = zeros(nk,1) ;
  S = zeros(nk,1) ;
  [C(1),S(1)] = FresnelCS(t) ;
  if nk > 1
    tt   = pi/2*t^2 ;
    ss   = sin(tt) ;
    cc   = cos(tt) ;
    C(2) = ss/pi ;
    S(2) = (1-cc)/pi ;
    if nk > 2
      C(3) = (t*ss-S(1))/pi ;
      S(3) = (C(1)-t*cc)/pi ;
    end
  end
end
%
%
%
function [X,Y] = evalXYaLarge( nk, a, b )
  X       = zeros(nk,1) ;
  Y       = zeros(nk,1) ;
  s       = sign(a) ;
  z       = sqrt(abs(a)/pi) ;
  ell     = s*b/sqrt(abs(a)*pi) ;
  g       = -0.5*s*b^2/abs(a) ;
  [Cl,Sl] = FresnelCSk(nk,ell) ;
  [Cz,Sz] = FresnelCSk(nk,ell+z) ;
  dC      = Cz - Cl ;
  dS      = Sz - Sl ;
  cg      = cos(g)/z ;
  sg      = sin(g)/z ;
  X(1)    = cg * dC(1) - s * sg * dS(1) ;
  Y(1)    = sg * dC(1) + s * cg * dS(1) ;
  if nk > 1
    cg   = cg/z ;
    sg   = sg/z ;
    DC   = dC(2)-ell*dC(1);
    DS   = dS(2)-ell*dS(1);
    X(2) = cg * DC - s * sg * DS ;
    Y(2) = sg * DC + s * cg * DS ;
    if nk > 2
      cg   = cg/z ;
      sg   = sg/z ;
      DC   = dC(3)+ell*(ell*dC(1)-2*dC(2)) ;
      DS   = dS(3)+ell*(ell*dS(1)-2*dS(2)) ;
      X(3) = cg * DC - s * sg * DS ;
      Y(3) = sg * DC + s * cg * DS ;
    end
  end
end
%
%
%
function res = S(mu,nu,b)
  tmp = 1/((mu+nu+1)*(mu-nu+1)) ;
  res = tmp ;
  for n=1:100
    tmp = tmp * (-b/(2*n+mu-nu+1)) * (b/(2*n+mu+nu+1)) ;
    res = res + tmp ;
    if abs(tmp) < abs(res) * 1e-50
      break ;
    end;
  end
end
%
%
%
function [X,Y] = evalXYazero( nk, b )
  X  = zeros(nk,1) ;
  Y  = zeros(nk,1) ;
  sb = sin(b) ;
  cb = cos(b) ;
  b2 = b*b ;
  if abs(b) < 1e-3
    X(1) = 1-b2/6*(1-b2/20*(1-b2/42)) ;
    Y(1) = (b/2)*(1-b2/12*(1-b2/30)) ;
  else
    X(1) = sb/b ;
    Y(1) = (1-cb)/b ;
  end
  A = b*sb ;
  D = sb-b*cb ;
  B = b*D ;
  C = -b2*sb ;
  for k=1:nk-1
    X(k+1) = ( k*A*S(k+1/2,3/2,b) + B*S(k+3/2,1/2,b) + cb )/(1+k) ;
    Y(k+1) = ( C*S(k+3/2,3/2,b) + sb ) / (2+k) + D*S(k+1/2,1/2,b) ;
  end
end
%
%
%
function [X,Y] = evalXYaSmall( nk, a, b, p )
  [X0,Y0] = evalXYazero( nk + 4*p + 2, b ) ;

  for j=1:nk
    X(j) = X0(j)-a*Y0(j+2)/2 ;
    Y(j) = Y0(j)+a*X0(j+2)/2 ;
  end

  t  = 1 ;
  aa = -(a/4)^2 ;
  for n=1:p
    t  = t*aa/(n*(2*n-1)) ;
    bf = a/(4*n+2) ;
    for j=1:nk
      X(j) = X(j) + t*(X0(4*n+j)-bf*Y0(4*n+j+2)) ;
      Y(j) = Y(j) + t*(Y0(4*n+j)+bf*X0(4*n+j+2)) ;
    end
  end
end