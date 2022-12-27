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

  // ioss

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

//.....................................

//.....................................
void print(string s, vector<int> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
int sum(int cur, int prev)
{
  int scur = (cur * (cur + 1)) / 2;
  int sprev = (prev * (prev + 1)) / 2;
  return scur - sprev;
}
//.....................................

void suraj()
{
  // inputs
  int n;
  cin >> n;

  vector<int> k(n), h(n);

  for (int &i : k)
    cin >> i;
  for (int &i : h)
    cin >> i;

  // algo part

  vector<int> parent(n);
  parent[0] = 0;
  for (int i = 1; i < n; i++)
  {
    int kDiff = k[i] - k[i - 1];
    if (h[i] > kDiff)
      parent[i] = parent[i - 1];
    else
      parent[i] = i;
  }
  print("parent", parent);
  vector<int> startValue(n, 1);
  // trusting that h[0] wont be > k[0].
  // startValue[0] = h[0];
  for (int i = 0; i < n; i++)
  {
    if (parent[i] != i)
    {
      startValue[parent[i]] = max(startValue[parent[i]], h[i] - (k[i] - k[parent[i]]));
    }
    else
      startValue[parent[i]] = h[i];
  }
  print("startValue", startValue);
  int leastMana = 0;
  int prev = 0;
  for (int i = 0; i < n; i++)
  {
    if (parent[i] == i)
      prev = 0;
    int current = (startValue[parent[i]] + (k[i] - k[parent[i]]));
    leastMana += sum(current, prev);
    prev = current;
    // leastMana += current;
  }
  // output

  cout << leastMana << endl;
  cout << "-------------------------" << endl;
}
