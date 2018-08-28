#include<iostream>
#include<vector>

#include "util.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int nSize = nums.size();
        for(int i = 0; i < nSize; ++i){   
            int needNum = target - nums[i];
            for(int j = i + 1; j < nSize; ++j){   
                if(needNum == nums[j]){   
                    ret.push_back(j);
                    ret.push_back(i); // 按需push_back
                    return ret;
                }   
            }   
            ret.clear();
        }   
        ret.clear();
        return ret;        
    }
};

int main(int argc, char *argv[])
{
    vector<int> vec = {2, 7, 10, 15};
    int target = 9;
    Solution s;
    vector<int> result = s.twoSum(vec, 9);
	print_1d_vector(result);
    return 0;
}
