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














vector<int>link[9];
bool used[9];
map<string,int>m;
map<int,string>m2;



void check(int i){
    if(used[i]==false){
        used[i]=true;
    if(link[i].size()==0){
        cout<<m2[i]<<endl;return;
    }else if(link[i].size()==1){
        if(used[link[i][0]]==true)return;
        cout<<m2[i]<<endl;
        cout<<m2[link[i][0]]<<endl;
        check(link[i][0]);return;
    }else{
        int ta=link[i][0];int tb=link[i][1];
        if(link[ta].size()==1&&link[tb].size()==1){
            if(m2[ta]<m2[tb]){
                cout<<m2[ta]<<endl<<m2[i]<<endl<<m2[tb]<<endl;
            }else{
                cout<<m2[tb]<<endl<<m2[i]<<endl<<m2[ta]<<endl;
            }
        }else if(link[ta].size()==1&&link[tb].size()!=1){
            cout<<m2[ta]<<endl<<m2[i]<<endl<<m2[tb]<<endl;
        }
        else if(link[ta].size()!=1&&link[tb].size()==1){
            cout<<m2[tb]<<endl<<m2[i]<<endl<<m2[ta]<<endl;
        }
        return;
    }
    }
}










void suraj(){
int n;cin>>n;

m["Beatrice"]=1;m2[1]="Beatrice";
m["Belinda"]=2;m2[2]="Belinda";
m["Bella"]=3;m2[3]="Bella";
m["Bessie"]=4;m2[4]="Bessie";
m["Sue"]=8;m2[8]="Sue";
m["Buttercup"]=7;m2[7]="Buttercup";
m["Blue"]=6;m2[6]="Blue";
m["Betsy"]=5;m2[5]="Betsy";

for(int i=0;i<9;i++)used[i]=false;

for(int t=0;t<n;t++){
    string tempa,tempb,temp;
    cin>>tempa;
    cin>>temp;cin>>temp;cin>>temp;cin>>temp;
    cin>>tempb;
    int tempc=m[tempa];
    int tempd=m[tempb];
    link[tempc].pb(tempd);
    link[tempd].pb(tempc);

}

for(int i=1;i<=8;i++){
    cout<<"I"<<" "<<i<<endl;
    if(used[i]==false){
        check(i);
    }

}




}//
























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
