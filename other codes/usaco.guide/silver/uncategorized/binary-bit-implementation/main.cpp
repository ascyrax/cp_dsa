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





























int binary_search(vector<int> &a, int query) {
    int bit, i = 0;
    for (bit = 0; (1 << bit) < a.size(); bit += 1){
        cout<<bit<<" "<<(1<<bit)<<endl;
    }
    cout<<bit<<endl;
    bit--;//since its value was 1 more than we wanted
    // find i = the rightmost position for which a[i] < query
    for (bit=bit; bit >= 0; bit -= 1) {
        if (i + (1 << bit) < a.size() && a[i + (1 << bit)] < query) {
            i += (1 << bit);
        }
    }
    i += 1;
    if (a[i] == query) {
        return i;
    }
    return -1;
}






void suraj(){///////////////////////

vector<int>v(100);
cout<<binary_search(v,5)<<endl;















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
