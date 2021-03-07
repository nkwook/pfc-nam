#include <iostream>
#include <list>
using namespace std;

int main()
{
    int number;
    cin >> number;
    string inputs[number], outputs[number];

    for (int i = 0; i < number; i++)
    {
        cin >> inputs[i];
    }

    for (int i = 0; i < number; i++)
    {

        list<char> L;
        auto cursor = L.end();
        // trasnverse~
        for (char c : inputs[i])
        {
            if (c == '<')
            {
                if (cursor != L.begin())
                    cursor--;
            }
            else if (c == '>')
            {
                if (cursor != L.end()){
                    cursor++;
                }
            }
            else if (c == '-')
            {
                // cout << *cursor <<" , ";
                if (cursor != L.begin())
                {
                    cursor--;
                    cursor=L.erase(cursor);
                    // we should update cursor position
                }
            }
            else
            {
                L.insert(cursor, c);              
            }
        }
        for (char cc : L)
        {
            cout << cc;
        }
        cout << "\n";
    }
}