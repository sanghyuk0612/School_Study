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

	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s -> ", p->data.name);
	printf("NULL \n");
}

void Split_list(ListNode* head, element value) {

	ListNode* p = head;
	ListNode* head1;
	ListNode* head2;
	head1 = head;
	while (strcmp(p->data.name, value.name) != 0) {
		p = p->link;
		head = head->link;
	}
	head2 = head->link;
	p->link = NULL;
	printf("head1 : ");
	print_list(head1);
	printf("head2 : ");
	print_list(head2);

}
ListNode* delete (ListNode* head, element value) {
	ListNode* pre = (ListNode*)malloc(sizeof(ListNode));
	if (strcmp(head->data.name, value.name) == 0) {
		ListNode* removed;
		removed = head; // (1)
		head = removed->link; // (2)
		free(removed); // (3)
		printf("���� �ܾ� : %s\n", value.name);
		printf("�����Ϸ��� ��Ұ� �� �տ� �־ ���� �� �����ϴ�.\n");
		print_list(head);
		return head;

	}
	for (ListNode* p = head; p != NULL; p = p->link) {

		if (strcmp(p->data.name, value.name) == 0) {

			ListNode* removed = (ListNode*)malloc(sizeof(ListNode));
			removed = p;
			pre->link = removed->link;
			printf("���� �ܾ� : %s\n", value.name);
			if (p->link == NULL) {
				printf("�����Ϸ��� ��Ұ� �� �ڿ� �־ ���� �� �����ϴ�.\n");
				print_list(head);
				free(removed);
				return head;
			}
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
	head = delete(head, data);

	return 0;
}