#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

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

int main()
{
    startTime = (double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    //ioss
    cout << setprecision(15) << fixed << endl;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //cout<<"Case #"<<i<<": ";
        suraj();
    }
    return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

//...............................

//...............................
bool custom(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
    {
        return true;
    }
    else if (a.first == b.first)
    {
        if (a.second > b.second)
            return true;
        else
            return false;
    }
    else
        return false;
}
//...............................

void suraj()
{
    int n;
    cin >> n;
    vector<int> caveSize(n);
    int sumCaveSize = 0;
    vector<vector<int>> cave(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        caveSize[i] = a;
        sumCaveSize += a;
        for (int j = 0; j < a; j++)
        {
            int b;
            cin >> b;
            cave[i].pb(b);
        }
    }
    vector<pair<int, int>> vminHero(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> tempCave = cave[i];
        int minHero = 0;
        for (int j = 0; j < caveSize[i]; j++)
        {
            minHero = max(minHero, tempCave[j] + 1 - j);
        }
        vminHero[i] = make_pair(minHero, caveSize[i]);
    }
    sort(vminHero.begin(), vminHero.end(), custom);
    int ans = vminHero[0].first;
    // int temp = vminHero[0].first + caveSize[vminHero[0].second];
    int temp = vminHero[0].first + vminHero[0].second;
    for (int i = 1; i < n; i++)
    {
        // temp += caveSize[vminHero[i].second];
        if (temp >= vminHero[i].first)
        {
            // temp = temp + caveSize[vminHero[i].second];
            temp += vminHero[i].second;
        }
        else
        {
            temp = temp + (vminHero[i].first - temp);
        }
    }
    // cout << " ........ " << endl;
    // for (auto i : vminHero)
    //     cout << i.first << " " << i.second << " ";
    // cout << endl;
    // cout << ans << " " << temp << " " << sumCaveSize << endl;
    ans = temp - sumCaveSize;
    cout << ans << endl;
    // cout << "////////////////////////////////////" << endl;
}

//................................
