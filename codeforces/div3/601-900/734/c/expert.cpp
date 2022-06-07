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
// double gct() //get_current_time
// {
//         return ((double)clock() - startTime) / CLOCKS_PER_SEC;
// }
// void suraj();

// int main()
// {
//         startTime = (double)clock();
//         //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
//         // ioss
//         int t;
//         cin >> t;
//         for (int i = 1; i <= t; i++)
//         {
//                 //cout<<"Case #"<<i<<": ";
//                 suraj();
//         }
//         return 0;
// }

// // @author: ascyrax

// const ll mod = 1e9 + 7;

// //...............................

// void suraj()
// {
//         int n, k;
//         cin >> n >> k;
//         vector<pair<int, int>> vp(n);
//         for (int i = 0; i < n; i++)
//         {
//                 int a;
//                 cin >> a;
//                 vp[i] = make_pair(a, i);
//         }
//         map<int, int> m;
//         vector<int> vcolor(n);

//         if (k == 1)
//         {
//                 for (auto el : vp)
//                 {
//                         if (m[el.first])
//                         {
//                                 m[el.first]++;
//                                 vcolor[el.second] = 1;
//                         }
//                         else
//                         {
//                                 vcolor[el.second] = 0;
//                         }
//                 }
//                 for (int i : vcolor)
//                         cout << i << " ";
//                 cout << endl;

//                 return;
//         }

//         sort(vp.begin(), vp.end());

//         int currentColor = 1;
//         vcolor[vp[0].second] = currentColor++;
//         int left = 1;
//         for (int i = 1; i < n; i++)
//         {
//                 if (vp[i].first == vp[i - 1].first)
//                 {
//                         if (currentColor == left)
//                         {
//                                 vcolor[vp[i].second] = 0;
//                         }
//                         else
//                         {
//                                 vcolor[vp[i].second] = currentColor++;
//                                 currentColor %= k;
//                         }
//                 }
//                 else
//                 {
//                         left = currentColor;

//                         vcolor[vp[i].second] = currentColor++;
//                 }
//         }
//         cout << "Hi" << endl;
//         for (int i : vcolor)
//                 cout << i << " ";
//         cout << endl;
//         if (currentColor != 1)
//         {
//                 for (int i = 1; i <= currentColor; i++)
//                 {
//                         for (int j : vcolor)
//                         {
//                                 if (j == i)
//                                 {
//                                         j = 0;
//                                         break;
//                                 }
//                         }
//                 }
//         }
//         for (int i : vcolor)
//                 cout << i << " ";
//         cout << endl;
// }

// //................................

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define endl "\n"
#define ioss                         \
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
        ioss int t;
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

void suraj()
{
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> vp(n);

        for (int i = 0; i < n; i++)
        {
                int a;
                cin >> a;
                vp[i] = make_pair(a, i);
        }

        sort(vp.begin(), vp.end());

        int current = 1;
        int started = 1;
        vector<int> vColor(n);
        vColor[vp[0].second] = current++;

        if (current > k) // if k==1 and current ==2
                current -= k;
        for (int i = 1; i < n; i++)
        {
                // cout << vp[i].first << " " << current << endl;
                if (vp[i].first == vp[i - 1].first)
                {
                        if (current != started)
                        {
                                vColor[vp[i].second] = current++;
                        }
                        else
                        {
                                vColor[vp[i].second] = 0; //which is already 0
                        }
                }
                else
                {
                        started = current;
                        vColor[vp[i].second] = current++;
                }
                if (current > k)
                        current -= k;
        }
        if (current > k)
                current -= k;
        if (current == 1)
        {
                //all colors are same in no
                //do nothing
        }
        else
        {
                //color (1 to current-1) is more than color (current to k) by 1 occurence
                int cnt = 0;
                // for (int i = 1; i < current; i++)
                // {
                //         // for (int j = 0; j < n; j++)
                //         // {
                //         //         // if (vColor[j] == i)
                //         //         // {
                //         //         //         vColor[j] = 0;
                //         //         //         break;
                //         //         // }
                //         //         if(vp[j].)
                //         // }
                //         //(i-1)th element of vp
                //         auto vpi = vp[i - 1];
                //         vColor[vp[i - 1].second] = 0;

                // }
                int temp = 0;
                while (true)
                {
                        if (vColor[vp[temp].second] != 0)
                        {
                                vColor[vp[temp].second] = 0;
                                cnt++;
                        }
                        temp++;
                        if (cnt == current - 1)
                                break;
                }
        }
        // int ans = 0;
        for (int i : vColor)
        {
                cout << i << " ";
                // if (i == 1)
                //         ans++;
        }
        // cout << ans << endl;
        cout << endl;
}

//................................
