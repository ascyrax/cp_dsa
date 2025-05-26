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
#define mp make_pair
#define pb push_back
#define ppb pop_back
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

void suraj()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int minChanges = n;
    string finalString = s;

    map<char, int> cntOf;
    for (char ch : s)
    {
        cntOf[ch]++;
    }

    // int ptrL = 0, ptrR = 1;

    vector<vector<int>> indexOf(26, vector<int>());
    for (int i = 0; i < n; i++)
    {
        char ch = s[i] - 'a';
        indexOf[ch].push_back(i);
    }
    // debug(cntOf);
    // debug(indexOf);

    for (int i = 1; i <= 26; i++)
    {
        // here i = no of distinct characters in the final string :)

        int distinctChars = i;
        int freqIncludedChars = n / distinctChars;
        if (n % distinctChars != 0)
            continue;

        debug(cntOf);
        debug(indexOf);

        vector<pair<pair<int, int>, char>> v;
        for (auto el : cntOf)
        {
            char ch = el.first;
            int charCnt = el.second;
            v.push_back(make_pair(make_pair(abs(charCnt - freqIncludedChars), freqIncludedChars - charCnt), ch));
        }

        sort(v.begin(), v.end());

        debug(distinctChars);
        debug(freqIncludedChars);

        debug(v);

        vector<pair<char, int>> extra;
        vector<char> missing;

        for (int j = 0; j < distinctChars && j < v.size(); j++)
        {
            debug(j);
            // int diff = v[j].first;
            char ch = v[j].second;
            int charCnt = cntOf[ch];
            debug(ch);
            debug(charCnt);
            if (charCnt > freqIncludedChars)
            {
                int diff = charCnt - freqIncludedChars;
                for (int k = 0; k < diff; k++)
                {
                    extra.push_back(make_pair(ch, indexOf[ch - 'a'][k]));
                }
            }
            else if (charCnt < freqIncludedChars)
            {
                int diff = freqIncludedChars - charCnt;
                for (int k = 0; k < diff; k++)
                {
                    missing.push_back(ch);
                }
            }
        }

        for (int j = distinctChars; j < v.size(); j++)
        {
            char ch = v[j].second;
            int charCnt = cntOf[ch];
            // debug(ch);
            // debug(charCnt);
            for (int k = 0; k < charCnt; k++)
            {
                // debug(k);
                extra.push_back(make_pair(ch, indexOf[ch - 'a'][k]));
                // debug(extra);
            }
            // debug("HI");
        }

        debug(extra);
        debug(missing);

        if (extra.size() < minChanges)
        {
            minChanges = extra.size();
            finalString = s;
            // if extra and missing are equal in size :)
            if (extra.size() == missing.size())
            {
            }
            else if (extra.size() < missing.size())
            {
                // this should never happen
            }
            else if (extra.size() > missing.size())
            {
                // if extra > missing in size :)
                // we gotta include a character which is not even present in the initial string s
                for (int i = 0; i < 26; i++)
                {
                    if (indexOf[i].size() == 0)
                    {
                        char ch = i + 'a';
                        for (int j = 0; j < freqIncludedChars; j++)
                        {
                            missing.push_back(ch);
                        }
                    }
                }
            }
            for (int i = 0; i < extra.size(); i++)
            {
                finalString[extra[i].second] = missing[i];
            }
        }

        debug(minChanges);
        debug(finalString);
    }

    cout << minChanges << endl
         << finalString << endl;
}
