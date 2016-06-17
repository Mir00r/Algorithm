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

void BFS(int nv, int ne, int src, int dst)  // BFS(G) starts from here
{
   int u, v;
   for(u = 1; u <= nv; u++)   // for each vertex u  V-{s}
   {
        color[u] = WHITE;      // initialize
        prev[u] = NIL;
        dist[u] = INF;
   }

   color[src] = GRAY;
   dist[src] = 0;
   prev[src] = NIL;

   queue <int> Q;  // Decleare Queue Variable
   Q.push(src);    // Insert value / ENQUEUE(Q,s);
   while(!Q.empty())   // Check While(Q not empty)
   {
      u = Q.front();  // u = DEQUEUE(Q);
      Q.pop();
      for(v = 1; v <= nv; v++)   // for each v  adj[u]
      {
         if(adj[u][v] == 1)   // when discover vertex
         {
            if(color[v] == WHITE)
            {
               color[v] = GRAY;
               dist[v] = dist[u] + 1;
               prev[v] = u;
               Q.push(v);
            }
         }
         color[u] = BLACK;
      }
   }
}

void PrintPath(int s, int v){
	if(v == s)
		printf("%d ", s);
    else if(prev[v] == NIL)
		printf("No path");
    else{
		PrintPath(s, prev[v]);
		printf("%d ", v);
	}
}

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
   BFS(nv, ne, src, dst);
   PrintPath(src, dst);
   return 0;
}
