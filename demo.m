clear;
clc;
tx_p = 100.0;
c = 50.0;
f = 50.0;
x0 = 0.5;
fun = @(d)parameterfun(d,tx_p,c,f);
F = fsolve(fun,x0);