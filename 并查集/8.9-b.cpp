/*************************************************************************
    > File Name: 8.9-b.cpp
    > Author: sunowsir
    > *** *** 
    > Created Time: 2017年08月09日 星期三 14时03分06秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3+10;

struct Node{
	int par,rank;
};

Node node[maxn];
bool book[maxn];

void init(int n){
	for(int i=0;i<n;i++){
		node[i].par=i;
		node[i].rank=0;
		book[i]=false;
	}
}

int find(int x){
	if(node[x].par==x)  return x;
	else  return node[x].par=find(node[x].par);
}

void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)  return;
	if(node[x].rank<node[y].rank)  node[x].par=y;
	else{
		node[y].par=x;
		if(node[x].rank==node[y].rank)  node[x].rank++;
	}
}

int main(){
	int n,m,x,y;
	while(scanf("%d",&n) &&n!=0){
		scanf("%d",&m);
		init(n);
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			x--,y--;
			unite(x,y);
		}
		int ans=0,tmp=0;
		for(int i=0;i<n;i++){
			tmp=find(i);
			if(!book[tmp]){
				book[tmp]=true;
				ans++;
			}
		}
		ans--;
		printf("%d\n",ans);
	}
	return 0;
}
