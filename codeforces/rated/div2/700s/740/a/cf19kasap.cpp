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
        // ioss
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

//...............................

//...............................

void suraj()
{
        int n;
        cin >> n;
        vector<int> v(n), vsort, vInitial;
        for (int &i : v)
                cin >> i;
        vInitial = v;
        sort(v.begin(), v.end());
        vsort = v;
        v = vInitial;
        for (int i = 1;; i++)
        {
                if (v == vsort)
                {
                        cout << i - 1 << endl;
                        break;
                }
                if (i % 2 == 1)
                {
                        for (int j = 0; j < n; j += 2)
                        {
                                if (j + 1 < n)
                                        if (v[j] > v[j + 1])
                                        {
                                                swap(v[j], v[j + 1]);
                                        }
                        }
                }

                else
                {
                        for (int j = 1; j < n; j += 2)
                        {
                                if (j + 1 < n)
                                        if (v[j] > v[j + 1])
                                        {
                                                swap(v[j], v[j + 1]);
                                        }
                        }
                }
        }
}

//................................
