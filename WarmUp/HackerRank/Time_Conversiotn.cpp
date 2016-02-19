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
    int H, M, S;
    char ampm[3];

    scanf ("%d:%d:%d%s", &H, &M, &S, ampm);

    if ( !strcmp ( ampm, "PM" ) && H != 12 )
        H += 12;

    if ( !strcmp ( ampm, "AM" ) && H == 12 )
        H = 0;

    printf ("%02d:%02d:%02d\n", H, M, S);

    return 0;
}
