#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 105
#define col 105
#define MAX 100000 + 5
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


void Selection_Sort ( int arr[], int n ) {
    int iminx = 0, tmp = 0, i, j;

    for ( i = 0; i < n - 1; i ++ ) {
        iminx = i;  // ith postion; elements from i till n - 1 are candidates
        for ( j = i + 1; j < n; j++ ) {
            if ( arr[ j ] < arr[ iminx ] )
                iminx = j; // update the index of minimum element
        }
        // then just swap the element
        tmp = arr[ i ];
        arr[ i ] = arr[ iminx ];
        arr[ iminx ] = tmp;
    }
}

int main () {
    int arr[ MAX ], i, j, tmp, n;
    scanf ("%d", &n);
    for (i = 0; i < n; i++ ) scanf ("%d", &arr[ i ]);

    Selection_Sort ( arr, n );

    for ( i = 0; i < n; i++) printf ("%d ", arr[ i ]);
    NL;

    return 0;
}

