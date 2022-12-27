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
                cout
            << setprecision(15) << fixed << endl;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        if (v[0] == 1)
        {
                cout << n + 1 << " ";
                for (int i = 1; i <= n; i++)
                {
                        cout << i << " ";
                }
                cout << endl;
        }
        else if (v[0] == 0)
        {
                if (v[n - 1] == 0)
                {
                        for (int i = 1; i <= n; i++)
                        {
                                cout << i << " ";
                        }
                        cout << n + 1 << endl;
                }
                else
                {
                        int temp = -1;
                        for (int i = 0; i < n; i++)
                        {
                                if (v[i] == 1)
                                {
                                        temp = i;
                                        break;
                                }
                        }
                        for (int i = 1; i <= temp; i++)
                        {
                                cout << i << " ";
                        }
                        cout << n + 1 << " ";
                        for (int i = temp + 1; i <= n; i++)
                        {
                                cout << i << " ";
                        }
                        cout << endl;
                }
        }
}

//................................
