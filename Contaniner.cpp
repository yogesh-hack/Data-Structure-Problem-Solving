// problem : 11

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;
        int max_area = 0;

        // Two-pointer Approach
        while (i < j) {
            int h = min(height[i], height[j]);
            int w = j - i;
            max_area = max(max_area, h * w);
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return max_area;
    }
};
