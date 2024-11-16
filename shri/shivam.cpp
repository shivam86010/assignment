//-----------------------------------------------------
void preorder(TreeNode*root, vector<int>&ans)
{
    if(root==Null)
    return ans;
    
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

//-----------------------------------------------------
vector<int>preorder(TreeNode*root)
{
    vector<int>ans;
    if(root==Null)
    return ans;
    
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty())
    {
        root=st.top();
        st.pop();
        
        ans.push_back(root->val);
        if(root->right!=Null)
        st.push(root->right);
        
        if(root->left!=Null)
        st.push(root->left);
    }
    return ans;
}

//-----------------------------------------------------
void inorder(TreeNode*root, vector<int>&ans)
{
    if(root==Null)
    return ans;
    
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

//-----------------------------------------------------
vector<int>inorder(TreeNode*root)
{
    stack<TreeNode*>st;
    TreeNode*node=root;
    vector<int>ans;
    while(true)
    {
        if(node!=Null)
        {
            st.push(node);
            node=node->left;
        }
        else 
        {
            if(st.empty()==true)
            break;
            node=st.top();
            st.pop();
            
            ans.push_back(node->val);
            node=node->right;
        }
    }
    return ans;
}

//-----------------------------------------------------
void postorder(TreeNode*root, vector<int>&ans)
{
    if(root==Null)
    return ans;
    
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}

//-----------------------------------------------------
vector<int>postorder(TreeNode*root)
{
    vector<int>ans;
    if(root==Null)
    return ans;
    
    stack<TreeNode*>st1;
    stack<TreeNode*>st2;
    st1.push(root);
    while(!st1.empty())
    {
        root=st1.top();
        st1.pop();
        st2.push(root);
        
        if(root->left!=Null)
        st1.push(root->left);
        
        if(root->right!=Null)
        st1.push(root->right);
    }
    
    while(!st2.empty())
    {
        ans.push_back(st2.top()->val);
        st2.pop();
    }
    return ans;
}

//-----------------------------------------------------
vector<int>onetraversal(TreeNode*root)
{
    vector<int>pre;
    vector<int>in;
    vector<int>post;
    stack<pair<TreeNode*, int>>st;
    st.push({root, 1});
    if(root==Null)
    return ;
    
    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        
        if(it.second==1)
        {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            
            if(it.first->left!=Null)
            {
                st.push({it.first->val, 1});
            }
        }
        else if(it.second==2)
        {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            
            if(it.first->right!=Null)
            {
                st.push({it.first->right, 1});
            }
        }
        else 
        {
            post.push_back(it.first->val);
        }
    }
    
}


//-----------------------------------------------------
int maxdepth(TreeNode*root)
{
    if(root==Null)
    return 0;
    
    int lh=maxdepth(root->left);
    int rh=maxdepth(root->right);
    
    return 1+max(lh,rh);
}


//-----------------------------------------------------
int height(TreeNode*root)
{
    if(root==Null)
    return 0;
    
    int lh=height(root->left);
    if(lh==-1)
    return -1;
    
    int rh=height(root->right);
    if(rh==-1)
    return -1;
    
    if(abs(lh-rh)>1)
    return -1;
    
    return 1+max(lh, rh);
}
bool isbalanced(TreeNode*root)
{
    return height(root)!=-1;
}


//-----------------------------------------------------
int height(TreeNode*root,  int &num)
{
    if(root==Null)
    return 0;
    
    int lh=height(root->left, num);
    int rh=height(root->right, num);
    num=max(num, lh+rh);
    
    return 1+max(lh, rh);
}
int diameter(TreeNode*root)
{
    int dia=0;
    height(root, dia);
    return dia;
}

//-----------------------------------------------------
vector<vector<int>>levelorder(TreeNode*root)
{
    vector<vector<int>>ans;
    if(root==Null)
    return ans;
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(node->left!=Null)
            q.push(node->left);
            
            if(node->right!=Null)
            q.push(node->right);
            
            level.push_back(root->val);
        }
        ans.push_back(level);
    }
    return ans;
}

//-----------------------------------------------------
vector<vector<int>>levelorder2(TreeNode*root)
{
    vector<vector<int>>ans;
    if(root==Null)
    return ans;
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(node->left!=Null)
            q.push(node->left);
            
            if(node->right!=Null)
            q.push(node->right);
            
            level.push_back(root->val);
        }
        ans.push_back(level);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//-----------------------------------------------------
vector<vector<int>>zigzag(TreeNode*root)
{
    vector<vector<int>>ans;
    if(root==Null)
    return ans;
    
    queue<TreeNode*>q;
    q.push(root);
    bool lefttoright=true;
    
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            int index= lefttoright ? i : (size-1-i);
            if(node->left!=Null)
            q.push(node->left);
            
            if(node->right!=Null)
            q.push(node->right);
        }
        lefttoright=!lefttoright;
        ans.push_back(level);
    }
    return ans;
}

//-----------------------------------------------------
int maxpathdown(TreeNode*root, int &maxi)
{
    if(root==Null)
    return 0;
    
    int lh=max(0, maxpathdown(root->left, maxi));
    int rh=max(0, maxpathdown(root->right, maxi));
    maxi=max(maxi, lh+rh+root->val);
    
    return root->val+max(lh, rh);
}
int maxpathsum(TreeNode*root)
{
    int maxi=INT_MIN;
    maxpathsum(root, maxi);
    return maxi;
}

//-----------------------------------------------------
bool issametree(TreeNode*p, TreeNode*q)
{
    if(p==Null || q==Null)
}

//-----------------------------------------------------
TreeNode*searchinBST(TreeNode*root, int val)
{
    while(root!=Null && root->val!=val)
    {
        if(root->val>val)
        {
            root=root->left;
        }
        else 
        {
            root=root->right;
        }
    }
    return root;
}

