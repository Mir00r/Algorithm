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

int gona[102], arr[MAX], n;


int partition (int beg, int end){
    int st_ind, pivot, i;
    int size = (end-beg) + 1;

    pivot = (rand() % size) + beg;
    swap (arr[pivot], arr[end]);
    st_ind = beg;

    for (i = beg; i < end; i++){
        if (arr[i] < arr[end]){
            swap (arr[st_ind], arr[i]);
            st_ind++;
        }
    }

    swap (arr[end], arr[st_ind]);
    return st_ind;
}

void qk_srt(int beg, int end){
    int pivot;

    if (beg >= end) return;

    pivot = partition(beg, end);
    printf ("Pvot = %d\n", pivot);

    qk_srt(beg, pivot-1);
    qk_srt(pivot+1, end);
}

int main(){
    int i, j, cnt, ans;
    while (scanf ("%d", &n) == 1){
        if (n == 0) break;

        for (i = 0; i < n; i++)
            scanf ("%d", &arr[i]);

        qk_srt(0, n-1);

        for (i = 0; i < n; i++)
            printf ("%d ", arr[i]);
        NL;
    }
    return 0;
}


/*
int Partiiotn ( char str[], int st, int ed ) {
    char x = str[ ed ];
    int i = ( st - 1 );
    int j;

    for ( j = st; j < ed; j++ ) {
        if ( str[ j ] <= x ) {
            i++;
            swap ( str[ i ], str[ j ] );
        }
    }
    swap ( str[ i + 1], str[ ed ] );
    return ( i + 1 );
}


void QuickSort ( char str[], int st, int ed ) {
    int perti;

    if ( st < ed ) {
        perti = Partiiotn( str, st, ed );
        QuickSort ( str, st, perti - 1 );
        QuickSort ( str, perti + 1, ed );
    }
}



*/

/*

int partition (int beg, int end){
    int i, pivot, par_ind, ans=0;;

    pivot = arr[end];
    par_ind = beg;  // set partition index as start initially

    for (i = beg; i < end; i++){
        if (arr[i] <= pivot){
            ans++;
            swap (arr[i], arr[par_ind]);    // swap if element is leser then pivot
            par_ind++;
        }
    }

    swap (arr[par_ind], arr[end]);

    return par_ind;
}


void qk_sort (int beg, int end){
    int par_indx;

    if (beg < end){
        par_indx = partition (beg, end);
        qk_sort (beg, par_indx - 1);
        qk_sort (par_indx + 1, end);
    }

}

*/
