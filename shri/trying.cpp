        
        
///////////////////////////////////// 
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head == NULL || left == right){
            return head;
        }
        ListNode* prev, *tail = NULL, *temp = NULL;
        ListNode dummy(NULL);
        prev = &dummy;
        dummy.next = head;
        for(int i=0; i < left-1; i++){
            prev = prev->next;
        }
        tail = prev->next;
        for(int i=0; i< right - left;i++){
            temp = prev->next;
            prev->next = tail->next;
            tail->next = tail->next->next;
            prev->next->next = temp; 
        }
        
        return dummy.next;     
        
    ////////////////
//Maximum Twin Sum of a Linked List | LeetCode 2130
int pairSum(ListNode* head) {
        
        ListNode* fast=head->next;
        ListNode* slow=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* newhead=slow->next;
        slow->next=NULL;
        
        newhead=reverseList(newhead);
        
        int ans=0;
        
        while(head && newhead)
        {
            ans=max(ans,head->val+newhead->val);
            
            head=head->next;
            newhead=newhead->next;
        }
        
        return ans;
    }    
        
        
//
ListNode* deleteDuplicates(ListNode* head) {
       ListNode *dummy=new ListNode(0,head);
       ListNode *prev=dummy;
        
        while(head!=NULL){
       
            if(head->next!=NULL && head->val==head->next->val){

                while(head->next!=NULL && head->val==head->next->val){
                    head=head->next;
                }
                prev->next=head->next;
            
            } else {
                prev=prev->next;
            }
                       
            head=head->next;
        }q
        
        return dummy->next;
    }
/////////////////////// 
ListNode* deleteMiddle(ListNode* head) {
        if(head->next==0)
        return 0;
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*pre=0;
        while(fast!=0 && fast->next!=0)
        {
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*temp=pre->next;
        pre->next=pre->next->next;
        delete(temp);
        return head;
    }
};
        
///////////////////////////////////////////  203 
    ListNode* removeElements(ListNode* head, int val) {
        if(head==0)
            return 0;
        head->next=removeElements(head->next, val);
        return head->val==val?head->next :head;
    }

//////////////////////////// 
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val){
            head = head->next;
        }
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL){
            if(temp->next->val == val){
                temp->next = temp->next->next;
                continue;
            }
            temp = temp->next;
        }
        return head;
    }
///////////////// 
    ListNode* removeElements(ListNode* head, int val) {

        while (head != NULL && head -> val == val )
        {
            head = head -> next ; 
        }
        
        if(head==NULL) return head;
        
        ListNode *curr = head ;
        ListNode *prev = NULL ;
        
        while(curr!=NULL)
        {
            if(curr->val == val)
            {
                prev->next = curr->next;
            }
            else
            {
                prev = curr;
            }
            curr = curr->next;
        }
        return head ;
////////////////////////////////////////////////// 
vector<int> nextLargerNodes(ListNode* head) {
         ListNode *temp = head;
        vector<int> v;
        while(head)
        {
            int curr_val = head -> val;
            temp = head;
            while(temp)
            {
                if(temp -> val > curr_val)
                {
                    v.push_back(temp -> val);
                    break;
                }
                temp = temp -> next;
            }
            if(temp == NULL)
                v.push_back(0);
            head = head -> next;
        }
        return v;  
    }
};
//=============================================================================== 
#include<bits/stdc++.h>
using namespace std;
int trapingwater(int arr[], int n)
{
    
    
    int watertraped=0;
    for(int i=0; i<n; i++)
    {
        int j=i;
        int leftmaxi=0;
        int rightmaxi=0;
        if(j>=0)
        {
            leftmaxi = max(leftmaxi, arr[j]);
            j--;
        }
        j=i;
        while(j<n)
        {
            rightmaxi =max(rightmaxi, arr[j]);
            j++;
        }
        watertraped +=min(leftmaxi, rightmaxi)-arr[i];
    }
    return watertraped;
}
/*int trap(int arr[], int n) 
{

  int waterTrapped = 0;
  for (int i = 0; i < n; i++) 
  {
    int j = i;
    int leftMax = 0, rightMax = 0;
    while (j >= 0) 
    {
      leftMax = max(leftMax, arr[j]);
      j--;
    }
    j = i;
    while (j < n) 
    {
      rightMax = max(rightMax, arr[j]);
      j++;
    }
    waterTrapped += min(leftMax, rightMax) - arr[i];
  }
  return waterTrapped;
}*/

int trapingwater2(int arr[], int n)
{
    int prefix[n];
    int suffix[n];
    prefix[0]=arr[0];
    for(int i=1; i<n; i++)
    {
        prefix[i]=max(prefix[i-1], arr[i]);
    }
    suffix[n-1]=arr[n-1];
    for(int i=n-2; i>=0; i--)
    {
        suffix[i]=max(suffix[i+1], arr[i]);
    }
    int waterTrapped=0;
    for(int i=0; i<n; i++)
    {
        waterTrapped+=min(prefix[i], suffix[i])-arr[i];
    }
    return waterTrapped;
}

int trapingwater3(int arr[], int n)
{
    int leftMax=0;
    int rightMax=0;
    int start=0;
    int end=n-1;
    int waterTrapped=0;
    while(start<=end)
    {
        if(arr[start]<=arr[end])
        {
            if(leftMax>=arr[start])
            {
                leftMax=arr[i];
            }
            else 
            {
                waterTrapped+=leftMax-arr[start];
            }
            start++;
        }
        else 
        {
            if(rightMax>=arr[end])
            {
                rightMax[end];
            }
            else 
            {
                waterTrapped+=rightMax-arr[end];
            }
            end--;
        }
    }
    return waterTrapped;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<trapingwater(arr, n)<<endl;
}




