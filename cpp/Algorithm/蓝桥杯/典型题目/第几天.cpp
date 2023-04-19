#include <iostream>

bool is_LeapYear(int year){

    if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)){
        
        return true;
    }else{

        return false;
    }
}
int main(){

    int ans = 4;
    for(int i = 1; i <= 4; i++){

        if(i == 1 || i == 3){

            ans += 31;
        }
        if(i == 2){

            if(is_LeapYear(2000)){

                ans += 29;
            }else{

                ans += 28;
            }
        }
        if(i == 4){

            ans += 30;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}