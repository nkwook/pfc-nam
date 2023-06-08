#include "jelly.h"

#include <iostream>
#include <cassert>
static int n, jelly[1005], q_count = 0;
static void WA(const char *str)
{
    std::cout << str << std::endl;
    exit(0);
}
int query(std::vector<int> E)
{
    q_count++;
    if (q_count > 20000)
        WA("query limit exceeded.");
    std::vector<int> buf(n + 5);
    for (int i = 0; i < E.size(); i++)
    {
        if (E[i] < 1 || E[i] > n)
            WA("query number should be between 1 and n.");
        if (buf[jelly[E[i]]])
            WA("duplicate numbers in query.");
        buf[jelly[E[i]]] = 1;
    }
    int response = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        if (buf[i] == 0 && buf[i - 1] == 1)
            response++;
    }
    return response;
}

int main()
{
    assert(std::cin >> n);
    for (int i = 1; i <= n; i++)
    {
        int a;
        assert(std::cin >> a);
        jelly[a] = i;
    }
    std::vector<int> guess = start(n);
    if (n != guess.size())
        WA("final guess's size is not n.");
    bool reversed;
    if (jelly[guess[0]] == 1)
        reversed = false;
    else if (jelly[guess[0]] == n)
        reversed = true;
    else
        WA("WA");
    for (int i = 0; i < n; i++)
    {
        if (reversed)
        {
            if (n - i != jelly[guess[i]])
                WA("wrong answer.");
        }
        else if (i + 1 != jelly[guess[i]])
            WA("wrong answer.");
    }
    std::cout << "correct! query count: " << q_count << std::endl;
    return 0;
}