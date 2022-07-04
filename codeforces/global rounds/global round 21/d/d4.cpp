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
//.....................................
void print(string s, vector<int> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
//.....................................

int n;
vector<int> v;
vector<int> prefixMin, prefixMax;
vector<int> postfixMin, postfixMax;
vector<int> indexOf;
//.....................................
int dist(int l, int r)
{
  if (l == r)
    return 0;
  // cout << "l: " << l << ", r: " << r << endl;
  int minLeft = prefixMin[r];
  int maxLeft = prefixMax[r];

  int minRight = postfixMin[l];
  int maxRight = postfixMax[l];

  // cout << "maxRight: " << maxRight << ", minRight: " << minRight << endl;

  if ((v[l] == minLeft && v[r] == maxLeft) || (v[l] == maxLeft && v[r] == minLeft))
  {
    // cout << "if" << endl;
    if (l == r)
      return 0;
    else
      return 1;
  }
  else if ((v[l] == minRight && v[r] == maxRight) || (v[l] == maxRight && v[r] == minRight))
  {
    // cout << "else if" << endl;
    // cout << "true" << endl;
    if (l == r)
      return 0;
    else
      return 1;
  }

  if (l == 0)
  {
    // cout << "l==0" << endl;
    if (v[r] == maxLeft)
    {
      // return dist(0, indexOf[minLeft]) + dist(indexOf[minLeft], r); // cz dist(indexOf[minLeft],r) = 1 as there is a direct edge between these two
      return dist(0, indexOf[minLeft]) + 1;
    }
    else if (v[r] == minLeft)
    {
      // return dist(0, indexOf[maxLeft]) + dist(indexOf[maxLeft], r);
      return dist(0, indexOf[maxLeft]) + 1;
    }
  }
  if (r == n - 1)
  {
    // cout << "r==n-1" << endl;
    if (v[l] == maxRight)
    {
      // cout << "v[l] == maxRight" << endl;
      // return dist(l, indexOf[minRight]) + dist(indexOf[minRight], n - 1);
      return 1 + dist(indexOf[minRight], n - 1);
    }
    else if (v[l] == minRight)
    {
      // cout << "v[l] == minRight" << endl;
      // return dist(l, indexOf[maxRight]) + dist(indexOf[maxRight], n - 1);
      return 1 + dist(indexOf[maxRight], n - 1);
    }
  }
  // return 1;
}
//.....................................

void suraj()
{
  cin >> n;
  v = vector<int>(n);
  indexOf = vector<int>(n + 1);
  prefixMin = vector<int>(n, inf);
  prefixMax = vector<int>(n, -inf);
  postfixMin = vector<int>(n, inf);
  postfixMax = vector<int>(n, -inf);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    indexOf[v[i]] = i;
  }

  prefixMin[0] = v[0];
  prefixMax[0] = v[0];
  for (int i = 1; i < n; i++)
  {
    prefixMin[i] = min(prefixMin[i - 1], v[i]);
    prefixMax[i] = max(prefixMax[i - 1], v[i]);
  }

  postfixMin[n - 1] = v[n - 1];
  postfixMax[n - 1] = v[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    postfixMin[i] = min(postfixMin[i + 1], v[i]);
    postfixMax[i] = max(postfixMax[i + 1], v[i]);
  }

  // print("prefixMin", prefixMin);
  // print("prefixMax", prefixMax);
  // print("postfixMin", postfixMin);
  // print("postfixMax", postfixMax);

  int maxLeft = prefixMax[n - 1];
  int minLeft = prefixMin[n - 1];

  // cout << "--" << endl;
  // cout << dist(0, indexOf[maxLeft]) << endl;
  // cout << "--" << endl;
  // cout << dist(indexOf[maxLeft], n - 1) << endl;
  // cout << "--" << endl;

  int ans = dist(0, indexOf[maxLeft]) + dist(indexOf[maxLeft], n - 1);
  cout << ans << endl;
}
