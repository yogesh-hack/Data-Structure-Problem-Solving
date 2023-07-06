### 

dfgfd



saf




f
sdf

sdf


sfsf


-jbashjf
-khsfkjsdf
-hjgsafjksf
# Tree 
- Collection of tree-Nodes

1. Class TreeNode
```
    ↳ data
    ↳ list <TreeNode> children
```

2. Binary tree -> atmost 2 children (0,1,2)
```
    ↳ data
    ↳ leftchild
    ↳ rightchild
```
# Tree 
- Collection of tree-Nodes

1. Class TreeNode
```
    ↳ data
    ↳ list <TreeNode> children
```

2. Binary tree -> atmost 2 children (0,1,2)
```
    ↳ data
    ↳ leftchild
    ↳ rightchild
```

## Type of Binary Tree
A. Complete Bainary Tree








# Tree 
- Collection of tree-Nodes

1. Class TreeNode
```
    ↳ data
    ↳ list <TreeNode> children
```

2. Binary tree -> atmost 2 children (0,1,2)
```
    ↳ data
    ↳ leftchild
    ↳ rightchild
```

## Type of Binary Tree
A. Complete Bainary Tree
```
    ↳ all level are completely filled except last one.
```
B. Full Binary Tree
```
    ↳ Every node has 0 or 2 childern
```
C. Perfect Binary Tree
```
    ↳ every internal node has exactly 2 childern
```
D. Skewed Bainary Tree 
```
    ↳ all nodes has either one or no child
    ↳ used for finding compexity
```

## Structure of Tree Code in C++"

```c++
#include <iostream>
using namespace std;

// Defining binary tree Nodes
strcut TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x),left(nullptr),right(nullptr) {};
    TreeNode(int x, TreeNode *left,TreeNode *right) : val(x),left(left),right(right) {};
};

int main(){
    //  Construct a binary  tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
}
```

## Depth of binary tree 
```
1. Add 1 when Returning
2. Sum at each node
3. max sum of value is depth
```

### Code
```c++
int depth(TreeNode *root){
    if(root == NULL) return 0;

    int leftnode = 1 + depth(root -> left);
    int rightnode = 1 +  depth(root -> right);
    return max(leftnode, rightnode); 
}
```

## Traversal
    ↳ DFS : 
        ↳ - preorder
        ↳ - inorder
        ↳ - postorder
    ↳ BFS : 
        ↳ Level order

**A. Preorder :**
- Order  : `Root -> leftchild -> rightchild`
```
TC : $$O(N)$$
SC : $$O(N)$$
```

### Code
```c++
vector<int> preorderTraversal(TreeNode *root){
    vector<int> ans;
    Preorder(root,ans);
    return ans;
}

void Preorder(Treeorder *root , vector<int> ans){
    if(root == NULL) return;
    ans.push_back(root->val);
    Preorder(root->left,ans);
    Preorder(root->right,ans);
    return;
}
```

**B. PostOrder :**
- Order : `LeftChild -> rightchild -> root`
```
TC : $$O(N)$$
SC : $$O(N)$$
```

### Code

```c++
vector<int> postorderTraversal(TreeNode *root){
    vector<int> ans;
    Postorder(root,ans);
    return ans;
}

void Postorder(Treeorder *root , vector<int> ans){
    if(root == NULL) return;
    Postorder(root->left,ans);
    Postorder(root->right,ans);
    ans.push_back(root->val);
    return;
}
```

**C. Inorder :**
- order : `leftchild -> root -> rightchild`
```
TC : $$O(N)$$
SC : $$O(N)$$
```

### Code

```c++
vector<int> inorderTraversal(TreeNode *root){
    vector<int> ans;
    Inorder(root,ans);
    return ans;
}

void Inorder(Treeorder *root , vector<int> ans){
    if(root == NULL) return;
    Inorder(root->left,ans);
    ans.push_back(root->val);
    Inorder(root->right,ans);
    return;
}
```

