
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
    }
}

//---------------------------------------------------------------- 


//reverse array using inbuilt function 
//time complexity is O(n)
//space complexity is O(1)
void reverseinbuilt(int arr[], int n)
{
    reverse(arr, arr+n);
    
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//reverse array 
//time complexity is O(n)
//space complexity is O(1)
void reverse1(int arr[], int n)
{
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

//reverse array pairwise 
//time complexity is O(n)
//space complexity is O(1)
void reverse2(int arr[], int n)
{
    for(int i=0; i<n; i+=2)
    {
        if(i+1<n)
        {
            swap(arr[i], arr[i+1]);
        }
    }
}

//reverse array group size k 
//time complexity is O(n)
//space complexity is O(1)
void reverse3(int arr[], int n, int k)
{
    for(int i=0; i<n; i+=k)
    {
        if(i+k<n)
        {
            reverse(arr+i, arr+i+k);
        }
        else
        {
            reverse(arr+i, arr+n);
        }
    }
}

//reverse integer
//time complexity is O(n)
//space complexity is O(1)
int reverseinteger(int n)
{
    int ans=0;
    while(n!=0)
    {
        int digit=n%10;
        ans=ans*10+digit;
        n/=10;
    }
    return ans;
}

//check array are palindrome or not 
//time complexity is O(n)
//space complexity is O(1)
bool checkpalindrome(int arr[], int n)
{
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        if(arr[start]!=arr[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

//wave array (given sorted array convert wave from)
//time complexity is O(n)
//space complexity is O(1)
void wave(int arr[], int n)
{
    for(int i=0; i<n; i+=2)
    {
        if(i+1<n)
        {
            swap(arr[i], arr[i+1]);
        }
    }
}

//array are sorted or not brute force approach 
//time complexity is O(n^2)
//space complexity is O(1)
bool issorted(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]<arr[j])
            {
                return false;
            }
        }
    }
    return true;
}

//optimal 
//time complexity is O(n)
//space complexity is O(1)
bool issorted(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        if(arr[i]<arr[i-1])
        {
            return false;
        }
    }
    return true;
}

//move negative element at the end of array using bruteforce approach 
//time complexity is O(n)
//space complexity is O(n)
void moveneg(int arr[], int n)
{
    vector<int>temp;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>0)
        {
            temp.push_back(arr[i]);
        }
    }
    
    for(int i=0; i<n; i++)
    {
        if(arr[i]<0)
        {
            temp.push_back(arr[i]);
        }
    }
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
void movenegopt(int arr[], int n)
{
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

//move zero at the end of array using bruteforce approach 
//time complexity is O(n)
//space complexity is O(n)
vector<int> movezero(int arr[], int n)
{
    vector<int>temp;
    for(int i=0; i<n; i++)
    {
        if(arr[i]!=0)
        {
            temp.push_back(arr[i]);
        }
    }
    
    int sz=temp.size();
    for(int i=0; i<sz; i++)
    {
        arr[i]=temp[i];
    ]
    
    for(int i=sz; i<n; i++)
    {
        arr[i]=0;
    }
    return arr;
}

//optimal approach
//time complexity is O(n)
//space complexity is O(1)
vector<int> movezeroopt(int arr[], int n)
{
    int j=-1;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==0)
        {
            j=i;
            break;
        }
    }
    
    //this means no nonzero element 
    if(j==-1)
    return arr;
    
    for(int i=j+1; i<n; i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return arr;
}

//arrange alternate sign element in array bruteforce approach 
//time complexity is O(n)
//space complexity is O(n)
vector<int>RearrangebySign(vector<int>arr, int n)
{
    
    vector<int> pos;
    vector<int> neg;
  
    for(int i=0; i<n; i++)
    {
        if(arr[i]>0) 
        pos.push_back(arr[i]);
      
        else 
        neg.push_back(A[i]);
    }
  
    // Positives on even indices, negatives on odd.
    for(int i=0; i<n/2; i++)
    {
      
      arr[2*i] = pos[i];
      arr[2*i+1] = neg[i];
    }
    
  return arr;
}

//better approach 
//time complexity is O(n)
//space complexity is O(n)
vector<int> RearrangebySign(vector<int>arr)
{
    int n = arr.size();

    vector<int> ans(n,0);
  
    int posIndex = 0;
    int negIndex = 1;
    for(int i=0; i<n; i++)
    {
      
        //Fill negative elements in odd indices and inc by 2
        if(arr[i]<0)
        {
            ans[negIndex] = arr[i];
            negIndex+=2;
        }
      
        //Fill positive elements in even indices and inc by 2.
        else
        {
            ans[posIndex] = arr[i];
            posIndex+=2;
        }
   }
  return ans;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(n)
vector<int> RearrangebySign(vector<int>arr, int n)
{
    vector<int> pos;
    vector<int> neg;
  
    for(int i=0;i<n;i++)
    {
      
      if(arr[i]>0) 
      pos.push_back(arr[i]);
      
      else 
      neg.push_back(arr[i]);
    }
  
    if(pos.size() < neg.size())
    {
        for(int i=0; i<pos.size(); i++)
        {
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        
        int index = pos.size()*2;
        for(int i = pos.size(); i<neg.size(); i++)
        {
            arr[index] = neg[i];
            index++;
        }
    }
    else
    {
        for(int i=0; i<neg.size(); i++)
        {
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        
        int index = neg.size()*2;
        for(int i = neg.size(); i<pos.size(); i++)
        {
            arr[index] = pos[i];
            index++;
        }
    }
  return arr;
}

//parity sort 
//time complexity is O(n)
//space complexity is O(1)
void paritysort(int arr[], int n)
{
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]%2==0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

//O 1 2 sort 
//time complexity is O(n)
//space complexity is O(1)
void sort012(int arr[], int n)
{
    int count0=0;
    int count1=0;
    int count2=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==0)
        {
            count0++;
        }
        else if(arr[i]==1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    for(int i=0; i<count0; i++)
    arr[i]=0;
    
    for(int i=count0; i<count0+count1; i++)
    arr[i]=1;
    
    for(int i=count1+count0; i<n; i++)
    arr[i]=2;
    
}

//dnf sort 
//time complexity is O(n)
//space complexity is O(1)
void DNFSORT(int arr[], int n)
{
    int start=0;
    int mid=0;
    int end=n-1;
    while(mid<=end)
    {
        if(arr[mid]==0)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[end], arr[mid]);
            end--;
        }
    }
}

//three way partition of array 
//time complexity is O(n)
//space complexity is O(1)
void partition(int arr[], int n, int a, int b)
{
    int start=0;
    int mid=0;
    int end=n-1;
    while(mid<=end)
    {
        if(arr[mid]<a)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
        else if(arr[mid]>b)
        {
            swap(arr[mid], arr[end]);
            end--;
        }
        else
        {
            mid++;
        }
    }
}

//find the minimum element in array using bruteforce approach
//time complexity is O(nlogn)
//space complexity is O(1)
int minimumele(int arr[], int n)
{
    sort(arr, arr+n);
    return arr[0];
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
int minimumeleopt(int arr[], int n)
{
    int mini=INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(arr[i]<mini)
        {
            mini=arr[i];
        }
    }
    return mini;
}

//find the maximum element in array using bruteforce approach
//time complexity is O(nlogn)
//space complexity is O(1)
int maximumele(int arr[], int n)
{
    sort(arr, arr+n);
    return arr[n-1];
}

//optimal approach
//time complexity is O(n)
//space complexity is O(1)
int maximumeleopt(int arr[], int n)
{
    int maxi=INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>maxi)
        {
            maxi=arr[i];
        }
    }
    return maxi;
}

