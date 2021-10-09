/*
	* File     : 25.K个一组翻转链表.cpp
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : 2021年08月24日 星期二 01时12分45秒
*/

#include "bits/stdc++.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



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
private: 
    void reverse_list(ListNode*, ListNode*);
public:
    ListNode* reverseKGroup(ListNode*, int);
};

void Solution::reverse_list(ListNode* start_left, ListNode* end) {
    ListNode *l = start_left;
    ListNode *s = start_left->next;
    ListNode *e = end;
    ListNode *r = end->next;

    if (s == e) 
        return ;

    ListNode *last = l;
    ListNode *current = s;
    while (current != r) {
        ListNode *temp = current->next;
        current->next = last;
        last = current;
        current = temp;
    }

    l->next = e;
    s->next = r;

    return ;
}

ListNode* Solution::reverseKGroup(ListNode* head, int k) {
    ListNode *ret;
    bool end = false;

    ListNode *current = new ListNode;
    current->next = head;

    while (current != nullptr) {

        ListNode *start_left = current;
        current = current->next;
        if (!current)
            break;

        for (int i = 0; i < k && !end; i++) {
            current = current->next;
            if (current == nullptr)
                end = true;
        }

        if (end) 
            break;

        this->reverse_list(start_left, current);
    }

    ret = current->next;

    current->next = nullptr;
    delete current;

    return ret;
}


