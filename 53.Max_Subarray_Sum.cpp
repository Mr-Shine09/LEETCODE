#include <vector>
#include <iostream>
using namespace std;

class Solution 
{
    public:
        int maxSubArray(vector<int>& nums)
        {
            //Kadane's Algorithm
            //currMax & globalMax
            //check if curr element > curr element + prev subarray
            //(cuz negative running sum would only drag down future values)
            //So start fresh
            //Global max is to check which subarray sum is bigger
    
            int currMax = nums[0];
            int globalMax = nums[0];
            for(int i=1; i<nums.size();i++)
            {
                currMax = max(nums[i],nums[i] + currMax);
                globalMax = max(globalMax,currMax);
            }
    
            return globalMax;
        }
};

int main()
{
        Solution s;
        vector<int> v1 = {-2,1,-3,4,-1,2,1,-5,4};
        vector<int> v2 = {1};
        vector<int> v3 = {5,4,-1,7,8};
    
        cout << s.maxSubArray(v1) << endl;
        cout << s.maxSubArray(v2) << endl;
        cout << s.maxSubArray(v3) << endl;
        return 0;
}
