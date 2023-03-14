#include "lang.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

#define N 100

static char lang[20], lan[100][20];
static int lnum, i, j, k, n, nl, uni[N], right, tot;
int language(int L)
{
    if (L < 0 || L >= 56)
    {
        printf("Invalid Language Code. %d\n", L);
        exit(-1);
    }
    if (lnum == -1)
    {
        printf("Multiple language call.\n");
        exit(-1);
    }

    int ans = lnum;
    right += (L == lnum);
    tot++;
    lnum = -1;
    return ans;
}

int main()
{
    for (n = 0; 1 == scanf("%2s", lang); n++)
    {
        for (i = 0; i < nl && strcmp(lang, lan[i]); i++)
            ;
        strcpy(lan[i], lang);
        if (i == nl)
            nl++;
        lnum = i;
        for (i = 0; i < N; i++)
            scanf("%d,", &uni[i]);
        scanf("%*[^\n]");
        std::vector<int> uni_vec(uni, uni + N);
        excerpt(uni_vec);
    }
    printf("OK %0.2lf%%\n", 100.0 * right / tot);
    return 0;
}
