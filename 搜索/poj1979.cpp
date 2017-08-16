/*************************************************************************
    > File Name: poj1979.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年07月08日 星期六 16时04分20秒
 ************************************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define cls(x,y) memset(x,y,sizeof(x))
const int maxn = 100;
char mp[maxn][maxn];
int nx[4]={0,0,-1,1};
int ny[4]={1,-1,0,0};
int n,m,ans;
bool book[maxn][maxn];

int dfs(int x,int y){
	//每调用一次dfs函数都记一下个数，调用几次就是成功搜索几次。
	ans++;
	//此次调用时传入的x和y作为此次搜索的中心点，此次搜索的方向都是以这个x和y为标志物，是该点的上下左右。
	//把该点标记，表示已经搜索过。
	book[x][y] = true;
	for(int i=0;i<4;i++){
		int dx,dy;
		//x和y分别赋值上nx[i]和ny[i]dx和dy就变成了x和y的上下左右方向。
		dx=x+nx[i];
		dy=y+ny[i];
		//1.判断该方向的点（此时的dx和dy）是不是还在地图中
		//2.判断该方向上的点是不是'.'（不懂去看题目要干啥）
		//3.判断该方向上的点搜没搜索过（用book[]来标记看第26行）
		if(dx>=0 && dx<m && dy>=0 && dy<n && mp[dx][dy]=='.' && !book[dx][dy])
			//如果这些条件都符合，把该方向上的点作为中心点，调用dfs。
			dfs(dx,dy);
	}
	return ans;
}

int main(){
	int x,y;
	while(scanf("%d%d",&n,&m) && n && m){
		cls(book,false);
		cls(mp,0);
		ans=0;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
				cin>>mp[i][j];
				if(mp[i][j] == '@'){
					x=i;
					y=j;
				}
			}
		cout<<dfs(x,y)<<endl;
	}
	return 0;
}