//decode string 
    string decodeString(string s) {
        stack<string>str;
        stack<int>count;
        string ans="";
        int num=0;
        for (int i=0;i<s.size();i++){
           if (s[i]>='0' && s[i]<='9'){ 
               num=10*num+s[i]-'0';
           }
           else if (s[i]=='[') {//reset
                str.push(ans);
                ans="";
                count.push(num);
                num=0;
           }
           else if(s[i]==']'){ //add the num times to the ans
               string temp=ans;
               ans=str.top();
               str.pop();
               int times=count.top();
               count.pop();
               while (times--){
                   ans+=temp;
               }
           }
           else { // for char 
               ans+=s[i];
           }

        }
        return ans;
    }


     vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>nge(n, 0); 
        stack<int>st{};
        
        for(int i = n-1; i>=0; --i){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();
				
            if(!st.empty())
                nge[i] = st.top()-i; 
            
            st.push(i);
        }
        
        return nge;
    }   
        
        


//Number of Subarrays with Bounded Maximum
//Brick Wall
//Max Chunks To Make Sorted
//Max Chunks To Make Sorted II
int sum1 = 0, sum2 = 0, ans = 0;
        vector<int> t = arr;
        sort(t.begin(), t.end());
        for(int i = 0; i < arr.size(); i++) {
            sum1 += t[i];
            sum2 += arr[i];
            if(sum1 == sum2) ans++;
        }
	return ans;




Balanced Binary Tree https://leetcode.com/problems/balanced-binary-tree/

O(N^2)

class Solution {
    public boolean isBalanced(TreeNode root) {
        if(root == null)
            return true;
        int lh = height(root.left);
        int rh = height(root.right);
        return Math.abs(lh - rh) <= 1 && isBalanced(root.left) && isBalanced(root.right);
    }
    
    private int height(TreeNode node) {
        if(node == null)
            return 0;
        return Math.max(height(node.left), height(node.right)) + 1;
    }
}


//leetcode 719 binary search question
//1201 above method 1283


//https://leetcode.com/discuss/study-guide/1688903/Solved-all-two-pointers-problems-in-100-days 
https://leetcode.com/problems/frequency-of-the-most-frequent-element/solutions/1175088/C++-Maximum-Sliding-Window-Cheatsheet-Template/






#include<bits/stdc++.h>
using namespace std;

//preorder traversal 
//time complexity is O(n)
//space complexity is O(n) 
void preorder(Node*root)
{
    if(root==NULL)
    return ;
    
    print(root->val);
    preorder(root->left);
    preorder(root->right);
}

//iterative method of preorder traversal 
//time complexity is O(n)
//space complexity is O(n) 
vector<int>preorder(Node*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    stack<Node*>st;
    st.push(root);
    while(!st.empty())
    {
        root=st.top();
        st.pop();
        
        ans.push_back(root->val);
        if(root->left!=NULL)
        st.push(root->left);
        
        if(root->right!=NULL)
        st.push(root->right);
    }
    return ans;
}

//inorder traversal 
//time complexity is O(n)
//space complexity is O(n) 
void inorder(Node*root)
{
    if(root==NULL)
    return ;
    
    inorder(root->left);
    print(root->val);
    inorder(root->right);
}

//iterative method to inorder traversal 
//time complexity is O(n)
//space complexity is O(n) 
vector<int>inorder(Node*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    stack<Node*>st;
    Node*node=root;
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
            ans.push_back(node);
            node=node->right;
        }
    }
    return ans;
}

//postorder traversal 
//time complexity is O(n)
//space complexity is O(n) 
void postorder(Node*root)
{
    if(root==NULL)
    return ;
    
    postorder(root->left);
    postorder(root->right);
    print(root->val);
}

//iterative method to postorder traversal 
//time complexity is O(n)
//space complexity is O(n) 
vector<int>postorder(Node*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    stack<Node*>st1;
    stack<Node*>s2;
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

//maximum depth of binary tree 
//time complexity is O(n)
//space complexity is O(n) 
int maxidepth(Node*root)
{
    if(root==NULL)
    return ;
    
    int lh=maxidepth(root->left);
    int rh=maxidepth(root->right);
    
    return 1+max(lh, rh);
}

//check for balance binary tree 
//time complexity is O(n)
//space complexity is O(n) 
int dfsheight(Node*root)
{
    if(root==NULL)
    return 0;
    
    int lefth=dfsheight(root->left);
    if(lefth==-1)
    return -1;
    
    int righth=dfsheight(root->right);
    if(righth==-1)
    return -1;
    
    if(abs(lefth-righth)>1)
    return -1;
    
    return 1+max(lefth, righth);
}
bool isbalance(Node*root)
{
    return dfsheight(root)!=-1;
}

//diameter of binary tree 
//time complexity is O(n)
//space complexity is O(n) 
int height(Node*root, int maxi)
{
    if(root==NULL)
    return 0;
    
    int lh=height(root->left, maxi);
    int rh=height(root->right, maxi);
    maxi=max(maxi, lh+rh);
    
    return 1+max(lh, rh);
}
int diameter(Node*root)
{
    int maxi=-1;
    height(root, maxi);
    return maxi;
}

//maximum path sum 
//time complexity is O(n)
//space complexity is O(n) 
int maxpath(Node*root, int &maxi)
{
    if(root==NULL)
    return 0;
    
    int lh=max(0, maxpath(root->left), maxi);
    int rh=max(0, maxpath(root->right), maxi);
    
    maxi=max(maxi, lh+rh+root->val);
    return root->val+max(lh, rh);
}
int maxipathsum(Node*root)
{
    int maxi=INT_MIN;
    maxpath(root, maxi);
    return maxi;
}


//check two tree is identical or not 
//time complexity is O(n)
//space complexity is O(n) 
bool isidentical(Node*root1, Node*root2)
{
    if(root1==NULL && root2==NULL)
    return true;
    
    if(root1==NULL && root2!=NULL)
    return false;
    
    if(root2==NULL && root1!=NULL)
    return false;
    
    return (root1->val==root2->val && isidentical(root1->left, root2->left) && isidentical(root1->right, root2->right));
}



















#include<bits/stdc++.h>
using namespace std;

//preorder traversal 
//time complexity O(n)
//space complexity is O(n)
void preorder(TreeNode*root)
{
    if(root==NULL)
    return ;
    
    print(root->val);
    preorder(root->left);
    preorder(root->right);
}

//iterative method of preorder traversal 
//time complexity O(n)
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
        TreeNode*node=st.top();
        st.pop();
        
        ans.push_back(node);
        
        if(node->left!=NULL)
        st.push(node->left);
        
        if(node->right!=NULL)
        st.push(node->right);
    }
    return ans;
}

