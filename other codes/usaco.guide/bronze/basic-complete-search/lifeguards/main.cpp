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

int n;cin>>n;
vector<pair<int,int>>v(n);
for(auto &i:v)cin>>i.first>>i.second;
if(n==2){
    cout<<max(v[1].second-v[1].first,v[0].second-v[0].first)+1<<endl;return;
}else if(n==1){
    cout<<v[0].second-v[0].first+1<<endl;return;
}
int ans=0;
for(int i=0;i<n;i++){
    int l,r;
    if(i==n-1){
         l=v[i-1].first;
         r=v[i-1].second;
    }else{
         l=v[i+1].first;
         r=v[i+1].second;
    }
    vector<int>temp(2005);
    for(int j=0;j<n;j++){
        if(i==j)continue;
        else{
            for(int k=2*v[j].first;k<=2*v[j].second;k++){
                temp[k]=1;
            }
        }
    }
   // for(int m=0;m<=30;m++){
       // cout<<temp[m]<<" ";
   // }cout<<endl;
    int temp2=0;int cnt=0;
    for(int k=0;k<=temp.size();k++){
        if(temp[k]==1)cnt++;
        else{
            temp2=max(temp2,cnt);cnt=0;
        }
    }
    ans=max(ans,temp2);
}
cout<<(ans+1)/2<<endl;



}//













int main()
{






    startTime=(double)clock();
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();





    //suraj3();
    //suraj4();
    return 0;
}
