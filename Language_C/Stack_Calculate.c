#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char element;
//문자연결리스트 구조체 함수
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;
//숫자연결리스트 구조체 정의함수
typedef struct NumberNode {
	double data;
	struct NumberNode* link;
} NumberNode;
//숫자연결리스트 정의함수
typedef struct {
	NumberNode* top;
}LinkedNumberList;
//문자연결리스트 정의함수
typedef struct {
	StackNode* top;
} LinkedStackType;

//우선순위 반환함수
int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}
// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "error : %s\n", message);
	exit(1);
}
// 숫자스택생성 함수
void initNumber(LinkedNumberList* s)
{
	s->top = NULL;
}
//문자스택생성 함수
void init(LinkedStackType* s)
{
	s->top = NULL;
}
//문자스택 push함수
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}
//숫자스택 push함수
void Numberpush(LinkedNumberList* s, double num) {
	NumberNode* temp = (NumberNode*)malloc(sizeof(NumberNode));
	temp->data = num;
	temp->link = s->top;
	s->top = temp;
}
// 숫자스택 pop 함수
double Numberpop(LinkedNumberList* s) {
	if (is_Numberempty(s)) {
		error("스택이 비어있음\n");
	}
	else {
		NumberNode* temp = s->top;
		double data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}

}
//문자스택 pop함수
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		error("스택이 비어있음\n");
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}
// 괄호검사함수
int check_matching(const char* in)
{
	StackNode s;
	char ch, open_ch;
	int i, n = strlen(in); // n= 문자열의 길이
	init(&s); // 스택의 초기화
	for (i = 0; i < n; i++) {
		ch = in[i]; // ch = 다음 문자
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
	if (!is_empty(&s)) return 0; // 스택에 남아있으면 오류
	return 1;
}
// 피크함수
element peek(LinkedStackType* s)
{
	if (is_empty(s))
		error("스택이 비어있음\n");
	else
		return s->top->data;
}
//요소마다 공백을 만들어주는 함수
char* to_space(char exp[]) {
	int i = 0;
	int len = strlen(exp);
	char* space = (char*)malloc(sizeof(char) * (len*2));
	int j = 0;
	for (int i = 0; i < len; i++) {
		char ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': //연산자는 앞뒤로 공백주기
			space[j++] = ' ';
			space[j++] = ch;
			space[j++] = ' ';

			break;
		case'(': // (괄호는 뒤쪽에 공백주기
			space[j++] = ch;
			space[j++] = ' ';
			break;
		case')': // )는 앞쪽에 공백주기
			space[j++] = ' ';
			space[j++] = ch;
			break;
		default: // 피연산자는 공백주지 말기
			space[j++] = ch; 
			break;
		}
	}
	space[j] = '\0';
	return space;
}
//숫자 스택이 비었는지 확인해주는 함수
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
//중위식을 후위식으로 변환해주는 함수
char* infix_to_postfix(char exp[])
{
	char top_op;
	char* space = to_space(exp);
	int len = strlen(space);
	int k = 0;
	char* postfix = (char*)malloc(sizeof(char) * len);// 메모리할당
	LinkedStackType s;
	init(&s); // 스택 초기화
	for (int i = 0; i < len; i++) {
		char ch = space[i];
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
//문자열을 뒤집어 주는 함수
char* reverse_char(char exp[]) {
	int len = strlen(exp); // 길이를 받아서 len에 저장
	char* reverse = (char*)malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++) {
		char ch = exp[i];
		if (ch == '(') // 뒤집으므로'('는 ')'로 변환
			ch = ')';
		else if (ch == ')') // 뒤집으므로 ')'는 '('로 변환
			ch = '(';
		reverse[len - i - 1] = ch; //exp는 앞에서부터 뽑아온 문자를 reverse는 뒤에서부터 저장
	}
	reverse[len] = '\0'; // 마지막에 \0을 대입
	return reverse;
}
//중위식을 전위식으로 변환해주는 함수
char* infix_to_prefix(char exp[]) {
	char* prefix = reverse_char(exp); //1차적으로 뒤집어줌
	prefix = infix_to_postfix(prefix); // 뒤집어준걸 후위식으로 변환해줌
	prefix = reverse_char(prefix); // 그것을 다시 뒤집어줌
	return prefix;
}
//식 구조 확인 함수
void Sign_check(element exp[]) {
	int len = strlen(exp);
	int check = 1;
	if (exp[0] >= 58 || exp[0] <= 47) { //첫째항에 숫자가 아닌 문자가 있으면 오류함수 출력
		error("식 구조 오류입니다.");
	}
	for (int i = 1; i < len; i++) {
		char ch = exp[i];
		if ((ch < 40 || ch>57) && ch != 44)
			error("문장구조 오류입니다."); // 문장에 숫자나 연산자를 제외하고 다른 문자가 있으면 오류함수 출력
		if (check == 0) {
			if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '.') // 연산자나 . 이 연속으로 나오면 오류함수 출력
				error("식 구조 오류입니다.");
		}
		if (ch=='+' || ch=='-'||ch=='*' || ch == '/' || ch == '.') { //한번이라도 연산자나 . 이 나왔으면 check함수를 0으로 변경
			check = 0;
			continue;
		}
		check = 1; // 연산자나 .이아니면 check를 다시 1로 변경
	}
	if (check == 0)
		error("식 구조 오류입니다."); //마지막이 연산자나 .으로 끝났다면 오류함수 출력
}
//후위식 계산함수
double eval(char exp[])
{
	double op1, op2, value;
	int i = 0;
	int len = strlen(exp);
	char ch;
	LinkedNumberList s;
	initNumber(&s); //숫자 연결리스트 생성
	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch == ' ') { 
			ch = exp[++i];
		}
		int num;
		char* ch_num = (char*)malloc(sizeof(char) * len); // ch_num에 메모리 할당
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') { //피연산자가 아니라면 
			int j = 0;

			while (ch != ' ') { //공백을 기준으로 공백이 나올때까지 ch_num에 문자열 저장
				ch_num[j] = ch;
				ch = exp[++i];
				j++;
			}
			ch_num[j] = '\0';
			value = atof(ch_num); //문자열을 float로 바꾸고 저장
			Numberpush(&s, value); //저장한 것을 연결리스트에 push해줌

		}
		else { //연산자이면 피연산자를 스택에서 제거
			op2 = Numberpop(&s);
			op1 = Numberpop(&s);

			switch (ch) { //연산을 수행하고 스택에 저장
			case '+': Numberpush(&s, op1 + op2); break;
			case '-': Numberpush(&s, op1 - op2); break;
			case '*': Numberpush(&s, op1 * op2); break;
			case '/':
				if (op2 == 0)
					error("0으로 나눌 수 없습니다.");
				Numberpush(&s, op1 / op2); 
				break;
			}
		}
	}
	double result = Numberpop(&s);
	return result;
}

// 주 함수
int main(void)
{
	char* s = "5*(3.5-2)+4.68/3";
	/*
	char* s = (char*)malloc(sizeof(char)*100);
	printf("식을 띄어쓰기 없이 입력해주세요 : ");
	gets(s);
	*/
	Sign_check(s);
	if (check_matching(s) != 1)
		error("괄호검사실패");
	char* prefix = infix_to_prefix(s);
	char* postfix = infix_to_postfix(s);
	printf("중위식: %s\n", s);
	printf("전위식: %s\n", prefix);
	printf("후위식: %s\n", postfix);
	double result = eval(postfix);
	printf("계산 결과: %lf", result);
	return 0;
}