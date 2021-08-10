#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

/* matrix can be resize, standard is 10x10
   number of bombs can be change, here is 15
*/

FILE* fout;

int mat[11][11];
int bomb = 0; 

void makeBomb() {
    
    for ( int  i = 0; i < 10; i++ ) {
        for ( int j = 0; j < 10; j++ ) {
            
            if ( bomb <= 15 ) {
                
                int r = rand() % 99;
                if ( r < 15 ) {
                    bomb++;
                    mat[i][j] = 9;
                }
                else {
                    mat[i][j] = 0;
                }
                
            }
            
        }
    }
        
}

void bombE(int m, int n) {
    
    if ( m != 0 )
        mat[m-1][n] += 1;
    
    if ( n != 0 )
        mat[m][n-1] += 1;    
    
    if ( m != 9 )
        mat[m+1][n] += 1;
    
    if ( n != 9 )
        mat[m][n+1] += 1;
    
    if ( m != 0 && n != 0 )
        mat[m-1][n-1] += 1;
    
    if ( m != 9 && n != 9 )
        mat[m+1][n+1] += 1;

    if ( m != 0 && n != 9 )
        mat[m-1][n+1] += 1;    
    
    if ( m != 9 && n != 0 )
        mat[m+1][n-1] += 1;    

}

void makeNum() {
    
    for ( int i = 0; i < 10 ; i++ ) {
        for ( int j = 0; j < 10; j++ ) {
            
            if ( mat[i][j] >= 9 ) {
                bombE(i,j);
            }

        }
    }
    
    for ( int i = 0; i < 10; i++ ) {
        for ( int j = 0; j < 10; j++ ) {
            if ( mat[i][j] >= 9 ) {
                mat[i][j] = 120 - 48;
            }
        }
    }

}

void print() {
    
    fout = fopen("solvedMatrix.txt", "w");
    
    for ( int i = 0; i < 10; i++ ) {
        for ( int j = 0; j < 10; j++ ) {
            mat[i][j] += 48;
            fprintf(fout, "%c ", mat[i][j]);
            printf("%c ", mat[i][j]);
        }
        fprintf(fout, "\n");
        printf("\n");
    }
    
    fclose(fout);
    
}

int main() {
    makeBomb();
    makeNum();
    print();
    return 0;
}