//second largest element in array bruteforce approach
//time complexity is O(nlogn)
//space complexity is O(1)
int secondlargest(int arr[], int n)
{
    sort(arr, arr+n);
    int largest=arr[n-1];
    
    int sec=-1;
    for(int i=n-2; i>=0; i--)
    {
        if(arr[i]!=largest)
        {
            sec=arr[i];
            break;
        }
    }
    return sec;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
int secondlargestopt(int arr[], int n)
{
    int largest=arr[0];
    int sec=INT_MIN;
    for(int i=1; i<n; i++)
    {
        if(arr[i] >largest)
        {
            sec=largest;
            largest=arr[i];
        }
        else if(largest>arr[i] && arr[i]>sec)
        {
            sec=arr[i];
        }
    }
    return sec;
}

//second smallest element in array bruteforce approach 
//time complexity is O(nlogn)
//space complexity is O(1)
int secondsmallest(int arr[], int n)
{
    sort(arr, arr+n);
    int small=arr[0];
    
    int sec=-1;
    for(int i=1; i<n; i++)
    {
        if(arr[i]!=small)
        {
            sec=arr[i];
            break;
        }
    }
    return sec;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
int secondsmallestopt(int arr[], int n)
{
    int smallest=arr[0];
    int sec=INT_MAX;
    for(int i=1; i<n; i++)
    {
        if(arr[i]<smallest)
        {
            sec=smallest;
            smallest=arr[i];
        }
        else if(smallest!=arr[i] && arr[i]<sec)
        {
            sec=arr[i];
        }
    }
    return sec;
}

//find the kthsmallest element in array 
int kthsmallest(int arr[], int n, int k)
{
    priority_queue<int>q;
    for(int i=0; i<n; i++)
    {
        q.push(arr[i]);
        if(q.size()>k)
        {
            q.pop();
        }
    }
    return q.top();
}

//find the kthlargest element in array
int kthlargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>>q;
    for(int i=0; i<n; i++)
    {
        q.push(arr[i]);
        if(q.size()>k)
        {
            q.pop();
        }
    }
    return q.top();
}

//Find the Kth Largest Integer in the Array
//third largest element in array 
int thirdlargest(int arr[], int n)
{
    int a=INT_MIN;
    int b=INT_MIN;
    int c=INT_MIN;
    int flage=0;
    for(int i=0; i<n; i++)
    {
        a=max(a, arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]!=a)
        {
            b=max(b, arr[i]);
        }
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]!=a && arr[i]!=b)
        {
            c=max(c, arr[i]);
            flage=1;
        }
    }
    if(flage)
    {
        return c;
    }
    return a;
}

//monotonic array (An array is monotonic if it is either monotone increasing or monotone decreasing.)
//find unique element in array bruteforce approach 
int unique(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        int count=0;
        for(int j=i; j<n; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
        if(count==1)
        {
            return arr[i];
        }
    }
    return -1;
}

//better approach 
int uniqueele(int arr[], int n)
{
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    for(int i=0; i<n; i++)
    {
        if(mp[arr[i]]==1)
        {
            return arr[i];
        }
    }
    return -1;
}

