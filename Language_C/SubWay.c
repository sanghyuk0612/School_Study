#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <limits.h>
#include<time.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 552
#define INF 9999 // 무한대 (연결이 없는 경우)
//그래프 타입정의
typedef struct GraphType {
    int n; // 정점의 개수
    int** weight;// [MAX_VERTICES] [MAX_VERTICES] ;
} GraphType;
int distance[MAX_VERTICES]; // 시작정점으로부터의 최단경로 거리
int found[MAX_VERTICES]; //방문한 정점 표시 
int path[MAX_VERTICES]; // 경로 표시
int total, transfer_time, check_tmp, t, transfer_count;

//에러처리함수
void error(char message[]) {
    fprintf(stderr, "%s", message);
    exit(1);
}

//.csv확장자를 붙여줌
char* plus_extention(char* line) {
    char name[5] = ".csv";
    char* file_name = (char*)malloc(sizeof(char) * 30);
    strcpy(file_name, line);
    strcat(file_name, name);
    return file_name;
}

//몇호선인지 확인하는 함수
char* check_line(int line) {
    char* result = (char*)malloc(sizeof(char) * 30);
    if (0 <= line && line < 63)
        strcpy(result, "1호선");
    else if (63 <= line && line < 102)
        strcpy(result, "1지선");
    else if (102 <= line && line < 145)
        strcpy(result, "2호선");
    else if (145 <= line && line < 155)
        strcpy(result, "2지선");
    else if (155 <= line && line < 198)
        strcpy(result, "3호선");
    else if (198 <= line && line < 246)
        strcpy(result, "4호선");
    else if (246 <= line && line < 290)
        strcpy(result, "5호선");
    else if (290 <= line && line < 298)
        strcpy(result, "5지선");
    else if (298 <= line && line < 336)
        strcpy(result, "6호선");
    else if (336 <= line && line < 378)
        strcpy(result, "7호선");
    else if (378 <= line && line < 395)
        strcpy(result, "8호선");
    else if (395 <= line && line < 420)
        strcpy(result, "9호선");
    else if (420 <= line && line < 445)
        strcpy(result, "분당선");
    else if (445 <= line && line < 474)
        strcpy(result, "인천1선");
    else if (474 <= line && line < 502)
        strcpy(result, "중앙선");
    else if (502 <= line && line < 525)
        strcpy(result, "경춘선");
    else if (525 <= line && line < 543)
        strcpy(result, "경의선");
    else
        strcpy(result, "공항철도");
    return result;
}

//최소거리리턴
int choose(int distance[], int n, int found[])
{
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for (i = 0; i < n; i++)
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    return minpos;
}


//최단거리
void shortest_path(GraphType* g, int start)
{
    int i, u, w;
    for (i = 0; i < g->n; i++) // 초기화
    {
        distance[i] = g->weight[start][i];
        path[i] = start;
        found[i] = FALSE;
    }
    found[start] = TRUE; //시작 정점 방문 표시
    path[start] = start;
    distance[start] = 0;

    for (i = 0; i < g->n - 1; i++) {
        u = choose(distance, g->n, found);
        found[u] = TRUE;
        for (w = 0; w < g->n; w++) {
            if (!found[w]) {
                if (distance[u] + g->weight[u][w] < distance[w]) {
                    distance[w] = distance[u] + g->weight[u][w];
                    path[w] = u; //더 짧은 길이 있다면 새로 업데이트
                }
            }
        }
    }
}

//몇번째 줄인지 검사하고 무슨역인지 리턴해줌
char* find_station(int num) {
    FILE* pFile = NULL;
    pFile = fopen("역이름.csv", "r"); //파일열기
    if (pFile == NULL)
        error("파일에러");
    char str_tmp[1024];
    char tmp_code[20];
    char* tmp_name = (char*)malloc(sizeof(char) * 30);
    fgets(str_tmp, sizeof(str_tmp), pFile);
    fgets(str_tmp, sizeof(str_tmp), pFile);
    for (int i = 0; i < num; i++) { //선택한 줄까지 계속해서 다음줄로 넘어감
        fgets(str_tmp, sizeof(str_tmp), pFile);
    }
    strcpy(tmp_code, strtok(str_tmp, ","));
    strcpy(tmp_name, strtok(NULL, "\n,"));//선택한 줄이 됐으면 두번째로 있는 역이름 리턴
    fclose(pFile);
    pFile = NULL;
    return tmp_name;
}

