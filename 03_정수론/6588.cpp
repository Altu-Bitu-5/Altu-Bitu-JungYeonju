#include <iostream>

using namespace std;

void makePrime(int *is_num)
{
    for (int i = 2; i * i <= 1000000; i++)
    {
        if (!is_num[i])
        {
            for (int j = i + i; j <= 1000000; j += i)
            {
                is_num[j] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int is_num[1000001];

    makePrime(is_num);

    while (1)
    {
        cin >> n;

        if (!n)
        {
            break;
        }
        for (int i = 2; i <= n; i++)
        {
            if (!is_num[i] && !is_num[n - i])
            {
                printf("%d = %d + %d\n", n, i, n - i);
                break;
            }
        }
    }
}