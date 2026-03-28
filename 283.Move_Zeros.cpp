#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:

        Solution(initializer_list<int> values) : nums(values)
        {
        }
        void moveZeroes(vector<int>& nums)
        {
            int insertptr = 0;
            for(int i=0; i<nums.size(); i++)
            {
                if(nums [i] != 0 && insertptr != i)
                {
                    swap(nums[insertptr],nums[i]);
                    insertptr++;
                }
            }
        }
        void vector_displayer(vector<int>& nums){
            cout << "[";
            for(int i=0; i<nums.size(); i++)
            {
                cout << nums[i] << " ";
            }
            cout << "]" <<endl;
        }

            vector<int> nums;
};

int main()
{
    Solution s1 = {0,1,0,3,12};
    Solution s2 = {0};
    Solution s3 = {1,3,12,0,0};
    Solution s4 = {0,0,1};

    s1.moveZeroes(s1.nums);
    s1.vector_displayer(s1.nums);

    s2.moveZeroes(s2.nums);
    s2.vector_displayer(s2.nums);

    s3.moveZeroes(s3.nums);
    s3.vector_displayer(s3.nums);

    s4.moveZeroes(s4.nums);
    s4.vector_displayer(s4.nums);
}
