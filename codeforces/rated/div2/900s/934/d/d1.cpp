// @author: ascyrax

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define int long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;
using lld = long double;

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

void suraj();

signed main()
{

    fastio();

#ifndef ONLINE_JUDGE
    clock_t startTime = clock();
#endif

    // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

    // cout << setprecision(15) << fixed;

    int t = 1;

    cin >> t;

    for (int i = 1; i <= t; i++)
    {

        // cout<<"Case #"<<i<<": ";

        suraj();

        debug("---");
    }

#ifndef ONLINE_JUDGE
    cerr << "Execution Time : " << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
#endif

    return 0;
}

int calculate_hash(string s)
{
    int hashValue = 0;

    return hashValue;
}

void suraj()
{

    int n, q;
    string s;

    cin >> n >> q;
    cin >> s;

    // calculate hash value array for prefix sums shit :)
    const int mod = 1e9 + 9; // this does not need to be a prime :) viz. it just needs to be a big number :)
    const int p = 31;        // since the input contains only lowercase english letters :)
    int val = 1;             // ie p to the power 0
    string sRev;
    vector<int> power_p;
    vector<int> hashValue, revHashValue;

    sRev = s;
    reverse(sRev.begin(), sRev.end());
    // debug(sRev);

    power_p = vector<int>(n, 0);
    power_p[0] = val;
    for (int i = 1; i < n; i++)
    {
        val *= p;
        val %= mod;
        power_p[i] = val;
    }
    // debug(power_p);

    hashValue = vector<int>(n, 0);
    revHashValue = vector<int>(n, 0);
    hashValue[0] = s[0] - 'a' + 1;
    revHashValue[0] = sRev[0] - 'a' + 1;

    // debug(hashValue);

    for (int i = 1; i < n; i++)
    {
        // debug(i);
        // int temp = (s[i] - 'a' + 1);
        // debug(temp);
        // debug(temp * power_p[i]);
        hashValue[i] = hashValue[i - 1] + (s[i] - 'a' + 1) * power_p[i];
        hashValue[i] %= mod;
        // debug(hashValue);

        revHashValue[i] = revHashValue[i - 1] + (sRev[i] - 'a' + 1) * power_p[i];
        revHashValue[i] %= mod;
    }

    vector<int> ps[26];
    for (int i = 0; i < 26; i++)
    {
        ps[i] = vector<int>(n, 0);
    }
    ps[s[0] - 'a'][0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            ps[j][i] = ps[j][i - 1];
        }
        ps[s[i] - 'a'][i]++;
    }
    // debug(hashValue);
    // debug(revHashValue);

    vector<int> badIndices;
    for (int i = 0; i + 2 < n; i++)
    {
        if (s[i] != s[i + 2])
            badIndices.push_back(i);
    }
    // badIndices
    // debug(badIndices);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int lenq = r - l + 1;
        int ans = 0;
        // if all the elements between l and r are not same, then s[l..r] is (2-good, 3-good, ... , (len-1)-good)
        // else f(sl...sr) = 0;
        string curQuery = s.substr(l, lenq);
        // debug(curQuery);
        // debug(hashValue);
        // debug(revHashValue);

        vector<int> cntAlphs(26, 0);
        for (int i = 0; i < 26; i++)
        {
            cntAlphs[i] = ps[i][r];
            if (l - 1 >= 0)
                cntAlphs[i] -= ps[i][l - 1];
        }
        // debug(cntAlphs);
        int cntUniqueChars = 0;
        for (int el : cntAlphs)
            if (el > 0)
                cntUniqueChars++;
        // debug(cntAlphs);
        // debug(cntUniqueChars);

        // no substr can ever be 1-good
        if (cntUniqueChars == 1) // then the substr cannot be k-good (for 1<=k<=lenq)
        {
            ans += 0;
            cout << ans << endl;
            continue;
        }
        else if (cntUniqueChars == 2)
        {
            // debug(cntUniqueChars);
            // we need to add the even lengths to the ans
            // ie ans += 2 + 4 + 6 + ... + lastVal
            // => ans += 2(1 + 2 + 3 + lastVal/2)
            int lastVal = lenq;
            if (lenq % 2 == 1) // => length of the current query substring is odd
                lastVal--;
            lastVal /= 2;
            ans += 2 * (lastVal) * (lastVal + 1) / 2.0;
            // debug(ans);

            // either all 3..5..7...lastVal will be include or none of them :)
            if (lenq % 2 == 1)
                lastVal = lenq;
            else
                lastVal = lenq - 1;

            // bool isPalindrome = true;
            // // h(s[i...j])*p^i = h(s[0..j]) - h(s[0...i-1])
            // int hVal = hashValue[r] + mod;
            // debug(hVal);
            // if (l - 1 >= 0)
            //     hVal -= hashValue[l - 1]; // this is h(s[i..j]) * p^i :)
            // debug(hVal);
            // hVal %= mod;
            // debug(hVal);
            // // on reversing, s[l] goes to sRev[n-1-l],
            // // and s[r] goes to sRev[n-r-1]
            // // where n-r <= n-l
            // int revHVal = revHashValue[n - 1 - l] + mod;
            // debug(revHVal);
            // if (n - r - 2 >= 0)
            //     revHVal -= revHashValue[n - r - 2];
            // debug(revHVal);
            // revHVal %= mod;
            // debug(revHVal);

            // // now hVal = h(s[l...r])*p^l
            // // and revHVal = h(s[n-1-r...n-1-l])*p^(n-1-r)
            // if (l <= n - 1 - r)
            // {
            //     int diff = n - 1 - r - l;
            //     hVal *= power_p[diff];
            //     hVal %= mod;
            // }
            // else if (l > n - 1 - r)
            // {
            //     int diff = l - n - 1 - r;
            //     revHVal *= power_p[diff];
            //     revHVal %= mod;
            // }

            // debug(hVal);
            // debug(revHVal);
            // debug(ans);

            // if (hVal != revHVal)
            //     isPalindrome = false;

            // auto it = lower_bound(badIndices.begin(), badIndices.end(), l);
            // int badIndex;
            // if (it == badIndices.end())
            //     badIndex = n;
            // else
            //     badIndex = *it;
            // badIndex += 2;
            // debug(badIndex);
            // bool isRepeating = true;
            // if (badIndex <= r)
            // {
            //     isRepeating = false;
            // }

            // => we can compare s[l, l + lenq/2] and s[l + lenq/2, r]
            // => this can be done in O(1) :) using prefix sums of hash values :)

            // if (lenq % 2 == 1)
            // {
            //     if (!isPalindrome && !isRepeating)
            //     {
            //         int cnt = (lastVal + 1) / 2 - 1;
            //         ans += cnt;
            //         // 2 .. 4 .. 6 .. lastVal-1
            //         lastVal--;
            //         lastVal /= 2;
            //         ans += 2 * (lastVal) * (lastVal + 1) / 2.0;
            //         debug(ans);
            //     }
            // }
            // else if (lenq % 2 == 0)
            // {
            auto it = lower_bound(badIndices.begin(), badIndices.end(), l);
            int badIndex;
            if (it == badIndices.end())
                badIndex = n;
            else
                badIndex = *it;
            badIndex += 2;
            // debug(badIndex);
            // debug(r);
            // debug(ans);
            if (badIndex <= r)
            {
                int cnt = (lastVal + 1) / 2 - 1;
                ans += cnt;
                // 2 .. 4 .. 6 .. lastVal-1
                lastVal--;
                lastVal /= 2;
                ans += 2 * (lastVal) * (lastVal + 1) / 2.0;
                //     }
                // }
                // debug(ans);
            }
        }
        else if (cntUniqueChars >= 3) // then the substr can be (k-good) for 2<=k<=lenq-1
        {
            ans += (lenq - 1) * (lenq) / 2.0; // 2-good to (lenq-1)-good
            ans -= 1;                         // since it cannot be 1-good
            int hVal = hashValue[r] + mod;
            if (l - 1 >= 0)
                hVal -= hashValue[l - 1]; // this is h(s[i..j]) * p^i :)
            // on reversing, s[l] goes to sRev[n-1-l],
            // and s[r] goes to sRev[n-r-1]
            // where n-r <= n-l
            int revHVal = revHashValue[n - 1 - l] + mod;
            if (n - r - 2 >= 0)
                revHVal -= revHashValue[n - r - 2];
            hVal %= mod;
            revHVal %= mod;
            // now hVal = h(s[l...r])*p^l
            // and revHVal = h(s[n-1-r...n-1-l])*p^(n-1-r)
            if (l <= n - 1 - r)
            {
                int diff = n - 1 - r - l;
                hVal *= power_p[diff];
                hVal %= mod;
            }
            else if (l > n - 1 - r)
            {
                int diff = l - n - 1 - r;
                revHVal *= power_p[diff];
                revHVal %= mod;
            }
            if (hVal != revHVal)
                ans += lenq;
        }

        // if (!isPalindrome) // => the query string is lenq-good
        // ans += lenq;
        // h(s[i...j])*p^i = h(s[0..j]) - h(s[0...i-1])

        // => we can compare s[l, l + lenq/2] and s[l + lenq/2, r]
        // => this can be done in O(1) :) using prefix sums of hash values :)

        cout << ans << endl;
    }
}
