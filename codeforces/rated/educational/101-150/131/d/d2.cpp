// @author: ascyrax
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define ioss                   \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

double startTime;

double gct() // get_current_time
{
  return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

void suraj();

signed main()
{

  ioss

      // startTime=(double)clock();

      // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

      // cout << setprecision(15) << fixed;

      int t = 1;

  cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

int inf = 1e18;
int mod = 1e9 + 7;
//.....................................

void print(string s, vector<int> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
void print(string s, set<int> st)
{
  cout << s << endl;
  for (auto el : st)
    cout << el << " ";
  cout << endl;
}
void print(string s, vector<pair<pair<int, int>, int>> st)
{
  cout << s << endl;
  for (auto el : st)
    cout << el.first.first << " " << el.first.second << " " << el.second << endl;
  cout << endl;
  cout << "----" << endl;
}
void print(string s, vector<pair<int, int>> vp)
{
  cout << s << endl;
  for (auto el : vp)
  {
    cout << el.first << " " << el.second << endl;
  }
}
//.....................................

//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> b[i];
  }

  vector<pair<pair<int, int>, int>> leftSorted;
  for (int i = 1; i <= n; i++)
  {

    int mnai = i / (b[i] + 1) + 1;
    int mxai;
    if (b[i] != 0)
      mxai = min(n, i / (b[i])); // i.e = 1/b[i] basically
    else
      mxai = n;
    // cout << "i: " << i << " b[i]: " << b[i] << " , left: " << mnai << " , right: " << mxai << endl;
    leftSorted.pb(make_pair(make_pair(mnai, mxai), i));
  }
  sort(leftSorted.begin(), leftSorted.end());
  print("leftSorted", leftSorted);

  set<pair<pair<int, int>, int>> st; // el.second is the index.
  int ptr = 0;
  vector<int> ans(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    // cout << "I: " << i << endl;
    while (ptr < leftSorted.size() && leftSorted[ptr].first.first <= i)
    {
      st.insert(make_pair(make_pair(leftSorted[ptr].first.second, leftSorted[ptr].first.first), leftSorted[ptr].second));
      ptr++;
    }
    while (!st.empty())
    {
      auto top = *(st.begin());
      if (top.first.first < i)
        st.erase(st.begin());
      else
        break;
    }
    // cout << top.first.first << " " << top.first.second << " " << top.second << endl;
    ans[(*st.begin()).second] = i;
    st.erase(st.begin());
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << " ";
  cout << endl;
}
