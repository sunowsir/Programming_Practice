/*************************************************************************
	> File Name: LinkedList.c
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice
	> Created Time: 2017年09月23日 星期六 09时23分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
    if(head == NULL) {
        if(index != 0) {
            printf("failed\n");
            return head;
        }
        head = node;
        printf("success\n");
        return head;
    }
    if(index == 0) {
        node->next = head;
        head = node;
        printf("success\n");
        return head;
    }
    Node *current_node = head;
    int count = 0;
    while(current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if(count == index - 1) {
        node->next = current_node->next;
        current_node->next = node;
        printf("success\n");
        return head;
    }
    printf("failed\n");
    return head;
}

LinkedList reverse(LinkedList head) {
    if(head == NULL) {
        printf("failed\n");
        return head;
    }
    Node *current_node, *next_node;
    current_node = head->next;
    head->next = NULL;
    while(current_node != NULL) {
        next_node = current_node->next;
        current_node->next = head;
        head = current_node;
        current_node = next_node;
    }
    printf("success\n");
    return head;
}

LinkedList delete_list(LinkedList head, int index) {
    if(head == NULL) {
        printf("failed\n");
        return head;
    }
    Node *current_node = head;
    int count = 0;
    if(index == 0) {
        head = head->next;
        free(current_node);
        printf("success\n");
        return head;
    }
    while(current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if(count == index - 1 && current_node->next != NULL) {
        Node *delete_node = current_node->next;
        current_node->next = delete_node->next;
        free(delete_node);
        printf("success\n");
        return head;
    }
    printf("failed\n");
    return head;
}

void output(LinkedList head) {
    if(head == NULL) {
        printf("NULL\n");
        return;
    }
    Node *current_node = head;
    int tmp = 0;
    while(current_node != NULL) {
        if(tmp == 1) {
            printf(" ");
        }
        tmp = 1;
        printf("%d", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
    return;
}

void clear(LinkedList head) {
    Node *current_node = head;
    while(current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
    return;
}

int main() {
    LinkedList list = NULL;
    int n, value, loc, t, N;
    N = 1;
    //输入操作数
    printf("输入操作数：\n");
    scanf("%d", &n);
    while(n--) {
        printf("第%d次操作：\n", N++);
        printf("输入操作类型：\n");
        scanf("%d", &t);
        Node *node = (Node *)malloc(sizeof(Node));
        if(t == 1) {
            printf("插入：\n");
            printf("输入loc 和 value：\n");
            scanf("%d%d", &loc, &value);
            node->next = NULL;
            node->data = value;
            list = insert(list, node, loc);
        }
        if(t == 2) {
            printf("删除：\n");
            printf("输入loc：\n");
            scanf("%d", &loc);
            list = delete_list(list, loc);
        }
        if(t == 3) {
            printf("反转：\n");
            list = reverse(list);
        }
        if(t == 4) {
            printf("遍历：\n");
            output(list);
        }
    }
    clear(list);
    return 0;
}