//optimal approach 
int uniqueele2(int arr[], int n)
{
    int ans=0;
    for(int i=0; i<n; i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}

//Non Repeating Numbers (means more than one unique element in array )
vector<int> allunique(int arr[], int n)
{
    unordered_map<int,int>mp;
    vector<int>ans;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    
    for(auto it : mp)
    {
        if(it.second==1)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}

//unique number of occurence 
int uniqueocc(int arr[], int n)
{
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    
    unordered_set<int>st;
    for(auto it : mp)
    {
        st.insert(it.second);
    }
    return st.size()==mp.size();
}

//sum of unique element in array 
int uniqueelesum(int arr[], int n)
{
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    
    int sum=0;
    for(int i=0; i<n; i++)
    {
        if(mp[arr[i]]==1)
        {
            sum+=arr[i];
        }
    }
    return sum;
}

//find duplicate element in array using bruteforce approach
int duplicate(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        int count=0;
        for(int j=i; j<n; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
        if(count==2)
        {
            return arr[i];
        }
    }
    return -1;
}

//better approach 
int duplicateele(int arr[], int n)
{
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    for(int i=0; i<n; i++)
    {
        if(mp[arr[i]]>1)
        {
            return arr[i];
        }
    }
    return -1;
}

//optimal approach 
int duplicateele2(int arr[], int n)
{
    int ans=0;
    for(int i=0; i<n; i++)
    {
        ans=ans^arr[i];
    }
    for(int i=1; i<n; i++)
    {
        ans=ans^i;
    }
    return ans;
}

//find all duplicate element in array using bruteforce approach 
vector<int> allduplicateele(int arr[], int n)
{
    vector<int>ans;
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    for(int i=0; i<n; i++)
    {
        if(mp[arr[i]]>1)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

//optimal approach 
vector<int> allduplicateele2(int arr[], int n)
{
    vector<int>ans;
    for(int i=0; i<n; i++)
    {
        int index=abs(arr[i])-1;
        if(arr[index]<0)
        ans.push_back(abs(arr[i]));
        
        arr[index]*=-1;
    }
    return ans;
}

//contain duplicate (this means if any element in array are duplicate than return true other wise false) brute force approach(n^2) 
//better approach (sorting)
//optimal approach (hashmap)
//contain duplicate --II (given k find the arr[i]==arr[j] and i-j<=k )
//contain duplicate-- III (given k and t find two element abs(arr[j]-arr[j]<=t && abs(i-j)<=k))
// concatenation of array 
//second method
//find the leader of array brute force approach 
vector<int>leadersBruteForce(int arr[], int n) 
{
  vector<int> ans;
  for (int i=0; i<n; i++) 
  {
    bool leader = true;

    //Checking whether arr[i] is greater than all the elements in its right side
    for (int j=i + 1; j<n; j++)
    if (arr[j] > arr[i]) 
    {
        // If any element found is greater than current leader curr element is not the leader.
        leader = false;
        break;
    }

    // Push all the leaders in ans array.
    if (leader)
    ans.push_back(arr[i]);

  }
  return ans;
}

//optimal approach 
vector<int>leader(int arr[], int n)
{
    vector<int>ans;
    
    int index=arr[n-1];
    ans.push_back(arr[n-1]);
    for(int i=n-2; i>=0; i--)
    {
        if(arr[i]>index)
        {
            ans.push_back(arr[i]);
            index=arr[i];
        }
    }
    return ans;
}


//find the equlibrium point 
int equlibrium(int arr[], int n)
{
    int totalsum=0;
    int leftsum=0;
    for(int i=0; i<n; i++)
    {
        totalsum+=arr[i];
    }
    for(int i=0; i<n; i++)
    {
        int rightsum=totalsum-leftsum-arr[i];
        if(leftsum==rightsum)
        {
            return arr[i];
        }
        
        leftsum+=arr[i];
    }
    return -1;
}

//number of steps to reduce a number to zero
//longest subarray of 1's after deleting one element
//max consecutive ones if k number of zero is filp  to one  
//maximum consecutive ones if filp atleast one zero to one 
//maximum consecutive ones  
//number of zero filled subarray 
//nextpermutation of array 
vector<int> nextGreaterPermutation(vector<int> &arr) 
{
    int n = arr.size();

    // Step 1: Find the break point
    int ind = -1;
    for (int i=n-2; i>=0; i--) 
    {
        if (arr[i] < arr[i+1]) 
        {
            // index i is the break point
            ind = i;
            break;
        }
    }

    //If break point does not exist:
    if (ind == -1) 
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    // Step 2: Find the next greater element and swap it with arr[ind]
    for (int i=n-1; i>ind; i--) 
    {
        if (arr[i] > arr[ind]) 
        {
            swap(arr[i], arr[ind]);
            break;
        }
    }

    // Step 3: reverse the right half
    reverse(arr.begin()+ind+1, arr.end());

    return arr;
}

//intersection of two array 
vector<int> intersection(int arr1[], int arr2[], int n, int m)
{
    int i=0;
    int j=0;
    vector<int>ans;
    while(i<n && j<m)
    {
        if(arr1[i]==arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}

//common element 
int common(int arr1[], int arr2[], int arr3[], int n int m, int p)
{
    int i=0;
    int j=0;
    int k=0;
    int ptr1=INT_MIN;
    int ptr2=INT_MIN;
    int ptr3=INT_MIN;
    vector<int>ans;
    while(i<n && j<m)
    {
        while(i<n && arr1[i]==ptr1)
        i++;
        
        while(j<m && arr2[j]==ptr2)
        j++;
        
        while(k<p && arr3[k]==ptr3)
        k++;
        
        if(arr1[i]==arr2[j] && arr2[j]==arr3[k])
        {
            ans.push_back(arr1[i]);
            ptr1=arr1[i];
            ptr2=arr2[j];
            ptr3=arr3[k];
            i++;
            j++;
            k++;
        }
        else if(arr1[i]<arr2[j])
        {
            ptr1=arr1[i];
            i++;
        }
        else if(arr2[j]<arr3[k])
        {
            ptr2=arr2[j];
            j++;
        }
        else
        {
            ptr3=arr3[k];
            k++;
        }
    }
    return ans;
}

//union of two array hashmap 
int union(int arr1[], int arr2[], int n, int m)
{
    vector<int>ans;
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        mp[arr1[i]]++;
    }
    for(int i=0; i<m; i++)
    {
        mp[arr2[i]]++;
    }
    for(auto it : mp)
    {
        ans.push_back(it.first);
    }
    return ans;
}

//using hash set 
int union2(int arr1[], int arr2[], int n, int m)
{
    vector<int>ans;
    unordered_set<int>st;
    for(int i=0; i<n; i++)
    {
        st.insert(arr1[i]);
    }
    for(int i=0; i<m; i++)
    {
        st.insert(arr2[j]);
    }
    for(auto it : st)
    {
        ans.push_back(it);
    }
    return ans;
}

//using two pointer
int union3(int arr1[], int arr2[], int n, int m)
{
    int i=0;
    int j=0;
    vector<int>ans;
    while(i<n && j<m)
    {
        if(arr1[i]<=arr[j])
        {
            if(ans.size()==0 || ans.beck()!=arr1[i])
            {
                ans.push_back(arr1[i]);
                i++;
            }
        }
        else
        {
            if(ans.size()==0 || ans.back()!=arr2[j])
            {
                ans.push_back(arr2[j]);
                j++;
            }
        }
    }
    while(i<n)
    {
        if(ans.back()!=arr1[i])
        {
            ans.push_back(arr1[i]);
            i++;
        }
    }
    while(j<m)
    {
        if(ans.back()!=arr2[j])
        {
            ans.push_back(arr2[j]);
            j++;
        }
    }
}

//valid triangle  bruteforce approach 
int triangle(int arr[], int n)
{
    itn count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if(arr[i]+arr[j]>arr[k] && arr[i]+arr[k]>arr[j] && arr[j]+arr[k]>arr[i])
                {
                    count++;
                }
            }
        }
    }
    return count;
}

//optimal approach 
int triangle2(int arr[], int n)
{
    sort(arr, arr+n);
    itn count=0;
    for(int i=n-1; i>=2; i--)
    {
        itn start=0;
        itn end=i-1;
        while(start<end)
        {
            if(arr[start]+arr[end]>arr[i])
            {
                count+=(end-start);
                end--;
            }
            else
            {
                start++;
            }
        }
    }
    return count;
}

//boat save people 
int boatsave(int arr[], int n, int limit)
{
    sort(arr, arr+n);
    int start=0;
    int end=n-1;
    int count=1;
    while(start<=end)
    {
        if(arr[start]+arr[end]<=limit)
        {
            count++;
            end--;
            start++;
        }
        else
        {
            count++;
            end--;
        }
    }
}

//valid mountain array 
//longest mountain array 
//contain with most water 
//majority element bruteforce approach 
int majority(int arr[], int n)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
        if(count>n/2)
        {
            return arr[i];
        }
    }
    return -1;
}

//better approach 
int majority1(int arr[], int n)
{
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    for(auto it : mp)
    {
        if(it.second>n/2)
        {
            return it.first;
        }
    }
    return -1;
}

