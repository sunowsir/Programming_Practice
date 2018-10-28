/* 
 * File Name:    jisuanke_tree4.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * Created Time: 2018年10月27日 星期六 19时38分13秒
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node;

Node *init (char data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

Node *build (char *str,int  pos) {
    int len  = (int)strlen(str);
    if (str == 0) {
        return NULL;
    }
    Node *root = init(str[pos]);
}

void output(Node *root, char first) {
    if (root == NULL) {
        return ;
    }
    if (root->data != first) {
        printf(" ");
    }
    printf("%c", root->data);
    output(root->lchild, first);
    output(root->rchild, first);
    return ;
}

void clear(Node *root) {
    if(root == NULL) {
        return ;
    }
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int main () {

    char str[10010] = {'\0'};
    scanf("%[^\n]s", str);
    if ((int)strlen(str) == 0) {
        cout << "" << endl;
        return 0;
    }
    Node *root = build(str, 0);
    output(root, str[0]);
    printf("\n");
    clear(root);

    return 0;
}
