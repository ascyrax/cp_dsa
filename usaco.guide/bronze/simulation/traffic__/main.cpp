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
int left=0,right=999999999;
int n;cin>>n;
int flag=0;int ptr=-1;
int aleft=0,aright=999999999;

vector<string>vd(n);vector<int>vl(n),vr(n);
string prev="";

for(int i=0;i<n;i++){
    string a;int l,r;cin>>a>>l>>r;
    vd[i]=a;vl[i]=l;vr[i]=r;
    if(a=="on"){
//        if(flag>0&&ptr==-1){
//            aleft=max(0,left);aright=max(0,right);ptr=i-1;
//        }
        left+=l;right+=r;
    }else if(a=="off"){
//        if(flag>0&&ptr==-1){ptr=i-1;
//            aleft=max(0,left);aright=max(0,right);
//        }
        left-=r;right-=l;left=max(0,left);right=max(0,right);
    }else if(a=="none"){
//        flag++;
//        if(prev=="none"){
            left=max(left,l);right=min(right,r);
//        }else{
//            left=l;right=r;
//        }
    }//cout<<left<<" "<<right<<endl;
    prev=a;
}/*
cout<<aleft<<" "<<aright<<endl;
cout<<left<<" "<<right<<endl;
cout<<ptr<<endl;*/
for(int i=n-1;i>=0;i--){//cout<<"last "<<aleft<<" "<<aright<<endl;
    if(vd[i]=="none"){
        aleft=max(aleft,vl[i]);aright=min(aright,vr[i]);
    }else if(vd[i]=="on"){
        aleft-=vr[i];aright-=vl[i];aleft=max(0,aleft);aright=max(0,aright);
    }else{
        aleft+=vl[i];aright+=vr[i];
    }
}

//cout<<aleft<<" "<<aright<<endl;
cout<<aleft<<" "<<aright<<endl;
cout<<left<<" "<<right<<endl;























}//




































int main()
{
        startTime=(double)clock();
        freopen("traffic.in","r",stdin);
        freopen("traffic.out","w",stdout);
        ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        //suraj2();
        //suraj3();
        //suraj4();
        return 0;
}
