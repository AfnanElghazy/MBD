Zeta = 0.2;
Wn = 2;
num = [0 Wn^2];
denum =[1 2*Zeta*Wn Wn^2];
G = tf(num ,denum);
hold on 
step(G);