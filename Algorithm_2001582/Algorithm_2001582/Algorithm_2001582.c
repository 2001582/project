#include <stdio.h>
#include <conio.h> // _getch
#include <windows.h> // gotoxy, cursor, system
#include <stdlib.h> // malloc
#include <string.h> // memset	
#include <time.h> // �ð� ��� �Լ���(���� �˰��� �ӵ�üũ) 
#include <stdbool.h> // bool ����
#include <limits.h> // �ִ�, �ּ�, ��Ʈ �� ��

void gotoxy(int x, int y); // Ŀ�� �̵� �Լ�
void cursor(int n); // Ŀ�� ���߱� ���� �Լ�
void draw_boxArea(void); // ȭ�� ���� �Լ�
void startMenu(void); // �ʱ� ȭ�� �Լ�
void sortMenu(void); // ���� �˰��� �޴� �Լ�
void graphMenu(void); // �׷��� �˰��� �޴� �Լ�
void selectionSortPage(void); // ���� ���� ȭ�� ��� �Լ�
void bubbleSortPage(void); // ���� ���� ȭ�� ��� �Լ�
void insertionSortPage(void); // ���� ���� ȭ�� ��� �Լ�
void mergeSortPage(void); // �պ� ���� ȭ�� ��� �Լ�
void quickSortPage(void); // �� ���� ȭ�� ��� �Լ�
void heapSortPage(void); // �� ���� ȭ�� ��� �Լ�
void shellSortPage(void); // �� ���� ȭ�� ��� �Լ�
void countingSortPage(void); // ��� ���� ȭ�� ��� �Լ�
void radixSortPage(void); // ��� ���� ȭ�� ��� �Լ�
void speedCheck(void); // ���� �ӵ� �� �Լ�
void BFSPage(void); // BFS ȭ�� ��� �Լ�
void DFSPage(void); // DFS ȭ�� ��� �Լ�
void primPage(void); // ���� ȭ�� ��� �Լ�
void kruskalPage(void); // ũ�罺Į ȭ�� ��� �Լ�

int stack[11];
int queue[11];
int front = -1;
int rear = -1;
int top = -1;
int graph[11][11];
bool visited[11];
int visitedList[11];
int visitedCount = 0;

int main(void) // ���� �Լ�
{
	system(" mode  con lines=40   cols=130 "); // �ܼ�â ũ�� ����
	startMenu(); // �ʱ� ȭ��
	return 0;
}

void startMenu(void) // �ʱ� ȭ��
{
	draw_boxArea(); // �׸� ���� �׸��� �Լ�

	// �ʱ� ���� ����
	gotoxy(20, 3);
	puts("*------------------------- �˰��� �н� ���α׷� -------------------------*");
	gotoxy(24, 7);
	puts("�˰��� �н��� ������ �� �� �ִ� ���α׷��Դϴ�!");
	gotoxy(24, 9);
	puts("���ϴ� �޴��� ��ȣŰ�� �Է��ϼ���");
	gotoxy(24, 13);
	puts("1. ���� �˰��� �н�");
	gotoxy(24, 15);
	puts("2. �׷��� �˰��� �н�");
	gotoxy(24, 19);
	puts("��� ȭ�鿡���� (�ʱ�ȭ�� : ESC, ����ȭ�� : �齺���̽�, ���� : X)");

	char key = _getch(); // Ű�� �Էµ� ��, _getch()�Լ��� �Է� ���۵� �ȳ���� ȭ�� ��µ� X
	system("cls"); // ȭ�� �����

	switch (key) {
	case '1':
		sortMenu(); // 1�� Ű�� ������ sortMenu() �Լ� ȣ��
		break;
	case '2':
		graphMenu(); // 2�� Ű�� ������ graphMenu() �Լ� ȣ��
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	default: // �ٸ� Ű�� ���� ���� �ٽ� �ʱ�ȭ��
		startMenu();
		break;
	}
}
void sortMenu(void) // ���� �˰��� �޴� �׸��� �Լ�
{
	draw_boxArea();

	gotoxy(20, 3);
	puts("*------------------------- �˰��� �н� ���α׷� -------------------------*");
	gotoxy(24, 7);
	puts("���� �н� �޴��Դϴ�. ���ϴ� �޴��� ��ȣ�� �Է��ϼ���");
	gotoxy(24, 9);
	puts("��� ���� �˰��� ���� ������ �������� �����Դϴ�.");
	gotoxy(24, 13);
	puts("1. ���� ���� �н�");
	gotoxy(24, 15);
	puts("2. ���� ���� �н�");
	gotoxy(24, 17);
	puts("3. ���� ���� �н�");
	gotoxy(24, 19);
	puts("4. �պ� ���� �н�");
	gotoxy(24, 21);
	puts("5. �� ���� �н�");
	gotoxy(24, 23);
	puts("6. �� ���� �н�");
	gotoxy(55, 13);
	puts("7. �� ���� �н�");
	gotoxy(55, 15);
	puts("8. ��� ���� �н�");
	gotoxy(55, 17);
	puts("9. ��� ���� �н�");
	gotoxy(55, 23);
	puts("0. ���� �ӵ� ��");

	char key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

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
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		startMenu();
		break;
	default: // �ٸ� Ű�� ���� ���� �ٽ� �� ȭ�� ȣ��
		sortMenu();
		break;
	}
}
void graphMenu() { // �׷��� �˰��� �޴� �׸��� �Լ�
	draw_boxArea();

	gotoxy(20, 3);
	puts("*------------------------- �˰��� �н� ���� ���α׷� -------------------------*");
	gotoxy(24, 7);
	puts("�׷��� �н� �޴��Դϴ�.���ϴ� �޴��� ��ȣŰ�� �Է��ϼ���");
	gotoxy(24, 11);
	puts("1. �ʺ� �켱 Ž��(BFS) �н�");
	gotoxy(24, 13);
	puts("2. ���� �켱 Ž��(DFS) �н�");
	gotoxy(24, 15);
	puts("3. ���� �˰��� �н�");
	gotoxy(24, 17);
	puts("4. ũ�罺Į �˰��� �н�");

	char key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

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
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		startMenu();
		break;
	default: // �ٸ� Ű�� ���� ���� �ٽ� �� ȭ�� ȣ��
		graphMenu();
		break;
	}
}

