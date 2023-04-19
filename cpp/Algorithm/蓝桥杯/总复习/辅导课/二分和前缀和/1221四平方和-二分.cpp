#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int Max = 2500010;

int n,m;

struct cd
{

    bool operator<(const cd &temp){

        if(sum != temp.sum){

            return sum < temp.sum;
        }
        else if(c != temp.c){

            return c < temp.c;
        }else{

            return d < temp.d;
        }
    }

    int sum;
    int c;
    int d;

}cd[Max];

int main(){

    std::cin >> n;

    for(int c = 0; c * c <= n; c++){

        for(int d = c; d * d + c * c <= n; d++){

            struct cd cd_temp = {c * c + d * d,c,d};
            cd[m++] = cd_temp;
        }
    }
    std::sort(cd,cd + m);
    for(int a = 0; a * a <= n; a++){

        for(int b = a; b * b + a * a<= n; b++){

            int temp = n - (b * b + a * a);
            int left = 0;
            int right = m - 1;

            while (left < right)
            {
                 int mid = (left + right) / 2;

                 if(cd[mid].sum >= temp){

                    right = mid;
                 }else{

                    left = mid + 1;
                 }
            }
            if(cd[left].sum == temp){

                std::cout << a << " " << b << " " << cd[left].c << " " << cd[right].d << std::endl;
                return 0;
            }
        }
    }
    return 0;
}