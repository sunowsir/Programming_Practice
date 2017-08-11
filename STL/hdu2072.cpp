/*************************************************************************
    > File Name: hdu2072.cpp
    > Author: sunowsir
    > Mail: *** ***
    > Created Time: 2017年07月07日 星期五 17时24分45秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
#define cl(x) memset(x,0,sizeof(0));

set<string> st;

int main(){
	string w,s;
	while(getline(cin,w)){
		if(w[0]=='#')  break;
		st.clear();
		s="";
		for(int i=0;i<w.size();i++){
			//开头如果是空格或者到了文章的末尾说明到了分割点；
			if(w[i]==' '||i==w.size()){
				if(s=="")  continue;
				//把单词写入集合st中；
				st.insert(s);
				//写入完成后把s初始化；
				s="";
			}
			//如果不是空格或末尾将单词写入s中；
			else  s+=s[i];
		}
		cout<<st.size()<<endl;
	}
	return 0;
}
