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
vector<int>v(n);for(int &i:v)cin>>i;
sort(v.begin(),v.end());

int ans=0;

for(int i=0;i<n;i++){
   int t=1;int sum=0;
   int curr=v[i];
   while(true){
       auto it=lower_bound(v.begin(),v.end(),curr+t);
       if(it==v.end()){
           it--;
           if(*it<=curr+t&&*it!=curr){
               curr=*it;t++;
           }else
               break;
       }
       else if(*it<=curr+t&&*it!=curr){
           curr=*it;t++;
       }else{
            it--;
            if(*it<=curr+t&&*it!=curr){
                curr=*it;t++;
            }else
                break;
       }
   }
   sum+=lower_bound(v.begin(),v.end(),curr)-lower_bound(v.begin(),v.end(),v[i])+1;
   t=1;//cout<<"sum"<<sum<<endl;
   curr=v[i];
   while(true){
       auto it=lower_bound(v.begin(),v.end(),curr-t);
       if(*it>=curr-t&&*it!=curr){
           t++;curr=*it;
       }else{
           break;
       }
   }
   sum+=lower_bound(v.begin(),v.end(),v[i])-lower_bound(v.begin(),v.end(),curr);
   //cout<<"sum"<<sum<<endl;
   ans=max(ans,sum);
}


cout<<ans<<endl;



}//
























int main()
{
    startTime=(double)clock();
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
