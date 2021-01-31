function [phi,theta,psi] = ZQ_quat2euler(qin)

if (typeof(qin) <> "ZQuat")
  error("Wrong type of input argument. Quaternion expected");
end

q = qin/norm(qin);
q0 = q.r
q1 = q.i(1,:)
q2 = q.i(2,:)
q3 = q.i(3,:)

phi = atan( ( 2.*(q0.*q1+q2.*q3) ),( 1-2.*(q1.^2+q2.^2) ) );  // in C, look at atan2(x/y)
theta = asin( 2.*(q0.*q2-q3.*q1) );
psi = atan( ( 2.*(q0.*q3+q1.*q2) ),( 1-2.*(q2.^2+q3.^2) ) );

if or( (abs(theta)>%pi-0.0001) | ((abs(theta)>%pi/2-0.0001)&(abs(theta)<%pi/2+0.0001)) )
  warning("theta near pi or pi/2: results may not be accurate!");
end

endfunction

//q = ZQ_defQuat(0,%pi/4,%pi/4,0);
//[a,b,c] = ZQ_quat2euler(q);
//
//disp(q);
//disp([a,b,c]);
