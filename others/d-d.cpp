/*************************************************************************
    > File Name: d-d.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年07月28日 星期五 15时48分33秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
#define cls(x) memset(x,0,sizeof(x))

int main(){
	char c[maxn],str[maxn];
	while(1){
		gets(str);
		if(str[3]=='O')  break;
		else if(str[0]=='S')  continue;
		else if(str[0]=='E')  continue;
		else{
			for(int i=0;i<strlen(str);i++){
				if(str[i]=='A')  str[i]='V';
				else if(str[i]=='B')  str[i]='W';
				else if(str[i]=='C')  str[i]='X';
				else if(str[i]=='D')  str[i]='Y';
				else if(str[i]=='E')  str[i]='Z';
				else if(str[i]==' ')  str[i]=' ';
				else if(str[i]==',')  str[i]=',';
				else  str[i]-=5;

				cout<<str[i];
			}
			cout<<endl;
			cls(str);
		}
	}
	return 0;
}
