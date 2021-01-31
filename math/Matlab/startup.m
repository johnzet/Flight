addpath sensor
addpath animation


dt = 0.02; % accel and gyro sample period
g = 9.81;

%  Gyro
gyroMax = 500;  % gyro full scale range in degrees/s
gyroSensitivity = deg2rad(1/65.5);  % 65.6 LSB/deg/s for 500 deg/s range
gyroNoise = deg2rad(0.01)^2;  %0.01 degree/s/sqrt(Hz)
gyroOffset = deg2rad(0);  
gyroLpfFreq = 41;

% Accelerometer
accelMax = 4;   % accel full scale range in gs
accelSensitivity = g/8192;
accelNoise = (300e-6)^2;  %300ug/sqrt hz
accelOffset = 0;  % gs
accelLpfFreq = 41;

% Magnetometer
magMax = 4800;  % uT
magSensitivity = 0.6;  % uT
magNoise = 0; % unknown
magOffset = 0; 

% Altimeter
altSensitivity = 0.084;  % meter = 0.01 hPa
altNoise = 0.25; % meter
altOffset = 0;

% GPS
gpsNoise = 10 * 1.41;  % 10 meters 2D RMS

% tail control loop
torqueOffset = 0;  % [-1,1]
plantTorqueOffset = 0.2; % radians/s^2  (adds-in by superposition)
plantGain = 12;

outerProportionalGain = 4;
outerIntegralGain = 0;
innerProportionalGain = 1;
innerIntegralGain = 0.05;

%display(length(find_system('gyroscope', 'LookUnderMasks', 'on', 'FollowLinks', 'on','Virtual', 'off')), 'blocks used')