//inorder traversal 
//time complexity O(n)
//space complexity is O(n)
void inorder(TreeNode*root)
{
    if(root==NULL)
    return ;
    
    inorder(root->left);
    print(root->val);
    inorder(root->right);
}

//iterative method to inorder traversal 
//time complexity O(n)
//space complexity is O(n)
vector<int>inorder(TreeNode*root)
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
            
            ans.push_back(node);
            node=node->right;
        }
    }
    return ans;
}

//postorder traversal 
//time complexity O(n)
//space complexity is O(n)
void postorder(TreeNode*root)
{
    if(root==NULL)
    return ;
    
    postorder(root->left);
    postorder(root->right);
    print(root->val);
}

//iterative method to postorder traversal 
//time complexity O(n)
//space complexity is O(n)
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
        st.push(root->right);
    }
    
    while(!st2.empty())
    {
        ans.push_back(st2.top());
        st2.pop();
    }
    return ans;
}

//maximum depth of binary tree 
//time complexity O(n)
//space complexity is O(n)
int maxidepth(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=maxidepth(root->left);
    int rh=maxidepth(root->right);
    
    return 1+max(lh, rh);
}

//check for balance binary tree 
//time complexity O(n)
//space complexity is O(n)
int dfsheight(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=dfsheight(root->left);
    if(lh==-1)
    return -1;
    
    int rh=dfsheight(root->right);
    if(rh==-1)
    return -1;
    
    if(abs(lh-rh)>1)
    return -1;
    
    return 1+max(lh, rh);
}
bool chckbalance(TreeNode*root)
{
    return dfsheight(root)!=-1;
}

//diameter of binary tree 
//time complexity O(n)
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
int diameterofbt(TreeNode*root)
{
    int maxi=-1;
    height(root, maxi);
    return maxi;
}

//maximum path sum 
//time complexity O(n)
//space complexity is O(n)
int pathsumofbt(TreeNode*root, int &maxi)
{
    if(root==NULL)
    return 0;
    
    int lh=max(0, pathsumofbt(root->left, maxi));
    int rh=max(0, pathsumofbt(root->right, maxi));
    
    maxi=max(maxi, root->val+lh+rh);
    return root->val+max(lh, rh);
}
int maxipathsum(TreeNode*root)
{
    int maxi=INT_MIN;
    pathsumofbt(root, maxi);
    return maxi;
}

//check two tree is identical/same  or not 
//time complexity O(n)
//space complexity is O(n)
bool isidentical(TreeNode*root1, TreeNode*root2)
{
    if(root1==NULL && root2==NULL)
    return true;
    
    if(root1==NULL && root2!=NULL)
    return false;
    
    if(root1!=NULL && root2==NULL)
    return false;
    
    return (root1->val==root2->val && isidentical(root1->left, root2->left) && isidentical(root1->right, root2->right));
}

//check symmetric tree  or not 
//time complexity O(n)
//space complexity is O(n)
bool slove(TreeNode*root1, TreeNode*root2)
{
    if(root1==NULL && root2==NULL)
    return true;
    
    if(root1!=NULL && root2==NULL)
    return false;
    
    if(root1==NULL && root2!=NULL)
    return false;
    
    return (root1->val==root2->val && slove(root1->left, root2->left) &&  slove(root1->right, root2->right));
}
bool symmetric(TreeNode*root)
{
    if(root==NULL)
    return true;
    
    return slove(root->left, root->right);
}

//level order traversal 
//time complexity O(n)
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
//time complexity O(n)
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
//time complexity O(n)
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
            
            sum+=node->val;
        }
        ans.push_back(sum/size);
    }
    return ans;
}


//level order successor of a node in binary tree 
//time complexity O(n)
//space complexity is O(n)
TreeNode*successor(TreeNode*root, int key)
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
        
        if(node->val==k)
        brek;
    }
    return q.front();
}


//zig-zag order traversal 
//time complexity O(n)
//space complexity is O(n)
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
            
            int index=lefttoright ? i : (size-1-i);
            
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
//time complexity O(n)
//space complexity is O(n)
vector<int>rightsise(TreeNode*root)
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
//time complexity O(n)
//space complexity is O(n)
vector<int>leftsize(TreeNode*root)
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
//time complexity O(n)
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
//time complexity O(n)
//space complexity is O(n)
int deepestsleafsum(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    queue<TreeNode*>q;
    q.push(root);
    int sum=0;
    while(!q.empty())
    {
        int size=q.size();
        sum=0;
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            sum+=node->val;
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
        }
    }
    return sum;
}

//convert sorted array to binary search tree
//time complexity O(n)
//space complexity is O(n)
TreeNode*maketree(vector<int>&num, int start, int end)
{
    if(start>end)
    return NULL;
    
    int mid=start+(end-start)/2;
    
    TreeNode*node=new TreeNode(num[mid]);
    
    node->left=maketree(num, start, mid-1);
    node->right=maketree(num, mid+1, end);
    
    return node;
}
TreeNode*sortedarrtoBST(vector<int>&num)
{
    return maketree(num, 0, num.size()-1);
}

