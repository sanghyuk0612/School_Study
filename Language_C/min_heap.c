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
// 생성 함수
HeapType* create_heap()
{
	return(HeapType*)malloc(sizeof(HeapType));
}
//노드생성함수
element* new_element() {
	return (element*)malloc(sizeof(element));
}
// 초기화 함수
void init_heap(HeapType* h)
{
	h-> heap_size=0;
}
//공백인지 체크해주는 함수
int is_empty(HeapType* h) {
	return (h->heap_size == 0);	
}
//최상위 요소 리턴해주는 함수
element find(HeapType* h) {
	return h->heap[1];
}

// 삽입 함수
void insert_min_heap(HeapType* h, element *item)
{
	int i;
	i = ++(h->heap_size);
	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item->key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i]  = *item; // 새로운 노드를 삽입
}
// 삭제 함수
element delete_min_heap(HeapType* h)
{
	if (is_empty(h)) {
		printf("heap is empty");
		exit(1);
	}
	int parent, child;
	element item = find(h); //find 함수 사용
	element temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) 
			break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
int main(void) {
	element* e1, *e2, * e3, * e4, * e5 ;
	e1 = new_element(); //노드생성
	e1->key = 30;

	e2 = new_element();//노드생성
	e2->key = 50;

	e3 = new_element();//노드생성
	e3->key = 10;

	e4 = new_element();//노드생성
	e4->key = 20;

	e5 = new_element();//노드생성
	e5->key = 5;

	HeapType* heap;
	heap = create_heap(); // 히프 생성
	init_heap(heap); // 초기화
	// 삽입
	insert_min_heap(heap, e1);
	insert_min_heap(heap, e2);
	insert_min_heap(heap, e3);
	insert_min_heap(heap, e4);
	insert_min_heap(heap, e5);
	free(e1); free(e2); free(e3); free(e4); free(e5); //메모리 할당해제
	// 삭제
	printf("<%d> ", delete_min_heap(heap).key);
	printf("<%d> ", delete_min_heap(heap).key);
	printf("<%d> ", delete_min_heap(heap).key);
	printf("<%d> ", delete_min_heap(heap).key);
	printf("<%d> ", delete_min_heap(heap).key);
	free(heap);
	return 0;
}