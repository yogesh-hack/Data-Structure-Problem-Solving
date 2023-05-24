// 1137. N-th Tribonacci Number
// Example 1:

// Input: n = 4
// Output: 4
// Explanation:
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4
// Example 2:

// Input: n = 25
// Output: 1389537


class Solution {
public:
    int tribonacci(int n) {
        vector<int>tribonacci={0,1,1};
        if(n<tribonacci.size())
        {
            return tribonacci[n];
        }
        n-=2;
        while(n--)
        {
            int N=tribonacci.size();
            tribonacci.push_back(tribonacci[N-1]+tribonacci[N-2]+tribonacci[N-3]);
        }
        return tribonacci.back();
    }
};
