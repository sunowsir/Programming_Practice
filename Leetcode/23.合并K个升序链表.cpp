/*
	* File     : 23.合并K个升序链表.cpp
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : Thu 10 Jun 2021 10:51:09 PM CST
*/

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() <= 0) {
            return nullptr;
        }
        
        if (lists.size() == 1) {
            return lists[0];
        }

        ListNode *result = lists[0];

        for (int i = 1; i < lists.size(); i++) {
            ListNode *current = lists[i];

            if (current == nullptr) {
                continue;
            }
            
            if (result == nullptr) {
                result = new ListNode(current->val);
                current = current->next;
            }

            while (current != nullptr) {
                if (current->val < result->val) {
                    ListNode *temp = result;
                    result = current;
                    current = current->next;
                    result->next = temp;
                    continue;
                } 

                bool completed = false;
                ListNode *res_cur = result;
                while (res_cur->next != nullptr) {
                    if (current->val >= res_cur->val && current->val <= res_cur->next->val) {
                        ListNode *temp = res_cur->next;
                        res_cur->next = current;
                        current = current->next;
                        res_cur->next->next = temp;

                        completed = true;
                        break;
                    }
                    res_cur = res_cur->next;
                }
                
                if (completed == false && current->val > res_cur->val) {
                    res_cur->next = current;
                    current = current->next;
                    res_cur->next->next = nullptr;
                }
            }
        }

        return result;
    }
};
