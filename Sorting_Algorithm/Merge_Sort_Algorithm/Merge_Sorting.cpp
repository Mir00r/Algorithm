#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 5
#define col 5
#define MAX 10000
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define MOD 7477777
#define PI 3.1415926535897932384626433832795
#define PrimeRange 1000000
#define CharRange 255
#define LIMIT 1000

int arr[ MAX ];

void Merge ( int beg, int mid, int end) {
    int i, j, k, indx = 0, cnt=0, tmp[ MAX ];

    i = beg;
    j = mid + 1;

    while ( i <= mid && j <= end ) {
        if ( arr[ i ] < arr[ j ] ) {
            tmp[ indx ] = arr[ i ];
            i++;
        }
        else {
            tmp[ indx ] = arr[ j ];
            j++;
        }
        indx++;
    }

    while ( i <= mid ) {
        tmp[ indx ] = arr[ i ];
        i++;
        indx++;
    }

    while ( j <= end ) {
        tmp[ indx ] = arr[ j ];
        j++;
        indx++;
    }

    for ( i = beg, k=0; i <= end; i++ ) {
        arr[ i ] = tmp[ k ];
        k++;
    }
}


void Divide ( int beg, int end ) {
    int mid;

    if ( end <= beg ) {
        return;
    }
    else {
        mid = ( beg + end ) / 2;

        Divide ( beg, mid );
        Divide ( mid + 1, end );
        Merge ( beg, mid, end );
    }
}



int main () {
    int n, i;

    scanf ("%d", &n);
    for ( i = 0; i < n; i++ ) scanf ("%d", &arr[ i ]);

    Divide ( 0, n - 1 );

    for ( i = 0; i < n; i++ ) printf ("%d ", arr[ i ]);
    NL;

    return 0;
}

