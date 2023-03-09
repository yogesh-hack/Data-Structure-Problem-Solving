//{ Driver Code Starts
//Initial Template for javascript
'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let n = parseInt(readLine());
        let arr = new Array(n);
        let input_ar1 = readLine().split(' ').map(x=>parseInt(x));
        for(let i=0;i<n;i++)
            arr[i] = input_ar1[i];
        let obj = new Solution();
        console.log(obj.majorityElement(arr, n));
        
    }
}
// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number[]} a
 * @param {number} size
 * @returns {number}
*/

class Solution {
    
    majorityElement(a, size)
    {
        const map = new Map();

          // Count the frequency of each element
          for (let i = 0; i < a.length; i++) {
            const num = a[i];
            if (map.has(num)) {
              map.set(num, map.get(num) + 1);
            } else {
              map.set(num, 1);
            }
          }

          // Check if any element appears more than n/2 times
          for (let [key, value] of map) {
            if (value > a.length / 2) {
              return key;
            }
          }
        
          // No majority element found
          return -1;
    }
}
