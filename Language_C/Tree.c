#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    char student_name[100];
    char phone_number[14];
} element;

typedef struct TreeNode
{
    element key;
    struct TreeNode* left, * right;
} TreeNode;

TreeNode* search(TreeNode* node, char key[])
{
    if (node == NULL)
        return NULL;

    if (strcmp(key, node->key.student_name) == 0)
        return node;
    else if (strcmp(key, node->key) < 0)
        return search(node->left, key);
    else
        return search(node->right, key);
    

}

TreeNode* new_node(char name[], char number[])
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(temp->key.phone_number, number);
    strcpy(temp->key.student_name, name);
    temp->left = temp->right = NULL;
    return temp;
}

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

TreeNode* max_value_node(TreeNode* node)
{
    TreeNode* current = node;

    while (current->right != NULL)
        current = current->right;

    return current;
}

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

void inorder(TreeNode* root)
{
    if (root)
    {
        inorder(root->left);
        printf("�̸�: '%s'\n��ȭ��ȣ: %s\n", root->key.student_name, root->key.phone_number);
        inorder(root->right);
    }
}

void preorder(TreeNode* root)
{
    if (root != NULL)
    {
        printf("[%d] ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("[%d] ", root->key);
    }
}

int main(void)
{
    TreeNode* root = NULL;
    /*
    root = insert_node(root, "������","010-2021-3420");
    root = insert_node(root, "������2", "010-2021-3424");
    root = insert_node(root, "������3", "010-2021-3426");
    root = insert_node(root, "������1", "010-20231-3420");
    delete_node(root, "������2");
    root = insert_node(root, "������1", "010-1234-3245");
    */

    char ch;
    char name[100];
    char number[30];
    
    do {
        printf("����(i), Ž��(s), ���(p), ����(d), ����(q): ");
        scanf(" %c", &ch);
        getchar();
        switch(ch) {            
            case 'i':
                printf("�̸� : ");
                scanf("%s", &name);
                printf("��ȭ��ȣ : ");
                scanf("%s", &number);
                root = insert_node(root, name, number);
                break;
            case 's':
                printf("�˻��̸� : ");
                scanf("%s", &name);
                TreeNode* temp;
                if (search(root, name) != NULL) {
                    temp = search(root, name);
                    printf("'%s'�� ��ȭ��ȣ : %s\n", temp->key.student_name, temp->key.phone_number);
                }
                else
                    printf("�˻���� ����\n");
                break;
            case 'p':
                printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
                inorder(root);
                printf("\n");
                break;
            case 'd':
                printf("�̸� : ");
                scanf("%s", &name);
                root = delete_node(root, name);
                break;
            case 'q':
                break;
            default:
                printf("�ùٸ� ��ɾ �Է����ּ���\n");
        }
    } while (ch != 'q');

    printf("���α׷��� �����մϴ�.\n");
    ch = '1';
    return 0;

}