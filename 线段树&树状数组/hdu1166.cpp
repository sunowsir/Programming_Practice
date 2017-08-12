/*************************************************************************
    > File Name: hdu1166.cpp
    > Author: sunowsir
    > GitHub: https://github.com/sunowsir/pratice
    > Created Time: 2017年08月12日 星期六 13时08分04秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define cls(x,y) memset(x,y,sizeof(x))
const int maxn = 5e4+10;
int bit[maxn];
int n;

int sum(int i){
	int s=0;
	while(i>0){
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i,int x){
	while(i<=n){
		bit[i] += x;
		i += i & -i;
	}
}

int main(){
	int t,N,tmp;
	N=1;
	cin>>t;
	while(t--){
		cls(bit,0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>tmp;
			add(i,tmp);
		}
		string str;
		int i,j;
		printf("Case %d:\n",N++);
		while(cin>>str && str!="End"){
			cin>>i>>j;
			if(str == "Add")  add(i,j);
			else if(str == "Sub")  add(i,-j);
			else  cout<<sum(j)-sum(i-1)<<endl;
		}
	}
	return 0;
}