void draw_boxArea(void) {
	cursor(0); // Ŀ�� ���߱�

	// �׸� ���� �׸���
	gotoxy(2, 0); // ��ǥ�� Ŀ���� �̵��ϴ� �Լ�
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
void gotoxy(int x, int y) // Ŀ�� �̵� �Լ�
{
	COORD Pos; // ��ǥ ��� �ִ� ����ü
	Pos.X = x; // x ��ǥ �ʱ�ȭ (���� x������)
	Pos.Y = y; // y ��ǥ �ʱ�ȭ (���� y������)
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); // ��ǥ ��ġ�� Ŀ�� �̵� �Լ�
}
void cursor(int n) // Ŀ�� ���߱� ���� �Լ�
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = n; // �Ű����� n�� 0�̸� Ŀ�� ���߰� 1�̸� �巯������
	ConsoleCursor.dwSize = 1; // Ŀ�� ������
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
		printf("���� ����: ");
		for (int k = 0; k < size; k++) {
			if (k >= size - i) // ���ĵ� �κ���
				printf("\033[34m%d ", data[k]); // �Ķ������� ���
			else // ���ĵ��� ���� �κ���
				printf("\033[0m%d ", data[k]); // ���� �������� ���
		}
		printf("\033[0m"); // ������ ������� ����
		printf("\n�迭�� ���ҳ��� ���Ͽ� ã�� �ִ� : \033[31m%d\033[0m\n", data[max]);
		printf("���ĵ��� ���� �κ��� �� ���� �ִ��� �����մϴ�.\n");

		temp = data[(size - 1) - i]; // �� ���� ���� ����
		data[(size - 1) - i] = data[max];
		data[max] = temp;

		printf("���� �� ����: ");
		for (int k = 0; k < size; k++) {
			if (k >= size - i - 1) // ���ĵ� �κ���
				printf("\033[34m%d ", data[k]); // �Ķ������� ���
			else // ���ĵ��� ���� �κ���
				printf("\033[0m%d ", data[k]); // ���� �������� ���
		}
		printf("\033[0m"); // ������ ������� ����
		printf("\n\n");
	}
}
void selectionSortCode() {
	puts("���� ���� �ڵ�\n\n");
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
	puts("    printf(\"������ ���� ���� �Է�: \");");
	puts("    scanf_s(\"%d\", &n);");
	puts("");
	puts("    int* data = malloc(n * sizeof(int));");
	puts("");
	puts("    if (data == NULL) {");
	puts("        printf(\"�迭 �޸� �Ҵ� ����\");");
	puts("        return 1;");
	puts("    }");
	puts("");
	puts("    printf(\"������ ���� �Է�: \");");
	puts("    for (int i = 0; i < n; i++) {");
	puts("        scanf_s(\"%d\", &data[i]);");
	puts("    }");
	puts("");
	puts("    printf(\"���� �� �迭 : \");");
	puts("    for (int i = 0; i < n; i++)");
	puts("        printf(\"%d \", data[i]);");
	puts("    printf(\"\\n\");");
	puts("");
	puts("    selectionSort(data, n);");
	puts("");
	puts("    printf(\"���� �� �迭  : \");");
	puts("    for (int i = 0; i < n; i++)");
	puts("        printf(\"%d \", data[i]);");
	puts("    printf(\"\\n\");");
	puts("");
	puts("    free(data);");
	puts("    return 0;");
	puts("}");

	puts("\n\n ESCŰ or �齺���̽� or X�� �Է��ϼ���");
	char key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ���� ���� �ٽ� �� ȭ��
		selectionSortCode();
		break;
	}
}
void selectionSortPage() {
	puts("*----------------------------------------------------���� ����----------------------------------------------------*\n\n");
	puts("����: �� ���ҿ� ���� �� �����Ͽ� ���� ū ���� ã�� �迭�� �޺κп� �δ� ������ �ݺ��Ͽ� �����ϴ� ����Դϴ�.\n");
	puts("�ð� ���⵵: ��� ���ҿ� ���� �� �����ؼ� �ִ��� ã�ƾ� �ϹǷ� �Է� �� N�� ����ϴ� �ð�,");
	puts("              �׷� ���� �ѹ��� ���� �ϳ��� ���ĵǹǷ� ��� �����Ϸ��� �� �Է� �� N�� ����ϴ� �ð�");
	puts("              ���� �ð����⵵�� O(N^2) �Դϴ�.\n\n");
	puts("�ڵ� ������ �Ͻðڽ��ϱ�? �Ͻ÷��� Y, �ƴ϶�� ESCŰ Ȥ�� �齺���̽��� �����ּ���.\n");

	char key = _getch(); // Ű�� �ԷµǸ�

	switch (key) {
	case 'Y': // YŰ�� yŰ�� ������ �ڵ� ���
		break;
	case 'y':
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		system("cls"); // ȭ�� �����
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		system("cls"); // ȭ�� �����
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		system("cls"); // ȭ�� �����
		selectionSortPage();
		break;
	}

	int n = 0;
	printf("������ ���� ������ �Է��ϼ���: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n��ŭ �����Ҵ�

	if (data == NULL) {
		printf("�迭 �޸� �Ҵ� ����");
		return 1;
	}

	printf("������ ���� �Է��ϼ��� (����� ����): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("���� �� �迭 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n");

	selectionSort(data, n);

	printf("���� �� �迭  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d ", data[i]);
	printf("\033[0m");
	printf("\n");

	free(data);

	puts("\n\n�ڵ带 Ȯ���Ͻ÷��� Y�� �Է����ּ���");

	key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'Y': // YŰ�� yŰ�� ������ �ڵ� ���
		selectionSortCode();
		break;
	case 'y':
		selectionSortCode();
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		selectionSortPage();
		break;
	}
}
void bubbleSort(int data[], int size) {
	int temp = 0; // ������ ���� �ӽ� ����
	for (int i = 0; i < size - 1; i++) { // �� n - 1���� �ݺ��� �ϸ� �̹� ������ �Ϸ�� ����
		Sleep(500);
		printf("\nStep %d \n", i + 1);
		printf("���� ����: ");
		for (int k = 0; k < size; k++) {
			if (k >= size - i) // ���ĵ� �κ���
				printf("\033[34m%d ", data[k]); // �Ķ������� ���
			else // ���ĵ��� ���� �κ���
				printf("\033[0m%d ", data[k]); // ���� �������� ���
		}
		printf("\n");
		printf("\033[0m"); // ���� �������� ���
		for (int j = 0; j < (size - 1) - i; j++) { // �� ���� �������� �ڿ� ū ���� �ϳ��� ���̱⿡ (n - 1) - i������ ��
			if (data[j] > data[j + 1]) { // ���� ���� ������ ��, ������ ���� �� ũ�� ����
				temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
			}
		}
		printf("������ �� ���� �� -> ū ���� �ڷ� ������ ���� -> ������ �ݺ� -> �ִ��� �� �ڷ� ��ġ\n");
		printf("���� �� ����: ");
		for (int k = 0; k < size; k++) {
			if (k >= size - 1 - i) // ���ĵ� �κ���
				printf("\033[34m%d ", data[k]); // �Ķ������� ���
			else // ���ĵ��� ���� �κ���
				printf("\033[0m%d ", data[k]); // ���� �������� ���
		}
		printf("\033[0m"); // ������ ������� ����
		printf("\n\n");
	}
}
void bubbleSortCode() {
	puts("���� ���� �ڵ�\n\n");
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
	puts("    printf(\"������ ���� ���� �Է�: \");");
	puts("    scanf_s(\"%d\", &n);");
	puts("");
	puts("    int* data = malloc(n * sizeof(int)); ");
	puts("");
	puts("    if (data == NULL) {");
	puts("        printf(\"�迭 �޸� �Ҵ� ����\");");
	puts("        return 1;");
	puts("    }");
	puts("");
	puts("    printf(\"������ ���� �Է�: \");");
	puts("    for (int i = 0; i < n; i++) {");
	puts("        scanf_s(\"%d\", &data[i]);");
	puts("    }");
	puts("");
	puts("    printf(\"���� �� �迭 : \");");
	puts("    for (int i = 0; i < n; i++)");
	puts("        printf(\"%d \", data[i]);");
	puts("    printf(\"\\n\"); ");
	puts("");
	puts("    bubbleSort(data, n);");
	puts("");
	puts("    printf(\"���� �� �迭  : \");");
	puts("    for (int i = 0; i < n; i++)");
	puts("        printf(\"%d \", data[i]);");
	puts("    printf(\"\\n"); ")";
	puts("");
	puts("    free(data);");
	puts("    return 0;");
	puts("}");

	puts("\n\n ESCŰ or �齺���̽� or X�� �Է��ϼ���");
	char key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ���� ���� �ٽ� �� ȭ��
		bubbleSortCode();
		break;
	}
}
void bubbleSortPage() {
	puts("*----------------------------------------------------���� ����----------------------------------------------------*\n\n");
	puts("����:  ��� ������ ���ҳ��� ���ϰ�, ū ���̸� ���������� �����ؼ� �ѱ�⸦ �ݺ�");
	puts("       �̷��� 1������ ���� ���� ū ���� �ϳ��� ���ĵǸ�, �� ������ �Է¿� ����Ѹ�ŭ �ݺ��ϴ� �����Դϴ�.\n");
	puts("�ð� ���⵵: ��� ���ҿ� ���� �� �����ؼ� ���� ū ���� �����ʿ� ���� 1������ ������ �Է� N�� ����� �ð�");
	puts("              �׷� ���� �ѹ��� ���� �ϳ��� ���ĵǹǷ� ��� �����Ϸ��� �� �Է� �� N�� ����ϴ� �ð�");
	puts("              ���� �ð����⵵�� O(N^2) �Դϴ�.\n\n");
	puts("�ڵ� ������ �Ͻðڽ��ϱ�? �Ͻ÷��� Y, �ƴ϶�� ESCŰ Ȥ�� �齺���̽��� �����ּ���.\n");

	char key = _getch(); // Ű�� �ԷµǸ�

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		system("cls"); // ȭ�� �����
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		system("cls"); // ȭ�� �����
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		system("cls"); // ȭ�� �����
		bubbleSortPage();
		break;
	}

	int n = 0;
	printf("������ ���� ������ �Է��ϼ���: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n��ŭ �����Ҵ�

	if (data == NULL) {
		printf("�迭 �޸� �Ҵ� ����");
		return 1;
	}

	printf("������ ���� �Է��ϼ��� (����� ����): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("���� �� �迭 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n\n");

	bubbleSort(data, n);

	printf("���� �� �迭  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d ", data[i]);
	printf("\033[0m");
	printf("\n");

	free(data);

	puts("\n\n�ڵ带 Ȯ���Ͻ÷��� Y�� �Է����ּ���");

	key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'Y': // YŰ�� yŰ�� ������ �ڵ� ���
		bubbleSortCode();
		break;
	case 'y':
		bubbleSortCode();
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		bubbleSortPage();
		break;
	}
}
void insertionSort(int data[], int size) {
	int i, j, key;
	for (i = 1; i < size; i++) {
		Sleep(500);
		printf("\nStep %d \n", i);
		printf("���� ����: ");
		for (int k = 0; k < size; k++) {
			if (k <= i - 1) // ���ĵ� �κ���
				printf("\033[34m%d ", data[k]); // �Ķ������� ���
			else // ���ĵ��� ���� �κ���
				printf("\033[0m%d ", data[k]); // ���� �������� ���
		}
		printf("\n");
		printf("\033[0m"); // ���� �������� ���

		if (i != size) {
			printf("�������� ���ĵ� �κп� ���Ե� ����: \033[31m%d\033[0m\n", data[i]);
		}

		key = data[i];
		j = i - 1;
		while (j >= 0 && key < data[j]) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = key;

		printf("�� �����Ͽ� ��ġ�� ã��, ���Ե� ���Ҹ� ã�� ��ġ�� �ֱ�\n");
		printf("���� �� ����: ");
		for (int k = 0; k < size; k++) {
			if (k <= i) // ���ĵ� �κ���
				printf("\033[34m%d ", data[k]); // �Ķ������� ���
			else // ���ĵ��� ���� �κ���
				printf("\033[0m%d ", data[k]); // ���� �������� ���
		}
		printf("\033[0m"); // ������ ������� ����
		printf("\n\n");
	}
}
void insertionSortCode() {
	puts("���� ���� �ڵ�\n\n");
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
	puts("\tprintf(\"������ ���� ������ �Է��ϼ���: \");");
	puts("\tscanf_s(\"%d\", &n);");
	puts("");
	puts("\tint* data = malloc(n * sizeof(int));");
	puts("");
	puts("\tif (data == NULL) {");
	puts("\t\tprintf(\"�迭 �޸� �Ҵ� ����\");");
	puts("\t\treturn 1;");
	puts("\t}");
	puts("");
	puts("\tprintf(\"������ ���� �Է��ϼ��� (����� ����): \");");
	puts("\tfor (int i = 0; i < n; i++) {");
	puts("\t\tscanf_s(\"%d\", &data[i]);");
	puts("\t}");
	puts("");
	puts("\tprintf(\"���� ���� �迭 ��� : \");");
	puts("\tfor (int i = 0; i < n; i++)");
	puts("\t\tprintf(\"%d \", data[i]);");
	puts("\tprintf(\"\");");
	puts("");
	puts("\tinsertionSort(data, n);");
	puts("");
	puts("\tprintf(\"���� ���� �迭 ��� : \");");
	puts("\tfor (int i = 0; i < n; i++)");
	puts("\t\tprintf(\"%d \", data[i]);");
	puts("\tprintf(\"\");");
	puts("");
	puts("\tfree(data);");
	puts("\treturn 0;");
	puts("}");


	puts("\n\n ESCŰ or �齺���̽� or X�� �Է��ϼ���");
	char key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ���� ���� �ٽ� �� ȭ��
		insertionSortCode();
		break;
	}
}
void insertionSortPage() {
	puts("*----------------------------------------------------���� ����----------------------------------------------------*\n\n");
	puts("����:  �� ��°���� �����Ͽ� �̹� ���ĵ� �����͵��� ����, ������ ��ġ�� �ľ��ϰ� �����͸� �ִ� ������ �ݺ��ϴ� �˰���");
	puts("       ���� ��� �� ��° ���Ұ� ���ԵǸ�, ������ �� ��° �����Ͱ� �̹� ���ĵ� ���� �ϳ��ϳ� �� ������ ���� ���� ��ġ�� �ľ��ϰ� ����.\n");
	puts("�ð� ���⵵: ���Ե� ���Ұ� �̹� ���ĵ� ���� �� �����Ϸ��� �Է� N�� ����� �ð�");
	puts("              �׷� ���� �ѹ��� ���� �ϳ��� ���ԵǾ� ���ĵǹǷ� ��� �����Ϸ��� �� �Է� �� N�� ����ϴ� �ð�");
	puts("              ���� �ð����⵵�� O(N^2) �Դϴ�.\n\n");
	puts("�ڵ� ������ �Ͻðڽ��ϱ�? �Ͻ÷��� Y, �ƴ϶�� ESCŰ Ȥ�� �齺���̽��� �����ּ���.\n");

	char key = _getch(); // Ű�� �ԷµǸ�

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		system("cls"); // ȭ�� �����
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		system("cls"); // ȭ�� �����
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		system("cls"); // ȭ�� �����
		insertionSortPage();
		break;
	}

	int n = 0;
	printf("������ ���� ������ �Է��ϼ���: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n��ŭ �����Ҵ�

	if (data == NULL) {
		printf("�迭 �޸� �Ҵ� ����");
		return 1;
	}

	printf("������ ���� �Է��ϼ��� (����� ����): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("���� �� �迭 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n\n");

	insertionSort(data, n);

	printf("���� �� �迭  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d ", data[i]);
	printf("\033[0m");
	printf("\n");

	free(data);

	puts("\n\n�ڵ带 Ȯ���Ͻ÷��� Y�� �Է����ּ���");

	key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'Y': // YŰ�� yŰ�� ������ �ڵ� ���
		insertionSortCode();
		break;
	case 'y':
		insertionSortCode();
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
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
void printArrayWithColor(int data[], int size) { // ������ ���� �Ķ��� ���
	for (int i = 0; i < size - 1; ++i)
		printf("%d ", data[i]);
	printf("\033[34m%d\033[0m ", data[size - 1]);
	puts("");
}
void merge(int data[], int first, int mid, int last) {
	int left = first, right = mid + 1, t_index = first;
	int* temp = malloc((last + 1) * sizeof(int));

	printf("\n�迭 �պ�(���ĵǵ��� �պ�): ");
	printf("\033[31m");
	printArray(data, first, mid); // ���� �迭 ���
	printf("\033[0m");
	printf("AND ");
	printf("\033[31m");
	printArray(data, mid + 1, last); // ������ �迭 ���
	printf("\033[0m");

	while (left <= mid && right <= last) {
		if (data[left] <= data[right]) // �� �迭�� ���� ���� ������ ��
			temp[t_index++] = data[left++]; // ���� �迭�� ���� �� ������ �� �� ����ֱ�
		else
			temp[t_index++] = data[right++]; // ������ �迭�� ���� �� ������ �� �� ����ֱ�
	}

	if (left > mid) { // ���� �迭�� ���� �������� ������ ������ �迭�� �� �״�� �ٿ��ֱ�
		for (int i = right; i <= last; i++)
			temp[t_index++] = data[i];
	}
	else { // ������ �迭�� ���� �������� ������ ���� �迭�� �� �״�� �ٿ��ֱ�
		for (int i = left; i <= mid; i++)
			temp[t_index++] = data[i];
	}

	for (int i = first; i <= last; i++) // ���� ���� temp�迭�� ���� data�迭�� �� �����
		data[i] = temp[i];

	printf("\n�պ� �� ����: ");
	printArray(data, first, last);
	printf("\n");
	Sleep(500);
}
void mergeSort(int data[], int first, int last) {
	if (first < last) { // first�� last���� ���� ���� ����ǹǷ� �������� ���� �� ���ǹ��� ����X

		int mid = (first + last) / 2; // �迭�� ���̸� �������� ���� �ε����� mid�� ����

		printf("\n�迭 ����: ");
		printArray(data, first, mid); // ���� ���� �迭 ���
		printf("AND ");
		printArray(data, mid + 1, last); // ������ ���� �迭 ���
		printf("���� �и���");

		mergeSort(data, first, mid); // �� �κ��� ��� ���ȣ���ϸ鼭 ������ �ε��� �ڸ���
		mergeSort(data, mid + 1, last); // �� �κ��� ��� ���ȣ���ϸ鼭 ������ �ε��� �ڸ���
		merge(data, first, mid, last); // �� �迭 ��ġ��
	}
}
void mergeSortCode() {
	puts("�պ� ���� �ڵ�\n\n");
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
	puts("\tprintf(\"������ ���� ������ �Է��ϼ���: \");");
	puts("\tscanf_s(\"%d\", &n);");
	puts("");
	puts("\tint* data = malloc(n * sizeof(int));");
	puts("");
	puts("\tif (data == NULL) {");
	puts("\t\tprintf(\"�迭 �޸� �Ҵ� ����\");");
	puts("\t\treturn 1;");
	puts("\t}");
	puts("");
	puts("\tprintf(\"������ ���� �Է��ϼ��� (����� ����): \");");
	puts("\tfor (int i = 0; i < n; i++) {");
	puts("\t\tscanf_s(\"%d\", &data[i]);");
	puts("\t}");
	puts("");
	puts("\tprintf(\"���� ���� �迭 ��� : \");");
	puts("\tfor (int i = 0; i < n; i++)");
	puts("\t\tprintf(\"%d \", data[i]);");
	puts("\tprintf(\"\");");
	puts("");
	puts("\tmergeSort(data, 0, n - 1);");
	puts("");
	puts("\tprintf(\"���� ���� �迭 ��� : \");");
	puts("\tfor (int i = 0; i < n; i++)");
	puts("\t\tprintf(\"%d \", data[i]);");
	puts("\tprintf(\"\");");
	puts("");
	puts("\tfree(data);");
	puts("\treturn 0;");
	puts("}");

	puts("\n\n ESCŰ or �齺���̽� or X�� �Է��ϼ���");
	char key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ���� ���� �ٽ� �� ȭ��
		mergeSortCode();
		break;
	}
}
void mergeSortPage() {
	puts("*----------------------------------------------------�պ� ����----------------------------------------------------*\n\n");
	puts("����:  �־��� �����͸� ���� ���� �������� ��� ���� ��, �� �����Ͽ� �����ϰ� ��ġ�� ������ �ݺ��ϴ� �˰���");
	puts("       ���� ������ �����Ͱ� �ϳ��� �� ������ ����Ǹ�, ���ҵ� �����͵��� ������ �°� ���ġ�Ͽ� �պ��ϴ� ������ �ݺ�\n\n");
	puts("�ð� ���⵵: �պ� ������ �����͸� ��� ������ ������ ������, logN �ܰ踦 ��ġ��, �� �ܰ迡�� ���Ҹ� ���ϸ� �պ��� �� �Է� N�� ����� �ð�");
	puts("             ���� �ð� ���⵵�� O(NlogN)�Դϴ�.\n\n");
	puts("�ڵ� ������ �Ͻðڽ��ϱ�? �Ͻ÷��� Y, �ƴ϶�� ESCŰ Ȥ�� �齺���̽��� �����ּ���.\n\n");

	char key = _getch(); // Ű�� �ԷµǸ�

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		system("cls"); // ȭ�� �����
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		system("cls"); // ȭ�� �����
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		system("cls"); // ȭ�� �����
		mergeSortPage();
		break;
	}

	int n = 0;
	printf("������ ���� ������ �Է��ϼ���: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n��ŭ �����Ҵ�

	if (data == NULL) {
		printf("�迭 �޸� �Ҵ� ����");
		return 1;
	}

	printf("������ ���� �Է��ϼ��� (����� ����): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("���� �� �迭 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n\n");

	mergeSort(data, 0, n - 1);

	printf("\n\n���� �� �迭  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d ", data[i]);
	printf("\033[0m");
	printf("\n");

	free(data);

	puts("\n\n�ڵ带 Ȯ���Ͻ÷��� Y�� �Է����ּ���");

	key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'Y': // YŰ�� yŰ�� ������ �ڵ� ���
		mergeSortCode();
		break;
	case 'y':
		mergeSortCode();
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		mergeSortPage();
		break;
	}
}
void quickSort(int data[], int L, int R) {
	Sleep(500);
	printf("\n���� ���� (�����Ͽ� �ݺ�): ");
	for (int i = L; i <= R; i++) {
		printf("%d ", data[i]);
	}

	int left = L, right = R;
	int pivot = data[(L + R) / 2];    // pivot ���� (���) 
	int temp;

	printf("\n�ǹ� �� ����(���): \033[31m%d\033[0m", pivot);

	while (left <= right) {
		while (data[left] < pivot)    // left�� pivot���� ū ���� �����ų� pivot�� ���� ������ 
			left++;
		while (data[right] > pivot)    // right�� pivot���� ���� ���� �����ų� pivot�� ���� ������ 
			right--;
		if (left <= right) {   // left�� right���� ���ʿ� �ִٸ� ��ȯ 
			temp = data[left];
			data[left] = data[right];
			data[right] = temp;

			left++;
			right--;
		}
	}

	printf("\n�ǹ� ���� ���� �� ����: ");
	for (int i = L; i <= R; i++) {
		if (data[i] == pivot) {
			printf("\033[31m%d\033[0m ", data[i]);  // �ǹ� ���̸� ���������� ���
		}
		else {
			printf("%d ", data[i]);
		}
	}
	printf("\033[0m\n");

	if (L < right)
		quickSort(data, L, right);    // ���� �迭 ��������� �ݺ� 

	if (left < R)
		quickSort(data, left, R);    // ������ �迭 ��������� �ݺ� 
}
void quickSortCode() {
	puts("�� ���� �ڵ�\n\n");
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
	puts("	printf(\"������ ���� ������ �Է��ϼ���: \");");
	puts("	scanf_s(\"%d\", &n);");
	puts("");
	puts("	int* data = malloc(n * sizeof(int));");
	puts("");
	puts("	if (data == NULL) {");
	puts("		printf(\"�迭 �޸� �Ҵ� ����\");");
	puts("		return 1;");
	puts("	}");
	puts("");
	puts("	printf(\"������ ���� �Է��ϼ��� (����� ����): \");");
	puts("	for (int i = 0; i < n; i++) {");
	puts("		scanf_s(\"%d\", &data[i]);");
	puts("	}");
	puts("");
	puts("	printf(\"���� ���� �迭 ��� : \");");
	puts("	for (int i = 0; i < n; i++)");
	puts("		printf(\"%d \", data[i]);");
	puts("	printf(\"\\n\");");
	puts("");
	puts("	quickSort(data, 0, n - 1);");
	puts("");
	puts("	printf(\"���� ���� �迭 ��� : \");");
	puts("	for (int i = 0; i < n; i++)");
	puts("		printf(\"%d \", data[i]);");
	puts("	printf(\"\\n\");");
	puts("");
	puts("	free(data);");
	puts("	return 0;");
	puts("}");

	puts("\n\n ESCŰ or �齺���̽� or X�� �Է��ϼ���");
	char key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ���� ���� �ٽ� �� ȭ��
		quickSortCode();
		break;
	}
}
void quickSortPage() {
	puts("*----------------------------------------------------�� ����----------------------------------------------------*\n\n");
	puts("����:  �־��� ������ �� �ϳ��� �ǹ����� ���� ��, �ǹ����� ���� ���� ����, ū ���� ���������� ������ �� �����ϴ� �˰���");
	puts("       �� ������ ��������� �ݺ��Ͽ� ��ü �����͸� �����մϴ�.\n\n");
	puts("�ð� ���⵵: �ּ��� ���, �����Ͱ� ������ ������ �ð� ���⵵�� O(NlogN)�Դϴ�. �Ǻ� �������� �� �����ϸ� �ű� ��");
	puts("             �Է� N�� ����� �ð�.  �׸��� ������ �� �������ٸ� logN�� ����� �ð��� �ɸ��� �����Դϴ�.");
	puts("             ������ �־��� ��쿡�� �����Ͱ� �� ���������� ���� ��쿡, ��� �����͸� ���ؾ� �ؼ� �ð� ���⵵�� O(N^2)\n\n");
	puts("�ڵ� ������ �Ͻðڽ��ϱ�? �Ͻ÷��� Y, �ƴ϶�� ESCŰ Ȥ�� �齺���̽��� �����ּ���.\n\n");

	char key = _getch(); // Ű�� �ԷµǸ�

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		system("cls"); // ȭ�� �����
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		system("cls"); // ȭ�� �����
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		system("cls"); // ȭ�� �����
		quickSortPage();
		break;
	}

	int n = 0;
	printf("������ ���� ������ �Է��ϼ���: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n��ŭ �����Ҵ�

	if (data == NULL) {
		printf("�迭 �޸� �Ҵ� ����");
		return 1;
	}

	printf("������ ���� �Է��ϼ��� (����� ����): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("���� �� �迭 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n\n");

	quickSort(data, 0, n - 1);

	printf("\n\n\n���� �� �迭  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d\033[0m ", data[i]);
	printf("\n");

	free(data);

	puts("\n\n�ڵ带 Ȯ���Ͻ÷��� Y�� �Է����ּ���");

	key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'Y': // YŰ�� yŰ�� ������ �ڵ� ���
		quickSortCode();
		break;
	case 'y':
		quickSortCode();
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		quickSortPage();
		break;
	}
}
void exHeapSort() {
	puts("���÷� �迭 [10, 2, 8, 6, 3, 5, 7] �� �� ���ķ� �������� �����ϴ� ���� �����帮�ڽ��ϴ�.");
	Sleep(600);
	puts("1. �迭�� ������� Ʈ���� ����ֽ��ϴ�.(����Ʈ���� �����ǵ��� �ֱ�)\n");
	puts("         10");
	puts("       /    \\");
	puts("      2      8");
	puts("     / \\    / \\");
	puts("    6   3  5   7\n");
	Sleep(600);
	puts("2. ���� ���� ������ �θ� ��� '8'���� maxHeapify�� �����մϴ�.");
	puts("maxHeapify�� ȣ��Ǹ� �θ���� �� �ڽ� ��峢���� �� ������ ���� �ִ��� �θ���� �ø��ϴ�(����)");
	puts("���⼭�� �θ� ��� '8'�� � �ڽ� ��庸�ٵ� ũ�⿡ ������� �������� �����մϴ�.\n");
	puts("         10");
	puts("       /    \\");
	puts("      2      8");
	puts("     / \\    / \\");
	puts("    6   3  5   7\n");
	Sleep(600);
	puts("3. �ε����� ���� �� �׺��� ������ �θ��� '2'�� ���� maxHeapify�� �����մϴ�. '2'�� ���� �ڽ� ��� �� ���� ū �� '6'�� ��ġ�� �ٲߴϴ�.\n");
	puts("         10");
	puts("       /    \\");
	puts("      6      8");
	puts("     / \\    / \\");
	puts("    2   3  5   7\n");
	Sleep(600);
	puts("4. ���� ��Ʈ ��� '10'�� ���� maxHeapify�� �����մϴ�. '10'�� �̹� ���� ū ���̹Ƿ� ���� ���� �����մϴ�.\n");
	puts("         10");
	puts("       /    \\");
	puts("      6      8");
	puts("     / \\    /  \\");
	puts("    2   3  5    7\n");
	Sleep(600);
	puts("5. ���� �ִ� ���� ����������ϴ�. ���� �� ���� ������ �����մϴ�. ");
	puts("maxHeap���������� ��Ʈ ��尡 ���� ū ���Դϴ�. �̰� �̿��Ͽ� ��Ʈ ��带 �ϳ��� �����Ͽ� ������ �Ϸ�ǰڽ��ϴ�.");
	puts("��Ʈ ���� ���� ���� ���� ���� ��ȯ�ϰ�, �迭 �������� ���ܽ�ŵ�ϴ�. �׸��� ���� Ʈ�� �������� �� �ִ����� ����\n");
	puts("         7");
	puts("       /    \\");
	puts("      6      5");
	puts("     / \\    /  ");
	puts("    2   3  8   \n");
	Sleep(600);
	puts("---------�ִ��� ������ Ʈ������ �ٽ� �ִ��� ����---------\n");
	puts("         8");
	puts("       /    \\");
	puts("      6      7");
	puts("     / \\    /");
	puts("    2   3  5\n");
	Sleep(600);
	puts("6. �� ������ �ݺ��Ͽ� ���������� ������������ ���ĵ� �迭�� ����ϴ�.\n");
	puts("���� �� �迭 : \033[34m2 3 5 6 7 8 10\033[0m\n\n");
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
	printf("�ִ� ������ ����: (maxHeapify):");
	printArray2(data, size);
	puts("");

	for (int i = size - 1; i > 0; i--) {
		int temp = data[0];
		data[0] = data[i];
		data[i] = temp;

		printf("��Ʈ ���� ���� ��� ����: ");
		printArrayWithColor(data, i + 1);

		maxHeapify(data, i, 0);

		printf("�������� �ٽ� heapify(�̶� ���ҵ� ���� ��Ʈ ���� ����): ");
		printArray2(data, i);
		puts("");
		Sleep(500);
	}
}
void heapSortCode() {
	puts("�� ���� �ڵ�\n\n");
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
	puts("	printf(\"������ ���� ������ �Է��ϼ���: \");");
	puts("	scanf_s(\"%d\", &n);");
	puts("");
	puts("	int* data = malloc(n * sizeof(int));");
	puts("");
	puts("	if (data == NULL) {");
	puts("		printf(\"�迭 �޸� �Ҵ� ����\");");
	puts("		return 1;");
	puts("	}");
	puts("");
	puts("	printf(\"������ ���� �Է��ϼ��� (����� ����): \");");
	puts("	for (int i = 0; i < n; i++) {");
	puts("		scanf_s(\"%d\", &data[i]);");
	puts("	}");
	puts("");
	puts("	printf(\"���� ���� �迭 ��� : \");");
	puts("	for (int i = 0; i < n; i++)");
	puts("		printf(\"%d \", data[i]);");
	puts("	printf(\"\\n\");");
	puts("");
	puts("	heapSort(data, n);");
	puts("");
	puts("	printf(\"���� ���� �迭 ��� : \");");
	puts("	for (int i = 0; i < n; i++)");
	puts("		printf(\"%d \", data[i]);");
	puts("	printf(\"\\n\");");
	puts("");
	puts("	free(data);");
	puts("	return 0;");
	puts("}");

	puts("\n\n ESCŰ or �齺���̽� or X�� �Է��ϼ���");
	char key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ���� ���� �ٽ� �� ȭ��
		heapSortCode();
		break;
	}
}
void heapSortPage() {
	puts("*----------------------------------------------------�� ����----------------------------------------------------*\n\n");
	puts("����:  �־��� �����͸� ��(Heap)�̶�� �ڷᱸ���� �̿��Ͽ� �����ϴ� �˰����Դϴ�.");
	puts("           �����͸� ���� ������ ��, ���� ū ���� ��Ʈ�� ��ġ���� ����(��������)�� �����մϴ�.\n\n");
	puts("�ð� ���⵵: �� ������ �ð� ���⵵�� �׻� O(NlogN)�Դϴ�. �ִ� ������ ����� �������� logN�� �ð��� �ɸ���,");
	puts("             �̸� N�� �ݺ��ϱ� ������ O(NlogN)�� �ð� ���⵵�� �����ϴ�.\n\n");
	puts("�ڵ� ���� ��, ���� ���ø� �����帮�ڽ��ϴ�.\n");
	exHeapSort();
	puts("\n");
	puts("�ڵ� ������ �Ͻðڽ��ϱ�? �Ͻ÷��� Y, �ƴ϶�� ESCŰ Ȥ�� �齺���̽��� �����ּ���.\n\n");

	char key = _getch(); // Ű�� �ԷµǸ�

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		system("cls"); // ȭ�� �����
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		system("cls"); // ȭ�� �����
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		system("cls"); // ȭ�� �����
		heapSortPage();
		break;
	}

	int n = 0;
	printf("������ ���� ������ �Է��ϼ���: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n��ŭ �����Ҵ�

	if (data == NULL) {
		printf("�迭 �޸� �Ҵ� ����");
		return 1;
	}

	printf("������ ���� �Է��ϼ��� (����� ����): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("���� �� �迭 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n\n");

	heapSort(data, n);

	printf("\n���� �� �迭  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d\033[0m ", data[i]);
	printf("\n");

	free(data);

	puts("\n\n�ڵ带 Ȯ���Ͻ÷��� Y�� �Է����ּ���");

	key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'Y': // YŰ�� yŰ�� ������ �ڵ� ���
		heapSortCode();
		break;
	case 'y':
		heapSortCode();
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		heapSortPage();
		break;
	}
}
void printSublist(int data[], int size, int start, int gap) {
	printf("���긮��Ʈ: ");
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
		printf("\n\n���� ����: \033[31m%d\033[0m\n", gap);

		for (i = 0; i < gap; ++i) {
			printSublist(data, n, i, gap);
		}

		puts("\n������ ����Ʈ���� ���� �����մϴ�.\n");

		for (i = gap; i < n; i++) {
			temp = data[i];
			for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
				data[j] = data[j - gap];
			}
			data[j] = temp;
		}

		puts("������ ���� ������ ���긮��Ʈ");
		for (i = 0; i < gap; ++i) {
			printSublist(data, n, i, gap);
		}

		printf("���긮��Ʈ�� ��ģ ���: ");
		for (i = 0; i < n; ++i)
			printf("%d ", data[i]);
		puts("");
	}
}
void shellSortCode() {
	puts("�� ���� �ڵ�\n\n");
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
	puts("    printf(\"������ ���� ���� �Է�: \");");
	puts("    scanf_s(\"%d\", &n);");
	puts("");
	puts("    int* data = malloc(n * sizeof(int)); // n��ŭ �����Ҵ�");
	puts("");
	puts("    if (data == NULL) {");
	puts("        printf(\"�迭 �޸� �Ҵ� ����\");");
	puts("        return 1;");
	puts("    }");
	puts("");
	puts("    printf(\"������ ���� �Է�: \");");
	puts("    for (int i = 0; i < n; i++) {");
	puts("        scanf_s(\"%d\", &data[i]);");
	puts("    }");
	puts("");
	puts("    printf(\"���� �� �迭 : \");");
	puts("    for (int i = 0; i < n; i++)");
	puts("        printf(\"%d \", data[i]);");
	puts("    printf(\"\\n\");");
	puts("");
	puts("    shellSort(data, n);");
	puts("");
	puts("    printf(\"���� �� �迭 : \");");
	puts("    for (int i = 0; i < n; i++)");
	puts("        printf(\"%d \", data[i]);");
	puts("    printf(\"\\n\");");
	puts("");
	puts("    free(data); // �޸� ����");
	puts("    return 0;");
	puts("}");

	puts("\n\n ESCŰ or �齺���̽� or X�� �Է��ϼ���");
	char key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ���� ���� �ٽ� �� ȭ��
		shellSortCode();
		break;
	}
}
void shellSortPage() {
	puts("*----------------------------------------------------�� ����----------------------------------------------------*\n\n");
	puts("����:  �� ������ ���� ������ ������ ������, ��ü�� �迭�� ������ �������� �ɰ� ���� ������ ���������ϴ� �˰���");
	puts("       �̶� �������� �迭���� ���� ���Ŀ��� �� ��ġ�� ã�� �� ���ݸ�ŭ �̵��մϴ�(�ð� ����)");
	puts("       ���� ���ĵ� ������ ���긮��Ʈ���� �ٽ� ��Ĩ�ϴ�. �̶�, �ε����� �µ��� �������� �պ��մϴ�.");
	puts("       �ݺ��ϸ� ������ ���ݾ� ���̸�, ���������� 1�� �˴ϴ�. �� ���� ��ü ����� ���������ϴ� �Ͱ� �����ϴ�\n\n");
	puts("�ð� ���⵵: �� ������ �ð� ���⵵�� ���ݿ� ���� �ٸ�����, �Ϲ������� O(N^(3/2))�Դϴ�.");
	puts("             �̴� ���� ������ O(N^2)���� ȿ�����̸�, ������ ���ÿ� ���� ���� ������ �� �ֽ��ϴ�.\n\n");
	puts("�ڵ� ������ �Ͻðڽ��ϱ�? �Ͻ÷��� Y, �ƴ϶�� ESCŰ Ȥ�� �齺���̽��� �����ּ���.\n\n");

	char key = _getch(); // Ű�� �ԷµǸ�

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		system("cls"); // ȭ�� �����
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		system("cls"); // ȭ�� �����
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		system("cls"); // ȭ�� �����
		shellSortPage();
		break;
	}

	int n = 0;
	printf("������ ���� ������ �Է��ϼ���: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n��ŭ �����Ҵ�

	if (data == NULL) {
		printf("�迭 �޸� �Ҵ� ����");
		return 1;
	}

	printf("������ ���� �Է��ϼ��� (����� ����): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("���� �� �迭 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n\n");

	shellSort(data, n);

	printf("\n���� �� �迭  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d\033[0m ", data[i]);
	printf("\n");

	free(data);

	puts("\n\n�ڵ带 Ȯ���Ͻ÷��� Y�� �Է����ּ���");

	key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'Y': // YŰ�� yŰ�� ������ �ڵ� ���
		shellSortCode();
		break;
	case 'y':
		shellSortCode();
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
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

	printf("\n�Էµ� �迭: ");
	printArray2(data, n);

	for (int i = 0; i < n; i++) {
		count[data[i]]++;
	}

	printf("\nī��Ʈ �迭 ����(0���� %d���� �� ���� ���� ��): ", max);
	printArray2(count, max + 1);

	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	printf("ī��Ʈ �迭�� �� ��Ҹ� ���������� ����(ó������ ���ذ��� ����): ");
	printArray2(count, max + 1);

	for (int i = n - 1; i >= 0; i--) {
		Sleep(500);
		printf("\n������ ����: \033[31m%d\033[0m\n", data[i]);
		printf("�����յ� ī��Ʈ �迭���� ������ ���� \033[31m%d\033[0m�� �ε����� �Ͽ� ����: \033[34m%d \033[0m\n", data[i], count[data[i]] - 1);
		printf("��, �Է¹��� �迭���� \033[31m%d\033[0m���� ���ų� ���� ���� \033[34m%d \033[0m�� �ִٰ� ���� ����\n", data[i], count[data[i]] - 1);
		count[data[i]]--;
		result[count[data[i]]] = data[i];
		sorted[count[data[i]]] = 1;
		printf("������ ���� \033[31m%d\033[0m -> ���ĵ� �迭�� �ε��� \033[34m%d \033[0m��ġ�� �ֽ��ϴ�(%d������ ���� %d�� �ֱ� ����)\n", data[i], count[data[i]], data[i], count[data[i]] + 1);
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
	puts("��� ���� �ڵ�\n\n");
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
	puts("    printf(\"������ ���� ���� �Է�: \");");
	puts("    scanf_s(\"%d\", &n);");
	puts("");
	puts("    int* data = malloc(n * sizeof(int));");
	puts("");
	puts("    if (data == NULL) {");
	puts("        printf(\"�迭 �޸� �Ҵ� ����\");");
	puts("        return 1;");
	puts("    }");
	puts("");
	puts("    printf(\"������ ���� �Է�: \");");
	puts("    for (int i = 0; i < n; i++) {");
	puts("        scanf_s(\"%d\", &data[i]);");
	puts("    }");
	puts("");
	puts("    printf(\"���� �� �迭 : \");");
	puts("    for (int i = 0; i < n; i++)");
	puts("        printf(\"%d \", data[i]);");
	puts("    printf(\"\\n\");");
	puts("");
	puts("    countingSort(data, n);");
	puts("");
	puts("    printf(\"���� �� �迭 : \");");
	puts("    for (int i = 0; i < n; i++)");
	puts("        printf(\"%d \", data[i]);");
	puts("    printf(\"\\n\");");
	puts("");
	puts("    free(data);");
	puts("    return 0;");
	puts("}");

	puts("\n\n ESCŰ or �齺���̽� or X�� �Է��ϼ���");
	char key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ���� ���� �ٽ� �� ȭ��
		countingSortCode();
		break;
	}
}
void countingSortPage() {
	puts("*--------------------------------------------------��� ����--------------------------------------------------*\n\n");
	puts("����:  ��� ������ �� ���ڰ� �� �� �����ϴ��� ���� ������� �����ϴ� �˰����Դϴ�.");
	puts("       ���� �Է� �� �� �ִ� ���� ã�� �� ũ�⸸ŭ�� �迭�� ����ϴ�.(������ ���� Ƚ���� ����� �迭) ");
	puts("       �� �� �Է� �迭�� ��ȸ�ϸ� �� ���ڰ� �����ϴ� Ƚ���� ���� �����մϴ�.");
	puts("       �׸��� �� Ƚ���� ����� ī��Ʈ �迭�� �� ����� ���� ���� ���� ĭ����, �� ������ �� ���ؼ� ���� ĭ����");
	puts("       �̷��� ��� ���ϰ� ����� �ݺ��Ͽ� ���������� �迭�� ����ϴ�.");
	puts("       ���� �Է¹��� �迭�� ���ʺ��� �����յ� ī��Ʈ �迭�� �����Ͽ� ���ο� �迭�� ������ �����մϴ�.\n\n");
	puts("�ð� ���⵵: ��� ������ �ð� ���⵵�� O(N+K)�Դϴ�. ���⼭ N�� ������ ����, K�� �Է� �� �� �ִ��Դϴ�.");
	puts("             �̴� ��� ������ �� ������ ���� Ƚ���� ���� �ٷ� �����ϱ� ������ ������ ���Դϴ�.");
	puts("             �̶�, �Է¼��� �ִ��� ���⵵�� ������ ��ġ�� ������, �Է¼��� �ִ��� ���� �迭�� �����ϴ� ���� ����\n\n");
	puts("�ڵ� ������ �Ͻðڽ��ϱ�? �Ͻ÷��� Y, �ƴ϶�� ESCŰ Ȥ�� �齺���̽��� �����ּ���.\n\n");

	char key = _getch(); // Ű�� �ԷµǸ�

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		system("cls"); // ȭ�� �����
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		system("cls"); // ȭ�� �����
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		system("cls"); // ȭ�� �����
		countingSortPage();
		break;
	}

	int n = 0;
	printf("������ ���� ������ �Է��ϼ���: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n��ŭ �����Ҵ�

	if (data == NULL) {
		printf("�迭 �޸� �Ҵ� ����");
		return 1;
	}

	printf("������ ���� �Է��ϼ��� (����� ����): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("���� �� �迭 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n\n");

	countingSort(data, n);

	printf("\n���� �� �迭  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d\033[0m ", data[i]);
	printf("\n");

	free(data);

	puts("\n\n�ڵ带 Ȯ���Ͻ÷��� Y�� �Է����ּ���");

	key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'Y': // YŰ�� yŰ�� ������ �ڵ� ���
		countingSortCode();
		break;
	case 'y':
		countingSortCode();
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
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
		printf("\n\033[31m%d\033[0m�� �ڸ� ���� ����\n\n", exp);
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
	puts("��� ���� �ڵ�\n\n");
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
	puts("\tprintf(\"������ ���� ���� �Է�: \");");
	puts("\tscanf_s(\"%d\", &n);");
	puts("");
	puts("\tint* data = malloc(n * sizeof(int));");
	puts("");
	puts("\tif (data == NULL) {");
	puts("\t\tprintf(\"�迭 �޸� �Ҵ� ����\");");
	puts("\t\treturn 1;");
	puts("\t}");
	puts("");
	puts("\tprintf(\"������ ���� �Է�: \");");
	puts("\tfor (int i = 0; i < n; i++) {");
	puts("\t\tscanf_s(\"%d\", &data[i]);");
	puts("\t}");
	puts("");
	puts("\tprintf(\"���� �� �迭 : \");");
	puts("\tfor (int i = 0; i < n; i++)");
	puts("\t\tprintf(\"%d \", data[i]);");
	puts("\tprintf(\"\\n\");");
	puts("");
	puts("\tradixSort(data, n);");
	puts("");
	puts("\tprintf(\"���� �� �迭 : \");");
	puts("\tfor (int i = 0; i < n; i++)");
	puts("\t\tprintf(\"%d \", data[i]);");
	puts("\tprintf(\"\\n\");");
	puts("");
	puts("\tfree(data);");
	puts("\treturn 0;");
	puts("}");

	puts("\n\n ESCŰ or �齺���̽� or X�� �Է��ϼ���");
	char key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ���� ���� �ٽ� �� ȭ��
		radixSortCode();
		break;
	}
}
void radixSortPage() {
	puts("*--------------------------------------------------��� ����--------------------------------------------------*\n\n");
	puts("����:  ��� ������ �־��� �����͵��� ���� �ڸ������� ���ϴ� ������ �ݺ��Ͽ� �����ϴ� �˰����Դϴ�.");
	puts("       ���� ���� �ڸ������� ���� �����ϸ�, �� ������ ���� ���� �ڸ������� �����մϴ�.");
	puts("       �̷��� �� �ڸ������� ���� �����ϸ�, �������� ������ �ڸ��� ��� ������� ���ĵǹǷ� �ᱹ ��ü�� ����\n\n");
	puts("�ð� ���⵵: �ð� ���⵵�� O(d*(n+b))�Դϴ�. ���⼭ n�� ������ ����, b�� ����Ʈ(���), d�� �ִ� �ڸ���");
	puts("             �̴� ��� ������ �� �ڸ����� ���������� �����ϱ� ������ ������ ���Դϴ�.");
	puts("             �̶�, �Է��� �ִ� �ڸ����� �Է� ���� ������ ���⵵�� ������ ��ġ�� ������,");
	puts("             �ڸ����� ���� ���� �͵��� �����ϴµ� ���� �ӵ��� �����ݴϴ�.\n\n");
	puts("�ڵ� ������ �Ͻðڽ��ϱ�? �Ͻ÷��� Y, �ƴ϶�� ESCŰ Ȥ�� �齺���̽��� �����ּ���.\n\n");

	char key = _getch(); // Ű�� �ԷµǸ�

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		system("cls"); // ȭ�� �����
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		system("cls"); // ȭ�� �����
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		system("cls"); // ȭ�� �����
		radixSortPage();
		break;
	}

	int n = 0;
	printf("������ ���� ������ �Է��ϼ���: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int)); // n��ŭ �����Ҵ�

	if (data == NULL) {
		printf("�迭 �޸� �Ҵ� ����");
		return 1;
	}

	printf("������ ���� �Է��ϼ��� (����� ����): ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	printf("���� �� �迭 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n\n");

	radixSort(data, n);

	printf("\n���� �� �迭  : ");
	for (int i = 0; i < n; i++)
		printf("\033[34m%d\033[0m ", data[i]);
	printf("\n");

	free(data);

	puts("\n\n�ڵ带 Ȯ���Ͻ÷��� Y�� �Է����ּ���");

	key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'Y': // YŰ�� yŰ�� ������ �ڵ� ���
		radixSortCode();
		break;
	case 'y':
		radixSortCode();
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
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
	int temp = 0; // ������ ���� �ӽ� ����
	for (int i = 0; i < size - 1; i++) { // �� n - 1���� �ݺ��� �ϸ� �̹� ������ �Ϸ�� ����
		for (int j = 0; j < (size - 1) - i; j++) { // �� ���� �������� �ڿ� ū ���� �ϳ��� ���̱⿡ (n - 1) - i������ ��
			if (data[j] > data[j + 1]) { // ���� ���� ������ ��, ������ ���� �� ũ�� ����
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
		key = data[i]; // key���� ���� ������ ���Ҹ� �����س���

		for (j = i - 1; j >= 0 && key < data[j]; j--) // �̹� ���ĵǾ��ִ� �迭�� ���ʿ������� �� ����
			data[j + 1] = data[j]; // ���� key���� �� ������ �迭 ��ĭ�� �ڷ� �о �ڸ� �����

		data[j + 1] = key; // ������� �ڸ��� key�� ����
	}
}
void mergeBasic(int data[], int first, int mid, int last) { // �� �迭 ��ġ�� �Լ�
	int left = first, right = mid + 1, t_index = first;
	int* temp = malloc((last + 1) * sizeof(int));

	while (left <= mid && right <= last) {
		if (data[left] <= data[right]) // �� �迭�� ���� ���� ������ ��
			temp[t_index++] = data[left++]; // ���� �迭�� ���� �� ������ �� �� ����ֱ�
		else
			temp[t_index++] = data[right++]; // ������ �迭�� ���� �� ������ �� �� ����ֱ�
	}

	if (left > mid) { // ���� �迭�� ���� �������� ������ ������ �迭�� �� �״�� �ٿ��ֱ�
		for (int i = right; i <= last; i++)
			temp[t_index++] = data[i];
	}
	else { // ������ �迭�� ���� �������� ������ ���� �迭�� �� �״�� �ٿ��ֱ�
		for (int i = left; i <= mid; i++)
			temp[t_index++] = data[i];
	}

	for (int i = first; i <= last; i++) // ���� ���� temp�迭�� ���� data�迭�� �� �����
		data[i] = temp[i];
}
void mergeSortBasic(int data[], int first, int last) {
	int mid;
	if (first < last) { // first�� last���� ���� ���� ����ǹǷ� �������� ���� �� ���ǹ��� ����X
		mid = (first + last) / 2; // �迭�� ���̸� �������� ���� �ε����� mid�� ����

		mergeSortBasic(data, first, mid); // �� �κ��� ��� ���ȣ���ϸ鼭 ������ �ε��� �ڸ���
		mergeSortBasic(data, mid + 1, last); // �� �κ��� ��� ���ȣ���ϸ鼭 ������ �ε��� �ڸ���
		mergeBasic(data, first, mid, last); // �� �迭 ��ġ��
	}
}
void quickSortBasic(int data[], int L, int R) {
	int left = L, right = R;
	int pivot = data[(L + R) / 2];    // pivot ���� (���) 
	int temp;

	while (left < right) {
		while (data[left] < pivot)    // left�� pivot���� ū ���� �����ų� pivot�� ���� ������ 
			left++;
		while (data[right] > pivot)    // right�� pivot���� ���� ���� �����ų� pivot�� ���� ������ 
			right--;
		if (left <= right) {   // left�� right���� ���ʿ� �ִٸ� ��ȯ 
			temp = data[left];
			data[left] = data[right];
			data[right] = temp;

			left++;
			right--;
		}
	}

	if (L < right)
		quickSortBasic(data, L, right);    // ���� �迭 ��������� �ݺ� 

	if (left < R)
		quickSortBasic(data, left, R);    // ������ �迭 ��������� �ݺ� 
}
void heapSortBasic(int data[], int size) {
	for (int i = (size - 1) / 2; i >= 0; i--) // �ִ��� �����
		maxHeapify(data, size, i);

	for (int i = size - 1; i > 0; i--) { // ������� ������ �� ���� �ϳ��� ��Ҹ� �����Ͽ� ���� ���� 
		swap(&data[0], &data[i]);     // ���� �ִ밪�� ��Ʈ�� ������ ��Ҹ� ��ȯ 
		maxHeapify(data, i, 0);      // ���� ��ҵ鿡 ���� �ִ� �� ���� ���� 
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
	printf("������ ���� ������ �Է��ϼ���: ");
	scanf_s("%d", &n);

	int* data = malloc(n * sizeof(int));
	int* copy = malloc(n * sizeof(int));

	if (data == NULL) {
		printf("�迭 �޸� �Ҵ� ����");
		return 1;
	}

	printf("�����͸� �������� �����Ͻðڽ��ϱ�? �׷��ٸ� Y, �ƴ϶�� �ƹ�Ű�� �Է��ϼ���");

	char key = _getch(); // Ű�� �ԷµǸ�

	if (key == 'y' || key == 'Y') {

		srand(time(NULL));  // ���� ������ �ʱ�ȭ
		for (int i = 0; i < n; i++) {
			data[i] = rand() % 20001;  // 0 ~ 20000 ������ ���� ����
		}
	}
	else {
		printf("\n\n������ ���� �Է��ϼ��� (����� ����): ");
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &data[i]);
		}
	}

	printf("\n\n���� �� �迭 : ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);

	printf("\n\n���� �� �迭: ");
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
	printf("���� ����: %f��\n", cpu_time_used);

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	bubbleSortBasic(copy, n);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("���� ����: %f��\n", cpu_time_used);

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	insertionSortBasic(copy, n);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("���� ����: %f��\n", cpu_time_used);

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	mergeSortBasic(copy, 0, n - 1);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("�պ� ����: %f��\n", cpu_time_used);

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	quickSortBasic(copy, 0, n - 1);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("�� ����: %f��\n", cpu_time_used);

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	heapSortBasic(copy, n);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("�� ����: %f��\n", cpu_time_used);

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	shellSortBasic(copy, n);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("�� ����: %f��\n", cpu_time_used);

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	countingSortBasic(copy, n);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("��� ����: %f��\n", cpu_time_used);

	Sleep(500);
	memcpy(copy, data, n * sizeof(int));
	start = clock();
	radixSortBasic(copy, n);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("��� ����: %f��\n", cpu_time_used);

	free(data);
	free(copy);

	puts("\n\n ESCŰ or �齺���̽� or X�� �Է��ϼ���");

	key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		sortMenu();
		break;
	default:
		sortMenu();
		break;
	}
}

void exBFS() {
	puts("BFS �˰����� �̿��� �׷��� Ž���� �����մϴ�. ���� ������ 10�Դϴ�.\n");
	Sleep(600);

	puts("1. ���� ���� '10'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�.\n");
	puts("�湮 ����Ʈ: [10]\n");
	puts("�׷��� ����:\n");
	puts(" 5\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - 2 - 8 - 3\n");
	puts("   \\     |   |\n");
	puts("     9   7 - 6\n");
	Sleep(600);

	puts("2. ���� '10'�� ����� ���� '2', '5', '9'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�.");
	puts("�湮 ����Ʈ: [10, 2, 5, 9]\n");
	puts("�׷��� ����:\n");
	puts(" \033[34m5\033[0m\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - 8 - 3\n");
	puts("   \\     |   |\n");
	puts("     \033[34m9\033[0m   7 - 6\n");
	Sleep(600);

	puts("3. �������� �湮�� ���� '2'�� ����� ���� '8'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�.");
	puts("�湮 ����Ʈ: [10, 2, 5, 9, 8]\n");
	puts("�׷��� ����:\n");
	puts(" \033[34m5\033[0m\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - \033[34m8\033[0m - 3\n");
	puts("   \\     |   |\n");
	puts("    \033[34m9\033[0m    7 - 6\n");
	Sleep(600);

	puts("4. �������� �湮�� ���� '5'�� '9'�� �湮�� ������ ����� �ٸ� ������ �����Ƿ�, �湮 ����Ʈ�� �߰��Ǵ� ������ �����ϴ�.\n");
	Sleep(600);

	puts("5. �������� �湮�� ���� '8'�� ����� ���� '3', '7'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�.");
	puts("�湮 ����Ʈ: [10, 2, 5, 9, 8, 3, 7]\n");
	puts("�׷��� ����:\n");
	puts(" \033[34m5\033[0m\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - \033[34m8\033[0m - \033[34m3\033[0m\n");
	puts("   \\     |   |\n");
	puts("    \033[34m9\033[0m    \033[34m7\033[0m - 6\n");
	Sleep(600);

	puts("6. ����������, �湮�� ���� '3'�� ����� ���� '6'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�.");
	puts("�湮 ����Ʈ: [10, 2, 5, 9, 8, 3, 7, 6]\n");
	puts("�׷��� ����:\n");
	puts(" \033[34m5\033[0m\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - \033[34m8\033[0m - \033[34m3\033[0m\n");
	puts("   \\     |   |\n");
	puts("    \033[34m9\033[0m    \033[34m7\033[0m - \033[34m6\033[0m\n");
	Sleep(600);

	puts("BFS Ž���� �Ϸ�Ǿ����ϴ�. ���� �湮 ����Ʈ�� [\033[34m10, 2, 5, 9, 8, 3, 7, 6\033[0m] �Դϴ�.\n\n");
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

	printf("\n1. ���� ���� '%d'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�.\n�湮 ����Ʈ : \033[34m%d\033[0m\n\n", start, start);

	int step = 2;
	while (!isQueueEmpty()) {
		int current = dequeue();
		for (int i = 1; i <= V; i++) {
			if (graph[current][i] && !visited[i]) {
				visited[i] = true;
				enqueue(i);
				Sleep(500);
				printf("%d. �������� �湮�� ���� '%d'�� ����� ���� '%d'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�\n�湮 ����Ʈ : ", step++, current, i);
				for (int j = 0; j <= rear; j++) {
					printf("\033[34m%d\033[0m ", queue[j]);
				}
				printf("\n\n");
			}
		}
	}
	printf("\n���� �湮 ����Ʈ: ");
	for (int j = 0; j <= rear; j++) {
		printf("\033[34m%d\033[0m ", queue[j]);
	}
}
void BFSCode() {
	puts("BFS �ڵ�\n\n");
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
	puts("\tprintf(\"\\n1. ���� ���� '%d'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�.\\n�湮 ����Ʈ : \\033[34m%d\\033[0m\\n\\n\", start, start);\n");
	puts("\tint step = 2;");
	puts("\twhile (!isQueueEmpty()) {");
	puts("\t\tint current = dequeue();");
	puts("\t\tfor (int i = 1; i <= V; i++) {");
	puts("\t\t\tif (graph[current][i] && !visited[i]) {");
	puts("\t\t\t\tvisited[i] = true;");
	puts("\t\t\t\tenqueue(i);");
	puts("\t\t\t\tprintf(\"%d. �������� �湮�� ���� '%d'�� ����� ���� '%d'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�\\n�湮 ����Ʈ : \", step++, current, i);");
	puts("\t\t\t\tfor (int j = 0; j <= rear; j++) {");
	puts("\t\t\t\t\tprintf(\"\\033[34m%d\\033[0m \", queue[j]);");
	puts("\t\t\t\t}");
	puts("\t\t\t\tprintf(\"\\n\n\");");
	puts("\t\t\t}");
	puts("\t\t}");
	puts("\t}");
	puts("\tprintf(\"\\n���� �湮 ����Ʈ: \");");
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
	puts("\t\tprintf(\"���� ������ �Է��ϼ��� (2, 3, 5, 6, 8, 9, 10 �� ����): \");");
	puts("\t\tscanf_s(\"%d\", &start);");
	puts("\t\tif (start == 2 || start == 3 || start == 5 || start == 6 || start == 8 || start == 9 || start == 10) {");
	puts("\t\t\tbreak;");
	puts("\t\t}");
	puts("\t\telse {");
	puts("\t\t\tprintf(\"�߸��� ������ �ԷµǾ����ϴ�. �ٽ� �Է����ּ���\\n\");");
	puts("\t\t}");
	puts("\t}\n");
	puts("\tBFS(10, start);\n");
	puts("\treturn 0;");
	puts("}");

	puts("\n\n ESCŰ or �齺���̽� or X�� �Է��ϼ���");
	char key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		graphMenu();
		break;
	default: // �ٸ� Ű�� ���� ���� �ٽ� �� ȭ��
		BFSCode();
		break;
	}
}
void BFSPage() {
	puts("*--------------------------------------------------�ʺ� �켱 Ž��(BFS)--------------------------------------------------*\n\n");
	puts("����:  �ʺ� �켱 Ž��(BFS)�� ���� �������� ���� ����� ��������� Ž���ϴ� ����Դϴ�.");
	puts("       �������� �ٷ� Ž���� �� �ִ� �������� ��� Ž���� ��, �� �ʺ� �켱�Ͽ� �׷����� ��� �������� �湮�մϴ�.");
	puts("       ������ �ִ� �������� Ž���ϰ� �� ������ ���̸� ���� �� �ָ� �ִ� ������ �湮�ϴ� Ž�� ����Դϴ�.\n\n");
	puts("�ð� ���⵵: BFS�� �ð� ���⵵�� O(V+E)�Դϴ�. ���⼭ V�� �׷����� ������ ��, E�� �׷����� ������ ���� �ǹ��մϴ�.");
	puts("             �̴� BFS�� �׷����� ��� ������ ��Ȯ�� �� ���� �湮�ϰ�, ��� ������ �˻��ϱ� �����Դϴ�.\n\n");
	puts("\n�ڵ� ���� �� ���ø� ���� �����帮�ڽ��ϴ�.");
	exBFS();
	puts("\n");
	puts("�ڵ� ������ �Ͻðڽ��ϱ�? �Ͻ÷��� Y, �ƴ϶�� ESCŰ Ȥ�� �齺���̽��� �����ּ���.(���� �׷���)\n\n");

	char key = _getch(); // Ű�� �ԷµǸ�

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		system("cls"); // ȭ�� �����
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		system("cls"); // ȭ�� �����
		graphMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		system("cls"); // ȭ�� �����
		BFSPage();
		break;
	}

	int start;

	// �׷��� �ʱ�ȭ(����)
	graph[10][2] = graph[2][10] = graph[10][5] = graph[5][10] = graph[9][10] = graph[10][9] = 1;
	graph[2][8] = graph[8][2] = 1;
	graph[8][3] = graph[3][8] = graph[8][7] = graph[7][8] = 1;
	graph[3][6] = graph[6][3] = 1;
	graph[6][7] = graph[7][6] = 1;

	while (1) {
		printf("���� ������ �Է��ϼ��� (2, 3, 5, 6, 8, 9, 10 �� ����): ");
		scanf_s("%d", &start);
		char c = 'a';
		scanf_s("%*c", c);
		if (start == 2 || start == 3 || start == 5 || start == 6 || start == 8 || start == 9 || start == 10) {
			break;
		}
		else {
			printf("�߸��� ������ �ԷµǾ����ϴ�. �ٽ� �Է����ּ���\n");
		}
	}

	BFS(10, start);
	// ���������� ���� ���·�
	memset(queue, 0, sizeof(queue));
	memset(graph, 0, sizeof(graph));
	memset(visited, 0, sizeof(visited));
	front = -1;
	rear = -1;

	puts("\n\n�ڵ带 Ȯ���Ͻ÷��� Y�� �Է����ּ���");

	key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'Y': // YŰ�� yŰ�� ������ �ڵ� ���
		BFSCode();
		break;
	case 'y':
		BFSCode();
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		graphMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		BFSPage();
		break;
	}
}
void exDFS() {
	puts("DFS �˰����� �̿��� �׷��� Ž���� �����մϴ�. ���� ������ 10�Դϴ�.\n");
	Sleep(600);

	puts("1. ���� ���� '10'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�.");
	puts("�湮 ����Ʈ: [10]\n");
	puts("�׷��� ����:\n");
	puts(" 5\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - 2 - 8 - 3");
	puts("   \\     |   |\n");
	puts("     9   7 - 6\n");
	Sleep(600);

	puts("2. ���� '10'�� ����� ���� '2', '5', '9' �� '2'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�.");
	puts("�湮 ����Ʈ: [10, 2]\n");
	puts("�׷��� ����:\n");
	puts(" 5\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - 8 - 3\n");
	puts("   \\     |   |\n");
	puts("     9   7 - 6\n");
	Sleep(600);

	puts("3. �������� �湮�� ���� '2'�� ����� ���� '8'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�.");
	puts("�湮 ����Ʈ: [10, 2, 8]\n");
	puts("�׷��� ����:\n");
	puts(" 5\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - \033[34m8\033[0m - 3\n");
	puts("   \\     |   |\n");
	puts("    9    7 - 6\n");
	Sleep(600);

	puts("4. �������� �湮�� ���� '8'�� ����� ���� '3', '7' �� '3'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�.");
	puts("�湮 ����Ʈ: [10, 2, 8, 3]\n");
	puts("�׷��� ����:\n");
	puts(" 5\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - \033[34m8\033[0m - \033[34m3\033[0m\n");
	puts("   \\     |   |\n");
	puts("    9    7 - 6\n");
	Sleep(600);

	puts("5. ����������, �湮�� ���� '3'�� ����� ���� '6'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�.");
	puts("�湮 ����Ʈ: [10, 2, 8, 3, 6]\n");
	puts("�׷��� ����:\n");
	puts(" 5\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - \033[34m8\033[0m - \033[34m3\033[0m\n");
	puts("   \\     |   |\n");
	puts("    9    7 - \033[34m6\033[0m\n");
	Sleep(600);

	puts("6. �������� �湮�� ���� '6'�� ����� ������ �����Ƿ�, ���� �������� ���ư� '7'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�.");
	puts("�湮 ����Ʈ: [10, 2, 8, 3, 6, 7]\n");
	puts("�׷��� ����\n");
	puts(" 5\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - \033[34m8\033[0m - \033[34m3\033[0m\n");
	puts("   \\     |   |\n");
	puts("    9    \033[34m7\033[0m - \033[34m6\033[0m\n");
	Sleep(600);

	puts("7. ����������, ������ �湮���� �ʾ� ���� �ִ� ���� '5', '9'�� ���������� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�.");
	puts("�湮 ����Ʈ: [10, 2, 8, 3, 6, 7, 5, 9]\n");
	puts("�׷��� ����:\n");
	puts(" \033[34m5\033[0m\n");
	puts(" |\n");
	puts("\033[34m10\033[0m - \033[34m2\033[0m - \033[34m8\033[0m - \033[34m3\033[0m\n");
	puts("   \\     |   |\n");
	puts("    \033[34m9\033[0m    \033[34m7\033[0m - \033[34m6\033[0m\n");
	Sleep(600);

	puts("DFS Ž���� �Ϸ�Ǿ����ϴ�. ���� �湮 ����Ʈ�� [\033[34m10, 2, 8, 3, 6, 7, 5, 9\033[0m] �Դϴ�.\n");
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

	printf("\n1. ���� ���� '%d'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�.\n�湮 ����Ʈ : \033[34m%d\033[0m\n\n", start, start);

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
				printf("%d. �������� �湮�� ���� '%d'�� ����� ���� '%d'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�\n�湮 ����Ʈ : ", step++, current, i);
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
	printf("\n���� �湮 ����Ʈ : ");
	for (int j = 0; j < visitedCount; j++) {
		printf("\033[34m%d\033[0m ", visitedList[j]);
	}
}
void DFSCode() {
	puts("DFS �ڵ�\n\n");
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
	puts("\tprintf(\"\\n1. ���� ���� '%d'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�.\\n�湮 ����Ʈ : \\033[34m%d\\033[0m\\n\\n\", start, start);");
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
	puts("\t\t\t\tprintf(\"%d. �������� �湮�� ���� '%d'�� ����� ���� '%d'�� �湮�ϰ�, �湮 ����Ʈ�� �߰��մϴ�\\n�湮 ����Ʈ : \", step++, current, i);");
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
	puts("\tprintf(\"\\n���� �湮 ����Ʈ : \");");
	puts("\tfor (int j = 0; j < visitedCount; j++) {");
	puts("\t\tprintf(\"\\033[34m%d\\033[0m \", visitedList[j]);");
	puts("\t};");
	puts("\tprintf(\"\\n\");");
	puts("};");
	puts("");
	puts("int main() {");
	puts("\tint start;");
	puts("");
	puts("\t// �׷��� �ʱ�ȭ(����)");
	puts("\tgraph[10][2] = graph[2][10] = graph[10][5] = graph[5][10] = graph[9][10] = graph[10][9] = 1;");
	puts("\tgraph[2][8] = graph[8][2] = 1;");
	puts("\tgraph[8][3] = graph[3][8] = graph[8][7] = graph[7][8] = 1;");
	puts("\tgraph[3][6] = graph[6][3] = 1;");
	puts("\tgraph[6][7] = graph[7][6] = 1;");
	puts("");
	puts("\twhile (1) {");
	puts("\t\tprintf(\"���� ������ �Է��ϼ��� (2, 3, 5, 6, 8, 9, 10 �� ����): \");");
	puts("\t\tscanf_s(\"%d\", &start);");
	puts("\t\tif (start == 2 || start == 3 || start == 5 || start == 6 || start == 8 || start == 9 || start == 10) {");
	puts("\t\t\tbreak;");
	puts("\t\t};");
	puts("\t\telse {");
	puts("\t\t\tprintf(\"�߸��� ������ �ԷµǾ����ϴ�. �ٽ� �Է����ּ���\\n\");");
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

	puts("\n\n ESCŰ or �齺���̽� or X�� �Է��ϼ���");
	char key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		graphMenu();
		break;
	default: // �ٸ� Ű�� ���� ���� �ٽ� �� ȭ��
		DFSCode();
		break;
	}
}
void DFSPage() {
	puts("*--------------------------------------------------���� �켱 Ž��(DFS)--------------------------------------------------*\n\n");
	puts("����:  DFS�� ���� �������� �� �̻� �湮�� ������ ���� ������ ���� �� �湮�ϴ� Ž�� ����Դϴ�.");
	puts("       ���� �湮�� �������� ������ ������ �� �ϳ��� �����Ͽ� �Ǵٽ� �湮�� �����ϸ�, �� �̻� �湮�� ������ ���� ��");
	puts("       ���� �������� ���ư� �湮���� ���� ������ Ž���ϴ� ����Դϴ�. ");
	puts("       ��, BFS�� �޸� ���� ���� ���� �� �켱�մϴ�.\n\n");
	puts("�ð� ���⵵: DFS�� �ð� ���⵵�� BFS�� ���������� O(V+E)�Դϴ�. ���⼭ V�� ������ ��, E�� �׷����� ������ ���� �ǹ�");
	puts("             �̴� DFS�� �׷����� ��� ������ ��Ȯ�� �� ���� �湮�ϰ�, ��� ������ �˻��ϱ� �����Դϴ�.\n\n");
	puts("\n�ڵ� ���� �� ���ø� ���� �����帮�ڽ��ϴ�.");
	exDFS();
	puts("\n");
	puts("�ڵ� ������ �Ͻðڽ��ϱ�? �Ͻ÷��� Y, �ƴ϶�� ESCŰ Ȥ�� �齺���̽��� �����ּ���.(���� �׷���)\n\n");

	char key = _getch(); // Ű�� �ԷµǸ�

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		system("cls"); // ȭ�� �����
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		system("cls"); // ȭ�� �����
		graphMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		system("cls"); // ȭ�� �����
		DFSPage();
		break;
	}

	int start;

	// �׷��� �ʱ�ȭ(����)
	graph[10][2] = graph[2][10] = graph[10][5] = graph[5][10] = graph[9][10] = graph[10][9] = 1;
	graph[2][8] = graph[8][2] = 1;
	graph[8][3] = graph[3][8] = graph[8][7] = graph[7][8] = 1;
	graph[3][6] = graph[6][3] = 1;
	graph[6][7] = graph[7][6] = 1;

	while (1) {
		printf("���� ������ �Է��ϼ��� (2, 3, 5, 6, 8, 9, 10 �� ����): ");
		scanf_s("%d", &start);
		char c = 'a';
		scanf_s("%*c", c);
		if (start == 2 || start == 3 || start == 5 || start == 6 || start == 8 || start == 9 || start == 10) {
			break;
		}
		else {
			printf("�߸��� ������ �ԷµǾ����ϴ�. �ٽ� �Է����ּ���\n");
		}
	}

	DFS(10, start);

	memset(graph, 0, sizeof(graph));
	memset(visited, 0, sizeof(visited));
	memset(stack, 0, sizeof(visited));
	memset(visitedList, 0, sizeof(visitedList));
	visitedCount = 0;
	top = -1;

	puts("\n\n�ڵ带 Ȯ���Ͻ÷��� Y�� �Է����ּ���");

	key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'Y': // YŰ�� yŰ�� ������ �ڵ� ���
		DFSCode();
		break;
	case 'y':
		DFSCode();
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		graphMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
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
	printf("\n������ ����ġ\n");
	int totalWeight = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (graph[i][j] != 0) {
				printf("(%d, %d)�� ����ġ: %d\n", i + 1, j + 1, graph[i][j]);
				totalWeight += graph[i][j];
			}
		}
	}
	printf("\n����ġ ����: %d\n", totalWeight);
}
void printMST(int parent[], int graph[5][5]) {
	printf("������ ����ġ:\n");
	int totalWeight = 0;
	for (int i = 1; i < 5; i++) {
		printf("(%d, %d)�� ����ġ: %d \n", parent[i] + 1, i + 1, graph[i][parent[i]]);
		totalWeight += graph[i][parent[i]];
	}
	printf("����ġ ����: %d\n", totalWeight);
}
void primMST(int graph[5][5]) {
	int parent[5];
	int key[5];
	bool mstSet[5];
	for (int i = 0; i < 5; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	parent[0] = -1;

	printf("\n���� ���: ");
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
				printf("%d��° �ܰ�: ���� %d�� ����� ���� ��, ���� ���� ����ġ�� ���� ���� %d�� ����\n", count++, u + 1, v + 1);
				total_edges++;
			}
	}

	printf("\n�ּ� ���� Ʈ���� ������ �Ϸ�Ǿ����ϴ�.\n\n");
	printf("\n���� ���: ");
	for (int i = 1; i <= 5; i++) {
		printf("%d ", i);
	}
	printf("\n");
	printMST(parent, graph);
}
void primCode(void) {
	puts("���� �˰��� �ڵ�\n\n");
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
	puts("\tprintf(\"\\n������ ����ġ\\n\");");
	puts("\tint totalWeight = 0;");
	puts("\tfor (int i = 0; i < 5; i++) {");
	puts("\t\tfor (int j = i + 1; j < 5; j++) {");
	puts("\t\t\tif (graph[i][j] != 0) {");
	puts("\t\t\t\tprintf(\"(%d, %d)�� ����ġ: %d\\n\", i + 1, j + 1, graph[i][j]);");
	puts("\t\t\t\ttotalWeight += graph[i][j];");
	puts("\t\t\t}");
	puts("\t\t}");
	puts("\t}");
	puts("\tprintf(\"\\n����ġ ����: %d\\n\", totalWeight);");
	puts("}");
	puts("");
	puts("void printMST(int parent[], int graph[5][5]) {");
	puts("\tprintf(\"������ ����ġ:\\n\");");
	puts("\tint totalWeight = 0;");
	puts("\tfor (int i = 1; i < 5; i++) {");
	puts("\t\tprintf(\"(%d, %d)�� ����ġ: %d \\n\", parent[i] + 1, i + 1, graph[i][parent[i]]);");
	puts("\t\ttotalWeight += graph[i][parent[i]];");
	puts("\t}");
	puts("\tprintf(\"����ġ ����: %d\\n\", totalWeight);");
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
	puts("\tprintf(\"\\n���� ���: \");");
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
	puts("\t\t\t\tprintf(\"%d��° �ܰ�: ���� %d�� ����� ���� ��, ���� ���� ����ġ�� ���� ���� %d�� ����\\n\", count++, u + 1, v + 1);");
	puts("\t\t\t\ttotal_edges++;");
	puts("\t\t\t}");
	puts("\t}");
	puts("");
	puts("\tprintf(\"\\n�ּ� ���� Ʈ���� ������ �Ϸ�Ǿ����ϴ�.\\n\");");
	puts("");
	puts("\tprintf(\"\\n���� ���: \");");
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

	puts("\n\n ESCŰ or �齺���̽� or X�� �Է��ϼ���");
	char key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		graphMenu();
		break;
	default: // �ٸ� Ű�� ���� ���� �ٽ� �� ȭ��
		primCode();
		break;
	}
}
void primPage() {
	puts("*--------------------------------------------------���� �˰���--------------------------------------------------*\n\n");
	puts("����:  ���� �˰����� �׷������� �ּ� ���� Ʈ���� ã�� �˰����̸�, 'Ž������ ���'�� �̿��մϴ�.");
	puts("       ���� ������ ������ ��, ������ ������ ������ ������ �� ����ġ�� ���� ���� ������ ������ �����ϴ� �������");
	puts("       ���� Ʈ���� Ȯ���س����� ����Դϴ�. (�翬�� Ʈ���� ����� ���̱� ������ ����Ŭ�� ����� ������ ����)");
	puts("       �� ������ ��� ������ ���õǾ� �ּ� ���� Ʈ���� �ϼ��� ������ �ݺ��մϴ�.\n\n");
	puts("�ð� ���⵵: ���� �˰����� �ð� ���⵵�� �켱���� ť�� �̿��� ��� O(ElogE)�Դϴ�. ���⼭ E�� �׷����� ������ ���� �ǹ��մϴ�.");
	puts("             �̴� �׷����� ��� ������ ���� ������ �����ϰ� �켱���� ť�� �̿��Ͽ� ������ �����ϱ� �����Դϴ�.\n\n");
	puts("�ڵ� ������ �Ͻðڽ��ϱ�? �Ͻ÷��� Y, �ƴ϶�� ESCŰ Ȥ�� �齺���̽��� �����ּ���.\n\n");

	char key = _getch(); // Ű�� �ԷµǸ�

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		system("cls"); // ȭ�� �����
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		system("cls"); // ȭ�� �����
		graphMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		system("cls"); // ȭ�� �����
		primPage();
		break;
	}

	int graph[5][5] = { {0, 2, 0, 6, 0},
					{2, 0, 3, 8, 5},
					{0, 3, 0, 0, 7},
					{6, 8, 0, 0, 9},
					{0, 5, 7, 9, 0} };
	primMST(graph);

	puts("\n\n�ڵ带 Ȯ���Ͻ÷��� Y�� �Է����ּ���");

	key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'Y': // YŰ�� yŰ�� ������ �ڵ� ���
		primCode();
		break;
	case 'y':
		primCode();
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		graphMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		primPage();
		break;
	}
}

