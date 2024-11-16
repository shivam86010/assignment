#include<bits/stdc++.h>
using namespace std;

//level order traversal 
vector<vector<int>>levelorder(Node*root)
{
    vector<vector<int>>ans;
    if(root==NULL)
    return ans;
    
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        for(int i=0; i<size; i++)
        {
            Node*node=q.front();
            q.pop();
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}

//second version of level order traversal 
vector<vector<int>>levelorder2(Node*root)
{
    vector<vector<int>>ans;
    if(root==NULL)
    return ans;
    
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        for(int i=0; i<size; i++)
        {
            Node*node=q.front();
            q.pop();
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//average of level of binary tree  
vector<double>levelorder(Node*root)
{
    vector<double>ans;
    if(root==NULL)
    return ans;
    
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        double sum=0;
        for(int i=0; i<size; i++)
        {
            Node*node=q.front();
            q.pop();
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            sum+=node->val;
        }
        ans.push_back(sum/size);
    }
    return ans;
}

//level order successor of a node in binary tree 
Node*findsuccessor(Node*root, int key)
{
    if(root==NULL)
    return NULL;
    
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node*node=q.front();
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

//zig-zag order traversal 
vector<vector<int>>zig-zagorder(Node*root)
{
    vector<vector<int>>ans;
    if(root==NULL)
    return ans;
    
    bool lefttoright=true;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level(size);
        for(int i=0; i<size; i++)
        {
            Node*node=q.front();
            q.pop();
            
            int index=lefttoright ? 0 : (size-1-i);
            level[index]=node->val;
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
        }
        ans.push_back(level);
        lefttoright=!lefttoright;
    }
    return ans;
}

//right side view of binary tree 
vector<int>rightside(Node*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0; i<size; i++)
        {
            Node*node=q.front();
            q.pop();
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            if(i==size-1)
            ans.push_back(node->val);
        }
    }
    return ans;
}

//left side view of binary tree 
vector<int>leftsideview(Node*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0; i<size; i++)
        {
            Node*node=q.front();
            q.pop();
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            if(i==0)
            ans.push_back(node->val);
        }
    }
    return ans;
}

//minimum depth of binary tree 
int minidepth(node*root)
{
    if(root==NULL)
    return 0;
    
    int depth=1;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0; i<size; i++)
        {
            Node*node=q.front();
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













//maximum depth of binary tree 
int maximumdepth(Node*root)
{
    if(root==NULL)
    return 0;
    
    int lh=maximumdepth(root->left);
    int rh=maximumdepth(root->right);
    
    return 1+max(lh, rh);
}

// 
//convert sorted array to binary search tree
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

//convert sorted linked list to binary search tree 
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





//search in binary search tree recusive solution ---700
//time complexity is is O(logn)
//space complexity is O(n)
TreeNode*BSTsearch(TreeNode*root, int val)
{
    if(root==NULL || root->val==val)
    return root;
    
    
    if(val>root->val)
    return BSTsearch(root->right, val);
    
    return BSTsearch(root->left, val);
}

//iterative solution 
//time complexity is is O(logn)
//space complexity is O(1)
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
//time complexity is O(N)
//space complexity is O(1)
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
//time complexity is is O(logn)
//space complexity is O(n)
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
//time complexity is is O(logn)
//space complexity is O(1)
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
//time complexity is is O(logn)
//space complexity is O(1)
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
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is is O(n)
//space complexity is O(1)
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
//time complexity is is O(nlogn)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(1)+ recursive stack space
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
//time complexity is O(nlogn)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(N)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
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

//increasing order search tree brute force approach  ------- 897 
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
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


//lowest common ancestor of binary search tree 
//time complexity is O(n)
//space complexity is O(n)
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




//construct binary tree from preorder and inorder 
//time complexity is O(n)
//space complexity is O(n)
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


//construct binary tree from inorder and postorder 
//time complexity is O(n)
//space complexity is O(n)
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
    
    map<intint>mp;
    for(int i=0; i<inorder.size(); i++)
    {
        mp[inorder[i]]++;
    }
    
    TreeNode*root=maketree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1, mp);
    return root;
}

