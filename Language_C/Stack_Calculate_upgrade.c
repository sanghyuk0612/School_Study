#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct { // ���ڿ� ��� ���� �Լ�
	char name[100];
} s_element;

typedef struct ListNode { // ��� Ÿ��
	s_element data;
	struct ListNode* link;
} ListNode;

typedef struct { //���ڿ� ����Ʈ ����
	ListNode* top;
}LinkedsList;

typedef char element;
//���ڿ��Ḯ��Ʈ ����ü �Լ�
typedef struct StackNode {
	element* data;
	struct StackNode* link;
} StackNode;

//���ڿ��Ḯ��Ʈ ����ü �����Լ�
typedef struct NumberNode {
	double data;
	struct NumberNode* link;
} NumberNode;

//���ڿ��Ḯ��Ʈ �����Լ�
typedef struct {
	NumberNode* top;
}LinkedNumberList;
//���ڿ��Ḯ��Ʈ �����Լ�
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
// ���ڿ����û��� �Լ�
void initS(LinkedsList* s)
{
	s->top = NULL;
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

//���ڿ� push �Լ�
void s_push(LinkedsList* head, s_element value)
{

	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	strcpy(temp->data.name, value.name);
	//temp->data = value;
	temp->link = head->top;
	head->top = temp;
}
//���ڿ� pop �Լ�
s_element s_pop(LinkedsList* head) {
	if (is_s_empty(head)) {
		error("�ùٸ� ���� �Է����ּ���.\n");
	}
	ListNode* temp = head->top;
	s_element data;
	//s_element data = temp->data;
	strcpy(data.name, temp->data.name);
	head->top = head->top->link;
	free(temp);
	return data;

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
void check_matching(const char* in)
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
					error("��ȣ�� �߸��Ǿ����ϴ�.");
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) error("��ȣ�� �߸��Ǿ����ϴ�.");; // ���ÿ� ���������� ����
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
	char* space = (char*)malloc(sizeof(char) * (len * 2));
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
//���� ������ ������� Ȯ�����ִ� �Լ�
int is_Numberempty(LinkedNumberList* s) {
	return (s->top == NULL);
}
// ���ڿ� ���� ���� ���� ���� �Լ�
int is_s_empty(LinkedsList* s)
{
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

//���ڿ��� ������ �ִ� �Լ�
char* reverse_char(char exp[]) {
	int len = strlen(exp); // ���̸� �޾Ƽ� len�� ����
	char* reverse = (char*)malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++) {
		char ch = exp[i];
		if (ch == '(') // �������Ƿ�'('�� ')'�� ��ȯ
			ch = ')';
		else if (ch == ')') // �������Ƿ� ')'�� '('�� ��ȯ
			ch = '(';
		reverse[len - i - 1] = ch; //exp�� �տ������� �̾ƿ� ���ڸ� reverse�� �ڿ������� ����
	}
	reverse[len] = '\0'; // �������� \0�� ����
	return reverse;
}
//�������� ���������� ��ȯ���ִ� �Լ�
char* infix_to_postfix(char exp[])
{
	char top_op;
	char* space = to_space(exp);
	int len = strlen(space);
	int k = 0;
	char* postfix = (char*)malloc(sizeof(char) * len);// �޸��Ҵ�
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
//�������� ���������� ��ȯ���ִ� �Լ�
char* postfix_to_infix(char exp[]) {
	LinkedsList stack;
	
	int len = strlen(exp);
	s_element op1;
	s_element op2;
	s_element data;
	initS(&stack);
	for (int i = 0; i < len; i++) {
		char ch = exp[i];
		if (ch == ' ') {
			ch = exp[++i];
		}
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			char s[100] = { 0x00, };
			
			strcpy(op2.name, s_pop(&stack).name); // ���ÿ��� pop�Ͽ� op2�� ����
			strcpy(op1.name, s_pop(&stack).name); // ���ÿ��� pop�Ͽ� op1�� ����
			s_element p;
			sprintf(s, "(%s %c %s)", op1, ch, op2); //�� �ΰ��� ��� �����ڿ� �Բ� ��ȣ�� ����
			strcpy(p.name, s); //�װ� p.name�� ����
			s_push(&stack, p); //�װ��� �ٽ� push ����
		}
		else { // �ǿ�����
			char *ch_num= (char*)malloc(sizeof(char)*len);
			int j = 0;
			ch_num[j++] = exp[i];
			while (exp[i + 1] != ' ') { // ������ ���ö����� ch_num�� �־���
				ch = exp[++i];
				ch_num[j] = ch;
				j++;
			}
			ch_num[j] = '\0'; //�������� '\0'����
			strcpy(data.name, ch_num); //�װ��� data.name�� ����
			s_push(&stack, data); // �����Ѱ��� �ٽ� push����
		}
	}
	char* infix = (char*)malloc(sizeof(char)*100);
	
	strcpy(infix, s_pop(&stack).name); //infix��� ������ �ٽ� �־��ְ� ��ȯ
	return infix;
}

//�������� ���������� ��ȯ���ִ� �Լ�
char* infix_to_prefix(char exp[]) {
	char* prefix = reverse_char(exp); //1�������� ��������
	prefix = infix_to_postfix(prefix); // �������ذ� ���������� ��ȯ����
	prefix = reverse_char(prefix); // �װ��� �ٽ� ��������
	return prefix;
}
//�����Ŀ��� ���������� ��ȯ���ִ� �Լ�
char* prefix_to_postfix(char exp[]) {

	char* postfix = reverse_char(exp); //1�������� ��������
	postfix = postfix_to_infix(postfix); // �������ذ� ���������� ��ȯ����
	postfix = reverse_char(postfix); // �װ��� �ٽ� ��������
	postfix = infix_to_postfix(postfix);
	int len = strlen(exp);
	return postfix;
}
//�� ���� Ȯ�� �Լ�
void Sign_check(element exp[]) {
	int len = strlen(exp);
	int check = 1;
	if (exp[0] >= 58 || exp[0] <= 47){//ù°�׿� ���ڳ� �����̳� ��ȣ�� �ƴ� ���ڰ� ������ �����Լ� ���
		if (exp[0] != 41 && exp[0] != 40 && exp[0] !=' ')
			error("�� ���� �����Դϴ�.");
	}
	for (int i = 1; i < len; i++) {
		char ch = exp[i];
		if (ch < 40 || ch>57 || ch==44) {
			if (ch != ' ')
				error("���屸�� �����Դϴ�."); // ���忡 ���ڳ� �����ڸ� �����ϰ� �ٸ� ���ڰ� ������ �����Լ� ���
		}
		if (check == 0) {
			if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '.') // �����ڳ� . �� �������� ������ �����Լ� ���
				error("�� ���� �����Դϴ�.");
		}
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '.') { //�ѹ��̶� �����ڳ� . �� �������� check�Լ��� 0���� ����
			check = 0;
			continue;
		}
		check = 1; // �����ڳ� .�̾ƴϸ� check�� �ٽ� 1�� ����
	}
	if (check == 0)
		error("�� ���� �����Դϴ�."); //�������� �����ڳ� .���� �����ٸ� �����Լ� ���
}