// 파일안에 있는 num줄의 첫번째 이름 리턴
char* num_line(char* line, int num) {
    FILE* pFile = NULL;
    char File_name[30];
    strcpy(File_name, plus_extention(line)); //확장자 붙이기
    pFile = fopen(File_name, "r");
    if (pFile == NULL)
        error("파일에러");
    char str_tmp[1024];
    char tmp_name[30], code[30];
    char* tmp_code = (char*)malloc(sizeof(char) * 30);
    fgets(str_tmp, sizeof(str_tmp), pFile);
    fgets(str_tmp, sizeof(str_tmp), pFile);
    for (int i = 0; i < num; i++) {
        fgets(str_tmp, sizeof(str_tmp), pFile);
    }
    strcpy(tmp_code, strtok(str_tmp, ","));
    fclose(pFile);
    pFile = NULL;
    return tmp_code;
}

//최단경로 출력함수
void print_path(int start, int end, GraphType* g)
{
    if (path[end] == start) // 첫번째 역일시
        printf("<출발>\n");
    int sg = t++; //몇번째 정류장인지 체크
    if (path[end] != start)
        print_path(start, path[end], g); // 재귀함수 호출
    if (check_tmp == 1) { //전역이 환승역이였으면 넘어감
        check_tmp = 0; //tmp0으로 초기화
        return;
    }

    char station1[20];
    char station2[20];
    char line[20];
    strcpy(line, check_line(path[end])); //몇호선인지 체크
    strcpy(station1, find_station(end)); //무슨역인지 확인
    strcpy(station2, find_station(path[end]));  //무슨역인지 확인
    if (strcmp(station2, station1) == 0 && sg != 0) { //전역과 다음역이 같으면 환승
        if (total != 0) {//첫번째역이 환승역이 아니면
            total += g->weight[path[end]][end];
            printf("-><환승 :  소요시간 %d분> %s\n", g->weight[path[end]][end], station2); //환승멘트 출력
            transfer_time += g->weight[path[end]][end]; //환승시간 저장
            t--; //총 역에서 제외함
            check_tmp = 1; //환승역체크
            transfer_count++; //환승횟수 추가
        }
        else
            t--; //첫번째역이 환승역일시 총 역에서 제외하고 다음으로 넘어감
    }

    else { // 환승이 아닐시
        if ((strcmp(station2, station1) != 0)) {
            total += g->weight[path[end]][end]; //총 시간에 더해줌

            printf("-><%s> %s    \n", line, station2); //출력
        }
        else
            t--;
    }
    if (sg == 0) { //마지막역이면
        printf("-><%s> %s  <도착>  \n\n", line, station1); //마지막역 출력
        printf("소요시간 : %d (%d + 환승 소요시간 : %d)분\n", total, total - transfer_time, transfer_time); // 총시간 환승시간출력
        printf("정거장 수 : %d 개\n", t + 1); //총 정류장수출력
    }
}

//몇줄인지 체크
int count_line(char* line) {
    int count = -1;

    char file_name[30];
    char str_tmp[1024];
    strcpy(file_name, plus_extention(line));
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        error("파일열기에 실패했습니다");
    }
    while (fgets(str_tmp, sizeof(str_tmp), fp) != NULL) {//입력받은 호선의 파일이 끝날때까지 count에 +1씩 더함
        count++;
    }
    fclose(fp);
    fp = NULL;
    return count; //count 값을 리턴해줌
}

