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





























void suraj2(){
int a,b,c,d;cin>>a>>b>>c>>d;int area_a=(d-b)*(c-a);
int e,f,g,h;cin>>e>>f>>g>>h;int area_b=(h-f)*(g-e);
int i,j,k,l;cin>>i>>j>>k>>l;
int area1,area2;
if((i>a&&i<c)){
    if(j>d){
        //no intersection
        area1=0;
    }else if(j<b){
        //check further
    }
    else if(j>b&&j<d){
        //intersection
        area1=(c-i)*(d-j);
    }
}else if(k>a&&k<c){
    if(l<b)area1=0;
    else if(l>b&&l<d){
        area1=(l-b)*(k-a);
    }//else if()
}





}//


bool ok[2001][2001];
int ans=0;
void suraj(){
   int xa,ya,xb,yb;
   for(int i=0;i<3;i++){
       cin>>xa>>ya>>xb>>yb;
       xa+=1000;ya+=1000;xb+=1000;yb+=1000;
           for(int x=xa;x<xb;x++){
               for(int y=ya;y<yb;y++){
                   if(i==1||i==0)
                   ok[x][y]=true;
                   else
                       ok[x][y]=false;
               }
           }
       }

   for(int x=0;x<2001;x++){
    for(int y=0;y<2001;y++){
        if(ok[x][y]==true)ans++;
    }
}
   cout<<ans<<endl;
   }//



















int main()
{
    startTime=(double)clock();
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
