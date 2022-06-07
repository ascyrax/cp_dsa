
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
int n;cin>>n;string s;cin>>s;
int lens=n;
int ans=0;int flag=0;
bool found=false;
for(int i=1;i<=n;i++){///////

flag=0;
    for(int j=0;j<n;j++){//
        string a=s.substr(j,i);
        for(int k=j+1;k<n;k++){
            string b=s.substr(k,i);
            if(a==b){
                ans=i+1;flag=1;found=true;break;
            }
        }
        if(flag==1){break;}
    }//

    if(flag==0)break;

}//////
cout<<ans<<endl;




}//
























int main()
{
    startTime=(double)clock();
    freopen("whereami.in","r",stdin);
    freopen("whereami.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
