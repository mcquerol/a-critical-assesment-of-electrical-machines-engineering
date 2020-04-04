function[] = lab4()
N=8597;
Ra=(0.2+(N/12e3));
La=(5+(N/2000))/1e3;
Rf=(40+(N/100));
Lf=(5+(N/1e3));
Laf=(500+(N/20))/1000;
J=0.22;
B=0.008;
Tf=5;

assignin('base','Ra',Ra);
assignin('base','La',La);
assignin('base','Rf',Rf);
assignin('base','Lf',Lf);
assignin('base','Laf',Laf);
assignin('base','J',J);
assignin('base','B',B);
assignin('base','Tf',Tf);
% 
% model='machinelab';
% t=0:10:30;
% t_sweep = t.*(t);
% numSims = length(t_sweep);
% for i = numSims:-1:1
%     in(i) = Simulink.SimulationInput(model);
%     in(i) = in(i).setVariable('torque_in',t(i));
% end
% out = parsim(in, 'ShowProgress', 'on');
% for i = numSims:-1:1
%         simOut = out(i);
% %         ts = simOut.logsout.get('RPM').Values;
% %         torque = simOut.logsout.get('E_Torque').Values;
%         ds = Simulink.SimulationData.Dataset(simout);
%         ds1 = Simulink.SimulationData.Dataset(simout1);
%         dsfinal = concat(ds,ds1)
% %         plot(torque);
% %         hold on
% %         plot(ts);
% %         hold all
% end
% title('Response of a 3-DoF Suspension Model')
% xlabel('Time (s)');
% ylabel('RPM');
end
