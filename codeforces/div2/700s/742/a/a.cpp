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
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
int n;
string s;
int flag = 0;

//...............................

//...............................

void suraj()
{
        cin >> n;
        vector<char> ans;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
                if (s[i] == 'U')
                {
                        flag = 1;
                }
                if (s[i] == 'D')
                {
                        flag = 2;
                }
        }
        for (int i = 0; i < n; i++)
        {
                if (s[i] == 'L')
                {
                        ans.pb('L');
                }
                else if (s[i] == 'R')
                {
                        ans.pb('R');
                }
                else if (s[i] == 'U')
                {
                        ans.pb('D');
                }
                else
                        ans.pb('U');
        }
        for (char ch : ans)
                cout << ch << "";
        cout << endl;
}

//................................
