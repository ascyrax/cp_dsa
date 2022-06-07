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
        freopen("cownomics.in", "r", stdin);
        freopen("cownomics.out", "w", stdout);
        //ioss
        // cout << setprecision(15) << fixed << endl;
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
int n, m;
vector<string> spotty, plain;
//...............................

//...............................

void suraj()
{
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
                string a;
                cin >> a;
                spotty.pb(a);
        }
        for (int i = 0; i < n; i++)
        {
                string a;
                cin >> a;
                plain.pb(a);
        }
        int ans = 0;
        for (int a = 0; a < m; a++)
        {
                for (int b = a + 1; b < m; b++)
                {
                        for (int c = b + 1; c < m; c++)
                        {
                                map<string, int> m;
                                int flag = 1;
                                for (int i = 0; i < n; i++)
                                {
                                        string ts = "", tp = "";
                                        // cout << spotty[i][a] << " " << spotty[i][b] << " " << spotty[i][c] << endl;
                                        // cout << plain[i][a] << " " << plain[i][b] << " " << plain[i][c] << endl;

                                        ts += spotty[i][a];
                                        ts += spotty[i][b];
                                        ts += spotty[i][c];
                                        tp += plain[i][a];
                                        tp += plain[i][b];
                                        tp += plain[i][c];
                                        // cout << ts << " " << tp << " " << m[ts] << " " << m[tp] << endl;
                                        if (m[ts] < 0)
                                        {
                                                flag = -1;
                                                break;
                                        }
                                        else
                                        {
                                                m[ts]++;
                                        }
                                        if (m[tp] > 0)
                                        {
                                                flag = -1;
                                                break;
                                        }
                                        else
                                        {
                                                m[tp]--;
                                        }
                                }
                                if (flag == 1)
                                {
                                        // cout << a << " " << b << " " << c << endl;
                                        ans++;
                                }
                        }
                }
        }
        cout << ans << endl;
}

//................................
