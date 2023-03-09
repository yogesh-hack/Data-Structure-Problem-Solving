//{ Driver Code Starts
//Initial Template for javascript

"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;



process.stdin.on("data", (inputStdin) => {
  inputString += inputStdin;
});

process.stdin.on("end", (_) => {
  inputString = inputString
    .trim()
    .split("\n")
    .map((string) => {
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
 
  for (; i < t; i++) {
    let N = parseInt(readLine());
    let arr = readLine().trim().split(" ").map((x) => parseInt(x));
    let k = parseInt(readLine());
    let obj = new Solution();
    let res = obj.kthSmallest(arr,0,N-1,k);
    console.log(res);
  }

}

// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number[]} arr
 * @param {number} l (starting index of the array i.e 0)
 * @param {number} r (ending index of the array i.e size-1)
 * @param {number} k
 * @return {number}
*/

class Solution {
  kthSmallest(arr,l,r,k){
    // Sort the array in ascending order
    arr.sort((a, b) => a - b);

    // Return the kth smallest element
    return arr[k - 1];
  }
}
