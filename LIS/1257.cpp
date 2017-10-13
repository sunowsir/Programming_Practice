/*************************************************************************
    > File Name: 1257.cpp
    > Author: sunowsir
    > GitHub: github.com/sunowsir/practice 
    > Created Time: 2017年08月22日 星期二 11时23分42秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 3e4+10;
int a[maxn],dp[maxn];
int n;

void lis(){
	int ans=0;
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++)
			if(a[j] < a[i])
				dp[i]=max(dp[i],dp[j]+1);
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
}

int main(){
	while(cin>>n){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
			cin>>a[i];
		lis();
	}
	return 0;
}
