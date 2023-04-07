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
// 초기화 함수
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
// 삭제 함수
double Numberpop(LinkedNumberList* s) {
	if (is_Numberempty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
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
		default: // 피연산자
			space[j++] = ch;
			break;
		}
	}
	space[j] = '\0';
	//printf("%s\n", space);
	int k = 0;
	LinkedStackType s;
	init(&s); // 스택 초기화
	for (i = 0; i < j; i++) {
		ch = space[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': // 연산자
			// 스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				postfix[k++] = pop(&s);
			push(&s, ch);
			break;
		case '(': // 왼쪽 괄호
			push(&s, ch);
			break;
		case ')': // 오른쪽 괄호
			top_op = pop(&s);
			// 왼쪽 괄호를 만날때까지 출력
			while (top_op != '(') {
				postfix[k++] = top_op;
				top_op = pop(&s);
			}
			break;
		default: // 피연산자
			if (ch == ' ' && postfix[k - 1] == ' ')
				break;
			postfix[k++] = ch;
			break;
		}
	}
	while (!is_empty(&s)) { // 스택에 저장된 연산자들 출력
		postfix[k++] = ' ';
		postfix[k++] = pop(&s);

	}
	postfix[k] = '\0';
	return postfix;

}
int is_Numberempty(LinkedNumberList* s) {
	return (s->top == NULL);
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
		else { //연산자이면 피연산자를 스택에서 제거
			op2 = Numberpop(&s);
			op1 = Numberpop(&s);
			
			switch (ch) { //연산을 수행하고 스택에 저장
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

// 주 함수
int main(void)
{
	char* s = "5*(3.5-2)+4.68/3";
	char* postfix;
	printf("중위표시수식 %s \n", s);
	printf("후위표시수식 ");
	postfix = infix_to_postfix(s);
	printf("%s\n", postfix);
	double result = eval(postfix);
	printf("%lf", result);

	return 0;
}