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


vector<int>v(3);for(int &i:v)cin>>i;
deque<int>dq;
for(int i:v)dq.push_back(i);
for(int i:dq)cout<<i<<" ";cout<<endl;
int n=v.size();
long long ans=0;
sort(dq.begin(),dq.end());
cout<<dq.front()<<" "<<dq.back()<<endl;
while(dq.front()!=dq.back()){
    int diff=dq.back()-dq.front();
    ans+=diff;
    for(int i=0;i<n-1;i++){
        dq[i]+=diff;
    }
    //dq can be sorted by removing the last element and inserting it in the front
    int lastElement=dq.back();
    dq.pop_back();
    dq.push_front(lastElement);
}
cout<<int(ans)<<endl;











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
