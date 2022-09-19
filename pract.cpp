#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int a;
		cin >> a;
		int arr[a];
		if (a % 2 == 0) // even
		{
			int i;
			for (i = 0; i < a - 2; i++)
			{
				if (i % 2 == 0)
					arr[i] = i + 2;
				else
					arr[i] = i;
			}
			arr[a - 2] = a - 1;
			arr[a - 1] = a;
		}
		else // odd
		{
			int i;
			arr[0] = 1;
			for (i = 1; i < a - 2; i++)
			{
				if (i % 2 == 0)
					arr[i] = i;
				else
					arr[i] = i + 2;
			}
			arr[a - 2] = a - 1;
			arr[a - 1] = a;
		}
		for (int i = 0; i < a; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}