//������ ����Լ�
double eval(char exp[])
{
	double op1, op2, value;
	int i = 0;
	int len = strlen(exp);
	char ch;
	LinkedNumberList s;
	initNumber(&s); //���� ���Ḯ��Ʈ ����
	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch == ' ') {
			ch = exp[++i];
		}
		int num;
		char* ch_num = (char*)malloc(sizeof(char) * len); // ch_num�� �޸� �Ҵ�
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') { //�ǿ����ڰ� �ƴ϶�� 
			int j = 0;

			while (ch != ' ') { //������ �������� ������ ���ö����� ch_num�� ���ڿ� ����
				ch_num[j] = ch;
				ch = exp[++i];
				j++;
			}
			ch_num[j] = '\0';
			value = atof(ch_num); //���ڿ��� float�� �ٲٰ� ����
			Numberpush(&s, value); //������ ���� ���Ḯ��Ʈ�� push����

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
	int choice; // ������ ���� ���� ����
	printf("�Է� ������ �����ϼ���.\n\n"); 
	printf("1. �� �� �� \n2. �� �� �� \n3. �� �� �� \n4. ��    ��\n\n��    �� : ");
	scanf("%d%*c", &choice); // scanf�� gets�� ���� ���� ���Ͽ� scnaf���� ������ ������ ������
	if (choice == 1) { // ������ 1�ϰ�� 
		char* prefix = (char*)malloc(sizeof(char) * 100);
		printf("������ �Է��ϼ��� : ");
		gets(prefix);
		char* postfix = prefix_to_postfix(prefix);
		char* infix = postfix_to_infix(postfix);
		Sign_check(infix); //��ȯ�� infix�� �����˻縦��
		check_matching(infix);//��ȯ�� infix�� �������� ��ȣ�˻縦 ��
		printf("������: %s\n", infix);
		printf("������: %s\n", prefix);
		printf("������:%s\n", postfix);
		double result = eval(postfix); //��ȯ�� postfix�� ���
		printf("��� ���: %lf\n", result);
	}
	else if (choice == 2) {
		char* infix = (char*)malloc(sizeof(char) * 100);
		printf("������ �Է��ϼ��� : ");
		gets(infix);
		char* prefix = infix_to_prefix(infix);
		char* postfix = infix_to_postfix(infix);
		Sign_check(infix);
		check_matching(infix);
		printf("������: %s\n", infix);
		printf("������: %s\n", prefix);
		printf("������: %s\n", postfix);
		double result = eval(postfix);
		printf("��� ���: %lf\n", result);
	}
	else if (choice == 3) {
		char* postfix = (char*)malloc(sizeof(char) * 100);
		printf("������ �Է��ϼ��� : ");
		gets(postfix);
		char* infix = postfix_to_infix(postfix);
		char* prefix = infix_to_prefix(infix);
		Sign_check(infix);
		check_matching(infix);
		printf("������: %s\n", infix);
		printf("������: %s\n", prefix);
		printf("������: %s\n", postfix);
		double result = eval(postfix);
		printf("��� ���: %lf\n", result);
	}
	
	printf("���α׷��� �����մϴ�.");
	return 0;
	
}