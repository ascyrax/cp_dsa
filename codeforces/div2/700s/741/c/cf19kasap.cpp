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
        //ioss
        //cout << setprecision(15) << fixed << endl;
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
const int inf = 2147483647;
const int ninf = -2147483647 - 1;
//...............................

//...............................

//...............................

void suraj()
{
        int n;
        cin >> n;
        string s;
        cin >> s;

        for (int i = n / 2; i < n; i++)
        {
                // cout << s << " " << s[i] << endl;
                if (s[i] == '0')
                {

                        cout << (0) + 1 << " " << (i) + 1 << " " << (0) + 1 << " " << (i - 1) + 1 << endl;
                        return;
                }
        }
        for (int i = n / 2 - 1; i >= 0; i--)
        {
                // cout << s << " " << s[i] << endl;
                if (s[i] == '0')
                {

                        cout << (i) + 1 << " " << (n - 1) + 1 << " " << (i + 1) + 1 << " " << (n - 1) + 1 << endl;
                        return;
                }
        }
        cout << (0) + 1 << " " << (n / 2 - 1) + 1 << " " << (1) + 1 << " " << (n / 2 - 1 + 1) + 1 << endl;
}

//................................
