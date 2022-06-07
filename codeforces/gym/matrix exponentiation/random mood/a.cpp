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
        cout << setprecision(15) << fixed;
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

//...............................

void suraj()
{
        ll n;
        ld p;
        cin >> n >> p;

        vector<ld> prob(n + 1); // p[i] => probability that mood will change after i minutes

        prob[0] = p;

        // p[2]=p[1]*(1-p) + (1-p[1])*p

        // int i = 2;
        int j = 1;
        while (pow(2, j) <= n)
        {
                prob[j] = prob[j - 1] * (1 - prob[j - 1]) + (1 - prob[j - 1]) * prob[j - 1];
                // i *= 2;
                j++;
        }
        ld prob_happy = 1.0; // initially the person is happy
        // ld prob = p;
        // i = 0;
        // while (n > 0)
        // {
        //         if (n % 2 == 1)
        //         {
        //                 prob_happy = prob_happy * (1 - p) + (1 - prob_happy) * p;
        //         }
        //         p = p * (1 - p) + (1 - p) * p;
        //         n /= 2;
        // }
        j = 0;
        while (n > 0)
        {
                if (n % 2 == 1)
                {
                        prob_happy = prob_happy * (1 - prob[j]) + (1 - prob_happy) * prob[j];
                }
                n /= 2;
                j++;
        }
        cout << prob_happy << endl;
}

//................................
