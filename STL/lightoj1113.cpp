/*************************************************************************
    > File Name: lightoj1113.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年07月07日 星期五 13时44分27秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

stack<string> sb,sf;
queue<string> ss;

int main(){
	int n,N;
	string s,web;
	cin>>n;
	N=1;
	while(n--){
		//把首页入栈；
		sb.push("http://www.lightoj.com/");
		cout<<"Case "<<N++<<":"<<endl;
		while(1){
			cin>>s;
			if(s=="VISIT"){
				cin>>web;
				sb.push(web);
				while(!sf.empty())  sf.pop();//根据题意，当back空了后再插入后，之前的网址也回不去了；
				cout<<web<<endl;
			}
			if(s=="BACK"){
				if(!sb.empty()){
					sf.push(sb.top());
					sb.pop();
					//保证首页是题目所给不被pop掉；
					if(sb.empty()){
						sb.push(sf.top());
						sf.pop();
						cout<<"Ignored"<<endl;
					}
					else  cout<<sb.top()<<endl;
				}
			}
			if(s=="FORWARD"){
				if(!sf.empty()){
					sb.push(sf.top());
					sf.pop();
					cout<<sb.top()<<endl;
				}
				else  cout<<"Ignored"<<endl;
			}
			ss.push(sb.top());
			if(s=="QUIT")  break;
		}
		//把两个栈清空；
		while(!sb.empty())  sb.pop();
		while(!sf.empty())  sf.pop();
	}
	return 0;
}
