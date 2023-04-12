#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char element;
//���ڽ��� ����ü �Լ�
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;
//���ڽ��� ����ü �����Լ�
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

//�켱���� ��ȯ�Լ�
int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}
// ���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "error : %s\n", message);
	exit(1);
}
// ���ڽ��û��� �Լ�
void initNumber(LinkedNumberList* s)
{
	s->top = NULL;
}
//���ڽ��û��� �Լ�
void init(LinkedStackType* s)
{
	s->top = NULL;
}
//���ڽ��� push�Լ�
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}
//���ڽ��� push�Լ�
void Numberpush(LinkedNumberList* s, double num) {
	NumberNode* temp = (NumberNode*)malloc(sizeof(NumberNode));
	temp->data = num;
	temp->link = s->top;
	s->top = temp;
}
// ���ڽ��� pop �Լ�
double Numberpop(LinkedNumberList* s) {
	if (is_Numberempty(s)) {
		error("������ �������\n");
	}
	else {
		NumberNode* temp = s->top;
		double data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}

}
//���ڽ��� pop�Լ�
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		error("������ �������\n");
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}
// ��ȣ�˻��Լ�
int check_matching(const char* in)
{
	StackNode s;
	char ch, open_ch;
	int i, n = strlen(in); // n= ���ڿ��� ����
	init(&s); // ������ �ʱ�ȭ
	for (i = 0; i < n; i++) {
		ch = in[i]; // ch = ���� ����
		switch (ch) {
		case '(': case '[': case '{':
			push(&s, ch);
			break;
		case ')': case ']': case '}':
			if (is_empty(&s)) return 0;
			else {
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '[' && ch != ']') ||
					(open_ch == '{' && ch != '}')) {
					return 0;
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) return 0; // ���ÿ� ���������� ����
	return 1;
}
// ��ũ�Լ�
element peek(LinkedStackType* s)
{
	if (is_empty(s))
		error("������ �������\n");
	else
		return s->top->data;
}
//��Ҹ��� ������ ������ִ� �Լ�
char* to_space(char exp[]) {
	int i = 0;
	int len = strlen(exp);
	char* space = (char*)malloc(sizeof(char) * (len*2));
	int j = 0;
	for (int i = 0; i < len; i++) {
		char ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': //�����ڴ� �յڷ� �����ֱ�
			space[j++] = ' ';
			space[j++] = ch;
			space[j++] = ' ';

			break;
		case'(': // (��ȣ�� ���ʿ� �����ֱ�
			space[j++] = ch;
			space[j++] = ' ';
			break;
		case')': // )�� ���ʿ� �����ֱ�
			space[j++] = ' ';
			space[j++] = ch;
			break;
		default: // �ǿ����ڴ� �������� ����
			space[j++] = ch; 
			break;
		}
	}
	space[j] = '\0';
	return space;
}
char* infix_to_postfix(char exp[])
{
	char top_op;
	char *space = to_space(exp);
	int len = strlen(space);
	int k = 0;
	char* postfix = (char*)malloc(sizeof(char) * len);
	LinkedStackType s;
	init(&s); // ���� �ʱ�ȭ
	for (int i = 0; i < len; i++) {
		char ch = space[i];
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
//���ڿ��� ������ �ִ� �Լ�
char* reverse_char(char exp[]) {
	int len = strlen(exp);
	char* reverse = (char*)malloc(sizeof(char) * (len+1));
	for (int i = 0; i < len; i++) {
		char ch = exp[i];
		if (ch == '(')
			ch = ')';
		else if (ch == ')')
			ch = '(';
		reverse[len -i-1] = ch;
	}
	reverse[len] = '\0';
	return reverse;
}
//�������� ���������� ��ȯ���ִ� �Լ�
char* infix_to_prefix(char exp[]) {
	char* prefix = reverse_char(exp);
	prefix = infix_to_postfix(prefix);
	prefix = reverse_char(prefix);
	return prefix;
}
//���� ������ ������� Ȯ�����ִ� �Լ�
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
//�� ���� Ȯ�� �Լ�
void Sign_check(element exp[]) {
	int len = strlen(exp);
	int check = 1;
	if (exp[0] >= 58 || exp[0] <= 47) {
		error("�� ���� �����Դϴ�.");
	}
	
	for (int i = 1; i < len; i++) {
		char ch = exp[i];
		if ((ch < 40 || ch>57) && ch != 44)
			error("���屸�� �����Դϴ�.");
		if (check == 0) {
			if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '.')
				error("�� ���� �����Դϴ�.");
		}
		if (ch=='+' || ch=='-'||ch=='*' || ch == '/' ) {
			check = 0;
			continue;
		}
		check = 1;
	}
	if (check == 0)
		error("�� ���� �����Դϴ�.");
}
//���� ����Լ�
void print_stack(LinkedStackType* s)
{
	for (StackNode* p = s->top; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
//������ ����Լ�
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
			case '/':
				if (op2 == 0)
					error("0���� ���� �� �����ϴ�.");
				Numberpush(&s, op1 / op2); 
				break;
			}
		}
	}
	double result = Numberpop(&s);
	return result;
}

// �� �Լ�
int main(void)
{
	char* s = "5*(3.5-2)+4.68/3";
	/*
	char* s = (char*)malloc(sizeof(char)*100);
	printf("���� ���� ���� �Է����ּ��� : ");
	gets(s);
	*/
	Sign_check(s);
	if (check_matching(s) != 1)
		error("��ȣ�˻����");
	char* prefix = infix_to_prefix(s);
	char* postfix = infix_to_postfix(s);
	printf("������: %s\n", s);
	printf("������: %s\n", prefix);
	printf("������: %s\n", postfix);
	double result = eval(postfix);
	printf("��� ���: %lf", result);
	return 0;
}