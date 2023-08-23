#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmpArr(string a, string b)
{
	if (a.size() == b.size())
	{
		int digitA = 0, digitB = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] >= '0' && a[i] <= '9')
				digitA += (a[i] - '0');
			if (b[i] >= '0' && b[i] <= '9')
				digitB += (b[i] - '0');
		}
		if (digitA == digitB)
			return a < b;
		else
			return digitA < digitB;
	}
	return a.size() < b.size();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	string input;
	vector<string> serial;

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> input;
		serial.push_back(input);
	}
	sort(serial.begin() , serial.end(), cmpArr);
	for (int i = 0; i < serial.size(); i++)
	{
		cout << serial[i] << "\n";
	}
	return 0;
}