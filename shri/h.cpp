
//video10,  11,12, 14,15,16,17 ,19
//search element in an array 
//reverse array 
//second maximum element 
int secondlargest(int arr[], int n)
{
    int largest=-1;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
        }
    }
    
    int second=-1;
    for(int i=0; i<n; i++)
    {
        if(arr[i]!=largest)
        {
            second=max(second, arr[i]);
        }
    }
    return second;
}

//find missing number where number lies between (1 to n)
int missing(int arr[], int n)
{
    //sum of array element 
    int sum=0;
    for(int i=0; i<n; i++)
    sum+=arr[i];
    
    //sum of n number 
    int ans=n*(n-1)/2;
    
    return (ans-sum);
}

//rotate array by one place 
void rotate(int arr[], int n)
{
    int last=arr[n-1];
    
    for(int i=n-2; i>=0; i--)
    {
        arr[i+1]=arr[i];
    }
    
    arr[0]=last;
}

//convert lower letter to upper letter 
char convert(char ch)
{
    char ans=ch-'a'+'A';
    return ans;
}

//convert upper letter to lower letter 
char convert(char ch)
{
    char ans=ch-'A'+'a';
    return ans;
}

//armstrong number 
//find traling zero in factorial (this means find the factorial than how many zero come into ans) multiple of make zero always 
int tralingzero(int n)
{
    int count=0;
    while(n>=5)
    {
        count+=n/5;
        n=n/5;
    }
    return count;
}

//(double>float>int when apply / , * ) 
//(>, <, >=, <=) > (==, !=)
//conver decimal to binary 
int convertbinary(int n)
{
    int ans=0;
    int mul=1;
    int rem;
    while(n>0)
    {
        rem=rem%2;
        n=n/2;
        ans=rem*mul+ans;
        mul=mul*10;
    }
    return ans;
}

//conver binary to decimal
int convertdecimal(int n)
{
    int ans=0;
    int mul=1;
    int rem;
    while(n>0)
    {
        rem=rem%10;
        n=n/10;
        ans=rem*mul+ans;
        mul=mul*2;
    }
    return ans;
}


//nim game  
bool canwinnim(int n)
{
    if(n%4!=0)
    return true;
    else 
    return false;
}


//selection sort 
//two sum || using binary search (time complexity is O(nlogn))
int binaryseach(int arr[], int start, int end, int target)
{
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        if(arr[mid]<target)
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
vector<int>twosum2(int arr[], int n, int target)
{
    for(int i=0; i<n-1; i++)
    {
        int remain=target-arr[i];
        int index=binaryseach(arr, i+1, n-1, remain);
        
        if(index!=-1)
        return ({i+1, index+1});
    }
    return {};
}

//using two pointer 
vector<int>twosum2opt(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    vector<int>ans;
    while(start<end)
    {
        if(arr[start]+arr[end]==target)
        {
            ans.push_back(start+1);
            ans.push_back(end+1);
            return ans;
        }
        else if(arr[start]+arr[end]<target)
        {
            strat++;
        }
        else 
        {
            end--;
        }
    }
    return ans;
}

//using recursion 
vector<int>solve(vector<int>&arr, int target, int start, int end)
{
    if(start>=end)
    return {};
    
    if(arr[start]+arr[end]==target)
    return {start+1, end+1};
    else if(arr[start]+arr[end]<target)
    return solve(arr, target, start+1, end);
    else 
    return solve(arr, target, start, end-1);
}
vector<int>twosumrec(vector<int>&arr int target)
{
    return solve(arr, target, 0, arr.size()-1);
}

//Pair with largest sum which is less than K in the array (using two pointer)
int twoSumLessThanK(vector<int>&arr, int k) 
{
    sort(arr.begin(), arr.end());
    int maxSum = -1;
    int start = 0;
    int end = arr.size() - 1;
    
    while (start<end) 
    {
        int sum = arr[start] + arr[end];
        if (sum < k) 
        {
            maxSum = max(maxSum, sum);
            start++;
        } 
        else 
        {
            end--;
        }
    }
    return maxSum;
}

//using binary search 
int twosumlessk(int arr[], int n, int k)
{
    sort(arr, arr+n);
    
    int maxans=-1;
    for(int i=0; i<n; i++)
    {
        int remain=k-arr[i];
        int start=i+1;
        int end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]<remain)
            {
                maxans=max(maxans, arr[i]+arr[mid]);
                start=mid+1;
            }
            else 
            {
                end=mid-1;
            }
        }
    }
    return maxans;
}

//Rearrange an array in maximum minimum 
void rearrange(int arr[], int n)
{
    int ans[n];
    int start=0;
    int end=n-1;
    int index=0;
    while(start<=end)
    {
        if(index%2==0)
        {
            ans[index]=arr[end];
            end--;
            index++;
        }
        else 
        {
            ans[index]=arr[start];
            start++;
            index++;
        }
    }
    
    for(int i=0; i<n; i++)
    arr[i]=ans[i];
}

//Find the smallest missing number 

//--------------------------------------------------------------- 

#include<bits/stdc++.h>
using namespace std;

class stack{
    
    int size;
    int *arr;
    int top;
    
    public : 
    stack(int sz)
    {
        size=sz;
        top=-1;
        arr=new int[sz];
    }
    
    void push(int val)
    {
        if(top==size-1)
        {
            cout<<"stack are overflow"<<end;
            return ;
        }
        else 
        {
            top++;
            arr[top]=val;
        }
    }
    
    void pop()
    {
        if(top==-1)
        {
            cout<<"stack are underflow"<<endl;
            return ;
        }
        else 
        {
            coout<<arr[top]<<endl;
            top--;
        }
    }
    
    int peak()
    {
        if(top==-1)
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        else 
        {
            return arr[top];
        }
    }
    
    bool isempty()
    {
        return top==-1;
    }
    
    int issize()
    {
        return top+1;
    }
};

//stack implement using linklist 
class node 
{
    int data;
    node *next;
    
    public :
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

class stack{
    
    node*top;
    int size;
    
    public :
    stack()
    {
        top=NULL;
        size=0;
    }
    
    void push(int val)
    {
        node*temp=new node(val);
        if(temp==NULL) //heap memory are full 
        {
            cout<<"stack overflow"<<endl;
        }
        
        temp->next=top;
        top=temp;
        size++;
    }
    
    void pop()
    {
        if(top==NULL)
        {
            cout<<"stack underflow"<<endl;
        }
        else 
        {
            node*ptr=top;
            cout<<top->data<<endl;
            
            top=top->next;
            delete ptr;
            size--;
        }
    }
    
    int peak()
    {
        if(top==NULL)
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        else 
        {
            return top->data;
        }
    }
    
    bool isempty()
    {
        return top==NULL;
    }
    
    int issize()
    {
        return size;
    }
};

//next greater element in array 
//next smaller element in array
//next smaller element in array 
//next  element in array
//smallest number are left 
//stock  span problem 
//next greater element 2 



// Recursion 
//print 1 to n 
//print 1 to n for all even number 
//check palindrome on string 
//count vowel in string 
//reverse string 
//convert lowercase letter to uppercase letter 
//fiboncci series 
//nth stair 
//gcd of 2 number  
//factorial of a number  
//sum of n  number 
//power of a number 
int power(int num, int n)
{
    if(n==1)
    return 1;
    
    return num*power(num, n-1);
}

//sum of square of n number 
int squaresum(int n)
{
    if(n==1)
    return 1;
    
    return n*n+squaresum(n-1);
}





