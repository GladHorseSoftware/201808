#include <iostream>
#include "common.h"

using namespace std;

string tic_tac_toe(string a[3])
{
    int i,j,s=0,x=0,o=0;

    for(i=0;i<3;i++)
    {
        //cout<<a[i]<<endl;
        for(j=0;j<3;j++)
        {
            if(a[i][j]=='X') x++;
            if(a[i][j]=='0') o++;
            if(a[i][j]!='X'&&a[i][j]!='0'&&a[i][j]!='.') {
                //printf("a[%d][%d]=%d\n",i,j,a[i][j]);
                return "illegal";
            }
        }
    }
    //printf("%d,%d\n",o,x);
    if(o>x||x-o>1)
    {
        //printf("x=%d,o=%d \n",x,o);
        return "illegal";
    }
    bool FirWon=false,SecWon=false;

    for(i=0;i<3;i++) {
        //判断行是否有连成一排
        if ((a[i][0] == a[i][1]) && (a[i][1] == a[i][2])) {
            if (a[i][0] == 'X') {
                //printf("%d\n",__LINE__);
                FirWon = true;
            }
            if (a[i][0] == '0') {
                //printf("%d\n",__LINE__);
                SecWon = true;
            }
        }
    }
    //判断列是否有连成一排
    for(j=0;j<3;j++)
    {
        if((a[0][j]==a[1][j]) && (a[1][j]==a[2][j]))
        {
            if (a[0][j]=='X') {
                //printf("%d\n",__LINE__);
                FirWon = true;
            }
            if (a[0][j]=='0') {
                //printf("%d\n",__LINE__);
                SecWon = true;
            }
        }
    }

    //判断对角线
    if((a[0][0]==a[1][1] && a[1][1]==a[2][2])||
       (a[0][2]==a[1][1] && a[1][1]==a[2][0]))
    {
        if (a[1][1]=='X') {
            //printf("%d\n",__LINE__);
            FirWon = true;
        }
        if (a[1][1]=='0') {
            //printf("%d\n",__LINE__);
            SecWon = true;
        }
    }
    //不应该出现连个都赢
    if(FirWon&&SecWon)
    {
        //printf("Both win\n");
        return "illegal";
    }
    else
    {
        if(FirWon && !SecWon)
        {
            //如果x赢了但此时x个数和o相等
            if (x-o<=0) return "illegal";
            return "the first player won";
        }
        if(SecWon && !FirWon)
        {
            //如果x比o多走一步，此时不应该出现o已经赢了
            if (x-o>=1) return "illegal";
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
    //走完9宫格还没有人赢，则平局
    if(x+o==9 && !FirWon && !SecWon) {
        return "draw";
    }
}

#ifdef ENV_UNITTEST
int tic_tac_toe_main()
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
}

TEST(tic_tac_toe, test8)
{
    string a[3]={
            "XXX",
            "X00",
            "X00"};

    EXPECT_STREQ(tic_tac_toe(a).c_str(),"the first player won");
}


TEST(tic_tac_toe, test9)
{
    string a[3]={
            "000",
            "X.X",
            "X.X"};

    EXPECT_STREQ(tic_tac_toe(a).c_str(),"illegal");
}

TEST(tic_tac_toe, test10)
{
    string a[3]={
            "XXX",
            "0.0",
            "0.."};

    EXPECT_STREQ(tic_tac_toe(a).c_str(),"illegal");
}

TEST(tic_tac_toe, test11)
{
    string a[3]={
            "X0X",
            "0X0",
            "X0X"};

    EXPECT_STREQ(tic_tac_toe(a).c_str(),"the first player won");
}

TEST(tic_tac_toe, test120)
{
    string a[3]={
            "X00",
            "0XX",
            "XX0"};

    EXPECT_STREQ(tic_tac_toe(a).c_str(),"draw");
}
/*
TEST(tic_tac_toe, testmain)
{
    tic_tac_toe_main();
}*/
#endif