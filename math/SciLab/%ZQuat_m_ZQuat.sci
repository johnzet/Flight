function [q3] = %ZQuat_m_ZQuat(q1,q2)

N1 = size(q1);
N2 = size(q2);

if (N1 > 1 | N2 > 1)
  error("Invalid arguments sizes");
end

q1r = q1.r;
q1x = q1.i(1);
q1y = q1.i(2);
q1z = q1.i(3);

q2r = q2.r;
q2x = q2.i(1);
q2y = q2.i(2);
q2z = q2.i(3);

//ix = q1r*q2x + q1x*q2r - q1y*q2z + q1z*q2y;
//iy = q1r*q2y + q1x*q2z + q1y*q2r - q1z*q2x;
//iz = q1r*q2z - q1x*q2y + q1y*q2x + q1z*q2r;
//r  = q1r*q2r - q1x*q2x - q1y*q2y - q1z*q2z;
 
ix = q1r*q2x + q1y*q2z - q1z*q2y + q1x*q2r;
iy = q1r*q2y + q1y*q2r + q1z*q2x - q1x*q2z;
iz = q1r*q2z - q1y*q2x + q1z*q2r + q1x*q2y;
r  = q1r*q2r - q1y*q2y - q1z*q2z - q1x*q2x;
q3 = ZQ_defQuat(r, ix, iy, iz);

endfunction
 
