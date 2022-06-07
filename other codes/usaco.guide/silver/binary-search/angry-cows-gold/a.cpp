// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// typedef long double ld;

// #define size(x) (int)(x).size()
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
//         freopen("angry.in", "r", stdin);
//         freopen("angry.out", "w", stdout);
//         ioss
//         //int t;cin>>t;for(int i=1;i<=t;i++)
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
//         int n;
//         cin >> n;
//         vector<int> v(n);
//         for (int &i : v)
//                 cin >> i;
//         sort(v.begin(), v.end());
//         float min = 0, max = 1e9, mid = min + (max - min) / 2;

//         while (max - min > 0.1)
//         {
//                 // cout << min << " " << max << endl;
//                 mid = min + (max - min) / 2;
//                 int flag = 0;
//                 for (int i = 1; i < n; i++)
//                 {
//                         if (v[i] - v[i - 1] <= mid - 1)
//                                 continue;
//                         else
//                         {
//                                 if (flag == 1) //ie the cow has already been placed at some x
//                                 {
//                                         flag = -1;
//                                         min = mid + 1;
//                                         break;
//                                 }
//                                 else // ie we can place the cow if diffX <= 2*mid
//                                 {
//                                         if (v[i] - v[i - 1] > 2 * mid)
//                                         {
//                                                 flag = -1;
//                                                 min = mid + 1; //cz mid is invalid so we need sth gt(>) mid
//                                         }
//                                         else
//                                         {
//                                                 flag = 1; //the only cow is placed now and if diff>mid-1 again =>increade mid
//                                         }
//                                 }
//                         }
//                 }
//                 if (flag == 0 || flag == 1)
//                 {
//                         max = mid;
//                 }
//                 flag = 0;
//         }
//         // cout << min << " " << mid << " " << max << endl;
//         // mid = mid + (max - mid) / 2;
//         // printing a no with 1 place after decimal intact
//         int cnt = 0;
//         int midcopy = mid;
//         while (midcopy > 0)
//         {
//                 midcopy /= 10;
//                 cnt++;
//         }
//         cout << fixed << setprecision(1) << mid << endl;
// }

// //................................

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define size(x) (int)(x).size()
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
        freopen("angry.in", "r", stdin);
        freopen("angry.out", "w", stdout);
        ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)
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
        int n;
        cin >> n;
        vector<float> v(n);
        for (float &i : v)
                cin >> i;
        vector<float> minRight(n), minLeft(n);
        //where minLeft[i]= min r(power) with which the ith haybale should burst such that all the haybales on the left will also burst out
        minRight[n - 1] = 0;
        sort(v.begin(), v.end());
        for (int i = n - 2; i >= 0; i--)
        {
                float diff = v[i + 1] - v[i];
                minRight[i] = max(minRight[i + 1], diff + 1);
        }

        minLeft[0] = 0;
        for (int i = 1; i < n; i++)
        {
                float diff = v[i] - v[i - 1];
                minLeft[i] = max(minLeft[i - 1], diff + 1);
        }
        // for (int i = 0; i < n; i++)
        // {
        //         minBoth[i] = max(minLeft[i], minRight[i]);
        // }
        // sort(minBoth.begin(), minBoth.end());
        // for (int i : v)
        //         cout << i << " ";
        // cout << endl;
        // for (int i : minLeft)
        //         cout << i << " ";
        // cout << endl;
        // for (int i : minRight)
        //         cout << i << " ";
        // cout << endl;
        float ans = 1e9;
        for (int i = 0; i < n; i++)
        {
                ans = min(ans, max(minLeft[i], minRight[i]));
        }
        // cout << ans << endl;
        for (int i = 0; i <= n - 2; i++)
        {
                float diff = v[i + 1] - v[i];
                float left = minLeft[i];
                float right = minRight[i + 1];
                // cout << diff << " " << left << " " << right << endl;
                if (max(left, right) < ans)
                {
                        ans = min(ans, max(diff / 2, max(left, right)));
                }
        }
        cout << fixed << setprecision(1) << ans << endl;
}

//................................
