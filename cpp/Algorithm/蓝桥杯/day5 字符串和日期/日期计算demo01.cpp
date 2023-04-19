#include <iostream>

//知道0001.01.01是星期一，计算任意日期的星期数

int calculate(int year, int month, int day){

    int ans = 0;
    for(int i = 1; i < year; i++){

        if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)){

            ans += 366 % 7;
            ans %= 7;
        }else{

            ans += 365 % 7;
            ans %= 7;
        }
    }
    for(int i = 1; i < month; i++){

        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){

            ans += 31 % 7;
            ans %= 7;
        }else if(i == 4 || i == 6 || i == 9 || i == 11){

            ans += 30 % 7;
            ans %= 7;
        }else{

            if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){

                ans += 29;
                ans %= 7;
            }else{

                ans += 28;
                ans %= 7;
            }

       }
    }
    ans += (day - 1) % 7;
    ans %= 7;

    return ans;
}
int main(){

    int year,month,day;
    std::cin >> year >> month >> day;

    std::string days[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    
    std::cout << days[calculate(year,month,day)] << std::endl;
    return 0;
}