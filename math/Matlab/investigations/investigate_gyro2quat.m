function investigate_gyro2quat() 

    q = [1 0 0 0];
    Q = [];
    T = [];
    Gx = [];
    Gy = [];
    Gz = [];
    
    for t = 0:1000
        gx = 0.1*sin(2*pi*t/500);
        gy = 0.1*sin(2*pi*t/1000);
        gz = 0.1*sin(2*pi*t/333.33333);

        qt = angle2quat(deg2rad(gx), deg2rad(gy), deg2rad(gz), 'XYZ');
%         dcm = angle2dcm(deg2rad(gx), deg2rad(gy), deg2rad(gz), 'XYZ');
%         qt = dcm2quat(dcm);
        qt = quatnormalize(qt);
        q = quatmultiply(q,qt);
        q = quatnormalize(q);

        Q = [Q q'];
        T = [T t];
        Gx = [Gx gx];
        Gy = [Gy gy];
        Gz = [Gz gz];

        
    end
    
    figure
    subplot(5,1,1);
    plot(T, Gx, 'r',  T, Gy, 'b',   T, Gz, 'g')
    legend({'X', 'Y', 'Z'})
    subplot(5,1,2);
    plot(T, Q(1,:));
    subplot(5,1,3);
    plot(T, Q(2,:));
    subplot(5,1,4);
    plot(T, Q(3,:));
    subplot(5,1,5);
    plot(T, Q(4,:));
    
    q
%     [x,y,z] = quat2angle(q);
%     rad2deg(x)
%     rad2deg(y)
%     rad2deg(z)
    

    
    
    
    
    
    
