#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#define MAX_ELEMENT 200
typedef struct
{
	int key;
} element;

typedef struct
{
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType; 
// ���� �Լ�
HeapType* create_heap()
{
	return(HeapType*)malloc(sizeof(HeapType));
}
//�������Լ�
element* new_element() {
	return (element*)malloc(sizeof(element));
}
// �ʱ�ȭ �Լ�
void init_heap(HeapType* h)
{
	h-> heap_size=0;
}
//�������� üũ���ִ� �Լ�
int is_empty(HeapType* h) {
	return (h->heap_size == 0);	
}
//�ֻ��� ��� �������ִ� �Լ�
element find(HeapType* h) {
	return h->heap[1];
}

// ���� �Լ�
void insert_min_heap(HeapType* h, element *item)
{
	int i;
	i = ++(h->heap_size);
	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item->key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i]  = *item; // ���ο� ��带 ����
}
// ���� �Լ�
element delete_min_heap(HeapType* h)
{
	if (is_empty(h)) {
		printf("heap is empty");
		exit(1);
	}
	int parent, child;
	element item = find(h); //find �Լ� ���
	element temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ�� �� �� ū �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) 
			break;
		// �� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
int main(void) {
	element* e1, *e2, * e3, * e4, * e5 ;
	e1 = new_element(); //������
	e1->key = 30;

	e2 = new_element();//������
	e2->key = 50;

	e3 = new_element();//������
	e3->key = 10;

	e4 = new_element();//������
	e4->key = 20;

	e5 = new_element();//������
	e5->key = 5;

	HeapType* heap;
	heap = create_heap(); // ���� ����
	init_heap(heap); // �ʱ�ȭ
	// ����
	insert_min_heap(heap, e1);
	insert_min_heap(heap, e2);
	insert_min_heap(heap, e3);
	insert_min_heap(heap, e4);
	insert_min_heap(heap, e5);
	free(e1); free(e2); free(e3); free(e4); free(e5); //�޸� �Ҵ�����
	// ����
	printf("<%d> ", delete_min_heap(heap).key);
	printf("<%d> ", delete_min_heap(heap).key);
	printf("<%d> ", delete_min_heap(heap).key);
	printf("<%d> ", delete_min_heap(heap).key);
	printf("<%d> ", delete_min_heap(heap).key);
	free(heap);
	return 0;
}