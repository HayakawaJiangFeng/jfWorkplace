#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

const int Max = 100010;

int values[Max];

int n,q;

int main(){

    std::cin >> n >> q;
    for(int i = 0; i < n; i++){

        std::cin >> values[i];
    }

    for(int i = 0; i < q; i++){

        int temp;
        std::cin >> temp;

        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            int mid = (left + right) >> 1;
            if(values[mid] >= temp){

                right = mid;
            }else{

                left = mid + 1;
            }
        }
        if(values[right] == temp){

            std::cout << right << " ";

            right = n - 1;

            while (left < right)
            {
                 int mid = (left + right + 1) >> 1;

                 if(values[mid] <= temp){

                    left = mid;
                 }else{

                    right = mid - 1;
                 }
            }
            std::cout << left << std::endl;
        }else{

            std::cout << "-1 -1" << std::endl;
        }
    }

    return 0;
}