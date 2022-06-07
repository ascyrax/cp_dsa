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
double gct() // get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

void suraj();

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

int main()
{
        // ioss
        // startTime=(double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

//...............................

//...............................

void suraj()
{
        int n;
        cin >> n;
        string a;
        cin >> a;
        string b;
        cin >> b;

        if (a == b)
        {
                cout << 0 << endl;
                return;
        }

        int aa = 0, ab = 0, ba = 0, bb = 0;
        for (int i = 0; i < n; i++)
        {
                if (a[i] == '0' && b[i] == '0')
                {
                        aa++;
                }
                else if (a[i] == '1' && b[i] == '1')
                {
                        bb++;
                }
                else if (a[i] == '0' && b[i] == '1')
                {
                        ab++;
                }
                else if (a[i] == '1' && b[i] == '0')
                {
                        ba++;
                }
        }
        int ans = 1e9;
        cout << "aa = " << aa << endl;
        cout << "bb = " << bb << endl;
        cout << "ab = " << ab << endl;
        cout << "ba = " << ba << endl;
        // if by pairs of moves(i.e. even no of moves)
        if (ab == ba)
        {
                ans = min(ans, ab + ba);
        }

        // if by odd no of moves
        // choosing ab
        if (ba > 0)
        {
                cout << "choosing ba" << endl;
                int baPrev = ba, abPrev = ab, aaPrev = aa, bbPrev = bb;
                ba = 0, bb = 0, aa = 0, ab = 0;
                // ba -> aa , all except the hinge candle
                ba = 1;
                aa += baPrev - 1;
                // aa -> ba
                ba += aaPrev;
                // bb -> ba
                ba += bbPrev;
                // ab -> bb
                bb += abPrev;
                cout << "aa = " << aa << endl;
                cout << "bb = " << bb << endl;
                cout << "ab = " << ab << endl;
                cout << "ba = " << ba << endl;
                ans = min(ans, ba + ba + 1); // +1 becz of the first move where an ab was
                // hinged and all other candles were toggled

                ba = baPrev, ab = abPrev, aa = aaPrev, bb = bbPrev;
        }
        cout << "--------------" << endl;
        cout << "aa = " << aa << endl;
        cout << "bb = " << bb << endl;
        cout << "ab = " << ab << endl;
        cout << "ba = " << ba << endl;
        // choosing aa
        if (bb > 0)
        {
                cout << "choosing bb" << endl;
                int baPrev = ba, abPrev = ab, aaPrev = aa, bbPrev = bb;
                aa = 0, bb = 0, ab = 0, ba = 0;
                // bb -> ab , all except the hinge candle
                bb = 1;
                ab += bbPrev - 1;
                // ab -> bb
                bb += abPrev;
                // aa -> ba
                aa += baPrev;
                // ba -> aa
                aa += baPrev;
                cout << "aa = " << aa << endl;
                cout << "bb = " << bb << endl;
                cout << "ab = " << ab << endl;
                cout << "ba = " << ba << endl;
                ans = min(ans, ab + ba + 1); // +1 becz of the first move where an aa was
                // hinged and all other candles were toggled
                ba = baPrev, ab = abPrev, aa = aaPrev, bb = bbPrev;
        }
        if (ans == 1e9)
                cout << -1 << endl;
        else
                cout << ans << endl;
}

//................................
// int
// int
// int
// int
