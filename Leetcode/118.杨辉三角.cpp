/*
	* File     : 118.杨辉三角.cpp
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : Sat 26 Jun 2021 10:01:34 PM CST
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        if (numRows == 0) 
            return ans;
        
        vector<int> line;
        line.push_back(1);
        ans.push_back(line);

        for (int i = 1; i < numRows; i++) {
            vector<int> line;
            for (int j = 0; j <= i; j++) {
                int up, up_right;
                up = ((j >= ans[i - 1].size()) ? (0) : (ans[i - 1][j]));
                up_right = (((j + 1 > i) || (j >= ans[i - 1].size())) ? (0) : (ans[i - 1][j + 1]));

                line.push_back(up + up_right);
            }
            ans.push_back(line);
        }

        return ans;
    }
};

