class solution{
public:
    vector<vector<int>> levelTracvel(TreeNode* root){
        TreeNode* node = root;
        stack<TreeNode*> que;
        vector<vector<int>> vector;
        que.push(root);
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
            vector.push_back(vec);          
        }
        return vector;
    }
}

class solution{
public:
    vector<vector<int>> levelTracvel(TreeNode* root){
        // TreeNode* node = root;
        queue[stack]<TreeNode*> que;
        vector<vector<int>> vector;
        if(root != NULL)[add judge] que.push(root);
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
            vector.push_back(vec);
        }
        return vector;
    }
}

class solution{
public:
    TreeNode* InvertLevelTraversal(TreeNode* root){
        queue<TreeNode*> que;
        //vector<vector<int>> result;
        if(root !=NULL ) que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();
                swap[reverse](node->left, node->right);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return root;
    }
}