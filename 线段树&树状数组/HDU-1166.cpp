/*************************************************************************
    > File Name: 1166.cpp
    > Author: sunowsir
    > *** *** 
    > Created Time: 2017年08月09日 星期三 16时34分35秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define cls(x,y) memset(x,y,sizeof(x))
const int maxn = 50005;
int n,bit[maxn];

int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i -= i & (-i);
	}
	return s;
}

void update(int i,int x){
	while(i<=n){
		bit[i] += x;
		i += i & (-i);
	}
}

int main(){
	int t,m,N=1;
	string str;
	scanf("%d",&t);
	while(t--){
		cls(bit,0);
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d",&m);
			update(i,m);//不断输入的同时也就相当于把每一个点加上一个值
		}
		int x,y;
		printf("Case %d:\n",N++);
		while(cin>>str&&str!="End"){
			scanf("%d%d",&x,&y);
			if(str=="Add")  update(x,y);
			if(str=="Sub")  update(x,-y);
			if(str=="Query")  printf("%d\n",sum(y)-sum(x-1));
		}
	}
	return 0;
}
