#include <bits/stdc++.h>
//#include "common.h"
using namespace std;

//type=1, a: R23C55 返回值：BC23
string toColName(string a)
{
    string result="";
	int row=0,col=0;
	int i;
	for(i=1;isdigit(a[i]);++i)//获得行数23
	{
		row=10*row+(a[i]-'0');//先读入2，后读入3变成23，2进位需要扩大十倍。
	}
    //此时i指向C，通过++i指向5
	for(++i;isdigit(a[i]);++i)//获得列数55
	{
		col=10*col+(a[i]-'0');
	}
	//printf("col=%d\n",col);
	char ch='A';

	while(col>0)
	{
		if (col%26 > 0) {
			ch=col%26+'A'-1;//BC中的C放入result
		} else
			ch = 'Z';
		//printf("%d,%c,%d(%d,%d)\n",col,ch,ch,'R','Z');
        result = ch + result;
        //1--26, 单个字母，倍数为0
        //27--27*26，双字母，倍数为1---27，AA-ZZ
        //27*26+1--26*26*26+26 三字母，倍数27---26*26+1
        if (col%26 == 0) {
        	col = col/26 - 1;
        } else {
			col /= 26;
		}
	}
	char sRow[100];
    sprintf(sRow,"%s%d",result.c_str(),row);
	return sRow;
}

//type=0,输入BC23, 返回R23C55
string toColNum(string input)
{
	char s[100];
	int col=0,row=0;
	int j;
	for(j=0;!isdigit(input[j]);++j)//读入BC
	{
		col=26*col+input[j]-'A'+1;
	}
	//读入23
	for(;input[j];++j)
	{
		row=10*row+input[j]-'0';
	}
	memset(s,0,100);
	sprintf(s,"R%dC%d",row,col);
    return s;
}

int getType(string str)
{
	int type=0;
	for(int i=1;i<str.size()-1;++i)
	{
		//如果i是字母，i-1和i+1是数字
		if(isdigit(str[i-1])&&!isdigit(str[i])&&isdigit(str[i+1]))
		{
			type=1;//R23C55
			//printf("%s,%c,%c,%c\n",str.c_str(),str[i-1],str[i],str[i+1]);
			break;
		}
	}
	return type;
}

#ifdef ENV_UNITTEST
int Spreadsheets()
#else
int main()
#endif
{
	string s;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		cin>>s;
		int type=getType(s);

		//cout << "type = " << type << "," <<s<< endl;
		if(type==0)//BC23
		{
			cout<<toColNum(s)<<endl;
		}
		else {//R23C55
			cout<<toColName(s)<<endl;
			//printf("%d\n",Con12(s));
		}
	}
}

#ifdef ENV_UNITTEST
TEST(spreadsheets, toColNum_test1)
{
	EXPECT_STREQ("BC23",toColName("R23C55").c_str());
}
TEST(spreadsheets, toColName_test1)
{
	EXPECT_STREQ("R23C55",toColNum("BC23").c_str());
}

TEST(spreadsheets, toColName_test2)
{
	EXPECT_STREQ("RZ228",toColName("R228C494").c_str());
}

TEST(spreadsheets, Spreadsheets_test1)
{
	//Spreadsheets();
}

TEST(spreadsheets, getType_test1)
{
	EXPECT_EQ(0,getType("BC23"));
}

TEST(spreadsheets, getType_test2)
{
	EXPECT_EQ(1,getType("R23C55"));
}
TEST(spreadsheets, getType_test3)
{
	EXPECT_EQ(0,getType("RZ228"));
}
#endif