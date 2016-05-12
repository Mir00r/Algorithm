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


void Bucket_Sort ( int arr[], int n ) {
    int i, j;
    int bucket[ MAX ];

    // initsialize the bucket array
    //memo ( bucket, 0 );
    for ( i = 0; i < MAX; i++ )
        bucket[ i ] = 0;

    // count the number of element occurse
    for ( i = 0; i < n; i++ )
        bucket[ arr[ i ] ]++;

    // print all the indexes number
    for ( i = 0; i < MAX; i++ ) {
        for ( j = 0; j < bucket[ i ]; j++ )
            printf ("%d ", i );
    }
    NL;
}

int main () {
    int arr[ MAX ], i, j, k, tmp, n;
    scanf ("%d", &n);
    for (i = 0; i < n; i++ ) scanf ("%d", &arr[ i ]);

    //Bucket_Sort ( arr, n );
    for ( i = n / 2; i > 0; i /= 2 ) {
        for ( j = i; j < n; j++ ) {
            tmp = arr[ j ];
            for ( k = j - i; k >= 0; k -= i ) {
                if ( tmp < arr[ k ] )
                    arr[ k + i ] = arr[ k ];
                else
                    break;
            }
            arr[ k + i ] = tmp;
        }
    }

    for ( i = 0; i < n; i++) printf ("%d ", arr[ i ]);
    NL;
    return 0;
}
