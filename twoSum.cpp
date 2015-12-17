/************************************************************************
Two Sum
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 

author: uu                                                                    
************************************************************************/

#include<iostream>
#include<vector>
//#include<algorithm>
#include<map>
using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int, int> m;
        int sz = nums.size();
        for(int i = 0; i < sz; ++i)
        {
            map<int, int>::iterator p = m.find(target - nums[i]);
            if(p != m.end()) 
            {
                vector<int> ret;
                ret.push_back(p->second+1);
                ret.push_back(i+1);
                return ret;
            }
            m[nums[i]] = i;
        }
    }
};




int main()
{
    Solution *s = new Solution();

    vector<int> nums;
    //nums.push_back(2);
    //nums.push_back(7);
    //nums.push_back(11);
    //nums.push_back(15);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(4);
    nums.push_back(7);
    nums.push_back(2);
    //sort(nums.begin(), nums.end());

    vector<int> vec = s->twoSum(nums, 11);
    cout << vec[0] << " " << vec[1] << endl;
    return 0;

} 

// errorCode
// 注释的方法只对排好序的数组可以工作，没排序或没按由小到大的排序的都会出错
//    vector<int> ret;
//    int j = 0;
//    for(int i=0; i<nums.size(); i++)
//    {
//        if(nums[i] < target)
//        {
//            j = i;
//        }
//    }
//    for(int i = 0; i < j; )
//    {
//        int sum = nums[i] + nums[j];
//        if(sum==target)
//        {
//            // ret.insert(0,i+1);
//            // ret.insert(1,j+1);
//            ret.push_back(i+1);
//            ret.push_back(j+1);
//            break;
//        }
//        else
//        {
//            (sum > target) ? j--: i++;
//        }
//    }
//    return ret;

//}