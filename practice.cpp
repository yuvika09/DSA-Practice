#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	cin >> a;
	int num = 0, mul = 1;
	while (a > 0)
	{
		if (a % 10 == 0)
		{
			num += 5 * mul;
		}
		else
		{
			num += (a % 10) * mul;
		}
		mul *= 10;
		a /= 10;
	}
	cout << num;
	return 0;
}