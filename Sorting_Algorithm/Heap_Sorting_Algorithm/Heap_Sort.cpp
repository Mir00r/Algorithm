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


// Tutorial link -> http://geeksquiz.com/heap-sort/

void HeapiFy ( int arr[], int HS, int pindx ) {
    int left, right, maxn;

    maxn = pindx;           // Initialize largest as root
    left = pindx * 2 + 1;      // left child
    right = pindx * 2 + 2;  // right child

    // if left child is larger then root
    if ( left < HS && arr[ left ] > arr[ maxn ] )
        maxn = left;

    // If right child is larger than largest so far
    if ( right < HS && arr[ right ] > arr[ maxn ] )
        maxn = right;

    // If largest is not root
    if ( maxn != pindx  ) {
        swap ( arr[ pindx ], arr[ maxn ] );
        HeapiFy ( arr, HS, maxn );  // Recursively heapify the affected sub-tree
    }
}


void Heap_Sort ( int arr[], int HS ) {
    int Pindx, i, j;

    // Build heap rearrange array
    for ( i = HS / 2 - 1; i >= 0; i-- )
        HeapiFy ( arr, HS, i );

    //  One by one extract an element from heap
    for ( i = HS - 1; i >= 0; i-- ) {
        swap ( arr[ 0 ], arr[ i ] );    // Move current root to end
        HeapiFy ( arr, i, 0 );           // call max heapify on the reduced heap
    }
}

int main () {
    int arr[ MAX ], i, n;
    scanf ("%d", &n);
    for (i = 0; i < n; i++ ) scanf ("%d", &arr[ i ]);

    Heap_Sort ( arr, n );

    for ( i = 0; i < n; i++) printf ("%d ", arr[ i ]);
    NL;

    return 0;
}
