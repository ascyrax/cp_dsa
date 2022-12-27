#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
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
        for (int i = 1; i <= t; i++) //{cout<<"Case #"<<i<<": ";
                suraj();
        //}
        return 0;
}

// @author: ascyrax

const int mod = 1e9 + 7;

//...............................

// void suraj()
// {
//         ll n, a, b;
//         cin >> n >> a >> b;
//         ll n2 = n;
//         bool flag = false;
//         if (n == 1)
//                 cout << "Yes" << endl;
//         if (n % a == 0)
//         {
//                 cout << "Yes" << endl;
//                 return;
//         }
//         else
//         {
//                 n = n % a;
//                 // cout << "n%a = " << n % a << endl;
//                 // cout << "n = " << n << endl;
//                 // cout << "n%b = " << n % b << endl;
//                 if (n % b == 0)
//                 {
//                         cout << "Yes" << endl;
//                         return;
//                 }

//                 else
//                 {
//                         flag = false;
//                         // ie cout << "No" << endl;
//                         ll rem = n % b;
//                         cout << rem << endl;
//                         //x*a+rem=b*y hona chahiye

//                         ll x = 1, y = 1;
//                         while (x * a + y * b + rem <= n2)
//                         {
//                                 if (x * a + rem == y * b)
//                                 {
//                                         cout << "Yes" << endl;
//                                         return;
//                                 }
//                                 else if (x * a + rem > y * b)
//                                 {
//                                         y++;
//                                 }
//                                 else
//                                 {
//                                         x++;
//                                 }
//                         }
//                         cout << "No" << endl;
//                 }
//         }
// }
// //flag is false
// // if (n2 % b == 0)
// // {
// //         cout << "Yes" << endl;
// //         return;
// // }
// // else
// // {
// //         n2 = n2 % b;
// //         if (n2 % a == 0)
// //         {
// //                 cout << "Yes" << endl;
// //         }
// //         else
// //         {
// //                 //ie  flag=false; still
// //                 cout << "No" << endl;
// //         }
// // }

// //................................
void suraj()
{
        int n, a, b;
        cin >> n >> a >> b;
        //n can be pow(a,k)+x*b;
        if (a == 1)
        {
                if ((n - 1) % b == 0)
                {
                        cout << "Yes" << endl;
                }
                else
                        cout << "No" << endl;
        }
        else if (b == 1)
        {
                cout << "Yes" << endl;
        }
        else
        {
                for (int i = 0; pow(a, i) <= n && i <= 30; i++)
                {
                        if ((n - int(pow(a, i))) % b == 0)
                        {
                                cout << "Yes" << endl;
                                return;
                        }
                }
                cout << "No" << endl;
        }
}