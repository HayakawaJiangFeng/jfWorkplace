#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

int A,B,C;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_date(int date){

    int year = date / 10000;
    int month = date % 10000 / 100;
    int day = date % 100;

    if(day == 0 || month == 0 || month > 12) return false;
    if(month != 2){
        if(day > days[month]) return false;
    }
    if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0 && month == 2)){

        if(day > 29) return false;
    }else{

        if(day > days[month]) return false;
    }
    return true;
}

int main(){

    scanf("%d/%d/%d", &A, &B, &C);

    for(int i = 19600101; i <= 20591231; i++){

        int year = i / 10000;
        int month = i % 10000 / 100;
        int day = i % 100;

        if(is_date(i)){

            if((year % 100 == A && month == B && day == C) || (year % 100 == C && month == A && day == B) || (year % 100 == C && month == B && day == A)){

                printf("%02d-%02d-%02d\n", year,month,day);
            }
        }
    }
    return 0;
}