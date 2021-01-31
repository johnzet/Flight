function [q2] = %ZQuat_m_s(q1,a)

N1 = size(q1);
sa = size(a); 

if (sa(2) > 1 | N1 > 1)
  error("Invalid arguments sizes"); 
end

if (sa(1) > 1) then
    // vector
    //q2 = ZQ_defQuat(q1.r * a, q1.i * a);
    error("Use ZQ_sandwich(q,v) instead");
else
    // scalar
    q2 = ZQ_defQuat(q1.r * a, q1.i * a);
end

endfunction
