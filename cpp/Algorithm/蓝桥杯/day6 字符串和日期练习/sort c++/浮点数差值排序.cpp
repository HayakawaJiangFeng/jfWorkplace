#include <cstdio>
#include <algorithm>
#include <cmath>

//常量，用来判断浮点数是否相等,<EPSILON则认为两个浮点数相等
const double  EPSILON = 1e-6;
int nums[105] = {};

bool cmp(double x, double y){

    double dx = fabs(x - round(x));
    double dy = fabs(y - round(y));
    
    //判断x和y是否相等
    if(fabs(dx-dy) < EPSILON){

        return x < y;
    }else{

        return x > y;
    }
}
int main(){

    int number = 0;
    scanf("%d",number);

    for(int i = 0; i < number; i++){

        scanf("%lf",&nums[i]);
    }
    std::sort(nums,nums + number,cmp);
    for(int i = 0; i < number; i++){

        if(i != number - 1){

            printf("%lf ",nums[i]);
        }else{

            printf("%lf\n",nums[i]);
        }
    }

    return 0;
}

