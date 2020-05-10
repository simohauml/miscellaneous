#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

class Solution;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        if (s1 > s2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int iMin { 0 };
        int iMax { s1 };
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = (s1 + s2 + 1) / 2 - i;
            if (j != 0 && i != s1 && nums2[j - 1] > nums1[i]) {
                iMin = i + 1;
            } else if (j != s2 && i != 0 && nums1[i - 1] > nums2[j]) {
                iMax = i - 1;
            } else {
                int maxLeft { 0 };
                if (0 == i) {
                    maxLeft = nums2[j - 1];
                } else if (0 == j) {
                    maxLeft = nums1[i - 1];
                } else {
                    maxLeft = std::max(nums1[i - 1], nums2[j - 1]);
                }
                if (1 == (s1 + s2) % 2) {
                    return maxLeft;
                }

                int minRight { 0 };
                if (i == s1) {
                    minRight = nums2[j];
                } else if (j == s2) {
                    minRight = nums1[i];
                } else {
                    minRight = std::min(nums1[i], nums2[j]);
                }

                return (maxLeft + minRight) * 0.5;
            }
        }
        return 0.0;
    }
};

int main() {
    Solution* s;
    vector<int> n1 = {1, 3};
    vector<int> n2 = { 2 };
    const int a = n1.size();
    constexpr int a = n1.size();

    double m = s->findMedianSortedArrays(n1, n2);
    cout << m << endl;
    return 0;
}

// The k-th number solution. Here the k is specialized to the median
// which is length/2
//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        int s1 = nums1.size();
//        int s2 = nums2.size();
//        int left = (s1 + s2 + 1) / 2;
//        int right = (s1 + s2 + 2) / 2;
//        return ((getKth(nums1, 0, s1 - 1, nums2, 0, s2 - 1, left) +
//                getKth(nums1, 0, s1 - 1, nums2, 0, s2 - 1, right)) * 0.5);
//
//    }
//private:
//    int getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
//        int len1 = end1 - start1 + 1;
//        int len2 = end2 - start2 + 1;
//        if(len1 > len2) {
//            return getKth(nums2, start2, end2, nums1, start1, end1, k);
//        }
//
//        if(0 == len1) {
//            return nums2[start2 + k - 1];
//        }
//
//        if(k == 1) {
//            return std::min(nums1[start1], nums2[start2]);
//        }
//
//        int i1 = start1 + std::min(len1, (k / 2)) - 1;
//        int i2 = start2 + std::min(len2, (k / 2)) - 1;
//        if(nums1[i1] <= nums2[i2]) {
//            return getKth(nums1, i1 + 1, end1, nums2, start2, end2, k - (i1 - start1 + 1));
//        } else {
//            return getKth(nums1, start1, end1, nums2, i2 + 1, end2, k - (i2 - start2 + 1));
//        }
//    }
//
//};

//Basic solution
//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        double median {};
//        int i1 {0};
//        int i2 {0};
//        int midCount {};
//        int top {};
//        int next {};
//        int max_size = nums1.size() + nums2.size();
//        midCount = (0 == (max_size % 2)) ? (max_size / 2) + 1 : (max_size + 1) / 2;
//
//        int count {0};
//        while(count < midCount) {
//            if((i1 < nums1.size()) && (i2 < nums2.size())) {
//                if(nums1[i1] < nums2[i2]) {
//                    next = top;
//                    top = nums1[i1];
//                    count++;
//                    i1++;
//                } else if(nums1[i1] > nums2[i2]) {
//                    next = top;
//                    top = nums2[i2];
//                    count++;
//                    i2++;
//                } else {
//                    if(2 <= (midCount - count)) {
//                        next = top = nums1[i1];
//                        count = count + 2;
//                        i1++;
//                        i2++;
//                    } else {
//                        next = top;
//                        top = nums1[i1];
//                        count++;
//                    }
//                }
//            } else if(i1 >= nums1.size()) {
//                if(2 <= (midCount - count)) {
//                    top = nums2[i2 + (midCount - count - 1)];
//                    next = nums2[i2 + (midCount - count - 2)];
//                    count = midCount;
//                } else {
//                    next = top;
//                    top = nums2[i2 + (midCount - count - 1)];
//                    count++;
//                }
//            } else if(i2 >= nums2.size()) {
//                if(2 <= (midCount - count)) {
//                    top = nums1[i1 + (midCount - count - 1)];
//                    next = nums1[i1 + (midCount - count - 2)];
//                    count = midCount;
//                } else {
//                    next = top;
//                    top = nums1[i1 + (midCount - count - 1)];
//                    count++;
//                }
//            }
//        }
//
//        median = (0 == (max_size % 2)) ? (static_cast<double>(top) + static_cast<double>(next)) / 2.0 : top;
//        return median;
//    }
//};