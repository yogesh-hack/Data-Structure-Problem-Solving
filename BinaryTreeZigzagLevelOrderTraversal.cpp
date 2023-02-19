/**

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]



 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        // base case
        if(root == NULL) return ans;

        // create queue
        queue<TreeNode*> queue;
        queue.push(root);

        int check = false;

        while(!queue.empty()){
            int n = queue.size();

            vector<int> temp;
            while(n--){
                TreeNode* tree = queue.front();
                queue.pop();

                if(tree -> left){
                    queue.push(tree -> left);
                }

                if(tree -> right){
                    queue.push(tree -> right);
                }

                temp.push_back(tree -> val);
            }

            // if check is true
            if(check){
                reverse(temp.begin(), temp.end());
                check = false;
            }
            else{
                check = true;
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
