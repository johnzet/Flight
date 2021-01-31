function [R] = ZQ_quat2matrix(qin)

if (typeof(qin) <> "ZQuat")
  error("Wrong type of input argument. Quaternion expected");
end

q = qin/norm(qin);

qw = q.r;
qx = q.i(1);
qy = q.i(2);
qz = q.i(3);

R = [1 - 2*qy^2 - 2*qz^2, 2*qx*qy - 2*qz*qw, 2*qx*qz + 2*qy*qw;
     2*qx*qy + 2*qz*qw, 1 - 2*qx^2 - 2*qz^2, 2*qy*qz - 2*qx*qw;
     2*qx*qz - 2*qy*qw, 2*qy*qz + 2*qx*qw, 1 - 2*qx^2 - 2*qy^2];


endfunction
