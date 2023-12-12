#include <stdio.h>
#include <conio.h> // _getch
#include <windows.h> // gotoxy, cursor, system
#include <stdlib.h> // malloc
#include <string.h> // memset	
#include <time.h> // 시간 계산 함수들(정렬 알고리즘 속도체크) 
#include <stdbool.h> // bool 관련
#include <limits.h> // 최대, 최소, 비트 수 등

void gotoxy(int x, int y); // 커서 이동 함수
void cursor(int n); // 커서 감추기 위한 함수
void draw_boxArea(void); // 화면 영역 함수
void startMenu(void); // 초기 화면 함수
void sortMenu(void); // 정렬 알고리즘 메뉴 함수
void graphMenu(void); // 그래프 알고리즘 메뉴 함수
void selectionSortPage(void); // 선택 정렬 화면 출력 함수
void bubbleSortPage(void); // 버블 정렬 화면 출력 함수
void insertionSortPage(void); // 삽입 정렬 화면 출력 함수
void mergeSortPage(void); // 합병 정렬 화면 출력 함수
void quickSortPage(void); // 퀵 정렬 화면 출력 함수
void heapSortPage(void); // 힙 정렬 화면 출력 함수
void shellSortPage(void); // 셸 정렬 화면 출력 함수
void countingSortPage(void); // 계수 정렬 화면 출력 함수
void radixSortPage(void); // 기수 정렬 화면 출력 함수
void speedCheck(void); // 정렬 속도 비교 함수
void BFSPage(void); // BFS 화면 출력 함수
void DFSPage(void); // DFS 화면 출력 함수
void primPage(void); // 프림 화면 출력 함수
void kruskalPage(void); // 크루스칼 화면 출력 함수

int stack[11];
int queue[11];
int front = -1;
int rear = -1;
int top = -1;
int graph[11][11];
bool visited[11];
int visitedList[11];
int visitedCount = 0;

int main(void) // 메인 함수
{
	system(" mode  con lines=40   cols=130 "); // 콘솔창 크기 조절
	startMenu(); // 초기 화면
	return 0;
}

void startMenu(void) // 초기 화면
{
	draw_boxArea(); // 네모 영역 그리는 함수

	// 초기 설명 시작
	gotoxy(20, 3);
	puts("*------------------------- 알고리즘 학습 프로그램 -------------------------*");
	gotoxy(24, 7);
	puts("알고리즘 학습에 도움을 줄 수 있는 프로그램입니다!");
	gotoxy(24, 9);
	puts("원하는 메뉴의 번호키를 입력하세요");
	gotoxy(24, 13);
	puts("1. 정렬 알고리즘 학습");
	gotoxy(24, 15);
	puts("2. 그래프 알고리즘 학습");
	gotoxy(24, 19);
	puts("어느 화면에서든 (초기화면 : ESC, 이전화면 : 백스페이스, 종료 : X)");

	char key = _getch(); // 키가 입력될 시, _getch()함수는 입력 버퍼도 안남기고 화면 출력도 X
	system("cls"); // 화면 지우고

	switch (key) {
	case '1':
		sortMenu(); // 1번 키를 누르면 sortMenu() 함수 호출
		break;
	case '2':
		graphMenu(); // 2번 키를 누르면 graphMenu() 함수 호출
		break;
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	default: // 다른 키가 들어올 때는 다시 초기화면
		startMenu();
		break;
	}
}
void sortMenu(void) // 정렬 알고리즘 메뉴 그리는 함수
{
	draw_boxArea();

	gotoxy(20, 3);
	puts("*------------------------- 알고리즘 학습 프로그램 -------------------------*");
	gotoxy(24, 7);
	puts("정렬 학습 메뉴입니다. 원하는 메뉴의 번호를 입력하세요");
	gotoxy(24, 9);
	puts("모든 정렬 알고리즘에 대한 설명은 오름차순 기준입니다.");
	gotoxy(24, 13);
	puts("1. 선택 정렬 학습");
	gotoxy(24, 15);
	puts("2. 버블 정렬 학습");
	gotoxy(24, 17);
	puts("3. 삽입 정렬 학습");
	gotoxy(24, 19);
	puts("4. 합병 정렬 학습");
	gotoxy(24, 21);
	puts("5. 퀵 정렬 학습");
	gotoxy(24, 23);
	puts("6. 힙 정렬 학습");
	gotoxy(55, 13);
	puts("7. 셸 정렬 학습");
	gotoxy(55, 15);
	puts("8. 계수 정렬 학습");
	gotoxy(55, 17);
	puts("9. 기수 정렬 학습");
	gotoxy(55, 23);
	puts("0. 정렬 속도 비교");

	char key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case '1':
		selectionSortPage();
		break;
	case '2':
		bubbleSortPage();
		break;
	case '3':
		insertionSortPage();
		break;
	case '4':
		mergeSortPage();
		break;
	case '5':
		quickSortPage();
		break;
	case '6':
		heapSortPage();
		break;
	case '7':
		shellSortPage();
		break;
	case '8':
		countingSortPage();
		break;
	case '9':
		radixSortPage();
		break;
	case '0':
		speedCheck();
		break;
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		startMenu();
		break;
	default: // 다른 키가 들어올 때는 다시 이 화면 호출
		sortMenu();
		break;
	}
}
void graphMenu() { // 그래프 알고리즘 메뉴 그리는 함수
	draw_boxArea();

	gotoxy(20, 3);
	puts("*------------------------- 알고리즘 학습 도움 프로그램 -------------------------*");
	gotoxy(24, 7);
	puts("그래프 학습 메뉴입니다.원하는 메뉴의 번호키를 입력하세요");
	gotoxy(24, 11);
	puts("1. 너비 우선 탐색(BFS) 학습");
	gotoxy(24, 13);
	puts("2. 깊이 우선 탐색(DFS) 학습");
	gotoxy(24, 15);
	puts("3. 프림 알고리즘 학습");
	gotoxy(24, 17);
	puts("4. 크루스칼 알고리즘 학습");

	char key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case '1':
		BFSPage();
		break;
	case '2':
		DFSPage();
		break;
	case '3':
		primPage();
		break;
	case '4':
		kruskalPage();
		break;
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		startMenu();
		break;
	default: // 다른 키가 들어올 때는 다시 이 화면 호출
		graphMenu();
		break;
	}
}

