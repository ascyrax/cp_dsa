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

// @author: ascyrax

const ll mod = 1e9 + 7;
const int inf = 2147483647;
const int ninf = -2147483647 - 1;
//...............................
int n;
vector<int> v;
//...............................

//...............................

void suraj()
{

        cin >> n;
        int neven = 0, nodd = 0;
        v = vector<int>(n, 0);
        for (int &i : v)
        {
                cin >> i;
                if (i % 2 == 0)
                        neven++;
                else
                        nodd++;
        }
        if (abs(neven - nodd) > 1)
        {
                cout << -1 << endl;
        }
        else
        {

                // int pEven = -1, pOdd = -1;
                // for (int i = 0; i < n; i++)
                // {
                //         if (v[i] % 2 == 0)
                //         {
                //                 pEven = i;
                //                 break;
                //         }
                // }
                // for (int i = 0; i < n; i++)
                // {
                //         if (v[i] % 2 == 1)
                //         {
                //                 pOdd = i;
                //                 break;
                //         }
                // }
                int swapCost = 0;
                int curr = 1;
                for (int i = 0; i < n - 1; i++)
                {
                        if ((nodd > neven) || (nodd == neven && v[0] % 2 == 1))
                        {
                                if (i % 2 == 0 && v[i] % 2 != 1)
                                {
                                        for (int j = i + 1; j < n; j++)
                                        {
                                                if (v[j] % 2 == 1)
                                                {
                                                        swapCost += abs(j - i);
                                                        swap(v[i], v[j]);
                                                        break;
                                                }
                                        }
                                }
                                else if (i % 2 == 1 && v[i] % 2 != 0)
                                {
                                        for (int j = i + 1; j < n; j++)
                                        {
                                                if (v[j] % 2 == 0)
                                                {
                                                        swapCost += abs(j - i);
                                                        swap(v[i], v[j]);
                                                        break;
                                                }
                                        }
                                }
                        }
                        else if ((neven > nodd) || (neven == nodd && v[0] % 2 == 0)) //if the first element is even
                        {
                                if (i % 2 == 1 && v[i] % 2 != 1)
                                {
                                        for (int j = i + 1; j < n; j++)
                                        {
                                                if (v[j] % 2 == 1)
                                                {
                                                        swapCost += abs(j - i);
                                                        swap(v[i], v[j]);
                                                        break;
                                                }
                                        }
                                }
                                else if (i % 2 == 0 && v[i] % 2 != 0)
                                {
                                        for (int j = i + 1; j < n; j++)
                                        {
                                                if (v[j] % 2 == 0)
                                                {
                                                        swapCost += abs(j - i);
                                                        swap(v[i], v[j]);
                                                        break;
                                                }
                                        }
                                }
                        }
                }

                cout << swapCost << endl;
        }
}

//................................
/**
 *    author:  tourist
 *    created: 29.08.2021 17:36:22       
**/
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//         ios::sync_with_stdio(false);
//         cin.tie(0);
//         int tt;
//         cin >> tt;
//         while (tt--)
//         {
//                 int n;
//                 cin >> n;
//                 vector<int> a(n);
//                 for (int i = 0; i < n; i++)
//                 {
//                         cin >> a[i];
//                         a[i] %= 2;
//                 }
//                 const long long inf = (long long)1e18;
//                 long long ans = inf;
//                 for (int r = 0; r < 2; r++)
//                 {
//                         vector<int> x;
//                         vector<int> y;
//                         for (int i = r; i < n; i += 2)
//                         {
//                                 x.push_back(i);
//                         }
//                         for (int i = 0; i < n; i++)
//                         {
//                                 if (a[i] % 2 == 0)
//                                 {
//                                         y.push_back(i);
//                                 }
//                         }
//                         if (x.size() == y.size())
//                         {
//                                 long long cur = 0;
//                                 for (int i = 0; i < (int)x.size(); i++)
//                                 {
//                                         cur += abs(x[i] - y[i]);
//                                 }
//                                 ans = min(ans, cur);
//                         }
//                 }
//                 cout << (ans == inf ? -1 : ans) << '\n';
//         }
//         return 0;
// }