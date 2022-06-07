/*
ID: ascyrax1
TASK: test
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back

double startTime;
double gct()//get_current_time
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}
void suraj();




































void suraj(){///////////////////////

int x,n;cin>>x>>n;
set<int>slight;
slight.insert(0);slight.insert(x);
multiset<int>mslength;
mslength.insert(x);
//for(int i:mslength)cout<<i<<" ";cout<<endl;
//for(int i:slight)cout<<i<<" ";cout<<endl;
//cout<<"________________________________________"<<endl;
for(int i=0;i<n;i++){
    int light;cin>>light;

    int right=*slight.lower_bound(light);
    int left=*(--slight.lower_bound(light));
//    cout<<"left "<<left<<" right "<<right<<endl;
    slight.insert(light);
    mslength.insert(light-left);mslength.insert(right-light);
//    for(auto i:mslength)cout<<i<<" ";cout<<endl;
    mslength.erase(mslength.find(right-left));
//    for(auto i:mslength)cout<<i<<" ";cout<<endl;
//    for(auto i:slight)cout<<i<<" ";cout<<endl;
//    cout<<"------------------------------"<<endl;
    cout<<*(--mslength.end())<<endl;
}












}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
