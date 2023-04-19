#include <iostream>

int n,m;
int res;

int ans[100];
int numbers[100];

bool is_prime(int num){

    if(num < 2){

        return false;
    }
    for(int i = 2; i < num / i; i++){

        if(num % i == 0){

            return false;
        }
    }
    return true;
}
void dfs(int x, int start){

    if(x > m){

        int sum = 0;
        for(int i = 1; i <= m; i++){

            sum += ans[i];
        }
        if(is_prime(sum)){

            res++;
        }
        return;
    }
    for(int i = start; i <= n; i++){

        ans[x] = numbers[i];
        dfs(x + 1, i + 1);
        ans[x] = 0;
    }
}
int main(){

    std::cin >> n >> m;
    
    for(int i = 1; i <= n; i++){

        std::cin >> numbers[i];
    }

    dfs(1,1);

    std::cout << res << std::endl;
    return 0;
}

/*
#include <iostream>

int numbers[100];
int ans[100];
int n,k;
int res;

bool is_prime(int x){

    if(x < 2){

        return false;
    }
    for(int i = 2; i <= x / i; i++){

        if(x % i == 0){

            return false;
        }
    }
    return true;
}
void dfs(int x, int start){

    if(x > k){

        int sum = 0;
        for(int i = 1; i <= k; i++){

            sum += ans[i];
        }
        if(is_prime(sum)){

            res++;
        }
        return;
    }
    for(int i = start; i <= n; i++){

        ans[x] = numbers[i];
        dfs(x + 1, i + 1);
        ans[x] = 0;
    }

}

int main(){

    std::cin >> n >> k;
    for(int i = 1; i <= n; i++){

        std::cin >> numbers[i];
    }

    dfs(1,1);
    
    std::cout << res << std::endl;

    return 0;
}
*/