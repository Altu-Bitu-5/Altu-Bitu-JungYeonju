#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	int ans = 0;
	string str;
	set<string> S;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		S.insert(str);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> str;
		if (S.find(str) != S.end())
			ans++;
	}
	cout << ans;

	return 0;
}