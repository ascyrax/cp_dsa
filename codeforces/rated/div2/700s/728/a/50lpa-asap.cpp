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
        ioss int t;
        cin >> t;
        for (int i = 1; i <= t; i++) //{cout<<"Case #"<<i<<": ";
                suraj();
        //}
        return 0;
}

// @author: ascyrax

//...............................

void suraj()
{
        int n;
        cin >> n;
        if (n % 2 == 0)
        {
                for (int i = 1; i <= n; i++)
                {
                        if (i % 2 == 1)
                                cout << i + 1 << " ";
                        else
                                cout << i - 1 << " ";
                }
        }
        else
        {
                for (int i = 1; i <= n - 3; i++)
                {
                        if (i % 2 == 1)
                                cout << i + 1 << " ";
                        else
                                cout << i - 1 << " ";
                }
                cout << n << " " << n - 2 << " " << n - 1;
        }
        cout << endl;
}

//................................
