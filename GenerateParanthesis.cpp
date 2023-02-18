// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]



class Solution {
public:

    vector<string> result;
    void solve(string &ans, int open, int close){
        // base case
        if(open == 0 & close == 0){
            result.push_back(ans);
            return;
        }

        if(open > 0){
            ans.push_back('(');
            solve(ans,open-1,close);
            ans.pop_back();
        }

        if(close > 0){
            if(close > open){
                ans.push_back(')');
                solve(ans,open,close-1);
                ans.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string ans = "";
        solve(ans,n,n);
        return result;
    }
};
