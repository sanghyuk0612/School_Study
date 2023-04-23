#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct { // 큐 타입
	element* data;
	int max_size;
	int front, rear;
	int count;
}QueueType;
// 오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 초기화
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
	q->count = 0;
	q->max_size = 5;
}
// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->count == 0);
}
// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return (q->max_size-1 == q->count);
}
// 원형큐 출력 함수
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
	element temp[100]; //임시로 사용
	int i = 0; 
	int j = 0;
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i) % (q->max_size);
			temp[j++] = q->data[i]; // 앞에서부터 값을 순서대로 temp에 넣어줌
			if (i == q->rear)
				break;
			i++;
		} while (i != q->front);
	}
	i = 0;
	while (i < q->max_size) {
		q->data[i] = temp[i]; //temp에 넣었던 값을 data부분에 차례대로 넣어줌
		i++;
	}
	q->max_size *= 2;
	q->front = 0; // front와 rear 재설정
	q->rear = i-1;
	q->data = (element*)realloc(q->data, q->max_size * sizeof(element)); // 메모리 늘려줌
}
// 삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q)) {
		rerize(q);
	}
	q->data[q->rear] = item;
	q->rear = (q->rear+1) % q->max_size;
	q->count++;
}
// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front) % q->max_size;
	q->count--;
	
	return q->data[q->front++];
}

int main(void) {
	QueueType* queue;
	queue = (QueueType*)malloc(sizeof(QueueType));
	init_queue(queue);
	queue->data = (element*)malloc(sizeof(element) * queue->max_size);
	printf("--데이터 추가 단계--\n");
	element item = 1;
	while (item <101) {

		enqueue(queue, item);
		Queue_print(queue);
		item++;
	}
	/*
	printf("--데이터 삭제 단계--\n");
	while (!is_empty(queue)) {
		item = dequeue(queue);
		printf("꺼내진 정수: %d\n", item);
		Queue_print(queue);
	}
	printf("큐는 공백상태입니다.\n");
	*/
	return 0;
}