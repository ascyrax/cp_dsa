//METHOD 1
//I used dfs(depth-first search) to color all the nodes with two different colors.
//And then i found all the new edges that can be formed between any two nodes of
//different colors. How i did this was---->>>> i summed up the total no of blue and red nodes. Now for each node,
//we can just ignore its neighbors(i.e the node with which it already has an existing edge) because a node cannot form new edges with its neighbors
//and hence the no of new edges that a particular node can form is = (total no of nodes of opposite colors) - (total no of nodes of opposite color adjacent to it, i.e. its neighbors)
//Note:- each new node will get counted twice. So ans/2.  :)

//METHOD2
//The tree itself is bipartite so we can run a dfs to partition the tree into the 2 sets (called bicoloring),
//We can't add an edge between any 2 nodes in the same set and we can add an edge between every 2 nodes in different sets,
//so let the number of nodes in the left set be l and the number of nodes in the right set be r, The maximum number of edges that can exist is l * r,
//but n - 1 edges already exist so the maximum number of edges to be added is l * r - (n - 1).













#include <bits/stdc++.h>

using namespace std;

typedef  long long ll;
typedef long double ld;

#define endl "\n"
#define ioss ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back



void suraj();

int main()
{
    ioss
    suraj();
    return 0;
}


int n;
vector<vector<int>>graph(100000);
char col='r';
vector<bool>visited(100000);
vector<char>color(100000);





void dfs(int node,char col){
    if(visited[node]){
        return;
    }else{
        visited[node]=true;
        color[node]=col;
        if(col=='r')col='b';
        else col='r';
        for(int neigh:graph[node]){
            dfs(neigh,col);
        }
        return;
    }
}













void suraj(){///////////////////////


cin>>n;
graph.resize(n);
visited.resize(n);
color.resize(n);

for(int i=0;i<=n-2;i++){
    int a,b;cin>>a>>b;
    graph[a-1].pb(b-1);
    graph[b-1].pb(a-1);
}

for(int i=0;i<n;i++){
    if(visited[i]){
        continue;
    }else{
        dfs(i,col);
    }
}
int blue=0,red=0;
for(int i=0;i<n;i++){
    if(color[i]=='b')blue++;
    else red++;
}
ll ans=0;
for(int i=0;i<n;i++){
    int tblue=0,tred=0;
    for(int neigh:graph[i]){
        if(color[neigh]=='b')tblue++;
        else tred++;
    }
    if(color[i]=='b'){//blue
        ans+=(red-tred);
    }else{//red
        ans+=(blue-tblue);
    }
}
cout<<ans/2<<endl;








}////////////////////////////























