

#include<bits/stdc++.h>
using namespace std;

class maxheap
{
    int *arr;
    int size;
    int totalsize;
    
    public : 
    maxheap(int n)
    {
        arr=new arr[n];
        size=0;
        totalsize=n;
    }
    
    void insertion(int val)
    {
        if(size==totalsize)
        {
            cout<<"heap overflow"<<endl;
            return ;
        }
        
        arr[size]=val;
        int index=size;
        size++;
        
        while(index>0)
        {
            if(arr[index]>arr[(index-1)/2])
            {
                swap(arr[index], arr[(index-1)/2]);
                index=(index-1)/2;
            }
            else 
            {
                break;
            }
        }
        cout<<arr[index]<< " is inserted into heap \n";
    }
    
    int deletion()
    {
        if(size==0)
        {
            cout<<"heap underflow"<<endl;
        }
        
        int ans=arr[1];
        
        arr[1]=arr[size];
        size--;
        
        int index=1;
        while(index<size)
        {
            int left=2*index;
            int right=2*right+1;
            int largest=index;
            
            if(left<size && arr[largest]<arr[left])
            largest=left;
            
            if(right<size && arr[largest]<arr[right])
            largest=right;
            
            if(largest==index)
            break;
            else 
            {
                swap(arr[index], arr[largest]);
                index=largest; 
            }
            
        }
        return ans;
    }
}


void heapify(int arr[], int n, int i)
{
    int index=i;
    int leftindex=2*i;
    int rightindex=2*i+1;
    
    if(left<=n && arr[largest]<arr[leftindex])
    largest=leftindex;
    
    if(right<=n && arr[largest]<arr[rightindex])
    largest=rightindex;
    
    if(index!=largest)
    {
        swap(arr[index], arr[largest]);
        index=largest;
        
        heapify(arr, n, index);
    }
}

void buildheap(int arr[], int n)
{
    for(int i=n/2; i>0; i--)
    {
        heapify(arr, n, i);
    }
}

//first element and  last element are swap 
//heapify 
void heapsort(int arr[], int n)
{
    while(n!=1)
    {
        swap(arr[1], arr[n]);
        n--;
        
        heapify(arr, n, 1);
    }
}




//height of heap 
int heapheight(int arr[], int n)
{
    if(n==1)
    return 1;
    
    int height=0;
    while(n>1)
    {
        height++;
        n=n/2;
    }
    return height;
}

//minimum cost of ropes 
int minicost(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>>q;
    
    for(int i=0; i<n; i++)
    q.push(arr[i]);
    
    int cost=0;
    while(q.size()>1)
    {
        int top=q.top();
        q.pop();
        
        top+=q.top();
        q.pop();
        
        cost+=top;
        
        q.push(top);
    }
    return cost;
}

//magician and chocolates 
int magicianchoc(int arr[], int n, int A)
{
    priority_queue<int>q;
    
    for(int i=0; i<n; i++)
    q.push(arr[i]);
    
    int maxcho=0;
    
    while(A && (!q.empty()))
    {
        maxcho+=q.top();
        
        if(q.top()/2)
        q.push(q.top()/2);
        
        q.pop();
        A--;
    }
    return maxcho;
}

//last stone weight 
int laststone(int arr[], int n)
{
    priority_queue<int>q;
    
    for(int i=0; i<n; i++)
    q.push(arr[i]);
    
    while(q.size()>1)
    {
        int wight=q.top();
        q.pop();
        
        weight-=q.top();
        q.pop();
        
        if(weight)
        q.push(weight);
    }
    
    if(q.empty())
    return 0;
    
    return q.top();
}

//profit maximization 
int profitmaxi(int arr[], int n, int B)
{
    int sum=0;
    priority_queue<int>q;
    
    for(int i=0; i<n; i++)
    q.push(arr[i]);
    
    while(B && (!q.empty()))
    {
        sum+=q.top();
        
        if(q.top()-1)
        q.push(q.top()-1);
        
        q.pop();
        B--;
    }
    return sum;
}

//kth smallest element 
int kthsmallest(int arr[], int n, int k)
{
    priority_queue<int>q;
    
    for(int i=0; i<k; i++)
    q.push(arr[i]);
    
    for(int i=k; i<n; i++)
    {
        if(arr[i]<q.top())
        {
            q.pop();
            
            q.push(arr[i]);
        }
    }
    return q.top();
}

//kth largest element 
int kthsmallest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>>q;
    
    for(int i=0; i<k; i++)
    q.push(arr[i]);
    
    for(int i=k; i<n; i++)
    {
        if(arr[i]>q.top())
        {
            q.pop();
            
            q.push(arr[i]);
        }
    }
    return q.top();
}



//merge to max heap 
void heapify(int arr[], int index, int n)
{
    int index=index;
    int left=2*index;
    int right=2*index+1;
    
    if(left<n && arr[left]>arr[largest])
    largest=left;
    
    if(right<n && arr[right]>arr[largest])
    largest=right;
    
    if(largest!=index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, largest, n);
        
    }
}
vector<int>mergeheap(int arr1[], int arr2[], int n, int m)
{
    vector<int>ans;
    
    for(int i=0; i<n; i++)
    ans.push_back(arr1[i]);
    
    for(int i=0; i<m; i++)
    ans.push_back(arr2[i]);
    
    n=ans.size();
    for(int i=n/2-1; i>=0; i--)
    {
        heapify(ans, i, n);
    }
    return ans;
}

//is binary tree are heap 
int countnode(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    return 1+countnode(root->left)+countnode(root->right);
}
bool cbt(TreeNode*root, int index, int total)
{
    if(root==NULL)
    return 1;
    
    if(index>=total)
    return 0;
    
    return cbt(root->left, 2*index+1, total) && cbt(root->right, 2*index+2, total);
}
bool maxheap(TreeNode*root)
{
    if(root->left!=NULL)
    {
        if(root->val<root->left->val)
        return 0;
        
        if(!maxheap(root->left))
        return 0;
    }
    if(root->right!=NULL)
    {
        if(root->val<root->right->val)
        return 0;
        
        return maxheap(root->right)
    }
    return 1; //this means no left no right 
}
bool isheap(TreeNode*root)
{
    int num=countnode(root);
    
    bool ans=cbt(root, 0, num);
    if(ans==0)
    return 0;
    
    return maxheap(root);
    
}

//bst to max heap 
void inorder(TreeNode*root, vector<int>*ans)
{
    if(root==NULL)
    return ;
    
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
void postorder(TreeNode*root, vector<int>&ans, int &index)
{
    if(root==NULL)
    return ;
    
    postorder(root->left, ans, index);
    postorder(root->right, ans, index);
    
    root->val=ans[index];
    index++;
}
void convertbsttomaxheap(TreeNode*root)
{
    //inorder traversal 
    vector<int>ans;
    inorder(root, ans);
    
    //postorder traversal 
    int index=0;
    postorder(root, ans, index);
}


//rescursion 
//climb stair 
//print array 
//find maximum 
//print each digit 
//print(n/10)
//int digit=n%10;
//cout<<digit<<" ";

//stack 
//background string compare 