//check completeness of binary tree using level order traversal 
//time complexity is O(n)
//space complexity is O(n)
bool completeness(TreeNode*root)
{
    bool past=false; //this means check the past main koi null mila hai kya 
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode*node=q.front();
        q.pop();
        
        if(node==NULL)
        {
            past=true;
        }
        else 
        {
            if(past==true)
            {
                return false;
            }
            q.push(node->left);
            q.push(node->right);
        }
    }
    return true;
}

//check completeness of binary tree using level order traversal 
//time complexity is O(n)
//space complexity is O(n)
int CountNode(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    return 1+CountNode(root->left)+CountNode(root->right);
}
bool dfs(TreeNode*root, int i, int totalnode)
{
    if(root==NULL)
    return true;
    
    if(i>totalnode)
    return false;
    
    return dfs(root->left, 2*i, totalnode) && dfs(root->right, 2*i+1, totalnode);
}
bool completeness(TreeNode*root)
{
    int totalnode=CountNode(root);
    
    int i=1;
    return dfs(root, i, totalnode);
}


//validate binary search tree 
//time complexity is O(n)
//space complexity is O(1)
bool slove(TreeNode*root, long mini, long maxi)
{
    if(root==NULL)
    return true;
    
    if(root->val>=maxi || root->val<=mini)
    return false;
    
    return slove(root->left, mini,  root->val) && slove(root->right, root->val, maxi);
}
bool isvalidate(TreeNode*root)
{
    return slove(root, LONG_MIN, LONG_MAX);
}











#include<bits/stdc++.h>
using namespace std;

vector<int>topview(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    map<int,int>mp;
    queue<pair<TreeNode*, int>>q;
    q.push({root, 0});
    while(!q.empty())
    {
        auto it =q.front();
        q.pop();
        
        TreeNode*node=it.first;
        int line=it.second;
        
        if(mp.find(line)==mp.end())
        mp[line]=root->val;
        
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


vector<int>bottomview(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    map<int,int>mp;
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

vector<vector<int>>vertical(TreeNode*root)
{
    map<int, map<int, vector<int>>mp;
    queue<pair<TreeNode*, pair<int,int>>q;
    vector<int>ans;
    
    if(root==NULL)
    return ans;
    
    q.push({root, {0, 0}});
    while(!q.empty())
    {
        auto it =q.front();
        q.pop();
        
        TreeNode*node=q.first;
        int x=q.first.second.first;
        int y=q.first.second.second;
        
        node[x][y].insert(node->val);
        
        if(node->left!=NULL)
        q.push({node->left, {x-1, y+1}});
        
        if(node->right!=NULL)
        q.push({node->right, {x+1, y+1}});
    }
    
    vector<vector<int>>ans;
    for(auto p : node)
    {
        vector<int>result;
        for(auto q : p.second)
        {
            result.insert(result.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(result);
    }
    return ans;
}





//----------------------------------------------------------------------------------------- 
//count complete tree node 
int countcomplete(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int count=0;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        
        count+=size;
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
        }
    }
    return count;
}

//using property of complete binary tree
//time complexity is O(logn)^2 
//space complexity is O(logn)
int leftheight(TreeNode*root)
{
    int height=0;
    while(root!=NULL)
    {
        height++;
        root=root->left;
    }
    return height;
}
int rightheight(TreeNode*root)
{
    int height=0;
    while(root!=NULL)
    {
        height++;
        root=root->right;
    }
    return height;
}
int countcomplete(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=leftheight(root);
    int rh=rightheight(root);
    
    if(lh==rh)
    return 2*lh-1;   //(1<<lh)-1
    
    return 1+countcomplete(root->left)+countcomplete(root->right);
}



///////////////////////////////////////////////////////////////////////////////////////////////////// 

//preorder traversal 
//time complexity is O(n)
//space complexity is O(n) recusive call stack space if consider 
void preorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

//iterative method of preorder traversal 
//time complexity is O(n)
//space complexity is O(n)
vector<int>preorder(TreeNode*root)
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
        
        if(root->right!=NULL)
        st.push(root->right);
        
        if(root->right!=NULL)
        st.push(root->left);
        
        ans.push_back(root->val);
    }
    return ans;
}

//inorder traversal
//time complexity is O(n)
//space complexity is O(n) recusive call stack space if consider 
void inorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

//iterative method to inorder traversal 
//time complexity is O(n)
//space complexity is O(n)
vector<int>inorder(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    TreeNode*node=root;
    stack<TreeNode*>st;
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

//postorder traversal 
//time complexity is O(n)
//space complexity is O(n) recusive call stack space if consider 
void postorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}

//iterative method to postorder traversal
//time complexity is O(n)
//space complexity is O(2n)
vector<int>preorder(TreeNode*root)
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
        ans.push_back(st2.top());
        st2.pop();
    }
    return ans;
}

