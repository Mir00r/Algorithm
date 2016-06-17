#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define row 10000
#define col 10000
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL -1
#define INF 2147482647

int adj[row][col];
int color[row];
int prev[row];
int dist[row];


int main(){
   int i, j, nv, ne, src, dst, u, v;
   printf("Enter Num. of Vertices & Edges : ");
   scanf("%d%d", &nv, &ne);
   for(i = 1; i <= ne; i++){
      printf("Enter Terminal Nodes: ");
      scanf("%d%d", &u, &v);
      adj[u][v] = 1;
   }
   printf("Enter Src and DST vertex: ");
   scanf("%d%d", &src, &dst);
//   BFS(nv, ne, src, dst);
  // PrintPath(src, dst);
   return 0;
}
