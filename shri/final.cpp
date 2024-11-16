#include<bits/stdc++.h>
using namespace std;


//reverse array using inbuilt function
void reverse1(int arr[], int n)
{
    reverse(arr, arr+n);
}

//reverse array 
void reverse(int arr[], int n)
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
void reversepair(int arr[], int n)
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
void reverseksize(int arr[], int n, int k)
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
int reverseinteger(int n)
{
    int ans=0;
    while(n!=0)
    {
        ans=ans*10+n%10;
        n=n/10;
    }
    return ans;
}

//check array are palindrome or not
bool palindrome(int arr[], int n)
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
void 012sort(int arr[], int n)
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
            count2--;
        }
    }
    
    for(int i=0; i<count0; i++)
    arr[i]=0;
    
    for(int i=count0; i<count0+count1; i++)
    arr[i]=1;
    
    for(int i=count0+count1; i<n; i++)
    arr[i]=2;
}

//dnf sort 
void dnfsort(int arr[], int n)
{
    int start=0;
    int mid=0;
    int end=n-1;
    while(mid<=end)
    {
        if(arr[mid]==0)
        {
            swap(arr[start], arr[mid]);
            start++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else 
        {
            swap(arr[mid], arr[end]);
            end--;
        }
    }
}

//three way partition of array 
void threeway(int arr[], int n, int a, int b)
{
    int start=0;
    int mid=0;
    int end=n-1;
    while(mid<=end)
    {
        if(arr[mid]<a)
        {
            swap(arr[start], arr[mid]);
            start++;
            mid++;
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
int minimum(int arr[], int n)
{
    sort(arr, arr+n);
    return arr[0];
}

//optimal approach 
int minimumopt(int arr[], int n)
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
int maximum(int arr[], int n)
{
    sort(arr, arr+n);
    return arr[n-1];
}

//optimal approach
int maximumopt(int arr[], int n)
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
int secondlargest(int arr[], int n)
{
    if(n==0 || n==1)
    return -1; 
    
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
int secondlargestopt(int arr[], int n)
{
    if(n==0 || n==1)
    return -1; 
    
    int largest=arr[0];
    int sec=INT_MIN;
    for(int i=1; i<n; i++)
    {
        if(arr[i]>largest)
        {
            sec=largest;
            largest=arr[i];
        }
        
        if(largest>arr[i] && arr[i]>largest)
        {
            sec=arr[i];
        }
    }
    return sec;
}

//second smallest element in array bruteforce approach 
int secondsmallest(int arr[], int n)
{
    if(n==0 || n==1)
    return -1;
    
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
int secondsmallestopt(int arr[], int n)
{
    if(n==0 || n==1)
    return -1;
    
    int small=arr[0];
    int sec=INT_MAX;
    for(int i=1; i<n; i++)
    {
        if(arr[i]<small)
        {
            sec=small;
            small=arr[i];
        }
        
        else if(small!=arr[i] && arr[i]<small)
        {
            sec=arr[i];
        }
    }
    return sec;
}

//find the kthsmallest element in array 
//find the kthlargest element in array 
//Find the Kth Largest Integer in the Array
//third largest element in array 
//monotonic array (An array is monotonic if it is either monotone increasing or monotone decreasing.)
//find unique element in array bruteforce approach
int unique(int arr[], int n)
{
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    
    for(auto it : mp)
    {
        if(it.second==1)
        {
            return it.first;
        }
    }
    return -1;
}

//optimal approach
int uniqueopt(int arr[], int n)
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
    return mp.size()==st.size();
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
    for(auto it : mp)
    {
        if(it.second==1)
        {
            sum+=it.first;
        }
    }
    return sum;
}

//find duplicate element in array using bruteforce approach 
int duplicate(int arr[], int n)
{
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    
    for(auto it : mp)
    {
        if(it.second>1)
        {
            return it.first;
        }
    }
    return -1;
}

//optimal approach 
int duplicateopt(int arr[] , int n)
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
vector<int> allduplicate(int arr[], int n)
{
    unordered_map<int,int>mp;
    vector<int>ans;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    
    for(auto it : mp)
    {
        if(it.second>1)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}

//optimal approach 
vector<int> allduplicateopt(int arr[], int n)
{
    vector<int>ans;
    
    for(int i=0; i<n; i++)
    {
       int index=abs(arr[i])-1; 
       if(arr[index]<0)
       {
           ans.push_back(abs(arr[i]));
       }
       
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
int findequlibrium(int arr[], int n)
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
vector<int>intersection(int arr1[], int arr2[], int n, int m)
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
vector<int>common(int arr1[], int arr2[], int arr3[], int n, int m, int p)
{
    int i=0;
    int j=0;
    int k=0;
    int ptr1=INT_MIN;
    int ptr2=INT_MIN;
    int ptr3=INT_MIN;
    vector<int>ans;
    while(i<n && j<m && k<p)
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
vector<int> unionmap(int arr1[], int arr2[], int n, int m)
{
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
vector<int> unionset(int arr1[], int arr2[], int n, int m)
{
    unordered_map<int>st;
    for(int i=0; i<n; i++)
    {
        st.insert(arr1[i]);
    }
    
    for(int i=0; i<m; i++)
    {
        st.insert(arr2[i]);
    }
    
    for(auto it : st)
    {
        ans.push_back(it);
    }
    return ans;
}

//using two pointer 
vector<int> unionpointer(int arr1[], int arr2[], int n, int m)
{
    vector<int>ans;
    int i=0;
    int j=0;
    while(i<n && j<m)
    {
        if(arr1[i]<=arr2[j])
        {
            if(ans.size()==0 || ans.back()!=arr1[i])
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
    return ans;
}

//valid triangle  bruteforce approach  
//optimal approach 
//boat save people 
//valid mountain array 
//longest mountain array 
//contain with most water 
//majority element bruteforce approach 
int majority(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        int count=0;
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
int majoritybetter(int arr[], int n)
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
int majorityopt(int arr[], int n)
{
    int count=0;
    int el;
    for(int i=0; i<n; i++)
    {
        if(count==0)
        {
            count=1;
            el=arr[i];
        }
        else if(el==arr[i])
        {
            count++;
        }
        else 
        {
            count--;
        }
    }
    
    int count1=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==el)
        {
            count1++;
        }
    }
    
    if(count1>n/2)
    return el;
    
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
vector<int> majority2better(int arr[], int n)
{
    unordered_map<int,int>mp;
    vector<int>ans;
    
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    
    for(auto it : mp)
    {
        if(it.second>n/3)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}

//optimal approach 
vector<int> majorityopt(int arr[], int n)
{
    int count1=0;
    int count2=0; 
    int el1=INT_MIN;
    int el2=INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(count1==0 && el2!=arr[i])
        {
            count1=1;
            el1=arr[i];
        }
        else if(count2==0 && el1!=arr[i])
        {
            count2=1;
            el2=arr[i];
        }
        else if(el1==arr[i])
        {
            count1++;
        }
        else if(el2==arr[i])
        {
            count2++;
        }
        else 
        {
            count1--;
            count2--;
        }
    }
    
    int count3=0;
    int count4=0;
    vector<int>ans;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==el1)
        {
            count3++;
        }
        if(arr[i]==el2)
        {
            count4++;
        }
    }
    
    if(count3>n/3)
    ans.push_back(el1);
    
    if(count4>n/3)
    ans.push_back(el2);
    
    return ans;
}

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
int foursum2(int arr1[], int arr2[], int arr3[], int arr4[], int n)
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
                    if(arr1[i]+arr2[j]+arr3[k]+arr4[p]==0)
                    {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

//optimal approach
int foursum2opt(int arr1[], int arr2[], int arr3[], int arr4[], int n)
{
    unordered_map<int,int>mp;
    for(auto l : arr3)
    {
        for(auto m : arr4)
        {
            mp[l+m]++;
        }
    }
    
    int count=0;
    for(auto i : arr2)
    {
        for(auto j : arr1)
        {
            count+=mp[j-i];
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
int maxisubarrsumbetter(int arr[], int n)
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
int maxisubarrsumopt(int arr[], int n)
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
int maxisubarrprod(int arr[], int n)
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
int maxisubarrprod(int arr[], int n)
{
    int maxi=INT_MIN;
    for(int i=0; i<n; i++)
    {
        int prod=1;
        for(int j=i; j<n; j++)
        {
            maxi=max(maxi, prod);
        }
    }
    return maxi;
}

//optimal approach
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
int subarrsumk(int arr[], int n, int k) 
{
    int count = 0; 
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++) 
        {
            int sum = 0;
            for(int K=i; K<=j; K++)
            {
                sum += arr[K];
            }
            
            if(sum == k)
            count++;
        }
    }
    return count;
}

//better approach
int subarrsumk(int arr[], int n, int k) 
{
    int count = 0; 
    for(int i=0; i<n; i++)
    {
        int sum=0;
        for(int j=i; j<n; j++) 
        {
            sum+=arr[j];
            if(sum == k)
            count++;
        }
    }
    return count;
}

//optimal approach 

//longest sum subarray equal k bruteforce approach 
//better approach 
//optimal approach 
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
//binary search 
//order agnostic binary search 
//first occurence of target 
//last occurence of target 
//lowerbound of target 
//upperbound of target 
//celi value of target 
//floor value of target 
//find the minimum element in sorted rotated array 
//second version of minimum element 
//search element in rotated sorted array 
//second version of search 
//find the square root of element 
//find the peak element 
//find position of an element in a sorted array of infinte number 
//search insert position 
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
//print linked list 
void printList(ListNode*head)
{
    if(head==NULL)
    return ;
    
    ListNode*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//length of linked list 
int lengthofList(TreeNode*root)
{
    if(head==NULL)
    return 0;
    
    int count=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

//binary of linked list 
int binaryofList(TreeNode*root)
{
    if(head==NULL)
    return 0;
    
    int ans=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        ans*=2;
        ans+=temp->val;
        temp=temp->next;
    }
    return ans;
}

//reverse linked list using stack 
ListNode*reverseList(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    stack<int>st;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        st.push(temp->val);
        temp=temp->next;
    }
    
    temp=head;
    while(temp!=NULL)
    {
        temp->val=st.top();
        st.pop();
        
        temp=temp->next;
    }
    return head;
}
//reverse linked list recursive method 
ListNode*reverseListrec(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    ListNode*newhead=reverseListrec(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

//reverse linked list iterative method 
ListNode*reverseListit(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    ListNode*curr=head;
    ListNode*pre=NULL;
    ListNode*nextn=NULL;
    while(curr!=NULL)
    {
        nextn=curr->next;
        curr->next=pre;
        pre=curr;
        curr=curr->next;
    }
    return pre;
}

//reverse linked list in k group 
//middle of linked list
ListNode*middlenode(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    int count=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    
    int half=count/2;
    temp=head;
    
    while(half--)
    {
        temp=temp->next;
    }
    return temp->val;
}

//2-method to find the middle element in list  
ListNode*middlenode(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

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
//delete last node 
ListNode*deleteTail(ListNode*head) 
{
    if (head==NULL || head->next==NULL)
    return NULL;
    
    ListNode*temp = head;
    while (temp->next->next != NULL) 
    {
        temp = temp->next;
    }
    
    delete temp->next;
    temp->next = NULL;
    return head;
}



//reverse doubly linked list 
ListNode*reverseDLL(ListNode* head)
{
    if(head==NULL || head->next == NULL)
    return head;
    
    stack<int> st;
    
    ListNode* temp = head;
    while(temp!=NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    while(temp!=NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}


ListNode* reverseDLL(ListNode* head) 
{
    if (head == NULL || head->next == NULL)
    return head; 
    
    ListNode* prev = NULL;  
    ListNode* current = head;   

    while (current != NULL) 
    {
        // Store a reference to the previous node
        prev = current->back; 
        
        // Swap the previous and next pointers
        current->back = current->next; 
        
        // This step reverses the links
        current->next = prev;          
        
        current = current->back; 
    }
    return prev->back;
}


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
vector<int>preOrder(TreeNode*root)
{
    vector<int>arr;
    preorder(root, arr);
    return arr;
}

//preorder traversal using iterative 
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
        
        ans.push_back(root->val);
        
        if(root->right!=NULL)
        st.push(root->right);
        
        if(root->left!=NULL)
        st.push(root->left);
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
vector<int>inOrder(TreeNode*root)
{
    vector<int>arr;
    inorder(root, arr);
    return arr;
}

//inorder traversal using iterative
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
vector<int>postOrder(TreeNode*root)
{
    vector<int>arr;
    postorder(root, arr);
    return arr;
}

//postorder traversal using iterative using 2 stack 
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

///postorder traversal using iterative using 1 stack 
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

//preorder, inorder and postorder traversal using single iteration 
vector<vector<int>>preinpost(TreeNode*root)
{
    if(root==NULL)
    return {};
    
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
                st.push({it.first->right, 1});
            }
        }
        else 
        {
            post.push_back(it.first->val);
        }
    }
    
    vector<vector<int>>ans;
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    return ans;
}

//level order traversal 
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

//second version of level order traversal 
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

//zigzag order traversal
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
            
            int index=lefttoright ? i : size-i-1;
            level[index]=node->val;
            
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

//left side view of binary tree 
vector<int>leftview(TreeNode*root)
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

//right side view of binary tree
vector<int>rightview(TreeNode*root)
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


//average of level binary tree 
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
    return 0;
    
    queue<TreeNode*>q;
    q.push(root);
    int maxi=INT_MIN;
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
        maxi=max(maxi, sum);
    }
    return maxi;
}

//Kth largest sum in a binary tree (2583)
//minimum depth of binary tree
int minimumdepth(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int depth=0;
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

//maximum depth of binary tree using level order 
int maximumdepth(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
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
        }
        depth++;
    }
    return depth;
}

//using recusive 
int maximumdepth(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=maximumdepth(root->left);
    int rh=maximumdepth(root->right);
    
    return 1+max(lh, rh);
}

//minimum number of operations to sort a binary tree by level (2471)
//find largest value in each row
vector<int>largestvalinlevel(TreeNode*root)
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
            
            maxi=max(maxi, node->val);
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
        }
        ans.push_back(maxi);
    }
    return ans;
}

//find bottom left tree value (513)
//cousins of binary tree 
//deepest leaves sum 
//find largest value in each row
//find bottom left tree value 
//check for balance binary tree brute force approach 
int getHeight(Node* root) 
{
    if (root==NULL)
    return 0;
    
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    return 1+max(lh, rh);
}
bool isBalanced(Node* root) 
{
    if (root==NULL)
    return true;

    int lh= getHeight(root->left);
    int rh= getHeight(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) 
    {
        return true;
    }
    return false;
    
}

//optimal approach 
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

//diameter of binary tree 
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
    int dia=0;
    height(root, dia);
    return dia;
}

//maximum path sum
int pathsum(TreeNode*root, int &maxi)
{
    if(root==NULL)
    return 0;
    
    int lh=max(0, pathsum(root->left, maxi));
    int rh=max(0, pathsum(root->right, maxi));
    
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
    if(root==NULL)
    return true; 
    
    return identical(root->left, root->right);
}

//boundary order traversal in binary tree ==
//convert sorted array to binary search tree
TreeNode*maketree(vector<int>arr, int start, int end)
{
    if(start>=end)
    return NULL;
    
    int mid=start+(end-start)/2;
    TreeNode*root=new TreeNode(arr[mid]);
    
    root->left=maketree(arr, start, mid);
    root->right=maketree(arr, mid+1, end);
    
    return root;
}
TreeNode*sortedarrtobt(vector<int>arr)
{
    return maketree(arr, 0, arr.size()-1);
}

//convert sorted linked list to binary search tree
TreeNode*maketree(vector<int>arr, int start, int end)
{
    if(start>=end)
    return NULL;
    
    int mid=start+(end-start)/2;
    TreeNode*root=new TreeNode(arr[mid]);
    
    root->left=maketree(arr, start, mid);
    root->right=maketree(arr, mid+1, end);
    
    return root;
}
TreeNode*sortedlisttobt(ListNode*head)
{
    vector<int>ans;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        ans.push_back(temp->val);
        temp=temp->next;
    }
    
    return maketree(ans, 0, ans.size()-1);
}

//second mathod 
TreeNode*sortedlisttobt(ListNode*head)
{
    if(head==NULL)
    return NULL;
    
    if(head->next==NULL)
    return new TreeNode(head->val);
    
    auto slow=head;
    auto fast=head;
    auto temp=NULL;
    while(fast!=NULL && fast->next!=NULL)
    {
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    
    
    TreeNode*root=new TreeNode(slow);
    root->left=sortedlisttobt(head);
    root->right=sortedlisttobt(slow->next);
    
    return root;
}

//make maximum binary tree
//construct binary tree from preorder and inorder (105)
//construct binary tree from inorder and postorder (106)
//path sum  (112)
//path sum-II (113)
//binary tree path 
//sum root to leaf number (node 1->2->3==123 and so on )
//count total node in a complete binary tree ==
//invert binary tree 
//sum of left leaf node 
//merge two binary tree
//verical order traversal ==
//top view of binary tree ==
//bottom view of binary tree==
//print root to node path in binary tree ==
//maximum width of binary tree ==
//children sum property in binary tree ==
//print all the node at a distance k in binary tree ==
//minimum time taken to burn the binary tree from a node==
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
//lowest common ancestor of deepest leaves(both have same solution)  ----1123 
//increasing order search tree brute force approach  ------- 897 
//optimal approach 
//lowest common ancestor of binary tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    if (root == NULL || root ==p || root == q)
    return root;
    
    TreeNode* lh = lowestCommonAncestor(root->left, p, q);
    TreeNode* rh = lowestCommonAncestor(root->right, p, q);

    if(lh == NULL) 
    {
        return rh;
    }
    else if(rh == NULL) 
    {
        return lh;
    }
    else 
    {
        return root;
    }
}

//lowest common ancestor of binary search tree (235)
//populating next right pointers in each node (116)
