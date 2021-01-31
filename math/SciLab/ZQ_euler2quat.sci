function [q] = ZQ_euler2quat(v)

sv = size(v); 

if (sv(2) > 1 | sv(1) <> 3)
  error("Invalid argument sizes"); 
end

sinx = sin(v(1)/2);
siny = sin(v(2)/2);
sinz = sin(v(3)/2);
cosx = cos(v(1)/2);
cosy = cos(v(2)/2);
cosz = cos(v(3)/2);

r = cosx*cosy*cosz + sinx*siny*sinz;
x = sinx*cosy*cosz - cosx*siny*sinz;
y = cosx*siny*cosz + sinx*cosy*sinz;
z = cosx*cosy*sinz - sinx*siny*cosz;

q = ZQ_defQuat(r, x, y, z);

q = q/norm(q);

endfunction
