#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define endl "\n"
#define ioss ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back
#define eb emplace_back

double startTime;
double gct()//get_current_time
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}





























void suraj(){

int n,k;cin>>n>>k;
vector<vector<int>>arr;
for(int i=0;i<k;i++){
    vector<int>temp(k);
    arr.pb(temp);
}

for(int i=0;i<n;i++){
    vector<int>v(k);
    for(int j=0;j<k;j++){
        cin>>v[j];
    }
    for(int j=0;j<k;j++){
        for(int m=j;m<k;m++){
                arr[v[j]-1][v[m]-1]=1;
        }
    }

}
int ans=0;
for(int i=0;i<k;i++){
    for(int j=0;j<k;j++){
        if(arr[i][j]==1&&arr[j][i]==0)
            ans++;
    }
}

cout<<ans<<endl;

}//
























int main()
{
    startTime=(double)clock();
    freopen("gymnastics.in","r",stdin);
    freopen("gymnastics.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