//convert sorted linked list to binary search tree 
//time complexity O(n)
//space complexity is O(n)
TreeNode*maketree(vector<int>&num, int start, int end)
{
    if(start>end)
    return NULL;
    
    int mid=start+(end-start)/2;
    
    TreeNode*node=new TreeNode(num[mid]);
    
    node->left=maketree(num, start, mid-1);
    node->right=maketree(num, mid+1, end);
    
    return node;
}
TreeNode*sortedlisttoBST(ListNode*head)
{
    vector<int>num;
    while(head!=NULL)
    {
        num.push_back(head->val);
        head=head->next;
    }
    
    return maketree(num, 0, num.size()-1);
}

//second mathod 
//time complexity O(n)
//space complexity is O(n)
TreeNode*sortedlisttoBST(ListNode*head)
{
    if(head==NULL)
    return NULL;
    
    if(head->next==NULL)
    return new TreeNode(head->val);
    
    auto slow=head;
    auto fast=head;
    auto pre=NULL;
    while(fast!=NULL && fast->next!=NULL)
    {
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    
    pre->next=NULL;
    TreeNode*root=new TreeNode(slow->val);
    
    root->left=sortedlisttoBST(head);
    root->right=sortedlisttoBST(slow->next);
    
    return root;
}


//path sum 
//time complexity O(n)
//space complexity is O(n)
bool pathsumBT(TreeNode*root, int targetsum)
{
    if(root==NULL)
    return false;
    
    if(root->left==NULL && root->right==NULL && targetsum-root->val==0)
    return true;
    
    return pathsumBT(root->left, targetsum-root->val) || pathsumBT(root->right, targetsum-root->val);
}

//path sum-II
//time complexity O(n)
//space complexity is O(n)
vector<vector<int>>ans;
vector<int>path;
void slove(TreeNode*root, int targetSum, int sum)
{
    if(root==NULL)
    return ;
    
    path.push_back(root->val);
    sum+=root->val;
    
    if(root->left==NULL && root->right==NULL && sum==targetSum)
    ans.push_back(path);
    
    slove(root->left, targetSum, sum);
    slove(root->right, targetSum, sum);
    path.pop_back();
    
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum)
{
    int sum=0;
    slove(root, targetSum, sum);
    return ans;
}

//binary tree path 
//time complexity O(n)
//space complexity is O(n)
void slove(TreeNode*root, string temp, vector<string>&ans)
{
    if(root==NULL)
    return ;
    
    if(root->left==NULL && root->right==NULL)
    {
        temp+=to_string(root->val);
        ans.push_back(temp);
        return ;
    }
    
    temp+=to_string(root->val)+"->";
    
    slove(root->left, temp, ans);
    slove(root->right, temp, ans);
}
vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string>ans;
    if(root==NULL)
    return ans;
    
    string temp=" "'
    slove(root, temp, ans);
    return ans;
}


//sum root to leaf number 
//time complexity O(n)
//space complexity is O(n)
void slove(TreeNode*root, int num, int &sum)
{
    if(root==NULL)
    return ;
    
    num+=num*10+root->val;
    if(root->left==NULL && root->right==NULL)
    {
        sum+=num;
        return ;
    }
    
    slove(root->laft, num, sum);
    slove(root->right, num, sum);
}
int sumNumber(TreeNode*root)
{
    int sum=0;
    slove(root, 0, sum)
    return sum;
}

//count complete tree node 
//time complexity O(n)
//space complexity is O(n)
int countNodes(TreeNode* root) 
{
    if(root==NULL)
    return 0;

    int lh=countNodes(root->left);
    int rh=countNodes(root->right);

    return 1+lh+rh;
}

//invert binary tree 
//time complexity O(n)
//space complexity is O(n)
TreeNode*invertBT(TreeNode*root)
{
    if(root==NULL)
    return NULL;
    
    invertBT(root->left);
    invertBT(root->right);
    
    TreeNode*temp=root->left;
    root->left=root->right;
    root->right=temp;
    
    return root;
}

//sum of left leaf node 
//merge two binary tree 







///////////////////////// 
#include<bits/stdc++.h>
using namespace std;

//number of good pair means(arr[i]==arr[j]) brute force approach 
//time complexcity is O(n^2)
//space complexcity is O(1)
int goodpair(int arr[], int n)
{
    int count=0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
    }
    return count;
}
 
//optimal approach 
//time complexcity is O(n)
//space complexcity is O(1)
int goodpair2(int arr[], int n)
{
    int count=0;
    vector<int>fre(101, 0);
    for(int i=0; i<n; i++)
    fre[arr[i]]++;
    
    for(int i=0; i<=100; i++)
    {
        count+=(fre[i]*(fre[i]-1))/2;
    }
    return count;
}


//count nice pair in array nice pair means(arr[i]+rev(arr[j])==arr[j]+rev(arr[i]))
//time complexcity is O(n)
//space complexcity is O(n)
int rev(int n)
{
    int ans=0;
    while(n!=0)
    {
        ans=ans*10+n%10;
        n=n/10;
    }
    return ans;
}
int countnice(int arr[], int n)
{
    unordered_map<int,long>mp;
    int m=1e9+7;
    int count=0;
    for(auto i : mp)
    mp[i-rev(i)]++;
    
    for(auto it : mp)
    {
        count=(count+ (it.second*(it.second-1))/2)%m;
    }
    return count;
}

//2824  count paire whose sum is less than target  brute force approach 
//time complexcity is O(n^2)
//space complexcity is O(1)
int countpair(int arr[], int n, int target)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]+arr[j]<target)
            {
                count++;
            }
        }
    }
    return count;
}

//optimal approach 
//time complexcity is O(nlogn)
//space complexcity is O(1)
int countpair2(int arr[], int n, int target)
{
    int count=0;
    sort(arr, arr+n);
    int start=0;
    int end=n-1;
    while(start<end)
    {
        if(arr[start]+arr[end]<target)
        {
            count+=(end-start);
            start++;
        }
        else 
        {
            end--;
        }
    }
    return count;
}

//max number of k sum pair  brute force approach 
//time complexcity is O(n^2)
//space complexcity is O(1)
int Ksumpair(int arr[], int n, int k)
{
    int count=0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]+arr[j]==k)
            {
                count++;
            }
        }
    }
    return count;
}


