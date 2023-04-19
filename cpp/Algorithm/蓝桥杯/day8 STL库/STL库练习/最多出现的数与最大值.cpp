#include <map>
#include <iostream>

//输入一堆数，可能会有重复，输出最多出现次数的数字，若出现的次数一样，输出最大的那个

std::map<int,int> m1;

int main(){

    int n,ans1,ans2;
    std::cin >> n;
    ans1 = 0;
    for(int i = 0; i < n; i++){

        int num;
        std::cin >> num;
        m1[num]++;
    }
    for(std::map<int, int>::iterator it = m1.begin(); it != m1.end(); it++){

        if(it->second >= ans1){

            ans1 = it->second;
            ans2 = it->first;
        }
    }
    std::cout << ans2 << " " << ans1 << std::endl;

    return 0;
}