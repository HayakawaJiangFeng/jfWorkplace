#include <iostream>
#include <fstream>

//读写文件

/**
1. 头文件 <fstream>
2. 创建流对象 ofstream ofs / istream ifs;
3. 打开文件 ofs / ifs .open("文件路径",打开方式)
4. 写数据 ofs << "写入的数据"
5. ofs / ifs .close();

打开方式：
    ios::in     为读文件打开
    ios::out    为写文件打开
    ios::ate    初始位置：文件尾
    ios::trunc  若文件已经存在，则删除再新建
    ios::app    以追加的方式写文件
    ios::binary 以二进制的方式
*/
void test1(){

    //写文件
    std::ofstream ofs;
    ofs.open("test.txt",std::ios::out);

    ofs << "name : jiangfeng" << std::endl;
    ofs << "sex : female" << std::endl;
    ofs << "age : 19" << std::endl;

    ofs.close();
}

void test2(){

    //读文件
    std::ifstream ifs;
    ifs.open("test.txt",std::ios::in);

    if(!ifs.is_open()){

        std::cout << "文件打开失败" << std::endl;
    }

    //读数据
    //第一种
    //char buf[1024] = {0};
    /*
    while(ifs >> buf){

        std::cout << buf << std::endl;
    }
    */

    //第二种
    /*
    while(ifs.getline(buf,sizeof(buf))){

        std::cout << buf << std::endl;
    }
    */

    //第三种
    /*
    std::string buf;
    while(getline(ifs,buf)){

        std::cout << buf << std::endl;
    }
    */

    //第四种
    char c;
    while(EOF != (c = ifs.get())){

        std::cout << c;
    }

    ifs.close();
}
int main(){

    test1();
    test2();
    return 0;
}