//better approach 
//time complexcity is O(n)
//space complexcity is O(n)
int Ksumpair2(int arr[], int n, int k)
{
    unordered_map<int,int>mp;
    int count=0;
    for(int i=0; i<n; i++)
    {
        if(mp[k-arr[i]])
        {
            mp[k-arr[i]]--;
            mp[arr[i]]--;
            count++;
        }
        mp[arr[i]]++;
    }
    return count;
}

//optimal approach 
//time complexcity is O(nlogn)
//space complexcity is O(1)
int Ksumpair2(int arr[], int n, int k)
{
    sort(arr, arr+n);
    int count=0;
    int start=0;
    int end=n-1;
    while(start<end)
    {
        if(arr[start]+arr[end]==k)
        {
            count++;
            start++;
            end--;
        }
        else if(arr[start]+arr[end]>k)
        {
            end--;
        }
        else 
        {
            start++;
        }
    }
    return count;
}

//167 two sum-II (in this problem array are already sorted)
//time complexcity is O(n)
//space complexcity is O(1)
int twosum-II(int arr[] , int n, int target)
{
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        if(arr[start]+arr[end]==target)
        {
            return {start+1, end+1};
        }
        else if(arr[start]+arr[end]>target)
        {
            end--;
        }
        else 
        {
            start++;
        }
    }
    return {};
}

//count number of pairs with absolute difference (arr[i]-arr[j]==k)
int countpairabs(int arr[], int n, int target)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(abs(arr[i]-arr[j])==target)
            {
                count++;
            }
        }
    }
    return count;
}

//optimal approach 
int countpairabs2(int arr[], int n, int target)
{
    int count=0;
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        count+=mp[arr[i]-target]+mp[arr[i]-target];
        
        mp[arr[i]]++;
    }
    return count;
}

//count good meals this means adding two number and check the power of 2 or not 
int countgoodmeal(int arr[], int n)
{
    vector<int>pow;
    int prod=1;
    for(int i=0; i<22; i++)
    {
        pow.push_back(prod);
        prod*=2;
    }
    
    
    unordered_map<int, int>mp;
    long long count=0;
    for(auto it : arr)
    {
        for(auto p : pow)
        {
            if(mp.count(p-it))
            count+=mp[p-it];
        }
        mp[it]++;
    }
    return count%(int)(1e9+7);
}

//brick wall (count the minimum number of cross)
//time complexcity is O(n*m)
//space complexcity is O(n*m)
int minicross(vector<vector<int>>wall)
{
    int cross=0;
    int maxi=INT_MIN;
    for(int i=0; i<wall.size(); i++)
    {
        int sum=0;
        for(int j=0; j<wall[0].size()-1; i++)
        {
            sum+=wall[i][j];
            mp[sum]++;
            
            maxi=max(maxi, mp[sum]);
        }
    }
    cross=wall.size()-maxi;
    return cross;
}


//462 minimum move to equal array element -II 
//time complexcity is O(nlogn)
//space complexcity is O(1)
int minimummove(int arr[], int n)
{
    sort(arr, arr+n);
    int mid=n/2;
    int count=0;
    for(int i=0; i<n; i++)
    {
        count+=abs(arr[i]-arr[mid]);
    }
    return count;
}

//second method 
//time complexcity is O(nlogn)
//space complexcity is O(1)
int minimummove2(int arr[], int n)
{
    sort(arr, arr+n);
    int start=0;
    int end=n-1;
    while(start<end)
    {
        count+=arr[end]-arr[start];
        start++;
        end--;
    }
    return count;
}

//453 minimum move to equal array element 
//time complexcity is O(nlogn)
//space complexcity is O(1)
int minimoveequal(int arr[], int n)
{
    sort(arr, arr+n);
    int count=0;
    for(int i=0; i<n; i++)
    {
        count+=arr[i]-arr[0];
    }
    return count;
}

//number of pair of string with concatenate equal to target brute force approach 
//time complexcity is O(n^2)
//space complexcity is O(1)
int numberofpaircont(vector<string>arr, int target)
{
    int n=arr.size();
    int count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j && arr[i]+arr[j]==target)
            {
                count++;
            }
        }
    }
    return count;
}
//optimal approach 
//time complexcity is O(n)
//space complexcity is O(n)
int numberofpaircont2(vector<string>arr, int target)
{
    unordered_map<string, int>mp;
    int count=0;
    int n=target.size();
    for(auto it : arr)
    {
        mp[it]++;
    }
    
    for(int i=0; i<n; i++)
    {
        string s1=target.substr(0, i);
        string s2=target.substr(i, n);
        if(s1==s2)
        {
            count+=mp[s1]*(mp[s2]-1);
        }
        else 
        {
            count+=mp[s1]*mp[s2];
        }
    }
    return count;
}

//1827 minimum operation to make the array increasing 
//time complexcity is O(n)
//space complexcity is O(1)
int minimumoperation(int arr[], int n)
{
    int count=0;
    for(int i=1; i<n; i++)
    {
        
        if(arr[i]<=arr[i-1])
        {
            int change=arr[i-1]-arr[i]+1;
            count+=change;
            arr[i]+=change;
        }
    }
    return count;
}

//945 minimum increment to make array unique 
//time complexcity is O(n)
//space complexcity is O(1)
int minimumoperationunique(int arr[], int n)
{
    sort(arr, arr+n);
    int count=0;
    for(int i=1; i<n; i++)
    {
        if(arr[i]<=arr[i-1])
        {
            int change=arr[i-1]-arr[i]+1;
            count+=change;
            arr[i]+=change;
        }
    }
    return count;
}

