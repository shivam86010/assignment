

//contain duplicate (this means if any element in array are duplicate than return true other wise false) brute force approach(n^2) 
//better approach (sorting)
//optimal approach (hashmap)
//contain duplicate --II (given k find the arr[i]==arr[j] and i-j<=k )
//contain duplicate-- III (given k and t find two element abs(arr[j]-arr[j]<=t && abs(i-j)<=k))
// concatenation of array 
//second method
//count pairs whose sum is less than target 
//optimal approach 
//max number of K-sum pairs bruteforce approach (in this problem deleting pair )
//better approach 
//optimal approach
//count number of pairs with absolute difference K
//optimal approach 
//count good meals (adding two element in array than equal to power of two)
//number of pairs of strings with concatenation equal to target
//optimal approach
//subarray product less than k 
//merge interval 
//insert interval 
//non overlaping interval (count how mant interval are delete to make non overlap)
//largest number  
//minimum moves to equal array element
//minimum moves to equal array elements-2
//second method
//minimum operations to reduce X to zero
//brick wall (find the minimum cross)
//number of subarrays with bounded maximum
//max chunks to make sorted
//max chunks to make sorted II
//find k closest element 

//---------------------------------------------------------------------------------------------------------------

//guess number 
//Koko Eating Bananas
//Minimum days to make M bouquets 
//Find the Smallest Divisor Given a Threshold
//Capacity to Ship Packages within D Days
//book allocation problem 
//Aggressive cow problem 
//painter partition problem
//split array largest sum 

//-----------------------------------------------------------------------------------------------------------------------------


//remove duplicate from unsorted linked list 
//merge k linked list 
// Nth node from end of linked list 
//swap node kth from starting and kth from end in linked list 
//2-method 
//sort linked list 
//rotate linked list 
//reorder linked list 
//insertion sort in linked list 



//-------------------------------------------------------------------------------------------- 


//Minimum Number of Swaps to Make the String Balanced  ]][[[]]][[
//largest rectangle area in histogram 
//stock span problem 
//Evaluate Reverse Polish Notation
//generate parentheses (given n)
//longest valid parentheses  )()())--->4
//2 method
//remove invalid parentheses  ()())()--->(())(), ()()()
//remove k digit 
//time complexity is O(n^2)
//space complexity is O(n) 
//this is spacial case if k is not zero and element in stack than simply largest element will be delete 1,4,3,2,7,8 k=4
//Minimum Remove to Make Valid Parentheses   lee(t(co)d)e)
//2-method 
//score of Parentheses  ()=1  (a)=2*a
//minimum add to make Parentheses valid  ((( ==3 
//2-method 
//3-method 

//------------------------------------------------------- 


//two out of three (this means given three array find the common element in array atleast in  two array common ) 
//daily temperatures
// maximum product of word lengths
//maximum erasure value (erasure one subarray with maximum sum)
//count nice pair in array nice pair means(arr[i]+rev(arr[j])==arr[j]+rev(arr[i]))
//minimum operation to make the array increasing 
//minimum increment to make array unique 
//non decreasing array (only one element will be change to make array is non decreasing )
//wave sort 
//wiggle sort 
//maximum product of three number in array (in array contain both positive and negative number) brute force approach 
//optimal approach 
//increasing triplate (arr[i]<arr[j]<arr[k] than return true other wise false) brute force approach
//optimal approach 
//integer break (break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers. )
//3 sum closest (in this problen given both positive and negative element) brute froce approach 
//optimal approach 



//---------------------------------------

//iterative method of preorder traversal 
//iterative method to inorder traversal 
//iterative method to postorder traversal 
//path sum 
//path sum-II
//binary tree path 
//sum root to leaf number 
//count complete tree node 
//invert binary tree 
//sum of left leaf node 
//merge two binary tree 


