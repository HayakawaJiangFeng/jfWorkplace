#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

int date1;
int date2;

bool is_date(int date){

    int year = date / 1000;
    int month = date / 100 % 100;
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
bool is_rev(int date){

    std::string dateStr = std::to_string(date);
    
    for(int i = 0, j = 7; i < 4; i++,j--){

        if(dateStr[i] != dateStr[j]){

            return false;
        }
    }
    return true;
}
int main(){

    int res = 0;
    std::cin >> date1;
    std::cin >> date2;

    for(int i = date1; i <= date2; i++){

        if(is_rev(i)){

            if(is_date(i)){

                res++;
            }
        }
    }

    std::cout << res << std::endl;

    return 0;
}
