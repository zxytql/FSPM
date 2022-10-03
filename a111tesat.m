close all;
clc;
clear;

rou = 0.01; % 水蒸气密度
K = 1.3;    % 压制系数
real_com_dis = 0;


%发射机相关变量
tx_p = 115;   %发射机功率 发射功率+10dBm，接收灵敏度为-105dBm Sum=115dBm
tx_f = 433.92;  %频率 单位MHz
%坐标 单位为km
tx_pos_x = 0;
tx_pos_y = 0;

%干扰机相关变量
jammer_tx_p = 100;
jammer_p = 0;
jammer_f = 360; 
%坐标
jammer_pos_x = 10;
jammer_pos_y = 25;
jammer_height = 0; %经纬高的高度


%计算tx_gama_o
tx_gama_o = (7.19 * 1e-3 + 6.09 / (tx_f^2 + 0.227) + 4.81 / ((tx_f - 57)^2 + 1.5)) * tx_f^2 * 1e-5;

%计算tx_gama_w
tx_gama_w = (0.067 + 2.4 / ((tx_f * 1e-3 - 22.3)^2 + 6.6) + 7.33 / ((tx_f * 1e-3 - 183.5)^2 + 5) + 4.4 / ((tx_f * 1e-3 - 3.38)^2 + 10)) * tx_f^2 * rou * 1e-10;
%求和 用变量tx_c表示
tx_c = tx_gama_o + tx_gama_w;

%计算ja_gama_o
ja_gama_o = (7.19 * 1e-3 + 6.09 / (jammer_f^2 + 0.227) + 4.81 / ((jammer_f - 57)^2 + 1.5)) * jammer_f^2 * 1e-5;
%计算ja_gama_w
ja_gama_w = (0.067 + 2.4 / ((jammer_f * 1e-3 - 22.3)^2 + 6.6) + 7.33 / ((jammer_f * 1e-3 - 183.5)^2 + 5) + 4.4 / ((jammer_f * 1e-3 - 3.38)^2 + 10)) * jammer_f^2 * rou * 1e-10;
%求和 用变量ja_c表示
ja_c = ja_gama_o + ja_gama_w;

%原方程是超越方程 无法求得解析解 需给定初值 不为0即可
x0 = 0.2;

fun1 = @(d)parameterfun(d,tx_p,tx_c,tx_f); %根据输入求解d
tx_rad = fsolve(fun1,x0);

fun2 = @(d)parameterfun(d,jammer_tx_p,ja_c,jammer_f); %根据输入求解d
ja_rad = fsolve(fun2,x0);

fileID = fopen('k1.txt','w');%'w'表示打开或创建一个新txt文件以输出
for i = 0 : 1 : 360 % 弧度遍历
    theta = deg2rad(i);
    
    for j = tx_rad : -0.1 : 0  % 距离遍历
        pos_x = j * cos(theta) - (jammer_pos_x - tx_pos_x);
        pos_y = j * sin(theta) - (jammer_pos_y - tx_pos_y); % 减去距离
        
        dis = sqrt(pos_x^2 + pos_y^2);
        p_a = tx_p - Cal_L0(tx_f,j) - Cal_La(tx_f,rou,j);
        p_s = jammer_tx_p - Cal_L0(jammer_f,dis) - Cal_La(jammer_f,rou,dis);
        if (p_s - K * p_a < 0)
            real_com_dis = j;
            fprintf(fileID,'%.2f,%.2f \n',rad2deg(theta),real_com_dis);
            break;
        end
    end
%     fprintf('%.2f,%.2f \n',rad2deg(theta),real_com_dis);  
    
end
fclose(fileID);


% 画可通讯范围 
a=load("k1.txt");
a(:,1)=a(:,1)*pi/180;
al=a(:,1);
f=a(:,2);
cir_ok = polarplot(al,f,'g');
cir_ok.LineWidth = 2;

% 画干扰机通信范围
hold on
draw_cir(jammer_pos_x,jammer_pos_y,ja_rad);

% 画发射机通信范围
draw_cir(tx_pos_x,tx_pos_y,tx_rad);
hold off

% axis equal
% ax = gca;
% ax.XAxisLocation = 'origin';
% ax.YAxisLocation = 'origin';
% 
% % % 画出发射机 干扰机的通信范围
% viscircles([tx_pos_x,tx_pos_y],tx_rad);
% hold on;
% viscircles([jammer_pos_x,jammer_pos_y],ja_rad);

