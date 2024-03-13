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




































void suraj(){///////////////////////


//cout<<"....................................."<<endl;

int n,m;cin>>n>>m;//n cities       m travellers
vector<int>a(n);for(int &i:a)cin>>i;
vector<int>b(m);for(int &i:b)cin>>i;

vector<int>right(n);
int nearestRightTravellinTrain=-1;
for(int i=0;i<n;i++){
    if(a[i]==1){
        nearestRightTravellinTrain=i;
    }
    if(nearestRightTravellinTrain==-1)right[i]=-1;
    else
    right[i]=i-nearestRightTravellinTrain;
}


vector<int>left(n);
int nearestLeftTravellinTrain=-1;
for(int i=n-1;i>=0;i--){
    if(a[i]==2){
        nearestLeftTravellinTrain=i;
    }
    if(nearestLeftTravellinTrain==-1)left[i]=-1;
    else
    left[i]=nearestLeftTravellinTrain-i;
}

vector<int>fastestTrain(n);
for(int i=0;i<n;i++){
    if(left[i]==-1 && right[i]==-1)
        fastestTrain[i]=-1;
    else if(left[i]==-1)
        fastestTrain[i]=right[i];
    else if(right[i]==-1)
        fastestTrain[i]=left[i];
    else
    fastestTrain[i]=min(left[i],right[i]);
}
//for(int i:right)cout<<i<<" ";cout<<endl;
//for(int i:left)cout<<i<<" ";cout<<endl;
//for(int i:fastestTrain)cout<<i<<" ";cout<<endl;
for(int i=0;i<m;i++){
    if(b[i]==1)cout<<0<<" ";
    else
    cout<<fastestTrain[b[i]-1]<<" ";
}cout<<endl;
}////////////////////////////
























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
