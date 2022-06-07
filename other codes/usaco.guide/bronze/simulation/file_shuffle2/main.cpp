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
vector<int>a(n);for(int &i:a){cin>>i;--i;}
vector<int>rev(n);
for(int i=0;i<n;i++){
    int j=i;int k=a[i];
    rev[k]=j;
}
vector<int>id(n);for(int &i:id)cin>>i;
vector<int>one(n),two(n),three(n);
for(int i=0;i<n;i++){
    int b=rev[i];
    one[b]=id[i];
}
for(int i=0;i<n;i++){
    two[rev[i]]=one[i];
}
for(int i=0;i<n;i++){
    three[rev[i]]=two[i];
}

for(int i:three)cout<<i<<endl;

}//
























int main()
{
    startTime=(double)clock();
    freopen("file shuffle.in","r",stdin);
    freopen("file shuffle.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
