#include <cstdio>
#include <set>

std::set<int> s1;
std::set<int> s2;
std::set<int> s3;
int main(){

    int num1, num2;
    scanf("%d",&num1);
    scanf("%d",&num2);

    for(int i = 0; i < num1; i++){

        int nums;
        scanf("%d",&nums);

        s1.insert(nums);
    }
    for(int i = 0; i < num2; i++){

        int nums;
        scanf("%d",&nums);

        s2.insert(nums);
    }
    for(std::set<int>::iterator it = s1.begin(); it != s1.end(); it++){

        s3.insert(*it);
    }
    for(std::set<int>::iterator it = s2.begin(); it != s2.end(); it++){

        s3.insert(*it);
    }

    for(std::set<int>::iterator it = s3.begin(); it != s3.end(); it++){

        printf("%d ",*it);
    }
    printf("\n");

    return 0;
}