function [x] = %ZQuat_norm(q1, flag); 
// "flag" is needed since this is an overload of norm(m, flag) 

x = sqrt((q1.r).^2 + sum((q1.i).^2, "r"));

endfunction
