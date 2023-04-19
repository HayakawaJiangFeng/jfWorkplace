#include <iostream>

int is_WhatDay1(int year, int mouth, int day){

    int ans = 0;
    for(int i = 1; i < year; i++){
        
        if((i % 100 != 0 && i % 4 == 0) || i % 400 == 0){

            ans += 366 % 7;
            ans %= 7;
        }else{

            ans += 365 % 7;
            ans %= 7;
        }
    }
    for(int i = 1; i < mouth; i++){

        if(i == 1 || i || 3 || i == 5 || i || 7 || i || 8 || i == 10 || i == 12){

            ans += 31 % 7;
            ans %= 7;
        }else if(i == 4 || i == 6 || i == 9 || i == 11){

            ans += 30 % 7;
            ans %= 7;
        }else if(i == 2){
            if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)){

                ans += 29 % 7;
                ans %= 7;
            }else{

                ans += 28 % 7;
                ans %= 7;
            }
        }
    }
    ans += (day -1) % 7;
    ans %= 7;

    return ans;
}

int is_WhatDay2(int year, int mouth, int day){

    int w;
    
    if(mouth == 2){

        mouth = 14;
        year--;       
    }
    if(mouth == 1){

        mouth = 13;
        year--;
    }
    
    w = (day + 2 * mouth + 3 * (mouth + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;

    return w;
}

int main(){

    int year, mouth, day;
    std::cin >> year >> mouth >> day;

    std::string whatDay[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

    std::cout << whatDay[is_WhatDay1(year,mouth,day)] << std::endl;
    std::cout << whatDay[is_WhatDay2(year,mouth,day)] << std::endl;

    return 0;
}