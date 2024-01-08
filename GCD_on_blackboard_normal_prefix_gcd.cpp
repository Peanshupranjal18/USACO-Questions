#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define intt long long int
#define ll long long
#define ld long double
#define MOD 1000000007
#define f(i, n) for (intt i = 0; i < n; i++)
#define ff(i, a, b) for (intt i = a; i < b; i++)
#define pb push_back
#define ii pair<intt, intt>
#define vi vector<intt>
#define vvi vector<vector<intt>>
#define vpi vector<pair<intt, intt>>
#define fi first
#define sec second
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define minv *min_element
#define maxv *max_element
#define rt return
#define um unordered_map
#define acc accumulate
#define sz(x) x.size()
#define ub upper_bound
#define lb lower_bound
#define mt multiset
#define rs resize
#define mah priority_queue<intt>
#define mih priority_queue<intt, vector<intt>, greater<intt>>
#define mahp priority_queue<pair<intt, intt>>
#define mihp priority_queue<pair<intt, intt>, vector<pair<intt, intt>>, greater<pair<intt, intt>>>
using namespace std;
using namespace __gnu_pbds;

// Right Left Up Down
intt dx[] = {0, 0, 1, -1};
intt dy[] = {1, -1, 0, 0};
intt a, b, n, m;

bool possible(int x, int y)
{
    return (x < n && x >= 0 && y < m && y >= 0);
}

intt gcd(intt a, intt b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

const int maxN = (1e5 + 5);
intt pref[maxN];
intt suff[maxN];
intt v[maxN];

// vi v, v1, v2, v3, v4;
vi dp(200001);

bool isPrime(intt n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (intt i = 5; i <= sqrt(n); i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

// oset<int>s:s.find_by_order(k):Kth element in s,s.order_of_key(k):Number of item strictly lessthan k
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    cin >> n;
    ff(i, 1, n + 1) cin >> v[i];
    pref[0] = 0;
    suff[n + 1] = 0;
    ff(i, 1, n + 1) pref[i] = gcd(pref[i - 1], v[i]);
    for (intt i = n; i >= 1; i--)
        suff[i] = gcd(suff[i + 1], v[i]);
    intt res = 0;
    for (int i = 1; i <= n; ++i)
    {
        res = max(res, gcd(pref[i - 1], suff[i + 1]));
    }
    cout << res << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // intt tc;cin>>tc;while(tc--)
    solve();
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int maxN = 1e5 + 5;

// int arr[maxN];
// int prefGcd[maxN]; // prefGcd[i] = GCD of a1,a2, ..., ai
// int suffGcd[maxN]; // suffGcd[i] = GCD of ai, ai+1, ..., an
// int N;

// int gcd(int a, int b)
// {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cin >> N;
//     for (int i = 1; i <= N; ++i)
//         cin >> arr[i];

//     prefGcd[0] = 0;
//     suffGcd[N + 1] = 0;

//     for (int i = 1; i <= N; ++i)
//     {
//         prefGcd[i] = gcd(prefGcd[i - 1], arr[i]);
//     }

//     for (int i = N; i >= 1; --i)
//     {
//         suffGcd[i] = gcd(suffGcd[i + 1], arr[i]);
//     }

//     int res = 0;
//     for (int i = 1; i <= N; ++i)
//     {
//         res = max(res, gcd(prefGcd[i - 1], suffGcd[i + 1]));
//     }
//     cout << res << '\n';
// }