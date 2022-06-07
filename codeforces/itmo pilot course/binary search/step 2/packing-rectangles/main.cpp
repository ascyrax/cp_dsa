// @author: ascyrax

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































bool check(ll w,ll h,ll n,ll side){
    //square is side*side
    ll a=side/w;
    ll b=side/h;
    if(a*b>=n)return true;else return false;
}




void suraj(){///////////////////////

ll w,h,n;cin>>w>>h>>n;

ll left=0,right=1;
while(!check(w,h,n,right)){
    right*=2;
}
ll mid=(left+right)/2;
while(left<right){
    mid=(left+right)/2;
//    cout<<left<<" "<<right<<" "<<mid<<endl;
    //check if square side=mid is good enough for n rectangles or not
    bool result=check(w,h,n,mid);
    if(right-left==1){
        result=check(w,h,n,mid);
        if(!result){
            mid=right;break;
        }
    }
    // if it is good enough then right =mid
//    cout<<result<<endl;
    if(result)
        right=mid;
    // else left=mid
    else
        left=mid;

}

cout<<mid<<endl;









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
