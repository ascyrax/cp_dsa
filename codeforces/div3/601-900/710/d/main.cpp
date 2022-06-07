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

int n;cin>>n;
//vector<int>v(n);for(int &i:v)cin>>i;

//sort(v.begin(),v.end());
//int left=0;int right=n-1;
//int ans=n;
//while(v[left]!=v[right]&&left<right){
//    left++;right--;ans-=2;
//}
//cout<<ans<<endl;
map<int,int>m;
for(int i=0;i<n;i++){
    int a;cin>>a;
    m[a]++;
}
int maxCount=0;
for(auto el:m){
    maxCount=max(maxCount,el.second);
}
int ans=0;
if(n%2==0){
    int others=n-maxCount;
    ans=max(0,maxCount-others);
}else{
    int others=n-maxCount;
    if(maxCount>n/2){
        maxCount--;
        ans=max(0,maxCount-others)+1;
    }else{
        ans=1;
    }
}
cout<<ans<<endl;






}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
