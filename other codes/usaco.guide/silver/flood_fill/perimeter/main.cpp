/*
ID: ascyrax1
TASK: test
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define pb push_back

double startTime;
double gct() //get_current_time
{
    return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int n;
vector<string> grid(1000);
vector<pair<int, int>> vp;
int a = 0, p = 0;
vector<vector<bool>> visited(1001);

void flood_fill(int i, int j, char ch)
{
    if (i < 0 || j < 0 || i >= n || j >= n)
        return;
    if (visited[i][j])
        return;
    if (grid[i][j] == '.')
        return;
    visited[i][j] = true;
    //p--;//one among the four boundaries of the # needs to be decreased because of the adjacent #
    //p+=3;//this new adjacent # will add 3 of its boundaries to the perimeter
    a++; //this new adjacent # will add 1 area
         //    cout<<a<<" "<<p<<endl;
    p += 4;
    // cout << "p = " << p << endl;
    if (j + 1 < n && grid[i][j + 1] == '#')
        p--;
    if (j - 1 >= 0 && grid[i][j - 1] == '#')
        p--;
    if (i + 1 < n && grid[i + 1][j] == '#')
        p--;
    if (i - 1 >= 0 && grid[i - 1][j] == '#')
        p--;
    // cout << "p = " << p << endl;
    flood_fill(i, j + 1, ch);
    flood_fill(i, j - 1, ch);
    flood_fill(i - 1, j, ch);
    flood_fill(i + 1, j, ch);
    return;
}

bool custom_sort(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

void suraj()
{ ///////////////////////
    cin >> n;
    grid.resize(n);
    visited.resize(n);
    for (int i = 0; i < n; i++)
    {
        visited[i] = vector<bool>(n); //
    }
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        grid[i] = a;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && grid[i][j] == '#')
            {
                a = 0;
                p = 0;
                flood_fill(i, j, '#');
                vp.pb(make_pair(a, p));
            }
        }
    }

    //for(auto i:vp){
    //    cout<<i.first<<" "<<i.second<<endl;
    //}
    sort(vp.begin(), vp.end(), custom_sort);
    // for (auto a : vp)
    //     cout << a.first << " " << a.second << endl;
    cout << vp[0].first << " " << vp[0].second << endl;

} ////////////////////////////

int main()
{
    startTime = (double)clock();
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
