#include "workerManager.h"

WorkerManager::WorkerManager(){

    std::ifstream ifs;
    ifs.open(FILENAME, std::ios::in);

    //文件不存在的初始化
    if(!ifs.is_open()){

        std::cout << "文件不存在" << std::endl;

        //初始化
        this->empNum = 0;
        this->empArray = nullptr;
        this->fileIsEmpty = true;

        ifs.close();

        return;
    }

    //文件存在但是文件为空的初始化
    char ch;
    //读一个字符
    ifs >> ch;
    //如果这个字符是文件结尾标识符，则此文件为空
    if(ch == ifs.eof()){

        std::cout << "文件为空" << std::endl;

        //初始化
        this->empNum = 0;
        this->empArray = nullptr;
        this->fileIsEmpty = true;

        ifs.close();

        return;
    }

    //文件存在，并且文件中有数据
    int fileEmpNum = this->workerManager_getFileEmpNum();
    std::cout << "文件中已有员工人数 : " << fileEmpNum << std::endl;

    this->empNum = fileEmpNum;

    //开辟空间
    this->empArray = new Worker*[this->empNum];

    //将文件中的数据放入数组中
    this->workerManager_InitEmp();

    for(int i = 0; i < empNum; i++){

        std::cout << i << " " << empArray[i]->name << " " << empArray[i]->id << " " << empArray[i]->wdtId
                    << std::endl;
        
    }

}

void WorkerManager::workerManager_InitEmp(){

    std::ifstream ifs;
    ifs.open(FILENAME, std::ios::in);

    int id;
    std::string name;
    int wdtId;

    int index = 0;

    while(ifs >> id && ifs >> name && ifs >> wdtId){

        Worker* worker = nullptr;

        if(wdtId == 1){ //employee

            worker = new Employee(name, id ,wdtId);
        }else if(wdtId == 2){ //manager

            worker = new Manager(name, id, wdtId);
        }else{

            worker = new Boss(name, id, wdtId);
        }
        this->empArray[index] = worker;
        index++;
    }
    ifs.close();
}
WorkerManager::~WorkerManager(){
}
    
void WorkerManager::workerManager_ShowMenu(){

    std::cout << "*****************************" << std::endl;
    std::cout << "*** 欢迎使用职工管理系统 ****" << std::endl;
    std::cout << "***** 0.退出管理系统 ********" << std::endl;
    std::cout << "***** 1.增加职工信息 ********" << std::endl;
    std::cout << "***** 2.显示职工信息 ********" << std::endl;
    std::cout << "***** 3.删除离职职工 ********" << std::endl;
    std::cout << "***** 4.修改职工信息 ********" << std::endl;
    std::cout << "***** 5.查找职工信息 ********" << std::endl;
    std::cout << "***** 6.按编号排序  *********" << std::endl;
    std::cout << "***** 7.清空文档    *********" << std::endl;
    std::cout << "*****************************" << std::endl;
    std::cout << std::endl;
}

void WorkerManager::workerManager_ExitSystem(){

    std::cout << "欢迎下次使用" << std::endl;
    exit(0);
}

int WorkerManager::workerManager_getFileEmpNum(){

    std::ifstream ifs;
    ifs.open(FILENAME, std::ios::in);

    std::string name;
    int id;
    int wdtId;
    int fileEmpNum = 0;

    while(ifs >> id && ifs >> name && ifs >> wdtId){

        fileEmpNum++;
    }
    return fileEmpNum;
}

void WorkerManager::workerManager_Save(){

    std::ofstream ofs;
    ofs.open(FILENAME, std::ios::out);

    for(int i = 0; i < this->empNum; i++){

        ofs << this->empArray[i]->id << " "
            << this->empArray[i]->name << " "
            << this->empArray[i]->wdtId << std::endl;
    }

    ofs.close();
}

void WorkerManager::workerManager_AddEmp(){

    std::cout << "请输入添加的员工的人数 : " << std::endl;

    int addNum = 0;
    std::cin >> addNum;

    if(addNum > 0){

        //计算新空间的大小
        int newSize = this->empNum + addNum;

        //开辟新空间
        Worker** newSpace = new Worker*[newSize];

        //如果有旧数据，将就数据拷贝到新空间
        if(this->empArray != nullptr){

            for(int i = 0; i < this->empNum; i++){

                newSpace[i] = this->empArray[i];
            }
        }

        //输入新数据
        for(int i = 0; i < addNum; i++){

            int id;
            std::string name;
            int userSelect;

            std::cout << "请输入第 " << i + 1 << " 个员工的编号 : " << std::endl;
            std::cin >> id;
            
            std::cout << "请输入第 " << i + 1 << " 个员工的姓名 : " << std::endl;
            std::cin >> name;

            std::cout << "请选择该员工的职位 : " << std::endl;
            std::cout << "1. employee" << std::endl;
            std::cout << "2. manager" << std::endl;
            std::cout << "3. boss" << std::endl;
            std::cin >> userSelect;

            Worker* worker = nullptr;
            switch (userSelect)
            {
            case 1:
                worker = new Employee(name,id,1);
                break;
            case 2:
                worker = new Manager(name,id,2);
                break;
            case 3:
                worker = new Boss(name,id,3);
                break;
            
            default:
                break;
            }

            newSpace[this->empNum + i] = worker; 
        }
        
        //释放原有空间
        delete[] this->empArray;

        //更新新空间的指向
        this->empArray = newSpace;

        //更新新的个数
        this->empNum = newSize;

        //更新文件标识
        this->fileIsEmpty = false;

        std::cout << "成功添加 " << addNum << " 名新职工" << std::endl;

        this->workerManager_Save();

    }else{

        std::cout << "ERROR : addNum < 0 !" << std::endl;
    }
}
void WorkerManager::workerManager_ShowEmp(){

    if(!this->fileIsEmpty){

        for(int i = 0; i < this->empNum; i++){

            this->empArray[i]->showInfo();
        }
    }else{

        std::cout << "文件为空或者不存在" << std::endl;
    }
}