//using one stack find inorder , preorder, ans postorder stack continue(node, number(1, 2,3)) like 
//time complexity is O(n)
//space complexity is O(n)
vector<int>onestackusetraver(TreeNode*root)
{
    if(root==NULL)
    return ;
    
    stack<pair<TreeNode*, int>>st;
    st.push({root, 1});
    vector<int>in;
    vector<int>pre;
    vector<int>post;
    
    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        
        if(it.second==1)
        {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            
            if(it.first->left!=NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if(it.second==2)
        {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            
            if(it.first->right!=NULL)
            {
                st.push({first->right, 1});
            }
        }
        else 
        {
            post.push_back(it.first->val);
        }
    }
}

//maximum depth of binary tree 
//time complexity is O(n)
//space complexity is O(n)
int maximumdepth(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=maximumdepth(root->left);
    int rh=maximumdepth(root->right);
    
    return 1+max(lh, rh);
}

//check for balance binary tree
//time complexity is O(n)
//space complexity is O(n)
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
bool balance(TreeNode*root)
{
    return height(root)!=-1;
}

//diameter of binary tree
//time complexity is O(n)
//space complexity is O(n)
int slove(TreeNode*root, int &maxi)
{
    if(root==NULL)
    return 0;
    
    int lh=slove(root->left, maxi);
    int rh=slove(root->right, maxi);
    
    maxi=max(maxi, lh+rh);
    
    return 1+max(lh, rh);
}
int diameterofBT(TreeNode*root)
{
    int diam=0;
    slove(root, diam);
    return diam;
}

//maximum path sum
//time complexity is O(n)
//space complexity is O(n)
int pathsum(TreeNode*root, int &maxi)
{
    if(root==NULL)
    return 0;
    
    int lh=max(0,pathsum(root->left, maxi));
    int rh=max(0,pathsum(root->right, maxi));
    
    maxi=max(maxi, root->val+lh+rh);
    
    return root->val+max(lh, rh);
}
int maximumpathsum(TreeNode*root)
{
    int sum=INT_MIN;
    pathsum(root, sum);
    return sum;
}

//check two tree is identical/same  or not 
//time complexity is O(n)
//space complexity is O(n)
bool identical(TreeNode*root1, TreeNode*root2)
{
    if(root1==NULL && root2==NULL)
    return true;
    
    if(root1!=NULL && root2==NULL)
    return false;
    
    if(root1==NULL && root2!=NULL)
    return false;
    
    return (root1->val==root2->val) && identical(root1->left, root2->left) && identical(root1->right, root2->right);
}

//check symmetric tree  or not 
//time complexity is O(n)
//space complexity is O(n)
bool identical(TreeNode*root1, TreeNode*root2)
{
    if(root1==NULL && root2==NULL)
    return true;
    
    if(root1!=NULL && root2==NULL)
    return false;
    
    if(root1==NULL && root2!=NULL)
    return false;
    
    return (root1->val==root2->val) && identical(root1->left, root2->right) && identical(root1->right, root2->left);
}
bool symmetric(TreeNode*root)
{
    return identical(root->left, root->right);
}

//maximum width of binary tree (width=maximum number of node in level between any to node)
//time complexity is O(n)
//space complexity is O(n)
int widthofBT(TreeNode*root)
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
            int id=q.front().second-mini;
            TreeNode*node=q.front().first;
            q.pop();
            
            if(i==0)
            first=id;
            if(i==size)
            second=id;
            
            if(node->left!=NULL)
            q.push({node->left, id*2+1})
            
            if(node->right!=NULL)
            q.push({node->right, id*2+2});
        }
        ans=max(ans, second-first+1);
    }
    return ans;
}

//childrean sum property in binary tree 
//time complexity is O(n)
//space complexity is O(n)
void changeTree(TreeNode*root)
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
        root->left->val=root->val;
        
        else if(root->right!=NULL)
        root->right->val=root->val;
    }
    
    changeTree(root->left);
    changeTree(root->right);
    
    int tot=0;
    if(root->left!=NULL)
    tot+=root->left->val;
    
    if(root->right!=NULL)
    tot+=root->right->val;
    
    if(root->left!=NULL || root->right!=NULL)
    root->val=tot;
}

