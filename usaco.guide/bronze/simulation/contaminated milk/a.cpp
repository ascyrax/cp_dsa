// // @author: ascyrax

// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;

// typedef long double ld;

// #define endl "\n"

// #define ioss                         \
//         ios::sync_with_stdio(false); \
//         cin.tie(0);

// #define pb push_back

// double startTime;

// double gct() // get_current_time
// {
//         return ((double)clock() - startTime) / CLOCKS_PER_SEC;
// }

// void suraj();

// int main()
// {

//         // ioss

//         // startTime=(double)clock();

//         freopen("badmilk.in", "r", stdin);
//         freopen("badmilk.out", "w", stdout);

//         // cout << setprecision(15) << fixed;

//         int t = 1;

//         // cin>>t;

//         for (int i = 1; i <= t; i++)
//         {

//                 // cout<<"Case #"<<i<<": ";

//                 suraj();
//         }

//         return 0;
// }

// //...............................

// //...............................

// void suraj()
// {
//         ll n, m, d, s;
//         cin >> n >> m >> d >> s;

//         // vector<vector<pair<int,ll>>> persons(m + 1, vector<pair<int,ll>>()); // 1-indexed

//         vector<int> vp, vm, vt;

//         map<int, set<int>> milk;

//         for (int i = 0; i < d; i++)
//         {
//                 ll p, m, t;
//                 cin >> p >> m >> t;
//                 // persons[p].pb(make_pair(t, m));
//                 milk[m].insert(p);
//                 vp.pb(p);
//                 vm.pb(m);
//                 vt.pb(t);
//         }

//         // for (int i = 1; i <= m; i++)
//         // {
//         //         sort(persons[i].begin(), persons[i].end());
//         // }

//         vector<int> prevAccused, currAccused;

//         for (int i = 0; i < s; i++)
//         {
//                 ll p, t;
//                 cin >> p >> t;
//                 for (int j = 0; j < d; j++)
//                 {
//                         // cout << vp[j] << " " << vm[j] << " " << vt[j] << endl;
//                         if (vp[j] == p && vt[j] < t)
//                         {
//                                 currAccused.pb(vm[j]);
//                         }
//                 }

//                 if (i == 0)
//                 {
//                         prevAccused = currAccused;
//                         currAccused.clear();
//                         continue;
//                 }

//                 // cout << "i = " << i << endl;

//                 // cout << "prevAccused : " << endl;
//                 // for (auto el : prevAccused)
//                 //         // cout << el << " ";
//                 //         // cout << endl;
//                 //         // cout << "currAccused : " << endl;
//                 //         for (auto el : currAccused)
//                 //                 // cout << el << " ";
//                 //                 // cout << endl;

//                 map<ll, ll> cnt;
//                 for (auto el : currAccused)
//                         cnt[el]++;
//                 for (auto el : prevAccused)
//                         cnt[el]++;
//                 currAccused.clear();
//                 prevAccused.clear();
//                 for (auto el : cnt)
//                 {
//                         if (el.second == 2)
//                                 prevAccused.pb(el.first);
//                 }
//         }
//         ll ans = 0;
//         // cout << "prevAccused: " << endl;
//         for (auto el : prevAccused)
//         {
//                 // cout << el << " ";
//                 ans = max(ans, ll(milk[el].size()));
//         }
//         // cout << endl;
//         cout << ans << endl;
// }

// //................................

// // ll

// // ll

// // int

// // int
#include <bits/stdc++.h>

using namespace std;

#define FastIO                        \
        ios_base::sync_with_stdio(0); \
        cin.tie(0)
#define len(x) (int)(x).length()

void setIO(string fileName = "")
{
        FastIO;
        if (len(fileName))
        {
                freopen((fileName + ".in").c_str(), "r", stdin);
                freopen((fileName + ".out").c_str(), "w", stdout);
        }
}

struct Drinks
{
        int t, p, m;
};

struct Sick
{
        int p, t;
};

int main()
{
        setIO("badmilk");
        int n, m, d, s;
        cin >> n >> m >> d >> s;
        vector<Drinks> drinks(d);
        vector<Sick> sick(s);
        vector<int> drank[n];
        for (int i = 0; i < d; i++)
        {
                cin >> drinks[i].p >> drinks[i].m >> drinks[i].t;
                drinks[i].p--;
                drinks[i].m--;
                drinks[i].t--;
        }
        for (int i = 0; i < s; i++)
        {
                cin >> sick[i].p >> sick[i].t;
                sick[i].p--;
                sick[i].t--;
        }
        for (int i = 0; i < d; i++)
        {
                for (int j = 0; j < s; j++)
                {
                        if (drinks[i].p == sick[j].p && drinks[i].t < sick[j].t)
                        {
                                drank[drinks[i].p].push_back(drinks[i].m);
                        }
                }
        }
        vector<bool> sickMilk(m);
        for (int milk = 0; milk < m; milk++)
        {
                sickMilk[milk] = true;
        }
        for (int milk = 0; milk < m; milk++)
        {
                for (int person = 0; person < n; person++)
                {
                        if (drank[person].size())
                        {
                                bool possible = false;
                                for (int a : drank[person])
                                {
                                        if (a == milk)
                                        {
                                                possible = true;
                                                break;
                                        }
                                }
                                if (!possible)
                                {
                                        sickMilk[milk] = false;
                                }
                        }
                }
        }
        vector<bool> isSick(n);
        for (int milk = 0; milk < m; milk++)
        {
                for (int i = 0; i < d; i++)
                {
                        if (sickMilk[milk] && drinks[i].m == milk)
                        {
                                isSick[drinks[i].p] = true;
                        }
                }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
                ans += isSick[i];
        }
        cout << ans << endl;
}