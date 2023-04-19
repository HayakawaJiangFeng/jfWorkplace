#include <iostream>
#include "workerManager.h"

int main(){

    WorkerManager wm;

    int flag = 0;
    while(1){

        wm.workerManager_ShowMenu();
        std::cout << "Please enter your choice : " << std::endl;
        std::cin >> flag;

        switch (flag)
        {
        case 0:
            wm.workerManager_ExitSystem();
            break;
        case 1:
            wm.workerManager_AddEmp();
            break;
        case 2:
            wm.workerManager_ShowEmp();
            break;
        case 3:
            wm.workerManager_DelEmp();
            break;
        case 4:
            wm.workerManager_Update();
            break;
        case 5:
            wm.workerManager_LocateEmp();
            break;
        case 6:
            break;
        case 7:
            wm.workerManager_ClearFile();
            break;
        default:
            system("clear");
            break;
        }
    }

    return 0;
}