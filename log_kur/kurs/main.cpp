#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

#define MAX_VERTICES 10 // ������������ ���������� ������

// ��������� �������� � ����������� � �������
int zastavka1() {
    system("cls");
    setlocale(LC_ALL, "Rus");
    char title[] = "   ���������� ������ ����������� �������� ������ �����\n";
    char title2[] = "��������: ������� ���� ��������\n";
    char title3[] = "������: 23���3\n";
    int length = strlen(title);
    int length2 = strlen(title2);
    int length3 = strlen(title3);

    int x, y;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int console_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int console_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // ������������ ������� ��� ������ ������
    int x_title = (console_width - length) / 2;
    int x_title2 = (console_width - length2) / 2;
    int x_title3 = (console_width - length3) / 2;
    y = console_height / 2;

    // �������� ��������� �� ������
    for (int i = 0; i < y - 2; i++)  // ��������� ������ ������ ����� �������, ����� �� ��� ����� � ������
        printf("\n");

    for (int i = 0; i < x_title; i++)
        printf(" ");
    for (int j = 0; j < length; j++) {
        printf("%c", title[j]);
        Sleep(60);
    }
    Sleep(600);

    // �������� ��� �� ������
    for (int i = 0; i < x_title2; i++)
        printf(" ");
    for (int m = 0; m < length2; m++) {
        printf("%c", title2[m]);
        Sleep(60);
    }
    Sleep(600);

    // �������� ���������� � ������ � ����� �� ������
    for (int l = 0; l < x_title3; l++)
        printf(" ");
    for (int n = 0; n < length3; n++) {
        printf("%c", title3[n]);
        Sleep(60);
    }
    Sleep(1200);
    system("cls");
    return 0;
}

// ��������� �������� � ��������������
int zastavka2() {
    system("cls");
    setlocale(LC_ALL, "Rus");
    char title[] = "   �� ������ ������!\n";
    int length = strlen(title);
    int x, y;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int console_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int console_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    x = (console_width - length) / 2;
    y = console_height / 2;

    for (int i = 0; i < y; i++)
        printf("\n");
    for (int i = 0; i < x; i++)
        printf(" ");
    for (int j = 0; j < length; j++) {
        printf("%c", title[j]);
        Sleep(60);
    }
    Sleep(600);
    Sleep(1200);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    return 0;
}

void showMenu() {
    printf("1. ������ ������ �����\n");
    printf("2. ��������� ���� �������\n");
    printf("3. ��������� ���� ���������� �������\n");
    printf("4. ����� ����������� ��������� � ������� � �������\n");
    printf("5. ��������� ��������� � ����\n");
    printf("6. �������� ������� �����\n");
    printf("7. �����\n");
}

// ������� ��� �������� ������ ������� ���������
int** createGraph(int size) {
    int** graph = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        graph[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            graph[i][j] = 0; // ������������� ������
        }
    }
    return graph;
}

// ������� ��� ������� ����� �����
void inputGraph(int** graph, int size) {
    printf("������� ������� ��������� ����� (������ 0 � 1):\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i < j) { // ���������, ����� ������� ������ ������� ����� �������
                int value;
                do {
                    printf("������� [%d][%d]: ", i, j);
                    scanf_s("%d", &value);
                    if (value != 0 && value != 1) {
                        printf("������: ����� ������� ������ 0 ��� 1.\n");
                    }
                } while (value != 0 && value != 1);

                // ������������� �������� ����������� ��� ������������������ �����
                graph[i][j] = value;
                graph[j][i] = value;
            }
            else if (i == j) {
                graph[i][j] = 0; // ��� ������ �� �������
            }
        }
    }
}

// ������� ��� ���������� ����� ���������� ������� (������ 0 � 1)
void randomGraph(int** graph, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j) {
                graph[i][j] = rand() % 2; // ��������� �������� 0 ��� 1
                graph[j][i] = graph[i][j]; // ������������ ��������������
            }
            else {
                graph[i][j] = 0; // ��� ������ �� �������
            }
        }
    }
    printf("���� ������� �������� ���������� �������.\n");
}

