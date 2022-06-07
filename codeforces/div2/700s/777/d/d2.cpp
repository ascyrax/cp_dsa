// @author: ascyrax

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

double gct() // get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

void suraj();

int main()
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

//...............................
// const int N = 1000000;

// #define SIEVE
// int primes[N];
// vector<int> pr;
// void sieve()
// {
//         for (int i = 2; i < N; i++)
//         {
//                 if (primes[i] == 0) // means if i is a prime
//                 {
//                         pr.pb(i);
//                         for (int j = i * i; j < N; j += i)
//                                 primes[j] = 1;
//                 }
//                 primes[i] ^= 1;
//         }
// }
bool isPrime(ll d)
{
        for (ll i = 2; i * i <= d; i++)
        {
                if (d % i == 0)
                {
                        return false;
                }
        }
        return true;
}
//...............................

void suraj()
{
        ll x, d;
        cin >> x >> d;

        ll x2 = x;
        ll dInX = 0;
        while (x2 % d == 0)
        {
                dInX++;
                x2 /= d;
        }

        if (dInX == 1)
        {
                cout << "NO" << endl;
                return;
        }

        if (dInX == 2)
        {
                if (x2 != 1 && !isPrime(x2))
                {
                        cout << "YES" << endl;
                }
                else
                        cout << "NO" << endl;
                return;
        }

        // if (dInX ==3) // case (128 4)-> 4 4 4 and x2=2 -> 8 4 4 now if we break the last 4 and distribute it -> 8*2 4*2 or 8*4 4 or 8 4*4. for all these 3 cases a no. is divisible by d^2 i.e = 16. hence (128 4) can be represented in the form of product of beautiful nos in only one way i.e. 8 4 4 4. therefore ans is no.
        if (dInX == 3)
        {
                if (x2 == 1)
                {
                        if (!isPrime(d))
                                cout << "YES" << endl;
                        else
                                cout << "NO" << endl;
                }
                else if (!isPrime(x2))
                {
                        cout << "YES" << endl;
                }
                else
                {
                        if (isPrime(d))
                        {
                                cout << "NO" << endl;
                                return;
                        }
                        if (d % x2 != 0) // x2 is not present in d.
                        {
                                cout << "YES" << endl;
                                return;
                        }
                        // x2 divides d for sure and x2 is a prime.
                        int q = d / x2;
                        if ((x2 * x2) % d == 0)
                                cout << "NO" << endl;
                        else
                                cout << "YES" << endl;
                        // ll a = d, b = d;
                        // ll e, f;
                        // if ((x2 * x2) % d != 0)
                        // {
                        //         e = x2 * x2;
                        //         f = d / x2;
                        //         cout << "YES" << endl;
                        //         return;
                        // }
                        // ll x2needs = d / x2;
                        // ll e = x2 * x2;
                        // ll f = d / x2;
                        // if ((e % d == 0) || (f % d == 0))
                        // {
                        //         cout << "NO" << endl;
                        // }
                        // else
                        //         cout << "YES" << endl;
                }
                return;
        }
        // if(dInX >3) then below works

        if (!isPrime(d))
        {
                cout << "YES" << endl;
        }
        else
        {
                // d is prime
                if ((x2 == 1) || (isPrime(x2)))
                        cout << "NO" << endl;
                else
                        cout << "YES" << endl;
                // if (x2 != 1 && !isPrime(x2))
                // {
                //         cout << "YES" << endl;
                // }
                // else
                // {
                //         cout << "NO" << endl;
                // }
        }
}

//................................

// ll

// int

// int

// int
