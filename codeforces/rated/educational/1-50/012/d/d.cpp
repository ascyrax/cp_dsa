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

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................
bool isPrime(int n)
{
        if (n == 1)
                return true;
        int div = 0;
        for (int i = 2; i * i <= n; i++)
        {
                if (n % i == 0)
                        div++;
        }
        if (div >= 1)
                return false;
        else
                return true;
}
//...............................

void suraj()
{
        int n;
        cin >> n;
        vector<int> v(n);

        for (int &i : v)
                cin >> i;
        int lenMax = 0;
        pair<int, int> ans;
        for (int i = 0; i < n; i++)
        {
                lenMax = 1;
                ans = make_pair(i, i);
        }
        pair<int, int> twoAns;
        for (int i = 0; i < n; i++)
        {
                for (int j = i + 1; j < n; j++)
                {
                        // cout << v[i] << " " << v[j] << endl;
                        if (v[i] == 1 && v[j] == 1)
                        {
                                // cout << "if" << endl;
                                lenMax = 2;
                                twoAns = make_pair(v[i], v[j]);
                        }
                        else if ((v[i] % 2) != (v[j] % 2) && isPrime(v[i] + v[j]))
                        {
                                // cout << "else if" << endl;
                                lenMax = 2;
                                twoAns = make_pair(v[i], v[j]);
                        }
                }
        }
        int nOne = 0;
        int x = -1;
        for (int i = 0; i < n; i++)
        {
                if (v[i] == 1)
                        nOne++;
                if (v[i] % 2 == 0)
                {
                        if (isPrime(v[i] + 1))
                        {
                                x = v[i];
                        }
                }
        }
        if (x == -1)
        {
                if (nOne >= lenMax)
                {
                        cout << nOne << endl;
                        for (int i = 0; i < nOne; i++)
                                cout << 1 << " ";
                        cout << endl;
                        return;
                }
        }
        else
        {
                if (nOne + 1 >= lenMax)
                {
                        cout << nOne + 1 << endl;
                        for (int i = 0; i < nOne; i++)
                                cout << 1 << " ";
                        cout << x << endl;
                        return;
                }
        }
        cout << lenMax << endl;
        if (lenMax == 2)
        {
                cout << twoAns.first << " " << twoAns.second << endl;
        }
        else
        {
                for (int i = ans.first; i <= ans.second; i++)
                        cout << v[i] << " ";
                cout << endl;
        }
}

//................................
