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


void Insertion_Sort ( int arr[], int n ) {
    int value = 0, hole = 0, i, j;

    for ( i = 1; i < n ; i ++ ) {
        value = arr[ i ];  // ith postion; elements from i till n - 1 are candidates
        hole = i;
       // printf ("I -> %d Value -> %d Hole -> %d\n", i, value, hole);
        while ( hole > 0 && arr[ hole - 1 ] > value ) {
            arr[ hole ] = arr[ hole - 1 ];
            hole = hole - 1;
        }
        // then finally store the value in array
        arr[ hole ] = value;
    }
}

int main () {
    int arr[ MAX ], i, j, tmp, n;
    scanf ("%d", &n);
    for (i = 0; i < n; i++ ) scanf ("%d", &arr[ i ]);

    Insertion_Sort ( arr, n );

    for ( i = 0; i < n; i++) printf ("%d ", arr[ i ]);
    NL;

    return 0;
}
