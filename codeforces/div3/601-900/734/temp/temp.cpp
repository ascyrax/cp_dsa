#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define endl "\n"
#define ioss                         \
        ios::sync_with_stdio(false); \
        cin.tie(0);
#define pb push_back

double startTime;
double gct() //get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

//...............................

void suraj()
{
        vector<int> v = {1, 2, 3, 2, 5, 2, 7, 8};
        auto it = remove(v.begin(), v.end(), 2);
        for (int i : v)
                cout << i << " ";
        cout << endl;
        // for (auto i : it)
        //         cout << i << " ";
        // cout << endl;
        for (auto i = v.begin(); i != it; i++)
                cout << *i << " ";
        cout << endl;
        cout << *it << " " << it - v.begin() << endl;
        cout << typeid(it).name() << endl;
}

//................................
