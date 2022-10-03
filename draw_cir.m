function draw_cir(x,y,r)
    t=linspace(0,2*pi,50);
    z=x+r*cos(t)+1i*(y+r*sin(t));
    polarplot(angle(z),abs(z),'r--');
end