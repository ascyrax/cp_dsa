#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define all(x)  x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)(x).size()
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


int k,n;cin>>k>>n;
vector<int>judge(k),ann(n);//ann ->announce
for(int &i:judge)cin>>i;
for(int &i:ann)cin>>i;
sort(ann.begin(),ann.end());
int max_ann=ann[ann.size()-1];
int min_ann=ann[0];
vector<int>pr_judge(k);
pr_judge[0]=judge[0];

int max_pr_judge=pr_judge[0],min_pr_judge=pr_judge[0];

for(int i=1;i<k;i++){
    pr_judge[i]=pr_judge[i-1]+judge[i];
    max_pr_judge=max(max_pr_judge,pr_judge[i]);
    min_pr_judge=min(min_pr_judge,pr_judge[i]);
}

int max_ans=max_ann+abs(min_pr_judge);
int min_ans=min_ann-max_pr_judge;

int count_ans=0;

map<int,int>temp;
for(int j=0;j<k;j++){
    int a=pr_judge[j];
//    int b=i+a;
    temp.insert(make_pair(a,j));
}

for(int i=min_ans;i<=max_ans;i++){

    int flag=-1;
    for(int j:ann){
        if(temp.count(j-i)!=1){
            flag=0;break;
        }else{
            flag=1;
        }
    }
    if(flag==1)count_ans++;
}

cout<<count_ans<<endl;


//if(n==k)cout<<1<<endl;//there are no same bjs....-> n==k only when all announced scores are different
//// ie. there is no such case where -5 5 0 kind of thing occurs where after 5 and after 0...the announced score will be same.
//else if(n<k){
//    cout<<count_ans<<endl;
//}



















}//




































int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
