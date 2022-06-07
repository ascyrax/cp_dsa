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
int a,b;cin>>a>>b;
string sa="",sb="";
while(a>0){
    int temp=a%10;
    sa+=to_string(temp);
    a/=10;
}
while(b>0){
    int temp=b%10;
    sb+=to_string(temp);
    b/=10;
}
if(sa>sb){
    cout<<sa<<endl;
}else cout<<sb<<endl;
//int c,n,m;cin>>c>>n>>m;
//vector<int>vn(n);for(int &i:vn)cin>>i;
//vector<int>vm(m);for(int &i:vm)cin>>i;
////cout<<"-------------------------------------"<<endl;
//if(n==0){
//    for(int i:vm)cout<<0<<endl;
//    return;
//}
////vector<int>ready(51);
////int single=0;
////for(int i:vn){
////    if(i>c/2){
////        ;
////    }else{
////        int temp=c/i;
////        ready[-1+temp]++;
////        single++;
////    }
////}
////ready[0]=n-single;

////vector<int>ans(51);
////ans[0]=single+ready[0];//ie c
//////cout<<single<<" "<<ready[0]<<" "<<ans[0]<<endl;
//////for(int i:ready)cout<<i<<" ";cout<<endl;
////for(int i=1;i<51;i++){

////    ans[i]=single+2*ready[i-1];
////    single-=ready[i];
////    ready[i]+=2*ready[i-1];
////}

////for(int i:vm)cout<<ans[i]<<endl;

//vector<int>dp[51];
//vector<int>a(1001);
//for(int i=0;i<=50;i++){
//    dp[i]=a;
//}

//for(int i:vn){
//    dp[0][i]++;
//}
////for(int i=0;i<=n;i++)cout<<dp[0][i]<<" ";cout<<endl;
//for(int day=1;day<=50;day++){
//    for(int cow=1;cow<=1000;cow++){
//        if(cow>c/2){//cout<<"if"<<endl;
//            dp[day][cow]+=2*dp[day-1][cow];
//        }else{//cout<<"else"<<endl;
//            dp[day][cow*2]+=dp[day-1][cow];
//        }
//    }
//}


//for(int i:vm){
//    int ans=0;
//    for(int j=1;j<=1000;j++){
//        ans+=dp[i][j];
//    }
//    cout<<ans<<endl;
//}

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