//optimal approach 
int majority2(int arr[], int n)
{
    int count=0;
    int el;
    for(int i=0; i<n; i++)
    {
        if(count=0)
        {
            count=1;
            el=arr[i];
        }
        if(el==arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    int count1=0;
    for(int j=0; j<n; j++)
    {
        if(el==arr[j])
        {
            count1++;
        }
    }
    if(count1>n/2)
    {
        return el;
    }
    return -1;
}


//majority-II  bruteforce approach 
vector<int>majorityElement2(vector<int>arr) 
{
    int n = arr.size();
    vector<int>ans;

    for (int i=0; i<n; i++) 
    {
        //selected element is v[i] Checking if v[i] is not already a part of the answer
        if (ans.size() == 0 || ans[0] != arr[i]) 
        {
            int count = 0;
            for (int j=0; j<n; j++) 
            {
                if (arr[j] == arr[i]) 
                {
                    count++;
                }
            }
            
            if (cnt > (n / 3))
            ans.push_back(v[i]);
        }
        
        if(ans.size() == 2) 
        break;
    }
    return ans;
}

//better approach 
int majority22(int arr[], int n)
{
    int count1=0;
    int el1;
    int count2=0;
    int el2;
    for(int i=0; i<n; i++)
    {
        if(count1=0 && el2!=arr[i])
        {
            count1=1;
            el1=arr[i];
        }
        if(count2==0 && el1=arr[i])
        {
            count2=1;
            el2=arr[i];
        }
        if(el1==arr[i])
        {
            coun1++;
        }
        if(el2==arr[i])
        {
            count2++;
        }
        else
        {
            count2--;
            count--;
        }
    }
    
    vector<int>ans;
    int count3=0;
    int count4=0;
    for(int j=0; j<n; j++)
    {
        if(el1==arr[j])
        count3++;
        if(el2==arr[j])
        count4++;
    }
    if(count3>n/3)
    ans.push_back(el1);
    if(count4/3)
    ans.push_back(el2);
    return ans;
}

//optimal approach 
//remove duplicate element 
//second version  
//remove value from array 
//left rotate array by one place bruteforce approach 
void  leftrotate(int arr[], int n)
{
    vector<int>temp; //int temp[n];
    for(int i=1; i<n; i++)
    {
        temp[i-1]=arr[i];
    }
    temp[n-1]=arr[i];
    
    for(int i=0; i<n; i++)
    {
        count<<temp[i]<<" ";
    }
    count<<endl;
}

//optimal approach 
void leftrotateopt(int arr[], int n)
{
    int temp=arr[0];
    
    for(int i=0; i<n; i++)
    {
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    
    for(int i=0; i<n; i++)
    {
        count<<arr[i]<<" ";
    }
    count<<endl;
}

//right rotate array by one place bruteforce approach 
void rightrotate(int arr[], int n)
{
    vector<int>temp;
    for(int i=n-2; i>=0; i--)
    {
        temp[i+1]=arr[i];
    }
    temp[0]=arr[n-1];
    
    for(int i=0; i<n; i++)
    {
        count<<temp[i]<<" ";
    }
    count<<endl;
}

//optimal approach 
void rightrotateopt(int arr[], int n)
{
    int temp=arr[n-1];
    
    for(int i=n-2; i>=0; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=temp;
    
    for(int i=0; i<n; i++)
    {
        count<<arr[i]<<" ";
    }
    count<<endl;
}

//left rotate array by d place bruteforce approach 
void leftrotatebyd(int arr[], int n, int d)
{
    //vector<int>temp;
    if (n == 0)
    return;
    
    d=d%n;
    if (d > n)
    return;
    
    int temp[d];
    for(int i=0; i<d; i++)
    {
        temp[i]=arr[i];
        //temp.push_back(arr[i]);
    }
    
    for(int i=0; i<n-d; i++)
    {
        arr[i]=arr[i+d];
    }
    
    for(int i=n-d; i<n; i++)
    {
        arr[i]=temp[i-n+d];
    }
}

//optimal approach 
void leftrotatebydopt(int arr[], int n, int d)
{
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}

//right rotate array by d place bruteforce approach 
int rightrotatebyd(int arr[], int n, int d)
{
    //vector<int>temp;
    
    if (n == 0)
    return;
    
    d = d % n;
    if (d > n)
    return;
    
    int temp[d];
    for(int i=n-d; i<n; i++)
    {
        temp[i-n+d]=arr[i];
        //temp.push_back(arr[i]);
    }
    
    for(int i=n-d; i>=0; i--)
    {
        arr[i+d]=arr[i];
    }
    
    
    for(int i=0; i<d; i++)
    {
        arr[i]=temp[i];
    }
}

//optimal approach 
void rightrotatebydopt(int arr[], int n, int d)
{
    reverse(arr, arr+n-d-1);
    reverse(arr+n-d, arr+n-1);
    reverse(arr, arr+n);
}

//squares of a sorted array bruteforce approach 
//optimal approach 
//product of itself bruteforce approach  
//better approach  
//optimal approach 
//count pairs whose sum is less than target 
//optimal approach (using sorting and two pointer)
//max number of K-sum pairs bruteforce approach (in this problem deleting pair )
//better approach 
//optimal approach
//two sum II - input array is sorted 
//count number of pairs with absolute difference K
//optimal approach 
//count good meals (adding two element in array than equal to power of two)
//number of pairs of strings with concatenation equal to target
//optimal approach
//two sum bruteforce approach (version-1)
string twosum(int arr[], int n, int target)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]+arr[j]==target)
            {
                return "YES";
            }
        }
    }
    return "NO";
}

//optimal approach 
string twoSum(int n, vector<int> &arr, int target) 
{
    unordered_map<int, int>mp;
    for (int i=0; i<n; i++) 
    {
        if(mp.find(mp[target-arr[i]]) != mp.end()) 
        {
            return "YES";
        }
        
        mp[num] = i;
    }
    return "NO";
}

//two sum bruteforce approach (version-2)
vector<int>twosum2(vector<int>&arr int n, int target)
{
    vector<int>ans;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if (arr[i] + arr[j] == target) 
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return {-1,-1};
}

//optimal approach 
vector<int> twosumopt(int arr[], int n, int target)
{
    vector<int>ans;
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        if(mp.find(target-arr[i])!=mp.end())
        {
            ans.push_back(mp[target-arr[i]]);
            ans.push_back(i);
            return ans;
        }
        
        mp[arr[i]]=i;
    }
    return {-1,-1};
}

