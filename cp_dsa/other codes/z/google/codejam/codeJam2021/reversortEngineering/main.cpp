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
























//int flag=-1;


//int findFromLast(int n,int diff){
//    int a=0;
//    int sum=0;
//    int level=0;//last
//    while(sum<diff){
//        level++;
//        sum+=a;
//        a++;

//    }
//    if(sum==diff)flag=0;
//    else if(sum>diff)flag=1;
//    return level;
//}


//int count(vector<int>v){
//    //destroyed in seconds\
//    //saccchimeda
//    //bts==kohli
//    //or bts<kohli
//    //or kohli >=abdevillers
//    //or badal==rohit
//    //or megha==piyush chawla
//    int n=int(v.size());
//    for(int i=1;i<n;i++){
//        ;
//    }

//}





void suraj(){///////////////////////

int n,c;cin>>n>>c;
// vector<int>v;
// for(int i=2;i<=n;i+=2){
//     v.pb(i);
// }
// if(n%2==0){
//     for(int i=n-1;i>=0;i-=2){
//         v.pb(i);
//     }
// }else{
//     for(int i=n;i>=0;i-=2){
//         v.pb(i);
//     }
// }
// int maxC=n*(n+1)/2-1;
// if(c>maxC||c<n-1){
//     cout<<"IMPOSSIBLE"<<endl;
// }else{
//     int diff=maxC-c;
//     int fromLast=findFromLast(n,diff);
//     if(flag==0){

//     }else if(flag==1){

//     }
// }
vector<int>v;
for(int i=1;i<=n;i++){
    v.pb(i);
}
int flag=0;
//cout<<"before do"<<endl;
do{//cout<<"do"<<endl;
    int sum=0;
    auto vc=v;
    //for(int i:v)cout<<i<<" ";cout<<endl;
    for(int i=1;i<n;i++){
        auto loc=find(vc.begin(),vc.end(),i);
    //    cout<<"loc "<<loc-v.begin()<<endl;
        sum+=(loc-(vc.begin()+i-1))+1;
        if(loc!=vc.end())loc++;
        reverse(vc.begin()+i-1,loc);
    //    for(int i:v)cout<<i<<" ";cout<<endl;
    }
    if(sum==c){
        flag=1;
        for(int i:v)cout<<i<<" ";cout<<endl;
        break;
    }
}while(next_permutation(v.begin(),v.end()));

//cout<<"after do"<<endl;
if(flag==0){
    cout<<"IMPOSSIBLE"<<endl;
    //also badal is pagal and megha is super pagal
}









}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";
    suraj();
    }
    return 0;
}
