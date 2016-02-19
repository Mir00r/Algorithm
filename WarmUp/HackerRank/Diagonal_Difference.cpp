#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>


using namespace std;

#define LLI long long int
#define ULL unsigned long long
#define row 100
#define col 100
#define MAX 1001
#define getchar_unlocked() getchar()


int n, mat[row][col];


int main (){
    int i, j, a=0, b=0;

    scanf ("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf ("%d", &mat[ i ][ j ] );

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if ( i == j )
                a += mat[i][j];

    int left = 0 + n - 1;

    for (i = 0; i < n; i++)
        for (j = n - 1; j >= 0; j--)
            if ( left == i + j )
                b += mat[i][j];

    printf ("%d\n", abs (a - b) );


    return 0;
}
