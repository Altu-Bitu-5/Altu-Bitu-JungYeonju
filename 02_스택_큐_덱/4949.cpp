#include <iostream>
#include <vector>
#include <stack>
#include <string> // getline

using namespace std;

void printAns(bool ans)
{
    if (ans)
        cout << "yes\n";
    else
        cout << "no\n";
}

bool isBalanced(string s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case '[':
        case '(':
            st.push(s[i]);
            break;

        case ')':
            if (st.empty() || st.top() != '(')
                return false;
            else
                st.pop();
            break;
        case ']':
            if (st.empty() || st.top() != '[')
                return false;
            else
                st.pop();
            break;
        }
    }
    return st.empty();
}
int main()
{
    vector<string> v;

    while (1)
    {
        string tmp;

        getline(cin, tmp);
        if (tmp == ".")
            break;
        v.push_back(tmp);
    }
    for (int i = 0; i < v.size(); i++)
    {
        printAns(isBalanced(v[i]));
    }
    return 0;
}