int WorkerManager::workerManager_IsExit(int id){

    int index = -1;

    for(int i = 0; i < this->empNum; i++){

        if(this->empArray[i]->id == id){

            index = i;
            break;
        }
    }
    return index;
}

void WorkerManager::workerManager_DelEmp(){

    if(this->fileIsEmpty){

        std::cout << "文件不存在或者文件为空" << std::endl;
    }else{

        std::cout << "请输入你想删除职工的编号 : " << std::endl;
        
        int id;
        std::cin >> id;

        if(workerManager_IsExit(id) == -1){

            std::cout << "职工不存在" << std::endl;
        }else{

            int index = workerManager_IsExit(id);
            for(int i = index; i < this->empNum - 1; i++){

                empArray[i] = empArray[i + 1];
            }
            empNum--;
            this->workerManager_Save();
            std::cout << "删除成功" << std::endl;
        }
    }
}

void WorkerManager::workerManager_Update(){

    if(this->fileIsEmpty){

        std::cout << "文件不存在或者文件为空" << std::endl;
    }else{

        int id;
        std::cout << "请输入需要修改员工的编号 : " << std::endl;
        std::cin >> id;
        int index = this->workerManager_IsExit(id);

        if(index == -1){

            std::cout << "员工不存在" << std::endl;
        }else{

            delete this->empArray[index];
            Worker* worker = nullptr;
            int newId = 0;
            std::string name = "";
            int newWdtId = 0;

            std::cout << "找到编号为 : " << id << "的员工" << std::endl;
            std::cout << "请输入新编号 : " << std::endl;
            std::cin >> newId;
            std::cout << "请输入新名字 : " << std::endl;
            std::cin >> name;
            std::cout << "请输入新的部门编号 : " << std::endl;
            std::cin >> newWdtId;

            std::cout << "请输入岗位 : " << std::endl;
            std::cout << "1. 员工" << std::endl;
            std::cout << "2. 经理" << std::endl;
            std::cout << "3. 老板" << std::endl;
            int select;
            std::cin >> select;

            switch (select)
            {
            case 1:
                worker = new Employee(name,newId,newWdtId);
                break;
            case 2:
                worker = new Manager(name,newId,newWdtId);
                break;
            case 3:
                worker = new Boss(name,newId,newWdtId);
                break;
            default:
                break;
            }
            this->empArray[index] = worker;
            std::cout << "修改成功" << std::endl;
            this->workerManager_Save();
        }
    }
}
void WorkerManager::workerManager_LocateEmp(){

    if(this->fileIsEmpty){

        std::cout << "文件不存在或者文件为空" << std::endl;
    }else{

        std::cout << "请选择查找方式 : " << std::endl;
        std::cout << "1. 编号查找" << std::endl;
        std::cout << "2. 名字查找" << std::endl;

        int select;
        std::cin >> select;

        if(select == 1){

            std::cout << "请输入编号 : " << std::endl;
            int id;
            std::cin >> id;

            int index = workerManager_IsExit(id);
            if(index == -1){

                std::cout << "员工不存在" << std::endl;
            }else{

                std::cout << "查找成功，信息如下 : " << std::endl;
                this->empArray[index]->showInfo();
            }
        }else{

            std::cout << "请输入姓名 : " << std::endl;
            std::string name;
            std::cin >> name;

            bool flag = false;
            
            for(int i = 0; i < this->empNum; i++){

                if(empArray[i]->name == name){

                    flag = true;
                    std::cout << "查找成功，信息如下 : " << std::endl;
                    empArray[i]->showInfo();
                }
            }
            if(!flag){

                std::cout << "员工不存在" << std::endl;
            }
        }
    }
}

void WorkerManager::workerManager_ClearFile(){


    std::cout << "确定要清空文件(y/n) : " << std::endl;
    char ch;
    std::cin >> ch;

    if(ch == 'y'){

        std::ofstream ofs(FILENAME, std::ios::trunc);
        ofs.close();

        if(this->empArray != nullptr){

            for(int i = 0; i < this->empNum; i++){

                delete this->empArray[i];
            }
        }
        this->empNum = 0;
        delete[] this->empArray;
        this->empArray = nullptr;
        this->fileIsEmpty = true;
    }
    std::cout << "清空成功" << std::endl;
}