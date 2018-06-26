/*************************************************************************
    > File Name: 7-29-f.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年07月29日 星期六 15时43分50秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define cls(x,y) memset(x,y,sizeof(x))
const int maxn = 0x3f3f3f;
int n,m;
int cost[110][110];
int res,pos,minlow;
int low[maxn];

int prim(){
	res=0,low[1]=0,pos=1;
	//把1作为首个顶点
	for(int i=2;i<=n;i++)
		low[i]=cost[1][i];
	for(int i=1;i<n;i++){
		minlow=maxn;
		pos=0;
		//找出当前pos到剩余没有遍历过的所有点的所有边的权值的最小值
		for(int j=2;j<=n;j++){
			 //判断该点是否是曾经的pos
			 //若不是，判断这些不是的点到pos边的权值的最小值
			 if(low[j]!=0&&minlow>low[j]){
				 //把最小权值的边的权值赋值给min；
				 minlow=low[j];
				 //把该点作为下一个pos；
				 pos=j;
			 }
		}
		//如果pos身上没有边，那么pos就根本找不到
		if(minlow==maxn)  return  printf("?\n");
		//注意此时的pos已经是下一个pos了
		//把老pos到新pos的边权值加到res中；
		res+=minlow;
		//把新pos标记；
		low[pos]=0;
		//更新权值
		for(int j=2;j<=n;j++){
			//如果此时的该点不是曾经的pos，
			//low[j]:该点到老pos边的权值；
			//cost[pos][j]：该点导新pos的边的权值；
			//由于老pos和新pos是相连的并且是老pos身上的边的权值最小的边
			//所以选择low[j]和cost[pos][j]中权值最小的边
			if(low[j]>cost[pos][j])
				low[j]=cost[pos][j];
		}
	}
	return  printf("%d\n",res);
}

int main(){
	int a,b,c;
	while(cin>>m>>n&&m!=0){
		cls(cost,maxn);
		//输入边的权值
		for(int i=1;i<=m;i++){
			cin>>a>>b>>c;
			cost[a][b]=cost[b][a]=c;
		}
		prim();
	}
	return 0;
}