//665 non decreasing array (only one element will be change to make array is non decreasing )
bool nondecreasing(int arr[], int n)
{
    int count=0;
    for(int i=1; i<n; i++)
    {
        if(arr[i]<arr[i-1])
        {
            count++;
            if(count>1)
            return false;
            
            if(i==1 || arr[i-2]<=arr[i])
            arr[i-1]=arr[i];
            else 
            arr[i]=arr[i-1];
        }
    }
    return true;
}

//896 monotonic arrar 
//time complexcity is O(n)
//space complexcity is O(1)
bool monotonic(int arr[], int n)
{
    bool incre=false;
    bool decre=false;
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]<arr[i+1])
        incre=true;
        
        if(arr[i]>arr[i+1])
        decre=true;
    }
    
    if(incre==true && decre==true)
    return false;
    
    return true;
}

//wave sort 
//time complexcity is O(n)
//space complexcity is O(1)
vvoid wavesort(int arr[], int n)
{
    for(int i=1; i<n; i+=2)
    {
        if(arr[i]>arr[i-1])
        {
            swap(arr[i], arr[i-1]);
        }
        
        if(arr[i]>arr[i+1] && i<=n-2)
        {
            swap(arr[i], arr[i+1]);
        }
    }
}

//wiggle sort 
//time complexcity is O(nlogn)
//space complexcity is O(n)
void wigglesort(int arr[], int n)
{
    sort(arr arr+n);
    vector<int>ans(n, 0);
    int j=n-1;
    int i=1;
    while(i<n)
    {
        ans[i]=arr[j];
        i+=2;
        j--;
    }
    
    i=0;
    while(i<n)
    {
        ans[i]=arr[j];
        i+=2;
        j--;
    }
    arr=ans;
}

//maximum product of three number in array (in array contain both positive and negative number) brute force approach 
//time complexcity is O(nlogn)
//space complexcity is o(1)
int maximumprodofthree(int arr[], int n)
{
    sort(arr, arr+n);
    return max(arr[0]*arr[1]*arr[n-1], arr[n-1]*arr[n-2]*arr[n-3]);
}

//optimal approach 
//time complexcity is O(nlogn)
//space complexcity is o(1)
int maximumprodofthree2(int arr[], int n)
{
    int max1=INT_MIN, max2=INT_MIN, max3=INT_MIN;
    int min1=INT_MAX, min2=INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(arr[i]<=min1)
        {
            min2=min2;
            min2=arr[i];
        }
        else if(arr[i]<=min2)
        {
            min2=arr[i];
        }
        if(arr[i]>=max1)
        {
            max3=max2;
            max2=max1;
            max1=arr[i];
        }
        else if(arr[i]>=max2)
        {
            max3=max2;
            max2=arr[i];
        }
        else if(arr[i]>=max3)
        {
            max3=arr[i];
        }
    }
    return max(min*min2*max1, max1*max2*max3);
}

//maximum chunks to make array sorted (in this problem array element will be in range of 0 to n)
//time complexcity is O(n)
//space complexcity is O(1)
int maxichunk(int arr[], int n)
{
    int chunk=0;
    int maxi=-1;
    for(int i=0; i<n; i++)
    {
        maxi=max(maxi, arr[i]);
        if(i==maxi)
        {
            chunk++;
        }
    }
    return chunk;
}

//maximum chunk to make array sorted (in this problem array will be any think)
//time complexcity is O(n)
//space complexcity is O(n)
int maximumchunk2(int arr[], int n)
{
    vectorint>rightmin(n+1);
    
    rightmin[n]=INT_MAX;
    for(int i=n-1; i>=0; i--)
    {
        rightmin[i]=min(rightmin[i+1], arr[i]);
    }
    
    int leftmax=INT_MIN;
    int count=0;
    for(int i=0; i<n; i++)
    {
        leftmax=max(leftmax arr[i]);
        if(leftmax<=rightmin[i])
        {
            count++;
        }
    }
    return count;
}

//maximum erasure value (erasure one subarray with maximum sum)
//time complexcity is O(n)
//space complexcity is O(1)
int maxirease(int arr[], int n)
{
    int maxi=-1;
    int sum=0;
    unordered_set<int>st;
    int i=0;
    for(int j=0; j<n; j++)
    {
        while(st.find(arr[j])!=st.end())
        {
            st.erase(arr[i]);
            sum-=arr[i];
            i++;
        }
        st.insert(arr[j];
        sum+=arr[j];
        maxi=max(maxi, sum);
    }
    return maxi;
}

//guess number 
//time complexcity is O(logn)
//space complexcity is O(1)
int guessnumber(int n)
{
    int start=1;
    int end=n;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(guess(mid)==0)
        {
            return mid;
        }
        else if(guess(mid)==1)
        {
            start=mid+1;
        }
        else 
        {
            end=mid-1;
        }
    }
    return -1;
}

//find k closest element 
int kclosestele(int arr[], int n, int k int x)
{
    int start= 0;
    int end= arr.size()-k;
    while (start<end)
    {
        int mid =start+ (end-start)/2;
        if(x - arr[mid] > arr[mid + k] - x)
        {
            start= mid + 1;
        }
        else
        {
            end= mid;
        }
    }
        
    vector<int> ans;
    for(int i=0; i<k; i++)
    {
        ans.push_back(arr[start+i]);
    }
    return ans;

}

