/*
ID: ascyrax1
TASK: test
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back

double startTime;
double gct()//get_current_time
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}
void suraj();















int r,c;
vector<string>grid(1000);
vector<vector<bool>>visited(1000);




void flood_fill(int i,int j,char ch){
    if(i<0||i>=r||j<0||j>=c)return;
    if(grid[i][j]!=ch)return;
    if(visited[i][j])return;
    else{
        visited[i][j]=true;
        flood_fill(i,j+1,ch);
        flood_fill(i,j-1,ch);
        flood_fill(i-1,j,ch);
        flood_fill(i+1,j,ch);
        return;
    }
}














void suraj(){///////////////////////
int rooms=0;
cin>>r>>c;
grid.resize(r);
visited.resize(r);
for(int i=0;i<r;i++){
    vector<bool>temp(c);
    visited[i]=temp;
}
for(int i=0;i<r;i++){
    string row;cin>>row;
    grid[i]=row;
}

//for(int i=0;i<r;i++){
//    for(int j=0;j<c;j++){
//        cout<<visited[i][j]<<" ";
//    }cout<<endl;
//}



for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        if(!visited[i][j]&&grid[i][j]=='.'){
            rooms++;
            flood_fill(i,j,'.');
        }
    }
}

cout<<rooms<<endl;




//for(int i=0;i<r;i++){
//    for(int j=0;j<c;j++){
//        cout<<visited[i][j]<<" ";
//    }cout<<endl;
//}



}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
