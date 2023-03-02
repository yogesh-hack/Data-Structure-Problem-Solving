class Solution {
public:
    int strStr(string haystack, string needle) {
        int count = 0;
        int start = 0;
        int end = 0;

        for(int i=0;i< haystack.length();i++){
            count = 0;
            if(haystack[i] == needle[0]){
                start = i;
                end = i;

                for(char ch : needle){
                    if(haystack[end] != ch){
                        break;
                    }
                    count++;
                    end++;
                }

                if(count == needle.length()){
                    return i;
                }
            }
        }
        return -1;
    }
};
