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

int ans=0;

string s,t;cin>>s>>t;
int lent=int(t.size()),lens=int(s.size());
vector<int>black(lens);

for(int i=lens-1;i>=0;i--){
    if(s[i]==t[0]){
        //for(int i:black)cout<<i;cout<<endl;
        //cout<<i<<endl;
        int flag=2;
        for(int j=i,temp=0;temp<lent;j++,temp++){
            if(black[j]==1){//if(i==7)cout<<" if"<<j;
                temp--;
                continue;
            }else{//if(i==7)cout<<" else"<<j;
                if(s[j]!=t[temp]||(j==lens-1&&temp!=lent-1)){//cout<<"hey";
                    flag=3;
                    break;
                }
            }
        }
        if(flag==2){
            ans++;
            for(int j=i,temp=0;temp<lent;temp++,j++){
                if(black[j]==0){
                    black[j]=1;
                }else{
                    temp--;
                }
            }
        }
    }
}




//cout<<ans<<endl;
for(int i=0;i<lens;i++){
    if(black[i]==0){
        cout<<s[i];
    }
}
cout<<endl;

















}//




































int main()
{
    startTime=(double)clock();
    freopen("censor.in","r",stdin);
    freopen("censor.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
