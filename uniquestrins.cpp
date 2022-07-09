#include <bits/stdc++.h>

using namespace std;
const int ch_MAX = 26;
string RandomString(int ch)
{
    char alpha[ch_MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z'};
    string result = "";
    for (int i = 0; i < ch; i++)
        result = result + alpha[rand() % ch_MAX];

    return result;
}
template <typename S>
auto select_random(const S &s, size_t n)
{
    auto it = std::begin(s);
    // 'advance' the iterator n times
    std::advance(it, n);
    return it;
}
int main()
{
    srand(time(NULL));
    set<string> s;
    int test = rand() % 100 + 1;
    cout << test << endl;
    while (test--)
    {
        int ch = rand() % 50 + 1;

        s.insert(RandomString(ch));
    }
    vector<string> v;
    for (auto sf : s)
    {
        v.push_back(sf);
    }
    auto r = rand() % s.size(); // not _really_ random
    auto n = *select_random(s, r);
    v.push_back(n);
    shuffle(v.begin(), v.end(), random_device());
    for (auto d : v)
    {
        cout << d << endl;
    }

    return 0;
}
