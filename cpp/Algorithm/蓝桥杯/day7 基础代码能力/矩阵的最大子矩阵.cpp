#include <iostream>

int array[55][55];

int main(){

    int low, column, ans;
    ans = -1005;
    std::cin >> low >> column;

    for(int i = 0; i < low; i++){

        for(int j = 0; j < column; j++){

            std::cin >> array[i][j];
        }
    }

    for(int i = 0; i < low; i++){

        for(int j = i; j < low; j++){

            for(int k = 0; k < column; k++){

                for(int l = k; l < column; l++){

                    int temp = 0;
                    for(int p = i; p <= j; p++){

                        for(int q = k; q <= l; q++){

                            temp += array[p][q];
                        }
                    }
                    if(temp > ans){

                        ans = temp;
                    }
                }
            }
        }
    }
    
    std::cout << ans << std::endl;
    return 0;
}