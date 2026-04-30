class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> prefixProducts(nums.size(), 1);
        vector<int> suffixProducts(nums.size(), 1);
        
        for (int index=1;index<nums.size();index++)
        {
            prefixProducts[index] = prefixProducts[index-1]*nums[index-1];
        }

        for (int index = nums.size() - 2;index>-1;index--)
        {
            suffixProducts[index] = suffixProducts[index + 1]*nums[index+1];
        }

        for (int index = 0;index<nums.size();index++)
        {
            suffixProducts[index] = suffixProducts[index]*prefixProducts[index];
        }

        return suffixProducts;
    }
};

/*

there are two ways to do this -

you can first get product total product, then divide as you go, but this might lead to an overflow

or

maintain two product lists, elements so far, and elements after, multiply them by each other.

*/