//three sum bruteforce approach 
vector<vector<int>> threesum(int arr[], int n, int target)
{
    set<vector<int>>st;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if(arr[i]+arr[j]+arr[k]==target)
                {
                    vector<int>temp=({arr[i], arr[j], arr[k]});
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    
    //store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//better approach 
vector<vector<int>>threesumbett(vector<int> &arr, int n, int target) 
{
    set<vector<int>> st;

    for (int i=0; i<n; i++) 
    {
        set<int> hashset;
        for (int j=i+1; j<n; j++) 
        {
            //Calculate the 3rd element
            int third = target-(arr[i] + arr[j]);
            
            //Find the element in the set
            if (hashset.find(third) != hashset.end()) 
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//optimal approach 
vector<vector<int>> threesumopt(int arr[], int n, int target)
{
    vector<vector<int>>ans;
    sort(arr, arr+n);
    for(int i=0; i<n-1; i++)
    {
        if(i!=0 && arr[i]!=arr[i-1])
        continue;
        
        int start=i+1;
        int end=n-1;
        int sum=target-arr[i];
        
        while(start<end)
        {
            if(arr[start]+arr[end]==sum)
            {
                vector<int>temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[start]);
                temp.push_back(arr[end]);
                ans.push_back(temp);
                start++;
                end--;
                
                while(start<end && arr[start]==arr[start-1])
                start++;
                
                while(start<end && arr[end]==arr[end+1])
                end--;
            }
            else if(arr[start]+arr[end]>sum)
            {
                end--;
            }
            else 
            {
                start++;
            }
        }
    }
    return ans;
}

//four sum bruteforce approach 
vector<vector<int>> foursum(int arr[], int n, int target)
{
    vector<vector<int>>ans;
    set<vector<int>> st;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                for(int p=k+1; p<n; p++)
                {
                    if(arr[i]+arr[j]+arr[k]+arr[p]==target)
                    {
                        vector<int>temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[k]);
                        temp.push_back(arr[p]);
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    ans.push_back(st.begin(), ans.end());
    return ans;
}
//better approach 
vector<vector<int>> fourSumbetter(vector<int>& nums, int target, int n) 
{
    set<vector<int>>st;

    for (int i=0; i<n; i++) 
    {
        for (int j=i + 1; j<n; j++) 
        {
            set<long long> hashset;
            for (int k=j + 1; k<n; k++) 
            {
                // taking bigger data type to avoid integer overflow
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) 
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                // put the kth element into the hashset
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//optimal approach 
vector<vector<int>> foursumopt(int arr[], int , int target)
{
    vector<vector<int>>ans;
    sort(arr, arr+n);
    for(int i=0; i<n; i++)
    {
        if(i>0 && arr[i]!=arr[i-1])
        continue;
        
        for(int j=i; j<n-2; j++)
        {
            if(j!=i+1 && arr[j]==arr[j-1])
            continue;
            
            int start=j+1;
            int end=n-1;
            int sum=target-(arr[i]+arr[j]);
            
            while(start<end)
            {
                if(arr[start]+arr[end]==sum)
                {
                    vector<int>temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[start]);
                    temp.push_back(arr[end]);
                    ans.push_back(temp);
                    start++;
                    end--;
                    
                    while(start<end && arr[start]==arr[start-1])
                    start++;
                    
                    while(start<end && arr[end]==arr[end+1])
                    end--;
                }
                else if(arr[start]+arr[end]>sum)
                {
                    end--;
                }
                else 
                {
                    start++;
                }
            }
        }
        
    }
    return ans;
}

//four-II sum bruteforce approach 
int foursum2(int arr1[], int arr2[]  itn arr3[], int arr4[], int n)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                for(int p=0; p<n; p++)
                {
                    if(arr1[i]+arr2[j]+arr3[k]+arr4[k]==0)
                    {
                        count++;;
                    }
                }
            }
        }
    }
    return count;
}


//optimal approach
int foursum22(int arr1[], int arr2[]  itn arr3[], int arr4[], int n)
{
    unordered_map<int,int>mp;
    for(auto l : arr3)
    {
        for(auto m : arr4)
        {
            mp[l+m]++;
        }
    }
    int conunt=0;
    for(auto i : arr2)
    {
        for(auto j : arr1)
        {
            count+=0-mp[j-i];
        }
    }
    return count;
}

//maximum contigous subarray sum bruteforce approach 
int maxisubarrsum(int arr[], int n)
{
    int maxi=INT_MIN;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int sum=0;
            for(int k=i; k<=j; k++)
            {
                sum+=arr[k];
            }
            maxi=max(maxi, sum);
        }
    }
    return maxi;
}

//better approach
int maxisubarrsum2(int arr[], int n)
{
    int maxi=INT_MIN;
    for(int i=0; i<n; i++)
    {
        int sum=0;
        for(int j=i; j<n; j++)
        {
            sum+=arr[j];
            maxi=max(maxi, sum);
        }
    }
    return maxi;
}

//optimal approach
int maxisubarrsum(int arr[], int n)
{
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        maxi=max(maxi, sum);
        if(sum<0)
        {
            sum=0;
        }
    }
    return maxi;
}

//print all maximum subarray sum 
int maxSubarraySum(int arr[], int n) 
{
    int maxi = INT_MIN;
    int sum = 0;

    int start = 0;
    int ansStart = -1, 
    int ansEnd = -1;
    for (int i=0; i<n; i++) 
    {
        if (sum == 0) 
        start = i;
        
        sum +=arr[i];
        
        if (sum>maxi) 
        {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        
        if (sum < 0) 
        {
            sum = 0;
        }
    }

    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    return maxi;
}

//maximum product of subarray bruteforce approach
int maxisubarrPor(int arr[], int n)
{
    int maxi=INT_MIN;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int prod=1;
            for(int k=i; k<=j; k++)
            {
                prod*=arr[k];
            }
            maxi=max(maxi, prod);
        }
    }
    return maxi;
}

//better approach
int maxisubarrPor1(int arr[], int n)
{
    int maxi=INT_MIN;
    for(int i=0; i<n; i++)
    {
        int prod=1;
        for(int j=i; j<n; j++)
        {
            prod*=arr[i];
            maxi=max(maxi, prod);
        }
    }
    return maxi;
}

//optimal approach
int maxisubarrPor2(int arr[], int n)
{
    int maxi=INT_MIN;
    int prod=1;
    for(int i=0; i<n; i++)
    {
        prod*=arr[i];
        maxi=max(maxi, prod);
        if(prod==0)
        {
            prod=1;
        }
    }
    prod=1;
    for(int i=n-1; i>=0; i--)
    {
        prod*=arr[i];
        maxi=max(maxi, prod);
        if(prod==0)
        {
            prod=1;
        }
    }
    return maxi;
}
--or-- 
int maxisubarrprodopt(int arr[], int n)
{
    int pre=1;
    int suff=1;
    
    int ans=INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(pre==0)
        pre=1;
        
        if(suff==0)
        suff=1;
        
        pre*=arr[i];
        suff*=arr[n-i-1];
        
        ans=max(ans, max(pre, suff));
    }
    return ans;
}


//maximum sum equal k bruteforce approach
int maxisubarrK(int arr[], int n, int k)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int sum=0;
            for(int k=i; k<=j; k++)
            {
                sum+=arr[k];
            }
            if(sum==k)
            {
                count++;
            }
        }
    }
    return count;
}

//better approach
int maxisubarrK1(int arr[], int n)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        int sum=0;
        for(int j=i; j<n; j++)
        {
            sum+=arr[j];
            if(sum==k)
            {
                count++;
            }
        }
    }
    return count;
}

//optimal approach
int maxisubarrK2(int arr[], int n, int k)
{
    int count=0;
    int sum=0;
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        if(sum==k)
        {
            count++;
        }
        if(mp.find(sum-k)!=mp.end())
        {
            count+=mp[sum-k];
        }
        if(mp.find(sum)==mp.end())
        {
            mp[sum]++;
        }
        else
        {
            mp[sum]=1;
        }
    }
    return count;
}

//longest sum subarray equal k bruteforce approach 
int longestsubarrsum(int arr[], int n, int k)
{
    int maxlen=INT_MIN;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int sum=0;
            for(int k=i; k<=j; k++)
            {
                arr+=arr[k];
            }
            if(sum==k)
            {
                maxlen=max(maxlen, j-i+1);
            }
        }
    }
    return maxlen;
}

//better approach 
int longestsubarrsum1(int arr[], int n, int k)
{
    int maxlen=INT_MIN;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            sum+=arr[i];
            if(sum==k)
            {
                maxlen=max(maxlen, j-i+1);
            }    
        }
    }
    return maxlen;
}

//optimal approach
int longestsubarrsum2(int arr[], int n, int k)
{
    int start=0;
    int end=0;
    int sum=arr[0];
    int maxlen=0;
    while(end<n)
    {
        end++;
        if(end<n)
        {
            sum+=arr[end];
        }
        while(start<=end && sum>k)
        {
            sum-=arr[start];
            start++;
        }
        if(sum==k)
        {
            maxlen=max(maxlen, end-start+1);
        }
    }
    return maxlen;
}

