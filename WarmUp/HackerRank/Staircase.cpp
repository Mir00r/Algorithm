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


int main (){
    int n, i, j, k, last, tmp, cnt=1;

    scanf ("%d", &n);

    last = n - 1;
    for ( i = 0; i < n; i++ ){
        //last = n - 1;
        tmp = last;

        for ( j = 0; j < tmp; j++ )
            printf (" ");
        for ( k = 0; k < cnt; k++ )
            printf ("#");

        puts("");
        last--;
        cnt++;
    }
    return 0;
}