//-----------------------------------------------------
int findceil(TreeNode<int>*root, int key)
{
    int ceil=-1;
    while(root)
    {
        if(root->val==key)
        {
            ceil=root->val;
            return ceil;
        }
        
        if(key>root->val)
        {
            root=root->right;
        }
        else 
        {
            ceil=root->val;
            root=root->left;
        }
    }
    return ceil;
}

//-----------------------------------------------------
int findfloor(TreeNode<int>*root, int key)
{
    int floor=-1;
    while(root)
    {
        if(root->val==key)
        {
            floor=root->val;
            return floor;
        }
        
        if(key>root->val)
        {
            floor=root->val;
            root=root->right;
        }
        else 
        {
            root=root->left;
        }
    }
    return floor;
}

//-----------------------------------------------------
TreeNode*insertinBST(TreeNode*root, int val)
{
    if(root==Null)
    return new TreeNode(val);
    
    TreeNode*curr=root;
    while(true)
    {
        if(curr->val<=val)
        {
            if(curr->right!=Null)
            {
                curr=curr->right;
            }
            else 
            {
                curr->right=new TreeNode(val);
                break;
            }
        }
        else 
        {
            if(curr->left!=Null)
            {
                curr=curr->left;
            }
            else 
            {
                curr->left=new TreeNode(val);
                break;
            }
        }
    }
    return root;
}

//-----------------------------------------------------
TreeNode*findlastright(TreeNode*root)
{
    if(root->right==Null)
    return root;
    
    return findlastright(root->right);
}
TreeNode*helper(TreeNode*root)
{
    if(root->left==Null)
    {
        return root->right;
    }
    else if(root->right==Null)
    {
        return root->left;
    }
    
    TreeNode*rightchild=root->right;
    TreeNode*lastright=findlastright(rot->left);
    lastright->right=rightchild;
    
    return root->left;
}
TreeNode*deleteNodeinBST(TreeNode*root, int key)
{
    if(root==Null)
    return Null;
    
    if(root->val==key)
    return helper(root);
    
    TreeNode*dummy=root;
    while(root!=Null)
    {
        if(root->val>key)
        {
            if(root->left!=Null && root->left->val==key)
            {
                root->left=helper(root->left);
                break;
            }
            else 
            {
                root=root->left;
            }
        }
        else 
        {
            if(root->right!=Null && root->right->val==key)
            {
                root->right=helper(root->right);
                break;
            }
            else 
            {
                root=root->right;
            }
        }
    }
    return dummy;
}

//-----------------------------------------------------
void markparent(TreeNode*root, unordered_map<TreeNode*, TreeNode*>&parent, TreeNode*target)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    { 
        TreeNode*current=q.front();
        q.pop();
        
        if(current->left)
        {
            parent[current->left]=current;
            q.push(current->left);
        }
        
        if(current->right)
        {
            parent[current->right]=current;
            q.push(current->right);
        }
    }
}
vector<int>distancek(TreeNode*root, TreeNode*target, int k)
{
    unordered_map<TreeNode*, TreeNode*>parent; //node->parent 
    markparent(root, parent, target);
    
    unordered_map<TreeNode*, bool>visit;
    queue<TreeNode*>q;
    q,push(target);
    visit[target]=true;
    int curr_level=0;
    while(!queue.empty())
    {
        int size=q.size();
        if(curr_level++==k)
        break;
        
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(node->left && !visit[node->left])
            {
                q.push(node->left);
                visit[node->left]=true;
            }
            
            if(node->right && !visit[node->right])
            {
                q.push(node->right);
                visit[node->right]=true;
            }
            
            if(parent[node] && !visit[parent[node]])
            {
                q.push(parent[node]);
                visit[parent[node]]=true;
            }
        }
    }
    
    vector<int>ans;
    while(!q.empty())
    {
        TreeNode*node=q.front();
        q.pop();
        
        ans.push_back(node->val);
    }
    return ans;
}

//----------------------------------------------------------------------------------------- 
#include<bits/stdc++.h>
using namespace std;

//preorder traversal using recursive (144)== 
void preorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

//preorder traversal using iterative ==
vector<int>preorderit(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty())
    {
        root=st.top();
        st.pop();
        
        ans.push_back(root->val);
        
        if(root->right!=NULL)
        st.push(root->right);
        
        if(root->left!=NULL)
        st.push(root->left);
    }
    return ans;
}

//inorder traversal using recursive (94)==
void inorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

//inorder traversal using iterative ==
vector<int>inorderit(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    stack<TreeNode*>st;
    TreeNode*node=root;
    while(true)
    {
        if(node!=NULL)
        {
            st.push(node);
            node=node->left;
        }
        else 
        {
            if(st.empty()==true)
            break;
            
            node=st.top();
            st.pop();
            
            ans.push_back(node->val);
            
            node=node->right;
        }
    }
    return ans;
}

//postorder traversal using recursive (145)==
void postorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}

//postorder traversal using iterative using 2 stack ==
vector<int>postorderit(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    stack<TreeNode*>st1;
    stack<TreeNode*>st2;
    st1.push(root);
    while(!st1.empty())
    {
        root=st1.top();
        st1.pop();
        
        st2.push(root);
        if(root->left!=NULL)
        st1.push(root->left);
        
        if(root->right!=NULL)
        st1.push(root->right);
    }
    
    while(!st2.empty())
    {
        ans.push_back(st2.top()->val);
        st2.pop();
    }
    return ans;
}

