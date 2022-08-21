struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class solution{
public:
    TreeNode* invertTree(TreeNode* root){
        stack<TreeNode*> st;
        if( root != NULL ) st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            if (node != NULL){
                st.pop();
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);
                st.push(node);
                st.push(NULL);
            }else{
                st.pop();
                node = st.top();
                st.pop();
                swap(node->left,node->right);
            }
        }
        return root;
    }
}

class solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> result;
        if(root==NULL) return result;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            result.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return result;
    }
}


class solution{
public:
    vector<int> postorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> result;
        if(root == NULL) return result;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
}


class solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while( cur!= NULL || !st.empty() ){
            if(cur!=NULL){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;  
    }
}

class solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        queue<TreeNode*> que;
        vector<vector<int>> result;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            for(int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);

            }
            result.push_back(vec);
        }
        return result;
    }
}

class solution{
public:
    TreeNode* invertTree(TreeNode* root){
        queue<TreeNode*> que;
        if( root!=NULL ) que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return root;
    }
}

class solution{
public:
    TreeNode* invertTree(TreeNode* root){
        queue<TreeNode*>que;
        if( root!=NULL ) que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return root;
    }
}

//===================================

#include<iostream>
#include<stack>
//using namespace std;
int main()
{
    std::stack<int> mystack;
    
    mystack.push(10);
    mystack.push(20);

    mystack.top()-=5;

    std::cout<<"mystack.top() is now"<<mystack.top()<<std::endl;

    return 0;
}

#include<iostream>
#include<stack>
int main()
{
    std::stack<int> mystack;

    for(int i=0; i<5; ++i)
        mystack.push(i);
    std::cout<<"Popping out elements...";
    while(!mystack.empty())
    {
        std::cout<<''<<mystack.top();
        mystack.pop();
    }
    std::cout<<‘\n’；

    return 0;
}

#include<iostream>
#include<queue>

int main()
{
    std::queue<int> myqueue;
    int myint;

    do{
        std::cin>> myint;
        myqueue.push(myint);
    }while(myint);

    std::cout<<"";

    while(!myqueue.empty())
    {
        myqueue.pop();
    }

    return 0;
}