void draw_boxArea(void) {
	cursor(0); // 커서 감추기

	// 네모 영역 그리기
	gotoxy(2, 0); // 좌표로 커서를 이동하는 함수
	printf("%c%c", 0xa6, 0xa3);
	for (int i = 0; i < 110; i++)
		printf("%c%c", 0xa6, 0xa1);

	for (int i = 0; i < 27; i++)
	{
		gotoxy(2, i + 1);
		printf("%c%c", 0xa6, 0xa2);
	}

	gotoxy(2, 28);
	printf("%c%c", 0xa6, 0xa6);
	for (int i = 0; i < 110; i++)
		printf("%c%c", 0xa6, 0xa1);
	printf("%c%c", 0xa6, 0xa5);
	for (int i = 0; i < 27; i++)
	{
		gotoxy(113, 27 - i);
		printf("%c%c", 0xa6, 0xa2);
	}

	gotoxy(113, 0);
	printf("%c%c", 0xa6, 0xa4);
}
void gotoxy(int x, int y) // 커서 이동 함수
{
	COORD Pos; // 좌표 담고 있는 구조체
	Pos.X = x; // x 좌표 초기화 (현재 x값으로)
	Pos.Y = y; // y 좌표 초기화 (현재 y값으로)
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); // 좌표 위치로 커서 이동 함수
}
void cursor(int n) // 커서 감추기 위한 함수
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = n; // 매개변수 n이 0이면 커서 감추고 1이면 드러나도록
	ConsoleCursor.dwSize = 1; // 커서 사이즈
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int data[], int size) {
	int max, temp = 0;

	for (int i = 0; i < size - 1; i++) {
		max = 0;
		for (int j = 1; j < size - i; j++) {
			if (data[max] < data[j]) {
				max = j;
			}
		}
		Sleep(500);
		printf("\nStep %d \n", i + 1);
		printf("현재 상태: ");
		for (int k = 0; k < size; k++) {
			if (k >= size - i) // 정렬된 부분은
				printf("\033[34m%d ", data[k]); // 파란색으로 출력
			else // 정렬되지 않은 부분은
				printf("\033[0m%d ", data[k]); // 원래 색상으로 출력
		}
		printf("\033[0m"); // 색상을 원래대로 복원
		printf("\n배열의 원소끼리 비교하여 찾은 최댓값 : \033[31m%d\033[0m\n", data[max]);
		printf("정렬되지 않은 부분의 맨 끝과 최댓값을 스왑합니다.\n");

		temp = data[(size - 1) - i]; // 맨 뒤의 값과 스왑
		data[(size - 1) - i] = data[max];
		data[max] = temp;

		printf("스왑 후 상태: ");
		for (int k = 0; k < size; k++) {
			if (k >= size - i - 1) // 정렬된 부분은
				printf("\033[34m%d ", data[k]); // 파란색으로 출력
			else // 정렬되지 않은 부분은
				printf("\033[0m%d ", data[k]); // 원래 색상으로 출력
		}
		printf("\033[0m"); // 색상을 원래대로 복원
		printf("\n\n");
	}
}
void selectionSortCode() {
	puts("선택 정렬 코드\n\n");
	puts("#include <stdio.h>");
	puts("#include <stdlib.h>");
	puts("");
	puts("void selectionSort(int data[], int size) {");
	puts("    int max, temp = 0;");
	puts("");
	puts("    for (int i = 0; i < size - 1; i++) {");
	puts("        max = 0;");
	puts("        for (int j = 1; j < size - i; j++) {");
	puts("            if (data[max] < data[j]) {");
	puts("                max = j;");
	puts("            }");
	puts("        }");
	puts("        temp = data[(size - 1) - i];");
	puts("        data[(size - 1) - i] = data[max];");
	puts("        data[max] = temp;");
	puts("    }");
	puts("}");
	puts("");
	puts("int main(void) {");
	puts("    int n = 0;");
	puts("    printf(\"정렬할 수의 개수 입력: \");");
	puts("    scanf_s(\"%d\", &n);");
	puts("");
	puts("    int* data = malloc(n * sizeof(int));");
	puts("");
	puts("    if (data == NULL) {");
	puts("        printf(\"배열 메모리 할당 실패\");");
	puts("        return 1;");
	puts("    }");
	puts("");
	puts("    printf(\"정렬할 수를 입력: \");");
	puts("    for (int i = 0; i < n; i++) {");
	puts("        scanf_s(\"%d\", &data[i]);");
	puts("    }");
	puts("");
	puts("    printf(\"정렬 전 배열 : \");");
	puts("    for (int i = 0; i < n; i++)");
	puts("        printf(\"%d \", data[i]);");
	puts("    printf(\"\\n\");");
	puts("");
	puts("    selectionSort(data, n);");
	puts("");
	puts("    printf(\"정렬 후 배열  : \");");
	puts("    for (int i = 0; i < n; i++)");
	puts("        printf(\"%d \", data[i]);");
	puts("    printf(\"\\n\");");
	puts("");
	puts("    free(data);");
	puts("    return 0;");
	puts("}");

	puts("\n\n ESC키 or 백스페이스 or X를 입력하세요");
	char key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키가 들어올 때는 다시 이 화면
		selectionSortCode();
		break;
	}
}
void selectionSortPage() {
	puts("*----------------------------------------------------선택 정렬----------------------------------------------------*\n\n");
	puts("설명: 각 원소에 대해 비교 연산하여 제일 큰 값을 찾아 배열의 뒷부분에 두는 과정을 반복하여 정렬하는 방법입니다.\n");
	puts("시간 복잡도: 모든 원소에 대해 비교 연산해서 최댓값을 찾아야 하므로 입력 수 N에 비례하는 시간,");
	puts("              그런 과정 한번을 통해 하나가 정렬되므로 모두 정렬하려면 또 입력 수 N에 비례하는 시간");
	puts("              따라서 시간복잡도는 O(N^2) 입니다.\n\n");
	puts("코드 실행을 하시겠습니까? 하시려면 Y, 아니라면 ESC키 혹은 백스페이스를 눌러주세요.\n");

	char key = _getch(); // 키가 입력되면

	switch (key) {
	case 'Y': // Y키나 y키를 누르면 코드 출력
		break;
	case 'y':
		break;
	case 'x': // x키나 X키를 누르면 종료
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESC키 누르면 초기화면
		system("cls"); // 화면 지우고
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		system("cls"); // 화면 지우고
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		system("cls"); // 화면 지우고
		selectionSortPage();
		break;
	}

	int n = 0;
	printf("정렬할 수의 개수를 입력하세요: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n만큼 동적할당

	if (data == NULL) {
		printf("배열 메모리 할당 실패");
		return 1;
	}

	printf("정렬할 수를 입력하세요 (띄어쓰기로 구분): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("정렬 전 배열 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n");

	selectionSort(data, n);

	printf("정렬 후 배열  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d ", data[i]);
	printf("\033[0m");
	printf("\n");

	free(data);

	puts("\n\n코드를 확인하시려면 Y를 입력해주세요");

	key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'Y': // Y키나 y키를 누르면 코드 출력
		selectionSortCode();
		break;
	case 'y':
		selectionSortCode();
		break;
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		selectionSortPage();
		break;
	}
}
void bubbleSort(int data[], int size) {
	int temp = 0; // 스왑을 위한 임시 변수
	for (int i = 0; i < size - 1; i++) { // 총 n - 1번의 반복만 하면 이미 정렬은 완료된 상태
		Sleep(500);
		printf("\nStep %d \n", i + 1);
		printf("현재 상태: ");
		for (int k = 0; k < size; k++) {
			if (k >= size - i) // 정렬된 부분은
				printf("\033[34m%d ", data[k]); // 파란색으로 출력
			else // 정렬되지 않은 부분은
				printf("\033[0m%d ", data[k]); // 원래 색상으로 출력
		}
		printf("\n");
		printf("\033[0m"); // 원래 색상으로 출력
		for (int j = 0; j < (size - 1) - i; j++) { // 한 바퀴 돌때마다 뒤에 큰 수가 하나씩 쌓이기에 (n - 1) - i번씩만 비교
			if (data[j] > data[j + 1]) { // 만약 둘을 비교했을 때, 이전의 값이 더 크면 스왑
				temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
			}
		}
		printf("인접한 두 원소 비교 -> 큰 값이 뒤로 가도록 스왑 -> 끝까지 반복 -> 최댓값이 맨 뒤로 위치\n");
		printf("스왑 후 상태: ");
		for (int k = 0; k < size; k++) {
			if (k >= size - 1 - i) // 정렬된 부분은
				printf("\033[34m%d ", data[k]); // 파란색으로 출력
			else // 정렬되지 않은 부분은
				printf("\033[0m%d ", data[k]); // 원래 색상으로 출력
		}
		printf("\033[0m"); // 색상을 원래대로 복원
		printf("\n\n");
	}
}
void bubbleSortCode() {
	puts("버블 정렬 코드\n\n");
	puts("#include <stdio.h>");
	puts("#include <stdlib.h>");
	puts("");
	puts("void bubbleSort(int data[], int size) {");
	puts("    int temp = 0; ");
	puts("    for (int i = 0; i < size - 1; i++) {");
	puts("        for (int j = 0; j < (size - 1) - i; j++) { ");
	puts("            if (data[j] > data[j + 1]) { ");
	puts("                temp = data[j + 1];");
	puts("                data[j + 1] = data[j];");
	puts("                data[j] = temp;");
	puts("            }");
	puts("        }");
	puts("    }");
	puts("}");
	puts("");
	puts("int main(void) {");
	puts("    int n = 0;");
	puts("    printf(\"정렬할 수의 개수 입력: \");");
	puts("    scanf_s(\"%d\", &n);");
	puts("");
	puts("    int* data = malloc(n * sizeof(int)); ");
	puts("");
	puts("    if (data == NULL) {");
	puts("        printf(\"배열 메모리 할당 실패\");");
	puts("        return 1;");
	puts("    }");
	puts("");
	puts("    printf(\"정렬할 수를 입력: \");");
	puts("    for (int i = 0; i < n; i++) {");
	puts("        scanf_s(\"%d\", &data[i]);");
	puts("    }");
	puts("");
	puts("    printf(\"정렬 전 배열 : \");");
	puts("    for (int i = 0; i < n; i++)");
	puts("        printf(\"%d \", data[i]);");
	puts("    printf(\"\\n\"); ");
	puts("");
	puts("    bubbleSort(data, n);");
	puts("");
	puts("    printf(\"정렬 후 배열  : \");");
	puts("    for (int i = 0; i < n; i++)");
	puts("        printf(\"%d \", data[i]);");
	puts("    printf(\"\\n"); ")";
	puts("");
	puts("    free(data);");
	puts("    return 0;");
	puts("}");

	puts("\n\n ESC키 or 백스페이스 or X를 입력하세요");
	char key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키가 들어올 때는 다시 이 화면
		bubbleSortCode();
		break;
	}
}
void bubbleSortPage() {
	puts("*----------------------------------------------------버블 정렬----------------------------------------------------*\n\n");
	puts("설명:  계속 인접한 원소끼리 비교하고, 큰 값이면 오른쪽으로 스왑해서 넘기기를 반복");
	puts("       이렇게 1바퀴를 돌면 제일 큰 원소 하나가 정렬되며, 이 과정을 입력에 비례한만큼 반복하는 정렬입니다.\n");
	puts("시간 복잡도: 모든 원소에 대해 비교 연산해서 제일 큰 값이 오른쪽에 가는 1바퀴를 돌려면 입력 N에 비례한 시간");
	puts("              그런 과정 한번을 통해 하나가 정렬되므로 모두 정렬하려면 또 입력 수 N에 비례하는 시간");
	puts("              따라서 시간복잡도는 O(N^2) 입니다.\n\n");
	puts("코드 실행을 하시겠습니까? 하시려면 Y, 아니라면 ESC키 혹은 백스페이스를 눌러주세요.\n");

	char key = _getch(); // 키가 입력되면

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // x키나 X키를 누르면 종료
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESC키 누르면 초기화면
		system("cls"); // 화면 지우고
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		system("cls"); // 화면 지우고
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		system("cls"); // 화면 지우고
		bubbleSortPage();
		break;
	}

	int n = 0;
	printf("정렬할 수의 개수를 입력하세요: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n만큼 동적할당

	if (data == NULL) {
		printf("배열 메모리 할당 실패");
		return 1;
	}

	printf("정렬할 수를 입력하세요 (띄어쓰기로 구분): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("정렬 전 배열 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n\n");

	bubbleSort(data, n);

	printf("정렬 후 배열  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d ", data[i]);
	printf("\033[0m");
	printf("\n");

	free(data);

	puts("\n\n코드를 확인하시려면 Y를 입력해주세요");

	key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'Y': // Y키나 y키를 누르면 코드 출력
		bubbleSortCode();
		break;
	case 'y':
		bubbleSortCode();
		break;
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		bubbleSortPage();
		break;
	}
}
void insertionSort(int data[], int size) {
	int i, j, key;
	for (i = 1; i < size; i++) {
		Sleep(500);
		printf("\nStep %d \n", i);
		printf("현재 상태: ");
		for (int k = 0; k < size; k++) {
			if (k <= i - 1) // 정렬된 부분은
				printf("\033[34m%d ", data[k]); // 파란색으로 출력
			else // 정렬되지 않은 부분은
				printf("\033[0m%d ", data[k]); // 원래 색상으로 출력
		}
		printf("\n");
		printf("\033[0m"); // 원래 색상으로 출력

		if (i != size) {
			printf("다음으로 정렬된 부분에 삽입될 원소: \033[31m%d\033[0m\n", data[i]);
		}

		key = data[i];
		j = i - 1;
		while (j >= 0 && key < data[j]) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = key;

		printf("비교 연산하여 위치를 찾고, 삽입될 원소를 찾은 위치에 넣기\n");
		printf("삽입 후 상태: ");
		for (int k = 0; k < size; k++) {
			if (k <= i) // 정렬된 부분은
				printf("\033[34m%d ", data[k]); // 파란색으로 출력
			else // 정렬되지 않은 부분은
				printf("\033[0m%d ", data[k]); // 원래 색상으로 출력
		}
		printf("\033[0m"); // 색상을 원래대로 복원
		printf("\n\n");
	}
}
void insertionSortCode() {
	puts("삽입 정렬 코드\n\n");
	puts("#include <stdio.h>");
	puts("#include <stdlib.h>");
	puts("");
	puts("void insertionSort(int data[], int size) {");
	puts("\tint i, j, key;");
	puts("\tfor (i = 1; i < size; i++) {");
	puts("\t\tkey = data[i];");
	puts("\t\tfor (j = i - 1; j >= 0 && key < data[j]; j--)");
	puts("\t\t\tdata[j + 1] = data[j];");
	puts("\t\tdata[j + 1] = key;");
	puts("\t}");
	puts("}");
	puts("");
	puts("int main(void) {");
	puts("\tint n = 0;");
	puts("\tprintf(\"정렬할 수의 개수를 입력하세요: \");");
	puts("\tscanf_s(\"%d\", &n);");
	puts("");
	puts("\tint* data = malloc(n * sizeof(int));");
	puts("");
	puts("\tif (data == NULL) {");
	puts("\t\tprintf(\"배열 메모리 할당 실패\");");
	puts("\t\treturn 1;");
	puts("\t}");
	puts("");
	puts("\tprintf(\"정렬할 수를 입력하세요 (띄어쓰기로 구분): \");");
	puts("\tfor (int i = 0; i < n; i++) {");
	puts("\t\tscanf_s(\"%d\", &data[i]);");
	puts("\t}");
	puts("");
	puts("\tprintf(\"정렬 전의 배열 출력 : \");");
	puts("\tfor (int i = 0; i < n; i++)");
	puts("\t\tprintf(\"%d \", data[i]);");
	puts("\tprintf(\"\");");
	puts("");
	puts("\tinsertionSort(data, n);");
	puts("");
	puts("\tprintf(\"정렬 후의 배열 출력 : \");");
	puts("\tfor (int i = 0; i < n; i++)");
	puts("\t\tprintf(\"%d \", data[i]);");
	puts("\tprintf(\"\");");
	puts("");
	puts("\tfree(data);");
	puts("\treturn 0;");
	puts("}");


	puts("\n\n ESC키 or 백스페이스 or X를 입력하세요");
	char key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키가 들어올 때는 다시 이 화면
		insertionSortCode();
		break;
	}
}
void insertionSortPage() {
	puts("*----------------------------------------------------삽입 정렬----------------------------------------------------*\n\n");
	puts("설명:  두 번째부터 시작하여 이미 정렬된 데이터들을 보고, 삽입할 위치를 파악하고 데이터를 넣는 과정을 반복하는 알고리즘");
	puts("       예를 들어 두 번째 원소가 삽입되면, 다음은 세 번째 데이터가 이미 정렬된 곳을 하나하나 비교 연산을 통해 삽입 위치를 파악하고 들어간다.\n");
	puts("시간 복잡도: 삽입될 원소가 이미 정렬된 곳을 비교 연산하려면 입력 N에 비례한 시간");
	puts("              그런 과정 한번을 통해 하나가 삽입되어 정렬되므로 모두 정렬하려면 또 입력 수 N에 비례하는 시간");
	puts("              따라서 시간복잡도는 O(N^2) 입니다.\n\n");
	puts("코드 실행을 하시겠습니까? 하시려면 Y, 아니라면 ESC키 혹은 백스페이스를 눌러주세요.\n");

	char key = _getch(); // 키가 입력되면

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // x키나 X키를 누르면 종료
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESC키 누르면 초기화면
		system("cls"); // 화면 지우고
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		system("cls"); // 화면 지우고
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		system("cls"); // 화면 지우고
		insertionSortPage();
		break;
	}

	int n = 0;
	printf("정렬할 수의 개수를 입력하세요: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n만큼 동적할당

	if (data == NULL) {
		printf("배열 메모리 할당 실패");
		return 1;
	}

	printf("정렬할 수를 입력하세요 (띄어쓰기로 구분): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("정렬 전 배열 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n\n");

	insertionSort(data, n);

	printf("정렬 후 배열  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d ", data[i]);
	printf("\033[0m");
	printf("\n");

	free(data);

	puts("\n\n코드를 확인하시려면 Y를 입력해주세요");

	key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'Y': // Y키나 y키를 누르면 코드 출력
		insertionSortCode();
		break;
	case 'y':
		insertionSortCode();
		break;
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		insertionSortPage();
		break;
	}
}
void printArray(int data[], int first, int last) {
	for (int i = first; i <= last; i++) {
		printf("%d ", data[i]);
	}
}
void printArray2(int data[], int size) {
	for (int i = 0; i < size; ++i)
		printf("%d ", data[i]);
	puts("");
}
void printArrayWithColor(int data[], int size) { // 마지막 원소 파랑색 출력
	for (int i = 0; i < size - 1; ++i)
		printf("%d ", data[i]);
	printf("\033[34m%d\033[0m ", data[size - 1]);
	puts("");
}
void merge(int data[], int first, int mid, int last) {
	int left = first, right = mid + 1, t_index = first;
	int* temp = malloc((last + 1) * sizeof(int));

	printf("\n배열 합병(정렬되도록 합병): ");
	printf("\033[31m");
	printArray(data, first, mid); // 왼쪽 배열 출력
	printf("\033[0m");
	printf("AND ");
	printf("\033[31m");
	printArray(data, mid + 1, last); // 오른쪽 배열 출력
	printf("\033[0m");

	while (left <= mid && right <= last) {
		if (data[left] <= data[right]) // 각 배열의 가장 작은 값끼리 비교
			temp[t_index++] = data[left++]; // 왼쪽 배열의 값이 더 작으면 그 값 집어넣기
		else
			temp[t_index++] = data[right++]; // 오른쪽 배열의 값이 더 작으면 그 값 집어넣기
	}

	if (left > mid) { // 왼쪽 배열이 먼저 끝났으면 나머지 오른쪽 배열의 값 그대로 붙여넣기
		for (int i = right; i <= last; i++)
			temp[t_index++] = data[i];
	}
	else { // 오른쪽 배열이 먼저 끝났으면 나머지 왼쪽 배열의 값 그대로 붙여넣기
		for (int i = left; i <= mid; i++)
			temp[t_index++] = data[i];
	}

	for (int i = first; i <= last; i++) // 정렬 끝난 temp배열의 값을 data배열에 다 덮어쓰기
		data[i] = temp[i];

	printf("\n합병 후 상태: ");
	printArray(data, first, last);
	printf("\n");
	Sleep(500);
}
void mergeSort(int data[], int first, int last) {
	if (first < last) { // first가 last보다 작을 때만 실행되므로 같아지는 순간 이 조건문은 실행X

		int mid = (first + last) / 2; // 배열의 길이를 절반으로 나눈 인덱스를 mid에 저장

		printf("\n배열 분할: ");
		printArray(data, first, mid); // 왼쪽 분할 배열 출력
		printf("AND ");
		printArray(data, mid + 1, last); // 오른쪽 분할 배열 출력
		printf("으로 분리됨");

		mergeSort(data, first, mid); // 앞 부분을 계속 재귀호출하면서 반으로 인덱스 자르기
		mergeSort(data, mid + 1, last); // 뒷 부분을 계속 재귀호출하면서 반으로 인덱스 자르기
		merge(data, first, mid, last); // 두 배열 합치기
	}
}
void mergeSortCode() {
	puts("합병 정렬 코드\n\n");
	puts("#include <stdio.h>");
	puts("#include <stdlib.h>");
	puts("");
	puts("void merge(int data[], int first, int mid, int last) {");
	puts("\tint left = first, right = mid + 1, t_index = first;");
	puts("\tint* temp = malloc((last + 1) * sizeof(int));");
	puts("");
	puts("\twhile (left <= mid && right <= last) {");
	puts("\t\tif (data[left] <= data[right])");
	puts("\t\t\ttemp[t_index++] = data[left++];");
	puts("\t\telse");
	puts("\t\t\ttemp[t_index++] = data[right++];");
	puts("\t}");
	puts("");
	puts("\tif (left > mid) {");
	puts("\t\tfor (int i = right; i <= last; i++)");
	puts("\t\t\ttemp[t_index++] = data[i];");
	puts("\t}");
	puts("\telse {");
	puts("\t\tfor (int i = left; i <= mid; i++)");
	puts("\t\t\ttemp[t_index++] = data[i];");
	puts("\t}");
	puts("");
	puts("\tfor (int i = first; i <= last; i++)");
	puts("\t\tdata[i] = temp[i];");
	puts("}");
	puts("");
	puts("void mergeSort(int data[], int first, int last) {");
	puts("\tint mid;");
	puts("\tif (first < last) {");
	puts("\t\tmid = (first + last) / 2;");
	puts("");
	puts("\t\tmergeSort(data, first, mid);");
	puts("\t\tmergeSort(data, mid + 1, last);");
	puts("\t\tmerge(data, first, mid, last);");
	puts("\t}");
	puts("}");
	puts("");
	puts("int main(void) {");
	puts("\tint n = 0;");
	puts("\tprintf(\"정렬할 수의 개수를 입력하세요: \");");
	puts("\tscanf_s(\"%d\", &n);");
	puts("");
	puts("\tint* data = malloc(n * sizeof(int));");
	puts("");
	puts("\tif (data == NULL) {");
	puts("\t\tprintf(\"배열 메모리 할당 실패\");");
	puts("\t\treturn 1;");
	puts("\t}");
	puts("");
	puts("\tprintf(\"정렬할 수를 입력하세요 (띄어쓰기로 구분): \");");
	puts("\tfor (int i = 0; i < n; i++) {");
	puts("\t\tscanf_s(\"%d\", &data[i]);");
	puts("\t}");
	puts("");
	puts("\tprintf(\"정렬 전의 배열 출력 : \");");
	puts("\tfor (int i = 0; i < n; i++)");
	puts("\t\tprintf(\"%d \", data[i]);");
	puts("\tprintf(\"\");");
	puts("");
	puts("\tmergeSort(data, 0, n - 1);");
	puts("");
	puts("\tprintf(\"정렬 후의 배열 출력 : \");");
	puts("\tfor (int i = 0; i < n; i++)");
	puts("\t\tprintf(\"%d \", data[i]);");
	puts("\tprintf(\"\");");
	puts("");
	puts("\tfree(data);");
	puts("\treturn 0;");
	puts("}");

	puts("\n\n ESC키 or 백스페이스 or X를 입력하세요");
	char key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키가 들어올 때는 다시 이 화면
		mergeSortCode();
		break;
	}
}
void mergeSortPage() {
	puts("*----------------------------------------------------합병 정렬----------------------------------------------------*\n\n");
	puts("설명:  주어진 데이터를 가장 작은 단위까지 계속 나눈 후, 비교 연산하여 정렬하고 합치는 과정을 반복하는 알고리즘");
	puts("       분할 과정은 데이터가 하나가 될 때까지 진행되며, 분할된 데이터들을 순서에 맞게 재배치하여 합병하는 과정을 반복\n\n");
	puts("시간 복잡도: 합병 정렬은 데이터를 계속 반으로 나누기 때문에, logN 단계를 거치고, 각 단계에서 원소를 비교하며 합병할 때 입력 N에 비례한 시간");
	puts("             따라서 시간 복잡도는 O(NlogN)입니다.\n\n");
	puts("코드 실행을 하시겠습니까? 하시려면 Y, 아니라면 ESC키 혹은 백스페이스를 눌러주세요.\n\n");

	char key = _getch(); // 키가 입력되면

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // x키나 X키를 누르면 종료
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESC키 누르면 초기화면
		system("cls"); // 화면 지우고
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		system("cls"); // 화면 지우고
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		system("cls"); // 화면 지우고
		mergeSortPage();
		break;
	}

	int n = 0;
	printf("정렬할 수의 개수를 입력하세요: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n만큼 동적할당

	if (data == NULL) {
		printf("배열 메모리 할당 실패");
		return 1;
	}

	printf("정렬할 수를 입력하세요 (띄어쓰기로 구분): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("정렬 전 배열 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n\n");

	mergeSort(data, 0, n - 1);

	printf("\n\n정렬 후 배열  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d ", data[i]);
	printf("\033[0m");
	printf("\n");

	free(data);

	puts("\n\n코드를 확인하시려면 Y를 입력해주세요");

	key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'Y': // Y키나 y키를 누르면 코드 출력
		mergeSortCode();
		break;
	case 'y':
		mergeSortCode();
		break;
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		mergeSortPage();
		break;
	}
}
void quickSort(int data[], int L, int R) {
	Sleep(500);
	printf("\n현재 상태 (분할하여 반복): ");
	for (int i = L; i <= R; i++) {
		printf("%d ", data[i]);
	}

	int left = L, right = R;
	int pivot = data[(L + R) / 2];    // pivot 설정 (가운데) 
	int temp;

	printf("\n피벗 값 설정(가운데): \033[31m%d\033[0m", pivot);

	while (left <= right) {
		while (data[left] < pivot)    // left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
			left++;
		while (data[right] > pivot)    // right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
			right--;
		if (left <= right) {   // left가 right보다 왼쪽에 있다면 교환 
			temp = data[left];
			data[left] = data[right];
			data[right] = temp;

			left++;
			right--;
		}
	}

	printf("\n피벗 기준 정렬 후 상태: ");
	for (int i = L; i <= R; i++) {
		if (data[i] == pivot) {
			printf("\033[31m%d\033[0m ", data[i]);  // 피벗 값이면 빨간색으로 출력
		}
		else {
			printf("%d ", data[i]);
		}
	}
	printf("\033[0m\n");

	if (L < right)
		quickSort(data, L, right);    // 왼쪽 배열 재귀적으로 반복 

	if (left < R)
		quickSort(data, left, R);    // 오른쪽 배열 재귀적으로 반복 
}
void quickSortCode() {
	puts("퀵 정렬 코드\n\n");
	puts("#include <stdio.h>");
	puts("#include <stdlib.h>\n");
	puts("void quickSort(int data[], int L, int R) {");
	puts("    int left = L, right = R;");
	puts("    int pivot = data[(L + R) / 2];");
	puts("    int temp;");
	puts("");
	puts("    while (left < right) {");
	puts("        while (data[left] < pivot)");
	puts("            left++;");
	puts("        while (data[right] > pivot)");
	puts("            right--;");
	puts("        if (left <= right) {");
	puts("            temp = data[left];");
	puts("            data[left] = data[right];");
	puts("            data[right] = temp;");
	puts("");
	puts("            left++;");
	puts("            right--;");
	puts("        }");
	puts("    }");
	puts("");
	puts("    if (L < right)");
	puts("        quickSort(data, L, right);");
	puts("");
	puts("    if (left < R)");
	puts("        quickSort(data, left, R);");
	puts("}");
	puts("");
	puts("int main(void) {");
	puts("	int n = 0;");
	puts("	printf(\"정렬할 수의 개수를 입력하세요: \");");
	puts("	scanf_s(\"%d\", &n);");
	puts("");
	puts("	int* data = malloc(n * sizeof(int));");
	puts("");
	puts("	if (data == NULL) {");
	puts("		printf(\"배열 메모리 할당 실패\");");
	puts("		return 1;");
	puts("	}");
	puts("");
	puts("	printf(\"정렬할 수를 입력하세요 (띄어쓰기로 구분): \");");
	puts("	for (int i = 0; i < n; i++) {");
	puts("		scanf_s(\"%d\", &data[i]);");
	puts("	}");
	puts("");
	puts("	printf(\"정렬 전의 배열 출력 : \");");
	puts("	for (int i = 0; i < n; i++)");
	puts("		printf(\"%d \", data[i]);");
	puts("	printf(\"\\n\");");
	puts("");
	puts("	quickSort(data, 0, n - 1);");
	puts("");
	puts("	printf(\"정렬 후의 배열 출력 : \");");
	puts("	for (int i = 0; i < n; i++)");
	puts("		printf(\"%d \", data[i]);");
	puts("	printf(\"\\n\");");
	puts("");
	puts("	free(data);");
	puts("	return 0;");
	puts("}");

	puts("\n\n ESC키 or 백스페이스 or X를 입력하세요");
	char key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키가 들어올 때는 다시 이 화면
		quickSortCode();
		break;
	}
}
void quickSortPage() {
	puts("*----------------------------------------------------퀵 정렬----------------------------------------------------*\n\n");
	puts("설명:  주어진 데이터 중 하나를 피벗으로 선택 후, 피벗보다 작은 값은 왼쪽, 큰 값은 오른쪽으로 분할한 후 정렬하는 알고리즘");
	puts("       이 과정을 재귀적으로 반복하여 전체 데이터를 정렬합니다.\n\n");
	puts("시간 복잡도: 최선의 경우, 데이터가 반으로 나눠져 시간 복잡도는 O(NlogN)입니다. 피봇 기준으로 비교 연산하며 옮길 때");
	puts("             입력 N에 비례한 시간.  그리고 반으로 잘 나눠진다면 logN이 비례한 시간이 걸리기 때문입니다.");
	puts("             하지만 최악의 경우에는 데이터가 잘 나누어지지 않을 경우에, 모든 데이터를 비교해야 해서 시간 복잡도는 O(N^2)\n\n");
	puts("코드 실행을 하시겠습니까? 하시려면 Y, 아니라면 ESC키 혹은 백스페이스를 눌러주세요.\n\n");

	char key = _getch(); // 키가 입력되면

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // x키나 X키를 누르면 종료
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESC키 누르면 초기화면
		system("cls"); // 화면 지우고
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		system("cls"); // 화면 지우고
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		system("cls"); // 화면 지우고
		quickSortPage();
		break;
	}

	int n = 0;
	printf("정렬할 수의 개수를 입력하세요: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n만큼 동적할당

	if (data == NULL) {
		printf("배열 메모리 할당 실패");
		return 1;
	}

	printf("정렬할 수를 입력하세요 (띄어쓰기로 구분): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("정렬 전 배열 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n\n");

	quickSort(data, 0, n - 1);

	printf("\n\n\n정렬 후 배열  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d\033[0m ", data[i]);
	printf("\n");

	free(data);

	puts("\n\n코드를 확인하시려면 Y를 입력해주세요");

	key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'Y': // Y키나 y키를 누르면 코드 출력
		quickSortCode();
		break;
	case 'y':
		quickSortCode();
		break;
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		quickSortPage();
		break;
	}
}
void exHeapSort() {
	puts("예시로 배열 [10, 2, 8, 6, 3, 5, 7] 을 힙 정렬로 오름차순 정렬하는 것을 보여드리겠습니다.");
	Sleep(600);
	puts("1. 배열의 순서대로 트리에 집어넣습니다.(이진트리가 형성되도록 넣기)\n");
	puts("         10");
	puts("       /    \\");
	puts("      2      8");
	puts("     / \\    / \\");
	puts("    6   3  5   7\n");
	Sleep(600);
	puts("2. 가장 하위 레벨의 부모 노드 '8'부터 maxHeapify를 시작합니다.");
	puts("maxHeapify가 호출되면 부모노드와 그 자식 노드끼리의 비교 연산을 통해 최댓값을 부모노드로 올립니다(스왑)");
	puts("여기서는 부모 노드 '8'이 어떤 자식 노드보다도 크기에 변경없이 다음으로 진행합니다.\n");
	puts("         10");
	puts("       /    \\");
	puts("      2      8");
	puts("     / \\    / \\");
	puts("    6   3  5   7\n");
	Sleep(600);
	puts("3. 인덱스로 따질 때 그보다 이전인 부모노드 '2'에 대해 maxHeapify를 수행합니다. '2'와 그의 자식 노드 중 가장 큰 값 '6'의 위치를 바꿉니다.\n");
	puts("         10");
	puts("       /    \\");
	puts("      6      8");
	puts("     / \\    / \\");
	puts("    2   3  5   7\n");
	Sleep(600);
	puts("4. 이제 루트 노드 '10'에 대해 maxHeapify를 수행합니다. '10'은 이미 가장 큰 값이므로 변경 없이 진행합니다.\n");
	puts("         10");
	puts("       /    \\");
	puts("      6      8");
	puts("     / \\    /  \\");
	puts("    2   3  5    7\n");
	Sleep(600);
	puts("5. 이제 최대 힙이 만들어졌습니다. 이제 힙 정렬 과정을 시작합니다. ");
	puts("maxHeap구조에서는 루트 노드가 가장 큰 값입니다. 이걸 이용하여 루트 노드를 하나씩 제거하여 정렬이 완료되겠습니다.");
	puts("루트 노드는 가장 끝인 리프 노드와 교환하고, 배열 구조에서 제외시킵니다. 그리고 남은 트리 구조에서 또 최대힙을 구성\n");
	puts("         7");
	puts("       /    \\");
	puts("      6      5");
	puts("     / \\    /  ");
	puts("    2   3  8   \n");
	Sleep(600);
	puts("---------최댓값을 제외한 트리에서 다시 최대힙 구성---------\n");
	puts("         8");
	puts("       /    \\");
	puts("      6      7");
	puts("     / \\    /");
	puts("    2   3  5\n");
	Sleep(600);
	puts("6. 이 과정을 반복하여 최종적으로 오름차순으로 정렬된 배열을 얻습니다.\n");
	puts("정렬 후 배열 : \033[34m2 3 5 6 7 8 10\033[0m\n\n");
}
void maxHeapify(int data[], int size, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && data[left] > data[largest])
		largest = left;

	if (right < size && data[right] > data[largest])
		largest = right;

	if (largest != i) {
		int temp = data[i];
		data[i] = data[largest];
		data[largest] = temp;

		maxHeapify(data, size, largest);
	}
}
void heapSort(int data[], int size) {
	for (int i = size / 2 - 1; i >= 0; i--) {
		maxHeapify(data, size, i);
	}
	printf("최대 힙으로 구성: (maxHeapify):");
	printArray2(data, size);
	puts("");

	for (int i = size - 1; i > 0; i--) {
		int temp = data[0];
		data[0] = data[i];
		data[i] = temp;

		printf("루트 노드와 리프 노드 스왑: ");
		printArrayWithColor(data, i + 1);

		maxHeapify(data, i, 0);

		printf("나머지는 다시 heapify(이때 스왑된 기존 루트 노드는 제외): ");
		printArray2(data, i);
		puts("");
		Sleep(500);
	}
}
void heapSortCode() {
	puts("힙 정렬 코드\n\n");
	puts("#include <stdio.h>");
	puts("#include <stdlib.h>");
	puts("");
	puts("void swap(int* a, int* b) {");
	puts("	int temp = *a;");
	puts("	*a = *b;");
	puts("	*b = temp;");
	puts("}");
	puts("");
	puts("void maxHeapify(int data[], int size, int i) {");
	puts("	int parent = i;");
	puts("	int left = 2 * i + 1;");
	puts("	int right = 2 * i + 2;");
	puts("");
	puts("	if (left < size && data[left] > data[parent])");
	puts("		parent = left;");
	puts("");
	puts("	if (right < size && data[right] > data[parent])");
	puts("		parent = right;");
	puts("");
	puts("	if (parent != i) {");
	puts("		swap(&data[i], &data[parent]);");
	puts("		maxHeapify(data, size, parent);");
	puts("	}");
	puts("}");
	puts("");
	puts("void heapSort(int data[], int size) {");
	puts("	for (int i = (size - 1) / 2; i >= 0; i--)");
	puts("		maxHeapify(data, size, i);");
	puts("");
	puts("	for (int i = size - 1; i > 0; i--) {");
	puts("		swap(&data[0], &data[i]);");
	puts("		maxHeapify(data, i, 0);");
	puts("	}");
	puts("}");
	puts("");
	puts("");
	puts("int main(void) {");
	puts("	int n = 0;");
	puts("	printf(\"정렬할 수의 개수를 입력하세요: \");");
	puts("	scanf_s(\"%d\", &n);");
	puts("");
	puts("	int* data = malloc(n * sizeof(int));");
	puts("");
	puts("	if (data == NULL) {");
	puts("		printf(\"배열 메모리 할당 실패\");");
	puts("		return 1;");
	puts("	}");
	puts("");
	puts("	printf(\"정렬할 수를 입력하세요 (띄어쓰기로 구분): \");");
	puts("	for (int i = 0; i < n; i++) {");
	puts("		scanf_s(\"%d\", &data[i]);");
	puts("	}");
	puts("");
	puts("	printf(\"정렬 전의 배열 출력 : \");");
	puts("	for (int i = 0; i < n; i++)");
	puts("		printf(\"%d \", data[i]);");
	puts("	printf(\"\\n\");");
	puts("");
	puts("	heapSort(data, n);");
	puts("");
	puts("	printf(\"정렬 후의 배열 출력 : \");");
	puts("	for (int i = 0; i < n; i++)");
	puts("		printf(\"%d \", data[i]);");
	puts("	printf(\"\\n\");");
	puts("");
	puts("	free(data);");
	puts("	return 0;");
	puts("}");

	puts("\n\n ESC키 or 백스페이스 or X를 입력하세요");
	char key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키가 들어올 때는 다시 이 화면
		heapSortCode();
		break;
	}
}
void heapSortPage() {
	puts("*----------------------------------------------------힙 정렬----------------------------------------------------*\n\n");
	puts("설명:  주어진 데이터를 힙(Heap)이라는 자료구조를 이용하여 정렬하는 알고리즘입니다.");
	puts("           데이터를 힙에 삽입한 후, 가장 큰 값을 루트에 위치시켜 정렬(오름차순)을 진행합니다.\n\n");
	puts("시간 복잡도: 힙 정렬의 시간 복잡도는 항상 O(NlogN)입니다. 최대 힙으로 만드는 과정에서 logN의 시간이 걸리며,");
	puts("             이를 N번 반복하기 때문에 O(NlogN)의 시간 복잡도를 가집니다.\n\n");
	puts("코드 실행 전, 먼저 예시를 보여드리겠습니다.\n");
	exHeapSort();
	puts("\n");
	puts("코드 실행을 하시겠습니까? 하시려면 Y, 아니라면 ESC키 혹은 백스페이스를 눌러주세요.\n\n");

	char key = _getch(); // 키가 입력되면

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // x키나 X키를 누르면 종료
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESC키 누르면 초기화면
		system("cls"); // 화면 지우고
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		system("cls"); // 화면 지우고
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		system("cls"); // 화면 지우고
		heapSortPage();
		break;
	}

	int n = 0;
	printf("정렬할 수의 개수를 입력하세요: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n만큼 동적할당

	if (data == NULL) {
		printf("배열 메모리 할당 실패");
		return 1;
	}

	printf("정렬할 수를 입력하세요 (띄어쓰기로 구분): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("정렬 전 배열 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n\n");

	heapSort(data, n);

	printf("\n정렬 후 배열  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d\033[0m ", data[i]);
	printf("\n");

	free(data);

	puts("\n\n코드를 확인하시려면 Y를 입력해주세요");

	key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'Y': // Y키나 y키를 누르면 코드 출력
		heapSortCode();
		break;
	case 'y':
		heapSortCode();
		break;
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		heapSortPage();
		break;
	}
}
void printSublist(int data[], int size, int start, int gap) {
	printf("서브리스트: ");
	for (int i = 0; i < size; ++i) {
		if (i % gap == start % gap)
			printf("%d ", data[i]);
		else
			printf("   ");
	}
	puts("");
}
void shellSort(int data[], int n) {
	int gap, i, j, temp;

	for (gap = n / 2; gap > 0; gap /= 2) {
		Sleep(500);
		printf("\n\n현재 간격: \033[31m%d\033[0m\n", gap);

		for (i = 0; i < gap; ++i) {
			printSublist(data, n, i, gap);
		}

		puts("\n각각의 리스트들을 삽입 정렬합니다.\n");

		for (i = gap; i < n; i++) {
			temp = data[i];
			for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
				data[j] = data[j - gap];
			}
			data[j] = temp;
		}

		puts("각각을 삽입 정렬한 서브리스트");
		for (i = 0; i < gap; ++i) {
			printSublist(data, n, i, gap);
		}

		printf("서브리스트를 합친 결과: ");
		for (i = 0; i < n; ++i)
			printf("%d ", data[i]);
		puts("");
	}
}
void shellSortCode() {
	puts("셸 정렬 코드\n\n");
	puts("#include <stdio.h>");
	puts("#include <stdlib.h>");
	puts("");
	puts("void shellSort(int data[], int n) {");
	puts("	int gap, i, j, temp;");
	puts("");
	puts("	for (gap = n / 2; gap > 0; gap /= 2) {");
	puts("		for (i = gap; i < n; i++) {");
	puts("			temp = data[i];");
	puts("			for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {");
	puts("				data[j] = data[j - gap];");
	puts("			}");
	puts("			data[j] = temp;");
	puts("		}");
	puts("	}");
	puts("}");
	puts("");
	puts("int main(void) {");
	puts("    int n = 0;");
	puts("    printf(\"정렬할 수의 개수 입력: \");");
	puts("    scanf_s(\"%d\", &n);");
	puts("");
	puts("    int* data = malloc(n * sizeof(int)); // n만큼 동적할당");
	puts("");
	puts("    if (data == NULL) {");
	puts("        printf(\"배열 메모리 할당 실패\");");
	puts("        return 1;");
	puts("    }");
	puts("");
	puts("    printf(\"정렬할 수를 입력: \");");
	puts("    for (int i = 0; i < n; i++) {");
	puts("        scanf_s(\"%d\", &data[i]);");
	puts("    }");
	puts("");
	puts("    printf(\"정렬 전 배열 : \");");
	puts("    for (int i = 0; i < n; i++)");
	puts("        printf(\"%d \", data[i]);");
	puts("    printf(\"\\n\");");
	puts("");
	puts("    shellSort(data, n);");
	puts("");
	puts("    printf(\"정렬 후 배열 : \");");
	puts("    for (int i = 0; i < n; i++)");
	puts("        printf(\"%d \", data[i]);");
	puts("    printf(\"\\n\");");
	puts("");
	puts("    free(data); // 메모리 해제");
	puts("    return 0;");
	puts("}");

	puts("\n\n ESC키 or 백스페이스 or X를 입력하세요");
	char key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키가 들어올 때는 다시 이 화면
		shellSortCode();
		break;
	}
}
void shellSortPage() {
	puts("*----------------------------------------------------셸 정렬----------------------------------------------------*\n\n");
	puts("설명:  셸 정렬은 삽입 정렬을 개선한 것으로, 전체의 배열을 일정한 간격으로 쪼갠 다음 각각을 삽입정렬하는 알고리즘");
	puts("       이때 나뉘어진 배열들은 삽입 정렬에서 들어갈 위치를 찾을 때 간격만큼 이동합니다(시간 단축)");
	puts("       삽입 정렬된 각각의 서브리스트들은 다시 합칩니다. 이때, 인덱스에 맞도록 엇갈리게 합병합니다.");
	puts("       반복하며 간격을 절반씩 줄이며, 마지막에는 1이 됩니다. 이 때는 전체 목록을 삽입정렬하는 것과 같습니다\n\n");
	puts("시간 복잡도: 셸 정렬의 시간 복잡도는 간격에 따라 다르지만, 일반적으로 O(N^(3/2))입니다.");
	puts("             이는 삽입 정렬의 O(N^2)보다 효율적이며, 간격의 선택에 따라 더욱 개선될 수 있습니다.\n\n");
	puts("코드 실행을 하시겠습니까? 하시려면 Y, 아니라면 ESC키 혹은 백스페이스를 눌러주세요.\n\n");

	char key = _getch(); // 키가 입력되면

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // x키나 X키를 누르면 종료
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESC키 누르면 초기화면
		system("cls"); // 화면 지우고
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		system("cls"); // 화면 지우고
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		system("cls"); // 화면 지우고
		shellSortPage();
		break;
	}

	int n = 0;
	printf("정렬할 수의 개수를 입력하세요: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n만큼 동적할당

	if (data == NULL) {
		printf("배열 메모리 할당 실패");
		return 1;
	}

	printf("정렬할 수를 입력하세요 (띄어쓰기로 구분): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("정렬 전 배열 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n\n");

	shellSort(data, n);

	printf("\n정렬 후 배열  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d\033[0m ", data[i]);
	printf("\n");

	free(data);

	puts("\n\n코드를 확인하시려면 Y를 입력해주세요");

	key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'Y': // Y키나 y키를 누르면 코드 출력
		shellSortCode();
		break;
	case 'y':
		shellSortCode();
		break;
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		shellSortPage();
		break;
	}
}
void countingSort(int data[], int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (data[i] > max)
			max = data[i];
	}

	int* count = malloc((max + 1) * sizeof(int));
	memset(count, 0, (max + 1) * sizeof(int));
	int* result = malloc(n * sizeof(int));
	memset(result, 0, n * sizeof(int));
	int* sorted = malloc(n * sizeof(int));
	memset(sorted, 0, n * sizeof(int));

	printf("\n입력된 배열: ");
	printArray2(data, n);

	for (int i = 0; i < n; i++) {
		count[data[i]]++;
	}

	printf("\n카운트 배열 생성(0부터 %d까지 각 수의 등장 수): ", max);
	printArray2(count, max + 1);

	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	printf("카운트 배열의 각 요소를 누적합으로 갱신(처음부터 더해가며 갱신): ");
	printArray2(count, max + 1);

	for (int i = n - 1; i >= 0; i--) {
		Sleep(500);
		printf("\n정렬할 숫자: \033[31m%d\033[0m\n", data[i]);
		printf("누적합된 카운트 배열에서 정렬할 숫자 \033[31m%d\033[0m을 인덱스로 하여 접근: \033[34m%d \033[0m\n", data[i], count[data[i]] - 1);
		printf("즉, 입력받은 배열에는 \033[31m%d\033[0m보다 같거나 작은 값이 \033[34m%d \033[0m개 있다고 추정 가능\n", data[i], count[data[i]] - 1);
		count[data[i]]--;
		result[count[data[i]]] = data[i];
		sorted[count[data[i]]] = 1;
		printf("정렬할 숫자 \033[31m%d\033[0m -> 정렬될 배열의 인덱스 \033[34m%d \033[0m위치에 넣습니다(%d이하인 값이 %d개 있기 때문)\n", data[i], count[data[i]], data[i], count[data[i]] + 1);
		for (int j = 0; j < n; j++) {
			if (sorted[j]) {
				printf("\033[34m%d \033[0m", result[j]);
			}
			else {
				printf("%d ", result[j]);
			}
		}
		printf("\n\n");
	}

	free(sorted);
	free(count);
	free(result);
}
void countingSortCode() {
	puts("계수 정렬 코드\n\n");
	puts("#include <stdio.h>");
	puts("#include <stdlib.h>");
	puts("#include <string.h>");
	puts("");
	puts("void countingSort(int data[], int n) {");
	puts("    int max = 0;");
	puts("    for (int i = 0; i < n; i++) {");
	puts("        if (data[i] > max)");
	puts("            max = data[i];");
	puts("    }");
	puts("");
	puts("    int* count = malloc((max + 1) * sizeof(int));");
	puts("    int* result = malloc(n * sizeof(int));");
	puts("");
	puts("    memset(count, 0, (max + 1) * sizeof(int));");
	puts("");
	puts("    for (int i = 0; i < n; i++) {");
	puts("        count[data[i]]++;");
	puts("    }");
	puts("");
	puts("    for (int i = 1; i <= max; i++) {");
	puts("        count[i] += count[i - 1];");
	puts("    }");
	puts("");
	puts("    for (int i = n - 1; i >= 0; i--) {");
	puts("        result[count[data[i]] - 1] = data[i];");
	puts("        count[data[i]]--;");
	puts("    }");
	puts("");
	puts("    for (int i = 0; i < n; i++) {");
	puts("        data[i] = result[i];");
	puts("    }");
	puts("");
	puts("    free(count);");
	puts("    free(result);");
	puts("}");
	puts("");
	puts("int main(void) {");
	puts("    int n = 0;");
	puts("    printf(\"정렬할 수의 개수 입력: \");");
	puts("    scanf_s(\"%d\", &n);");
	puts("");
	puts("    int* data = malloc(n * sizeof(int));");
	puts("");
	puts("    if (data == NULL) {");
	puts("        printf(\"배열 메모리 할당 실패\");");
	puts("        return 1;");
	puts("    }");
	puts("");
	puts("    printf(\"정렬할 수를 입력: \");");
	puts("    for (int i = 0; i < n; i++) {");
	puts("        scanf_s(\"%d\", &data[i]);");
	puts("    }");
	puts("");
	puts("    printf(\"정렬 전 배열 : \");");
	puts("    for (int i = 0; i < n; i++)");
	puts("        printf(\"%d \", data[i]);");
	puts("    printf(\"\\n\");");
	puts("");
	puts("    countingSort(data, n);");
	puts("");
	puts("    printf(\"정렬 후 배열 : \");");
	puts("    for (int i = 0; i < n; i++)");
	puts("        printf(\"%d \", data[i]);");
	puts("    printf(\"\\n\");");
	puts("");
	puts("    free(data);");
	puts("    return 0;");
	puts("}");

	puts("\n\n ESC키 or 백스페이스 or X를 입력하세요");
	char key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키가 들어올 때는 다시 이 화면
		countingSortCode();
		break;
	}
}
void countingSortPage() {
	puts("*--------------------------------------------------계수 정렬--------------------------------------------------*\n\n");
	puts("설명:  계수 정렬은 각 숫자가 몇 번 등장하는지 세는 방식으로 정렬하는 알고리즘입니다.");
	puts("       먼저 입력 값 중 최대 값을 찾아 그 크기만큼의 배열을 만듭니다.(숫자의 등장 횟수를 기록할 배열) ");
	puts("       그 후 입력 배열을 순회하며 각 숫자가 등장하는 횟수를 세어 저장합니다.");
	puts("       그리고 그 횟수가 저장된 카운트 배열을 각 요소의 값을 더해 다음 칸으로, 또 이전을 다 더해서 다음 칸으로");
	puts("       이렇게 계속 더하고 기록을 반복하여 누적합으로 배열을 만듭니다.");
	puts("       따라서 입력받은 배열의 뒷쪽부터 누적합된 카운트 배열을 참고하여 새로운 배열에 정렬을 진행합니다.\n\n");
	puts("시간 복잡도: 계수 정렬의 시간 복잡도는 O(N+K)입니다. 여기서 N은 원소의 개수, K는 입력 값 중 최댓값입니다.");
	puts("             이는 계수 정렬이 각 숫자의 등장 횟수를 세서 바로 정렬하기 때문에 가능한 것입니다.");
	puts("             이때, 입력수와 최댓값이 복잡도에 영향을 미치기 때문에, 입력수와 최댓값이 작은 배열을 정렬하는 데에 적합\n\n");
	puts("코드 실행을 하시겠습니까? 하시려면 Y, 아니라면 ESC키 혹은 백스페이스를 눌러주세요.\n\n");

	char key = _getch(); // 키가 입력되면

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // x키나 X키를 누르면 종료
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESC키 누르면 초기화면
		system("cls"); // 화면 지우고
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		system("cls"); // 화면 지우고
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		system("cls"); // 화면 지우고
		countingSortPage();
		break;
	}

	int n = 0;
	printf("정렬할 수의 개수를 입력하세요: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n만큼 동적할당

	if (data == NULL) {
		printf("배열 메모리 할당 실패");
		return 1;
	}

	printf("정렬할 수를 입력하세요 (띄어쓰기로 구분): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("정렬 전 배열 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n\n");

	countingSort(data, n);

	printf("\n정렬 후 배열  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d\033[0m ", data[i]);
	printf("\n");

	free(data);

	puts("\n\n코드를 확인하시려면 Y를 입력해주세요");

	key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'Y': // Y키나 y키를 누르면 코드 출력
		countingSortCode();
		break;
	case 'y':
		countingSortCode();
		break;
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		countingSortPage();
		break;
	}
}
void radixSort(int data[], int n) {
	int i, m = 0, exp = 1;
	int* b = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		if (data[i] > m)
			m = data[i];
	}
	while (m / exp > 0) {
		Sleep(500);
		printf("\n\033[31m%d\033[0m의 자리 숫자 정렬\n\n", exp);
		int bucket[10] = { 0 };
		int* bucketValues[10];
		for (i = 0; i < 10; i++)
			bucketValues[i] = (int*)malloc(n * sizeof(int));
		int bucketCount[10] = { 0 };
		for (i = 0; i < n; i++) {
			int index = data[i] / exp % 10;
			bucket[index]++;
			bucketValues[index][bucketCount[index]++] = data[i];
		}
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--) {
			b[--bucket[data[i] / exp % 10]] = data[i];
		}
		for (int j = 0; j < 10; j++) {
			printf("%d: ", j);
			for (int k = 0; k < bucketCount[j]; k++) {
				printf("%d ", bucketValues[j][k]);
			}
			printf("\n");
		}
		for (i = 0; i < 10; i++)
			free(bucketValues[i]);
		for (i = 0; i < n; i++)
			data[i] = b[i];
		exp *= 10;
	}
	free(b);
}
void radixSortCode() {
	puts("계수 정렬 코드\n\n");
	puts("#include <stdio.h>");
	puts("#include <stdlib.h>");
	puts("");
	puts("void radixSort(int data[], int n) {");
	puts("\tint i, m = 0, exp = 1;");
	puts("\tint* b = (int*)malloc(n * sizeof(int));");
	puts("\tfor (i = 0; i < n; i++) {");
	puts("\t\tif (data[i] > m)");
	puts("\t\t\tm = data[i];");
	puts("\t}");
	puts("\twhile (m / exp > 0) {");
	puts("\t\tint bucket[10] = { 0 };");
	puts("\t\tfor (i = 0; i < n; i++)");
	puts("\t\t\tbucket[data[i] / exp % 10]++;");
	puts("\t\tfor (i = 1; i < 10; i++)");
	puts("\t\t\tbucket[i] += bucket[i - 1];");
	puts("\t\tfor (i = n - 1; i >= 0; i--)");
	puts("\t\t\tb[--bucket[data[i] / exp % 10]] = data[i];");
	puts("\t\tfor (i = 0; i < n; i++)");
	puts("\t\t\tdata[i] = b[i];");
	puts("\t\texp *= 10;");
	puts("\t}");
	puts("\tfree(b);");
	puts("}");
	puts("");
	puts("int main(void) {");
	puts("\tint n = 0;");
	puts("\tprintf(\"정렬할 수의 개수 입력: \");");
	puts("\tscanf_s(\"%d\", &n);");
	puts("");
	puts("\tint* data = malloc(n * sizeof(int));");
	puts("");
	puts("\tif (data == NULL) {");
	puts("\t\tprintf(\"배열 메모리 할당 실패\");");
	puts("\t\treturn 1;");
	puts("\t}");
	puts("");
	puts("\tprintf(\"정렬할 수를 입력: \");");
	puts("\tfor (int i = 0; i < n; i++) {");
	puts("\t\tscanf_s(\"%d\", &data[i]);");
	puts("\t}");
	puts("");
	puts("\tprintf(\"정렬 전 배열 : \");");
	puts("\tfor (int i = 0; i < n; i++)");
	puts("\t\tprintf(\"%d \", data[i]);");
	puts("\tprintf(\"\\n\");");
	puts("");
	puts("\tradixSort(data, n);");
	puts("");
	puts("\tprintf(\"정렬 후 배열 : \");");
	puts("\tfor (int i = 0; i < n; i++)");
	puts("\t\tprintf(\"%d \", data[i]);");
	puts("\tprintf(\"\\n\");");
	puts("");
	puts("\tfree(data);");
	puts("\treturn 0;");
	puts("}");

	puts("\n\n ESC키 or 백스페이스 or X를 입력하세요");
	char key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키가 들어올 때는 다시 이 화면
		radixSortCode();
		break;
	}
}
void radixSortPage() {
	puts("*--------------------------------------------------기수 정렬--------------------------------------------------*\n\n");
	puts("설명:  기수 정렬은 주어진 데이터들을 같은 자리수끼리 비교하는 과정을 반복하여 정렬하는 알고리즘입니다.");
	puts("       가장 낮은 자릿수부터 비교해 정렬하며, 이 과정을 가장 높은 자릿수까지 진행합니다.");
	puts("       이렇게 각 자릿수끼리 전부 정렬하면, 마지막엔 각각의 자리가 모두 순서대로 정렬되므로 결국 전체가 정렬\n\n");
	puts("시간 복잡도: 시간 복잡도는 O(d*(n+b))입니다. 여기서 n은 원소의 개수, b는 바이트(기수), d는 최대 자릿수");
	puts("             이는 기수 정렬이 각 자릿수를 독립적으로 정렬하기 때문에 가능한 것입니다.");
	puts("             이때, 입력의 최대 자릿수와 입력 값의 개수가 복잡도에 영향을 미치기 때문에,");
	puts("             자릿수가 비교적 적은 것들을 정렬하는데 빠른 속도를 보여줍니다.\n\n");
	puts("코드 실행을 하시겠습니까? 하시려면 Y, 아니라면 ESC키 혹은 백스페이스를 눌러주세요.\n\n");

	char key = _getch(); // 키가 입력되면

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // x키나 X키를 누르면 종료
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESC키 누르면 초기화면
		system("cls"); // 화면 지우고
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		system("cls"); // 화면 지우고
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		system("cls"); // 화면 지우고
		radixSortPage();
		break;
	}

	int n = 0;
	printf("정렬할 수의 개수를 입력하세요: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n만큼 동적할당

	if (data == NULL) {
		printf("배열 메모리 할당 실패");
		return 1;
	}

	printf("정렬할 수를 입력하세요 (띄어쓰기로 구분): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("정렬 전 배열 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n\n");

	radixSort(data, n);

	printf("\n정렬 후 배열  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d\033[0m ", data[i]);
	printf("\n");

	free(data);

	puts("\n\n코드를 확인하시려면 Y를 입력해주세요");

	key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'Y': // Y키나 y키를 누르면 코드 출력
		radixSortCode();
		break;
	case 'y':
		radixSortCode();
		break;
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		radixSortPage();
		break;
	}
}