//print all the node at a distance of k in binary tree 
//time complexity is O(n)
//space complexity is O(n)
void makeparent(TreeNode*root, unordered_map<TreeNode*, TreeNode*>&parent, TreeNode*target)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode*current=q.front();
        q.pop();
        
        if(current->left!=NULL)
        {
            parent[current->left]=current;
            q.push(current->left);
        }
        
        if(current->right!=NULL)
        {
            parent[current->right]=current;
            q.push(current->right);
        }
    }
}
vector<int>distance(TreeNode*root, TreeNode*target, int k)
{
    unordered_map<TreeNode*, TreeNode*>parent;
    makeparent(root, parent, target);
    
    int dis=0;
    unordered_map<TreeNode* bool>visited;
    queue<TreeNode*>q;
    q.push(target);
    visited[target]=true;
    
    while(!q.empty())
    {
        int size=q.size();
        
        if(dis==k)
        break;
        
        dis++;
        for(int i=0; i<size; i++)
        {
            TreeNode*current=q.front();
            q.pop();
            
            if(current->left!=NULL && !visited[current->left])
            {
                q.push(current->left);
                visited[current->left]=true;
            }
            
            if(current->right!=NULL && !visited[current->right])
            {
                q.push(current->right);
                visited[current->right]=true;
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

//minimum time taken by to burn the binary tree 
//time complexity is O(n)
//space complexity is O(n)
int findmaxdistance(mpa<TreeNode*, TreeNode*>&mp, TreeNode*target)
{
    queue<TreeNode*>q;
    q.push(root);
    map<TreeNode*, int>vis;
    vis[target]=1;
    int maxi=0;
    
    while(!q.empty())
    {
        int size=q.size();
        int flage=0;
        for(int i=0; i<size; i++)
        {
            auto node=q.front();
            q.pop();
            
            if(node->left!=NULL && !vis[node->left])
            {
                flage=1;
                vis[node->left]=1;
                q.push(node->left);
            }
            
            if(node->right!=NULL && !vis[node->right])
            {
                flage=1;
                vis[node->right]=1;
                q.push(node->right);
            }
            
            if(mp[node] && !vis[mp[node]])
            {
                flage=1;
                vis[mp[node]]=1;
                q.push(mp[node]);
            }
        }
        if(flage)
        maxi++;
    }
    return maxi; 
}
TreeNode*mapparent(TreeNode*root, map<TreeNode*, TreeNode*>&mp, int start)
{
    queue<TreeNode*>q;
    q.push(root);
    TreeNode*ans;
    while(!q.empty())
    {
        TreeNode*node=q.front();
        
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
int timetoburn(TreeNode*root, int start)
{
    map<TreeNode*, TreeNode*>mp;
    TreeNode*target=mapparent(root, mp, start);
    int maxi=findmaxdistance(mp, target);
    return maxi;
}

//boundary order traversal 
//time complexity is O(n)
//space complexity is O(n)



//top view of binary tree 
//time complexity is O(n)
//space complexity is O(n)
vector<int>topview(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    map<int,int>mp;
    queue<pair<TreeNode*, int>>q;
    q.push({root, 0});
    while(!q.empty())
    {
        auto it =q.front();
        q.pop();
        
        TreeNode*node=it.first;
        int line=it.second;
        
        if(mp.find(line)==mp.end())
        mp[line]=root->val;
        
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

//bottom view of binary tree 
//time complexity is O(n)
//space complexity is O(n)
vector<int>bottomview(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    map<int,int>mp;
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

//vertical order traversal 
//time complexity is O(n)logn
//space complexity is O(n)
vector<vector<int>>vertical(TreeNode*root)
{
    map<int, map<int, vector<int>>mp;
    queue<pair<TreeNode*, pair<int,int>>q;
    vector<int>ans;
    
    if(root==NULL)
    return ans;
    
    q.push({root, {0, 0}});
    while(!q.empty())
    {
        auto it =q.front();
        q.pop();
        
        TreeNode*node=q.first;
        int x=q.first.second.first;
        int y=q.first.second.second;
        
        node[x][y].insert(node->val);
        
        if(node->left!=NULL)
        q.push({node->left, {x-1, y+1}});
        
        if(node->right!=NULL)
        q.push({node->right, {x+1, y+1}});
    }
    
    vector<vector<int>>ans;
    for(auto p : node)
    {
        vector<int>result;
        for(auto q : p.second)
        {
            result.insert(result.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(result);
    }
    return ans;
}



//level order traversal
//time complexity is O(n)
//space complexity is O(n)
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
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}

//second version of level order traversal
//time complexity is O(n)
//space complexity is O(n)
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
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


//average of level of binary tree  
//time complexity is O(n)
//space complexity is O(n)
vector<int>average(TreeNode*root)
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
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            sum+=(node->val);
        }
        ans.push_back(sum/size);
    }
    return ans;
}

//level order successor of a node in binary tree 
//time complexity is O(n)
//space complexity is O(n)
int successor(TreeNode*root, int key)
{
    if(root==NULL)
    return 0;
    
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

//zig-zag order traversal 
//time complexity is O(n)
//space complexity is O(n)
vector<vector<int>>zig-zag(TreeNode*root)
{
    vector<vector<int>>ans;
    if(root==NULL)
    return ans;
    
    int lefttoright=true;
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
            
            int index=lefttoright ? i : size-1-i;
            level[index]=node->val;
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
        }
        lefttoright=!=lefttoright;
        ans.push_back(level);
    }
    return ans;
}

//right side view of binary tree 
//time complexity is O(n)
//space complexity is O(n)
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
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            if(i==size-1)
            ans.push_back(node->val);
        }
    }
    return ans;
}

//left side view of binary tree 
//time complexity is O(n)
//space complexity is O(n)
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
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            if(i==0)
            ans.push_back(node->val);
        }
    }
    return ans;
}

