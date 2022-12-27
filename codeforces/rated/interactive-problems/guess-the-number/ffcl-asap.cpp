#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
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
        //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        return 0;
}

// @author: ascyrax

//...............................

void suraj()
{
        int l = 0, r = 1000000;
        while (l != r)
        {
                int mid = (l + r + 1) / 2;
                cout << (mid) << endl;
                cout << flush;
                string response;
                cin >> response;
                int reslen = int(response.size());
                if (reslen == 2)
                {
                        if (response.substr(0, 2) == "<=")
                        {
                                r = mid;
                        }
                        else
                        {
                                l = mid;
                        }
                }
                else
                {
                        if (response.substr(0, 1) == "<")
                        {
                                r = mid - 1;
                        }
                        else
                        {
                                l = mid + 1;
                        }
                }
        }
        cout << "! " << l << endl;
}

//................................
