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
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // (1)
	p->data = value; // (2) why? �迭 = �迭
	p->link = head; // (3) ��� �������� ���� ����
	head = p; // (4) ��� ������ ����
	return head;
}
void print_list(ListNode* head)
{
	printf("head -> ");
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s -> ", p->data.name);
	printf("NULL \n");
}

void Split_list(ListNode* head, element value) {
	printf("head1 : ");
	ListNode* p = head;
	while (strcmp(p->data.name, value.name) != 0) {
		printf("%s -> ", p->data.name);
		p = p->link;
	}
	printf("%s -> ", p->data.name);
	printf("NULL \n");
	printf("head2 : ");
	while (p != NULL) {
		printf("%s -> ", p->data.name);
		p = p->link;
	}
	printf("NULL \n");

}
ListNode* delete (ListNode* head, element value) {
	ListNode* pre = (ListNode*)malloc(sizeof(ListNode));
	for (ListNode* p = head; p != NULL; p = p->link) {
		
		if (strcmp(p->data.name, value.name)==0) {
			
			ListNode* removed = (ListNode*)malloc(sizeof(ListNode));
			removed = p;
			pre->link = p->link;
			printf("���� �ܾ� : %s\n", value.name);
			
			Split_list(head, pre->data);
			free(removed);
			return head;
		}
		pre = p;
	}
	error("������ �Լ��� ã�� ���߽��ϴ�.");
}

// �׽�Ʈ ���α׷�
int main(void) {
	ListNode* head= NULL;
	element data;
	strcpy(data.name, "PEACH");
	head = insert_first(head, data);
	print_list(head);
	strcpy(data.name, "MELON");
	head = insert_first(head, data);
	print_list(head);
	strcpy(data.name, "MANGO");
	head = insert_first(head, data);
	print_list(head);
	strcpy(data.name, "LEMON");
	head = insert_first(head, data);
	print_list(head);
	strcpy(data.name, "BANANA");
	head = insert_first(head, data);
	print_list(head);
	strcpy(data.name, "KIWI");
	head = insert_first(head, data);
	print_list(head);
	strcpy(data.name, "APPLE");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "LEMON");
	delete(head,data);
	
	

	return 0;
}