a=load("k1.txt");
a(:,1)=a(:,1)*pi/180;
al=a(:,1);
f=a(:,2);
polarplot(al,f)