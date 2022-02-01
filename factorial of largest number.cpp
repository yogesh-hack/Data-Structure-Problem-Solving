/*Factorials of large numbers
Given an integer N, find its factorial.

Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120
Example 2:

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800
*/

#include <bits/stdc++.h>
using namespace std;
void multiply(int n, vector<int>& number) {
      int carry = 0;
      for (int i = 0; i < number.size(); i++) {
          int num = n * number[i];
          number[i] = (char)((num + carry) % 10);
          carry = (num + carry) / 10;
      }
      while (carry) {
          number.push_back(carry % 10);
          carry /= 10;
      }
  }
  vector<int> factorial(int N){
      vector<int> number;
      number.push_back(1);
      for (int i = 2; i <= N; i++)
          multiply(i, number);
      reverse(number.begin(), number.end());
      return number;

  }

int main() {
  int t;
  cin >> t;
  while (t--) {
      int N;
      cin >> N;
      vector<int> result =factorial(N);
      for (int i = 0; i < result.size(); ++i){
          cout<< result[i];
      }
      cout << endl;
  }
  return 0;
}
