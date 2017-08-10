# pratice
算法练习
//github初学，测试用代码
/*************************************************************************
    > File Name: team6-1011.cpp
    > Author: sunowsir
    > *** *** 
    > Created Time: 2017年08月10日 星期四 13时08分19秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;


int main(){
	int t,n,ans,maxc;
	int a1,a2,a3,a4,a5,a6,a7;
	int a,b,c,ab,bc,ac;
	cin>>t;
	while(t--){
		ans=0;
		maxc=-0x3f3f3f;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a1>>a2>>a3>>a4>>a5>>a6>>a7;
			if(a4>a7||a4==a7)  ab=a4-a7;
			else  continue;
			if(a5>a7||a5==a7)  bc=a5-a7;
			else  continue;
			if(a6>a7||a6==a7)  ac=a6-a7;
			else  continue;
			if(a1>(ab+ac+a7)||a1==(ab+ac+a7))  a=a1-(ab+ac+a7);
			else  continue;
			if(a2>(ab+bc+a7)||a2==(ab+bc+a7))  b=a2-(ab+bc+a7);
			else  continue;
			if(a3>(bc+ac+a7)||a3==(bc+ac+a7))  c=a3-(bc+ac+a7);
			else  continue;
			ans=a+b+c+ab+bc+ac+a7;
			maxc=max(maxc,ans);
		}
		cout<<maxc<<endl;
	}
	return 0;
}
