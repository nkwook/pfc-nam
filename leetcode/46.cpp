using namespace std;
#include <iostream>
#include <vector>

// need to pop.......

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;

        bool vis[nums.size()];
        vector<int> temp;

        for (int i = 0; i < nums.size(); i++)
        {
            vis[i] = false;
            // temp.push_back(0);
        }

        backtrack(temp, nums, result, vis);
        return result;
    }

    void backtrack(vector<int> &vec, vector<int> &nums, vector<vector<int>> &r,
                   bool *vis)
    {
        cout << "up\n";
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << ' ';
        }
        cout << '\n';
        for (int i = 0; i < 3; i++)
        {
            cout << vis[i] << ' ';
        }
        cout << '\n';

        if (vec.size() == nums.size())
        {
            r.push_back(vec);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            cout << "wtf" << i <<'\n';
            if (vis[i])
                continue;
            vec.push_back(nums[i]);
            vis[i] = true;
            backtrack(vec, nums, r, vis);
            vec.pop_back();
            vis[i] = false;

            cout << "down\n";
            for (int i = 0; i < vec.size(); i++)
            {
                cout << vec[i] << ' ';
            }
            cout << '\n';
            for (int i = 0; i < 3; i++)
            {
                cout << vis[i] << ' ';
            }
            cout << '\n';
        }

        return;
    }
};

int main()
{
    Solution s;

    // ListNode *l1=new ListNode(2, new ListNode(4, new ListNode(3)));
    // ListNode *l2=new ListNode(5, new ListNode(6, new ListNode(4)));
    vector<int> vin = {1, 2, 3};
    vector<vector<int>> v = s.permute(vin);
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << '\n';
    }
    return 0;
}