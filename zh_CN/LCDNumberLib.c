#include "LCDNumberLib.h"

void showLCDNumber(unsigned char port, unsigned int num, unsigned char posPort, unsigned int time)
{
    int i, j;
    unsigned char displayNum = num%10;                  //提取出需要显示的数字，只显示个位
    unsigned char posPortNum = posPort/10%10;       //提取出阳极端口寄存器号
    unsigned char posPortBitNum = posPort%10;       //提取出阳极端口寄存器位号

    switch (displayNum)                                                 //将需要显示的数字变换为液晶管编码
    {
        case 0: displayNum = num0;break;
        case 1: displayNum = num1;break;
        case 2: displayNum = num2;break;
        case 3: displayNum = num3;break;
        case 4: displayNum = num4;break;
        case 5: displayNum = num5;break;
        case 6: displayNum = num6;break;
        case 7: displayNum = num7;break;
        case 8: displayNum = num8;break;
        case 9: displayNum = num9;break;
    }

    switch (port)                                                           //通过端口识别，把液晶管编码发送到对应的端口上
    {
        case 0:P0 = ~displayNum;break;                          //由于是共阴极管，所以阴极管码要按位取反
        case 1:P1 = ~displayNum;break;
        case 2:P2 = ~displayNum;break;
        case 3:P3 = ~displayNum;break;
    default :
        P0 = ~letterE;
    }

    switch (posPortNum)                        //先识别出端口号
    {
    case 0:
        switch (posPortBitNum) {            //给对应的位低电平
            case 0:P00=0;break;
            case 1:P01=0;break;
            case 2:P02=0;break;
            case 3:P03=0;break;
            case 4:P04=0;break;
            case 5:P05=0;break;
            case 6:P06=0;break;
            case 7:P07=0;break;
        default:
            P00=1;
            break;
        };break;

    case 1:
        switch (posPortBitNum) {
            case 0:P10=0;break;
            case 1:P11=0;break;
            case 2:P12=0;break;
            case 3:P13=0;break;
            case 4:P14=0;break;
            case 5:P15=0;break;
            case 6:P16=0;break;
            case 7:P17=0;break;
        default:
            P10=1;
            break;
        };break;

    case 2:
        switch (posPortBitNum) {
            case 0:P20=0;break;
            case 1:P21=0;break;
            case 2:P22=0;break;
            case 3:P23=0;break;
            case 4:P24=0;break;
            case 5:P25=0;break;
            case 6:P26=0;break;
            case 7:P27=0;break;
        default:
            P20=1;
            break;
        };break;

    case 3:
        switch (posPortBitNum) {
            case 0:P30=0;break;
            case 1:P31=0;break;
            case 2:P32=0;break;
            case 3:P33=0;break;
            case 4:P34=0;break;
            case 5:P35=0;break;
            case 6:P36=0;break;
            case 7:P37=0;break;
        default:
            P30=1;
            break;
        };break;
    }

    for(i = 0;i <= (time*100);i++)                       //设置一个定时循环
    {
        for(j = 0;j < 100;j++);
    }

    switch (port)                                                           //通过端口识别，把液晶管编码发送到对应的端口上
    {
        case 0:P0 =255;break;                          //显示结束，还原高电平
        case 1:P1 =255;break;
        case 2:P2 =255;break;
        case 3:P3 =255;break;
    default :
        P0 =  ~letterE;
    }
    switch (posPortNum)                        //先识别出端口号
    {
    case 0:
        switch (posPortBitNum) {            //给对应的高电平
            case 0:P00=1;break;
            case 1:P01=1;break;
            case 2:P02=1;break;
            case 3:P03=1;break;
            case 4:P04=1;break;
            case 5:P05=1;break;
            case 6:P06=1;break;
            case 7:P07=1;break;
        default:
            P00=1;
            break;
        };break;

    case 1:
        switch (posPortBitNum) {
            case 0:P10=1;break;
            case 1:P11=1;break;
            case 2:P12=1;break;
            case 3:P13=1;break;
            case 4:P14=1;break;
            case 5:P15=1;break;
            case 6:P16=1;break;
            case 7:P17=1;break;
        default:
            P10=1;
            break;
        };break;

    case 2:
        switch (posPortBitNum) {
            case 0:P20=1;break;
            case 1:P21=1;break;
            case 2:P22=1;break;
            case 3:P23=1;break;
            case 4:P24=1;break;
            case 5:P25=1;break;
            case 6:P26=1;break;
            case 7:P27=1;break;
        default:
            P20=1;
            break;
        };break;

    case 3:
        switch (posPortBitNum) {
            case 0:P30=1;break;
            case 1:P31=1;break;
            case 2:P32=1;break;
            case 3:P33=1;break;
            case 4:P34=1;break;
            case 5:P35=1;break;
            case 6:P36=1;break;
            case 7:P37=1;break;
        default:
            P30=1;
            break;
        };break;
    }
}
void showLCDLetter(unsigned char port, unsigned char letter, unsigned char posPort, unsigned int time)
{
    int i, j;
    unsigned char posPortNum = posPort/10%10;       //提取出阳极端口寄存器号
    unsigned char posPortBitNum = posPort%10;       //提取出阳极端口寄存器位号

    switch (letter) {                                                       //我们把要显示的字母转换为液晶管显示码
         case 1:letter = letterA;break;
         case 65:letter = letterA;break;
         case 2:letter = letterB;break;
         case 66:letter = letterB;break;
         case 3:letter = letterC;break;
         case 67:letter = letterC;break;
         case 4:letter = letterD;break;
         case 68:letter = letterD;break;
         case 5:letter = letterE;break;
         case 69:letter = letterE;break;
         case 6:letter = letterF;break;
         case 70:letter = letterF;break;
         case 7:letter = letterG;break;
         case 71:letter = letterG;break;
         case 8:letter = letterH;break;
         case 72:letter = letterH;break;
    default:letter = letterE;
        break;
    }

    switch (port)                                                           //通过端口识别，把液晶管编码发送到对应的端口上
    {
        case 0:P0 =~letter;break;                          //由于是共阳极管，所以液极管码要按位取反
        case 1:P1 =~letter;break;
        case 2:P2 =~letter;break;
        case 3:P3 =~letter;break;
    default :
        P0 = ~letterE;
    }

    switch (posPortNum)                        //先识别出端口号
    {
    case 0:
        switch (posPortBitNum) {            //给对应的位低电平
            case 0:P00=0;break;
            case 1:P01=0;break;
            case 2:P02=0;break;
            case 3:P03=0;break;
            case 4:P04=0;break;
            case 5:P05=0;break;
            case 6:P06=0;break;
            case 7:P07=0;break;
        default:
            P00=1;
            break;
        };break;

    case 1:
        switch (posPortBitNum) {
            case 0:P10=0;break;
            case 1:P11=0;break;
            case 2:P12=0;break;
            case 3:P13=0;break;
            case 4:P14=0;break;
            case 5:P15=0;break;
            case 6:P16=0;break;
            case 7:P17=0;break;
        default:
            P10=1;
            break;
        };break;

    case 2:
        switch (posPortBitNum) {
            case 0:P20=0;break;
            case 1:P21=0;break;
            case 2:P22=0;break;
            case 3:P23=0;break;
            case 4:P24=0;break;
            case 5:P25=0;break;
            case 6:P26=0;break;
            case 7:P27=0;break;
        default:
            P20=1;
            break;
        };break;

    case 3:
        switch (posPortBitNum) {
            case 0:P30=0;break;
            case 1:P31=0;break;
            case 2:P32=0;break;
            case 3:P33=0;break;
            case 4:P34=0;break;
            case 5:P35=0;break;
            case 6:P36=0;break;
            case 7:P37=0;break;
        default:
            P30=1;
            break;
        };break;
    }

    for(i = 0;i <= (time*100);i++)                       //设置一个定时循环
        for(j = 0;j < (100);j++);

    switch (port)                                                           //通过端口识别，把液晶管编码发送到对应的端口上
    {
        case 0:P0 =255;break;                          //显示结束，还原高电平
        case 1:P1 =255;break;
        case 2:P2 =255;break;
        case 3:P3 =255;break;
    default :
        P0 = ~letterE;
    }

    switch (posPortNum)                        //先识别出端口号
    {
    case 0:
        switch (posPortBitNum) {            //给对应高电平
            case 0:P00=1;break;
            case 1:P01=1;break;
            case 2:P02=1;break;
            case 3:P03=1;break;
            case 4:P04=1;break;
            case 5:P05=1;break;
            case 6:P06=1;break;
            case 7:P07=1;break;
        default:
            P00=1;
            break;
        };break;

    case 1:
        switch (posPortBitNum) {
            case 0:P10=1;break;
            case 1:P11=1;break;
            case 2:P12=1;break;
            case 3:P13=1;break;
            case 4:P14=1;break;
            case 5:P15=1;break;
            case 6:P16=1;break;
            case 7:P17=1;break;
        default:
            P10=1;
            break;
        };break;

    case 2:
        switch (posPortBitNum) {
            case 0:P20=1;break;
            case 1:P21=1;break;
            case 2:P22=1;break;
            case 3:P23=1;break;
            case 4:P24=1;break;
            case 5:P25=1;break;
            case 6:P26=1;break;
            case 7:P27=1;break;
        default:
            P20=1;
            break;
        };break;

    case 3:
        switch (posPortBitNum) {
            case 0:P30=1;break;
            case 1:P31=1;break;
            case 2:P32=1;break;
            case 3:P33=1;break;
            case 4:P34=1;break;
            case 5:P35=1;break;
            case 6:P36=1;break;
            case 7:P37=1;break;
        default:
            P30=1;
            break;
        };break;
    }
}

void showLCDNumbers(unsigned char port, unsigned int num, unsigned char* posPort, unsigned char length, unsigned int time)
{
    unsigned int i, displayNum;
    int j;
    for(i = 0;i <= (time*100);i++)
    {
        displayNum = num;
        for(j = length - 1;j >= 0;--j)
        {
            showLCDNumber(port, displayNum, posPort[j], 0);
            displayNum /= 10;
        }
    }
}

void showLCDLetters(unsigned char port, unsigned char letter[], unsigned char posPort[], unsigned char length, unsigned int time)
{
    int i, j;

    for(i = 0;i <= (time*100);i++)
    {
        for(j = length -1;j >= 0;--j)
        {
            showLCDLetter(port, letter[j], posPort[j], 0);
        }
    }
}
