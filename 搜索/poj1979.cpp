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
	ans++;
	book[x][y] = true;
	for(int i=0;i<4;i++){
		int dx,dy;
		dx=x+nx[i];
		dy=y+ny[i];
		if(dx>=0 && dx<m && dy>=0 && dy<n && mp[dx][dy]=='.' && !book[dx][dy])
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