//minimum size subarray sum target bruteforce 
//optimal approach  
//sliding window maximum bruteforce approach 
//optimal approach 
//subarray product less than k 
//sorted unsorted continuous subarray 
//traping rain water bruteforce approach 
//better approach 
//optimal approach 
//merge interval bruteforce approach 
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) 
{
    int n = arr.size();

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++) 
    {
        int start = arr[i][0];
        int end = arr[i][1];

        //Skip all the merged intervals
        if (!ans.empty() && end <= ans.back()[1]) 
        {
            continue;
        }
        
        for(int j=i+1; j<n; j++) 
        {
            if(arr[j][0] <= end) 
            {
                end = max(end, arr[j][1]);
            }
            else 
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

//optimal approach 
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) 
{
    int n = arr.size(); 
    
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++) 
    {
        // if the current interval does not lie in the last interval
        if (ans.empty() || arr[i][0] > ans.back()[1]) 
        {
            ans.push_back(arr[i]);
        }
        
        // if the current interval lies in the last interval
        else 
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

//insert interval
vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) 
{
    if(interval.size()==0)
    return newInterval;
    
    vector<vector<int>>ans;
    for(auto it : interval)
    {
        if(it[1]<newInterval[0]) //non overlaping case 
        {
            ans.push_back(it);
        }
        else if(it[0]>newInterval[1]) //this means new interval will be greater than first than newInterval will be store first than 
        {
            ans.push_back(newInterval);
            newInterval=it;
        }
        else   //overlaping case 
        {
            newInterval[0]=min(newInterval[0], it[0]);
            newInterval[1]=max(newInterval[1], it[1]);
        }
    }
    ans.push_back(newInterval);
    return ans;
}

//non overlaping interval (count how mant interval are delete to make non overlap)
int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());
    int pre=0;
    int ans=0;
    for(int i=1; i<intervals.size(); i++)
    {
        if(intervals[i][0]<intervals[pre][1]) //overlaping case 
        {
            ans++;
            if(intervals[i][1]<=intervals[pre][1]) //this means delete intervals which one   (1,5) (2,3) than delete (1,5)
            {
                pre=curr;
            }
        }
        else 
        {
            pre=curr;
        }
    }
    return ans;
}

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
//count the number of subarrays with given xor K bruteforce approach
int subarraysWithXorK(vector<int>arr, int k) 
{
    int n = arr.size();
    int count = 0;

    for(int i=0; i<n; i++) 
    {
        for (int j=i; j<n; j++) 
        {
            int xorr = 0;
            for (int p=i; p<=j; p++) 
            {
                xorr=xorr^ arr[p];
            }
            
            if (xorr == k) 
            count++;
        }
    }
    return count;
}

//better approach 
int subarraysWithXorK(vector<int>arr, int k) 
{
    int n = arr.size();
    int count = 0;

    for(int i=0; i<n; i++) 
    {
        int xorr=0;
        for (int j=i; j<n; j++) 
        {
            xorr=xorr^arr[j];
            
            if (xorr == k) 
            count++;
        }
    }
    return count;
}

//optimal approach 
int subarraysWithXorK(vector<int>rra, int k) 
{
    int n=arr.size();
    int xr = 0;
    map<int, int>mp;
    mp[xr]++; 
    int count = 0;

    for (int i=0; i<n; i++) 
    {
        xr = xr^ a[i];
        
        int x =xr^ k;
        
        cnt += mp[x];
        
        mp[xr]++;
    }
    return count;
}


//longest consecutive sequence in an array brute force approach
bool linearSearch(vector<int>&arr, int num) 
{
    int n = arr.size();
    for(int i=0; i<n; i++) 
    {
        if (arr[i] == num)
        return true;
    }
    return false;
}
int longestconsecsequence(vector<int>&arr) 
{
    int n = arr.size();
    int longest = 1;
    
    for (int i=0; i<n; i++) 
    {
        int x = arr[i];
        int count = 1;
        
        //search for consecutive numbers using linear search
        while (linearSearch(arr, x + 1) == true) 
        {
            x += 1;
            count += 1;
        }
        
        longest = max(longest, count);
    }
    return longest;
}

//better approach
int longestconsecsequencebett(vector<int>&arr) 
{
    int n = arr.size();
    
    if (n == 0) 
    return 0;

    sort(arr.begin(), arr.end());
    
    int lastSmaller = INT_MIN;
    int count = 0;
    int longest = 1;

    for(int i=0; i<n; i++) 
    {
        if(arr[i] - 1 == lastSmaller) 
        {
            //arr[i] is the next element of the current sequence.
            count += 1;
            lastSmaller = arr[i];
        }
        else if(arr[i] != lastSmaller) 
        {
            count = 1;
            lastSmaller = arr[i];
        }
        
        longest = max(longest, count);
    }
    return longest;

}

//optimal approach 
int longestconsecsequenceopt(vector<int>&arr) 
{
    int n = arr.size();
    
    if (n == 0) 
    return 0;

    int longest = 1;
    unordered_set<int> st;
    
    for (int i=0; i<n; i++) 
    {
        st.insert(arr[i]);
    }

    for (auto it : st) 
    {
        //if 'it' is a starting number
        if (st.find(it - 1) == st.end()) 
        {
            //find consecutive numbers
            int count = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) 
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}


//length of the longest subarray with zero Sum
int maxLen(int arr[], int n)
{
    unordered_map<int,int> mp; 
    int maxi = 0;
    int sum = 0; 
    for(int i=0; i<n; i++) 
    {
        sum += arr[i]; 
        if(sum == 0) 
        {
            maxi = i + 1; 
        }
        else 
        {
            if(mp.find(sum) != mpp.end()) 
            {
                maxi = max(maxi, i-mp[sum]); 
            }
            else 
            {
                mp[sum] = i;
            }
        }   
    }

    return maxi; 
}

//count inversion bruteforce approach 
int numberOfInversions(vector<int>&arr, int n) 
{
    int count=0;
    for(int i=0; i<n; i++) 
    {
        for(int j=i+1; j<n; j++) 
        {
            if(arr[i] > arr[j]) 
            count++;
        }
    }
    return count;
}

//optimal approach 
int merge(vector<int> &arr, int start, int mid, int end) 
{
    vector<int> temp;
    int left = start;
    int right = mid + 1;

    int count = 0;

    while (left<=mid && right<=end) 
    {
        if (arr[left]<=arr[right]) 
        {
            temp.push_back(arr[left]);
            left++;
        }
        else 
        {
            temp.push_back(arr[right]);
            count +=(mid - left + 1); 
            right++;
        }
    }

    while (left <= mid) 
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= end) 
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=start; i<=end; i++) 
    {
        arr[i] = temp[i-start];
    }

    return count;
}

int mergeSort(vector<int> &arr, int start, int end) 
{
    int count = 0;
    if (start>=end) 
    return count;
    
    int mid = (start+ end)/2 ;
    count += mergeSort(arr, start, mid); 
    count += mergeSort(arr, mid + 1, end);
    count += merge(arr, start, mid, end); 
    
    return count;
}

int countInversions(vector<int>&arr, int n) 
{
    return mergeSort(arr, 0, n - 1);
}



//---------------------------------------------------------------------------------------------------------------
//linear search 
int linearsearch(int arr[], int n, int target)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]==target)
        {
            return i;
        }
    }
    return -1;
}

