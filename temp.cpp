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

    // cin>>t;

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
string solve(string &cipherText, int diff)
{
    cout << "solve" << endl;
    debug(cipherText);
    debug(diff);
    string result = "";
    for (char ch : cipherText)
    {
        // debug(ch);
        // cout << (ch + diff) << endl;
        if (ch >= 65 && ch <= 90)
        {
            if (ch + diff < 65)
                result += ch + diff + 26;
            else if (ch + diff > 90)
                result += ch + diff - 26;
            else
                result += ch + diff;
        }
        else if (ch >= 97 && ch <= 122)
        {
            if (ch + diff < 97)
                result += ch + diff + 26;
            else if (ch + diff > 122)
                result += ch + diff - 26;
            else
                result += ch + diff;
        }
        // else if (ch == ' ')
        else // ie ch could be anything
        {
            result += ch;
        }
        // debug(result);
    }

    return result;
}

string decode(string &cipherText, string &knownWord)
{
    vector<string> words;
    string word = "";
    for (char ch : cipherText)
    {
        if (ch == ' ')
        {
            words.push_back(word);
            word = "";
        }
        else
        {
            word += ch;
        }
    }
    if (word.size() > 0)
        words.push_back(word);
    word = "";
    debug(words);

    string result = "Invalid";

    for (string word : words)
    {
        bool flag = false;
        int diff = 100;
        // match word and knownWord
        if (word.size() == knownWord.size())
        {
            for (int i = 0; i < knownWord.size(); i++)
            {
                if (knownWord[i] < 65 || (knownWord[i] > 90 && knownWord[i] < 97) || knownWord[i] > 122)
                {
                    if (knownWord[i] - word[i] == 0)
                    {
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    if (diff != 100)
                    {
                        if (knownWord[i] - word[i] == diff)
                            flag = true;
                        else
                        {
                            flag = false;
                            break;
                        }
                    }
                    else
                    {
                        diff = knownWord[i] - word[i];
                    }
                }
            }
        }
        if (flag)
        {
            result = solve(cipherText, diff);
            break;
        }
    }

    return result;
}

void suraj()
{
    string cipherText, knownWord;
    cipherText = "nqxg! dwiu nqxg!";
    knownWord = "love";
    string result = decode(cipherText, knownWord);
    cout << result << endl;
}