//minimum depth of binary tree
//time complexity is O(n)
//space complexity is O(n)
int minimumdepth(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int depth=1;
    queue<TreeNode*>q;
    q.push(root);
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


//deepest leaves sum 
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
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

//find bottom left tree value 
//time complexity is O(n)
//space complexity is O(n)
TreeNode*bottomleft(TreeNode*root)
{
    if(root==NULL)
    return NULL;
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        root=q.front();
        q.pop();
        
        if(root->right!=NULL)
        q.push(root->right);
        
        if(root->left!=NULL)
        q.push(root->left);
    }
    return root->val;
}

//convert sorted array to binary search tree
//time complexity is O(n)
//space complexity is O(n)
TreeNode*makeBST(vector<int>&arr, int start, int end)
{
    if(start>end)
    return NULL;
    
    int mid=(start+end)/2;
    TreeNode*root=new TreeNode(arr[mid]);
    
    root->left=makeBST(arr, start, mid-1);
    root->right=makeBST(arr, mid+1, end);
    
    return root;
}
TreeNode*convertsortedarr(vector<int>&num)
{
    return makeBST(num, 0, num.size()-1);
}

//convert sorted linked list to binary search tree 
//time complexity is O(n)
//space complexity is O(n)
TreeNode*makeBST(vector<int>&arr, int start, int end)
{
    if(start>end)
    return NULL;
    
    int mid=(start+end)/2;
    TreeNode*root=new TreeNode(arr[mid]);
    
    root->left=makeBST(arr, start, mid-1);
    root->right=makeBST(arr, mid+1, end);
    
    return root;
}
TreeNode*convertsortedlist(ListNode*head)
{
    vector<int>num;
    while(head!=NULL)
    {
        num.push_back(head->val);
        head=head->val;
    }
    
    return slove(num, 0, num.size()-1);
}

//second mathod 
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
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

//construct binary tree from preorder and inorder 
//time complexity is O(n)
//space complexity is O(n)
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


//construct binary tree from inorder and postorder 
//time complexity is O(n)
//space complexity is O(n)
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
    
    map<intint>mp;
    for(int i=0; i<inorder.size(); i++)
    {
        mp[inorder[i]]=i;
    }
    
    TreeNode*root=maketree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1, mp);
    return root;
}

//path sum 
bool pathsum(TreeNode*root, int targetsum)
{
    if(root==NULL)
    return true;
    
    if(root->left==NULL && root->right==NULL && targetsum-root->val==0)
    return true;
    
    return pathsum(root->left, targetsum-root->val) || pathsum(root->right, targetsum-root->val);
}

//path sum-II
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

