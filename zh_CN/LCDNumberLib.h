/*这是液晶数码管的驱动库文件，本文件旨在更快更好的驱动液晶数码管，减少开发时间。
 * 定义了一些函数，每个函数都有对应的说明。
 * 本库文件针对的是89C51及兼容这一系列的微控制器，其他类型的微控制器没有特别支持。
 */
#ifndef _LCDNumberLib
#define _LCDNumberLib
/*阴极为同一寄存器的液晶数码管*/
/*showLCDNumber()函数通过一系列的参数输入，给某一特定的液晶数码管的液晶驱动，按照指定的时间显示一个数字。
*时间的计数方法是，每个单位1循环？次。根据自己微控制器的情况调节循环次数，达到自己想要的显示时间。
* 参数解释：共阴极端口（连续的某一端口的数字，例如P0口就填0），需要显示的数字，阳极端口（精确到位，例如P0^1口，填写01），循环量。
*/
void showLCDNumber(unsigned char port, unsigned char num, unsigned char posPort, unsigned int time);
