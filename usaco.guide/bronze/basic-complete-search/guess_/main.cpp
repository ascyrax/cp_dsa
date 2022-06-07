#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define all(x)  x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)(x).size()
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
vector<string>props[n];
map<string,int>mprops;
for(int i=0;i<n;i++){
    string animal;cin>>animal;
    int k;cin>>k;

    for(int j=0;j<k;j++){
        string prop;cin>>prop;
        props[i].pb(prop);
    }

    for(auto i:props[i]){
        mprops[i]+=1;
    }
}
////for(auto key:mprops){
//////    cout<<key.first<<" "<<key.second<<endl;
////}
////for(int i=0;i<n;i++){
////    for(auto j:props[i]){
//////        cout<<mprops[j]<<" ";
////    }cout<<endl;
////}

//vector<int>vcnt;
//for(int i=0;i<n;i++){
//    int cnt=0;
//    for(auto j:props[i]){
//        if(mprops[j]>1){
//            cnt++;
//        }
//    }
//    vcnt.pb(cnt);
//}
//sort(vcnt.rbegin(),vcnt.rend());
//cout<<vcnt[0]+1<<endl;

int ans=0;

for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){int cnt=0;
        for(int k=0;k<props[i].size();k++){
            for(int l=0;l<props[j].size();l++){

                if(props[i][k]==props[j][l]){
                    cnt++;
//                    if(i==1&&j==3){
//                        cout<<props[i][k]<<" "<<props[j][l]<<endl;
//                    }
                }
            }
        }//cout<<i<<" "<<j<<" "<<cnt<<endl;
        ans=max(ans,cnt);
    }

}
cout<<ans+1<<endl;

















}//




































int main()
{
    startTime=(double)clock();
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
