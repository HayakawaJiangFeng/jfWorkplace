#include <iostream>
#include <string>
using namespace std;

int main(){
    
    //存储每个小写字母出现的次数
    int chars[26];

    //存储出现最大次数
    int max = 0;

    //存储出现最多次数的字母
    char maxChar;

    string word;
    cin >> word;

    //遍历字符串，计算每个字母出现的次数
    for(int i = 0; i < word.length(); i++){

        chars[word[i] - 'a']++;
    }
    
    //找到最大次数，和最多出现的字母
    for(int i = 25; i >= 0; i--){

        if(chars[i] >= max){

            max = chars[i];
            maxChar = char(i + 'a');
        }
    }
    cout << maxChar << endl;
    cout << max;
    return 0;
}
/*
#include <iostream>
#include <string> 

using namespace std;

int main()
{
    //数组a储存每个小写字母的出现次数 
    int a[26] = {0};
    //储存字符串 
    string arr;
    //储存最大出现次数 
    int max = 0;
    //储存出现次数最大的字母 
    char max_sp;
    //输入字符串 
    cin >> arr;
    //对字母串中的每个字符计数 
    for(int i = 0; i < arr.length(); i++)
    {
        a[arr[i] - 'a']++;
    }
    //找出最大出现次数 
    for(int i = 25; i >= 0; i--)
    {
        if(a[i] >= max)
        {
            max = a[i];
            max_sp = char(i + 'a');
        }
    }
    //找到出现次数最大的字典序最小的字母，输出它和它的出现次数 
    cout << max_sp << endl;
        cout << max;

  return 0;
}
*/
