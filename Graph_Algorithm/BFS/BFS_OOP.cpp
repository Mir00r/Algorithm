#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 5
#define col 5
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

class Graph{
    private:
        int vertices; // No of vertices
        vector < int > *AdjMat; // Pointer to an array containing adjacency list
    public:
        Graph ( int v );    // Constructor
        void AddEdge( int from, int to );    // function to add an edge to graph
        void BFS ( int start );  // prints BFS traversal of the complete graph
};

Graph::Graph ( int v ) { // Constructor to set the number of vertices
    this->vertices = v;
    AdjMat = new vector < int >[ v ];
}

void Graph::AddEdge ( int from, int to ) { // function to add an edge to Graph
    AdjMat[ from ].pb(to);
}


void Graph::BFS ( int start ){ // BFS Traverse of the vertices reachable from start
    bool *visited = new bool[ this->vertices ]();
    queue < int > Q;

    Q.push ( start );
    vector < int >::iterator it;

    puts ("BFS Started: ");

    while ( !Q.empty() ) {
        int front = Q.front();
        printf ("Queue front value -> %d ", front );
        Q.pop();
        NL;

        // Mark the Current node as a visited
        visited[ front ] = true;

        // iterat for all the vertices in the adjacency list
        for ( it = AdjMat[ front ].begin(); it != AdjMat[ front ].end(); it++ ) {
            if ( !visited[ *it ] )
                Q.push( *it );
        }
    }
    NL;
}



void Test_Input() {
    // Creat a graph to perform DFS
    Graph g( 4 );

    g.AddEdge ( 0, 1 );
    g.AddEdge ( 0, 2 );
    g.AddEdge ( 1, 2 );
    g.AddEdge ( 2, 0 );
    g.AddEdge ( 2, 3 );
    g.AddEdge ( 3, 3 );

    printf ("Following is Breadth First Traversal (startting from vertices 2) \n");
    g.BFS ( 2 );
}

int main () {

    Test_Input();

//    int ver, edge, i, j, s, d;
//
//    puts ("Enter number of Vertices: ");
//    scanf ("%d", &ver);
//    Graph g( ver );
//    NL;
//
//    puts ("Enter number of Edges: ");
//    scanf ("%d", &edge);
//    for ( i = 0; i < edge; i++ ) {
//        puts ("Enter edges relation from and to: ");
//        scanf ("%d %d", &s, &d);
//        g.AddEdge ( s, d );
//    }
//    NL;
//
//    int sr;
//    puts ("Enter source where DFS is starting: ");
//    scanf ("%d", &sr);
//    g.DFS ( sr );

    return 0;
}