## BFS (Level Order Traversal) :
### Example :
```sql
          [50]    -------- level 0
       ↙        ↘
    [35]          [57] ------- level 1
   ↙    ↘        ↙   ↘
[30]     [40]  [40]    [58] ------ level 2
        ↙
     [11]              -------- level 3

ans = [50,35,57,30,40,40,58,11]
```

### Approach:
```
1. Enqueue the root Node into queue for store the nodes
2. loop until the queue becomes empty.
3. Inside the loop, dequeue a node from the front of the queue and print its value.
```

### Code :
```c++
vector<int> levelOrderTraversal(TreeNode* root) {
    vector<int> ans;
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();
            ans.push_back(current);

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }
    return ans;
}
    
```


## Merge two binary trees :
```
1. Perform preorder traversal on tree because node/root need to be first.
2. put value of each node in one node.
3. add each node values 
```
```
TC : $$O(n +m )$$
SC : $$O(max(n,m))$$
```

### Code :
```c++
TreeNode* merge(TreeNode *root1, TreeNode *root2){
    if(root1 == NULL && root2 == NULL) return NULL;
    if(root1 == NULL) return root2;
    if(root2 == NULL) return root1;

    // create new treenode to store sum of two tree
    TreeNode *newNode = new TreeNode(root1->val + root2->val);

    // call left and right sub-trees
    newNode -> left = merge(root1->left,root2->left);
    newNode -> right = merge(root1->right,root2->right);

    return newNode;
}

TreeNode * mergeTrees(TreeNode *root1,TreeNode* root2){
    return merge(root1,root2);
}
```

## Sum of root to leaf paths :
### Example :
```sql
        [1]
       ↙   ↘
    [0]     [1]
   ↙  ↘       ↘
[0]    [1]      [0]
      ↙
    [0]

=> (100)₂ + (1010)₂ + (110)₂
=> 4 + 12 + 6
=> 22 ans..
```
```
1. Initial sum = 0 and add node value to empty string
2. if root == NULL get, then stop and convert binary string into number.
3. Add to sum and return result.
```
```
TC : $$O(N)$$
SC : $$O(N)$$
```
### Code
```c++
void rootToleaf(TreeNode *root, string currentString,int * result){
    if(root->left == NULL && root->right == NULL){
        // convert integer to string
        currentString += to_string(root->val);
        // convert string to integer with binary representation
        result[0] += stoi(currentString,0,2);
        return;
    }

    string cur = to_string(root->val);
    if(root -> left != NULL) {
        rootToleaf(root->left,currentString+cur,result);
    }
    if(root -> right != NULL){
        rootToleaf(root->right,currentString+cur,result);
    }

}

int sumRootToLeaf(TreeNode *root){
    int* result = new int[1];
    result[0] = 0;
    rootToleaf(root,"",result);
    return result[0];
}

````

## Univalued Binary Tree :
### Example :
```sql
        [1]                 [1]
       ↙   ↘              ↙   ↘
    [1]     [1]         [1]     [1]
   ↙  ↘       ↘       ↙  ↘       ↘
[1]    [1]     [1]  [1]    [4]     [1]

    return True       return false
```
```
1. check all node until unique value is found
2. if unique value is found, return False to parent node to root node.
3. Perform AND operation with current Node's True/False and parent node's True/False, then return True/False.
```

### Code
```c++
bool isSame(TreeNode *root, int val){
    if(root == NULL) return true;
    // check unique value
    if(root->val != val) return false;

    bool left = isSame(root->left,val);
    bool right = isSame(root->right,val);

    return left && right;
}
bool isunivalTree(TreeNode *root){
    return isSame(root,root->val);
}
```

## Leaf Similar Tree :
### Example :
```sql
        [3]                 [3]
       ↙   ↘              ↙   ↘
    [5]     [1]         [5]      [1]
   ↙  ↘     ↙  ↘      ↙  ↘     ↙  ↘
[6]    [2] [9]  [8]   [6]  [7] [4]  [2]
      ↙  ↘                        ↙  ↘
    [7]   [4]                    [9]   [8]