//binary search
int binarysearch(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]<target)
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

//order agnostic binary search 
int agonbinarysearch(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]<target)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return -1;
}

//first occurence of target 
int firstocc(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
        {
            ans=mid;
            end=mid-1;
        }
        else if(arr[mid]<target)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return ans;
}

//last occurence of target 
int lastocc(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
        {
            ans=mid;
            start=mid+1;
        }
        else if(arr[mid]<target)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return ans;
}

//lowerbound of target 
int lowerbound(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    int ans=n;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]>=target)
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
}

//upperbound of target 
int upperbound(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    int ans=n;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]>target)
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return -1;
}

//celi value of target
int celivalue(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]>=target)
        {
            ans=arr[mid];
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
}

//floor value of target 
int floorvalue(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]<=target)
        {
            ans=arr[mid];
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return ans;
}

//find the minimum element in sorted rotated array
int minimumelerotated(int arr[], int n)
{
    int start=0;
    int end=n-1;
    while(start<end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]<arr[end])
        {
            end=mid;
        }
        else
        {
            satrt=mid+1;
        }
    }
    return start;
}

//second version of minimum element 
int minimumelerotated2(int arr[], int n)
{
    int start=0;
    int end=n-1;
    while(start<end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]<arr[end])
        {
            end=mid;
        }
        else if(arr[mid]>arr[end])
        {
            satrt=mid+1;
        }
        else
        {
            end--;
        }
    }
    return end;
}

//search element in rotated sorted array 
int searchrotated(int arr[], int n, target)
{
    int start=0;
    int end=n-1;
    while(start<end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        if(arr[start]<=arr[mid])
        {
            if(target>=arr[start] && target<=arr[mid])
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        else
        {
            if(target>=arr[mid] && target<=arr[end])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
    }
    return -1;
}
 
//second version of search 
bool searchrotated2(int arr[], int n, target)
{
    int start=0;
    int end=n-1;
    while(start<end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
        {
            return true;
        }
        if(arr[mid]==arr[start] && arr[end]==arr[mid])
        {
            start++;
            end--;
            continue ;
        }
        if(arr[start]<=arr[mid])
        {
            if(target>=arr[start] && target<=arr[mid])
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        else
        {
            if(target>=arr[mid] && target<=arr[end])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
    }
    return false;
}

//find the square root of element 
//find the peak element 
int peak(int arr[], int n)
{
    int start=0;
    intend=mid-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]>arr[mid+1])
        {
            end=mid;
        }
        else
        {
            start=mid+1;
        }
    }
    return start;
}

//find position of an element in a sorted array of infinte number 
int infinite(int arr[], int target)
{
    int start=0;
    int end=1;
    while(end<target)
    {
        int newstart=end;
        end=end+(end-start+1)*2;
        start=newstart;
    }
    return binaray(arr, start, end, target);
}


//search insert position 
int searchinsert(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    int ans=n;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]>=target)
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
}

//guess number 
//Koko Eating Bananas
int maxi(int arr[], int n)
{
    int maxi=arr[0];
    for(int i=0; i<n; i++)
    {
        if(arr[i]>maxi)
        {
            maxi=arr[i];
        }
    }
    return maxi;
}
int calculateHour(int arr[], int hourly)
{
    int totalhours=0;
    int n=arr.size();
    for(int i=0; i<n; i++)
    {
        totalhours+=ceil((double)(v[i]) / (double)(hourly))
    }
    return totalhours;
}
int miniratetoeatbanana(int arr[], int n, int h) //where h is number of hour given 
{
    int start=1;
    int end=maxi(arr,n);
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(calculateHour(arr, mid)<=h)  //if number of hour is more than given hour 
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return start;
}


//Minimum days to make M bouquets
bool ispossible(vector<int>&arr, int day , int m, int k)
{
    int n=arr.size();
    int count=0;
    int noofbouquets=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]<=day)
        {
            count++;
        }
        else
        {
            noofbouquets+=(count/k);
            count=0;
        }
    }
    noofbouquets+=(count/k);
    return noofbouquets>=m;
}
int minDays(vector<int>& bloomDay, int m, int k) //where k is number of adjacent flower and m is bouquests
{
    int n=bloomDay.size();
    //special case 
    if(m*k>n)
    return -1;
    
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=0; i<n; i++)
    {
        mini=min(mini, bloomDay[i]);
        maxi=max(maxi, bloomDay[i]);
    }
    int start=mini;
    int end=maxi;
    while(start<=end)
    {
        int mid=start=(end-start)/2;
        if(ispossible(bloomDay, mid, m, k))
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return start;
}

