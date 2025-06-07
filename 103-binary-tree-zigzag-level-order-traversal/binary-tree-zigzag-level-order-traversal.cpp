class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*>q;
        q.push(root);

        vector<vector<int>>ans;
        bool flag=true;

        while(!q.empty()){
            int N=q.size();
            vector<int>temp;
            flag=!flag;
            while(N--){
                TreeNode* curr=q.front();
                q.pop();

                temp.push_back(curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(flag) reverse(begin(temp),end(temp));
            ans.push_back(temp);
        }
        return ans;
    }
};