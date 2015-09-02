#include<iostream>
#include<cstdlib>
using namespace std;

/*

from: https://leetcode.com/problems/string-to-integer-atoi/

Describe:
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are 
the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all 
the input requirements up front.

Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.


*/

class Solution
{
public:
	/*
	leetcode上以这样的函数签名也是有它很大的意义的，尽管使用const String& str,以引用作为参数避免拷贝构造函数
	的调用，但这样的话会导致参数只能传递string对象，而不能传递C风格的字符串，如MyAtoi("123");这时就报错了；
	*/
	//int StringToInteger(const string& str)
	int MyAtoi(string str)
	{
		int size = str.size(); // 获取字符的个数
		int ret = 0; 
		int sign = 2; // 这个初值不设置为2是有别用的,只要是大于0的即可，表示是正数
		bool IsBegin = false;
		for(int i=0; i<size; i++)
		{
			if( str[i] < '0' || str[i] > '9')
			{
				if(ret != 0) // 避免"12 41 21414"中间出现非数字字符
					return ret*(sign>0?1:-1);
				if(str[i] == ' ' )
				{
					if(IsBegin)
						return ret*(sign>0?1:-1);
					else 
						continue;
				}
					
				else if(str[i] == '-' || str[i] == '+')
				{
					if(sign != 2) // 避免出现"-+343"或 "+-3243" 或"++3432" ，"--132"这种情况
						return 0;
					sign = (str[i] == '-' ? -1 : 1);
					IsBegin = true;
					
				}
				else 
					return 0;
			}
			else
			{	
				IsBegin = true;
				// 这个条件判断很好很完善，对比以下注释的的判断条件好好领悟，感受其中的奥妙
				if(ret > INT_MAX / 10 || (ret == INT_MAX /10 && (str[i]-'0')>INT_MAX%10)) 
					return sign > 0 ? INT_MAX : INT_MIN;
				ret = ret * 10 + str[i] - '0'; 
				
				// if(sign > 0 && (INT_MAX - ret) < 0) // 上溢
				// if(sign > 0 && (unsigned int)ret > INT_MAX)
				// {
					// return INT_MAX;
				// }
					
				// // 下溢 类似上面结论，减就是加， 这个判断很重要，好好领会
				// else if(sign < 0 && (unsigned int)(ret * sign * -1) > INT_MAX) 
				// {
					// return INT_MIN;
				//}
			}

	
		}
		
		return ret*(sign>0?1:-1);
	}
};


int main()
{
	Solution s;
	cout << "===========================\n";
	cout << "以下为正常数据测试:" << endl;
	cout << s.MyAtoi(" +00123") << endl;
	cout << s.MyAtoi("9") << endl;
	cout << s.MyAtoi("   91") << endl;
	cout << s.MyAtoi("2147483646") << endl;
	cout << s.MyAtoi("    +001340") << endl;
	cout << s.MyAtoi("-2147483646") << endl;
	cout << s.MyAtoi("  -283646") << endl;
	cout << s.MyAtoi("    -00134") << endl;
	cout << s.MyAtoi("    -0134") << endl;
	cout << s.MyAtoi("    -001034") << endl;
	cout << "===========================\n\n";
	
	cout << "===========================\n";
	cout << "以下为溢出测试:" << endl; 
	cout << s.MyAtoi("    21474836450") << endl;
	cout << s.MyAtoi("  -21474836492") << endl;
	cout << s.MyAtoi("    10522545459") << endl; // 用以上注释的边界判断，这句不能通过测试
	
	cout << "===========================\n\n";
	
	cout << "===========================\n";
	cout << "以下为异常字符串测试，结果返回前面那截数或0:" << endl;
	cout << s.MyAtoi("32dfad") << endl;
	cout << s.MyAtoi("-14gh") << endl;
	cout << s.MyAtoi("++23") << endl; 
	cout << s.MyAtoi("--2343") << endl;
	cout << s.MyAtoi(" +-123") << endl;
	cout << s.MyAtoi("-+2147483649") << endl;
	cout << s.MyAtoi("9ad") << endl;
	cout << s.MyAtoi("   +0 123") << endl;
	cout << s.MyAtoi("   - 123") << endl;
	cout << "===========================\n\n";
	
}