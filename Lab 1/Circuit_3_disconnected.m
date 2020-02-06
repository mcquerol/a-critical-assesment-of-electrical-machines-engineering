function[] = Circuit_3_disconnected()
V=(70*sqrt(2))/sqrt(3);
f=50;
assignin('base', 'V', V);
assignin('base', 'f', f);
%---Test 2-----------
R1=125;
L1=1;
C1=0;
R2=125;
L2=1;
C2=0;
R3=125;
L3=1;
C3=0;
assignin('base', 'R1', R1);
assignin('base', 'L1', L1);
assignin('base', 'C1', C1);
assignin('base', 'R2', R2);
assignin('base', 'L2', L2);
assignin('base', 'C2', C2);
assignin('base', 'R3', R3);
assignin('base', 'L3', L3);
assignin('base', 'C3', C3);
figure();
sim('fig3_disconnected.slx'); %simulate simulink model
plot(tout,I1,tout,I2,tout,I3,tout,I_total);
legend('I1','I2','I3',"Total current");
title('3 Phase 400VAC, f=50Hz - test 2 (disconnected)');
xlabel('Time (s)');
ylabel('Voltage (V)');
grid();
%---Test 4-----------
R1=125;
L1=1;
C1=0;
R2=62.5;
L2=1;
C2=0;
R3=250;
L3=1;
C3=0;
assignin('base', 'R1', R1);
assignin('base', 'L1', L1);
assignin('base', 'C1', C1);
assignin('base', 'R2', R2);
assignin('base', 'L2', L2);
assignin('base', 'C2', C2);
assignin('base', 'R3', R3);
assignin('base', 'L3', L3);
assignin('base', 'C3', C3);
figure();
sim('fig3_disconnected.slx'); %simulate simulink model
plot(tout,I1,tout,I2,tout,I3,tout,I_total);
legend('I1','I2','I3',"Total current");
title('3 Phase 400VAC, f=50Hz - test 4 (disconnected)');
xlabel('Time (s)');
ylabel('Voltage (V)');
grid();
end