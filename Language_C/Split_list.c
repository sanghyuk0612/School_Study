#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char name[100];
} element;
typedef struct ListNode { // ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;
// ���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); 
	p->data = value; 
	p->link = head;
	head = p;
	return head;
}
void print_list(ListNode* head)
{

	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s -> ", p->data.name);
	printf("NULL \n");
}
ListNode* Search_List(ListNode* head, element x) { //ã������ �Լ� �ٷ� �� ��带 ��ȯ���ִ� �Լ�
	ListNode* p= head;
	while (p != NULL)
	{
		if (strcmp(p->link->data.name, x.name) == 0) {
			return p;
		}
		p=p->link;
	}
	error("ã������ ��Ұ� �����ϴ�.");
	return NULL; // Ž�� ����
}

void Split_list(ListNode* head, element value) {

	ListNode* p = head;
	ListNode* head1;
	ListNode* head2;
	ListNode* s;
	head1 = p;
	s = Search_List(head, value);
	head2 = s->link->link;
	s->link->link = NULL;
	printf("head1 : ");
	print_list(head1);
	printf("head2 : ");
	print_list(head2);

}
void delete (ListNode* head, element value) {
	ListNode* pre = (ListNode*)malloc(sizeof(ListNode));
	ListNode* removed = (ListNode*)malloc(sizeof(ListNode));
	pre = Search_List(head, value);

	if (strcmp(head->data.name, value.name) == 0) {
		printf("���� �ܾ� : %s\n", value.name);
		removed = head;
		head = removed->link;
		free(removed); 
		printf("head1 : NULL \nhead2 : ");
		print_list(head);
	}

	else if (pre->link->link == NULL) {
		pre->link = NULL;
		printf("���� �ܾ� : %s\n", value.name);
		printf("head1 : ");
		print_list(head);
		printf("head2 : NULL");
		free(pre);
	}

	else {
		removed = pre->link;
		pre->link = removed->link;
		free(removed);
		printf("���� �ܾ� : %s\n", value.name);
		Split_list(head, pre->data);
	}
}

// �׽�Ʈ ���α׷�
int main(void) {
	ListNode* head = NULL;
	element data;
	strcpy(data.name, "PEACH");
	head = insert_first(head, data);

	strcpy(data.name, "MELON");
	head = insert_first(head, data);

	strcpy(data.name, "MANGO");
	head = insert_first(head, data);

	strcpy(data.name, "LEMON");
	head = insert_first(head, data);

	strcpy(data.name, "BANANA");
	head = insert_first(head, data);

	strcpy(data.name, "KIWI");
	head = insert_first(head, data);

	strcpy(data.name, "APPLE");
	head = insert_first(head, data);

	printf("head -> ");
	print_list(head);
	strcpy(data.name, "LEMON");
	delete(head, data);
	return 0;
}