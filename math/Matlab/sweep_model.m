gain = 1.5:0.1:5;
len = length(gain);
error = zeros(1,len);
effort = zeros(1,len);
for n=1:len
outerGain=gain(n);
sim('gyroYawLoop');
error(n) = totalAngleError;
effort(n) = totalControllerEffort;
end