//search in binary search tree recusive solution ---700
//iterative solution 
//find the ceil in a binary search tree 
//find floor in binary search tree 
//insert into a binary search tree recusive method ----701
//iterative method 
//delete node in binary search tree ---450 
//valid binary search tree --- 98 
//recover binary search tree means (swaping two node with changing the structure ) --- 99
//kth smallest element in binary search tree  brute force approach  ---230 
//better approach 
//optimal approach 
//find the second minimum node in binary tree 
//convert binary search tree to greater tree --538 
//trim binary search tree means(given a range when node node value not lie in range than simply delete) --- 669 
//count good node in binary tree (good means root to till node node value will be maximum than this node will be good node) --1448
//smallest subtree with all the depest node ---865 
//increasing order search tree brute force approach  ------- 897 
//optimal approach 
//lowest common ancestor of binary search tree 


//---------------------------------------------------------- 
//rotate matrix brute froce approach 
//optmal approach 
//determine matrix can be obtained by rotation (this means given two matrix mat and target chack rotate mat if obtain target than
//return true other wise return false)
//spiral traversal of a matrix 
//second version of above 
//digonal traversal of a matrix 
//second method 
//lucky number in matrix (lucky means minimum in row maximum in column )
//matrix digonal sum 
//kth smallest element in sorted matrix 
//flipping an image (given matrix 0 and 1 convert zero to one and one to zero)




//---------------------------------------

//preorder traversal 
//time complexity is O(n)
//space complexity is O(n)  
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
    while(!q.empty())
    {
        root=st.top();
        st.pop();
        
        ans.push_back(root->val);
        
        if(root->right!=NULL)
        st.push(root->right);
        
        if(root->left!=NULL)
        st.push(root->left);
        
        ans.push_back(node->val);
    }
    return ans;
}

//inorder traversal 
//time complexity is O(n)
//space complexity is O(n)  
void  inorder(TreeNode*root, vector<int>&ans)
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
    return ans
}

//postorder traversal 
//time complexity is O(n)
//space complexity is O(n)  
void postorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}

//iterative method to postorder traversal
vector<int>postorder(TreeNode*root)
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
int height(TreeNode*root, int &maxi)
{
    if(root==NULL)
    return 0;
    
    int lh=height(root->left, maxi);
    int rh=height(root->right, maxi);
    
    maxi=max(maxi, lh+rh);
    
    return 1+max(lh, rh);
}
int diameterofBT(TreeNode*root)
{
    int diameter=0;
    height(root, diameter);
    return diameter;
}