int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();
        for (int i : nums) sum += i;
        int target = sum - x;
        int currSum = 0, maxLen=0;
        int i = 0; //starting index of subarray
        bool found = false;
        for (int j = 0; j < n; j++) {
            currSum += nums[j];
            
            //shrinking our window
            while (i <= j && currSum > target) {
                currSum -= nums[i];
                i += 1;
            }
            if (currSum == target) {
                found = true;
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return found ? n - maxLen : -1;
    }


/// 

//increasing triplate (arr[i]<arr[j]<arr[k] than return true other wise false) brute force approach
//time complexity is O(n^3)
//space complexity is O(1)
bool inctriplate(int arr[], int n)
{
    for(int i=0; i<n-2; i++)
    {
        for(int j=i+1; j<n-1; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if(arr[j]>arr[i] && arr[k]>arr[j])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
bool inctriplate(int arr[], int n)
{
    if(n<3)
    return false;
    
    int first=INT_MAX;
    int second=INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(arr[i]<first)
        {
            first=arr[i];
        }
        else if(arr[i]>first && arr[i]<second)
        {
            second=arr[i];
        }
        else if(aar[i]>second)
        {
            return true;
        }
    }
    return false;
}

//343 integer break (break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers. )
//time complexity is O(n)
//space complexity is O(1)
int integerbreak(int n)
{
    if(n==2)
    return 1;
    
    if(n==3)
    return 2;
    
    int prod=1;
    while(n>4)
    {
        prod*=3;
        n=n-3;
    }
    prod*=n;
    return prod;
}

//number of subarray with bounded maximum 
//time complexity is O(n)
//space complexity is O(1)
int maxisubarrbounded(int arr[], int n, int low, int high)
{
    int count=0;
    int m=0;
    int i=0;
    int j=0;
    while(j<n)
    {
        if(arr[j]>high)
        {
            m=0;
            i=j+1;
        }
        else if(arr[i]>=low && arr[i]<=high)
        {
            m=j-i+1;
        }
        count+=m;
        j++;
    }
    return count;
}

//3 sum closest (in this problen given both positive and negative element) brute froce approach 
//time complexity is O(n^3)
//space complexity is O(1)
int sum3closest(int arr[], int n, int target)
{
    int diff=INT_MAX;
    int closesum=INT_MAX;
    for(int i=0; i<n-2; i++)
    {
        for(int j=i+1; j<n-1; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                int sum=arr[i]+arr[j]+arr[k];
                int close=abs(sum-target);
                if(close < diff)
                {
                    diff = close;
                    closessum = sum;
                }
            }
        }
    }
    return closessum;
}

//optimal approach 
//time complexity is O(n^2)
//space complexity is O(1)
int sum3closest2(int arr[], int n, int target)
{
    int diff=INT_MAX;
    int closesum=0;
    sort(arr, arr+n);
    for(int i=0; i<n-1; i++)
    {
        int start=i+1;
        int end=n-1;
        while(start<end)
        {
            int sum=arr[i]+arr[start]+arr[end];
            if(sum==target)
            {
                return sum;
            }
            else if(sum>target)
            {
                end--;
            }
            else 
            {
                start++;
            }
            
            int close=abs(sum-target);
            if(close<diff)
            {
                diff=close;
                closesum=sum;
                
            }
        }
    }
    return closesum;
}




//minimum cost climbing  stairs 
//minimum number of coins make target 
//maximum sum of non adjacent element -or- house robber
//cut rod into segment in x y z 
//combination sum IV
//get minimum number to make perfect squares 
//largest squares from a matrix
//min score triangulation of polygon
//count derangement 
//longest increasing subsequence
//russian doll envelope problem 
//0/1 knapsack problem 






#include<bits/stdc++.h>
using namespace std;

int slove(vector<int>&arr, int n)
{
    if(n==0)
    return arr[0];
    
    if(n==1)
    return arr[1];
    
    
    int ans+=arr[n]+min((slove(arr, n-2), slove(arr, n-1));
    return ans;
}
int minimumcost(vector<int>&arr)
{
    int ans=min(slove(arr, n-1), slove(arr, n-2));
    return ans;
}

//-----------------------------------------------------------------------
int slove(vector<int>&arr, int k)
{
    if(k==0)
    return 0;
    
    if(k<INT_MIN)
    return INT_MAX;
    
    int mini=INT_MAX;
    for(int i=0; i<n; i++)
    {
        int ans=slove(arr, k-arr[i]);
        if(ans!=INT_MIN)
        mini=min(mini, 1+ans);
    }
    return mini;
}
int minimumcoin(vector<int>&arr, int k)
{
    return slove(arr, k);
}

//------------------------------------------------------------------------------------- 
int slove(vector<int>&arr, int index)
{
    if(index<0)
    return 0;
    
    if(index==0)
    return arr[0];
    
    int incl=arr[index]+slove(arr, index-2);
    int excl=slove(arr, index-1);
    
    return max(incl, excl);
}
int maximumsumofadj(vector<int>&arr)
{
    int n=arr.size();
    return slove(arr, n-1);
}

//---------------------------------------------------------------------------------------
int slove(vector<int>&arr, int index)
{
    if(index<0)
    return 0;
    
    if(index==0)
    return arr[0];
    
    int incl=arr[index]+slove(arr, index-2);
    int excl=slove(arr, index-1);
    
    return max(incl, excl);
}
int houserobbery(vector<int>&arr)
{
    int n=arr.size();
    if(n==1)
    return arr[0];
    
    vector<int>first;
    vector<int>second;
    for(int i=0; i<n; i++)
    {
        if(i!=n-1)
        first.push_back(arr[i]);
        if(i!=0)
        second.push_back(arr[i]); 
    }
    
    return max(slove(first, first.size()-1), slove(second, second.size()-1));
}

//----------------------------------------------------------------------- 
int slove(int n, int x, int y, int z)
{
    if(n<0)
    return INT_MIN;
    
    if(n==0)
    return 0;
    
    int first=1+slove(n-x, x, y,z);
    int second=1+slove(n-y, x, y, z);
    int third=1+slove(n-z, x, y z);
    
    int max(first, max(second, third));
    return ans;
}
int cutsegment(int n, int x, int y, int z)
{
    int ans=slove(n, x y, z);
    if(ans<0)
    return 0;
    
    else 
    return ans;
}

//------------------------------------------------------------------------ 
int countderangement(int n)
{
    if(n==1)
    return 0;
    
    if(n==2)
    return 1;
    
    int ans=(n-1)*(countderangement(n-1)+countderangement(n-2));
    return ans;
}

//------------------------------------------------------------------------ 
int slove(int n, int k)
{
    if(n==1)
    return k;
    
    if(n==2)
    return k*k;
    
    int smae=(k-1)*slove(n-2, k);
    int different=(k-1)*slove(n-2, k);
    int ans=same+different;
    return ans;
}
int paintingfence(int n, int k)
{
    return slove(n, k);
}

//----------------------------------------------------- 
int slove(vector<int>&wt, vector<int>val, int index, int capcity)
{
    if(index==0)
    {
        if(wt[0]<=capcity)
        {
            return val[0];
        }
        return 0;
    }
    
    int incl=0;
    if(wt[0]<=capcity)
    {
        incl=val[index]+slove(wt, val, index-1, capcity-val[index]);
    }
    
    int excl=slove(wt, val, index-1, capcity);
    
    return max(incl, excl);
}
int 0/1knapsack(vector<int>wt, vector<int>val, int n, int capcity)
{
    return slove(wt, val, n-1, capcity);
}

//--------------------------------------------------------------------------------- 
int slove(vector<int>&arr, int target)
{
    if(target==0)
    return 1;
    
    if(target<0)
    return 0;
    
    int ans=0;
    for(int i=0; i<n; i++)
    {
        ans+=slove(arr, target-arr[i]);
    }
    return ans;
    
    
}
int combinationsum(vector<int>&arr, int target)
{
    return slove(arr, target)
}

//--------------------------------------------------------------------------------------- 
int slove(int n)
{
    if(n==0)
    return 0;
    
    int ans=n;
    for(int i=1; i*i<=n; i++)
    {
        ans=min(ans, 1+slove(n-i*i));
    }
    return ans;
}
int getminimumsquare(int n)
{
    return slove(n);
}

//-------------------------------------------------------------------------------------- 
int slove(vector<vector<int>>&arr, int i, int j, int maxi)
{
    if(i>=arr.size() || j>=arr[0].size())
    return 0;
    
    int right=slove(arr, i, j+1, maxi);
    int diagonal=slove(arr, i+1, j+1, maxi);
    int down=slove(arr, i+1, j, maxi);
    
    if(arr[i]==1)
    {
        int ans=1+min(right, min(down, diagonal));
        maxi=max(maxi, ans);
        return maxi
    }
    else 
    {
        return 0;, 
    }
}
int maximalsquare(vector<vector<int>>&arr)
{
    int maxi=0;
    slove(arr, 0,0 , maxi);
    return maxi;
}




mam i would request you for another 15 to 20 minutesof your 
time with me and i am sure by the end of this interview you will have 2-3 
very good reason of your own as to why you should hire me as a person 
looking to serve a company all i look  for is a chance to prove 
myself and i am hopeful that you will grant me that chance 



https://www.linkedin.com/feed/update/urn:li:activity:7133512794905210880/



//remove duplicate from unsorted linked list 


//odd or even l
//second method  to find odd and even linked list 

// Nth node from end of linked list 
//swap node kth from starting and kth from end in linked list 
//2-method 
//add two linked list 
//second version 
//sort linked list 
//rotate linked list 
//reorder linked list 
//insertion sort in linked list
//sort 0s 1s 2s linked list  
//flattening of linked list 




//---------------------------- 

#include<bits/stdc++.h>
using namespace std;

//factorial of a number 
int findfact(int n)
{
    int ans=1;
    for(int i=1; i<=n; i++)
    {
        ans=ans*i;
    }
    return ans;
}

//prime number (number are divisible by 1 or itself )
bool primenum(int n)
{
    for(int i=2; i<n; i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

//print all prime from 1 to n

int main()
{
    int n;
    cin>>n;
    for(int i=2; i<=n; i++)
    {
        bool isprime=primenumber(i);
        if(isprime)
        cout<<i<<" ";
    }
}

//find even or odd 
bool evenorodd(int n)
{
    if(n%2==0)
    {
        return true;
    }
    return false;
}

bool checkevenodd(int n)
{
    if(n&1==0)
    {
        return true;
    }
    return false;
}

//reverse integer 


//set k th bit  (first find the mask left shift 1 by k time and than bitwise or with given number )
int setkthbit(int n, int k)
{
    int mask= 1<<k;
    int ans= n|mask;
    return ans;
}


//convert the temperature 
vector<double>convert(double celsius)
{
    double kelvin=celsius+273.15;
    double fahrenheit=celsius*1.80+32.00;
    vector<double>ans;
    ans.push_back(kelvin);
    ans.push_back(fahrenheit);
    return ans;
}

//dnf sort  
//move all negative to the left 
void movenegative(int arr[], int n)
{
    int start=0;
    int end=n-1;
    while(start<end)
    {
        if(arr[start]<0)
        {
            start++;
        }
        else if(arr[end]>0)
        {
            end--;
        }
        else 
        {
            swap(arr[start], arr[end]);
        }
    }
}

//find duplicate using hash map 
//find duplicate using inbuilt sorting algorithm 
int duplicate(int arr[], int n)
{
    sort(arr, arr+n);
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]==arr[i+1])
        return arr[i];
    }
    return -1;
}

//visited method 
int duplicate2(int arr[], int n)
{
    int ans=-1;
    for(int i=0; i<n; i++)
    {
        int index=abs(arr[i]);
        if(arr[index]<0)
        {
            ans=index;
            break;
        }
        
        arr[index]*=-1;
    }
    return -1;
}

//find duplicate using cyclic sort 
//find duplicate using xor method 

//find missing number using visited method 
int missing(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        int index=abs(arr[i])-1;
        if(arr[index]>0)
        arr[index]*=-1;
    }
    
    for(int i=0; i<n; i++)
    {
        if(arr[i]>0)
        return i+1;
    }
    return -1;
}

//find missing number using cyclic sort 
//common element of three sorted array
//find unique element in array 
//union of two array 
//intersection of two array 
//2 sum 
//3 sum 

//------------------------------------------------------------- 
//when creating multiple varible to store the data than use array to store the data  
//read memset fuction 













