#include <iostream>
#include <string>

int start;
int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool is_LeapYear(int year){

    if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)){

        return true;
    }
    return false;
}

bool check_valid(int date){

    int year = date / 10000;
    int month = date % 10000 / 100;
    int day = date % 100;

    if(day == 0 || month > 12 || month <= 0 || year >= 9220 || year <= 1000){

        return false;
    }
    if(month != 2 && months[month] < day){

        return false;
    }
    if(month == 2){

        if(is_LeapYear(year)){

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

bool is_Hw(std::string date){

    int len = date.size();
    for(int i = 0, j = len - 1; i < j; i++,j--){

        if(date[i] != date[j]){

            return false;
        }
    }
    return true;
}
bool is_ABAB(std::string date){

    if(is_Hw(date)){

        if(date[0] != date[2] || date[1] != date[3] || date[1] == date[2]){
            
            return false;
        }else{

            return true;
        }
    }
    return false;
}
int main(){

    std::cin >> start;
    int flag = true;
    for(int i = start + 1;;i++){

        if(check_valid(i)){

            std::string temp = std::to_string(i);
            if(is_Hw(temp) && flag){

                flag = false;
                std::cout << i << std::endl;
            }
            if(is_ABAB(temp)){

                std::cout << i << std::endl;
                return 0;
            }
        }
    }
    return 0;
}