///postorder traversal using iterative using 1 stack ==
vector<int>postorderit2(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    stack<TreeNode*>st;
    TreeNode*curr=root;
    while(curr!=NULL || !st.empty())
    {
        if(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        else 
        {
            TreeNode*temp=st.top()->right;
            if(temp==NULL)
            {
                temp=st.top();
                st.pop();
                
                ans.push_back(temp->val);
                
                while(!st.empty() && temp==st.top()->right)
                {
                    temp=st.top();
                    st.pop();
                    
                    ans.push_back(temp->val);
                }
            }
            else 
            {
                curr=temp;
            }
        }
    }
    return ans;
}

//preorder, inorder and postorder traversal using single iteration 
void preinpostoder(TreeNode*root)
{
    if(root==NULL)
    return ;
    
    vector<int>pre;
    vector<int>in;
    vector<int>post;
    stack<pair<TreeNode*, int>>st;
    st.push({root, 1});
    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        
       if(it.second==1)
       {
           pre.push_back(it.first->val);
           it.second++;
           st.push(it);
           
           
       }
       else if(it.second==2)
       {
           in.push_back(it.first->val);
           it.second++;
           st.push(it);
       }
       else 
       {
           post.push_back(it.first->val);
       }
    }
}

//level order traversal (102)==
vector<vector<int>>levelorder(TreeNode*root)
{
    vector<vector<int>>ans;
    if(root==NULL)
    return ans;
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            level.push_back(node->val);
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}

//second version of level order traversal (107)==
vector<vector<int>>levelorder2(TreeNode*root)
{
    vector<vector<int>>ans;
    if(root==NULL)
    return ans;
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            level.push_back(node->val);
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
        }
        ans.push_back(level);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


//zigzag order traversal(103) ==
vector<vector<int>>zigzag(TreeNode*root)
{
    vector<vector<int>>ans;
    if(root==NULL)
    return ans;
    
    queue<TreeNode*>q;
    q.push(root);
    bool lefttoright=true;
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            int index=lefttoright ? i : size-1-i;
            level[index]=(node->val);
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
        }
        lefttoright=!lefttoright;
        ans.push_back(level);
    }
    return ans;
}


//left side view of binary tree (199) ==
vector<int>leftsideview(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(i==0)
            ans.push_back(node->val);
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
        }
    }
    return ans;
}

//right side view of binary tree ==
vector<int>rightsideview(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(i==size-1)
            ans.push_back(node->val);
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
        }
    }
    return ans;
}

//level order successor (successor means given a key value find the right value of given key)
int levelordersuccessor(TreeNode*root, int key)
{
    if(root==NULL)
    return NULL;
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode*node=q.front();
        q.pop();
        
        if(node->left!=NULL)
        q.push(node->left);
        
        if(node->right!=NULL)
        q.push(node->right);
        
        if(node->val==key)
        break;
    }
    return q.front();
}

//average of level binary tree (637)
vector<int>leftsideview(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        int sum=0;
        
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            sum+=(node->val);
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
        }
        ans.push_back(sum/size);
    }
    return ans;
}

//maximum level sum of a binary tree
int maxilevelsum(TreeNode*root)
{
    if(root==NULL)
    return -1;
    
    int ans=-1;
    int level=-1;
    int maxi=INT_MIN;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        int sum=0;
        level++;
        
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            sum+=(node->val);
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
        }
        
        if(sum>maxi)
        {
            ans=level;
            maxi=sum;
        }
    }
    return ans;
}

//Kth largest sum in a binary tree (2583)
int kthlargestsum(TreeNode*root, int k)
{
    if(root==NULL)
    return -1;
    
    priority_queue<int, vector<int>, greater<int>>pq;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        int sum=0;
        
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            sum+=(node->val);
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
        }
        pq.push(sum);
        
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    
    if(pq.size()<k)
    return -1;
    
    return pq.top();
}

//minimum depth of binary tree(111)
int minimumdepth(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    queue<TreeNode*>q;
    q.push(root);
    int depth=1;
    while(!q.empty())
    {
        int size=q.size();
        
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(node->left==NULL && node->right==NULL)
            return depth;
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
        }
        depth++;
    }
    return depth;
}

//maximum depth of binary tree(104) ==
int maxidepth(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=maxidepth(root->left);
    int rh=maxidepth(root->right);
    
    return 1+max(lh, rh);
}

//using level order traversal 
int maxidepth2(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    queue<TreeNode*>q;
    q.push(root);
    int depth=0;
    while(!q.empty())
    {
        int size=q.size();
        
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
        }
        depth++;
    }
    return depth;
}

//minimum number of operations to sort a binary tree by level (2471)
int countoperation(vector<int>&arr)
{
    int n=arr.size();
    vector<pair<int,int>>v;
    
    for(int i=0; i<n; i++)
    {
        v.push_back({arr[i], i});
    }
    
    sort(v.begin(), v.end());
    
    int count=0;
    for(int i=0; i<n; i++)
    {
        if(v[i].second==i)
        continue;
        
        while(v[i].second != i)
        {
            count++;
            swap(v[i], v[v[i].second]);
        }
    }
    return count;
}
int mininumberoperation(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int ans=0;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            level.push_back(node->val);
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
        }
        
        ans+=(countoperation(level));
    }
    return ans;
}

//find largest value in each row
//find bottom left tree value (513)
//cousins of binary tree using map data structure 
void slove(TreeNode* node, int depth, int parent, unordered_map<int, pair<int, int>>& m) 
{
    if (node==NULL) 
    return;
    
    mp[node->val] = {depth, parent};
    
    if(node->left!=NULL)
    slove(node->left, depth + 1, node->val, mp);
    
    if(node->right!=NULL)
    slove(node->right, depth + 1, node->val, mp);
}
bool isCousins(TreeNode* root, int x, int y) 
{
    unordered_map<int, pair<int, int>>mp;
	slove(root, 0, -1, mp);
	
	return mp[x].first == mp[y].first && mp[x].second != mp[y].second;
}

