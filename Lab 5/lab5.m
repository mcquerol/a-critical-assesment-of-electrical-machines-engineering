function [] = lab5()

V=400; %nominal RMS voltage for sources and machine
f=50; %nominal frequency for sources and machine
phase=0; %phase angle of reference phase
N=8597; %constant

P=(8e3-(N/2)); %Nominal electrical power for machine
Rs=(0.4+(N/15e3)); %stator resistance per phase (star) (ohms)
Ls=(2.5+(N/4e3))/1000; %stator inductance per phase (star) (H)
Rr=(0.3+(N/20e3)); %Rotor resistance per phase (star) (H)
Lr=(2.2+(N/3.5e3))/1000; %Rotor inductance per phase (star) (ohms)
Lm=(30+(N/200))/1000; %Magnetic core inductance per phase (star) (H)
J=0.1; %Rotor inertia (Kgm^2) 
B=0.01; %Coefficent of Viscous friction (Nms)
Pp=2; %pole pairs

assignin('base','V',V);
assignin('base','f',f);
assignin('base','phase',phase);
assignin('base','P',P);
assignin('base','Rs',Rs);
assignin('base','Ls',Ls);
assignin('base','Rr',Rr);
assignin('base','Lr',Lr);
assignin('base','Lm',Lm);
assignin('base','J',J);
assignin('base','B',B);
assignin('base','Pp',Pp);

%T_sweep=s*(0:10:50); try this sweep as well
end