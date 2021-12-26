#include <iostream>
using namespace std;

long long fac[101];
int n, r, g, b;
long long c[11][101][101][101] = {};

void dfs(int level, int rn, int gn, int bn)
{
    int sz=0;
    if (level == 1 ){
        int cnt=0;
        if(rn>=1) cnt++;
        if(gn>=1) cnt++;
        if(bn>=1) cnt++;

        c[0][0][0][0]+=cnt*c[level][rn][gn][bn];
        return;
    }
        
    if (level % 3 == 0)
    {
        sz = level / 3;
        if (rn >= sz && gn >= sz && bn >= sz)
        {
            c[level - 1][rn - sz][gn - sz][bn - sz] = c[level][rn][gn][bn] *
                                                       fac[level] / (fac[sz] * fac[sz] * fac[sz]);
            dfs(level - 1, rn - sz, gn - sz, bn - sz);
        }
    }
    if (level % 2 == 0)
    {
        sz = level / 2;
        if (rn >= sz && gn >= sz)
        {
            c[level - 1][rn - sz][gn - sz][bn] = c[level][rn][gn][bn] *
                                                  fac[level] / (fac[sz] * fac[sz]);
            dfs(level - 1, rn - sz, gn - sz, bn);
        }
        if (rn >= sz && bn >= sz)
        {
            c[level - 1][rn - sz][gn][bn - sz] = c[level][rn][gn][bn] *
                                                  fac[level] / (fac[sz] * fac[sz]);
            dfs(level - 1, rn - sz, gn, bn - sz);
        }
        if (bn >= sz && gn >= sz)
        {
            c[level - 1][rn][gn - sz][bn - sz] = c[level][rn][gn][bn] *
                                                  fac[level] / (fac[sz] * fac[sz]);
            dfs(level - 1, rn, gn - sz, bn - sz);
        }
    }

    if (rn >= level)
    {
        c[level - 1][rn - level][gn][bn] = c[level][rn][gn][bn];
        dfs(level - 1, rn - level, gn, bn);
    }
    if (gn >= level)
    {
        c[level - 1][rn][gn - level][bn] = c[level][rn][gn][bn];
        dfs(level - 1, rn, gn - level, bn);
    }
    if (bn >= level)
    {
        c[level - 1][rn][gn][bn - level] = c[level][rn][gn][bn];
        dfs(level - 1, rn, gn, bn - level);
    }
    return;
}

int main()
{
    fac[0] = 1;
    cin >> n >> r >> g >> b;
    c[n][r][g][b] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i;
    }

    dfs(n, r, g, b);

    cout << c[0][0][0][0];
}