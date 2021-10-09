/*
	* File     : 53.最大子序和.cpp
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : Sat 15 May 2021 10:16:33 AM CST
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int calc_temp = 0;
            for (int j = i; j < nums.size(); j++) {
                calc_temp += nums[j];
                ans = max(ans, calc_temp);
            }
        }

        return ans;
    }
};