void selectionSortBasic(int data[], int size) {
	int max, temp = 0;

	for (int i = 0; i < size - 1; i++) {
		max = 0;
		for (int j = 1; j < size - i; j++) {
			if (data[max] < data[j]) {
				max = j;
			}
		}
		temp = data[(size - 1) - i];
		data[(size - 1) - i] = data[max];
		data[max] = temp;
	}
}
void bubbleSortBasic(int data[], int size) {
	int temp = 0; // 스왑을 위한 임시 변수
	for (int i = 0; i < size - 1; i++) { // 총 n - 1번의 반복만 하면 이미 정렬은 완료된 상태
		for (int j = 0; j < (size - 1) - i; j++) { // 한 바퀴 돌때마다 뒤에 큰 수가 하나씩 쌓이기에 (n - 1) - i번씩만 비교
			if (data[j] > data[j + 1]) { // 만약 둘을 비교했을 때, 이전의 값이 더 크면 스왑
				temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
			}
		}
	}
}
void insertionSortBasic(int data[], int size) {
	int i, j, key;
	for (i = 1; i < size; i++) {
		key = data[i]; // key에는 이제 삽입할 원소를 복사해놓음

		for (j = i - 1; j >= 0 && key < data[j]; j--) // 이미 정렬되어있는 배열의 뒷쪽에서부터 비교 시작
			data[j + 1] = data[j]; // 만약 key값이 더 작으면 배열 한칸씩 뒤로 밀어서 자리 만들기

		data[j + 1] = key; // 만들어진 자리에 key값 삽입
	}
}
void mergeBasic(int data[], int first, int mid, int last) { // 두 배열 합치는 함수
	int left = first, right = mid + 1, t_index = first;
	int* temp = malloc((last + 1) * sizeof(int));

	while (left <= mid && right <= last) {
		if (data[left] <= data[right]) // 각 배열의 가장 작은 값끼리 비교
			temp[t_index++] = data[left++]; // 왼쪽 배열의 값이 더 작으면 그 값 집어넣기
		else
			temp[t_index++] = data[right++]; // 오른쪽 배열의 값이 더 작으면 그 값 집어넣기
	}

	if (left > mid) { // 왼쪽 배열이 먼저 끝났으면 나머지 오른쪽 배열의 값 그대로 붙여넣기
		for (int i = right; i <= last; i++)
			temp[t_index++] = data[i];
	}
	else { // 오른쪽 배열이 먼저 끝났으면 나머지 왼쪽 배열의 값 그대로 붙여넣기
		for (int i = left; i <= mid; i++)
			temp[t_index++] = data[i];
	}

	for (int i = first; i <= last; i++) // 정렬 끝난 temp배열의 값을 data배열에 다 덮어쓰기
		data[i] = temp[i];
}
void mergeSortBasic(int data[], int first, int last) {
	int mid;
	if (first < last) { // first가 last보다 작을 때만 실행되므로 같아지는 순간 이 조건문은 실행X
		mid = (first + last) / 2; // 배열의 길이를 절반으로 나눈 인덱스를 mid에 저장

		mergeSortBasic(data, first, mid); // 앞 부분을 계속 재귀호출하면서 반으로 인덱스 자르기
		mergeSortBasic(data, mid + 1, last); // 뒷 부분을 계속 재귀호출하면서 반으로 인덱스 자르기
		mergeBasic(data, first, mid, last); // 두 배열 합치기
	}
}
void quickSortBasic(int data[], int L, int R) {
	int left = L, right = R;
	int pivot = data[(L + R) / 2];    // pivot 설정 (가운데) 
	int temp;

	while (left < right) {
		while (data[left] < pivot)    // left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
			left++;
		while (data[right] > pivot)    // right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
			right--;
		if (left <= right) {   // left가 right보다 왼쪽에 있다면 교환 
			temp = data[left];
			data[left] = data[right];
			data[right] = temp;

			left++;
			right--;
		}
	}

	if (L < right)
		quickSortBasic(data, L, right);    // 왼쪽 배열 재귀적으로 반복 

	if (left < R)
		quickSortBasic(data, left, R);    // 오른쪽 배열 재귀적으로 반복 
}
void heapSortBasic(int data[], int size) {
	for (int i = (size - 1) / 2; i >= 0; i--) // 최대힙 만들기
		maxHeapify(data, size, i);

	for (int i = size - 1; i > 0; i--) { // 만들어진 힙에서 한 번에 하나씩 요소를 추출하여 정렬 수행 
		swap(&data[0], &data[i]);     // 현재 최대값인 루트와 마지막 요소를 교환 
		maxHeapify(data, i, 0);      // 남은 요소들에 대해 최대 힙 구성 수행 
	}
}
void shellSortBasic(int data[], int n) {
	int gap, i, j, temp;

	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i++) {
			temp = data[i];
			for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
				data[j] = data[j - gap];
			}
			data[j] = temp;
		}
	}
}
void countingSortBasic(int data[], int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (data[i] > max)
			max = data[i];
	}

	int* count = malloc((max + 1) * sizeof(int));
	int* result = malloc(n * sizeof(int));

	memset(count, 0, (max + 1) * sizeof(int));

	for (int i = 0; i < n; i++) {
		count[data[i]]++;
	}

	for (int i = 1; i <= 10; i++) {
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; i--) {
		result[count[data[i]] - 1] = data[i];
		count[data[i]]--;
	}

	for (int i = 0; i < n; i++) {
		data[i] = result[i];
	}

	free(count);
	free(result);
}
void radixSortBasic(int data[], int n) {
	int i, m = 0, exp = 1;
	int* b = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		if (data[i] > m)
			m = data[i];
	}
	while (m / exp > 0) {
		int bucket[10] = { 0 };
		for (i = 0; i < n; i++)
			bucket[data[i] / exp % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--bucket[data[i] / exp % 10]] = data[i];
		for (i = 0; i < n; i++)
			data[i] = b[i];
		exp *= 10;
	}
	free(b);
}
void speedCheck(void) {
	clock_t start, end;
	double cpu_time_used;
	int n = 0;
	printf("정렬할 수의 개수를 입력하세요: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int));
	int* copy = malloc(n * sizeof(int));

	if (data == NULL) {
		printf("배열 메모리 할당 실패");
		return 1;
	}

	printf("데이터를 랜덤으로 생성하시겠습니까? 그렇다면 Y, 아니라면 아무키나 입력하세요");

	char key = _getch(); // 키가 입력되면

	if (key == 'y' || key == 'Y') {

		srand(time(NULL));  // 난수 생성기 초기화
		for (int i = 0; i < n; i++) {
			data[i] = rand() % 20001;  // 0 ~ 20000 사이의 랜덤 숫자
		}
	}
	else {
		printf("\n\n정렬할 수를 입력하세요 (띄어쓰기로 구분): ");
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &data[i]);
		}
	}

	printf("\n\n정렬 전 배열 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);

	printf("\n\n정렬 후 배열: ");
	memcpy(copy, data, n * sizeof(int));
	quickSortBasic(copy, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", copy[i]);
	printf("\n\n\n");

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	selectionSortBasic(copy, n);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("선택 정렬: %f초\n", cpu_time_used);

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	bubbleSortBasic(copy, n);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("버블 정렬: %f초\n", cpu_time_used);

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	insertionSortBasic(copy, n);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("삽입 정렬: %f초\n", cpu_time_used);

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	mergeSortBasic(copy, 0, n - 1);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("합병 정렬: %f초\n", cpu_time_used);

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	quickSortBasic(copy, 0, n - 1);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("퀵 정렬: %f초\n", cpu_time_used);

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	heapSortBasic(copy, n);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("힙 정렬: %f초\n", cpu_time_used);

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	shellSortBasic(copy, n);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("셸 정렬: %f초\n", cpu_time_used);

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	countingSortBasic(copy, n);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("계수 정렬: %f초\n", cpu_time_used);

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	radixSortBasic(copy, n);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("기수 정렬: %f초\n", cpu_time_used);

	free(data);
	free(copy);

	puts("\n\n ESC키 or 백스페이스 or X를 입력하세요");

	key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		sortMenu();
		break;
	default:
		sortMenu();
		break;
	}
}

