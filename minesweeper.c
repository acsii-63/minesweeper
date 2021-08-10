#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


/* role:
   i bomb around 3x3 block: i ( i = [0;8] );
   block with bomb: x;
   block unknown: -1;
*/

char mat[11][11];
char solMat[11][11];

FILE* fin;
FILE* fout;

typedef struct {
    char mat3x3[4][4];
}mine;

void inp() {
    
    fin = fopen("solvedMatrix.txt", "r");
    
    for ( int i = 0; i < 10; i++ ) {
        for ( int j = 0; j < 10; j++ ) {
            fscanf(fin, "%c", &solMat[i][j]);
            fseek(fin, 1, SEEK_CUR);
            mat[i][j] = ' ';
            printf("%c ", solMat[i][j]);
        }
        fseek(fin, 2, SEEK_CUR);
        printf("\n");
    
    }
    fclose(fin);
    
}

void open(int k) {
    
}

int main() {
    inp();

    return 0;
}
