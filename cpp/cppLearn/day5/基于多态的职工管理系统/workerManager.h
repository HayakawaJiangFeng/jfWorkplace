#pragma once
#include <iostream>
#include <unistd.h>
#include <fstream>
#include "worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

#define FILENAME "empFile.txt" 

class WorkerManager{

public :

    //构造函数
    WorkerManager();

    //展示菜单函数
    void workerManager_ShowMenu(); 

    //退出系统函数
    void workerManager_ExitSystem();

    //添加员工函数
    void workerManager_AddEmp();

    //显示员工函数
    void workerManager_ShowEmp();

    //判断员工是否存在函数
    int workerManager_IsExit(int id);

    //删除员工函数
    void workerManager_DelEmp();

    //修改职工信息函数
    void workerManager_Update();

    //查找员工函数
    void workerManager_LocateEmp();

    //保存数据函数
    void workerManager_Save();

    //初始化员工函数
    void workerManager_InitEmp();
    //析构函数
    ~WorkerManager();

    //记录文件中的人数个数
    int empNum;

    //统计文件中的人数
    int workerManager_getFileEmpNum();

    //清空文件函数
    void workerManager_ClearFile();

    //员工数组的指针
    Worker** empArray;


    //标志文件是否为空
    bool fileIsEmpty;

};