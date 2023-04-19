#include <iostream>

/*
闰年：
    1.年份非整百且能被4整除的为闰年
    2.年份能被400整除的是闰年

    闰年2月份是29天 平年2月份是28天
*/
void is_LeapYear(int year){

    if((year % 100 != 0 && year % 4 == 0) || year % 400 == 0){

        std::cout << "闰年" << std::endl;
    }else{

        std::cout << "不是闰年" << std::endl;
    }
}

/*
星期几计算公式：

    星期为w，年份为y， 月份为m， 日期为d
    
    w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;

    计算出来的w再+1就是星期几了

    注意每年的1，2月份要当成上一年的13，14月份计算 如2023 2 24 则为 2022 14 24
*/

int calculated(int y, int m, int d){

    int w;
    w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;

    return w + 1;
}

int main(){

    is_LeapYear(2004); //output : 闰年
    std::cout << calculated(2022,14,24) << std::endl; //output : 5

    return 0;
}