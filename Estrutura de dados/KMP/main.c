#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct dictionary {
    int key;
    char *name;
} Dictionary;

int cols = 0;
int rows = 0;

void inputMatrix(int matrix[][cols], int rows, int cols, char *dicName, char *searchName);
void printMatrix(int matrix[][cols], int rows, int cols);
int getInsertValue(int matrix[][cols], int row, int col);
int getRemoveValue(int matrix[][cols], int row, int col);
int getMatchOrRepleacementValue(int matrix[][cols], int row, int col, char *dicName, char *searchName);
int getMax(int insertValue, int removeValue, int matchOrRepleacementValue);
void printBest(int matrix[][cols], int row, int col);
char* concat(const char *s1, const char *s2);
char* convertToUpperCase(char *str);

int main(int argc, char *argv[]) {
    Dictionary *dic = (Dictionary *) malloc(3*sizeof(Dictionary));
    dic[2].key = 1;
    dic[2].name = "COLHER";
    dic[0].key = 2;
    dic[0].name = "COLHERES";
    dic[1].key = 3;
    dic[1].name = "COOLER";
    
    char *name = (char *) malloc(100*sizeof(char));
    printf("Digite uma sequencia de caracteres para ser comparada:\n");
    fgets(name, 100, stdin);
    strtok(name, "\n");
    name = convertToUpperCase(name);
    for (int i = 0 ; i < 3 ; i++) {
        printf("\n\n");
        char *dicName =  concat("_", dic[i].name);
        char *searchName = concat("_", name);
        cols = strlen(dicName);
        rows = strlen(searchName);

        int matrix[rows][cols];
        memset(matrix, 0, rows*cols*sizeof(int));

        inputMatrix(matrix, rows, cols, dicName, searchName);

        printf("Matriz de Levenshtein %s x %s\n", name, dic[i].name);
        printMatrix(matrix, rows, cols);
        printBest(matrix, rows - 1, cols - 1);
        printf("\n\n");
        printf("***************************************************************\n");
    }
}

void inputMatrix(int matrix[][cols], int rows, int cols, char *dicName, char *searchName) {
    int i, j = 0;
    int jEmpty = 0;
    int iEmpty = -1;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if (i == 0) {
                matrix[i][j] = jEmpty;
                jEmpty--;
            } else {
                if (j == 0) {
                    matrix[i][j] = iEmpty;
                    iEmpty--;
                } else {
                    int insertValue = getInsertValue(matrix, i, j);
                    int removeValue = getRemoveValue(matrix, i, j);
                    int matchOrRepleacementValue = getMatchOrRepleacementValue(matrix, i, j, dicName, searchName);
                    matrix[i][j] = getMax(insertValue, removeValue, matchOrRepleacementValue);
                }
            }
        }
    }
}

void printMatrix(int matrix[][cols], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int getInsertValue(int matrix[][cols], int row, int col) {
    int i = row - 1;
    int j = col;
    return matrix[i][j] - 1;
}

int getRemoveValue(int matrix[][cols], int row, int col) {
    int i = row;
    int j = col - 1;
    return matrix[i][j] - 1;
}

int getMatchOrRepleacementValue(int matrix[][cols], int row, int col, char *dicName, char *searchName) {
    int i = row - 1;
    int j = col - 1;
    int pValue = -1;
    if (searchName[row] == dicName[col]) {
        pValue = 2;
    }
    return matrix[i][j] + pValue;
}

int getMax(int insertValue, int removeValue, int matchOrRepleacementValue) {
    int maxValue = insertValue > removeValue ? insertValue : removeValue;
    return maxValue > matchOrRepleacementValue ? maxValue : matchOrRepleacementValue;
}

void printBest(int matrix[][cols], int row, int col) {
    printf("\n");
    printf("Qtd de sub., ins. ou exc. necessárias: %d\n", matrix[row][col]);
}

char* concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char* convertToUpperCase(char *str) {
    int size = strlen(str);
    char *result = malloc(size + 1);
    for (int i = 0 ; i < size ; i++) {
        result[i] = toupper(str[i]);
    }
    return result;
}