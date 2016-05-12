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
    int arr[ MAX ], i, n;
    scanf ("%d", &n);
    for (i = 0; i < n; i++ ) scanf ("%d", &arr[ i ]);

    Bucket_Sort ( arr, n );

    return 0;
}





//another way from GeeksforGeeks

// Function to sort arr[] of size n using bucket sort
void bucketSort(float arr[], int n)
{
    // 1) Create n empty buckets
    vector<float> b[n];
    
    // 2) Put array elements in different buckets
    for (int i=0; i<n; i++)
    {
       int bi = n*arr[i]; // Index in bucket
       b[bi].push_back(arr[i]);
    }
 
    // 3) Sort individual buckets
    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());
 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
          arr[index++] = b[i][j];
}
 
/* Driver program to test above funtion */
int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, n);
 
    cout << "Sorted array is \n";
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
}
