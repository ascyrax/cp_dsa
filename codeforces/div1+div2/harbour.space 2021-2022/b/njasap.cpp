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
        string s, t;
        cin >> s >> t;
        string oppS = "";
        for (int i = s.size() - 1; i >= 0; i--)
                oppS += s[i];
        int r = 0;

        while (r <= s.size() - 1)
        {
                int l = int(t.size()) - r - 1;

                // if (1 + r + l > t.size())
                //         break;

                for (int i = max(0, l - r); i + r < s.size(); i++)
                {
                        // if (l > i + r)
                        //         break;
                        // cout << r << " " << l << " " << i << endl;
                        string temp = "";
                        temp = s.substr(i, r + 1);
                        // temp += oppS.substr(int(s.size()) - i - r, l);
                        string b = "";
                        for (int j = i + r - 1; j >= max(0, i + r - l); j--)
                        {
                                b += s[j];
                        }
                        // int aa = (i + r - l);
                        // if (aa < 0)
                        // {
                        //         aa = l + aa;
                        // }
                        // else
                        //         aa = l;
                        // string a = s.substr(max(0, i + r - l), aa);
                        // string b = "";
                        // for (char c : a)
                        //         b = c + a;
                        temp += b;
                        // cout << temp << " " << t << endl;
                        if (temp == t)
                        {
                                cout << "yes" << endl;
                                return;
                        }
                }

                r++;
        }
        cout << "no" << endl;
        return;
}

//................................
