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
void print(string s, vector<pair<int, int>> vp)
{
  cout << s << endl;
  for (auto el : vp)
  {
    cout << el.first << " " << el.second << endl;
  }
}
int inf = 1e18;
int mod = 1e9 + 7;
// int mod = 998244353;
//.....................................

//.....................................

//.....................................

void suraj()
{

  int n, m, k;
  cin >> n >> m >> k;

  stack<int> st;
  stack<int> temp;
  for (int i = 0; i < k; i++)
  {
    int a;
    cin >> a;
    a--;
    temp.push(a);
  }
  while (!temp.empty())
  {
    st.push(temp.top());
    temp.pop();
  }

  int emptyCells = n * m - 2;
  int ptr = k - 1;
  vector<bool> isStacked(k, true); // whether the card with this no is still stacked at 1,1.
  while (1)
  {
    if (!st.empty())
    {
      int top = st.top();
      st.pop();
      // cout << "top: " << top << " , emptyCells: " << emptyCells << " , ptr: " << ptr << endl;
      // ;
      isStacked[top] = false;
      emptyCells--;
      if (!(n == 2 && m == 2) && emptyCells == 0)
      {
        cout << "TIDAK" << endl;
        return;
      }
      else if (n == 2 && m == 2 && emptyCells == 0)
      {
        if (top != ptr)
        {
          cout << "TIDAK" << endl;
          return;
        }
        else
        {
          if (top == ptr)
          {
            while (ptr >= 0)
            {
              if (isStacked[ptr] == false)
              {
                emptyCells++;
                ptr--;
              }
              else
                break;
            }
            if (ptr < 0)
            {
              cout << "YA" << endl;
              return;
            }
          }
        }
      }
      if (top == ptr)
      {
        while (ptr >= 0)
        {
          if (isStacked[ptr] == false)
          {
            emptyCells++;
            ptr--;
          }
          else
            break;
        }
        if (ptr < 0)
        {
          cout << "YA" << endl;
          return;
        }
      }
    }
    else
    {
      cout << "YA" << endl;
      return;
    }
  }
}
