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
multiset<int>ms;
ms.insert(2);
ms.insert(3);
ms.insert(4);
ms.insert(4);
ms.insert(4);
ms.insert(7);
ms.insert(5);
ms.insert(6);
for(int i:ms)cout<<i<<" ";cout<<endl;
auto it=ms.upper_bound(4);
cout<<*(--it)<<endl;
it++;
cout<<*(it)<<endl;
cout<<*(++it)<<endl;















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
