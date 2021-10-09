/*
	* File     : 108.将有序数组转换为二叉搜索树.cpp
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : Sat 26 Jun 2021 06:02:17 PM CST
*/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* bst;

    void insert_to_bst(int);
    void get_num_dichotomy(vector<int>&, int, int);
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        this->get_num_dichotomy(nums, 0, nums.size() - 1);
        return this->bst;
    }
};

void Solution::insert_to_bst(int num) {
    TreeNode *node = new TreeNode(num);

    if (this->bst == nullptr) {
        this->bst = node;
        return ;
    }

    TreeNode **current = &(this->bst);
    while (*current != nullptr) {
        TreeNode *now_loop_node = *current;
        current = ((node->val < now_loop_node->val) ? 
                    (&(now_loop_node->left)) : (&(now_loop_node->right)));
    }
    *current = node;
}

void Solution::get_num_dichotomy(vector<int>& nums, int begin, int end) {
    int size = (end - begin + 1);

    if (size <= 0)
        return ;

    int mid_pos = size / 2;
    this->insert_to_bst(nums[mid_pos]);

    this->get_num_dichotomy(nums, begin, end - 1);
    this->get_num_dichotomy(nums, begin + 1, end);
}