void exBFS() {
	puts("BFS 알고리즘을 이용한 그래프 탐색을 시작합니다. 시작 정점은 10입니다.\n");
	Sleep(600);

	puts("1. 시작 정점 '10'을 방문하고, 방문 리스트에 추가합니다.\n");
	puts("방문 리스트: [10]\n");
	puts("그래프 상태:\n");
	puts(" 5\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - 2 - 8 - 3\n");
	puts("   \\     |   |\n");
	puts("     9   7 - 6\n");
	Sleep(600);

	puts("2. 정점 '10'과 연결된 정점 '2', '5', '9'를 방문하고, 방문 리스트에 추가합니다.");
	puts("방문 리스트: [10, 2, 5, 9]\n");
	puts("그래프 상태:\n");
	puts(" \033[34m5\033[0m\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - 8 - 3\n");
	puts("   \\     |   |\n");
	puts("     \033[34m9\033[0m   7 - 6\n");
	Sleep(600);

	puts("3. 다음으로 방문할 정점 '2'와 연결된 정점 '8'를 방문하고, 방문 리스트에 추가합니다.");
	puts("방문 리스트: [10, 2, 5, 9, 8]\n");
	puts("그래프 상태:\n");
	puts(" \033[34m5\033[0m\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - \033[34m8\033[0m - 3\n");
	puts("   \\     |   |\n");
	puts("    \033[34m9\033[0m    7 - 6\n");
	Sleep(600);

	puts("4. 다음으로 방문할 정점 '5'와 '9'는 방문한 정점과 연결된 다른 정점이 없으므로, 방문 리스트에 추가되는 정점이 없습니다.\n");
	Sleep(600);

	puts("5. 다음으로 방문할 정점 '8'와 연결된 정점 '3', '7'를 방문하고, 방문 리스트에 추가합니다.");
	puts("방문 리스트: [10, 2, 5, 9, 8, 3, 7]\n");
	puts("그래프 상태:\n");
	puts(" \033[34m5\033[0m\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - \033[34m8\033[0m - \033[34m3\033[0m\n");
	puts("   \\     |   |\n");
	puts("    \033[34m9\033[0m    \033[34m7\033[0m - 6\n");
	Sleep(600);

	puts("6. 마지막으로, 방문할 정점 '3'과 연결된 정점 '6'을 방문하고, 방문 리스트에 추가합니다.");
	puts("방문 리스트: [10, 2, 5, 9, 8, 3, 7, 6]\n");
	puts("그래프 상태:\n");
	puts(" \033[34m5\033[0m\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - \033[34m8\033[0m - \033[34m3\033[0m\n");
	puts("   \\     |   |\n");
	puts("    \033[34m9\033[0m    \033[34m7\033[0m - \033[34m6\033[0m\n");
	Sleep(600);

	puts("BFS 탐색이 완료되었습니다. 최종 방문 리스트는 [\033[34m10, 2, 5, 9, 8, 3, 7, 6\033[0m] 입니다.\n\n");
}
void enqueue(int vertex) {
	queue[++rear] = vertex;
}
int dequeue() {
	return queue[++front];
}
bool isQueueEmpty() {
	return (front == rear);
}
void BFS(int V, int start) {
	visited[start] = true;
	enqueue(start);

	printf("\n1. 시작 정점 '%d'을 방문하고, 방문 리스트에 추가합니다.\n방문 리스트 : \033[34m%d\033[0m\n\n", start, start);

	int step = 2;
	while (!isQueueEmpty()) {
		int current = dequeue();
		for (int i = 1; i <= V; i++) {
			if (graph[current][i] && !visited[i]) {
				visited[i] = true;
				enqueue(i);
				Sleep(500);
				printf("%d. 다음으로 방문할 정점 '%d'과 연결된 정점 '%d'를 방문하고, 방문 리스트에 추가합니다\n방문 리스트 : ", step++, current, i);
				for (int j = 0; j <= rear; j++) {
					printf("\033[34m%d\033[0m ", queue[j]);
				}
				printf("\n\n");
			}
		}
	}
	printf("\n최종 방문 리스트: ");
	for (int j = 0; j <= rear; j++) {
		printf("\033[34m%d\033[0m ", queue[j]);
	}
}
void BFSCode() {
	puts("BFS 코드\n\n");
	puts("#include <stdio.h>");
	puts("#include <stdbool.h>\n");
	puts("int queue[11];");
	puts("int front = -1;");
	puts("int rear = -1;");
	puts("int graph[11][11];");
	puts("bool visited[11];\n");
	puts("void enqueue(int vertex) {");
	puts("\tqueue[++rear] = vertex;");
	puts("}\n");
	puts("int dequeue() {");
	puts("\treturn queue[++front];");
	puts("}\n");
	puts("bool isQueueEmpty() {");
	puts("\treturn (front == rear);");
	puts("}\n");
	puts("void BFS(int V, int start) {");
	puts("\tvisited[start] = true;");
	puts("\tenqueue(start);\n");
	puts("\tprintf(\"\\n1. 시작 정점 '%d'을 방문하고, 방문 리스트에 추가합니다.\\n방문 리스트 : \\033[34m%d\\033[0m\\n\\n\", start, start);\n");
	puts("\tint step = 2;");
	puts("\twhile (!isQueueEmpty()) {");
	puts("\t\tint current = dequeue();");
	puts("\t\tfor (int i = 1; i <= V; i++) {");
	puts("\t\t\tif (graph[current][i] && !visited[i]) {");
	puts("\t\t\t\tvisited[i] = true;");
	puts("\t\t\t\tenqueue(i);");
	puts("\t\t\t\tprintf(\"%d. 다음으로 방문할 정점 '%d'과 연결된 정점 '%d'를 방문하고, 방문 리스트에 추가합니다\\n방문 리스트 : \", step++, current, i);");
	puts("\t\t\t\tfor (int j = 0; j <= rear; j++) {");
	puts("\t\t\t\t\tprintf(\"\\033[34m%d\\033[0m \", queue[j]);");
	puts("\t\t\t\t}");
	puts("\t\t\t\tprintf(\"\\n\n\");");
	puts("\t\t\t}");
	puts("\t\t}");
	puts("\t}");
	puts("\tprintf(\"\\n최종 방문 리스트: \");");
	puts("\tfor (int j = 0; j <= rear; j++) {");
	puts("\t\tprintf(\"\\033[34m%d\\033[0m \", queue[j]);");
	puts("\t}");
	puts("}\n");
	puts("int main() {");
	puts("\tint start;\n");
	puts("\tgraph[10][2] = graph[2][10] = graph[10][5] = graph[5][10] = graph[9][10] = graph[10][9] = 1;");
	puts("\tgraph[2][8] = graph[8][2] = 1;");
	puts("\tgraph[8][3] = graph[3][8] = graph[8][7] = graph[7][8] = 1;");
	puts("\tgraph[3][6] = graph[6][3] = 1;");
	puts("\tgraph[6][7] = graph[7][6] = 1;\n");
	puts("\twhile (1) {");
	puts("\t\tprintf(\"시작 정점을 입력하세요 (2, 3, 5, 6, 8, 9, 10 중 선택): \");");
	puts("\t\tscanf_s(\"%d\", &start);");
	puts("\t\tif (start == 2 || start == 3 || start == 5 || start == 6 || start == 8 || start == 9 || start == 10) {");
	puts("\t\t\tbreak;");
	puts("\t\t}");
	puts("\t\telse {");
	puts("\t\t\tprintf(\"잘못된 정점이 입력되었습니다. 다시 입력해주세요\\n\");");
	puts("\t\t}");
	puts("\t}\n");
	puts("\tBFS(10, start);\n");
	puts("\treturn 0;");
	puts("}");

	puts("\n\n ESC키 or 백스페이스 or X를 입력하세요");
	char key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		graphMenu();
		break;
	default: // 다른 키가 들어올 때는 다시 이 화면
		BFSCode();
		break;
	}
}
void BFSPage() {
	puts("*--------------------------------------------------너비 우선 탐색(BFS)--------------------------------------------------*\n\n");
	puts("설명:  너비 우선 탐색(BFS)은 시작 정점에서 가장 가까운 정점들부터 탐색하는 방법입니다.");
	puts("       정점에서 바로 탐색할 수 있는 정점들을 모두 탐색한 후, 즉 너비를 우선하여 그래프의 모든 정점들을 방문합니다.");
	puts("       가까이 있는 정점들을 탐색하고 그 다음에 깊이를 높혀 더 멀리 있는 정점에 방문하는 탐색 방법입니다.\n\n");
	puts("시간 복잡도: BFS의 시간 복잡도는 O(V+E)입니다. 여기서 V는 그래프의 정점의 수, E는 그래프의 간선의 수를 의미합니다.");
	puts("             이는 BFS가 그래프의 모든 정점을 정확히 한 번씩 방문하고, 모든 간선을 검사하기 때문입니다.\n\n");
	puts("\n코드 실행 전 예시를 먼저 보여드리겠습니다.");
	exBFS();
	puts("\n");
	puts("코드 실행을 하시겠습니까? 하시려면 Y, 아니라면 ESC키 혹은 백스페이스를 눌러주세요.(같은 그래프)\n\n");

	char key = _getch(); // 키가 입력되면

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // x키나 X키를 누르면 종료
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESC키 누르면 초기화면
		system("cls"); // 화면 지우고
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		system("cls"); // 화면 지우고
		graphMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		system("cls"); // 화면 지우고
		BFSPage();
		break;
	}

	int start;

	// 그래프 초기화(간선)
	graph[10][2] = graph[2][10] = graph[10][5] = graph[5][10] = graph[9][10] = graph[10][9] = 1;
	graph[2][8] = graph[8][2] = 1;
	graph[8][3] = graph[3][8] = graph[8][7] = graph[7][8] = 1;
	graph[3][6] = graph[6][3] = 1;
	graph[6][7] = graph[7][6] = 1;

	while (1) {
		printf("시작 정점을 입력하세요 (2, 3, 5, 6, 8, 9, 10 중 선택): ");
		scanf_s("%d", &start);
		char c = 'a';
		scanf_s("%*c", c);
		if (start == 2 || start == 3 || start == 5 || start == 6 || start == 8 || start == 9 || start == 10) {
			break;
		}
		else {
			printf("잘못된 정점이 입력되었습니다. 다시 입력해주세요\n");
		}
	}

	BFS(10, start);
	// 전역변수들 원래 상태로
	memset(queue, 0, sizeof(queue));
	memset(graph, 0, sizeof(graph));
	memset(visited, 0, sizeof(visited));
	front = -1;
	rear = -1;

	puts("\n\n코드를 확인하시려면 Y를 입력해주세요");

	key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'Y': // Y키나 y키를 누르면 코드 출력
		BFSCode();
		break;
	case 'y':
		BFSCode();
		break;
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		graphMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		BFSPage();
		break;
	}
}
void exDFS() {
	puts("DFS 알고리즘을 이용한 그래프 탐색을 시작합니다. 시작 정점은 10입니다.\n");
	Sleep(600);

	puts("1. 시작 정점 '10'을 방문하고, 방문 리스트에 추가합니다.");
	puts("방문 리스트: [10]\n");
	puts("그래프 상태:\n");
	puts(" 5\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - 2 - 8 - 3");
	puts("   \\     |   |\n");
	puts("     9   7 - 6\n");
	Sleep(600);

	puts("2. 정점 '10'과 연결된 정점 '2', '5', '9' 중 '2'를 방문하고, 방문 리스트에 추가합니다.");
	puts("방문 리스트: [10, 2]\n");
	puts("그래프 상태:\n");
	puts(" 5\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - 8 - 3\n");
	puts("   \\     |   |\n");
	puts("     9   7 - 6\n");
	Sleep(600);

	puts("3. 다음으로 방문할 정점 '2'와 연결된 정점 '8'를 방문하고, 방문 리스트에 추가합니다.");
	puts("방문 리스트: [10, 2, 8]\n");
	puts("그래프 상태:\n");
	puts(" 5\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - \033[34m8\033[0m - 3\n");
	puts("   \\     |   |\n");
	puts("    9    7 - 6\n");
	Sleep(600);

	puts("4. 다음으로 방문할 정점 '8'와 연결된 정점 '3', '7' 중 '3'를 방문하고, 방문 리스트에 추가합니다.");
	puts("방문 리스트: [10, 2, 8, 3]\n");
	puts("그래프 상태:\n");
	puts(" 5\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - \033[34m8\033[0m - \033[34m3\033[0m\n");
	puts("   \\     |   |\n");
	puts("    9    7 - 6\n");
	Sleep(600);

	puts("5. 마지막으로, 방문할 정점 '3'과 연결된 정점 '6'을 방문하고, 방문 리스트에 추가합니다.");
	puts("방문 리스트: [10, 2, 8, 3, 6]\n");
	puts("그래프 상태:\n");
	puts(" 5\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - \033[34m8\033[0m - \033[34m3\033[0m\n");
	puts("   \\     |   |\n");
	puts("    9    7 - \033[34m6\033[0m\n");
	Sleep(600);

	puts("6. 다음으로 방문할 정점 '6'과 연결된 정점이 없으므로, 이전 정점으로 돌아가 '7'을 방문하고, 방문 리스트에 추가합니다.");
	puts("방문 리스트: [10, 2, 8, 3, 6, 7]\n");
	puts("그래프 상태\n");
	puts(" 5\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - \033[34m8\033[0m - \033[34m3\033[0m\n");
	puts("   \\     |   |\n");
	puts("    9    \033[34m7\033[0m - \033[34m6\033[0m\n");
	Sleep(600);

	puts("7. 마지막으로, 이전에 방문하지 않아 남아 있던 정점 '5', '9'를 순차적으로 방문하고, 방문 리스트에 추가합니다.");
	puts("방문 리스트: [10, 2, 8, 3, 6, 7, 5, 9]\n");
	puts("그래프 상태:\n");
	puts(" \033[34m5\033[0m\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - \033[34m8\033[0m - \033[34m3\033[0m\n");
	puts("   \\     |   |\n");
	puts("    \033[34m9\033[0m    \033[34m7\033[0m - \033[34m6\033[0m\n");
	Sleep(600);

	puts("DFS 탐색이 완료되었습니다. 최종 방문 리스트는 [\033[34m10, 2, 8, 3, 6, 7, 5, 9\033[0m] 입니다.\n");
}
void push(int vertex) {
	stack[++top] = vertex;
}
int pop() {
	return stack[top--];
}
bool isStackEmpty() {
	return (top == -1);
}
void DFS(int V, int start) {
	visited[start] = true;
	push(start);
	visitedList[visitedCount++] = start;

	printf("\n1. 시작 정점 '%d'을 방문하고, 방문 리스트에 추가합니다.\n방문 리스트 : \033[34m%d\033[0m\n\n", start, start);

	int step = 2;
	while (!isStackEmpty()) {
		int current = stack[top];
		bool isPushed = false;
		for (int i = 1; i <= V; i++) {
			if (graph[current][i] && !visited[i]) {
				visited[i] = true;
				push(i);
				visitedList[visitedCount++] = i;
				Sleep(600);
				printf("%d. 다음으로 방문할 정점 '%d'과 연결된 정점 '%d'를 방문하고, 방문 리스트에 추가합니다\n방문 리스트 : ", step++, current, i);
				for (int j = 0; j < visitedCount; j++) {
					printf("\033[34m%d\033[0m ", visitedList[j]);
				}
				printf("\n\n");

				isPushed = true;
				break;
			}
		}
		if (!isPushed) {
			pop();
		}
	}
	printf("\n최종 방문 리스트 : ");
	for (int j = 0; j < visitedCount; j++) {
		printf("\033[34m%d\033[0m ", visitedList[j]);
	}
}
void DFSCode() {
	puts("DFS 코드\n\n");
	puts("#include <stdio.h>;");
	puts("#include <stdbool.h>;");
	puts("#include <string.h>;");
	puts("");
	puts("int stack[11];");
	puts("int top = -1;");
	puts("int graph[11][11];");
	puts("bool visited[11];");
	puts("int visitedList[11];");
	puts("int visitedCount = 0;");
	puts("");
	puts("void push(int vertex) {");
	puts("\tstack[++top] = vertex;");
	puts("};");
	puts("");
	puts("int pop() {");
	puts("\treturn stack[top--];");
	puts("};");
	puts("");
	puts("bool isStackEmpty() {");
	puts("\treturn (top == -1);");
	puts("};");
	puts("");
	puts("void DFS(int V, int start) {");
	puts("\tvisited[start] = true;");
	puts("\tpush(start);");
	puts("\tvisitedList[visitedCount++] = start;");
	puts("");
	puts("\tprintf(\"\\n1. 시작 정점 '%d'을 방문하고, 방문 리스트에 추가합니다.\\n방문 리스트 : \\033[34m%d\\033[0m\\n\\n\", start, start);");
	puts("");
	puts("\tint step = 2;");
	puts("\twhile (!isStackEmpty()) {");
	puts("\t\tint current = stack[top];");
	puts("\t\tbool isPushed = false;");
	puts("\t\tfor (int i = 1; i <= V; i++) {");
	puts("\t\t\tif (graph[current][i] && !visited[i]) {");
	puts("\t\t\t\tvisited[i] = true;");
	puts("\t\t\t\tpush(i);");
	puts("\t\t\t\tvisitedList[visitedCount++] = i;");
	puts("\t\t\t\tprintf(\"%d. 다음으로 방문할 정점 '%d'과 연결된 정점 '%d'를 방문하고, 방문 리스트에 추가합니다\\n방문 리스트 : \", step++, current, i);");
	puts("\t\t\t\tfor (int j = 0; j < visitedCount; j++) {");
	puts("\t\t\t\t\tprintf(\"\\033[34m%d\\033[0m \", visitedList[j]);");
	puts("\t\t\t\t};");
	puts("\t\t\t\tprintf(\"\\n\\n\");");
	puts("\t\t\t\tisPushed = true;");
	puts("\t\t\t\tbreak;");
	puts("\t\t\t};");
	puts("\t\t};");
	puts("\t\tif (!isPushed) {");
	puts("\t\t\tpop();");
	puts("\t\t};");
	puts("\t};");
	puts("\tprintf(\"\\n최종 방문 리스트 : \");");
	puts("\tfor (int j = 0; j < visitedCount; j++) {");
	puts("\t\tprintf(\"\\033[34m%d\\033[0m \", visitedList[j]);");
	puts("\t};");
	puts("\tprintf(\"\\n\");");
	puts("};");
	puts("");
	puts("int main() {");
	puts("\tint start;");
	puts("");
	puts("\t// 그래프 초기화(간선)");
	puts("\tgraph[10][2] = graph[2][10] = graph[10][5] = graph[5][10] = graph[9][10] = graph[10][9] = 1;");
	puts("\tgraph[2][8] = graph[8][2] = 1;");
	puts("\tgraph[8][3] = graph[3][8] = graph[8][7] = graph[7][8] = 1;");
	puts("\tgraph[3][6] = graph[6][3] = 1;");
	puts("\tgraph[6][7] = graph[7][6] = 1;");
	puts("");
	puts("\twhile (1) {");
	puts("\t\tprintf(\"시작 정점을 입력하세요 (2, 3, 5, 6, 8, 9, 10 중 선택): \");");
	puts("\t\tscanf_s(\"%d\", &start);");
	puts("\t\tif (start == 2 || start == 3 || start == 5 || start == 6 || start == 8 || start == 9 || start == 10) {");
	puts("\t\t\tbreak;");
	puts("\t\t};");
	puts("\t\telse {");
	puts("\t\t\tprintf(\"잘못된 정점이 입력되었습니다. 다시 입력해주세요\\n\");");
	puts("\t\t};");
	puts("\t};");
	puts("");
	puts("\tDFS(10, start);");
	puts("");
	puts("\tmemset(graph, 0, sizeof(graph));");
	puts("\tmemset(visited, 0, sizeof(visited));");
	puts("\tmemset(stack, 0, sizeof(visited));");
	puts("\tmemset(visitedList, 0, sizeof(visitedList));");
	puts("\tvisitedCount = 0;");
	puts("\ttop = -1;");
	puts("");
	puts("\treturn;");
	puts("};");

	puts("\n\n ESC키 or 백스페이스 or X를 입력하세요");
	char key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		graphMenu();
		break;
	default: // 다른 키가 들어올 때는 다시 이 화면
		DFSCode();
		break;
	}
}
void DFSPage() {
	puts("*--------------------------------------------------깊이 우선 탐색(DFS)--------------------------------------------------*\n\n");
	puts("설명:  DFS는 시작 정점에서 더 이상 방문할 정점이 없을 때까지 깊이 들어가 방문하는 탐색 방법입니다.");
	puts("       먼저 방문한 정점에서 인접한 정점들 중 하나를 선택하여 또다시 방문을 진행하며, 더 이상 방문할 정점이 없을 때");
	puts("       이전 정점으로 돌아가 방문하지 않은 정점을 탐색하는 방법입니다. ");
	puts("       즉, BFS와 달리 깊이 들어가는 것을 더 우선합니다.\n\n");
	puts("시간 복잡도: DFS의 시간 복잡도는 BFS와 마찬가지로 O(V+E)입니다. 여기서 V는 정점의 수, E는 그래프의 간선의 수를 의미");
	puts("             이는 DFS가 그래프의 모든 정점을 정확히 한 번씩 방문하고, 모든 간선을 검사하기 때문입니다.\n\n");
	puts("\n코드 실행 전 예시를 먼저 보여드리겠습니다.");
	exDFS();
	puts("\n");
	puts("코드 실행을 하시겠습니까? 하시려면 Y, 아니라면 ESC키 혹은 백스페이스를 눌러주세요.(같은 그래프)\n\n");

	char key = _getch(); // 키가 입력되면

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // x키나 X키를 누르면 종료
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESC키 누르면 초기화면
		system("cls"); // 화면 지우고
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		system("cls"); // 화면 지우고
		graphMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		system("cls"); // 화면 지우고
		DFSPage();
		break;
	}

	int start;

	// 그래프 초기화(간선)
	graph[10][2] = graph[2][10] = graph[10][5] = graph[5][10] = graph[9][10] = graph[10][9] = 1;
	graph[2][8] = graph[8][2] = 1;
	graph[8][3] = graph[3][8] = graph[8][7] = graph[7][8] = 1;
	graph[3][6] = graph[6][3] = 1;
	graph[6][7] = graph[7][6] = 1;

	while (1) {
		printf("시작 정점을 입력하세요 (2, 3, 5, 6, 8, 9, 10 중 선택): ");
		scanf_s("%d", &start);
		char c = 'a';
		scanf_s("%*c", c);
		if (start == 2 || start == 3 || start == 5 || start == 6 || start == 8 || start == 9 || start == 10) {
			break;
		}
		else {
			printf("잘못된 정점이 입력되었습니다. 다시 입력해주세요\n");
		}
	}

	DFS(10, start);

	memset(graph, 0, sizeof(graph));
	memset(visited, 0, sizeof(visited));
	memset(stack, 0, sizeof(visited));
	memset(visitedList, 0, sizeof(visitedList));
	visitedCount = 0;
	top = -1;

	puts("\n\n코드를 확인하시려면 Y를 입력해주세요");

	key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'Y': // Y키나 y키를 누르면 코드 출력
		DFSCode();
		break;
	case 'y':
		DFSCode();
		break;
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		graphMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		DFSPage();
		break;
	}
}
int minKey(int key[], bool mstSet[]) {
	int min = INT_MAX, min_index;
	for (int v = 0; v < 5; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}
void printEdgesAndWeights(int graph[5][5]) {
	printf("\n간선과 가중치\n");
	int totalWeight = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (graph[i][j] != 0) {
				printf("(%d, %d)의 가중치: %d\n", i + 1, j + 1, graph[i][j]);
				totalWeight += graph[i][j];
			}
		}
	}
	printf("\n가중치 총합: %d\n", totalWeight);
}
void printMST(int parent[], int graph[5][5]) {
	printf("간선과 가중치:\n");
	int totalWeight = 0;
	for (int i = 1; i < 5; i++) {
		printf("(%d, %d)의 가중치: %d \n", parent[i] + 1, i + 1, graph[i][parent[i]]);
		totalWeight += graph[i][parent[i]];
	}
	printf("가중치 총합: %d\n", totalWeight);
}
void primMST(int graph[5][5]) {
	int parent[5];
	int key[5];
	bool mstSet[5];
	for (int i = 0; i < 5; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	parent[0] = -1;

	printf("\n정점 출력: ");
	for (int i = 1; i <= 5; i++) {
		printf("%d ", i);
	}
	printf("\n");
	printEdgesAndWeights(graph);
	puts("");

	int count = 1;
	for (int total_edges = 0; total_edges < 5 - 1; ) {
		int u = minKey(key, mstSet);
		mstSet[u] = true;

		for (int v = 0; v < 5; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
				parent[v] = u, key[v] = graph[u][v];
				printf("%d번째 단계: 정점 %d와 연결된 정점 중, 가장 낮은 가중치를 가진 정점 %d를 선택\n", count++, u + 1, v + 1);
				total_edges++;
			}
	}

	printf("\n최소 신장 트리의 생성이 완료되었습니다.\n\n");
	printf("\n정점 출력: ");
	for (int i = 1; i <= 5; i++) {
		printf("%d ", i);
	}
	printf("\n");
	printMST(parent, graph);
}
void primCode(void) {
	puts("프림 알고리즘 코드\n\n");
	puts("#include <stdio.h>");
	puts("#include <limits.h>");
	puts("#include <stdbool.h>");
	puts("");
	puts("int minKey(int key[], bool mstSet[]) {");
	puts("\tint min = INT_MAX, min_index;");
	puts("\tfor (int v = 0; v < 5; v++)");
	puts("\t\tif (mstSet[v] == false && key[v] < min)");
	puts("\t\t\tmin = key[v], min_index = v;");
	puts("\treturn min_index;");
	puts("}");
	puts("");
	puts("void printEdgesAndWeights(int graph[5][5]) {");
	puts("\tprintf(\"\\n간선과 가중치\\n\");");
	puts("\tint totalWeight = 0;");
	puts("\tfor (int i = 0; i < 5; i++) {");
	puts("\t\tfor (int j = i + 1; j < 5; j++) {");
	puts("\t\t\tif (graph[i][j] != 0) {");
	puts("\t\t\t\tprintf(\"(%d, %d)의 가중치: %d\\n\", i + 1, j + 1, graph[i][j]);");
	puts("\t\t\t\ttotalWeight += graph[i][j];");
	puts("\t\t\t}");
	puts("\t\t}");
	puts("\t}");
	puts("\tprintf(\"\\n가중치 총합: %d\\n\", totalWeight);");
	puts("}");
	puts("");
	puts("void printMST(int parent[], int graph[5][5]) {");
	puts("\tprintf(\"간선과 가중치:\\n\");");
	puts("\tint totalWeight = 0;");
	puts("\tfor (int i = 1; i < 5; i++) {");
	puts("\t\tprintf(\"(%d, %d)의 가중치: %d \\n\", parent[i] + 1, i + 1, graph[i][parent[i]]);");
	puts("\t\ttotalWeight += graph[i][parent[i]];");
	puts("\t}");
	puts("\tprintf(\"가중치 총합: %d\\n\", totalWeight);");
	puts("}");
	puts("");
	puts("void primMST(int graph[5][5]) {");
	puts("\tint parent[5];");
	puts("\tint key[5];");
	puts("\tbool mstSet[5];");
	puts("\tfor (int i = 0; i < 5; i++)");
	puts("\t\tkey[i] = INT_MAX, mstSet[i] = false;");
	puts("\tkey[0] = 0;");
	puts("\tparent[0] = -1;");
	puts("");
	puts("\tprintf(\"\\n정점 출력: \");");
	puts("\tfor (int i = 1; i <= 5; i++) {");
	puts("\t\tprintf(\"%d \", i);");
	puts("\t}");
	puts("\tprintf(\"\\n\");");
	puts("\tprintEdgesAndWeights(graph);");
	puts("\tputs(\"\");");
	puts("");
	puts("\tint count = 1;");
	puts("\tfor (int total_edges = 0; total_edges < 5 - 1; ) {");
	puts("\t\tint u = minKey(key, mstSet);");
	puts("\t\tmstSet[u] = true;");
	puts("");
	puts("\t\tfor (int v = 0; v < 5; v++)");
	puts("\t\t\tif (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {");
	puts("\t\t\t\tparent[v] = u, key[v] = graph[u][v];");
	puts("\t\t\t\tprintf(\"%d번째 단계: 정점 %d와 연결된 정점 중, 가장 낮은 가중치를 가진 정점 %d를 선택\\n\", count++, u + 1, v + 1);");
	puts("\t\t\t\ttotal_edges++;");
	puts("\t\t\t}");
	puts("\t}");
	puts("");
	puts("\tprintf(\"\\n최소 신장 트리의 생성이 완료되었습니다.\\n\");");
	puts("");
	puts("\tprintf(\"\\n정점 출력: \");");
	puts("\tfor (int i = 1; i <= 5; i++) {");
	puts("\t\tprintf(\"%d \", i);");
	puts("\t}");
	puts("\tprintf(\"\\n\");");
	puts("\tprintMST(parent, graph);");
	puts("}");
	puts("");
	puts("int main() {");
	puts("\tint graph[5][5] = { {0, 2, 0, 6, 0},");
	puts("\t\t\t   {2, 0, 3, 8, 5},");
	puts("\t\t\t   {0, 3, 0, 0, 7},");
	puts("\t\t\t   {6, 8, 0, 0, 9},");
	puts("\t\t\t   {0, 5, 7, 9, 0} };");
	puts("\tprimMST(graph);");
	puts("\treturn 0;");
	puts("}");

	puts("\n\n ESC키 or 백스페이스 or X를 입력하세요");
	char key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		graphMenu();
		break;
	default: // 다른 키가 들어올 때는 다시 이 화면
		primCode();
		break;
	}
}
void primPage() {
	puts("*--------------------------------------------------프림 알고리즘--------------------------------------------------*\n\n");
	puts("설명:  프림 알고리즘은 그래프에서 최소 신장 트리를 찾는 알고리즘이며, '탐욕적인 방법'을 이용합니다.");
	puts("       시작 정점을 선택한 후, 선택한 정점에 인접한 간선들 중 가중치가 가장 낮은 간선의 정점을 선택하는 방식으로");
	puts("       신장 트리를 확장해나가는 방법입니다. (당연히 트리를 만드는 것이기 때문에 사이클을 만드는 간선은 제외)");
	puts("       이 과정을 모든 정점이 선택되어 최소 신장 트리가 완성될 때까지 반복합니다.\n\n");
	puts("시간 복잡도: 프림 알고리즘의 시간 복잡도는 우선순위 큐를 이용할 경우 O(ElogE)입니다. 여기서 E는 그래프의 간선의 수를 의미합니다.");
	puts("             이는 그래프의 모든 간선에 대해 연산을 수행하고 우선순위 큐를 이용하여 간선을 선택하기 때문입니다.\n\n");
	puts("코드 실행을 하시겠습니까? 하시려면 Y, 아니라면 ESC키 혹은 백스페이스를 눌러주세요.\n\n");

	char key = _getch(); // 키가 입력되면

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // x키나 X키를 누르면 종료
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESC키 누르면 초기화면
		system("cls"); // 화면 지우고
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		system("cls"); // 화면 지우고
		graphMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		system("cls"); // 화면 지우고
		primPage();
		break;
	}

	int graph[5][5] = { {0, 2, 0, 6, 0},
					{2, 0, 3, 8, 5},
					{0, 3, 0, 0, 7},
					{6, 8, 0, 0, 9},
					{0, 5, 7, 9, 0} };
	primMST(graph);

	puts("\n\n코드를 확인하시려면 Y를 입력해주세요");

	key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'Y': // Y키나 y키를 누르면 코드 출력
		primCode();
		break;
	case 'y':
		primCode();
		break;
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		graphMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		primPage();
		break;
	}
}