//maximum path sum 
//time complexity is O(n)
//space complexity is O(n)  
int pathsum(TreeNode*root, int &maxi)
{
    if(root==NULL)
    return 0;
    
    int lh=max(0, pathsum(root->left, maxi));
    int rh=max(0 pathsum(root->right, maxi));
    
    maxi=max(maxi, root->val+lh+rh);
    
    return root->val+max(lh, rh);
}
int maximumpathsum(TreeNode*root)
{
    int maxi=INT_MIN;
    pathsum(root, maxi);
    return maxi;
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
bool issame(TreeNode*root1, TreeNode*root2)
{
    if(root1==NULL && root2==NULL)
    return true;
    
    if(root1!=NULL && root2==NULL)
    return false;
    
    if(root1==NULL && root2!=NULL)
    return false;
    
    return (root1->val==root2->val) && issame(root1->left, root2->left) && issame(root1->right, root2->right);
}
bool symmetric(TreeNode*root)
{
    return issame(root->left, root->right);
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
        for(int i=0; i<n; i++)
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
        for(int i=0; i<n; i++)
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
vector<int>averagesum(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        
        for(int i=0; i<n; i++)
        {
            TreeNode*node=q.front();
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
//time complexity is O(n)
//space complexity is O(n)  
int successor(TreeNode*root, int key)
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
        
        if(root->val==key)
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
    
    bool lefttoright=true;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        
        vector<int>level;
        for(int i=0; i<n; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            int index=lefttoright ? i : size-i-1;
            
            leve[index]=node->val;
            
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

//right side view of binary tree
//time complexity is O(n)
//space complexity is O(n)  
vector<int>rightsidview(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        
        for(int i=0; i<n; i++)
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
        
        for(int i=0; i<n; i++)
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
        
        for(int i=0; i<n; i++)
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
        for(int i=0; i<n; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            sum+=root->val;
        }
    }
    return sum;
}

//find largest value in each row
//time complexity is O(n)
//space complexity is O(n)  
vector<int>largestinrow(TreeNode*root)
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
        for(int i=0; i<n; i++)
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
TreeNode*bottomleftleaf(TreeNode*root)
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
TreeNode*makeBST(vector<int>arr, int start, int end)
{
    if(start>end)
    return ;
    
    int mid=(start+end)/2;
    TreeNode*root=ew TreeNode(arr[mid]);
    
    root->left=makeBST(arr, start, mid-1);
    root->right=makeBST(arr, mid+1, end);
    
    return root;
}
TreeNode*convertsortedarrtoBST(vector<int>arr)
{
    return makeBST(arr, 0, arr.size());
}

//convert sorted linked list to binary search tree
//time complexity is O(n)
//space complexity is O(n)  
TreeNode*makeBST(vector<int>arr, int start, int end)
{
    if(start>end)
    return ;
    
    int mid=(start+end)/2;
    TreeNode*root=ew TreeNode(arr[mid]);
    
    root->left=makeBST(arr, start, mid-1);
    root->right=makeBST(arr, mid+1, end);
    
    return root;
}
TreeNode*convertsortedlisttoBST(ListNode*head)
{
    vector<int>ans;
    while(head!=NULL)
    {
        ans.push_back(head->val);
        head=head->next;
    }
    
    return makeBST(ans, 0, ans,size()-1);
}

//second mathod 
//time complexity is O(n)
//space complexity is O(n)  
TreeNode*convertsortedlisttoBST(ListNode*head)
{
    if(head==NULL)
    return NULL;
    
    if(head->next==NULL)
    return new TreeNode(head->val);
    
    auto slow=head;
    auto fast=head;
    auto temp;
    while(fast!=NULL && fast->next!=NULL)
    {
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    
    temp->next=NULL;
    TreeNode*root=new TreeNode(slow->val);
    
    root->left=convertsortedlisttoBST(head);
    root->right=convertsortedlisttoBST(slow->next);
    
    return root;
}

//make maximum binary tree
//time complexity is O(n)
//space complexity is O(n)  
TreeNode*makeBT(vector<int>ans, int start, int end)
{
    if(start>end)
    return ;
    
    int maxi=-1;
    int maxiindex;
    for(int i=start; i<=end; i++)
    {
        if(arr[i]>maxi)
        {
            maxi=arr[i];
            maxiindex=i;
        }
    }
    
    TreeNode*root=new TreeNode(maxi);
    
    root->left=makemaxiBT(ans, start, maxiindex-1);
    root->right=makemaxiBT(ans, maxiindex+1, end);
    
    return root;
}
TreeNode*maximumBT(vector<int>ans)
{
    return makeBT(ans, 0, ans,size()-1);
}

//construct binary tree from preorder and inorder 
//time complexity is O(n)
//space complexity is O(n)  
TreeNode*makeBT(vector<int>preorder, vector<int>inorder, int ps, int pe, int is, int ie, unordered_map<intint>mp)
{
    if(ps>pe || is>ie)
    return ;
    
    TreeNode*root=new TreeNode(preorder[ps]);
    int pos=mp[root];
    int left=pos-is;
    
    root->left=makeBT(preorder, inorder, ps+1, ps+left, is, pos-1, mp);
    root->right=makeBT(preorder, inorder, ps+left+1 pe, pos+1, ie, mp);
    
    return root;
}
TreeNode*constructBT(vector<int>preorder, vector<int>inorder)
{
    if(preorder.size()!=inorder.size())
    return NULL;
    
    unordered_map<int,int>mp;
    for(int i=0; i<inorder.size(); i++)
    {
        mp[inorder[i]]=i;
    }
    
    return makeBT(preorder, inorder, 0, preorder.size()-1, 0,  inorder.size()-1, mp);
}

//construct binary tree from inorder and postorder 
//time complexity is O(n)
//space complexity is O(n)  
TreeNode*makeBT(vector<int>postorder, vector<int>inorder, int ps, int pe, int is, int ie unordered_map<int,int>mp)
{
    if(ps>pe || is>ie)
    return ;
    
    TreeNode*root=TreeNode(postorder[pe]);
    int pos=mp[root];
    int left=pos-is;
    
    root->left=makeBT(postorder, inorder, ps, ps+left-1, ie, pos-1, mp);
    root->right=makeBT(postorder, inorder, ps+left, ppe-1, pos-1, ie, mp);
    
    return root;
}
TreeNode*constructBt(vector<int>postorder, vector<int>inorder)
{
    if(postorder.size()!=inorder.size())
    return NULL;
    
    unordered_map<int, int>mp;
    for(int i=0; i<inorder.size(); i++)
    {
        mp[inorder[i]]=i;
    }
    
    return makeBT(postorder, inorder, 0, postorder.size()-1, 0 inorder.size()-1, mp);
}

//path sum
//time complexity is O(n)
//space complexity is O(n)  
bool pathsum(TreeNode*root, int targetsum)
{
    if(root==NULL)
    return true;
    
    if(root->left==NULL && root->right==NULL && targetsum-root->val==0)
    return true;
    
    return pathsum(root->left, targetsum-root->val) || pathsum(root->right, targetsum-root->val);
}

//boundary order traversal
void lefttravers(TreeNode*root, vector<int>&ans)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
    return ;
    
    ans.push_back(root->val);
    if(root->left!=NULL)
    {
        lefttravers(root->left, ans);
    }
    else 
    {
        lefttravers(root->right, ans);
    }
}
void leaftravers(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->val);
        return ;
    }
    leaftravers(root->left, ans);
    leaftravers(root->right, ans);
}
void traversright(TreeNode*root, vector<int>&ans)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
    return ;
    
    if(root->right!=NULL)
    {
        traversright(root->right, ans);
    }
    else 
    {
        traversright(root->left, ans);
    }
    
    ans.push_back(root->val);
}
vector<int>boundarytraverse(TreeNode*root)
{
    if(root==NULL)
    return ans;
    
    ans.push_back(root->val);
    lefttravers(root->left, ans);
    leaftravers(root->left, ans);
    leaftravers(root->right, ans);
    traversright(root->right, ans);
    return ans;
}

//vertical order traversal 
vector<int>vertical(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    map<int, map<int,vector<int>>mp;
    queue<pair<TreeNode*, pair<int,int>>q;
    q.push(make_pair(root, make_pair(0, 0)));
    while(!q.empty())
    {
        pair<TreeNode*, pair<int,int>>node=q.front();
        q.pop();
        
        TreeNode*node=temp.first;
        int line=temp.second.first;
        int level=temp.second.second;
        
        mp[line][level].push_back(node->val);
        
        if(node->left!=NULL)
        q.push(make_pair(node->left, make_pair(line-1, level+1)));
        
        if(node->right!=NULL)
        q.push(make_pair(node->right, make_pair(line+1, level+1)));
    }
    
    for(auto it : mp)
    {
        for(auto i : it.second)
        {
            for(auto j : i.second)
            {
                ans.push_back(j);
            }
        }
    }
    return ans;
}

//top view of binary tree 
vector<int>topview(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    map<int,int>mp;
    queue<pair<TreeNode*, int>>q;
    q.push(make_pair(root, 0));
    while(!q.empty())
    {
        pair<TreeNode*, int>temp=q.front();
        q.pop();
        
        TreeNode*node=temp.first;
        int line=temp.second;
        
        if(mp.find(line)==mp.end())
        mp[line]=node->val;
        
        if(node->left!=NULL)
        q.push(make_pair(node->left, line-1));
        
        if(node->right!=NULL)
        q.push(make_pair(node->right, line+1));
    }
    
    for(auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

//bottom view of binary tree 
vector<int>bottomview(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    map<int,int>mp;
    queue<pair<TreeNode*, int>>q;
    q.push(make_pair(root, 0));
    while(!q.empty())
    {
        pair<TreeNode*, int>temp=q.front();
        q.pop();
        
        TreeNode*node=temp.first;
        int line=temp.second;
        
        mp[line]=node->val;
        
        if(node->left!=NULL)
        q.push(make_pair(node->left, line-1));
        
        if(node->right!=NULL)
        q.push(make_pair(node->right, line+1));
    }
    
    for(auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

//path sum-II
vector<vector<int>>ans;
vector<int>path;
void slove(TreeNode*root, int targetsum, int sum)
{
    if(root==NULL)
    return ;
    
    path.push_back(root->val);
    sum+=root->val;
    
    if(sum==targetsum && (root->left==NULL && root->right==NULL))
    {
        ans.push_back(path);
    }
    
    slove(root->left, targetsum, sum);
    slove(root->right, targetsum, sum);
    path.pop_back();
}
vector<vector<int>pathsum2(TreeNode*root, int targetsum)
{
    int sum=0;
    slove(root, targetsum sum);
    return ans;
}


//binary tree path 
//sum root to leaf number (node 1->2->3==123 and so on )
void slove(TreeNode*root, int sum, int &ans)
{
    if(root==NULL)
    return 0;
    
    sum+=root->val;
    if(root->left==NULL && root->right==NULL)
    {
        ans=ans*10+sum;
        return ;
    }
    
    slove(root->left, sum, ans);
    slove(root->right, sum, ans);
    
}
int sumtoroot(TreeNode*root)
{
    int ans=0;
    int sum=0;
    slove(root, sum, ans);
    return ans;
}

//count complete tree node 
int countcomplete(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=countcomplete(root->left);
    int rh=countcomplete(root->right);
    
    return 1+lh+rh;
}

//invert binary tree
TreeNode*invertBT(TreeNode*root)
{
    if(root==NULL)
    return NULL;
    
    invertBT(root->left);
    invertBT(root->right);
    
    swap(root->left, root->right);
    return root;
}

//sum of left leaf node 
//merge two binary tree 


//search in binary search tree recusive solution ---700
bool searchBTS(TreeNode*root, int target)
{
    if(root==NULL)
    return true;
    
    while(true)
    {
        if(root->val==target)
        {
            return root;
        }
        else if(root->val>target)
        {
            root=root->left;
        }
        else 
        {
            root=root->right;
        }
    }
    return false;
}

//iterative solution 
bool searchBTS(TreeNode*root, int target)
{
    if(root==NULL)
    return true;
    
    if(root->val>target)
    {
        root->left=searchBTS(root->left, target);
        return root;
    }
    else 
    {
        root->right=searchBTS(root->right target);
        return root;
    }
    return false;
}

//find the ceil in a binary search tree 
//find floor in binary search tree 
//insert into a binary search tree recusive method ----701
//iterative method 
//delete node in binary search tree ---450 
//valid binary search tree --- 98 
int slove(TreeNode*root, long min, long maxi)
{
    if(root==NULL)
    return true;
    
    if(root->val>=maxi && root->val<=mini)
    return false;
    
    return slove(root->left, mini, root->val) || slove(root->right, root->val, maxi);
}
bool validBST(TreeNode*root)
{
    return slove(root, LONG_MAX, LONG_MIN);
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
int kthsmallest2(TreeNode*root, int k)
{
    vector<int>ans;
    inorder(root, ans);
    return ans[k-1];
}

//optimal approach
void inorder(TreeNode*root, int &ans, int count, int k)
{
    if(root==NULL)
    return ;
    
    inorder(root->left, ans, count, k);
    count++;
    if(count==k)
    {
        ans=root->val;
        return ans;
    }
    inorder(root->right ans, count, k);
}
int kthsmallest3(TreeNode*root, int k)
{
    int ans;
    int count=0;
    inorder(root ans, count, k);
    return ans;
}

//find the second minimum node in binary tree 
//convert binary search tree to greater tree --538 
//trim binary search tree means(given a range when node node value not lie in range than simply delete) --- 669 
//count good node in binary tree (good means root to till node node value will be maximum than this node will be good node) --1448
//smallest subtree with all the depest node ---865 
//increasing order search tree brute force approach  ------- 897 
//optimal approach 
//lowest common ancestor of binary search tree 



void helper(TreeNode* root,vector<string>& answer,string curr){
        if(!root)return;
        if(root->left||root->right)curr+=(to_string(root->val)+"->");
        else{
            curr+=(to_string(root->val));
            answer.push_back(curr);
        }
        helper(root->left,answer,curr);
        helper(root->right,answer,curr);  
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        string curr="";
        helper(root,answer,curr);
        return answer;
