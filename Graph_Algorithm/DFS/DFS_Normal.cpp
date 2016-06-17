#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 5
#define col 5
#define MAX 100000
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




struct Vertex {
    char label;
    bool visited;
};


//array of vertices
struct Vertex* list_vertices[ row ];

//adjacency matrix
int adjMatrix[ row ][ col ];

//vertex count
int vertex_cnt;


//add vertex to the vertex list
void addVertex(char label) {
    struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
    //vertex_cnt = 0;

    vertex->label = label;
    vertex->visited = false;
    list_vertices[ vertex_cnt++ ] = vertex;
}

//add edge to edge array
void AddEdge(int start,int end) {
    adjMatrix[ start ][ end ] = 1;
    adjMatrix[ end ][ start ] = 1;
}

//display the vertex
void Display_Ver ( int vertex_indx ) {
    printf("%c ",list_vertices[ vertex_indx ]->label);
}

//get the adjacent unvisited vertex
int getAdjUn_Visited_Ver ( int vertex_indx ) {
    int i;

    for( i = 0; i < vertex_cnt; i++ ) {
        if( adjMatrix[ vertex_indx ][ i ] == 1 && list_vertices[ i ]->visited == false) {
            return i;
        }
    }
    return -1;
}

void DFS () {
    int i;
    stack < int > st;

    //mark first node as visited
    list_vertices[0]->visited = true;

    //display the vertex
    Display_Ver(0);

    //push vertex index in stack
    st.push(0);

    while( !st.empty() ) {
      //get the unvisited vertex of vertex which is at top of the stack
        int Un_Visited_Ver = getAdjUn_Visited_Ver( st.top() );

      //no adjacent vertex found
        if( Un_Visited_Ver == -1) {
            st.pop();
        }
        else {
            list_vertices[ Un_Visited_Ver ]->visited = true;
            Display_Ver( Un_Visited_Ver );
            st.push( Un_Visited_Ver );
        }
    }

    //stack is empty, search is complete, reset the visited flag
    for( i = 0; i < vertex_cnt; i++ ) {
        list_vertices[ i ]->visited = false;
    }
}


void Test_Input () {
    int i, j;

    for(i = 0; i < row; i++) { // set adjacency {
      for(j = 0; j < col; j++) // matrix to 0
         adjMatrix[ i ][ j ] = 0;
    }

    addVertex('S');   // 0
    addVertex('A');   // 1
    addVertex('B');   // 2
    addVertex('C');   // 3
    addVertex('D');   // 4

    AddEdge(0, 1);    // S - A
    AddEdge(0, 2);    // S - B
    AddEdge(0, 3);    // S - C
    AddEdge(1, 4);    // A - D
    AddEdge(2, 4);    // B - D
    AddEdge(3, 4);    // C - D

    printf("Depth First Search: ");

    DFS();
}


int main() {
    Test_Input();

    return 0;
}
