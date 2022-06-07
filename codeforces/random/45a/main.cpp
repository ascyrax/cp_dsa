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

string s;cin>>s;
int n;cin>>n;
vector<string>months={"January","February","March","April","May",
"June","July","August","September","October","November","December"};
map<int,string>is;
map<string,int>si;
for(int i=0;i<12;i++){
    si[months[i]]=i;
    is[i]=months[i];
}
int a=si[s];
a+=n;
a=a%12;
cout<<is[a]<<endl;




}//
























int main()
{
    startTime=(double)clock();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt,"w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
