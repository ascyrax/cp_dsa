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


int a,b,n;cin>>a>>b>>n;
//cout<<a<<b<<n<<endl;
vector<int>va(n),vb(n);
vector<pair<int,int>>vp;
for(int &i:va)cin>>i;
for(int &i:vb)cin>>i;
for(int i=0;i<n;i++){
    vp.pb(make_pair(va[i],vb[i]));
}
//sort(va.rbegin(),va.rend());
//sort(vb.rbegin(),vb.rend());
int ptr1=0;
for(int i=1;i<n;i++){
    if(va[i]>va[i-1]){
        ptr1=i;
    }else if(va[i]==va[i-1]){
        ptr1=i;////////////////////////////////////////////solve
    }
}

if(n==1){
    int nattacks=vb[0]/a+min(vb[0]%a,1);
//    cout<<nattacks<<endl;
    if((nattacks-1)*va[0]<b){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}else{
    vector<int>vna;
    for(int i=0;i<n;i++){
        int na=vb[i]/a+min(vb[i]%a,1);
        vna.pb(na);
    }
    vector<pair<int,int>>eas;
    for(int i=0;i<n;i++){
        eas.pb(make_pair(vna[i]*va[i],i));
    }
//    sort(eas.rbegin(),eas.rend());
    int sum=0;
    for(int i=0;i<n;i++){
        if(i==ptr1)continue;
        sum+=eas[i].first;
    }
    if(sum+eas[0].first<=b){
        cout<<"YES"<<endl;
    }else{
        if(sum<b){
//            int ptr=eas[0].second;
            int nrounds=eas[0].first/va[ptr1];
            if((nrounds-1)*va[ptr1]<(b-sum)){
                if(nrounds*a>=vb[ptr1]){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            cout<<"NO"<<endl;
        }
    }
}























}//




































int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
