// Auther:  Abdur Razzak
// Email:   abdur.razzaq06@gmail.com

#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 205
#define col 205
#define MAX 100006
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define mod 7477777
#define PI 3.1415926535897932384626433832795

vector <int> G[MAX];
int visited[MAX], level[MAX];
int parent[MAX];
int n, m;
int fastiv[MAX];

int bfs( int src, int des ){
    int u, v, i;
    queue <int> Q;
    Q.push(src);

    visited[src] = 1;
    level[src] = 0;
    while(!Q.empty()){

        u = Q.front();
        for( i = 0; i < G[u].size(); i++){

            v = G[u][i];
            if( !visited[v] ){

                level[v] = level[u] + 1;
                parent[v] =  u;
                visited[v] =  1;
                Q.push(v);
            }
        }
        Q.pop();
    }
    return level[des];
}



int main (){
    int i, j, Ai, Bi, Qi, Ci, indx=1, ans[MAX], c=0;
    fastiv[0] = 1;
    bool check ;
    scanf ("%d %d", &n, &m);

    for (i = 0 ; i < n-1; i++){
        scanf ("%d %d", &Ai, &Bi);
        G[Ai].pb(Bi);
        G[Bi].pb(Ai);
    }

    for (i = 0; i < m; i++){
        scanf ("%d %d", &Qi, &Ci);

        if (Qi == 1){
            fastiv[indx++] = Ci;
        }
        else  {
            for ( j = 0; j < indx; j++ ) {
                int a = fastiv [ j ] ;
                ans [ c++ ] = bfs (a, Ci);
                memo (visited, 0);
                memo (level, 0);

            }
            sort (ans, ans + c);
            printf ("%d\n",  ans[0]);
        }
        c = 0;
    }
    return 0;
}