// ������� ��� ������ ������� ���������
void printGraph(int** graph, int size) {
    printf("������� ��������� �����:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// ����������� ������� ��� ������ ����������� ��������
void findAllIndependentSets(
    int** graph, // ������� ��������� �����
    int size,    // ���������� ������ � �����
    int* currentSet, // ������� ����������� ��������� (�������� ��� ������ �������� ������)
    int currentSize, // ������ �������� ���������
    int index,       // ������ ������� �������, � ������� �������� ��������
    FILE* file       // ���� ��� ������ ��������� ��������
) {
    if (index == size) {
        if (currentSize > 0) {
            fprintf(file, "{ ");
            for (int i = 0; i < currentSize; i++) {
                fprintf(file, "%d ", currentSet[i]);
            }
            fprintf(file, "}\n");
        }
        return;
    }

    // �������� ������� ������� � ����������� ���������
    int canInclude = 1;
    for (int i = 0; i < currentSize; i++) {
        if (graph[currentSet[i]][index] == 1) {
            canInclude = 0;
            break;
        }
    }
    if (canInclude) {
        currentSet[currentSize] = index;
        findAllIndependentSets(graph, size, currentSet, currentSize + 1, index + 1, file);
    }
    // ��������� ������� ������� �� ������������ ���������
    findAllIndependentSets(graph, size, currentSet, currentSize, index + 1, file);
}
// ������� ��� ������ ����������� �������� � ���������� � ����
void findIndependentSetsToFile(int** graph, int size, FILE* file) {
    fprintf(file, "��������� ����������� ������:\n"); // ��������� ����� ������� ��������
    int currentSet[MAX_VERTICES];
    findAllIndependentSets(graph, size, currentSet, 0, 0, file);
}

// ������� ��� ���������� ����������� � ����
void saveResultsToFile(int** graph, int size) {
    FILE* file = fopen("result.txt", "w");
    if (file == NULL) {
        printf("�� ������� ������� ���� ��� ������.\n");
        return;
    }

    // ��������� ������� ���������
    fprintf(file, "������� ��������� �����:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fprintf(file, "%d ", graph[i][j]);
        }
        fprintf(file, "\n");
    }

    // ��������� ����� ����������� �������� � ��������� � ����
    findIndependentSetsToFile(graph, size, file);

    // ��������� ����
    fclose(file);
    printf("��� ����������� ��������� ��������� � ���� result.txt\n");
}

// �������� �������
int main() {
    int size = 0;
    int** graph = NULL;
    int choice;

    zastavka1(); // ��������� ��������

    while (1) {
        showMenu();
        printf("������� ��� �����: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("������� ������ �����: ");
            scanf_s("%d", &size);
            if (size < 1 || size > MAX_VERTICES) {
                printf("������ ����� ������ ���� �� 1 �� %d.\n", MAX_VERTICES);
                size = 0;
            }
            else {
                graph = createGraph(size); // ������� ����
            }
            break;
        case 2:
            if (size == 0) {
                printf("������� ������� ������ �����!\n");
            }
            else {
                inputGraph(graph, size); // ��������� ���� �������
            }
            break;
        case 3:
            if (size == 0) {
                printf("������� ������� ������ �����!\n");
            }
            else {
                randomGraph(graph, size); // ��������� ���� ���������� �������
            }
            break;
        case 4:
            if (size == 0) {
                printf("������� ��������� ����!\n");
            }
            else {
                printf("����������� ���������:\n");
                int currentSet[MAX_VERTICES]; // ������ ��� �������� �������� ������ �������� ������������ ���������
                findAllIndependentSets(graph, size, currentSet, 0, 0, stdout); // ������� � �������
            }
            break;
        case 5:
            if (size == 0) {
                printf("������� ������� ����������� �������!\n");
            }
            else {
                saveResultsToFile(graph, size); // ��������� ���������� � ����
            }
            break;
        case 6:
            if (size == 0) {
                printf("������� �������� �������!\n");
            }
            else {
                printGraph(graph, size); // ���������� ������� �����
            }
            break;
        case 7:
            for (int i = 0; i < size; i++)
                free(graph[i]); // ����������� ������
            free(graph);
            zastavka2(); // ��������� ��������� ��������
            return 0;
        default:
            printf("�������� �����. ���������� �����.\n");
            break;
        }
    }
    return 0;
}
