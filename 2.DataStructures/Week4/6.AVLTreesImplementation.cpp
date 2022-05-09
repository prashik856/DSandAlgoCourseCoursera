#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(0), right(0){}
};
unordered_map<TreeNode *, int> heightMapping;
unordered_map<TreeNode *, TreeNode *> parentMapping;

void inOrder(TreeNode *root){
    if(root == 0){
        return;
    }

    inOrder(root -> left);
    if(parentMapping[root] != 0){
        cout << root -> val << "->" << parentMapping[root]->val << "->" << heightMapping[root] << " ";
    } else {
        cout << root -> val << "->" << "->" << heightMapping[root] << " ";
    }

    inOrder(root -> right);
}

TreeNode* insert(TreeNode *root, int val, int height){
    TreeNode *newNode = new TreeNode(val);
    if(root == 0){
        // cout << "Root is empty" << endl;
        root = newNode;
        height++;
        heightMapping[newNode] = height;
        parentMapping[newNode] = 0;
        return root;
    }
    height++;
    TreeNode *temp = root;
    while(true){
        if(val > temp -> val){
            if(temp -> right == 0){
                height++;
                temp -> right = newNode;
                heightMapping[newNode] = height;
                parentMapping[newNode] = temp;
                break;
            } else {
                temp = temp -> right;
                height++;
            }
        } else {
            if(temp -> left == 0){
                height++;
                temp -> left = newNode;
                heightMapping[newNode] = height;
                parentMapping[newNode] = temp;
                break;
            } else {
                temp = temp -> left;
                height++;
            }
        }
    }
    return root;
}

TreeNode *findNode(TreeNode *root, int val){
    if(root == 0){
        return 0;
    }

    if(root -> val == val){
        return root;
    }
    TreeNode *result = 0;
    if(val > root -> val){
        result = findNode(root -> right, val);
    } else {
        result = findNode(root -> left, val);
    }

    return result;
}

void adjustHeight(TreeNode *root){
    int leftHeight = 0;
    if(root -> left != 0){
        leftHeight = heightMapping[root -> left];
    }
    int rigthHeight = 0;
    if(root -> right != 0){
        rigthHeight = heightMapping[root -> right];
    }
    int rootHeight = 1 + max(leftHeight, rigthHeight);
    heightMapping[root] = rootHeight;
}

void rotateLeft(TreeNode *root){

}

void rotateRight(TreeNode *root){
    TreeNode *parent = parentMapping[root];
    TreeNode *y = root -> left;
    TreeNode *b = y -> right;
    parentMapping[y] = parent;
    
}

void rebalanceLeft(TreeNode *root){
    
}

void rebalanceRight(TreeNode *root){
    TreeNode *node = root -> left;
    int leftHeight = 0;
    int rightHeight = 0;
    if(node -> left != 0){
        leftHeight = heightMapping[node -> left];
    }
    if(node -> right != 0){
        rightHeight = heightMapping[node -> right];
    }
    if(rightHeight > leftHeight){
        rotateLeft(node);
    }
    rotateRight(root);
}

void rebalance(TreeNode *root){
    TreeNode* parent = parentMapping[root];
    int leftHeight = 0;
    int rightHeight = 0;
    if(parent -> left != 0){
        leftHeight = heightMapping[parent -> left];
    }
    if(parent -> right != 0){
        rightHeight = heightMapping[parent -> right];
    }

    if(leftHeight > rightHeight + 1){
        rebalanceRight(root);
    } else if(rightHeight > leftHeight + 1){
        rebalanceLeft(root);
    }

    adjustHeight(root);
    if(parent != 0){
        rebalance(parent);
    }
}

TreeNode* avlInsert(TreeNode *root, int val){
    int height = 0;
    root = insert(root, val, height);
    TreeNode *node = findNode(root, val);
    rebalance(node);
    return root;
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TreeNode *root = 0;
    for(int i=0; i<a.size(); i++){
        // cout << "Inserting value: " << a[i] << endl;
        root = avlInsert(root, a[i]);
    }
    cout << "Given tree is: " << endl;
    inOrder(root); cout << endl;

    return 0;
}