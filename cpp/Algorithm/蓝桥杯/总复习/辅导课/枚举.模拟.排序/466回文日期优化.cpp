#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath> 

int date1;
int date2;
int res;

bool is_date(int date){

    int year = date / 10000;
    int month = date % 10000 / 100;
    int day = date % 100;

    if(day == 0 || month == 0 || month > 12){

        return false;
    }
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){

        if(day > 31){
            
            return false;
        }
    }
    if(month == 4 || month == 6 || month == 9 || month == 11){

        if(day > 30){

            return false;
        }
    }
    if(month == 2){

        if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)){

            if(day > 29){

                return false;
            }
        }else{

            if(day > 28){

                return false;
            }
        }
    }
    return true;
}
/*
bool is_rev(int date){

    std::string dateStr = std::to_string(date);
    
    for(int i = 0, j = 7; i < 4; i++,j--){

        if(dateStr[i] != dateStr[j]){

            return false;
        }
    }
    return true;
}
*/

int main(){

    std::cin >> date1 >> date2;

    for(int i = 1000; i < 10000; i++){

        int date = i;
        int temp = i;

        for(int i = 1; i <= 4; i++){
            
            date = date * 10 + temp % 10;
            temp /= 10;
        }
        if(date >= date1 && date <= date2 && is_date(date)){

           res++;
        }
    }
    std::cout << res << std::endl;
    return 0;
}