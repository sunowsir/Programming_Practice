/*************************************************************************
    > File Name: h-h.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年07月28日 星期五 17时36分11秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
#define cls(x) memset(x,0,sizeof(x))

int main(){
	int n,m=0,a[maxn];
	while(cin>>n&&n!=0){
		a[0]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==a[i-1])  ans+=5;
			else if(a[i]>a[i-1])  ans+=(a[i]-a[i-1])*6+5;
			else  ans+=(a[i-1]-a[i])*4+5;
		}
		cout<<ans<<endl;
	}
}
