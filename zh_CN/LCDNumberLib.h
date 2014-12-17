/*
 * 这是液晶数码管的驱动库文件，本文件旨在更快更好的驱动液晶数码管，减少开发时间。
 * 定义了一些函数，每个函数都有对应的说明。
 * 本库文件针对的是89C51及兼容这一系列的微控制器，其他类型的微控制器没有特别支持。
 */
#ifndef _LCDNumberLib
#define _LCDNumberLib
#include "reg52.h"
/*定义特殊位寄存器*/
sbit P00 = P0^0;
sbit P01 = P0^1;
sbit P02 = P0^2;
sbit P03 = P0^3;
sbit P04 = P0^4;
sbit P05 = P0^5;
sbit P06 = P0^6;
sbit P07 = P0^7;
sbit P10 = P1^0;
sbit P11 = P1^1;
sbit P12 = P1^2;
sbit P13 = P1^3;
sbit P14 = P1^4;
sbit P15 = P1^5;
sbit P16 = P1^6;
sbit P17 = P1^7;
sbit P20 = P2^0;
sbit P21 = P2^1;
sbit P22 = P2^2;
sbit P23 = P2^3;
sbit P24 = P2^4;
sbit P25 = P2^5;
sbit P26 = P2^6;
sbit P27 = P2^7;
sbit P30 = P3^0;
sbit P31 = P3^1;
sbit P32 = P3^2;
sbit P33 = P3^3;
sbit P34 = P3^4;
sbit P35 = P3^5;
sbit P36 = P3^6;
sbit P37 = P3^7;

/*定义和数字对应的数码管编码*/
const unsigned char num0 = 63;
const unsigned char num1 = 6;
const unsigned char num2 = 91;
const unsigned char num3 = 79;
const unsigned char num4 = 102;
const unsigned char num5 = 109;
const unsigned char num6 = 125;
const unsigned char num7 = 7;
const unsigned char num8 = 127;
const unsigned char num9 = 111;

/*定义和字母对应的数码管编码*/
const unsigned char letterA = 119 ;
const unsigned char letterB = 127 ;
const unsigned char letterC = 57 ;
const unsigned char letterD = 63 ;
const unsigned char letterE = 121 ;
const unsigned char letterF = 113 ;
const unsigned char letterG = 61 ;
const unsigned char letterH = 118 ;

/*阳极为同一寄存器的液晶数码管*/

/*
 *I   showLCDNumber()函数通过一系列的参数输入，给某一特定的液晶数码管的液晶驱动，按照指定的时间显示一个数字。
 *II  时间的计数方法是，每个单位1空循环？次。根据自己微控制器的情况调节循环次数，达到自己想要的显示时间。
 *III 参数解释：共阳极端口（连续的某一端口的数字，例如P0口就填0），需要显示的数字，阴极端口（精确到位，例如P0^1口，填写01），循环量（0为循环一次）。
 * IV特别说明：当num大于9时，则只显示个位数。
*/
void showLCDNumber(unsigned char port, unsigned int num, unsigned char posPort, unsigned int time);

/*
 *I   showLCDLetter()函数通过一系列的参数输入，给某一特定的液晶数码管的液晶驱动，按照指定的时间显示一个字母。
 *II  时间的计数方法是，每个单位1空循环？次。根据自己微控制器的情况调节循环次数，达到自己想要的显示时间。
 *III 参数解释：共阳极端口（连续的某一端口的数字，例如P0口就填0），需要显示的字母，阴极端口（精确到位，例如P0^1口，填写01），循环量（0为循环一次）。
 *IV 特别说明：字母只支持A、B、C、D、E、F、G、H这几个大写字母，输入函数参数时，可以用1、2、3、4、5、6、7、8这几个数字对应。亦可使用ASCII交换码，
 *即输入参数时用'A'来表示，不与前面冲突。若字母输入有误不能显示，则显示'E'表示错误。
*/
void showLCDLetter(unsigned char port, unsigned char letter, unsigned char posPort, unsigned int time);

/*
 *I  showLCDNumbers()函数通过一系列的参数输入，给某一特定的液晶数码管的液晶驱动，按照指定的时间显示一串数字。
 *II  时间的计数方法是，每个单位1空循环？次。根据自己微控制器的情况调节循环次数，达到自己想要的显示时间。
 *III 参数解释：共阳极端口（连续的某一端口的数字，例如P0口就填0），需要显示的数字，阴极端口数组（精确到位，例如P0^1口，填写01。端口放在数组中），端口
 *数组长度（默认也是数字位数）， 循环量（0为循环一次）。
 * IV特别说明：液晶数码管的每一位可以和输入的数字的每一位一一对应，默认配对原则是：输入数字的最低位和输入阳极端口号的最后一个对应显示。因此在传递端口
 * 号参数时应注意。
 */
void showLCDNumbers(unsigned char port, unsigned int num, unsigned int* posPort, unsigned char length, unsigned int time);

/*
 * I  showLCDLetters()函数通过一系列的参数输入，给某一特定的液晶数码管的液晶驱动，按照指定的时间显示一串字母。
 *II  时间的计数方法是，每个单位1空循环？次。根据自己微控制器的情况调节循环次数，达到自己想要的显示时间。
 *III 参数解释：共阳极端口（连续的某一端口的数字，例如P0口就填0），需要显示的字母的数组，阴极端口数组（精确到位，例如P0^1口，填写01。端口放在数组中），
 * 循环量（0为循环一次）。
 * IV特别说明：字母只支持A、B、C、D、E、F、G、H这几个大写字母，输入函数参数时，可以用1、2、3、4、5、6、7、8这几个数字对应。亦可使用ASCII交换码，
 *即输入参数时用'A'来表示，不与前面冲突。传递字母数组参数时，可以两种表示方法混用，不影响最终结果。数组中的字母和端口的配对显示原则是：字母数组和端口数组
 * 下标一一对应。
*/
void showLCDLetters(unsigned char port, unsigned char letter[], unsigned char posPort[], unsigned char length, unsigned int time);
#endif