// last Node(leaf node)
V1 = {6,7,4,9,8}
V2 = {6,7,4,9,8}
if (v1 == v2) return True otherwise return False
```
### Code
```c++
void traversal(TreeNode *root, vector<int> &v){
    if(root == NULL) return;

    if(root ->left == NULL && root ->right == NULL) {
        v.push_back(root>val);
    }

    if(root ->left != NULL){
        traversal(root->left,v);
    }
    if(root ->right != NULL){
        traversal(root->right,v);
    }
}

bool leafSimilar(TreeNode *root1, TreeNode *root2){
    vector<int> a;
    vector<int> b;
    traversal(root1,a);
    traversal(root2,b);
    return a == b;
}
```

## Binary Tree path :
`↳ Given root print all paths from root to leaf`
### Example :
```sql
        [2]
       ↙   ↘
    [4]     [5]
   ↙  ↘       ↘
[6]    [7]      [8]
      ↙
    [9]

▶ path 1 : [2 → 4 → 6]
▶ path 2 : [2 → 4 → 7 → 9]
▶ path 3 : [2 → 5 →8]

return ["2 → 4 → 6", "2 → 4 → 7 → 9", "2 → 5 → 8"]
```

### Approach
```sql
                        [2, " "]
                      ↙        ↘
                [4,"2→"]     [5,"2→"]
            ↙      ↘                ↘
    [6,"2→4→"]    [7,"2→4→"]        [8,"2→5→"]
        ▼            ↙                 ▼
 [leaf,"2→4→6→"] [9,"2→4→7→]         [leaf,"2→5→8→"]
                    ▼
                [leaf,"2→4→7→9→"]
```

### Code
```c++
void paths(TreeNode *root, vector<int> &res, string curr){
    if(root == NULL) return;

    if(root -> leaf == NULL && root->right == NULL){
        curr += to_string(root->val);
        res.push_back(curr);
        return;
    }

    curr = to_string(root->val) + "→";

    if(root -> leaf != NULL){
        paths(root->left, res, curr);
    }
    if(root -> right != NULL){
        paths(root->right, res, curr);
    }
}

vector<int> binarypath(TreeNode *root){
    vector<int> res;
    paths(root,res, "");
    return res;
}
```

## Sum of left leaves :
## Example :
```sql
        [1]
       ↙   ↘
    [2]     [3]
   ↙  ↘     ↙ 
[4]    [5] [11]
      ↙  ↘
    [9]   [8]
            ↘
            [9]

Result is : 4 + 7 + 11
            22 ans..
```

```
1. check root 's left and add True
2. Check root 's right and add False
3. return sum of left 

```

### Code :
```c++
int leftleafSum(TreeNode *root, bool leaf){
    if (root == NULL) return 0;

    if(root->left == NULL && root->right == NULL && leaf){
        return root->val;
    }

    int ls = leftleafSum(root->left,true);
    int rs = leftleafSum(root->right,false);
    return ls + rs;
}

int sumofleaf(TreeNode *root){
    return leftleafSum(root,false);
}

```

## Path Sum :
`↳ Sum of all nodes from root to leaf is equal to target sum -> then True else false.`

### Example :
```sql
        [20]
       ↙   ↘
    [15]     [12]
   ↙  ↘        ↘
[16]    [13]    [19]
      ↙ 
    [4] 
Target : 52
```
### Approach 
```sql
        [20,0] 
         ↙   ↘
     [15,20]     [12,20]
   ↙        ↘        ↘
[16,35]    [13,35]    [19,32]
            ↙    ↘
         [4,48] [null, 48] ▶ return
Target : 52
```
```
TC : $$O(n)$$
SC : $$O(1)$$
```

### Code
```c++
bool pathSum(TreeNode *root, int curr, int targetSum){
    if(root -> NULL) return false;

    if(root->left == NULL && root->right == NULL){
        return (curr+root->val) == targetSum;
    }

    return pathSum(root->left, curr+root->val, targetSum) || pathSum(root->right, curr+root->val, targetSum);
}

bool hasPathSum(TreeNode *root, int target){
    return pathSum(root,0,target);
}

```

## Left of Binary Tree :
### Exmaple : 
```sql
        [4] ------ 1
       ↙   ↘
    [9]     [10] ------- 2
      ↘     ↙  
      [12] [11] -------- 3
           ↙ 
        [4]  ----------- 4

Result is : [4,9,12,13]
```

### Approach
```
1. For every level traversal , check if it already exists in the set
2. If already exists in the set then countinue, else add the root's value to araay 
```

### Code :
```c++
void lefttraversal(TreeNode *root, vector<int> &res, set<int> &s, int curr){
    if (root == NULL) return;

    if(s.find(curr) == s.end()){
        s.insert(curr);
        res.push_back(root->val);
    }

    lefttraversal(root->left, res, s, curr + 1);
    lefttraversal(root->right, res, s, curr + 1);
    return;
}

vector<int> leftview(TreeNode *root){
    vector<int> res;
    set<int> s;
    lefttraversal(root, res, s, 0);
    return res;
}

```

## Right View of Binary Tree :
### Example :
```sql
        [4] ------ 1
       ↙   ↘
    [9]     [10] ------- 2
      ↘     ↙  
      [12] [11] -------- 3
           ↙ 
        [4]  ----------- 4

Result is : [4,10,11,4]
```

### Code :
```c++
void lefttraversal(TreeNode *root, vector<int> &res, set<int> &s, int curr){
    if (root == NULL) return;

    if(s.find(curr) == s.end()){
        s.insert(curr);
        res.push_back(root->val);
    }

    lefttraversal(root->right, res, s, curr + 1);
    lefttraversal(root->left, res, s, curr + 1);
    return;
}

vector<int> rightview(TreeNode *root){
    vector<int> res;
    set<int> s;
    righttraversal(root,res,s,0);
    return res;
}
```

## Same Binary Tree :
↳ return tree if both trees are same else false.

### Code:
```c++
bool isSameTree(TreeNode *root1, TreeNode *root2){
    if(root1 == NULL && root2 == NULL) return false;
    if(root1 == NULL || root2 == NULL || root1->val != root2->val) return false;

    return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}
```

## Invert Binary Tree :
↳ Find the mirror image of given binary tree.

### Exmaple:
```sql
        [20]                              [20]
       ↙   ↘                            ↙     ↘
    [15]     [12]          invert      [12]     [15]
  ↙  ↘        ↘         ▶▶▶▶▶▶    ↙       ↙    ↘ 
[16]    [13]    [19]                [19]    [13]    [16]
      ↙                                       ↘ 
    [4]                                        [4]

```

```
1. Invert the left and right sub-trees and strore them seperately.
2. Attach the branch to the root of the tree
```

### Code :
```c++
TreeNode *invertTree(TreeNode *root){
    if(root == NULL) return root;

    TreeNode *leftsub = invertTree(root->right);
    TreeNode *rightsub = invertTree(root->left);

    root->left = leftsub;
    root->right = rightsub;

    return root;
}
```


## Symmetric Tree :
↳ return tree if left sub-tree is equal to right sub-tree, else return false.

### Example :
```sql
            [2]
           ↙   ↘
        [1]     [12]
       ↙  ↘     ↙  ↘
    [6]    [3] [4]   [9]
   ↙                   ↘
[4]                     [4] 

```

### Code :
```c++
bool isMirror(TreeNode *leftTree, TreeNode *rightTree){
    if(leftTree == NULL && rightTree == NULL) return true;

    else if(leftTree == NULL || rightTree == NULL){
        return false;
    }
    else if(leftTree>val != rightTree->val){
        return false;
    }

    return isMirror(leftTree->left, rightTree->right) && isMirror(leftTree->right, rightTree->left);
}

bool isSymmetricTree(TreeNode *root){
    if(root == NULL) return true;
    return isMirror(root->left, root->right);
}
```


