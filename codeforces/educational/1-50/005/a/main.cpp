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
string a,b;cin>>a>>b;
int lena=a.size();int lenb=b.size();
int i=0;
for(i=0;i<lena;i++){
    if(a[i]!='0')break;
}
a=a.substr(i);
for(i=0;i<lenb;i++){
    if(b[i]!='0')break;
}
b=b.substr(i);
lena=a.size();lenb=b.size();
if(lena>lenb)cout<<">"<<endl;
else if(lena<lenb)cout<<"<"<<endl;
else{
    if(a==b)cout<<"="<<endl;
    else if(a<b)cout<<"<"<<endl;
    else if(a>b)cout<<">"<<endl;
}



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
