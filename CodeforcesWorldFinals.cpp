#include <iostream>
#include <stdio.h>
#include "common.h"
int r[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int p[12]={31,28,31,30,31,30,31,31,30,31,30,31};
using namespace std;
#define rep(i, n) for((i)=0;(i)<(int)(n);(i)++)

//比较y/m/d 和by/bm/bd之间的时间是否超过18年。
int f(int y, int m, int d, int by, int bm, int bd) {
    //判断by bm bd的合法性
    if(y%4==0)
    {
        if (bd>r[m-1])//如果是闰年，天数小于本月天数。
            return 0;
    } else
    {
        if (bd>p[m-1])//如果是平年，天数小于本月天数。
            return 0;
    }
    if(bm>12) return 0;
    //年度差超过18年
    if (y - by > 18)
        return 1;
    else {
        //年度差小于18
        if (y - by < 18) return 0;
        if (y - by == 18 && bm < m)//年度相差18年，月份差为正
            return 1;
        else {//年度相差18年，月相同，日期差为正
            if (y - by == 18 && bm == m && bd <= d)
                return 1;
            else//
                return 0;
        }
    }
}

//格式：d.m.y
int AgeIsOk(string finalDay, string birthDay)
{
    int y, by, m, bm, d, bd, i;

    sscanf(finalDay.c_str(),"%d.%d.%d", &d,&m,&y );
    sscanf(birthDay.c_str(),"%d.%d.%d",&bd,&bm,&by);
    //printf("%d,%d,%d,%d,%d,%d\n",y,m,d,by,bm,bd);
    if (f(y, m, d, by, bm, bd)) {
        return 1;
    } else {
        if (f(y, m, d, by, bd, bm) || f(y, m, d, bm, bd, by)
            || f(y, m, d, bm, by, bd) || f(y, m, d, bd, by, bm)
            || f(y, m, d, bd, bm, by))
            return 1;
        else
            return 0;
    }
}
/*
 *
 * */
#ifdef ENV_UNITTEST
int CodeforcesWorldFinales()
#else
int main()
#endif
{
    string finalday, birthday;

    cin>>finalday;
    cin>>birthday;
    //printf("%d,%d,%d,%d,%d,%d\n",y,m,d,by,bm,bd);
    if (AgeIsOk(finalday,birthday)) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}

#ifdef ENV_UNITTEST
TEST(CodeforcesWorldFinales, test1)
{
    EXPECT_EQ(1,AgeIsOk("01.01.98","01.01.80"));
}

TEST(tCodeforcesWorldFinales, test2)
{
    EXPECT_EQ(0,AgeIsOk("20.10.20","10.02.30"));
}

TEST(tCodeforcesWorldFinales, test3)
{
    EXPECT_EQ(0,AgeIsOk("28.02.74","28.02.64"));
}
/*
01.03.19
01.02.29*/
TEST(tCodeforcesWorldFinales, test67)
{
    EXPECT_EQ(0,AgeIsOk("01.03.19","01.02.29"));
}
#endif
