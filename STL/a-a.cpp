/*************************************************************************
    > File Name: a-a.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年07月28日 星期五 14时02分57秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

set<int> se;

int main(){
	int n,m,a,b;
	while(cin>>n>>m){
		se.clear();
		for(int i=0;i<n;i++){
			cin>>a;
			se.insert(a);
		}
		for(int i=0;i<m;i++){
			cin>>b;
			se.insert(b);
		}
		int tmp=0;
		set<int>::iterator it;
		for(it=se.begin();it!=se.end();it++){
			if(tmp==1)  cout<<" ";
			tmp=1;
			cout<<*it;
		}
		cout<<endl;
	}
	return 0;
}
