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























bool priority_sort(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
    if(a.second.first>b.second.first)
        return true;
    else return false;
}












void suraj(){///////////////////////


int n;cin>>n;
set<pair<int,int>>waiting;
vector<pair<int,pair<int,int>>>vfirst;
vector<int>va(n),vt(n);
for(int i=0;i<n;i++){
    int a,t;cin>>a>>t;
    va[i]=a;vt[i]=t;
    vfirst.pb(make_pair(a,make_pair(i,t)));//i represents priority..smaller the i higher the priority
}
sort(vfirst.begin(),vfirst.end());
for(auto i:vfirst){
    cout<<i.first<<" "<<i.second.second<<" "<<i.second.first<<endl;
}
int maxwait=0;
//vfirst sorted according to who arrived first and then sorted acc to priority and then time they take for sampling
int waittill=vfirst[0].first+vfirst[0].second.second;
vector<int>temp;
for(int i=1;i<n;i++){
    int arrival=vfirst[i].first;
    if(arrival<=waittill){
        temp.pb(i);
    }else{
        sort(vfirst.begin()+temp[0],vfirst.begin()+temp[int(temp.size())-1],priority_sort);
        temp.clear();
    }
}
cout<<maxwait<<endl;












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
