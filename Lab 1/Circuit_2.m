function[] = Circuit_2()
V=(400*sqrt(2))/sqrt(3);
f=50;
assignin('base', 'V', V);
assignin('base', 'f', f);
%-----------------
sim('fig2.slx') %simulate simulink model
figure();
plot(tout,I1,tout,I2,tout,I3,tout,I_total);
legend('I1','I2','I3',"Total current");
title('3 Phase 400VAC, f=50Hz');
xlabel('Time (s)');
ylabel('Voltage (V)');
grid();
end