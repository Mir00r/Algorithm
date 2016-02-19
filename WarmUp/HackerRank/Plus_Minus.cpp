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
    int n, i, arr[MAX], pos=0, neg=0, zero=0;

    scanf ("%d", &n);

    for (i = 0; i < n; i++)
        scanf ("%d", &arr[i]);

    for ( i = 0 ; i < n; i++ ){
        if ( arr[i] == 0)
            zero++;
        else if ( arr[i] < 0 )
            neg++;
        else
            pos++;
    }

   // printf ("%d %d %d\n", pos, neg, zero);

    double p = double (pos) / double (n);
    double ne = double (neg) / double (n);
    double z = double (zero) / double (n);

    printf ("%.6lf\n%.6lf\n%.6lf\n", p, ne, z);

    return 0;
}
