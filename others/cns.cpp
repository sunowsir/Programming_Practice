/*************************************************************************
	> File Name: cns.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年03月16日 星期五 15时26分19秒
 ************************************************************************/

//进制转换,n有可能为负；

#include <iostream>
#include <algorithm> //反转函数头文件；
#include <cstring>   
#include <cstdio>    //整形变量转字符函数“sprintf”头文件；
#include <map>
using namespace std;

int main() {

    int n, r;
    string str_num;
    map<int, char> m;
    str_num = "";
    for(int i = 0; i < 16; i++) {
        if(i > 9) {
            m[i] = 'A' + i - 10;
        }
        else {
            char temp[2];
            sprintf(temp, "%d", i);
            m[i] = temp[0];
        }
        //cout << "m[i] = " << m[i] << endl;
    }

    cin >> n >> r;

    bool pom = true;
    if(n < 0) {
        n = abs(n);
        pom = false;
    }

    while(n) {
        str_num.push_back(m[n % r]);
        n = n / r;
    }
    
    if(str_num == "") {
        cout << 0 << endl;
    }
    else {
        
        if(!pom) {
            str_num.push_back('-');
        }
        //反转；
        reverse(str_num.begin(), str_num.end());
        
        cout << str_num << endl;
    }


    return 0;
}
