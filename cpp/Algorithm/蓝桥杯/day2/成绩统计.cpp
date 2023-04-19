#include <iostream>
using namespace std;

int main(){

    //考试人数
    int numbers;
    cin >> numbers;

    int arr[numbers] = {0};
    for(int i = 0; i < numbers; i++){

        cin >> arr[i];
    }
    //统计及格的人数
    double x = 0;
    //统计优秀的人数
    double y = 0;
    //遍历成绩数组
    for(int i = 0; i < numbers; i++){

        if(arr[i] >= 60){

            x++;
        }
        if(arr[i] >= 85){

            y++;
        }
    }
    int x1 = (x / numbers) * 100.0 + 0.5;
    int y1 = (y / numbers) * 100.0 + 0.5;
    cout << x1 << "%" << endl;
    cout << y1 << "%" << endl;

    return 0;
}