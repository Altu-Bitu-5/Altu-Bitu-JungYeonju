#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string number, int k)
{
    string answer = "";

    cin >> number >> k;

    int length = number.size() - k;
    int start = 0;
    for (int i = 0; i < length; i++)
    {
        char max_num = number[start];
        int max_index = start;
        for (int j = start; j <= i + k; j++)
        {
            if (max_num < number[j])
            {
                max_num = number[j];
                max_index = j;
            }
        }
        start = max_index + 1;
        answer += max_num;
    }
    return answer;
}