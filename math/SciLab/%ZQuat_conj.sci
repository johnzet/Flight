function [q2] = %ZQuat_conj(q1)

q2 = ZQ_defQuat(q1.r, -q1.i);

endfunction
