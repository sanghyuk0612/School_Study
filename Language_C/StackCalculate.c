#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;
typedef struct NumberNode {
	double data;
	struct NumberNode* link;
} NumberNode;
typedef struct {
	NumberNode* top;
}LinkedNumberList;
typedef struct {
	StackNode* top;
} LinkedStackType;

int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}
// �ʱ�ȭ �Լ�
void initNumber(LinkedNumberList* s)
{
	s->top = NULL;
}
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
void Numberpush(LinkedNumberList* s, double num) {
	NumberNode* temp = (NumberNode*)malloc(sizeof(NumberNode));
	temp->data = num;
	temp->link = s->top;
	s->top = temp;
}
// ���� �Լ�
double Numberpop(LinkedNumberList* s) {
	if (is_Numberempty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		NumberNode* temp = s->top;
		double data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}

}
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
	char* space = (char*)malloc(sizeof(char) * 100);
	char* postfix = (char*)malloc(sizeof(char) * 100);

	int j = 0;
	for (i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/':
			space[j++] = ' ';
			space[j++] = ch;
			space[j++] = ' ';

			break;
		case'(':
			space[j++] = ch;
			space[j++] = ' ';
			break;
		case')':
			space[j++] = ' ';
			space[j++] = ch;
			break;
		default: // �ǿ�����
			space[j++] = ch;
			break;
		}
	}
	space[j] = '\0';
	//printf("%s\n", space);
	int k = 0;
	LinkedStackType s;
	init(&s); // ���� �ʱ�ȭ
	for (i = 0; i < j; i++) {
		ch = space[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': // ������
			// ���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������ ���
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				postfix[k++] = pop(&s);
			push(&s, ch);
			break;
		case '(': // ���� ��ȣ
			push(&s, ch);
			break;
		case ')': // ������ ��ȣ
			top_op = pop(&s);
			// ���� ��ȣ�� ���������� ���
			while (top_op != '(') {
				postfix[k++] = top_op;
				top_op = pop(&s);
			}
			break;
		default: // �ǿ�����
			if (ch == ' ' && postfix[k - 1] == ' ')
				break;
			postfix[k++] = ch;
			break;
		}
	}
	while (!is_empty(&s)) { // ���ÿ� ����� �����ڵ� ���
		postfix[k++] = ' ';
		postfix[k++] = pop(&s);

	}
	postfix[k] = '\0';
	return postfix;

}
int is_Numberempty(LinkedNumberList* s) {
	return (s->top == NULL);
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
double eval(char exp[])
{
	double op1, op2, value;
	int i = 0;
	int len = strlen(exp);
	char ch;
	LinkedNumberList s;
	initNumber(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch == ' ') {
			ch = exp[++i];
		}
		int num;
		char ch_num[100] = " ";
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			int j = 0;
			
			while (ch != ' ') {
				ch_num[j] = ch;
				ch = exp[++i];
				j++;
			}
			ch_num[j] = '\0';
			value = atof(ch_num);
			Numberpush(&s, value);

		}
		else { //�������̸� �ǿ����ڸ� ���ÿ��� ����
			op2 = Numberpop(&s);
			op1 = Numberpop(&s);
			
			switch (ch) { //������ �����ϰ� ���ÿ� ����
			case '+': Numberpush(&s, op1 + op2); break;
			case '-': Numberpush(&s, op1 - op2); break;
			case '*': Numberpush(&s, op1 * op2); break;
			case '/': Numberpush(&s, op1 / op2); break;
			}
		}
	}
	double result =Numberpop(&s);
	return result;
}

// �� �Լ�
int main(void)
{
	char* s = "5*(3.5-2)+4.68/3";
	char* postfix;
	printf("����ǥ�ü��� %s \n", s);
	printf("����ǥ�ü��� ");
	postfix = infix_to_postfix(s);
	printf("%s\n", postfix);
	double result = eval(postfix);
	printf("%lf", result);

	return 0;
}