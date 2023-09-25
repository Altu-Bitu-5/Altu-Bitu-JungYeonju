#include <iostream>
#include <vector>

using namespace std;

// 전체 알파벳 개수 상수로 지정
const int NUM_CHARS = 26;

// string의 각 알파벳의 개수 세기
void countFreq(string word, vector<int> &freq)
{
    // word를 끝까지 순회하며 알파벳의 개수를 freq에 순서대로 저장
    for (int i = 0; i < word.length(); i++)
    {
        freq[word[i] - 'A']++;
    }
}

int countDiff(string word, vector<int> std_freq)
{
    vector<int> cmp_freq(NUM_CHARS, 0);
    int diff = 0;

    // 비교하는 값의 frequency 카운팅
    countFreq(word, cmp_freq);

    /*
        완전히 같은 경우 diff == 0
        한 글자가 다르고, 길이가 1개 차이나는 경우 diff == 1
        한 글자가 다르고, 길이가 같은 경우 diff == 2
        이외의 경우는 diff > 2
    */
    for (int i = 0; i < NUM_CHARS; i++)
    {
        diff += abs(std_freq[i] - cmp_freq[i]);
    }
    return diff;
}

int main()
{
    int N, ans = 0;
    // 기준이 되는 값
    string std;

    // 입력
    cin >> N;
    cin >> std;

    // 기준 값에 대해 알파벳 개수만큼 0으로 초기화
    vector<int> std_freq(NUM_CHARS, 0);

    countFreq(std, std_freq);

    for (int i = 1; i < N; i++)
    {
        // 기준과 비교하는 입력값 받기
        string word;
        cin >> word;

        // 기준과 다른 개수 카운팅
        int diff = countDiff(word, std_freq);

        // 비슷한 단어 개수 카운팅
        if (diff == 0 || diff == 1 || (diff == 2 && std.length() == word.length()))
        {
            ans++;
        }
    }
    // 정답 출력
    cout << ans;
    return 0;
}