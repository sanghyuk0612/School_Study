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
ListNode* Search_List(ListNode* head, element x) { //찾으려는 함수 바로 전 노드를 반환해주는 함수
	ListNode* p= head;
	while (p != NULL)
	{
		if (strcmp(p->link->data.name, x.name) == 0) {
			return p;
		}
		p=p->link;
	}
	error("찾으려는 요소가 없습니다.");
	return NULL; // 탐색 실패
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
		printf("삭제 단어 : %s\n", value.name);
		removed = head;
		head = removed->link;
		free(removed); 
		printf("head1 : NULL \nhead2 : ");
		print_list(head);
	}

	else if (pre->link->link == NULL) {
		pre->link = NULL;
		printf("삭제 단어 : %s\n", value.name);
		printf("head1 : ");
		print_list(head);
		printf("head2 : NULL");
		free(pre);
	}

	else {
		removed = pre->link;
		pre->link = removed->link;
		free(removed);
		printf("삭제 단어 : %s\n", value.name);
		Split_list(head, pre->data);
	}
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
	delete(head, data);
	return 0;
}