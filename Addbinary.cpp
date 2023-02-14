class Solution {
public:
    string addBinary(string a, string b) {
        int i=0;
        int carry=0;
        string ans="";
        int A=a.size();
        int B=b.size();
        while(i < A || i < B || carry!=0){
            int x=0;
            if(i<A && a[A-i-1]=='1'){
                x=1;
            }
            int y=0;
            if(i<B && b[B-i-1]=='1'){
                y=1;
            }
            ans=to_string((x+y+carry)%2)+ans;
            carry=(x+y+carry)/2;
            i+=1;
        }
        return ans;
    }
};