//using recursion cousins of binary tree 
int xdepth, ydepth, xparent, yparent;
void depth(TreeNode* root, int x, int y, int dep, int par_val)
{
    if(root==NULL) 
    return;
    
    if(root->val==x)
    {
        xdepth=dep;
        xparent=par_val;
        return;
    }
    
    if(root->val==y)
    {
        ydepth=dep;
        yparent=par_val;
        return;
    }
    
    if(root->left!=NULL)
    slove(root->left, x, y, dep+1, root->val);
    
    if(root->right!=NULL)
    slove(root->right, x, y, dep+1, root->val);
}
bool isCousins(TreeNode* root, int x, int y) 
{
    if(root->val==x || root->val==y) return false;
    slove(root, x, y, 0, 0);
    
    if(xdepth==ydepth && xparent!=yparent) return true;
    return false;
}
    
//using level order cousins of binary tree
bool cousinsbt(TreeNode*root, int a, int b)
{
    if(root==NULL)
    return false;
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        bool ifexistx=false;
        bool ifexisty=false;
        
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(node->val==a)
            ifexistx=true;
            
            if(node->val==b)
            ifexisty=true;
            
            if(node->left!=NULL && node->right!=NULL)
            {
                if(node->left->val==a && node->right->val==b)
                return false;
                
                if(node->left->val==b && node->right->val==a)
                return false;
            }
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
        }
        if(ifexisty && ifexistx)
        return true;
    }
    return false;
}

//deepest leaves sum 
int deepestsum(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int sum=0;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        
        sum=0;
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            sum+=(node->val);
        }
    }
    return sum;
}

//find largest value in each row
vector<int>largestvalinrow(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        
        int maxi=INT_MIN;
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            maxi=max(maxi, node->val);
        }
        ans.push_back(maxi);
    }
    return ans;
}

//check for balance binary tree (110)== 
int height(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=height(root->left);
    if(lh==-1)
    return -1;
    
    int rh=height(root->right);
    if(rh==-1)
    return -1;
    
    if(abs(lh-rh)>1)
    return -1;
    
    return 1+max(lh, rh);
}
bool isbalance(TreeNode*root)
{
    return height(root)!=-1;
}

//diameter of binary tree == 
int slove(TreeNode*root, int &maxi)
{
    if(root==NULL)
    return 0;
    
    int lh=slove(root->left, maxi);
    int rh=slove(root->right, maxi);
    
    maxi=max(maxi, lh+rh);
    
    return 1+max(lh, rh);
}
int diameterofbt(TreeNode*root)
{
    int dia=0;
    slove(root, dia);
    return dia;
}

//maximum path sum ==
int maxipath(TreeNode*root, int &maxi)
{
    if(root==NULL)
    return 0;
    
    int lh=max(0, maxipath(root->left, maxi));
    int rh=max(0, maxipath(root->right, maxi));
    
    maxi=max(maxi, root->val+lh+rh);
    
    return root->val+max(lh, rh);
}
int maximumpathsum(TreeNode*root)
{
    int maxi=-1;
    maxipath(root, maxi);
    return maxi;
}

//check two tree is identical/same  or not (100)== 
bool isidentical(TreeNode*p, TreeNode*q)
{
    if(p==NULL || q==NULL)
    return (p==q);
    
    return (p->val==q->val) && isidentical(p->left, q->left) && isidentical(p->right, q->right)
}

//check symmetric tree  or not(101)== 
bool isidentical(TreeNode*p, TreeNode*q)
{
    if(p==NULL || q==NULL)
    return (p==q);
    
    return (p->val==q->val) && isidentical(p->left, q->right) && isidentical(p->right, q->left)
}
bool symmetric(TreeNode*root)
{
    return issame(root->left, root->right);
}

//boundary order traversal in binary tree ==
//convert sorted array to binary search tree(108)
Node*makeBST(vector<int>arr, int start, int end)
{
    if(start>end)
    return NULL;
    
    int mid=start+(end-start)/2;
    
    Node*root=new Node(arr[mid]);
    root->left=makeBST(arr, start, mid-1);
    root->right=makeBST(arr, mid+1, end);
    return root;
}
Node*sortedBST(vector<int>num)
{
    if(num.size()==0)
    return NULL;
    
    return makeBST(num, 0, nums.size()-1);
}

//convert sorted linked list to binary search tree  (109)
Node*slove(vector<int>&ans, int start, int end)
{
    if(start>end)
    return NULL;
    
    int mid=start+(end-start)/2;
    
    Node*root=new Node(ans[mid]);
    root->left=slove(ans, start, mid-1);
    root->right=slove(ans, mid+1, end);
    return root;
}
Node*sortedBST(Node*head)
{
    vector<int>ans;
    while(head!=NULL)
    {
        ans.push_back(head->val);
        head=head->next;
    }
    return slove(ans, 0, ans.size()-1);
}

//second mathod
TreeNode*convertsortedlist(ListNode*head)
{
    if(head==NULL)
    return NULL;
    
    if(head->next==NULL)
    return new TreeNode(head->val);
    
    auto slow=head;
    auto fast=head;
    auto pre=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    
    pre->next=NULL;
    TreeNode*root=new TreeNode(slow->val);
    
    root->left=convertsortedlist(head);
    root->right=convertsortedlist(slow->next);
    
    return root;
}


