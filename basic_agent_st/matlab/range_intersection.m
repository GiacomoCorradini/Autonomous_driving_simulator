function [t1,t2] = range_intersection( A,B )

%A and B is a vector 
%for example A = [1 2]; B = [2 2.5]; 

%find lower and upper limit for vector A and B
Lower_A = min(A); 
Upper_A = max(A); 

Lower_B = min(B); 
Upper_B = max(B); 

%check condition of lower and upper limit both vector
%this part is to determine lower limit 
if (Lower_A > Lower_B || Lower_A == Lower_B)
    Lower_Lim = Lower_A;    
else
    Lower_Lim = Lower_B; 
end

%this part is to determine upper limit
if (Upper_A > Upper_B || Upper_A == Upper_B)
    Upper_Lim = Upper_B;    
else
    Upper_Lim = Upper_A; 
end

%merge all vectors
input_vector = union(A,B); 

Overlap = input_vector(intersect(find(input_vector>=Lower_Lim),find(input_vector<=Upper_Lim)));

if isempty(Overlap)
    Overlap = [0, 0];
end

t1 = Overlap(1);
t2 = Overlap(2);

end

