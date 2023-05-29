#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <stack>
#include <tuple>

long long n, w, h;
vector<tuple<long long, long long, long long>> tables;
stack<long long> S;
long long firstMaxArea = 0;
long long secondMaxArea=0;

bool sortByHeight(tuple<long long, long long, long long> &a, tuple<long long, long long, long long> &b)
{
    return get<0>(a) > get<0>(b);
}

int main()
{
    cin >> n;
    long long absX = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> w >> h;
        tables.push_back(make_tuple(h, w, absX));
        absX += w;
    }

    long long cmpHeight = 0;

    for (long long i = 0; i < n; i++)
    {
        long long currIterHeight = get<0>(tables[i]);
        long long currIterWidth = get<1>(tables[i]);
        long long currIterAbsX = get<2>(tables[i]);

        long long leftAbsWidth = 0;
        if (S.empty())
        {
            S.push(i);
            continue;
        }

        long long topIndex = S.top();
        tuple<long long, long long, long long> cmpTuple = tables[topIndex];
        // cout << "cmpTuple " << get<0>(cmpTuple) << " " << get<1>(cmpTuple) << " " << get<2>(cmpTuple) <<'\n';
        long long cmpHeight = get<0>(cmpTuple);
        if (cmpHeight <= currIterHeight)
        {

            S.push(i);
            continue;
        }

        while (currIterHeight < cmpHeight)
        {
            S.pop();
            long long cmpWidth = get<1>(cmpTuple);
            long long cmpAbsX = get<2>(cmpTuple);
            long long rightEnd = currIterAbsX;
            long long leftEnd = 0;

            if (S.empty())
            {
                leftEnd = 0;
                // cout << "leftEnd: " << leftEnd <<'\n';
            }
            else
            {
                tuple<long long, long long, long long> leftEndTuple = tables[S.top()];
                long long leftEndWidth = get<1>(leftEndTuple);
                long long leftEndAbsX = get<2>(leftEndTuple);
                leftEnd = leftEndWidth + leftEndAbsX;

            }

            long long cmpArea = (rightEnd - leftEnd) * cmpHeight;
            // cout << "Calculating cmpArea\n"
            //      << "left : " << leftEnd << " right: " << rightEnd << " height: " << cmpHeight << " cmpArea: " << cmpArea << '\n';
            if (cmpArea > firstMaxArea)
            {
                firstMaxArea = cmpArea;
            }

            if (S.empty())
            {
                break;
            }

            topIndex = S.top();
            // S.pop();
            cmpTuple = tables[topIndex];
            cmpHeight = get<0>(cmpTuple);
            // cmpWidth=get<1>(cmpTuple);
            // cmpAbsX=get<2>(cmpTuple);
        }
        S.push(i);
    }

    // cout << "Stack size: " << S.size() << '\n';
    // while(!S.empty()){
    //     cout << S.top() << ' ';

    //     S.pop();
    // }
    // return 0;
    // last
    if (!S.empty())
    {
        tuple<long long, long long, long long> mostRightTuple = tables[S.top()];
        long long mostRightPosition = get<1>(mostRightTuple) + get<2>(mostRightTuple);
        while (!S.empty())
        {
            tuple<long long, long long, long long> iterTuple = tables[S.top()];
            long long iterHeight = get<0>(iterTuple);
            S.pop();
            long long leftEnd = 0;

            if (S.empty())
            {
                leftEnd = 0;
            }
            else
            {
                tuple<long long, long long, long long> leftEndTuple = tables[S.top()];
                long long leftEndWidth = get<1>(leftEndTuple);
                long long leftEndAbsX = get<2>(leftEndTuple);
                leftEnd = leftEndWidth + leftEndAbsX;
            }

            long long cmpArea = (mostRightPosition - leftEnd) * iterHeight;
            // cout << "Calculating cmpArea\n"
            //      << "left : " << leftEnd << " right: " << mostRightPosition << " height: " << iterHeight << " cmpArea: " << cmpArea << '\n';

            if (cmpArea > firstMaxArea)
            {
                firstMaxArea = cmpArea;
            }
        }
    }


    sort(tables.begin(), tables.end(), sortByHeight);

    long long cumWidth=0;
    long long intervalArea=0;
    for (auto p: tables){
        long long height=get<0>(p);
        long long width=get<1>(p);
        cumWidth+=width;
        intervalArea= cumWidth*height;
        // cout << "Calculating intvArea\n"
        //          << "cumw : " << cumWidth << " height: " << height << " intv: " << intervalArea << '\n';

        if(secondMaxArea < intervalArea){
            secondMaxArea= intervalArea;
        }
        
    }
    cout << secondMaxArea << '\n';
    cout << firstMaxArea ;

    return 0;
}