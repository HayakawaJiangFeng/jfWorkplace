#include <iostream>

int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool is_LeapYear(int date){

    if(date % 400 == 0 || (date % 100 != 0 && date % 4 == 0)){

        return true;
    }
    return false;
}

bool check_valid(int date){

    int year = date / 10000;
    int month = date % 10000 / 100;
    int day = date % 100;

    if(day <= 0 || month <= 0 || month > 12){

        return false;
    }
    if(month != 2){

        if(day > months[month]){

          return false;
        }
    }
    if(month == 2){

        if(is_LeapYear(year)){

            if(day > 29){

                return false;
            }else{

                return true;
            }
        }else{

            if(day > 28){

                return false;
            }else{
                
                return true;
            }
        }
    }
    return true;
}
int main(){

    int year,month,day;
    scanf("%d/%d/%d", &year,&month,&day);

    for(int i = 19600101; i <= 20591231; i++){

        if(check_valid(i)){

            int ty = i / 10000;
            int tm = i % 10000 / 100;
            int td = i % 100;

            if((ty % 100 == year && tm == month && td == day) || (tm == year && td == month && ty % 100 == day) || (td == year && tm == month && ty % 100 == day)){

                printf("%d-%02d-%02d\n",ty,tm,td);
            }
        }
    }
    return 0;
}