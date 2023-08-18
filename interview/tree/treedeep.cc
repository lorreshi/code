//
// Created by 石立宇 on 2023/8/17.
//
#include "../../dp/sly.h"

//create_tree
typedef struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
//    TreeNode(int x):val(x),left(NULL),right(NULL){}        //构造函数
}*Tree,Node;

int i=0;
void create(Tree& T,vector<int>& vec){
    int x=vec[i++];//如果i作为迭代的参数，则递归返回时i也跟着回到原来的数，因此要在取值时就修改i的变量

    //叶子节点
    if(x==-1){
        T=NULL;
        return;
    }else{
        T = new Node;//在堆区创建空间，T指向其空间首地址
        T->val=x;
        create(T->left,vec);//递归寻找左子树
        create(T->right,vec);//递归寻找右子树
    }
}

class Solution {
public:
    //遍历二叉树，将符合的元素加入数组vec中
    void traversal(TreeNode* cur,vector<int>& vec){
        //遇到空指针时，说明一条路已经走完
        if(cur==NULL){
            return;
        }

        vec.push_back(cur->val);//中
        traversal(cur->left,vec);//左
        traversal(cur->right,vec);//右
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root,result);
        return result;
    }
};


//递归深度优先遍历
int maxDepth(TreeNode* root){
    if(root == nullptr)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth)+1;
}
//非递归
int maxDepth1(TreeNode* root) {
    if(root == NULL) return 0;
    deque<TreeNode*> q;         //创建双端队列
    q.push_back(root);          //层次遍历每个点只访问一次，所以开始就要将根节点入队列
    int deep = 0;
    while(!q.empty()){          //队列不为空，表示还有节点未访问
        deep++;
        int num = q.size();
        for(int i = 0;i < num;i++){  //一个for循环表示一层
            TreeNode* node = q.front();
            q.pop_front();
            if(node->left) q.push_back(node->left);  //先左节点再右节点，因为是队列，先进先出。
            if(node->right) q.push_back(node->right);
        }
    }
    return deep;
}


int main(){

    vector<int> vec = {1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};
    struct TreeNode* T;
    create(T, vec);
    cout << maxDepth1(T) << endl;


    //return 0;
}


