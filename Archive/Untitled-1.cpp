#include <iostream>
#include <cmath>

using namespace std;

class Data
{
    public:
        float gama_o;
        float gama_w;
        float L0;
        float La;
};

double Cal_gama_o(double f)
{
	return (7.19 * 0.001 + 6.09 / (pow(f, 2) + 0.227) + 
	4.81 / (pow((f - 57), 2) + 1.5)) * pow(f, 2) * 0.00001;
}

double Cal_gama_w(double f, double density)
{
    return (0.067 + 2.4 / (pow((f * 0.001 - 22.3), 2) + 6.6) + 
    7.33 / (pow((f * 0.001 - 183.5), 2) + 5) + 4.4 / 
    (pow((f * 0.001 - 3.38), 2) + 10)) * pow(f, 2) * density * pow(10.0, -10.0);
}

double Cal_La(double gama_o, double gama_w, double d)
{
    return (gama_o + gama_w) * d;
}

double Cal_L0(double f, double d)
{
    return (32.45 + 20 * log10(f) + 20 * log10(d));
}

int main()
{
    /** 定义发射机和干扰机结构体 **/
    Data tx;
    Data jammer;

    /** 定义输入变量 **/
    float tx_power;
    float tx_f;
    float jammer_tx_power;
    float jammer_f;
    float rx_sen;  // 接收机灵敏度  如果接收到的功率大于灵敏度就可以通信
    float density; // 水蒸气密度

    float dis; //通信距离

    /** 先计算储存大气吸收损耗 **/
    tx.gama_o = Cal_gama_o(tx_f);
    tx.gama_w = Cal_gama_w(tx_f,density);

    jammer.gama_o = Cal_gama_o(jammer_f);
    jammer.gama_o = Cal_gama_w(jammer_f,density);

    for (float dis = 0; dis < 1000; dis += 0.1)
    {
        tx.L0 = Cal_L0(tx_f, dis);
        tx.La = Cal_La(tx.gama_o, tx.gama_w, dis);

        jammer.L0 = Cal_L0(jammer_f, dis);
        jammer.La = Cal_La(jammer.gama_o, jammer.gama_w, dis);

        static float rx_power = tx_power - (tx.L0 + tx.La);
        static float jammer_power = jammer_tx_power - (jammer.L0 + jammer.La);

        if()
    }
    
}