#include<stdio.h>
#include<math.h>
int main()
{
    double a,x,x1,f,ff;
    //全部定义为双精度浮点数,ff为f的一阶导
    scanf("%lf",&a);
    //这里我们需要给x赋一个初值，避免增加不必要的循环次数
    //也可以不按照以下做法赋初值，但切记 x!=0
    if(a<0){
        x=0.2;
    }
    else if(a==0){
        x=0.3;
    }
    else{
        x=a;
    }
    do{
        x1=x;
        f=500 - 32.45 - 20*log10(x1) - 20 * log10(100) + 50 * x1-a;//手动写出f(x)和f'(x)表达式

        ff=- 50 - 20/(x1*log(10));
        x=x1-f/ff;
    }while(fabs(x-x1)>=1e-4);
    printf("%.6f",x);
    return 0;
}
