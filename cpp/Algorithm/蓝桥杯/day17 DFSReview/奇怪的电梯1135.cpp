/*
题目描述

呵呵，有一天我做了一个梦，梦见了一种很奇怪的电梯。大楼的每一层楼都可以停电梯，而且第 
i
i 层楼（
1
≤
i
≤
N
1≤i≤N）上有一个数字 
K
i
K 
i
​	
 （
0
≤
K
i
≤
N
0≤K 
i
​	
 ≤N）。电梯只有四个按钮：开，关，上，下。上下的层数等于当前楼层上的那个数字。当然，如果不能满足要求，相应的按钮就会失灵。例如： 
3
,
3
,
1
,
2
,
5
3,3,1,2,5 代表了 
K
i
K 
i
​	
 （
K
1
=
3
K 
1
​	
 =3，
K
2
=
3
K 
2
​	
 =3，……），从 
1
1 楼开始。在 
1
1 楼，按“上”可以到 
4
4 楼，按“下”是不起作用的，因为没有 
−
2
−2 楼。那么，从 
A
A 楼到 
B
B 楼至少要按几次按钮呢？

输入格式

共二行。

第一行为三个用空格隔开的正整数，表示 
N
,
A
,
B
N,A,B（
1
≤
N
≤
200
1≤N≤200，
1
≤
A
,
B
≤
N
1≤A,B≤N）。

第二行为 
N
N 个用空格隔开的非负整数，表示 
K
i
K 
i
​	
 。

输出格式

一行，即最少按键次数，若无法到达，则输出 -1。


*/

#include <iostream>

int N,A,B;
int values[205];
int res = 1e9;
bool visit[205];

void dfs(int x, int cnt){

    if(cnt >= res){

        return;
    }
    if(x < 0 || x > N){

        return;
    }
    if(x == B){

        res = std::min(res ,cnt);
        return;
    }

    //向上
    if(x + values[x] <= N && !visit[x + values[x]]){

        visit[x + values[x]] = true;
        dfs(x + values[x], cnt + 1);
        visit[x + values[x]] = false;
    }

    //向下
    if(x - values[x] > 0 && !visit[x + values[x]]){

        visit[x - values[x]] = true;
        dfs(x - values[x], cnt + 1);
        visit[x - values[x]] = false;
    }

}

int main(){

    std::cin >> N >> A >> B;

    for(int i = 1; i <= N; i++){

        std::cin >> values[i];
    }

    dfs(A,0);
    
    if(res == 1e9){

        std::cout << -1 << std::endl;
    }else{

        std::cout << res << std::endl;
    }

    return 0;
}