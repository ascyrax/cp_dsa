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

void suraj()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int finalAns = n;
    string finalS;

    vector<vector<int>> indicesOf(26, vector<int>());
    for (int i = 0; i < n; i++)
    {
        indicesOf[s[i] - 'a'].push_back(i);
    }

    vector<int> v(26, 0);
    set<pair<int, int>> st;
    for (char c : s)
        v[c - 'a']++;
    // debug(v);
    for (int i = 0; i < 26; i++)
        st.insert(make_pair(v[i], i));
    // debug(st);
    vector<pair<int, int>> sortedPair;
    for (auto el : st)
        sortedPair.push_back(el);
    // debug(sortedPair);

    for (int i = 1; i <= 26; i++) // no of distinct chars
    {
        // debug(i);
        int tempAns = 0;
        string tempS = s;

        if (n % i != 0)
            continue;

        vector<int> targetIndices;
        vector<char> targetChars;

        int nRepeats = n / i; // each char will be present nRepeats times :)
        int nChanges = 0;
        for (int j = 0; j < 26; j++)
        {
            if (v[j] > nRepeats)
            {
                int diff = v[j] - nRepeats;
                nChanges += diff;
                tempAns += diff;
                for (int k = 0; k < diff; k++)
                {
                    targetIndices.push_back(indicesOf[j][k]);
                }
            }
        }

        // debug(targetIndices);

        // debug(nRepeats);
        // debug(nChanges);

        int ptr = -1;
        for (int j = 0; j < 26; j++)
        {
            if (sortedPair[j].first >= nRepeats)
            {
                // ptr = j;
                break;
            }
            ptr = j;
        }
        // if (ptr == -1)
        //     ptr = 25;

        // debug(ptr);

        int ptrL = 0;
        for (int j = 0; j < 26; j++)
        {
            if (sortedPair[j].first != 0)
            {
                ptrL = j;
                break;
            }
        }

        for (int ind = ptr; (ind >= ptrL) || (nChanges > 0); ind--)
        {
            int diff = nRepeats - sortedPair[ind].first;
            // debug(sortedPair[ind].second + 'a');
            char targetChar = sortedPair[ind].second + 'a';
            // debug(targetChar);

            // debug(diff);

            for (int j = 0; j < diff; j++)
                targetChars.push_back(targetChar);

            // debug(targetChars);

            if (diff > nChanges)
            {
                diff -= nChanges;
                nChanges = 0;
                while (1)
                {
                    char ch = sortedPair[ptrL].second;
                    char cnt = sortedPair[ptrL++].first;
                    nChanges += cnt;
                    tempAns += cnt;
                    for (int j = 0; j < cnt; j++)
                        targetIndices.push_back(indicesOf[ch][j]);
                    if (diff <= nChanges)
                        break;
                }
                int tempVal = diff;
                diff -= nChanges;
                nChanges -= tempVal;
            }
            else
            {
                nChanges -= diff;
            }
            // debug(nChanges);
        }

        // debug(targetIndices);
        // debug(targetChars);

        for (int j = 0; j < targetIndices.size(); j++)
        {
            tempS[targetIndices[j]] = targetChars[j];
        }

        // debug(tempAns);
        // debug(tempS);

        if (tempAns < finalAns)
        {
            finalAns = tempAns;
            finalS = tempS;
        }
    }

    cout << finalAns << endl;
    cout << finalS << endl;
}
