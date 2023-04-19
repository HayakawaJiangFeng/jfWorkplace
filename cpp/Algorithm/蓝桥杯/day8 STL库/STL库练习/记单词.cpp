#include <iostream>
#include <string>
#include <set>

//记n个单词，输入0 + 单词为记录单词，输入1 + 单词为询问是否记录了此单词

std::set<std::string> s1;
int main(){

    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){

        int flag;
        std::string word;
        std::cin >> flag >> word;

        for(int i = 0; i < word.size(); i++){

            if(word[i] >= 'A' && word[i] <= 'Z'){

                word[i] = 'a' + (word[i] - 'A');
            }
        }
        if(flag == 0){

            s1.insert(word);
        }else{

            if(s1.count(word)){

                std::cout << "YES" << std::endl;
            }else{

                std::cout << "NO" << std::endl;
            }
        }
    }
    
    return 0;
}