    // Meter-Kilogram-Second-Radian measure
    // Right-Hand rules
    // NWU - North-West-Up
    // x axis = forward
    // y axis = left
    // z axis = up
    // roll = x axis
    // pitch = y axis
    // yaw = z axis
    // vectors are all column vectors (1 columnm, n rows)

g = 9.81;

// dt is the sample period
// A_sample and aV_sample are x-y-z column vectors
// altim_sample is a scalar
// A_q_w_0, V_w_0, and P_w_0 are curent attitute, velocity and position

// Returned are the normalized attitude quaternion and the velocity and position vectors

function [A_q_w, V_w, P_w] = processSample(dt, A_q_w_0, V_w_0, P_w_0, A_sample, aV_sample, altim_sample)

    // angular position delta samples
    aP_sample_q = ZQ_euler2quat(aV_sample*dt);

    // attitude 
    A_q_w = A_q_w_0 * aP_sample_q;
    A_q_w = A_q_w/norm(A_q_w);
    
    // velocity
    A_sample_w = ZQ_sandwich(A_q_w, A_sample)
    V_w = V_w_0 + (A_sample_w - [0;0;g])*dt;
    
    //  position
    P_w = P_w_0 + V_w*dt; 
    
   
    // sensor fusion
    P_w(3) = P_w(3)*0.9 + altim_sample*0.1;

endfunction
