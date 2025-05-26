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

vector<char> getNewChars(int n)
{
    vector<char> newChars;
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (newChars.size() < n)
        {
            newChars.push_back(c);
        }
        else
        {
            break;
        }
    }
    return newChars;
}

void suraj()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int minChanges = n;
    string t = s;

    vector<pair<int, char>> freq(26);
    for (int i = 0; i < 26; i++)
    {
        freq[i] = {0, 'a' + i}; // initialize frequency and character
    }
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        freq[ch - 'a'].first++;
        freq[ch - 'a'].second = ch;
    }
    // sort in order of frequency
    sort(freq.rbegin(), freq.rend());
    // debug(freq);

    vector<vector<int>> grid(26, vector<int>());
    // grid[i] will contain the indices of character 'a' + i in the string s
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        int index = i;
        grid[ch - 'a'].push_back(index);
    }

    // debug(grid);

    for (int i = 1; i <= 26; i++)
    {
        int nChanges = 0;
        // i = no of distinct characters in t
        int targetFreq = n / i;
        if (n % i != 0)
            continue;

        // debug(targetFreq);
        vector<pair<char, int>> extras;
        vector<char> missing;
        for (int j = 0; j < i; j++)
        {
            int freqChar = freq[j].first;
            char ch = freq[j].second;
            // debug(freqChar);
            // debug(ch);
            // debug(freqChar);

            if (freqChar > targetFreq)
            {
                int diff = freqChar - targetFreq;
                nChanges += (diff);
                // debug(diff);
                // extras.push_back(freq[j].second);
                for (int k = 0; k < diff; k++)
                    extras.push_back(make_pair(ch, grid[ch - 'a'][k]));
            }
            else if (freqChar < targetFreq)
            {
                int diff = targetFreq - freqChar;
                nChanges += (diff);
                // debug(diff);
                // missing.push_back(freq[j].second);
                for (int k = 0; k < diff; k++)
                {
                    missing.push_back(ch);
                }
            }
            // debug(nChanges);
            // debug(extras);
            // debug(missing);
            // debug(nChanges);
        }
        for (int j = i; j < 26; j++)
        {
            int freqChar = freq[j].first;
            char ch = freq[j].second;
            if (freqChar > 0) // these chars are not allowed in t currently :)
            {
                nChanges += freqChar;
                for (int k = 0; k < freqChar; k++)
                    extras.push_back(make_pair(ch, grid[ch - 'a'][k]));
            }
        }

        // debug(extras);
        // debug(missing);

        // debug(nChanges);
        if (nChanges / 2 < minChanges)
        {
            minChanges = nChanges / 2;
            t = s;
            for (pair<char, int> pr : extras)
            {
                // char ch = pr.first;
                int index = pr.second;
                t[index] = missing.back();
                missing.pop_back();
            }
        }
    }

    cout << minChanges << endl;
    cout << t << endl;
}
