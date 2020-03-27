function [] = lab3()
format BANK;
Ioc=[58e-3; 72e-3; 85e-3;];
Voc=[100; 150; 170;];
Poc=[5; 10; 14;];

Pfoc=Poc./(Voc.*Ioc);
Phi=acos(Pfoc);
Ic=Ioc.*cos(Phi);
Im=Ioc.*sin(Phi);
Rc=Voc./Ic;
Xm=Voc./Im;

Ioc=Ioc.*1000;
Ic=Ic.*1000;
Im=Im.*1000;
Phi=rad2deg(Phi);
VarNames1={'Ioc (mA)','Voc (V)','Poc (W)','Pfoc','Phi (deg)','Ic (mA)','Im (mA)','Rc (ohm)','Xm (ohm)'};
Toc=table(Ioc,Voc,Poc,Pfoc,Phi,Ic,Im,Rc,Xm,'VariableNames',VarNames1,'RowNames',{'1','2','3'});
disp('---------- Open Circuit Test ----------');
disp(Toc);

Isc=[1; 1.4; 1.8;];
Vsc=[10; 20; 30;];
Psc=[9; 26; 53;];
Pfsc=Psc./(Vsc.*Isc);
Phi=acos(Pfsc);
Req=Psc./(Isc.^2);
Zeq=(Vsc./Isc).*exp(1j.*Phi);
% Xeq=sqrt((Zeq.^2)-(Req.^2));
Xeq=imag(Zeq);
Phi=rad2deg(Phi);
VarNames2={'Isc (A)','Vsc (V)','Psc (W)','Pfsc','Phi (deg)','Req (ohm)','Xeq (ohm)','Zeq (ohm)'};
Tsc = table(Isc,Vsc,Psc,Pfsc,Phi,Req,Xeq,Zeq,'VariableNames',VarNames2,'RowNames',{'1','2','3'});
disp('---------- Short Circuit Test ----------');
disp(Tsc);

end