//int형의 n*n배열대로 동적할당
int** make_mat(char* line) {
    int num = count_line(line);
    int** mat = (int**)malloc(sizeof(int*) * (num));
    for (int i = 0; i < num; i++) { //반복문 사용해 2차원 동적할당
        mat[i] = (int*)malloc(sizeof(int) * (num));
    }
    return mat;
}

//호선별로 2차원 동적배열로 만들어줌
int** make_station(char* line) {
    FILE* fp;
    int i, j;
    char str_tmp[1024];
    // 파일 오픈
    int** station = make_mat(line); //2차원 배열을 동적할당해줌
    char file_name[30];
    strcpy(file_name, plus_extention(line)); // 뒤에 .csv를 붙임
    fp = fopen(file_name, "rt"); //파일을 읽음
    if (fp == NULL) {
        error("파일열기 실패");
    }
    int num = count_line(line);
    i = 0;
    fgets(str_tmp, sizeof(str_tmp), fp);
    while (fgets(str_tmp, sizeof(str_tmp), fp) != NULL) {
        char* ptr = strtok(str_tmp, ",\n");
        j = 0;
        ptr = strtok(NULL, ",\n");
        while (ptr != NULL) {
            station[i][j] = atoi(ptr);
            ptr = strtok(NULL, ",\n");
            j++;
        }
        i++;
    }
    fclose(fp);
    fp = NULL;
    return station;

}



//역이름을 입력받아서 그 역의 코드를 리턴
char* search_code(char* name) {
    FILE* pFile = NULL;

    pFile = fopen("역이름.csv", "r");
    if (pFile == NULL) {
        error("파일열기 실패");
    }
    char str_tmp[1024];
    char tmp_code[20], tmp_name[30];
    char* code = (char*)malloc(sizeof(char) * 30);
    while (fgets(str_tmp, sizeof(str_tmp), pFile) != NULL) { //문장 읽어옴
        strcpy(tmp_code, strtok(str_tmp, ","));//,를 기준으로 분리
        strcpy(tmp_name, strtok(NULL, "\n,")); // 과 \n을 기준으로 분리

        if (!strcmp(tmp_name, name)) {
            strcpy(code, tmp_code); //입력받은 역코드와 파일안에있는 코드와 비교
            fclose(pFile);
            return code;
        }
    }
    error("찾는 역이 없습니다.");
    fclose(pFile);
    pFile = NULL;
    return NULL; // 못찾았으면 NULL리턴
}

//역코드를보고 몇번째줄에 있는지 리턴
int search(char* line_name, char* name) {
    FILE* pFile = NULL;
    char File_name[30];
    strcpy(File_name, plus_extention(line_name)); //확장자 붙여주기
    pFile = fopen(File_name, "r");
    if (pFile == NULL) {
        error("파일열기 실패");
    }
    char str_tmp[1024];
    char* tmp;
    int line = -1;

    (fgets(str_tmp, sizeof(str_tmp), pFile) != NULL); //첫줄은 버림
    while (fgets(str_tmp, sizeof(str_tmp), pFile) != NULL)
    {
        line++;
        tmp = strtok(str_tmp, ",\n"); //이름을 받아와서 비교
        if (strcmp(name, tmp) == 0) {
            fclose(pFile);
            return line;

        }
        tmp = strtok(NULL, ",\n");
    }
    error("찾는 코드의 역이 없습니다.");
    fclose(pFile);
    pFile = NULL;
}

