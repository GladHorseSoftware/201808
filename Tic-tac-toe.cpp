#include <bits/stdc++.h>
//#include "common.h"

using namespace std;

string tic_tac_toe(string a[])
{
    int i,j,s=0,x=0,o=0;
    string result;
    for(i=0;i<3;i++)
    {
        cout<<a[i]<<endl;
        for(j=0;j<3;j++)
        {
            if(a[i][j]=='X') x++;
            if(a[i][j]=='0') o++;
            if(a[i][j]!='X'&&a[i][j]!='0'&&a[i][j]!='.') return "illegal";
        }
    }
    //printf("%d,%d\n",o,x);
    if(o>x||x-o>1)
    {
        return "illegal";
    }
    bool FirWon,SecWon;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if((a[i][j]=='X'&&a[i][j+1]=='X'&&a[i][j+2]=='X')||
               (j>=2&&a[i][j]=='X'&&a[i][j-1]=='X'&&a[i][j-2]=='X')||
               (j>=1&&a[i][j]=='X'&&a[i][j+1]=='X'&&a[i][j-1]=='X'))

            {
                FirWon=1;
            }
            if((a[i][j]=='0'&&a[i][j+1]=='0'&&a[i][j+2]=='0')||
               (j>=2&&a[i][j]=='0'&&a[i][j-1]=='0'&&a[i][j-2]=='0')||
               (j>=1&&a[i][j]=='0'&&a[i][j+1]=='0'&&a[i][j-1]=='0'))

            {
                SecWon=1;
            }
        }
    }
    if((a[0][0]=='X'&&a[1][1]=='X'&&a[2][2]=='X')||
       (a[0][2]=='X'&&a[1][1]=='X'&&a[2][0]=='X'))
    {
        FirWon=1;
    }
    if((a[0][0]=='0'&&a[1][1]=='0'&&a[2][2]=='0')||
       (a[0][2]=='0'&&a[1][1]=='0'&&a[2][0]=='0'))
    {
       SecWon=1;
    }
    if(FirWon==1&&SecWon==1)
    {
        return "illegal";
    }
    else
    {
        if(FirWon==1&&SecWon==0)
        {
            return "the first player won";
        }
        if(SecWon==1&&FirWon==0)
        {
            return "the second player won";
        }
    }
    if(x-o==1&&x+o<9)
    {
        return "second";
    }
    if(x==o&&x+o<9)
    {
        return "first";
    }
}
#ifdef ENV_UNITTEST
int Tic_tac_toe()
#else
int main()
#endif
{
    string a[3];
    for(int i=0;i<3;i++) {
        cin >> a[i];
    }
    string result = tic_tac_toe(a);
    cout << result << endl;
}
#ifdef ENV_UNITTEST
/*
TEST(tic_tac_toe, test1)
{
    string a[3]={
            "X0X",
            ".0.",
            ".X."};

    EXPECT_STREQ(tic_tac_toe(a).c_str(),"second");
}

TEST(tic_tac_toe, test2)
{
    string a[3]={
            "0.X",
            "XX.",
            "000"};

    EXPECT_STREQ(tic_tac_toe(a).c_str(),"illegal");
}

TEST(tic_tac_toe, test4)
{
    string a[3]={
            "XXX",
            "...",
            "000"};


    EXPECT_STREQ(tic_tac_toe(a).c_str(),"illegal");
}

TEST(tic_tac_toe, test6)
{
    string a[3]={
            "X.X",
            "X.0",
            "0.0"};

    EXPECT_STREQ(tic_tac_toe(a).c_str(),"first");
}*/

TEST(tic_tac_toe, testmain)
{
    Tic_tac_toe();
}
#endif