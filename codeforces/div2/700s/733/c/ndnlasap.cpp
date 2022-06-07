#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define size(x) (int)(x).size()
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
        vector<int> va(n);
        int suma = 0, sumb = 0;
        for (int &i : va)
        {
                cin >> i;
                suma += i;
        }
        vector<int> vb(n);
        for (int &i : vb)
        {
                cin >> i;
                sumb += i;
        }
        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());
        vector<int> psa, psb;
        psa[0] = va[0];
        psb[0] = vb[0];
        for (int i = 1; i < n; i++)
        {
                psa[i] = psa[i - 1] + va[i];
                psb[i] = psb[i - 1] + vb[i];
        }

        int rem = n % 4;
        int leftout = n / 4;
        suma = psa[n - 1] - psa[n / 4 - 1];
        sumb = psb[n - 1] - psb[n / 4 - 1];
        if (suma >= sumb)
        {
                cout << 0 << endl;
                return;
        }
        else
        {
                int diff = sumb - suma;
                int nreq = diff / 100;
                //after n+nreq stages
                // sumb will decrease if we insert 0 in vb. so we
                // need to insert the min value of vb until rem becomes 0
                int ptrleft = 0;
                while (rem > 0)
                {
                        suma += 100;
                        suma -= va[ptrleft++];
                        rem--;
                        if (suma >= sumb)
                        {
                                cout << ptrleft << endl;
                                return;
                        }
                }
                //now we can add 0 to vb
                }
}

//................................
