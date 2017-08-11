/*************************************************************************
    > File Name: c-c.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年07月28日 星期五 14时28分27秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

map<string,int> m;

int main(){
	int t;
	while(cin>>t){
		if(t==0)  break;
		string str,ans;
		for(int i=0;i<t;i++){
			cin>>str;
			m[str]++;
		}
		int ansnum=-1;//second
		map<string,int>::iterator it;
		for(it=m.begin();it!=m.end();it++){
			if(ansnum < it->second){
				ansnum=it->second;
				ans=it->first;
			}
		}
		cout<<ans<<endl;
		m.clear();
	}
	return 0;
}
