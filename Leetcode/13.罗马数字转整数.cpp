/*
	* File     : 13.罗马数字转整数.cpp
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : Sat 15 May 2021 09:50:15 AM CST
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    std::map<char, int> maplist;

    bool compare_small_roman(char a, char b) {
        return this->maplist[a] < this->maplist[b];
    }
public:
    Solution() {
        maplist['I'] = 1;
        maplist['V'] = 5;
        maplist['X'] = 10;
        maplist['L'] = 50;
        maplist['C'] = 100;
        maplist['D'] = 500;
        maplist['M'] = 1000;
    }
    int romanToInt(string s) {
        if (s.size() == 0) {
            return 0;
        }

        int ans = 0;
        
        for (int i = 0; i < s.size() - 1; i++) {
            if (this->compare_small_roman(s[i], s[i + 1])) {
                ans -= this->maplist[s[i]];
            } else {
                ans += this->maplist[s[i]];
            }
        }
        ans += this->maplist[s[s.size() - 1]];

        return ans;
    }
};

