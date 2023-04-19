#include <iostream>
#include <vector>

int res;
long long n;
std::vector<long long> v;

int main(){

    std::cin >> n;

    for(long long i = 1; i * i <= n ; i++){

        if(n % i == 0){

            v.push_back(i);
            if(n % i != i){

                v.push_back(n / i);
            }
        }
    }

    for(long i = 0; i < v.size(); i++){

        for(int j = 0; j < v.size(); j++){

            for(int k = 0; k < v.size(); k++){

                if(v[i] * v[j] * v[k] == n){

                    res++;
                }
            }
        }
    }

    std::cout << res << std::endl;
    return 0;
}