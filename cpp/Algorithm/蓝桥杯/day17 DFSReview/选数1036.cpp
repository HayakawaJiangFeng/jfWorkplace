/*
题目描述

已知 
n
n 个整数 
x
1
,
x
2
,
⋯
 
,
x
n
x 
1
​	
 ,x 
2
​	
 ,⋯,x 
n
​	
 ，以及 
1
1 个整数 
k
k（
k
<
n
k<n）。从 
n
n 个整数中任选 
k
k 个整数相加，可分别得到一系列的和。例如当 
n
=
4
n=4，
k
=
3
k=3，
4
4 个整数分别为 
3
,
7
,
12
,
19
3,7,12,19 时，可得全部的组合与它们的和为：

3
+
7
+
12
=
22
3+7+12=22

3
+
7
+
19
=
29
3+7+19=29

7
+
12
+
19
=
38
7+12+19=38

3
+
12
+
19
=
34
3+12+19=34

现在，要求你计算出和为素数共有多少种。

例如上例，只有一种的和为素数：
3
+
7
+
19
=
29
3+7+19=29。

输入格式

第一行两个空格隔开的整数 
n
,
k
n,k（
1
≤
n
≤
20
1≤n≤20，
k
<
n
k<n）。

第二行 
n
n 个整数，分别为 
x
1
,
x
2
,
⋯
 
,
x
n
x 
1
​	
 ,x 
2
​	
 ,⋯,x 
n
​	
 （
1
≤
x
i
≤
5
×
1
0
6
1≤x 
i
​	
 ≤5×10 
6
 ）。

输出格式

输出一个整数，表示种类数。
*/

#include <iostream>

int n,k;
int numbers[25];
int ans[25];
int res;

bool is_prime(int number){
    
    if(number < 2){

        return false;
    }
    for(int i = 2; i < number / i; i++){

        if(number % i == 0){

            return false;
        }
    }
    return true;
}

void dfs(int x,int start){

    if(x == k){

        int sum = 0;
        for(int i = 0; i < k; i++){

            sum += ans[i];
        }
        if(is_prime(sum)){

            res++;
        }
        return;
    }
    for(int i = start; i < n; i++){

        ans[x] = numbers[i];
        dfs(x + 1, i + 1);
        ans[x] = 0;
    }
}
int main(){

    std::cin >> n >> k;

    for(int i = 0; i < n; i++){

        std::cin >> numbers[i];
    }   

    dfs(0,0);

    std::cout << res << std::endl;
    return 0;
}