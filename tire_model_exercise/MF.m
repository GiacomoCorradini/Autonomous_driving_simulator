function MF = MF(D, C, B, Sh, E, Sv, k)

MF = D * sin(C*atan(B*(k + Sh) - E*(B*(k + Sh) - atan(B*(k + Sh))))) + Sv;

end