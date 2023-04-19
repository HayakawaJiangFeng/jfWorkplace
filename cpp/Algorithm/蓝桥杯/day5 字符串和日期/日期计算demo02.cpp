#include <iostream>

//给出日期，计算sum天后的日期
int main(){

    int year,mouth,day,sum;
    std::cin >> year >> mouth >> day >> sum;

    int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    for(int i = 1; i <= sum; i++){

        if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)){

            days[2] = 29; 
        }
        day++;

        if(day == days[mouth] + 1){

            mouth++;
            day = 1;
        }
        if(mouth == 13){

            year++;
            mouth = 1;
        }
    }
    printf("%04d-%02d-%02d\n",year,mouth,day);

    return 0;
}