//count complete tree node
int countNodes(TreeNode*root)
{
    if(root==NULL)
    return 0;

    int lh=countNodes(root->left);
    int rh=countNodes(root->right);

    return 1+lh+rh;
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
//merge two binary tree 
TreeNode*mergetwoBT(TreeNode*root1, TreeNode*root2)
{
    if(root1==NULL)
    return root2;
    
    if(root2==NULL)
    return root1;
    
    TreeNode*temp=new TreeNode(root1->val+root2->val);
    
    temp->left=mergetwoBT(root1->left, root2->left);
    temp->right=mergetwoBT(root1->right, root2->right);
    
    return temp;
}


//search in binary search tree recusive solution ---700
TreeNode*searchinBST(TreeNode*root, int key)
{
    if(root==NULL)
    return NULL;
    
    if(root->val==key)
    return root;
    
    if(root->val>key)
    {
        return searchinBST(root->left, key);
    }
    else 
    {
        return searchinBST(root->right, key);
    }
}

//iterative solution 
TreeNode*searchinBST2(TreeNode*root, int key)
{
    if(root==NULL)
    return NULL;
    
    while(true)
    {
        if(root->val==key)
        {
            return root;
        }
        else if(root->val>key)
        {
            root=root->left;
        }
        else 
        {
            root=root->right;
        }
    }
    return NULL;
}

//find the ceil in a binary search tree 
int ceilvalue(TreeNode*root, int key)
{
    int ceil=-1;
    while(root!=NULL)
    {
        if(root->val==key)
        {
            ceil=root->val;
            return ceil;
        }
        
        if(root->val>key)
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

//find floor in binary search tree 
int floorvalue(TreeNode*root, int key)
{
    int floor=-1;
    while(root!=NULL)
    {
        if(root->val==key)
        {
            floor=root->val;
            return floor;
        }
        
        if(root->val>key)
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

//insert into a binary search tree recusive method ----701
TreeNode*insertintoBST(TreeNode*root, int key)
{
    if(root==NULL)
    return new TreeNode(key);
    
    if(root->val>key)
    {
        return insertintoBST(root->left, key);
    }
    else 
    {
        return insertintoBST(root->right, key);
    }
    return root;
}

//iterative method 
TreeNode*insertintoBST(TreeNode*root, int key)
{
    if(root==NULL)
    return new TreeNode(key);
    
    TreeNode*node=root;
    while(node!=NULL)
    {
        if(node->val>key)
        {
            if(node->left!=NULL)
            {
                node=node->left;
            }
            else 
            {
                node->left=new TreeNode(key);
                brea;
            }
        }
        else 
        {
            if(node->right!=NULL)
            {
                node=node->right;
            }
            else 
            {
                node->right=new TreeNode(key);
                break;
            }
        }
    }
    return root;
}

//delete node in binary search tree ---450 
TreeNode*findlastright(TreeNode*root)
{
    if(root==NULL)
    return root;
    
    return findlastright(root->right);
}
TreeNode*helper(TreeNode*root)
{
    if(root->left==NULL)
    return root->right;
    
    if(root->right==NULL)
    return root->left;
    
    TreeNode*rightchild=root->right;
    TreeNode*lastright=findlastright(root->left);
    lastright->right=rightchild;
    
    return root->left;
}
TreeNode*deletenode(TreeNode*root, int key)
{
    if(root==NULL)
    return root;
    
    if(root->val==key)
    return helper(root);
    
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
    return root;
}

//valid binary search tree --- 98 
bool slove(TreeNode*root, int mini, int maxi)
{
    if(root==NULL)
    return true;
    
    if(root->val>=maxi && root->val<=mini)
    return false;
    
    return slove(root->left, mini, root->val) && slove(root->right, root->val, maxi);
}
bool validBT(TreeNode*root)
{
    return slove(root, LOGN_MN, LOGN_MAX);
}

//recover binary search tree means (swaping two node with changing the structure ) --- 99
//kth smallest element in binary search tree  brute force approach  ---230 
void preorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
int kthsmallest(TreeNode*root, int k)
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
int kthsmallest(TreeNode*root, int k)
{
    vector<int>ans;
    inorder(root, ans);
    return ans[k-1];
}


//optimal approach
void slove(TreeNode*root, int count, int &ans, int k)
{
    if(root==NULL)
    return ;
    
    slove(root->left, count, ans, k);
    
    count++;
    if(count==k)
    {
        ans=root->val;
        return ;
    }
    
    slove(root->right, count, ans, k);
}
int kthsmallest(TreeNode*root, int k)
{
    int count=0;
    int ans;
    slove(root, count, ans, k);
    return ans;
}

//find the second minimum node in binary tree 
void preorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
TreeNode*secondminimuminBT(vector<int>&arr)
{
    vector<int>ans;
    preorder(root, ans);
    sort(ans.begin(), ans.end());
    int mini=ans[0];
    
    int sec=-1;
    for(int i=1; i<ans.size(); i++)
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
int sum=0;
TreeNode*convertBTgreater(TreeNode*root)
{
    if(root==NULL)
    return root;
    
    convertBTgreater(root->right);
    
    sum+=root->val;
    root->val=sum;
    
    convertBTgreater(root->left);
}

//trim binary search tree means(given a range when node node value not lie in range than simply delete) --- 669 
TreeNode*trimBST(TreeNode*root, int low int high)
{
    if(root==NULL)
    return NULL;
    
    if(root->val>=low && root->val<=high)
    {
        root->left=trimBST(root->left, low, high);
        root->right=trimBST(root->right, low, high);
        return root;
    }
    else if(root->val<=low)
    {
        return trimBST(root->right, low, high);
    }
    else if(root->val>=high)
    {
        return trimBST(root->left, low, high);
    }
    return root;
}

//count good node in binary tree (good means root to till node node value will be maximum than this node will be good node) --1448
void slove(TreeNode*root, int &count, int maxi)
{
    if(root==NULL)
    return ;
    
    if(root->val>=maxi)
    {
        count++;
        maxi=root->val;
    }
    
    slove(root->left, count, maxi);
    slove(root->right, count, maxi);
}
int countgoodnode(TreeNode*root)
{
    int count=0;
    slove(root, count, root->val);
    return count;
}

//smallest subtree with all the depest node ---865 
//lowest common ancestor of deepest leaves(both have same solution)  ----1123 
int height(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=height(root->left);
    int rh=height(root->right);
    
    return 1+max(lh, rh);
}
TreeNode*lowestcommonanc(TreeNode*root)
{
    int lefth=height(root->left);
    int righth=height(root->right);
    
    if(lefth==righth)
    return root;
    
    if(lefth>righth)
    {
        return lowestcommonanc(root->left);
    }
    else 
    {
        return lowestcommonanc(root->right);
    }
}

//increasing order search tree brute force approach  ------- 897 
void preorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
TreeNode*increasing(TreeNode*root)
{
    vector<int>ans;
    preorder(root ans);
    sort(ans.begin(), ans.end());
    
    TreeNode*root=new dummy(0);
    TreeNode*tail=dummy;
    
    for(auto it : ans)
    {
        tail->right=new TreeNode(it);
        tail=tail->right;
    }
    
    return dummy->right;
}

//optimal approach
void slove(TreeNode*root, TreeNode*&dummy)
{
    if(root==NULL)
    return NULL;
    
    slove(root->left, dummy);
    
    dummy->right=root->val;
    dummy=dummy->right;
    
    slove(root->right, dummy);
}
TreeNode*increasing(TreeNode*root)
{
    if(root==NULL)
    return NULL;
    
    TreeNode*dummy=new TreeNode(0);
    slove(root, dummy);
    
    return dummy->right;
}

//lowest common ancestor of binary tree 
//time complexity is O(n)
//space complexity is O(n)
TreeNode*lowestcommonanc(TreeNode*root, TreeNode*p, TreeNode*q)
{
    if(root==NULL || root==p || root==q)
    return root;
    
    int lh=lowestcommonanc(root->left, p q);
    int rh=lowestcommonanc(root->right, p, q);
    
    if(lh==NULL)
    {
        return rh;
    }
    else if(rh==NULL)
    {
        return lh;
    }
    else 
    {
        return root;
    }
}

//lowest common ancestor of binary search tree
int lowestcommonanc(TreeNode*root, TreeNode*p, TreeNode*q)
{
    if(root==NULL)
    return NULL;
    
    int curr=root->val;
    if(curr<p->val && curr<q->val)
    {
        return lowestcommonanc(root->right, p, q);
    }else 
    {
        return lowestcommonanc(root->left, p, q);
    }
    return root;
}









