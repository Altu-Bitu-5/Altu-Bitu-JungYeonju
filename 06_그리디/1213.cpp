#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    const int ALPHA_NUM = 26;

    string name;
    string odd, even;
    vector<int> alpha(ALPHA_NUM, 0);

    cin >> name;
    for (int i = 0; i < name.size(); i++)
    {
        alpha[name[i] - 'A']++;
    }

    for (int i = 0; i < ALPHA_NUM; i++)
    {
        if (alpha[i] % 2 == 1)
        {
            odd += (i + 'A');
            alpha[i]--;
        }
    }

    if (odd.size() > 1)
    {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    for (int i = 0; i < ALPHA_NUM; i++)
    {
        while (alpha[i] && alpha[i] % 2 == 0)
        {
            even += (i + 'A');
            alpha[i] -= 2;
        }
    }

    cout << even << odd;
    reverse(even.begin(), even.end());
    cout << even;

    return 0;
}