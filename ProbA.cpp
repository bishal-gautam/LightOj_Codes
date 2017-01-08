#include <bits/stdc++.h>
using namespace std;

#define VISITED 1
#define UNVISITED 0
#define MX 200005

vector<int> graph[MX+5];
int n, level[MX+5], mx_node, mn_node;
bool vis[MX+5];

int bfs( int u ) {
    int i, sz, vmp=0, lyk=0, v;
    queue<int> myque;
    myque.push( u );
   // memset( level, 0, sizeof level );
    vis[u] = VISITED;
    level[u] = 1;
    vmp++;
    while( !myque.empty() ) {
        u = myque.front(), myque.pop();
        sz = graph[u].size();

        for(i=0; i<sz; i++) {
            v = graph[u][i];
            if( !vis[v] ) {
                myque.push(v);
                vis[v] = VISITED;
                if( level[u] == 1 ) level[v] = 2,lyk++;
                else level[v] = 1,vmp++;
            }
        }
    }
    return max( vmp, lyk );
}

void clearGraph() {
    for(int i=0; i<=n; i++) graph[i].clear();
}

main() {
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int cases, caseno = 0, i, j, a, b, sm;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d", &n);
        memset( level, 0, sizeof level );
        mx_node = INT_MIN, mn_node = INT_MAX;   //initialization
        clearGraph();
        for(i=0; i<n; ++i) {          //adjacency list
            scanf("%d %d", &a, &b);
            mx_node = max( mx_node, a );
            mx_node = max( mx_node, b );
            mn_node = min( mn_node, a );
            mn_node = min( mn_node, b );
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        memset( vis, 0, sizeof vis );
        for(i=mn_node, sm=0; i<=mx_node; i++) {
            if( !vis[i] && graph[i].size() ) {
                sm += bfs( i );
            }
        }

        printf("Case %d: %d\n", ++caseno, sm);
    }
}
