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
	leetcode���������ĺ���ǩ��Ҳ�������ܴ������ģ�����ʹ��const String& str,��������Ϊ�������⿽�����캯��
	�ĵ��ã��������Ļ��ᵼ�²���ֻ�ܴ���string���󣬶����ܴ���C�����ַ�������MyAtoi("123");��ʱ�ͱ����ˣ�
	*/
	//int StringToInteger(const string& str)
	int MyAtoi(string str)
	{
		int size = str.size(); // ��ȡ�ַ��ĸ���
		int ret = 0; 
		int sign = 2; // �����ֵ������Ϊ2���б��õ�,ֻҪ�Ǵ���0�ļ��ɣ���ʾ������
		bool IsBegin = false;
		for(int i=0; i<size; i++)
		{
			if( str[i] < '0' || str[i] > '9')
			{
				if(ret != 0) // ����"12 41 21414"�м���ַ������ַ�
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
					if(sign != 2) // �������"-+343"�� "+-3243" ��"++3432" ��"--132"�������
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
				// ��������жϺܺú����ƣ��Ա�����ע�͵ĵ��ж������ú����򣬸������еİ���
				if(ret > INT_MAX / 10 || (ret == INT_MAX /10 && (str[i]-'0')>INT_MAX%10)) 
					return sign > 0 ? INT_MAX : INT_MIN;
				ret = ret * 10 + str[i] - '0'; 
				
				// if(sign > 0 && (INT_MAX - ret) < 0) // ����
				// if(sign > 0 && (unsigned int)ret > INT_MAX)
				// {
					// return INT_MAX;
				// }
					
				// // ���� ����������ۣ������Ǽӣ� ����жϺ���Ҫ���ú����
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
	cout << "����Ϊ�������ݲ���:" << endl;
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
	cout << "����Ϊ�������:" << endl; 
	cout << s.MyAtoi("    21474836450") << endl;
	cout << s.MyAtoi("  -21474836492") << endl;
	cout << s.MyAtoi("    10522545459") << endl; // ������ע�͵ı߽��жϣ���䲻��ͨ������
	
	cout << "===========================\n\n";
	
	cout << "===========================\n";
	cout << "����Ϊ�쳣�ַ������ԣ��������ǰ���ǽ�����0:" << endl;
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