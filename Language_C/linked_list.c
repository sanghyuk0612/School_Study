#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char name[100];
} element;
typedef struct ListNode { // 노드 타입
	element data;
	struct ListNode* link;
} ListNode;
// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // (1)
	p->data = value; // (2) why? 배열 = 배열
	p->link = head; // (3) 헤드 포인터의 값을 복사
	head = p; // (4) 헤드 포인터 변경
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
		printf("삭제 단어 : %s\n", value.name);
		printf("삭제하려는 요소가 맨 앞에 있어서 나눌 수 없습니다.\n");
		print_list(head);
		return head;

	}
	for (ListNode* p = head; p != NULL; p = p->link) {

		if (strcmp(p->data.name, value.name) == 0) {

			ListNode* removed = (ListNode*)malloc(sizeof(ListNode));
			removed = p;
			pre->link = removed->link;
			printf("삭제 단어 : %s\n", value.name);
			if (p->link == NULL) {
				printf("삭제하려는 요소가 맨 뒤에 있어서 나눌 수 없습니다.\n");
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
	error("삭제할 함수를 찾지 못했습니다.");
}

// 테스트 프로그램
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