//make maximum binary tree
TreeNode*makemaxitree(vector<int>&arr, int start, int end)
{
    if(start>end)
    return NULL;
    
    int maxi=INT_MIN;
    int maxindex=-1;
    for(int i=start; i<=end; i++)
    {
        if(arr[i]>maxi)
        {
            maxi=arr[i];
            maxindex=i;
        }
    }
    
    TreeNode*root=new TreeNode(maxi);
    
    root->left=makemaxitree(arr, start, maxindex-1);
    root->right=makemaxitree(arr, maxindex+1, end);
    
    return root;
}
TreeNode*maximumBT(vector<int>&arr)
{
    return makemaxitree(arr, 0, arr.size()-1);
}

//construct binary tree from preorder and inorder (105)
TreeNode*maketree(vector<int>&preorder, vector<int>inorder, int prest, int preend, int instart, int inend, map<int,int>mp)
{
    if(prest>preend || instart>inend)
    return NULL;
    
    TreeNode*root=new TreeNode(preorder[prest]);
    int pos=mp[root->val];
    int left=pos-instart;
    
    root->left=maketree(preorder, inorder, prest+1, prest+left, instart, pos-1 , mp);
    root->right=maketree(preorder, inorder, prest+left+1, preend, pos+1, inend, mp);
    
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    if(inorder.size()!=preorder.size())
    return NULL;
    
    map<int,int>mp;
    for(int i=0; i<inorder.size(); i++)
    {
        mp[inorder[i]]=i;
    }
    
    TreeNode*root=maketree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, mp);
    return root;
}


//construct binary tree from inorder and postorder (106)
TreeNode*maketree(vector<int>inorder, vector<int>postorder, int is, int ie, int ps, int pe, map<int,int>mp)
{
    if(is>ie || ps>pe)
    return NULL;
    
    TreeNode*root=new TreeNode(postorder[pe]);
    int pos=mp[root->val];
    int left=pos-is;
    
    root->left=maketree(inorder, postorder, is, pos-1, ps, pe+left-1, mp);
    root->right=maketree(inorder, postorder, pos+1, ie, ps+left, pe-1, mp);
    
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    if(inorder.size()!=postorder.size())
    return NULL;
    
    map<int,int>mp;
    for(int i=0; i<inorder.size(); i++)
    {
        mp[inorder[i]]++;
    }
    
    TreeNode*root=maketree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1, mp);
    return root;
}

//path sum  (112)
bool pathsum(TreeNode*root, int targetsum)
{
    if(root==NULL)
    return true;
    
    if(root->left==NULL && root->right==NULL && targetsum-root->val==0)
    return true;
    
    return pathsum(root->left, targetsum-root->val) || pathsum(root->right, targetsum-root->val);
}


//path sum-II (113)
vector<vector<int>>ans;
vector<int>path;
void slove(TreeNode*root, int sum, int targetsum)
{
    if(root==NULL)
    return ;
    
    sum+=root->val;
    path.push_back(root->val);
    if(sum==targetsum)
    {
        ans.push_back(path);
        return ;
    }
    
    slove(root->left, sum, targetsum);
    slove(root->right, sum, targetsum);
    path.pop_back();
}
vector<vector<int>pathsum-II(TreeNode*root, int targetsum)
{
    int sum=0;
    slove(root, sum, targetsum);
    return ans;
}

//binary tree path 
void slove(TreeNode*root, string temp, vector<string>&ans)
{
    if(root==NULL);
    return ;
    
    temp+=(to_string(root->val)+"->");
    if(root->left==NULL && root->right==NULL)
    {
        temp+=(to_string(root->val));
        ans.push_back(temp);
        return ;
    }
    
    if(root->left!=NULL)
    slove(root->left, temp, ans);
    
    if(root->right!=NULL)
    slove(root->right, temp, ans);
}
vector<string>binarytreePath(TreeNode*root)
{
    vector<string>ans;
    string s;
    slove(root, s, ans);
    return ans;
}

//sum root to leaf number (node 1->2->3==123 and so on )
void slove(TreeNode*root, int sum, int &ans)
{
    if(root==NULL);
    return ;
    
    sum=sum*10+root->val;
    if(root->left==NULL && root->right==NULL)
    {
        ans+=sum;
        return;
    }
    
    if(root->left!=NULL)
    slove(root->left, sum, ans);
    
    if(root->right!=NULL)
    slove(root->right, sum, ans);
}
int sumroottoleaf(TreeNode*root)
{
    int sum=0;
    int ans;
    slove(root, sum, ans);
    return ans;
}

//count total node in a complete binary tree ==
void slove(TreeNode*root, int &count)
{
    if(root==NULL)
    return ;
    
    count++;
    slove(root->left, count);
    slove(root->right, count);
}
int countcomplete(TreeNode*root)
{
    int count=0;
    slove(root, count);
    return count;
}

//second method 
int findheightleft(TreeNode*root)
{
    int height=0;
    while(root!=0)
    {
        height++;
        root=root->left;
    }
    return height;
}
int findheightright(TreeNode*root)
{
    int height=0;
    while(root!=0)
    {
        height++;
        root=root->left;
    }
    return height;
}
int countnode(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=findheightleft(root->left);
    int rh=findheightright(root->right);
    
    if(lh==rh)
    return (1<<lh)-1;
    
    return 1+countnode(root->left)+countnode(root->right);
}

//invert binary tree 
TreeNode*invertBT(TreeNode*root)
{
    if(root=NULL)
    return NULL;
    
    invertBT(root->left);
    invertBT(root->right);
    
    swap(root->left, root->right);
    
    return rot;
}

//sum of left leaf node 
void slove(TreeNode*root, int &sum)
{
    if(root==NULL)
    return ;

    if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL)
    sum+=root->left->val;

    slove(root->left, sum);
    slove(root->right, sum);
}
int sumOfLeftLeaves(TreeNode* root) 
{
    int sum=0;
    slove(root, sum);
    return sum;
}

