#include <bits/stdc++.h>
using namespace std;
int killer=0;
int killerof[1001][1001];
int n,m;
vector<string>v;

bool dead[1001][1001];
map<int,int>killsof;

void dfs(int i,int j){
    if(i<0||j<0||i>=n||j>=m){
        return;
    }
    if(dead[i][j]==true)
        return;
    if(v[i][j]=='*')
        return;
    dead[i][j]=true;
    killsof[killer]++;
    killerof[i][j]=killer;
    dfs(i-1,j);dfs(i+1,j);dfs(i,j+1);dfs(i,j-1);

}


void suraj(){

cin>>n>>m;
for(int i=0;i<n;i++){
    string a;cin>>a;v.push_back(a);
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(v[i][j]=='.'&&(dead[i][j]==false)){
            killer++;
            dfs(i,j);
        }
    }
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(v[i][j]=='.')cout<<".";
        else{
            int ans=1;
            set<int>s;
            s.insert(killerof[i+1][j]);
            if(i-1>=0)
            s.insert(killerof[i-1][j]);
            s.insert(killerof[i][j+1]);
            if(j-1>=0)
            s.insert(killerof[i][j-1]);
            for(int i:s){
                ans+=killsof[i];
            }
            cout<<ans%10;
        }
    }
    cout<<endl;
}



}//

int main()
{   suraj();
    return 0;
}