//mat에 환승을 추가해줌
void plus_transfer(int** mat) {
    FILE* pFile = NULL;
    pFile = fopen("환승정보.csv", "r");
    if (pFile == NULL) {
        error("파일열기 실패");
    }
    srand(time(NULL));
    char str_tmp[1024];
    int maxnum = count_line("환승정보");
    char tmp_code[30], tmp_name[30], s_code[30], tmp[30];
    int tmp_num, num1, num2;
    int tmp_add[10], tmp_add2[10];
    int i;
    fgets(str_tmp, sizeof(str_tmp), pFile);
    while (fgets(str_tmp, sizeof(str_tmp), pFile) != NULL) {
        tmp_num = 0;
        i = 0;
        strcpy(s_code, strtok(str_tmp, ",\n"));
        strcpy(tmp, strtok(NULL, ",\n"));
        while (tmp_num < maxnum - 1) {
            if ((strcmp(tmp, "9999") != 0) && (strcmp(tmp, "0") != 0)) { //환승역이라면
                tmp_add[i] = tmp_num; // 환승정보를 저장해둠
                tmp_add2[i++] = atoi(tmp); //그 환승하는데 소요시간을 정수형으로 변환뒤 대입
            }
            tmp_num++;
            strcpy(tmp, strtok(NULL, ",\n"));
        }
        int k = 0;
        for (int j = 0; j < i; j++) {
            strcpy(tmp_code, num_line("환승정보", tmp_add[k])); //저장했던 것을 인접행렬에 넣어줌
            num1 = search("역이름", tmp_code);
            num2 = search("역이름", s_code);
            int n = tmp_add2[k++];
            mat[num2][num1] = (rand() % n + 1);//랜덤함수 사용
        }

    }
    fclose(pFile);
    pFile = NULL;
}

//환승을 가중치 1로 바꿔줌
void plus_min_transfer(GraphType* g) {
    FILE* pFile = NULL;
    pFile = fopen("환승정보.csv", "r");
    if (pFile == NULL) {
        error("파일열기 실패");
    }
    srand(time(NULL));
    char str_tmp[1024];
    int maxnum = count_line("환승정보");
    char transfer_tmp[1024];
    char tmp_code[30], tmp_name[30], s_code[30], tmp[30];
    int tmp_num, num1, num2;
    int tmp_add[10];
    int i;
    strcpy(transfer_tmp, fgets(str_tmp, sizeof(str_tmp), pFile));
    while (fgets(str_tmp, sizeof(str_tmp), pFile) != NULL) {
        tmp_num = 0;
        i = 0;
        strcpy(s_code, strtok(str_tmp, ",\n"));
        strcpy(tmp, strtok(NULL, ",\n"));
        while (tmp_num < maxnum - 1) {
            if ((strcmp(tmp, "9999") != 0) && (strcmp(tmp, "0") != 0)) {
                tmp_add[i++] = tmp_num; // 환승정보를 저장해둠

            }
            tmp_num++;
            strcpy(tmp, strtok(NULL, ",\n"));
        }
        int k = 0;
        for (int j = 0; j < i; j++) {
            strcpy(tmp_code, num_line("환승정보", tmp_add[k++]));
            num1 = search("역이름", tmp_code);
            num2 = search("역이름", s_code);
            g->weight[num2][num1] = 1; //환승시 가중치를 1로 변환
        }
    }
    fclose(pFile);
    pFile = NULL;
}

//환승을 제외하고 모두 가중치를 0으로 만들어줌 환승시 가중치 1
void change_min_transfer(GraphType* g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            if (g->weight[i][j] != INF && g->weight[i][j] != 0) {
                g->weight[i][j] = 0; //INF와 0이 아니면 전부 0으로 만들어줌
            }
        }
    }
    plus_min_transfer(g); //환승역의 가중치인 1을 추가해주는 함수
}

