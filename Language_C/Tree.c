#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct element { //구조체 선언
    char student_name[100];
    char phone_number[14];
} element;

//트리노드 선언
typedef struct TreeNode
{
    element key;
    struct TreeNode* left, * right;
} TreeNode;

//검색 함수
TreeNode* search(TreeNode* node, char key[])
{
    if (node == NULL)
        return NULL;

    if (strcmp(key, node->key.student_name) == 0)
        return node;
    else if (strcmp(key, node->key.student_name) < 0)
        return search(node->left, key);
    else
        return search(node->right, key);


}

//생성함수
TreeNode* new_node(char name[], char number[])
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(temp->key.phone_number, number);
    strcpy(temp->key.student_name, name);
    temp->left = temp->right = NULL;
    return temp;
}


//삽입함수
TreeNode* insert_node(TreeNode* node, char name[], char number[])
{
    if (node == NULL)
        return new_node(name, number);

    if (strcmp(name, node->key.student_name) < 0)
        node->left = insert_node(node->left, name, number);
    else if (strcmp(name, node->key.student_name) > 0)
        node->right = insert_node(node->right, name, number);
    else
        strcpy(node->key.phone_number, number);
    return node;
}

//최대함수
TreeNode* max_value_node(TreeNode* node)
{
    TreeNode* current = node;

    while (current->right != NULL)
        current = current->right;

    return current;
}

//삭제함수
TreeNode* delete_node(TreeNode* root, char name[])
{
    if (root == NULL)
        return root;

    if (strcmp(name, root->key.student_name) < 0)
        root->left = delete_node(root->left, name);
    else if (strcmp(name, root->key.student_name) > 0)
        root->right = delete_node(root->right, name);
    else
    {
        if (root->left == NULL)
        {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = max_value_node(root->left);
        strcpy(root->key.phone_number, temp->key.phone_number);
        strcpy(root->key.student_name, temp->key.student_name);
        root->left = delete_node(root->left, temp->key.student_name);
    }

    return root;
}
int get_node_count(TreeNode* node)
{
    int count = 0;
    if (node != NULL)
        count = 1 + get_node_count(node->left) + get_node_count(node->right);
    return count;
}

//중위순환
void inorder(TreeNode* root)
{
    if (root)
    {
        inorder(root->left);

        printf("이름: '%s'\n전화번호: %s\n", root->key.student_name, root->key.phone_number);
        inorder(root->right);
    }
}
//메인함수
int main(void)
{
    TreeNode* root = NULL;
    char ch;
    char name[100];
    char number[30];
    do {
        printf("삽입(i), 탐색(s), 출력(p), 삭제(d), 종료(q): ");
        scanf(" %c", &ch);
        getchar();
        switch (ch) {
        case 'i':
            printf("이름 : ");
            scanf("%s", name);
            printf("전화번호 : ");
            scanf("%s", number);
            root = insert_node(root, name, number);
            break;
        case 's':
            printf("검색이름 : ");
            scanf("%s", name);
            TreeNode* temp;
            if (search(root, name) != NULL) {
                temp = search(root, name);
                printf("'%s'의 전화번호 : %s\n", temp->key.student_name, temp->key.phone_number);
            }
            else
                printf("검색결과 없음\n");
            break;
        case 'p':
            printf("이진 탐색 트리 중위 순회 결과 \n");
            int count = get_node_count(root);
            printf("전체 전화번호부의 개수는 %d개입니다\n", count);
            inorder(root);
            printf("\n");
            break;
        case 'd':
            printf("이름 : ");
            scanf("%s", name);
            root = delete_node(root, name);
            break;
        case 'q':
            break;
        default:
            printf("올바른 명령어를 입력해주세요\n");
        }
    } while (ch != 'q');
    printf("프로그램을 종료합니다.\n");
    return 0;

}