function [q2] = %ZQuat_r_s(q1,a)

N1 = size(q1);
sa = size(a); 

if (sa(1) > 1 | (N1 > 1 & sa(2) > 1))
  error("Invalid arguments sizes");
end

q2 = q1 * (1 ./ a); 

endfunction
 
