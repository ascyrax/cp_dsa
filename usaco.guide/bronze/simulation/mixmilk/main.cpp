#include <bits/stdc++.h>
#include <cstdio>
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
vector<int>size(3),con(3);
for(int i=0;i<3;i++){
    cin>>size[i]>>con[i];
}
int ptr=0;
for(int i=0;i<100;i++){
    int a=min(con[ptr],size[(ptr+1)%3]-con[(ptr+1)%3]);
    con[ptr]-=a;
    con[(ptr+1)%3]+=a;
    ptr++;
    ptr=ptr%3;
}
for(int i:con)cout<<i<<endl;




}//
























int main()
{
    startTime=(double)clock();
    freopen("mixmilk.in","r",stdin);
    freopen("mixmilk.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
