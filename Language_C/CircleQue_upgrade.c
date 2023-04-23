#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct { // ť Ÿ��
	element* data;
	int max_size;
	int front, rear;
	int count;
}QueueType;
// ���� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// �ʱ�ȭ
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
	q->count = 0;
	q->max_size = 5;
}
// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->count == 0);
}
// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return (q->max_size-1 == q->count);
}
// ����ť ��� �Լ�
void Queue_print(QueueType* q)
{
	printf("QUQUE(front=%d rear=%d,count = %d) = ", q->front, q->rear,q->count);
	int j =0;
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = i % (q->max_size);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
			i++;
			j++;
		} while (j < q->count);
	}
	printf("\n");
}
void rerize(QueueType *q) {
	element temp[100]; //�ӽ÷� ���
	int i = 0; 
	int j = 0;
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i) % (q->max_size);
			temp[j++] = q->data[i]; // �տ������� ���� ������� temp�� �־���
			if (i == q->rear)
				break;
			i++;
		} while (i != q->front);
	}
	i = 0;
	while (i < q->max_size) {
		q->data[i] = temp[i]; //temp�� �־��� ���� data�κп� ���ʴ�� �־���
		i++;
	}
	q->max_size *= 2;
	q->front = 0; // front�� rear �缳��
	q->rear = i-1;
	q->data = (element*)realloc(q->data, q->max_size * sizeof(element)); // �޸� �÷���
}
// ���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q)) {
		rerize(q);
	}
	q->data[q->rear] = item;
	q->rear = (q->rear+1) % q->max_size;
	q->count++;
}
// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front) % q->max_size;
	q->count--;
	
	return q->data[q->front++];
}

int main(void) {
	QueueType* queue;
	queue = (QueueType*)malloc(sizeof(QueueType));
	init_queue(queue);
	queue->data = (element*)malloc(sizeof(element) * queue->max_size);
	printf("--������ �߰� �ܰ�--\n");
	element item = 1;
	while (item <101) {

		enqueue(queue, item);
		Queue_print(queue);
		item++;
	}
	/*
	printf("--������ ���� �ܰ�--\n");
	while (!is_empty(queue)) {
		item = dequeue(queue);
		printf("������ ����: %d\n", item);
		Queue_print(queue);
	}
	printf("ť�� ��������Դϴ�.\n");
	*/
	return 0;
}