//merge two binary tree
Node*mergetree(Node*root1, Node*root2)
{
    if(root1==NULL)
    return root2;
    
    if(root2==NULL)
    return root1;
    
    root1->val+=root2->val;
    root1->left=mergetree(root1->left, root2->left);
    root1->right=mergetree(root1->right, root2->right);
    return root1;
}


//verical order traversal ==
vector<vector<int>>vericalorder(TreeNode*root)
{
    vector<vector<int>>ans;
    if(root==NULL)
    return ans;
    
    map<int, map<int, multiset<int>>mp;
    queue<pair<TreeNode*, pair<int,int>>q;
    q.push({root, {0, 0}});
    while(!q.empty())
    {
        auto p=q.front();
        p.pop();
        
        TreeNode*node=q.first;
        int line=p.second.first;
        int level=p.second.second;
        
        mp[line][level].insert({node->val});
        
        if(node->left!=NULL)
        {
            q.push({node->left, {line-1, level+1}});
        }
        
        if(node->right!=NULL)
        {
            q.push({node->right, {line+1, level+1}});
        }
    }
    
    for(auto it : mp)
    {
        vector<int>temp;
        for(auto q : it.second)
        {
            temp.insert(temp.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}


//top view of binary tree ==
vector<int>topview(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    map<int, int>mp;
    queue<pair<TreeNode*, int>>q;
    q.push({root, 0});
    while(!q.empty())
    {
        auto it =q.front();
        q.pop();
        
        TreeNode*node=it.first;
        int line=it.second;
        
        if(mp.find(line)==mp.end())
        mp[line]=node->val;
        
        if(node->left!=NULL)
        q.push({node->left, line-1});
        
        if(node->right!=NULL)
        q.push({node->right, line+1});
    }
    
    for(auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

//bottom view of binary tree==
vector<int>topview(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    map<int, int>mp;
    queue<pair<TreeNode*, int>>q;
    q.push({root, 0});
    while(!q.empty())
    {
        auto it =q.front();
        q.pop();
        
        TreeNode*node=it.first;
        int line=it.second;
        
        mp[line]=node->val;
        
        if(node->left!=NULL)
        q.push({node->left, line-1});
        
        if(node->right!=NULL)
        q.push({node->right, line+1});
    }
    
    for(auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

//print root to node path in binary tree ==
bool getpath(TreeNode*root, vector<int>&ans, int node)
{
    if(root==NULL)
    return false;
    
    ans.push_back(root->val);
    
    if(root->val==node)
    return true;
    
    if(getpath(root->left, ans, node) || getpath(root->right, ans, node))
    return true;
    
    ans.pop_back();
    return false;
}
vector<int>roottonode(TreeNode*root, int node)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    getpath(root, ans, node);
    return ans;
}

//maximum width of binary tree ==
int maxiwidth(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int ans=0;
    queue<pair<TreeNode*, int>>q;
    q.push({root, 0});
    while(!q.empty())
    {
        int size=q.size();
        
        int mini=q.front().second;
        int first;
        int last;
        for(int i=0; i<size; i++)
        {
            int currindex=q.front().second-mini;
            TreeNode*node=q.front().first;
            q.pop();
            
            if(i==0)
            first=currindex;
            
            if(i==size-1)
            last=currindex;
            
            if(node->left!=NULL)
            q.push({node->left, 2*currindex+1});
            
            if(node->right!=NULL)
            q.push({node->right, 2*currindex+2});
        }
        ans=max(ans, last-first+1);
    }
    return ans;
}

//children sum property in binary tree ==
void childrensum(TreeNode*root)
{
    if(root==NULL)
    return ;
    
    int child=0;
    if(root->left!=NULL)
    child+=root->left->val;
    
    if(root->right!=NULL)
    child+=root->right->val;
    
    if(child>=root->val)
    {
        root->val=child;
    }
    else 
    {
        if(root->left!=NULL)
        root->left-.val=root->val;
        
        else if(root->right!=NULL)
        root->right->val=root->val;
    }
    
    childrensum(root->left);
    childrensum(root->right);
    
    int total=0;
    if(root->left!=NULL)
    total+=root->left->val;
    
    if(root->right!=NULL)
    total+=root->right->val;
    
    if(root->left!=NULL || root->right!=NULL)
    root->val=total;
}

//print all the node at a distance k in binary tree ==
void markparent(TreeNode*root, unordered_map<TreeNode*, TreeNode*>&mp, TreeNode*target)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode*node=q.front();
        q.pop();
        
        if(node->left!=NULL)
        {
            mp[node->left]=node;
            q.push(node->left);
        }
        
        if(node->right!=NULL)
        {
            mp[node->right]=node;
            q.push(node->right);
        }
    }
}
vector<int>distancek(TreeNode*root, int k, TreeNode*target)
{
    unordered_map<TreeNode*, TreeNode*>parent;
    markparent(root, parent, target);
    
    unordered_map<TreeNode*, bool>visit;
    
    queue<TreeNode*>q;
    q.push(target);
    visit[target]=true;
    
    int distance=0;
    while(!q.empty())
    {
        int size=q.size();
        
        if(distance++ == k)
        break;
        
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(node->left!=NULL && !visit[node->left])
            {
                q.push(node->left);
                visit[node->left]=true;
            }
            if(node->right!=NULL && !visit[node->right])
            {
                q.push(node->right);
                visit[node->right]=true;
            }
            
            if(parent[node] && !visit[parent[node]])
            {
                q.push(parent[node]);
                visit[parent[node]]=true;
            }
        }
    }
    
    vector<int>ans;
    while(!q.empty())
    {
        TreeNode*node=q.front();
        q.pop();
        
        ans.push_back(node->val);
    }
    return ans;
}

//minimum time taken to burn the binary tree from a node==
int findmaxdistance(map<TreeNode<int>*, TreeNode<int>*>&mp , TreeNode<int>*target)
{
    queue<TreeNode<int>*>q;
    q.push(target);
    
    map<TreeNode<int>*, int>visit;
    mp[target]=1;
    int maxi=0;
    while(!q.empty())
    {
        int size=q.size();
        int flage=1;
        for(int i=0; i<size; i++)
        {
            auto node =q.front();
            q.pop();
            
            if(node->left!=NULL && !visit[node->left])
            {
                flage=1;
                q.push(node->left);
                visit[node->left]=1;
            }
            
            if(node->right!=NULL && !visit[node->right])
            {
                flage=1;
                q.push(node->right);
                visit[node->right]=1;
            }
            
            if(mp[node] && !visit[mp[node]])
            {
                flage=1;
                q.push(mp[node]);
                visit[mp[node]]=1;
            }
        }
        
        if(flage)
        maxi++;
    }
    return maxi;
}
TreeNode<int>*parentmap(TreeNode<int>*root, map<TreeNode<int>*, TreeNode<int>*>&mp, int start)
{
    queue<TreeNode<int>*>q;
    q.push(root);
    
    TreeNode<int>*ans; //this store the address  of start 
    while(!q.empty())
    {
        TreeNode<int>*node=q.front();
        if(node->val==start)
        ans=node;
        q.pop();
        
        if(node->left!=NULL)
        {
            mp[node->left]=node;
            q.push(node->left);
        }
        
        if(node->right!=NULL)
        {
            mp[node->right]=node;
            q.push(node->right);
        }
    }
    return ans;
}
int minitimeburn(TreeNode<int>*root, int start)
{
    map<TreeNode<int>*, TreeNode<int>*>mp;
    TreeNode<int>*target=parentmap(root, mp, start); //this map the node to parent and also resturn the address of start 
    
    int maxi=findmaxdistance(mp, target);
    return maxi;
}


//search in binary search tree recusive solution ---700
TreeNode*BSTsearch(TreeNode*root, int val)
{
    if(root==NULL || root->val==val)
    return root;
    
    
    if(val>root->val)
    return BSTsearch(root->right, val);
    
    return BSTsearch(root->left, val);
} 

//iterative solution 
TreeNode*BSTsearch(TreeNode*root, int val)
{
    TreeNode*temp=root;
    
    while(true)
    {
        if(temp==NULL || temp->val==val)
        break;
        
        else if(val>root->val)
        temp=temp->right;
        
        else 
        temp=temp->left;
    }
    return temp;
}

//find the ceil in a binary search tree 
int findceil(TreeNode<int>*root, int key)
{
    int ceil=-1;
    while(root)
    {
        if(root->val==key)
        {
            ceil=root->val;
            return ceil;
        }
        if(key>root->val)
        {
            root=root->right;
        }
        else 
        {
            ceil=root->val;
            root-=root->left;
        }
    }
    return ceil;
}

//find floor in binary search tree 
int findfloor(TreeNode<int>*root, int key)
{
    int floor=-1;
    while(root)
    {
        if(root->val==key)
        {
            floor=root->val;
            return floor;
        }
        if(key>root->val)
        {
            floor=root->val;
            root=root->right;
        }
        else 
        {
            root-=root->left;
        }
    }
    return floor;
}

//insert into a binary search tree recusive method ----701
TreeNode*insertintoBST(TreeNode*root, int val)
{
    if(root==NULL)
    return new TreeNode(val);
    
    if(val>root->val)
    {
        root->right=insertintoBST(root->right, val);
    }
    else 
    {
        root->left=insertintoBST(root->left, val);
    }
    return root;
}

//iterative method 
TreeNode*insertintoBST(TreeNode*root, int val)
{
    if(root==NULL)
    return new TreeNode(val);
    
    TreeNode*curr=root;
    while(true)
    {
        if(curr->val<=val)
        {
            if(curr->right!=NULL)
            {
                curr=curr->right;
            }
            else 
            {
                curr->right=new TreeNode(val);
                break;
            }
        }
        else 
        {
            if(curr->left!=NULL)
            {
                curr=curr->left;
            }
            else 
            {
                curr->left=new TreeNode(val);
                break;
            }
        }
    }
    return root;
}

//delete node in binary search tree ---450 
TreeNode*findlast(TreeNode*root)
{
    if(root->right==NULL)
    return root;
    
    return findlast(root->right);
}
TreeNode*helper(TreeNode*root)
{
    if(root->left==NULL)
    return root->right;
    
    else if(root->right==NULL)
    return root->left;
    
    TreeNode*rightchild=root->right;
    TreeNode*lastright=findlast(root->left);
    lastright->right=rightchild;
    
    return root->left;
}
TreeNode*deleteNode(TreeNode*root, int key)
{
    if(root==NULL)
    return NULL;
    
    if(root->val==key)
    return helper(root);
    
    TreeNode*dummy=root;
    while(root!=NULL)
    {
        if(root->val>key)
        {
            if(root->left!=NULL && root->left->val==key)
            {
                root->left=helper(root->left);
                break;
            }
            else 
            {
                root=root->left;
            }
        }
        else 
        {
            if(root->right!=NULL && root->right->val==key)
            {
                root->right=helper(root->right);
                break;
            }
            else 
            {
                root=root->right;
            }
        }
    }
    return dummy;
}

//valid binary search tree --- 98 
bool slove(TreeNode*root, long mini, long maxi)
{
    if(root==NULL)
    return true;
    
    if(root->val>=maxi || root->val<=mini)
    return false;
    
    return slove(root->left, mini, root->val) && slove(root->right, root->val, maxi);
    
}
bool isvalidBST(TreeNode*root)
{
    return slove(root, LONG_MIN, LONG_MAX);
}

//recover binary search tree means (swaping two node with changing the structure ) --- 99
private :
TreeNode*first;
TreeNode*second;
TreeNode*pre;
TreeNode*middle;
private;
void inorder(TreeNode*root)
{
    if(root==NULL)
    return ;
    
    inorder(root->left);
    
    if(pre!=NULL && (root->val<pre->val))
    {
        if(first==NULL)
        {
            first=pre;
            middle=root;
        }
        else 
        {
            second=root;
        }
    }
    
    pre=root;
    
    inorder(root->right);
}
void recoverTree(TreeNode*root)
{
    first=second=middle=NULL;
    pre=new TreeNode(INT_MIN);
    
    inorder(root);
    
    if(first && second)
    swap(first->val , second->val);
    
    else if(first && middle)
    swap(first->val, middle->val);
}


//kth smallest element in binary search tree  brute force approach  ---230
void preorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
int kthsmallestinBST(TreeNode*root, int k)
{
    vector<int>ans;
    preorder(root, ans);
    sort(ans.begin(), ans.end());
    
    return ans[k-1];
}

//better approach 
void inorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
int kthsmallestinBST(TreeNode*root, int k)
{
    vector<int>ans;
    inorder(root, ans);
    return ans[k-1];
}

//optimal approach
void inorder(TreeNode*root, int &count, int &ans, int k)
{
    if(root==NULL)
    return ;
    
    inorder(root->left, count, ans, k);
    count++;
    
    if(count==k)
    {
        ans=root->val;
        return ;
    }
    
    inorder(root->right, count, ans, k);
}
int kthsmallestinBST(TreeNode*root, int k)
{
    int count=0;
    int ans;
    inorder(root, count, ans, k);
    return ans;
}


//find the second minimum node in binary tree 
void preorder(TreeNode*root, vector<int>&ans)
{
    if(root===NULL)
    return ;
    
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
int secondmininodeBT(TreeNode*root)
{
    vector<int>ans;
    preorder(root, ans);
    sort(ans.begin(), ans.end());
    int mini=ans[0];
    
    int n=ans.size();
    int sec=-1;
    for(int i=1; i<n; i++)
    {
        if(ans[i]!=mini)
        {
            sec=ans[i];
            break;
        }
    }
    return sec;
}

//convert binary search tree to greater tree --538 
private :
int sum=0;
TreeNode*convertBST(TreeNode*root)
{
    if(root!=NULL)
    {
        convertBST(root->right);
        
        sum+=root->val;
        root->val=sum;
        
        convertBST(root->left);
    }
    return root;
}

//trim binary search tree means(given a range when node node value not lie in range than simply delete) --- 669 
TreeNode*trimeBST(TreeNode*root, int low, int high)
{
    if(root==NULL)
    return NULL;
    
    if(root->val>=low && root->val<=high)
    {
        root->left=trimeBST(root->left, low, high);
        root->right=trimeBST(root->right, low, high);
        return root;
    }
    else if(root->val>high)
    {
        return trimeBST(root->left, low, high);
    }
    else if(root->val<low)
    {
        return trimeBST(root->right low, high);
    }
    return root;
}

//count good node in binary tree (good means root to till node node value will be maximum than this node will be good node) --1448
void preorder(TreeNode*root, int &count, int maxi)
{
    if(root==NULL)
    return ;
    
    if(root->val>=maxi)
    {
        count++;
        maxi=root->val;
    }
    
    preorder(root->left, count, maxi);
    preorder(root->right, count maxi);
}
int goodNode(TreeNode*root)
{
    int count=0;
    if(root==NULL)
    return count;
    
    preorder(root, count, root->val);
    return count;
}

//smallest subtree with all the depest node ---865 
int height(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=height(root->left);
    int rh=height(root->right);
    
    return 1+max(lh, rh);
}
TreeNode*subtreewithdepest(TreeNode*root)
{
    if(root==NULL)
    return NULL;

    int lefth=height(root->left);
    int righth=height(root->right);
    
    if(lefth==righth)
    return root;
    
    if(lefth>righth)
    {
        return subtreewithdepest(root->left);
    }
    else 
    {
        return subtreewithdepest(root->right);
    }
}

//lowest common ancestor of deepest leaves(both have same solution)  ----1123 
//increasing order search tree brute force approach  ------- 897 
void inorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
TreeNode*increasingBST(TreeNode*root)
{
    if(root==NULL)
    return NULL;
    
    vector<int>ans;
    inorder(root, ans);
    
    TreeNode*ans=new TreeNode(-1);
    TreeNode*curr=ans;
    for(auto node : ans)
    {
        curr->right=new TreeNode(node);
        curr=curr->next;
    }
    return ans->right;
}

//optimal approach 
void inorder(TreeNode*root, TreeNode*&ans)
{
    if(root==NULL)
    return ;
    
    inorder(root->left, ans);
    
    ans->right=new TreeNode(root->val);
    ans=ans->right;
    
    inorder(root->right, ans);
}
TreeNode*increasingBST(TreeNode*root)
{
    if(root==NULL)
    return NULL;
    
    TreeNode*ans=new TreeNode(0);
    TreeNode*temp=ans;
    inorder(root, ans);
    return temp->right;
}

//lowest common ancestor of binary tree (236) ==
//lowest common ancestor of binary search tree (235)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode*q)
{
    if(root==NULL)
    return NULL;
    
    int curr=root->val;
    if(curr<r->val && curr<q->val)
    {
        return lowestCommonAncestor(root->left, q, q);
    }
    
    if(curr>p->val && curr>q->val) 
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}

//populating next right pointers in each node (116)