//Find the Smallest Divisor Given a Threshold
int SumbyD(vector<int>&arr, int divi)
{
    int n=arr.size();
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}
int Smallestdivisor(vector<int>&arr, int limit)
{
    int n=arr.size();
    //special case
    if(n>limit)
    return -1;
    
    int start=1;
    int end=*max_element(arr.begin(), arr.end());
    while(start<=end)
    {
        int mid=start+(end-satrt)/2;
        if(SumbyD(arr, mid)<=limit)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return start;
}

//Capacity to Ship Packages within D Days
int FindDay(vector<int>&arr, int cap)
{
    int n=arr.size();
    int load=0;
    int day=1;
    for(int i=0; i<n; i++)
    {
        if(load+arr[i]>cap)
        {
            day+=1;
            load=arr[i];
        }
        else
        {
            load+=arr[i];
        }
    }
    return day;
    
}
int leastWeightCapacity(vector<int> &weight, int day) 
{
    
    int start = *max_element(weights.begin(), weights.end());
    int end = accumulate(weights.begin(), weights.end(), 0);
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(FindDay(weight, mid)<=day)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return start;
}

//book allocation problem 
int Numberofstu(int arr[], int page)
{
    int student=1;
    int pageSum=0;
    for(int i=0; i<arr.size(); i++)
    {
        if(pageSum+arr[i]<=page)
        {
            pageSum+=arr[i];
        }
        else
        {
            student+=1;
            pageSum=arr[i];
        }
    }
    return student;
}
int bookallocation(int arr[], int n1, int , int m) //where n is number of page and m is number of student
{
    int start=*max_element(arr, arr+n);   //maximum element 
    int end=accumulate(arr, arr+n, 0); //sum of array 
    while(satrt<=end)
    {
        int mid=start=(end-start)/2;
        if(Numberofstu(arr,mid)>m)  //if the function gives noumber of student greater than given student than 
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return start;
}

//Aggressive cow problem 
bool Canbeplace(vector<int>&arr, int dist, int cow)
{
    int n=arr.size();
    int cntCows = 1; //no. of cows placed
    int last = arr[0]; //position of last placed cow
    for(int i=0; i<n; i++)
    {
        if(arr[i]-last>=dist)
        {
            cntCows++;
            last=arr[i];
        }
        if(cntCows>=cow)
        {
            return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int>&stall, int k)
{
    int n=stall.size();
    int start=1;
    int end=stall[n-1]-stall[0];
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(Canbeplace(stall, mid, k))
        {
            start=mid+1;;
        }
        else
        {
            end=mid-1;
        }
    }
    return start;
}

//painter partition problem
int Numberpainter(int arr[], int timet)
{
    int painter=1;
    int areasum=0;
    for(int i=0; i<arr.size(); i++)
    {
        if(areasum+arr[i]<=timet)
        {
            areasum+=arr[i];
        }
        else
        {
            painter++;
            areasum=arr[i];
        }
    }
    return painter;
}
int paintspartition(int arr[], int n, int k)  //where k is number of painter
{
    int start=*max_element(arr, arr+n);
    int end=accumulate(arr, arr+n, 0);
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(Numberpainter(arr, mid)>k)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return start;
}

//split array largest sum 
int Countpartition(int arr[], int maxsum)
{
    int partition=1;
    int subarraysum=0;
    for(int i=0; i<arr.size(); i++)
    {
        if(subarraysum+arr[i]<=maxsum)
        {
            subarraysum+=arr[i];
        }
        else
        {
            partition+=1;
            subarraysum=arr[i];
        }
    }
    return partition;
}
int splitlargestsum(int arr[], int n, int k) //where k is number of subarray where array will be divided 
{
    int start=*max_element(arr, arr+n);
    int end=accumulate(arr, arr+n, 0);
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(Countpartition(arr, mid)>k)  //if the partition of array more than given value than 
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return start;
}


//--------------------------------------------------------------------------------------------------------
//cyclic sort
void cyclicsort(int arr[], int n)
{
    int i=0;
    while(i<n)
    {
        int correct=arr[i]-1;
        if(arr[i]<n &&arr[i]!=arr[correct])
        {
            swap(arr[i], arr[correct]);
        }
        else
        {
            i++;
        }
    }
}


//find missing number
int missingNum(int arr[], int n)
{
    int i=0;
    while(i<n)
    {
        int correct=arr[i]-1;
        if(arr[i]<n &&arr[i]!=arr[correct])
        {
            swap(arr[i], arr[correct]);
        }
        else
        {
            i++;
        }
    }
    
    for(int index=0; index<n; index++)
    {
        if(arr[index]!=index+1)
        {
            return index+1;
        }
    }
    return n;
}

//find all disappeared in array 
int disappeared(int arr[], int n)
{
    int i=0;
    while(i<n)
    {
        int correct=arr[i]-1;
        if(arr[i]!=arr[correct])
        {
            swap(arr[i], arr[correct]);
        }
        else
        {
            i++;
        }
    }
    vector<int>ans;
    for(int index=0; index<n; index++)
    {
        if(arr[index]!=index+1)
        {
            ans.push_back(index+1);
        }
    }
    return n;
}


//first missing positive number 
int missingPos(int arr[], int n)
{
    int i=0;
    while(i<n)
    {
        int correct=arr[i]-1;
        if(arr[i]>0 && arr[i]<=n &&arr[i]!=arr[correct])
        {
            swap(arr[i], arr[correct]);
        }
        else
        {
            i++;
        }
    }

    for(int index=0; index<n; index++)
    {
        if(arr[index]!=index+1)
        {
            return index+1;
        }
    }
    return n;
}



//setmismatch 
int setmismatch(int arr[], int n)
{
    int i=0;
    while(i<n)
    {
        int correct=arr[i]-1;
        if(arr[i]!=arr[correct])
        {
            swap(arr[i], arr[correct]);
        }
        else
        {
            i++;
        }
    }
    vector<int>ans;
    for(int index=0; index<n; index++)
    {
        if(arr[index]!=index+1)
        {
            ans.push_back(index+1);
            ans.push_back(index);
        }
    }
    return ans;
}

//-----------------------------------------------------------------------------------------------------------------------------
//print linked list 
//length of linked list 
//binary of linked list 
//reverse linked list using stack 
//reverse linked list recursive method 
//reverse linked list iterative method 
//reverse linked list in k group 
//middle of linked list 
//2-method to find the middle element in list  
//cyclic in linked list  
//find the starting point of loop 
//remove loop from linked list 
//remove duplicate from sorted linked list using recursive method 
//remove duplicate from sorted linked list using iterative method 
//remove duplicate from unsorted linked list 
//palindrome linked list 
//merge linked list 
//second method to merge linked list 
//merge k linked list 
//second method to merge k linked list 
//intersection of linked list 
//second method to find intersection of linked list 
//odd or even linked list 
//second method  to find odd and even linked list 
//delete node where head or not given 
//check two linked list are identical or not 
// Nth node from end of linked list 
//swap node pairwise 
//swap node kth from starting and kth from end in linked list 
//2-method 
//add two linked list 
//second version 
//sort linked list 
//rotate linked list 
//Partition linked List 
//reorder linked list 
//insertion sort in linked list
//sort 0s 1s 2s linked list  
//flattening of linked list 
//reverse doubly linked list using stack 
//iterative approach 



//-------------------------------------------------------------------------------------------- 
//reverse string using stack 
//delete middle element in stack 
//valid parenthesis  {([])
//insertatbottom in stack 
//reverse stack 
//sort stack 
//redundant bracket (-,+,/ ,*)
//Minimum cost to make valid string {
//Minimum Number of Swaps to Make the String Balanced  ]][[[]]][[
//132 pattern bruteforce approach 
//better approach 
//optimal approach 
//next smaller element in array 
//previous smaller element int array 
//next greater element in array 
//previous greater element in array 
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
//number is power of two or not
//number is power of three or not 
//number is power of four or not 
//kid with the greatest number of candies (given array of candies and int extracandies return bool of vector ) 
//running sum of 1d array (this means prefix of sum ) 1,2,3,4 == 1,3,6,10
//number of good pair 
//optimal approach 
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

//preorder traversal using recursive
void preorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

//iterative method of preorder traversal 
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

//inorder traversal using recursive 
void inorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

//iterative method to inorder traversal 
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


//postorder traversal using recursive 
void postorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}

//iterative method to postorder traversal using 2 stack
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

//using single stack 
vector<int>postorder(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    stack<TreeNode*>st;
    TreeNode*curr=root;
    while(!st.empty() && curr!=NULL)
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
            curr=temp;
        }
    }
    return ans;
}

//all preoder , inorder and postorder traversal in single iteration
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

//maximum depth of binary tree using recursion
int maximumdepth(Node*root)
{
    if(root==NULL)
    return 0;
    
    int lh=maximumdepth(root->left);
    int rh=maximumdepth(root->right);
    
    return 1+max(lh, rh);
}

//using level order 
//check for balance binary tree 
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

//level order successor of a node in binary tree(successor means given a key value find the right value of given key)
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

//maximum level sum of a binary tree
//Kth largest sum in a binary tree 
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

//find bottom left tree value
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

//construct binary tree from preorder and inorder
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

//count total node in a complete binary tree 
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

//lowest common ancestor of binary tree 
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

//minimum number of operations to sort a binary tree by level (2471)
//cousins of binary tree
//verical order traversal
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

//top view of binary tree 
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

//print root to node path in binary tree 

//maximum width of binary tree
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

//children sum property in binary tree 
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

//print all the node at a distance k in binary tree
//minimum time taken to burn the binary tree from a node
//populating next right pointers in each node 



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









   