#include <bits/stdc++.h>
//#include "common.h"

using namespace std;

typedef long long ll;

ll op(ll a,ll b,char o)
{
    //cout<<a<<o<<b<<endl;
    if(o=='+')return a+b;
    else return a*b;
}

void sort_mp(ll v[], int len)
{
    int i,j;
    //for(i=0;i<=len-1;i++) cout<<v[i]<<" ";
    //cout << endl;
    for(i=0;i<=len-2;i++) {
        for (j = i + 1; j <= len-1; j++) {
            if (v[i] > v[j]) swap(v[i], v[j]);
        }
    }
    //for(i=0;i<=len-1;i++) cout<<v[i]<<" ";
    //cout << endl;
}

ll res[72];
ll SmallestNumber(ll a[], char s[])
{
    ll tmp;

    int index1, index2, index3, index4;
    int possible[][4] = {{1,2,3,4},{1,2,4,3},{1,3,2,4},{1,3,4,2},{1,4,2,3},{1,4,3,2},
                    {2,1,3,4},{2,1,4,3},{2,3,1,4},{2,3,4,1},{2,4,1,3},{2,4,3,1},
                    {3,1,2,4},{3,1,4,2},{3,2,1,4},{3,2,4,1},{3,4,1,2},{3,4,2,1},
                    {4,1,2,3},{4,1,3,2},{4,2,1,3},{4,2,3,1},{4,3,1,2},{4,3,2,1},
                    };
    cout<<endl;
    for (int i=0;i<24;i++) {
        index1 = possible[i][0] - 1;
        index2 = possible[i][1] - 1;
        index3 = possible[i][2] - 1;
        index4 = possible[i][3] - 1;
        tmp = op(a[index1],a[index2], s[0]);
        res[i*3+0] = op(op(tmp, a[index3], s[1]), a[index4], s[2]);
        res[i*3+1] = op(op(tmp, a[index4], s[1]), a[index3], s[2]);
        res[i*3+2] = op(op(a[index4], a[index3], s[1]), tmp, s[2]);
        //printf("%ld (%ld,%ld,%ld)\n",tmp,res[i*3+0],res[i*3+1],res[i*3+2]);
    }

    sort_mp(res,72);
    return res[0];
}

int main()
{
    ll a[4];
    char s[3];

    cin>>a[0]>>a[1]>>a[2]>>a[3];
    cin>>s[0]>>s[1]>>s[2];

    cout<<SmallestNumber(a,s)<<endl;
}

#ifdef ENV_UNITTEST
TEST(Small_Number, test1)
{
    ll a[4]={1,1,1,1};
    char s[3]={'+','+','*'};

    EXPECT_EQ(SmallestNumber(a,s),3);
}

TEST(Small_Number, test2)
{
    ll a[4]={2,2,2,2};
    char s[3]={'*','*','+'};

    EXPECT_EQ(SmallestNumber(a,s),8);
}

TEST(Small_Number, test3)
{
    ll a[4]={1,2,3,4};
    char s[3]={'*','+','+'};

    EXPECT_EQ(SmallestNumber(a,s),9);
}

TEST(Small_Number, test4)
{
    ll a[4]={15,1,3,1};
    char s[3]={'*','*','+'};

    EXPECT_EQ(SmallestNumber(a,s),18);
}

TEST(Small_Number, test5)
{
    ll a[4]={8,1,7,14};
    char s[3]={'+','+','+'};

    EXPECT_EQ(SmallestNumber(a,s),30);
}

TEST(Small_Number, test6)
{
    ll a[4]={7,17,3,25};
    char s[3]={'+','*','+'};

    EXPECT_EQ(SmallestNumber(a,s),63);
}

TEST(Small_Number, test10)
{
    ll a[4]={1000,1000,999,1000};//1000 1000 999 1000

    char s[3]={'*','*','*'};

    EXPECT_EQ(SmallestNumber(a,s),999000000000);
}
#endif