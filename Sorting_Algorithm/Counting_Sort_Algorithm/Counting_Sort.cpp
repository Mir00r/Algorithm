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


void Count_Sort ( int arr[], int n ) {
    int i, cnt = 0;

    int count[ MAX ];
    int tmp[ MAX ];

    for ( i =0; i < n; i++ )
        count[ arr[ i ] ]++; // number of element occurence counting

    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for ( i = 1; i < MAX; i++ )
        count[ i ] = count[ i - 1 ] + count[ i ];

    // inserting the largest elemetn in tmp array
    for ( i = n - 1; i >= 0; i-- ) {
        tmp[ count[ arr[ i] ] ] = arr[ i ];
        count[ arr[ i ] ]--;
    }

    // finally update our required array
    for ( i = 0; i < MAX; i++ ) {
        if ( tmp[ i ] > 0 )
            arr[ cnt++ ] = tmp[ i ];
    }
}

int main () {
    int arr[ MAX ], i, n;
    scanf ("%d", &n);
    for (i = 0; i < n; i++ ) scanf ("%d", &arr[ i ]);

    Count_Sort ( arr, n );

    for ( i = 0; i < n; i++) printf ("%d ", arr[ i ]);
    NL;

    return 0;
}

