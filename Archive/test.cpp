#include<stdio.h>
#include<math.h>
int main()
{
    double a,x,x1,f,ff;
    //ȫ������Ϊ˫���ȸ�����,ffΪf��һ�׵�
    scanf("%lf",&a);
    //����������Ҫ��x��һ����ֵ���������Ӳ���Ҫ��ѭ������
    //Ҳ���Բ�����������������ֵ�����м� x!=0
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
        f=500 - 32.45 - 20*log10(x1) - 20 * log10(100) + 50 * x1-a;//�ֶ�д��f(x)��f'(x)���ʽ

        ff=- 50 - 20/(x1*log(10));
        x=x1-f/ff;
    }while(fabs(x-x1)>=1e-4);
    printf("%.6f",x);
    return 0;
}
