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
        ioss int t;
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
        // vector<pair<string, vector<int>>> v(n);
        // vector<vector<int>> count(n, vector<int>(5));
        int totalAlpha = 0;
        vector<int> vlen;
        vector<string> vs(n);
        vector<pair<int, int>> va(n), vb(n), vc(n), vd(n), ve(n);
        for (int i = 0; i < n; i++)
        {
                string s;
                cin >> s;
                int lens = int(s.size());
                totalAlpha += lens;
                vlen.pb(lens);
                vector<char> temp;
                for (char c : s)
                        temp.pb(c);
                sort(temp.begin(), temp.end());
                int cnta = 0, cntb = 0, cntc = 0, cntd = 0, cnte = 0;
                for (char c : temp)
                {
                        if (c == 'a')
                                cnta++;
                        else if (c == 'b')
                                cntb++;
                        else if (c == 'c')
                                cntc++;
                        else if (c == 'd')
                                cntd++;
                        else if (c == 'e')
                                cnte++;
                }
                va[i] = make_pair(cnta, i);
                vb[i] = make_pair(cntb, i);
                vc[i] = make_pair(cntc, i);
                vd[i] = make_pair(cntd, i);
                ve[i] = make_pair(cnte, i);
        }

        // pslen[0] = vlen[0];
        int ans = 0;
        //for a
        sort(va.rbegin(), va.rend());

        vector<int> pslena(n);

        pslena[0] = vlen[va[0].second];
        for (int i = 1; i < n; i++)
        {
                pslena[i] = pslena[i - 1] + vlen[va[i].second];
        }
        vector<int> psa(n);
        psa[0] = va[0].first;
        for (int i = 1; i <= n; i++)
        {
                psa[i] = psa[i - 1] + va[i].first;
        }
        // cout << totalAlpha << endl;
        // for (int i : psa)
        //         cout << i << " ";
        // cout << endl;
        for (int i = n - 1; i >= 0; i--)
        {
                if (psa[i] > pslena[i] - psa[i])
                {
                        ans = max(ans, i + 1);
                        break;
                }
        }
        //for b
        sort(vb.rbegin(), vb.rend());
        vector<int> psb(n);
        psb[0] = vb[0].first;
        vector<int> pslenb(n);

        pslenb[0] = vlen[vb[0].second];
        for (int i = 1; i < n; i++)
        {
                pslenb[i] = pslenb[i - 1] + vlen[vb[i].second];
        }
        for (int i = 1; i <= n; i++)
        {
                psb[i] = psb[i - 1] + vb[i].first;
        }
        for (int i = n - 1; i >= 0; i--)
        {
                if (psb[i] > pslenb[i] - psb[i])
                {
                        ans = max(ans, i + 1);
                        break;
                }
        }
        //for c
        sort(vc.rbegin(), vc.rend());
        vector<int> psc(n);
        psc[0] = vc[0].first;
        vector<int> pslenc(n);

        pslenc[0] = vlen[vc[0].second];
        for (int i = 1; i < n; i++)
        {
                pslenc[i] = pslenc[i - 1] + vlen[vc[i].second];
        }
        for (int i = 1; i <= n; i++)
        {
                psc[i] = psc[i - 1] + vc[i].first;
        }
        for (int i = n - 1; i >= 0; i--)
        {
                if (psc[i] > pslenc[i] - psc[i])
                {
                        ans = max(ans, i + 1);
                        break;
                }
        }
        //for d
        sort(vd.rbegin(), vd.rend());
        vector<int> psd(n);
        psd[0] = vd[0].first;
        vector<int> pslend(n);

        pslend[0] = vlen[vd[0].second];
        for (int i = 1; i < n; i++)
        {
                pslend[i] = pslend[i - 1] + vlen[vd[i].second];
        }
        for (int i = 1; i <= n; i++)
        {
                psd[i] = psd[i - 1] + vd[i].first;
        }
        for (int i = n - 1; i >= 0; i--)
        {
                if (psd[i] > pslend[i] - psd[i])
                {
                        ans = max(ans, i + 1);
                        break;
                }
        }
        //for e
        sort(ve.rbegin(), ve.rend());
        vector<int> pse(n);
        pse[0] = ve[0].first;
        vector<int> pslene(n);

        pslene[0] = vlen[ve[0].second];
        for (int i = 1; i < n; i++)
        {
                pslene[i] = pslene[i - 1] + vlen[ve[i].second];
        }
        for (int i = 1; i <= n; i++)
        {
                pse[i] = pse[i - 1] + ve[i].first;
        }
        for (int i = n - 1; i >= 0; i--)
        {
                if (pse[i] > pslene[i] - pse[i])
                {
                        ans = max(ans, i + 1);
                        break;
                }
        }
        cout << ans << endl;
}

//................................
