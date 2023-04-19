#include <iostream>
#include <stack>

std::stack<int> st;
char ch[1005];
int nums[1005];

int main(){

    std::cin >> ch;
    bool flag = 1;
    int len = strlen(ch);
    for(int i = 0; i < len; i++){

        if(ch[i] == '('){

            st.push(i + 1);
        }else{

            if(!st.empty()){

                nums[i + 1] = st.top();
                st.pop(); 
            }else{

                flag = 0;
                break;
            }
        }
    }
    if(flag){
        
        std::cout << "YES" << std::endl;
    }else{

        std::cout << "NO" << std::endl;
    }
    for(int i = 1; i <= len; i++){

        if(nums[i]){

            std::cout << nums[i] << " " << i << std::endl;
        }
    }
    return 0;
}