//최소환승경로를 출력해주는함수
void print_min_transfer(int start, int end, GraphType* g, int** mat) {
    int sg = t++; //몇번째 정류장인지 체크
    if (path[end] == start)
        printf("<출발>\n"); //시작점 체크
    if (path[end] != start)
        print_min_transfer(start, path[end], g, mat);
    if (check_tmp == 1) { //전역이 환승역이였으면 넘어감
        check_tmp = 0;
        return;
    }

    char station1[20];
    char station2[20];
    char line[20];
    strcpy(line, check_line(path[end]));
    strcpy(station1, find_station(end));
    strcpy(station2, find_station(path[end]));
    char line1[30], line2[30];
    strcpy(line1, check_line(end));
    strcpy(line2, check_line(path[end]));
    if (strcmp(line1, line2) != 0 && sg != 0) { //전역과 이번역의 호선이 다르면 환승 그리고 마지막역이 환승역일 경우 넘어감
        if (total != 0) {//첫번째역이 환승역이 아니면
            total += mat[path[end]][end];
            printf("-><환승 :  소요시간 %d분> %s\n", mat[path[end]][end], station2); //환승멘트 출력
            transfer_time += mat[path[end]][end]; //환승시간 저장
            t--; //환승역은 두번으로 체크되기 때문에 총 역에서 제외함
            check_tmp = 1; //환승역체크
            transfer_count++; //환승횟수 추가
        }
        else
            t--; //총 역에서 제외함
    }

    else {
        if ((strcmp(station2, station1) != 0)) {
            total += mat[path[end]][end]; //총 시간에 더해줌
            printf("-><%s> %s    \n", line, station2); //출력
        }
        else
            t--;
    }
    if (sg == 0) { //마지막역이면
        printf("-><%s> %s  <도착>  \n\n", line, station1); //마지막역 출력
        printf("소요시간 : %d (%d + 환승 소요시간 : %d)분\n", total, total - transfer_time, transfer_time); // 총시간 환승시간출력
        printf("정거장 수 : %d 개\n", t + 1); //총 정류장수출력
    }
}

//모든 호선을 받아와서 하나의 큰 행렬로 만듬
int** plus_line() {
    int** line1, ** line12, ** line2, ** line22, ** line3, ** line4, ** line5, ** line6, ** line7, ** line8, ** line9, ** lineAir;
    int** lineIncheon, ** lineCenter, ** lineGyeong, ** lineChun, ** lineBun;
    line1 = make_station("1호선"); line12 = make_station("1지선"); line2 = make_station("2호선"); line22 = make_station("2지선");
    line3 = make_station("3호선"); line4 = make_station("4호선"); line5 = make_station("5호선"); line6 = make_station("6호선");
    line7 = make_station("7호선"); line8 = make_station("8호선"); line9 = make_station("9호선"); lineAir = make_station("공항철도");
    lineIncheon = make_station("인천1선"); lineCenter = make_station("중앙선"); lineGyeong = make_station("경의선");
    lineChun = make_station("경춘선"); lineBun = make_station("분당선");
    int** final_mat = make_mat("역이름");
    int num = count_line("역이름");
    int tmp;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            final_mat[i][j] = INF;
        }
    }

    num = count_line("1호선");
    int k = 0, l = 0;
    for (int i = 0; i < num; i++) {
        l = 0;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = line1[i][j];
            l++;
        }
        k++;
    }
    //tmp값부터 이어서 붙임
    tmp = l;
    num = count_line("1지선");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = line12[i][j];
            l++;
        }
        k++;
    }
    tmp = l;
    num = count_line("2호선");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = line2[i][j];
            l++;
        }
        k++;
    }
    tmp = l;
    num = count_line("2지선");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = line22[i][j];
            l++;
        }
        k++;
    }
    tmp = l;
    num = count_line("3호선");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = line3[i][j];
            l++;
        }
        k++;
    }
    tmp = l;
    num = count_line("4호선");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = line4[i][j];
            l++;
        }
        k++;
    }
    tmp = l;
    num = count_line("5호선");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = line5[i][j];
            l++;
        }
        k++;
    }
    tmp = l;
    num = count_line("5지선");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = line6[i][j];
            l++;
        }
        k++;
    }
    tmp = l;
    num = count_line("6호선");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = line6[i][j];
            l++;
        }
        k++;
    }
    tmp = l;
    num = count_line("7호선");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = line7[i][j];
            l++;
        }
        k++;
    }
    tmp = l;
    num = count_line("8호선");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = line8[i][j];
            l++;
        }
        k++;
    }
    tmp = l;
    num = count_line("9호선");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = line9[i][j];
            l++;
        }
        k++;
    }
    tmp = l;
    num = count_line("분당선");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = lineBun[i][j];
            l++;
        }
        k++;
    }
    tmp = l;
    num = count_line("인천1선");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = lineIncheon[i][j];
            l++;
        }
        k++;
    }
    tmp = l;
    num = count_line("중앙선");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = lineCenter[i][j];
            l++;
        }
        k++;
    }
    tmp = l;
    num = count_line("경춘선");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = lineChun[i][j];
            l++;
        }
        k++;
    }
    tmp = l;
    num = count_line("경의선");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = lineGyeong[i][j];
            l++;
        }
        k++;
    }
    tmp = l;
    num = count_line("공항철도");
    for (int i = 0; i < num; i++) {
        l = tmp;
        for (int j = 0; j < num; j++) {
            final_mat[k][l] = lineAir[i][j];
            l++;
        }
        k++;
    }
    plus_transfer(final_mat);
    return final_mat;
}

