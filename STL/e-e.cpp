/*************************************************************************
    > File Name: e-e.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年07月28日 星期五 15时28分59秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

set<string> se;

void word(string str){
	se.clear();
	string tmp="";
	for(int i=0;i<=str.size();i++){
		if(str[i]==' '||i==str.size()){
			if(tmp=="")  continue;
			se.insert(tmp);
			tmp="";
		}
		else  tmp+=str[i];
	}
	cout<<se.size()<<endl;
}

int main(){
	string str;
	while(getline(cin,str)&&str[0]!='#')
		word(str);
	return 0;
}
