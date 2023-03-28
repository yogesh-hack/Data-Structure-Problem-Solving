#Problem : 273

// Input: num = 123
// Output: "One Hundred Twenty Three"
// Example 2:

// Input: num = 12345
// Output: "Twelve Thousand Three Hundred Forty Five"
// Example 3:

// Input: num = 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

class Solution {
public:
    string one(int num)
    {
        switch(num)
        {
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
            default: return "";
        }
    }
    string ten(int num)
    {
        switch(num)
        {
            case 2: return "Twenty";
            case 3: return "Thirty";
            case 4: return "Forty";
            case 5: return "Fifty";
            case 6: return "Sixty";
            case 7: return "Seventy";
            case 8: return "Eighty";
            case 9: return "Ninety";
            default: return "";
        }
    }
    string lessThan20(int num)
    {
        switch(num)
        {
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
            default: return "";
        }
    }
    
    string value(int n){
        string st = to_string(n);
        string s = "";
        if(st.size() == 3){
            int hundred = n/100;
            n = n%100;
            s += one(hundred) + " Hundred";
        }
        if(9 < n && n < 100){
            if(s.size() != 0) s += " ";
            if(n < 20) {
                s += lessThan20(n);
                return s;
            }
            else s += ten(n/10);
            n = n%10;
            
        }
        if(n != 0){
            if(s.size() != 0) s += " ";
            s += one(n);
        }
        return s;
    }
    
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string ans = "";
        int billion = num/ (1000000000);
        num %= 1000000000;
        int million = num/1000000;
        num %= 1000000;
        int thousand = num/1000;
        num %= 1000;
        if(billion != 0){
            ans += value(billion) + " Billion";
        }
        if(million != 0){
            if(ans.size() != 0) ans += " ";
            ans += value(million) + " Million";
        }
        if(thousand != 0){
            if(ans.size() != 0) ans += " ";
            ans += value(thousand) + " Thousand";
        }
        if(num != 0){
            if(ans.size() != 0) ans += " ";
            ans += value(num);
        }
        return ans;
    }
};

