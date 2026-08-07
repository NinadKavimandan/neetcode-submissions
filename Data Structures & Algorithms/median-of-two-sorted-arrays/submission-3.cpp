class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int>& smallerArray = nums1.size() > nums2.size() ? nums2 : nums1;
        vector<int>& largerArray = nums1.size() > nums2.size() ? nums1 : nums2;
        int smallerSize = smallerArray.size();
        int largerSize = largerArray.size();
        int total = smallerSize + largerSize;

        int low = 0;
        int high = smallerSize;
        int half = (smallerSize + largerSize + 1)/2;

        while (low <= high)
        {
            int cut = (low + high)/2;
            int cutOnOther = half - cut;

            int smallerLeft = cut > 0 ? smallerArray[cut - 1] : INT_MIN;
            int largerLeft = cutOnOther > 0 ? largerArray[cutOnOther - 1] : INT_MIN;

            int smallerRight = cut == smallerSize ? INT_MAX : smallerArray[cut];
            int largerRight = cutOnOther == largerSize ? INT_MAX : largerArray[cutOnOther];

            if (smallerLeft <= largerRight && largerLeft <= smallerRight)
            {
                if (total%2 == 0)
                {
                    return (max(smallerLeft, largerLeft) + min(smallerRight, largerRight))/2.0;
                }

                return max(smallerLeft, largerLeft);
            }
            else if (smallerLeft > largerRight)
            {
                high = cut - 1;
            }
            else
            {
                low = cut + 1;
            }
        }

        return -1;
    }
};

/*

since nums1 and nums2 are both sorted, we can find the numbers that would have half the total number elements in the merged array on their left.
to achieve this, take (0, nums1.size()) number of elements from nums1, and the remaining from the half from nums2, where nums1 must be smaller than nums2 for a bounded search and cut domain.

the cut in both arrays should be such that, elements on the left of each cut must be smaller than smallest number on the right of the other array.
to decide the cut, we binary search on (0, nums1.size()) such that

nums1Left | nums1Right
nums2Left | nums2Right

nums1Left <= nums2Right
nums2Left <= nums1Right

Median would be the smaller from the bordering elements for odd number of merged elements, average of the two middle numbers for even numbered merge.

*/