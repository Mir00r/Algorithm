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

Tutorial Link -> http://www.geeksforgeeks.org/radix-sort/

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n){
    int mx = arr[0], i;
    for ( i = 1; i < n; i++ )
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp){
    int output[n]; // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for ( i = 0; i < n; i++ )
        count[ (arr[i]/exp)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for ( i = 1; i < 10; i++ )
        count[i] += count[i - 1];
 
    // Build the output array
    for ( i = n - 1; i >= 0; i-- ){
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for ( i = 0; i < n; i++ )
        arr[i] = output[i];
}
 
// The main function to that sorts arr[] of size n using 
// Radix Sort
void radixsort(int arr[], int n){
    // Find the maximum number to know number of digits
    int m = getMax(arr, n), exp;
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for ( exp = 1; m/exp > 0; exp *= 10 )
        countSort(arr, n, exp);
}
 
// A utility function to print an array
void print(int arr[], int n){
    for ( int i = 0; i < n; i++ )
        printf ("%d ", arr[ i ] );
    NL;
}
 
// Driver program to test above functions
int main(){
    int arr[ MAX ] , n, i;
    scanf ("%d", &n);
    for ( i = 0; i < n; i++ ) scanf ("%d", &arr[ i ]);
    radixsort(arr, n);
    print(arr, n);
    return 0;
}