int main(void) {

    FILE* pFile = NULL;
    pFile = fopen("역이름.csv", "r"); // 파일 열기
    char str_tmp[1024];
    int found_start = 0, found_end = 0;
    int choice, start_num, end_num;
    char S_code[20], S_name[30], start[30], end[30], start_code[10], end_code[10];
    while (found_end == 0 || found_start == 0) {
        pFile = fopen("역이름.csv", "r");
        printf("출발역을 입력해주세요 : ");
        scanf("%s", start);
        printf("도착역을 입력해주세요 : ");
        scanf("%s", end);
        if (strcmp(start, end) == 0) { //출발점과 도착점이 같을 경우 예외처리
            printf("출발역과 도착역이 같습니다.\n");
            continue;
        }
        while (fgets(str_tmp, sizeof(str_tmp), pFile) != NULL) {
            strcpy(S_code, strtok(str_tmp, ","));
            strcpy(S_name, strtok(NULL, "\n,"));
            if (!strcmp(S_name, start)) { //출발값과 파일에 있는 이름 비교
                strcpy(start_code, S_code);
                found_start = 1;
                break;
            }
        }

        if (found_start == 0) {
            fprintf(stderr, "찾으시는 출발역이 없습니다.다시 입력해주세요.\n");
            fclose(pFile);
            continue;
        }
        fclose(pFile);
        pFile = NULL;
        pFile = fopen("역이름.csv", "r");
        while (fgets(str_tmp, sizeof(str_tmp), pFile) != NULL) {
            strcpy(S_code, strtok(str_tmp, ","));
            strcpy(S_name, strtok(NULL, "\n,"));
            if (!strcmp(S_name, end)) { //도착값과 파일에 있는 이름 비교
                strcpy(end_code, S_code);
                found_end = 1;
                break;
            }
        }
        if (found_end == 0) {
            fprintf(stderr, "찾으시는 도착역이 없습니다.다시 입력해주세요.\n");
            fclose(pFile);
            continue;
        }
        fclose(pFile);
    }
    printf("1. 최단거리, 2. 최소환승\n:");
    scanf("%d", &choice);
    while (choice != 1 && choice != 2) {
        printf("올바른 번호를 입력해주세요\n"); //1번2번이외의 번호 예외처리
        printf("1. 최단거리, 2. 최소환승\n:");
        scanf("%d", &choice);
    }
    printf("\n\n");
    if (choice == 1) {
        printf("최단거리\n");
    }
    else if (choice == 2) {
        printf("최소환승\n");
    }


    char line[10];
    char code[10];

    start_num = search("역이름", start_code);

    end_num = search("역이름", end_code);


    GraphType g;
    int** final_mat = plus_line(); //지하철 노선도의 정보를 담고 있는 인접행렬 생성
    g.n = count_line("역이름"); //g의n의 총 역의 수 대입
    g.weight = final_mat; //가중치 저장



    if (choice == 1) {
        shortest_path(&g, start_num);
        print_path(start_num, end_num, &g);
    }
    if (choice == 2) {
        change_min_transfer(&g);
        shortest_path(&g, start_num);
        int** weight = plus_line(); //최소환승을 처리하기위해 재할당
        print_min_transfer(start_num, end_num, &g, weight);
    }
    return 0;
}
