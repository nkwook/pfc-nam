#include <iostream>
using namespace std;

int main()
{
    int number;
    cin >> number;
    string a[number], b[number];
    string result;

    for (int i = 0; i < number; i++)
    {
        cin >> a[i] >> b[i];
    }
    // 당장은 편해서 이터레이터 썼는데 여러개 동시에 처리할경우 문자열 번호로 인덱싱하는게 더 좋을 것 같다. 
    for (int i = 0; i < number; i++)
    {
        int arr[26]={};
        result="Possible";
        for (char achar : a[i])
        {
            // cout << achar;
            arr[achar - 'a']++;
        }
        for (char bchar : b[i])
        {
            // cout << bchar;
            arr[bchar - 'a']--;
        }
        for (int j = 0; j < 26; j++)
        {
            // cout <<arr[j] << "\n";
            if (arr[j] != 0)
            {
                result = "Impossible";
                break;
            }
        }
        cout << result << "\n";
    }

}
