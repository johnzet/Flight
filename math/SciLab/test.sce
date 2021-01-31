funcprot(0);
cd("C:\projects\flight\math");
exec("%s_m_ZQuat.sci");
exec("%ZQuat_conj.sci");
exec("%ZQuat_m_s.sci");
exec("%ZQuat_m_ZQuat.sci");
exec("%ZQuat_norm.sci");
exec("%ZQuat_p.sci");
exec("%ZQuat_r_S.sci");
exec("%ZQuat_size.sci");
exec("%ZQuat_t.sci");
exec("plotter.sci");
exec("ZQ_defQuat.sci");
exec("ZQ_euler2quat.sci");
exec("ZQ_quat2euler.sci");
exec("ZQ_sandwich.sci");
exec("ZQ_quat2matrix.sci");
exec("kinematics.sci");

function [A_q_w, V_w, P_w] = main()
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
    
    
    // ************* Sample Period and Count *******************
    dt = 1; 
    samples = 7;
    
    // ************* Initial Conditions *******************
    // attitude, quaternion, world frame 
    g = 9.81;

    A_q_w = ZQ_euler2quat([0;0;0]);
    A_q_w = A_q_w/norm(A_q_w);
    // velocity 
    V_w = [0;0;0];
    // position, world frame
    P_w = [0;0;0];

    // ************* Sample Data *******************
    // angular velocity, euler, body frame (gyro sample)
    //aV_sample = [0;-w*sin(theta);-w*cos(theta)]; 
    // linear acceleration, body frame (accelerometer sample)
    //A_sample = [0;0; lift];

    // ************* Logging Setup *******************
    A_log = [];
    A_q_log = [];
    V_log = [];
    P_log = []; 
    disp("start position: ")
    disp(P_w);
    
    theta = 0.1;
    for i = 1:samples
        aV_sample = [theta;0;0]; 
        A_sample = [0; g*sin(theta*(i)); g*cos(theta*(i))];

        A_q_w_0 = A_q_w;
        V_w_0 = V_w;
        P_w_0 = P_w;
        [A_q_w, V_w, P_w] = processSample(dt, A_q_w_0, V_w_0, P_w_0, A_sample, aV_sample, 0);

        
        // ************* Logging *******************
        V_log = [V_log V_w];
        P_log = [P_log P_w];

        [a,b,c] = ZQ_quat2euler(A_q_w);
        A_log = [A_log [a;b;c]];
        A_q_log = [A_q_log [A_q_w.r; A_q_w.i(1); A_q_w.i(2); A_q_w.i(3);]];
        R = ZQ_quat2matrix(A_q_w);

        VertexData(:,:,i) = GeoVerMakeBlock(P_w',R);
        [X,Y,Z] = GeoPatMakeBlock(VertexData(:,:,i));
        PatchData_X(:,:,i) = X;
        PatchData_Y(:,:,i) = Y;
        PatchData_Z(:,:,i) = Z;
    end

    
    disp("end position: ")
    disp(P_w);
    
    // ************* Plots *******************
    clf()
    fig = gcf();
    fig.figure_size = [1000,1000];
    subplot(221)
    title("Attitude, Euler")
    plot([A_log(1,:)' A_log(2,:)' A_log(3,:)'])
    legend(["X";"Y";"Z"], "in_upper_left")
   
    subplot(222)
    title("Attitude, Quaternion")
    plot([A_q_log(1,:)' A_q_log(2,:)' A_q_log(3,:)' A_q_log(4,:)'])
    legend(["R";"X";"Y";"Z"], "in_upper_left")

    subplot(223)
    title("Velocity")
    plot([V_log(1,:)' V_log(2,:)' V_log(3,:)'])
    legend(["X";"Y";"Z"], "in_upper_left")
    
    subplot(224)
    title("Position")
    plot([P_log(1,:)' P_log(2,:)' P_log(3,:)'])
    legend(["X";"Y";"Z"], "in_upper_left")
    


  
    
    
    // Draw initial figure
    figure(1);
    fig = gcf();
    fig.figure_size = [1000,1000];
    plot3d(PatchData_X(:,:,1),PatchData_Y(:,:,1),PatchData_Z(:,:,1));
    h_fac3d = gce();
    h_fac3d.color_mode = 4;
    h_fac3d.foreground = 1;
    h_fac3d.hiddencolor = 4;
    
    // Axes settings
    xlabel("x",'fontsize',2);
    ylabel("y",'fontsize',2);
    zlabel("z",'fontsize',2);
    h_axes = gca();
    h_axes.font_size = 2;
    h_axes.isoview = "on";
    h_axes.box = "off";
    h_axes.rotation_angles = [67,-128];
    xgrid;
    
    // Find plot extents
    maxX=-10000; minX=10000; maxY=-10000; minY=10000; maxZ=-10000; minZ=10000;
    for i=1:samples
        maxX = max(maxX, P_log(1,i));
        maxY = max(maxY, P_log(2,i));
        maxZ = max(maxZ, P_log(3,i));
        minX = min(minX, P_log(1,i));
        minY = min(minY, P_log(2,i));
        minZ = min(minZ, P_log(3,i));
    end
    h_axes.data_bounds = [minX-1, minY-1, minZ-1; maxX+1, maxY+1, maxZ+1];
    
    sleep(1000);
    
    // Animation Loop
    for i=1:samples
    
        drawlater();
        h_fac3d.data.x = PatchData_X(:,:,i);
        h_fac3d.data.y = PatchData_Y(:,:,i);
        h_fac3d.data.z = PatchData_Z(:,:,i);
        drawnow();
        
        sleep(500);
    end
endfunction

main();
