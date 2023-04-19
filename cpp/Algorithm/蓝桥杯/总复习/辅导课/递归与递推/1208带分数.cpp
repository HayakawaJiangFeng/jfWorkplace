#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int n;
int res;
int ans[15];
int nums[4];
bool st[15];

/*
void dfs_abc(int x){

    if(x > 3){

        if(nums[1] + nums[2] + nums[3] == 9){

            int a = 0;
            int b = 0;
            int c = 0;

            for(int i = 1; i <= nums[1]; i++){

                a = a * 10 + ans[i];
            }
            for(int i = nums[1] + 1; i <= nums[2]; i++){

                b = b * 10 + ans[i];
            }
            for(int i = nums[1] + nums[2] + 1; i <= nums[3]; i++){

                c = c * 10 + ans[i];
            }
            
            if(c * n == c * a + b && a != 0 && b != 0 && c != 0){

                std::cout << a << " " << b << " " << " " << c << std::endl;
                res++;
            }
        }
        return;
    }
    for(int i = 1; i <= 7; i++){

        nums[x] = i;
        dfs_abc(x + 1);
        nums[x] = 0;
    }
}
*/
int calc(int l, int r){

    int sum = 0;
    for(int i = l; i <= r; i++){

        sum = sum * 10 + ans[i];
    }
    return sum;
}
void dfs(int x){

    if(x > 9){

        //dfs_abc(1);

        /*
        for(int i = 1; i <= 9; i++){

            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
        */
        for(int i = 1; i <= 9; i++){

            for(int j = i + 1; j <= 9; j++){

                int a = calc(1, i);
                int b = calc(i + 1, j);
                int c = calc(j + 1, 9);

                if(n * c == c * a + b){

                    res++;
                }
            }
        }
        return;
    }

    for(int i = 1; i <= 9; i++){

        if(!st[i]){

            st[i] = true;
            ans[x] = i;
            dfs(x + 1);
            ans[x] = 0;
            st[i] = false;
        }
    }
}
int main(){

    std::cin >> n;

    dfs(1);
    //dfs_abc(1);

    std::cout << res << std::endl;

    return 0;
}