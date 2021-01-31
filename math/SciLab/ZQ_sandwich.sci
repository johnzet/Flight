function [v2] = ZQ_sandwich(q1,v)

N1 = size(q1);
sv = size(v); 

if (sv(2) > 1 | N1 > 1 | sv(1) <> 3 | typeof(q1) <> "ZQuat")
  error("Invalid argument sizes"); 
end

if (abs(abs(norm(q1))-1) > 0.001) then
    error("quaternion must be normalized first");
end

vq = ZQ_defQuat(0, v(1), v(2), v(3));

q2 = q1 * vq;
q2 = q2 * conj(q1);

v2 = [q2.i(1); q2.i(2); q2.i(3)];

endfunction