void kruskalPage() {
	puts("*--------------------------------------------------ũ�罺Į �˰���--------------------------------------------------*\n\n");
	puts("����:  ũ�罺Į �˰����� �׷������� �ּ� ���� Ʈ���� ã�� �˰����̸�, 'Ž������ ���'�� �̿��մϴ�.");
	puts("       ������ ���� ����ġ�� ���� �������� �����Ͽ� Ʈ���� Ȯ���س����ϴ�.");
	puts("       ��, ����Ŭ�� �����ϴ� ������ �����մϴ�.");
	puts("       �� ������ ��� ������ ���õǾ� �ּ� ���� Ʈ���� �ϼ��� ������ �ݺ��մϴ�.\n\n");
	puts("       ���� �˰������ �ֿ� ��������, ���� �˰����� ���� �������� ����� ������ ������ٴ� �����̸�");
	puts("       ũ�罺Į �˰����� �׻� ��� ������ ������� ������ ����Ѵٴ� ���Դϴ�.");
	puts("�ð� ���⵵: ������ ������������ �����ϴ� �� �ʿ��� �ð� O(ElogE)�̸�, ���⼭ E�� �׷����� ������ ���� �ǹ��մϴ�.\n\n");
	puts("�ڵ� ������ �Ͻðڽ��ϱ�? �Ͻ÷��� Y, �ƴ϶�� ESCŰ Ȥ�� �齺���̽��� �����ּ���.\n\n");

	char key = _getch(); // Ű�� �ԷµǸ�

	switch (key) {
	case 'y':
		break;
	case 'Y':
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		system("cls");
		return;
	case 'X':
		system("cls");
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		system("cls"); // ȭ�� �����
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		system("cls"); // ȭ�� �����
		graphMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		system("cls"); // ȭ�� �����
		kruskalPage();
		break;
	}


	puts("\n\n�ڵ带 Ȯ���Ͻ÷��� Y�� �Է����ּ���");

	key = _getch(); // Ű�� �ԷµǸ�
	system("cls"); // ȭ�� �����

	switch (key) {
	case 'Y': // YŰ�� yŰ�� ������ �ڵ� ���
		primCode();
		break;
	case 'y':
		primCode();
		break;
	case 'x': // xŰ�� XŰ�� ������ ����
		return;
	case 'X':
		return;
	case 27: // ESCŰ ������ �ʱ�ȭ��
		startMenu();
		break;
	case 8: // �齺���̽� ������ ���� ȭ��
		graphMenu();
		break;
	default: // �ٸ� Ű�� ������ �ٽ� �� ȭ��
		primPage();
		break;
	}
}