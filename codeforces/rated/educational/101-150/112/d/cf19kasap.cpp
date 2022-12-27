// @author: ascyrax

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
        ioss
            startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll mod = 1e9 + 7;
const int inf = 2147483647;
const int ninf = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
int n, m;
string s;
string a, b, c, d, e, f;

//abc  acb bca bac cab cba
//...............................
int cost(int l, int r)
{
        int cnt = 0;
        for (int i = l - 1; i <= r - 1; i++)
        {
                if (s[i] == s[i + 1])
                {
                        cnt++;
                }
                if (s[i] == s[i + 2])
                {
                        cnt++;
                }
                if (i + 3 <= l - 1 && s[i] != s[i + 3])
                {
                        cnt++;
                }
        }
        return cnt;
}
//...............................

void suraj()
{
        cin >> n >> m >> s;

        //form a ,b ,c
        while ((int)a.size() < n)
        {
                a += "abc";
                d += "acb";
                b += "bca";
                e += "bac";
                c += "cab";
                f += "cba";
        }
        a = a.substr(0, n);
        b = b.substr(0, n);
        c = c.substr(0, n);
        d = d.substr(0, n);
        e = e.substr(0, n);
        f = f.substr(0, n);
        // cout << a << " " << b << " " << c << " " << s << endl;
        vector<int> countA, countB, countC, countD, countE, countF;
        for (int i = 0; i < n; i++)
        {
                if (s[i] != a[i])
                        countA.pb(1);
                else
                        countA.pb(0);
                if (s[i] != b[i])
                        countB.pb(1);
                else
                        countB.pb(0);
                if (s[i] != c[i])
                        countC.pb(1);
                else
                        countC.pb(0);
                if (s[i] != d[i])
                        countD.pb(1);
                else
                        countD.pb(0);
                if (s[i] != e[i])
                        countE.pb(1);
                else
                        countE.pb(0);
                if (s[i] != f[i])
                        countF.pb(1);
                else
                        countF.pb(0);
        }
        // for (int i : countA)
        //         cout << i << " ";
        // cout << endl;
        // for (int i : countB)
        //         cout << i << " ";
        // cout << endl;
        // for (int i : countC)
        //         cout << i << " ";
        // cout << endl;
        vector<int> psA(n, 0), psB(n, 0), psC(n, 0), psD(n, 0), psE(n, 0), psF(n, 0);
        psA[0] = countA[0];
        psB[0] = countB[0];
        psC[0] = countC[0];
        psD[0] = countD[0];
        psE[0] = countE[0];
        psF[0] = countF[0];
        for (int i = 1; i < n; i++)
        {
                psA[i] = countA[i] + psA[i - 1];
                psB[i] = countB[i] + psB[i - 1];
                psC[i] = countC[i] + psC[i - 1];
                psD[i] = countD[i] + psD[i - 1];
                psE[i] = countE[i] + psE[i - 1];
                psF[i] = countF[i] + psF[i - 1];
        }
        // for (int i : psA)
        //         cout << i << " ";
        // cout << endl;
        // for (int i : psB)
        //         cout << i << " ";
        // cout << endl;
        // for (int i : psC)
        //         cout << i << " ";
        // cout << endl;
        for (int i = 0; i < m; i++)
        {
                int l, r;
                cin >> l >> r;
                int ans = 1e9;
                if (l - 2 >= 0)
                {
                        ans = min(psA[r - 1] - psA[l - 2], psB[r - 1] - psB[l - 2]);
                        ans = min(ans, psC[r - 1] - psC[l - 2]);
                        ans = min(ans, psD[r - 1] - psD[l - 2]);
                        ans = min(ans, psE[r - 1] - psE[l - 2]);
                        ans = min(ans, psF[r - 1] - psF[l - 2]);
                }
                else
                {
                        ans = min(psA[r - 1] - 0, psB[r - 1] - 0);
                        ans = min(ans, psC[r - 1] - 0);
                        ans = min(ans, psD[r - 1] - 0);
                        ans = min(ans, psE[r - 1] - 0);
                        ans = min(ans, psF[r - 1] - 0);
                }
                cout << ans << endl;
        }
}

//................................
