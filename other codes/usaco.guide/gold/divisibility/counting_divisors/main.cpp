/*
ID: ascyrax1
TASK: test
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define pb push_back

double startTime;
double gct() //get_current_time
{
    return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();
const int MAX_N = 1e6;
int max_div[MAX_N + 1];
void suraj()
{ ///////////////////////

    for (int i = 2; i <= MAX_N; i++)
    {
        if (max_div[i] == 0)
        {
            for (int j = i; j <= MAX_N; j += i)
            {
                max_div[j] = i;
            }
        }
    }

    for (int i = 0; i <= 100; i++)
        cout << max_div[i] << " ";
    cout << endl;
    // int n;
    // cin >> n;
    // vector<int> vx(n);
    // for (int &i : vx)
    //     cin >> i;
    // for (int i : vx)
    // {
    //     int ndiv = 0;
    //     int j = 1;
    //     for (j = 1; j * j < i; j++)
    //     {
    //         if (i % j == 0)
    //             ndiv += 2;
    //     }
    //     if (j * j == i)
    //         ndiv++;
    //     cout << ndiv << endl;
    // }

} ////////////////////////////

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
