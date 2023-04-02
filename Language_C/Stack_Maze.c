#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAZE_SIZE 6

typedef struct { // 교체!
    short r;
    short c;
} element;

element here = { 1,0 }, entry = { 1,0 };
typedef struct stack {
    int capacity;
    int top;
    element* data;
} StackType;

void initStack(StackType* s) {
    s->capacity = 1;
    s->top = -1;
    s->data = (element*)malloc(s->capacity * sizeof(element));
}
char maze[MAZE_SIZE][MAZE_SIZE] = {
    { '1', '1', '1', '1', '1', '1' },
    { 'e', '0', '0', '0', '1', '1' },
    { '1', '1', '0', '1', '1', '1' },
    { '1', '1', '0', '1', '1', '1' },
    { '1', '0', '0', '0', '0', 'x' },
    { '1', '1', '1', '1', '1', '1' },
};
void push(StackType* s, element item) {
    if (is_full(s)) {
        s->capacity *= 2;
        s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[++s->top] = item;
}

void push_loc(StackType* s, int r, int c){
    if (r < 0 || c < 0 ) return 0;
    if (maze[r][c] != '1' && maze[r][c] != '.') {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}
// 미로를 화면에 출력한다.
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
    printf("\n");
        for (int r = 0; r < MAZE_SIZE; r++) {
            for (int c = 0; c < MAZE_SIZE; c++) {
                printf("%c", maze[r][c]);
            }
            printf("\n");
        }
}
int is_empty(StackType* s) {
    return s->top == -1;
}

int is_full(StackType* s) {
    return s->top == (s->capacity - 1);
}
element pop(StackType* s) {
    if (is_empty(s))
        fprintf(stderr, "스택 공백 에러\n");
    return s->data[s->top--];
}
element peek(StackType* s) {
    if (is_empty(s))
        fprintf(stderr, "스택 공백 에러\n");
    return s->data[s->top];
}
int main(void) {
    int r, c;
    StackType s;
    initStack(&s);
    here = entry;
    while (maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        maze_print(maze);
        push_loc(&s, r- 1, c);
        push_loc(&s, r + 1, c);
        push_loc(&s, r, c- 1);
        push_loc(&s, r, c + 1);
        
        if (is_empty(&s)) {
            printf("실패\n");
                return 0;
        }
        else
            here = pop(&s);
    }
    printf("성공\n");
    return 0;
}
