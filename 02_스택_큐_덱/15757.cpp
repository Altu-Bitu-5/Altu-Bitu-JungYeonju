#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printSum(vector<int> sum)
{
    for (int i = sum.size() - 1; i >= 0; i--)
        cout << sum[i];
}

vector<int> calcSum(int *a, int *b, int size)
{
    vector<int> sum;
    for (int i = size; i >= 1; i--)
    {
        int tmp = a[i] + b[i];
        if (tmp >= 10)
        {
            b[i - 1]++;
            tmp -= 10;
        }
        sum.push_back(tmp);
    }
    if (b[0] != 0)
        sum.push_back(1);

    return sum;
}

void charToInt(string s, int *n, int start)
{
    for (int i = 1; i <= s.size(); i++)
    {
        n[i + start] = s[i - 1] - '0';
    }
}

int main()
{
    string a, b;
    int num_a[10001], num_b[10001];

    cin >> a >> b;
    if (a.size() > b.size())
    {
        swap(a, b);
    }
    int diff = b.size() - a.size();
    charToInt(a, num_a, diff);
    charToInt(b, num_b, 0);
    printSum(calcSum(num_a, num_b, b.size()));
    return 0;
}