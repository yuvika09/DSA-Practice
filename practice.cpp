#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b / gcd(a, b))
using namespace std;

void solve()
{
	int a, b, c;
	cin >> a >> b >> c;
	int sum = a + b + c;
	if (sum % 3 == 0)
	{
		cout << 0;
	}
	else
	{
		cout << 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int q = 1;
	cin >> q;
	while (q--)
	{
		solve();
		cout << endl;
	}
	return 0;
}