void kruskalPage() {
	puts("*--------------------------------------------------크루스칼 알고리즘--------------------------------------------------*\n\n");
	puts("설명:  크루스칼 알고리즘은 그래프에서 최소 신장 트리를 찾는 알고리즘이며, '탐욕적인 방법'을 이용합니다.");
	puts("       간선의 가장 가중치가 작은 간선부터 선택하여 트리를 확장해나갑니다.");
	puts("       단, 사이클을 형성하는 간선은 제외합니다.");
	puts("       이 과정을 모든 정점이 선택되어 최소 신장 트리가 완성될 때까지 반복합니다.\n\n");
	puts("       프림 알고리즘과의 주요 차이점은, 프림 알고리즘은 시작 정점부터 연결된 곳으로 뻗어나간다는 느낌이면");
	puts("       크루스칼 알고리즘은 항상 모든 간선을 대상으로 선택을 고려한다는 것입니다.");
	puts("시간 복잡도: 간선을 오름차순으로 정렬하는 데 필요한 시간 O(ElogE)이며, 여기서 E는 그래프의 간선의 수를 의미합니다.\n\n");
	puts("코드 실행을 하시겠습니까? 하시려면 Y, 아니라면 ESC키 혹은 백스페이스를 눌러주세요.\n\n");

	char key = _getch(); // 키가 입력되면

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // x키나 X키를 누르면 종료
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESC키 누르면 초기화면
		system("cls"); // 화면 지우고
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		system("cls"); // 화면 지우고
		graphMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		system("cls"); // 화면 지우고
		kruskalPage();
		break;
	}


	puts("\n\n코드를 확인하시려면 Y를 입력해주세요");

	key = _getch(); // 키가 입력되면
	system("cls"); // 화면 지우고

	switch (key) {
	case 'Y': // Y키나 y키를 누르면 코드 출력
		primCode();
		break;
	case 'y':
		primCode();
		break;
	case 'x': // x키나 X키를 누르면 종료
		return;
	case 'X':
		return;
	case 27: // ESC키 누르면 초기화면
		startMenu();
		break;
	case 8: // 백스페이스 누르면 이전 화면
		graphMenu();
		break;
	default: // 다른 키를 누르면 다시 이 화면
		primPage();
		break;
	}
}