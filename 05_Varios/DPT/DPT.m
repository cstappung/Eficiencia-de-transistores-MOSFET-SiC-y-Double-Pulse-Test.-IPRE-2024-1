%T1 = 3;
Rg = 50;

Tini = 0.0001;
Vdc = 420;
Vgson = 18;
Itest = 25;

%%%% PARAMETROS COMPONENTES %%%%
Rs = 0.07;
Vf = 3.3;
CaidaI = 0.05;
deltaVdc = 0.01*Vdc;


%T1 = 100*10^-6; 
%Lload = T1*Vdc/Itest; 
%T2 = 5*10^-6;
%T3 = T1/4;

Lload = 464.6*10^-6;
T1 = Lload*Itest/Vdc;
T2 = 5 * 10^-6;
T3 = 5 * 10^-6;


Cb = (Lload*Itest^2)/(2*Vdc*deltaVdc-deltaVdc^2);

Lloadmin = Rs*T2*(1/(log(1+(Itest*CaidaI/(Itest + (Vf/Rs))))));

Tz = Lload*98/Vdc - T1;