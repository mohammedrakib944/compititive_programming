#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

#define MX 110

vector<int> graph[MX];
bool vis[MX];
int dist[MX];

void bfs(int source){
    queue<int> Q;
    ///initilizion
    vis[source] = 1;
    dist[source] = 0;
    Q.push(source);

    while(!Q.empty()){
        int node = Q.front();
        Q.pop();

        //visit nodes for the source node
        for(int i=0; i< graph[node].size(); i++){
            int next = graph[node][i];
            if(vis[next]==0){
                vis[next] = 1; //visit
                dist[next] = dist[node] + 1; //update distance
                Q.push(next); //than push in queue
            }
        }
    }
}

int main(){

    ///input graph
    int nodes, edges;
    cin>>nodes>>edges;

    for(int i=1; i<=edges; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    //input finish graph

    int source;
    cin>>source;
    bfs(source);

    cout<<"From node "<<source<<endl;

    for(int i=1; i<=nodes; i++){
        cout<<"Distance of "<<i<<"  is : "<<dist[i] <<endl;
    }

return 0;
}
