#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;
typedef struct {
	StackNode* top;
} LinkedStackType;
int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '- ': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}
// 초기화 함수
void init(LinkedStackType* s)
{
	s->top = NULL;
}
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}
// 삭제 함수
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}
// 피크함수
element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		return s->top->data;
	}
}
char* infix_to_postfix(char exp[])
{
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	char postfix[100];
	int j = 0;
	LinkedStackType s;
	init(&s); // 스택 초기화
	for (i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': // 연산자
			// 스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				postfix[j++] = pop(&s);
			push(&s, ch);
			break;
		case '(': // 왼쪽 괄호
			push(&s, ch);
			break;
		case ')': // 오른쪽 괄호
			top_op = pop(&s);
			// 왼쪽 괄호를 만날때까지 출력
			while (top_op != '(') {
				postfix[j++] = top_op;
				top_op = pop(&s);
			}
			break;
		default: // 피연산자
			postfix[j++] = ch;
			break;
		}
	}
	while (!is_empty(&s)) // 스택에 저장된 연산자들 출력
		postfix[j++] = pop(&s);
	postfix[j] = '\0';
	return postfix;
}

// 공백 상태 검출 함수
int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedStackType* s)
{
	return 0;
}
// 삽입 함수

void print_stack(LinkedStackType* s)
{
	for (StackNode* p = s->top; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}


// 주 함수
int main(void)
{
	
	char* s = "(2+3)*4+9";
	printf("중위표시수식 %s \n", s);
	printf("후위표시수식 ");
	char *postfix = infix_to_postfix(s);
	printf("%s\n",postfix);
	return 0;
}