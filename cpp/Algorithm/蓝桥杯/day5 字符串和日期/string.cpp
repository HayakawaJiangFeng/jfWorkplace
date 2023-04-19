#include <iostream>

//字符串复制
void test_strcpy(){

    char* name1 = "jiang";
    char name2[50] = {};

    std::strcpy(name2,name1);
    printf("%s\n",name2);
}

//字符串拼接
void test_strcat(){

    char* name1 = "jiang";
    char* name2 = " ";
    char* name3 = "feng";

    char name[50] = {};
    std::strcat(name,name1);
    std::strcat(name,name2);
    std::strcat(name,name3);
    
    printf("%s\n",name);
}

//字符串对比
void test_strcmp(){

    char* str1 = "aabb";
    char* str2 = "aabb";
    char* str3 = "aabc";

    int cmp12 = std::strcmp(str1,str2);
    //str1 - str3
    int cmp13 = std::strcmp(str1,str3);

    std::cout << cmp12 << std::endl;
    std::cout << cmp13 << std::endl;
}

//计算字符串长度
void test_strlen(){

    char* str = "jiangfeng";
    std::cout << std::strlen(str) << std::endl;
}
int main(){

    test_strcpy();
    test_strcat();
    test_strcmp();
    test_strlen();

    return 0;
}