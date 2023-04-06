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
// �ʱ�ȭ �Լ�
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
// ���� �Լ�
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
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
// ��ũ�Լ�
element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
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
	init(&s); // ���� �ʱ�ȭ
	for (i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': // ������
			// ���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������ ���
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				postfix[j++] = pop(&s);
			push(&s, ch);
			break;
		case '(': // ���� ��ȣ
			push(&s, ch);
			break;
		case ')': // ������ ��ȣ
			top_op = pop(&s);
			// ���� ��ȣ�� ���������� ���
			while (top_op != '(') {
				postfix[j++] = top_op;
				top_op = pop(&s);
			}
			break;
		default: // �ǿ�����
			postfix[j++] = ch;
			break;
		}
	}
	while (!is_empty(&s)) // ���ÿ� ����� �����ڵ� ���
		postfix[j++] = pop(&s);
	postfix[j] = '\0';
	return postfix;
}

// ���� ���� ���� �Լ�
int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(LinkedStackType* s)
{
	return 0;
}
// ���� �Լ�

void print_stack(LinkedStackType* s)
{
	for (StackNode* p = s->top; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}


// �� �Լ�
int main(void)
{
	
	char* s = "(2+3)*4+9";
	printf("����ǥ�ü��� %s \n", s);
	printf("����ǥ�ü��� ");
	char *postfix = infix_to_postfix(s);
	printf("%s\n",postfix);
	return 0;
}