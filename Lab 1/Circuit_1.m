function[] = Circuit_1()
V=(400*sqrt(2))/sqrt(3);
f=50;
assignin('base', 'V', V);
assignin('base', 'f', f);
%-----------------
sim('fig1.slx') %simulate simulink model
figure();
plot(tout,V1,'-.rs',tout,V2,'-.bd',tout,V3,'-.g*');
legend('V1','V2','V3');
title('3 Phase 400VRMSAC, f=50Hz');
xlabel('Time (s)');
ylabel('Voltage (V)');
grid();
end