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
    int t;cin>>t;
    for(int e=0;e<t;e++){
int n;cin>>n;
string s;cin>>s;
while(s.size()!=1){
    int flag=0;
for(int i=0;i<s.size();i++){
    if(s.substr(i,3)=="AAB"||s.substr(i,3)=="ABA"||s.substr(i,3)=="BAA"){
        s.replace(i,3,"A");flag=1;
    }
    else if(s.substr(i,3)=="ABB"||s.substr(i,3)=="BAB"||s.substr(i,3)=="BBA"){
        s.replace(i,3,"B");flag=1;
    }
}
if(flag==0)break;
}
cout<<"Case #"<<e+1<<": ";
if(s.size()==1)cout<<"Y"<<endl;
else cout<<"N"<<endl;

    }



}//
























int main()
{
    startTime=(double)clock();
    freopen("bfin.txt","r",stdin);
    freopen("bfout.txt","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
