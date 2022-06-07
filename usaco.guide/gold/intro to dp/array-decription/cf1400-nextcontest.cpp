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
const int mod = 1e9 + 7;
void suraj()
{
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;

        if (n == 1)
        {
                if (v[0] == 0)
                {
                        cout << m << endl;
                }
                else
                        cout << 1 << endl;
                return;
        }
        int extreme = 1;
        if (v[0] == 0)
        {
                int temp = 0;
                if (v[1] == 1)
                        temp += min(2, m);
                else if (v[1] == 100)
                        temp += 2;
                else
                {
                        if (v[1] < m)
                                temp += 3;
                        else
                                temp += 2;
                }
                extreme *= (temp % mod);
        }
        if (v[n - 1] == 0)
        {
                int temp = 0;
                if (v[n - 2] == 1)
                {
                        temp += min(2, m);
                }
                else if (v[n - 2] == 100)
                {
                        temp += 2;
                }
                else
                {
                        if (v[n - 2] < m)
                                temp += 3;
                        else
                                temp += 2;
                }
                extreme *= (temp % mod);
        }
        int mid = 1;
        for (int i = 1; i <= n - 2; i++)
        {
                int temp = 0;
                if (v[i] == 0)
                {
                        if (v[i - 1] == v[i + 1])
                        {
                                if (v[i - 1] == 1)
                                {
                                        temp += min(2, m);
                                }
                                else if (v[i - 1] == m)
                                {
                                        temp += 2;
                                }
                                else
                                {
                                        temp += 3;
                                }
                        }
                        else if (abs(v[i + 1] - v[i - 1]) == 1)
                        {
                                temp += 2;
                        }
                        else if (abs(v[i + 1] - v[i - 1]) == 2)
                        {
                                temp += 1;
                        }
                        mid *= (temp % mod);
                }
        }
        cout << (mid * extreme) % mod << endl;
}

//................................
