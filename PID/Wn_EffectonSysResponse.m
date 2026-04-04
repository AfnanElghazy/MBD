Zeta = 1;
Wn = 0.5;
num = [0 Wn^2];
denum =[1 2*Zeta*Wn Wn^2];
G = tf(num ,denum);
hold on 
step(G);