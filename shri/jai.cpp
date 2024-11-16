#include<bits/stdc++.h>
using namespace std;

//reverse array using inbuilt function 
//time complexity is O(n)
//space complexity is O(1)
void reverse1(int arr[], int n)
{
    reverse(arr, arr+n);
}

//reverse array 
//time complexity is O(n)
//space complexity is O(1)
void reverse2(int arr[], int n)
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
void reverse3(int arr[], int n)
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
void reverse4(int arr[], int n, int k)
{
    for(int i=0; i<n; i+=k)
    {
        if(i+k<n)
        {
            reverse(arr+i, arr+i+k);
        }
        else 
        {
            reverse(arr+i, arrr+n);
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
        n=n/10;
    }
    return ans;
}

//check array are palindrome or not 
//time complexity is O(n)
//space complexity is O(1)
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

//wave array 
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

//array are sorted or not 
//time complexity is O(n)
//space complexity is O(1)
bool issorted(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]<=arr[i+1])
        {
            
        }
        else 
        {
            return false;
        }
    }
    return true;
}

//move negative element at the end of array using bruteforce approach 
//time complexity is O(n)
//space complexity is O(n)
int moveneg(int arr[], int n)
{
    vector<int>ans;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>0)
        {
            ans.push_back(arr[i]);
        }
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]<0)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
void movenegative(int arr[], int n)
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
int movezero(int arr[], int n)
{
    vector<int>ans;
    for(int i=0; i<n; i++)
    {
        if(arr[i]!=0)
        {
            ans.push_back(arr[i]);
        }
    }
    
    int sz=ans.size();
    for(int i=sz; i<n; i++)
    {
        ans.push_back(0);
    }
    return ans;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
void movezero0(int arr[], int n)
{
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

//arrange alternate sign element in array 
//time complexity is O(n)
//space complexity is O(1)
void alternatesign(int arr[], int n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        while(i<n && arr[i]>0)
        i++;
        
        while(j>0 && arr[j]<0)
        j--;
        
        if(i<j)
        {
            swap(arr[i], arr[j]);
        }
    }
    
    int k=0;
    while(k< && i<n)
    {
        swap(arr[i], arr[k]);
        i++;
        k+=2;
    }
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
    
    for(int i=count0+count1; i<n; i++)
    arr[i]=2;
}

//dnf sort 
//time complexity is O(n)
//space complexity is O(1)
void Dnfsort(int arr[], int n)
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
//time complexity is O(n)
//space complexity is O(1)
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
//time complexity is O(nlogn)
//space complexity is O(1)
int minimum(int arr[], int n)
{
    sort(arr, arr+n);
    return arr[0];
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
int minimumele(int arr[], int n)
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
int maximum(int arr[], int n)
{
    sort(arr, arr+n);
    return arr[n-1];
}

//optimal approach
//time complexity is O(n)
//space complexity is O(1)
int maximumele(int arr[], int n)
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
int secondlargestele(int arr[], int n)
{
    int largest=arr[0];
    int sec=INT_MIN;
    for(int i=1; i<n; i++)
    {
        if(arr[i]>largest)
        {
            sec=largest;
            largest=arr[i];
        }
        
        if(largest>arr[i] && arr[i]>sec)
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
    int smallest=arr[0];
    
    int sec=-1;
    for(int i=1; i<n; i++)
    {
        if(arr[i]!=smallest)
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
int secondsmallestele(int arr[], int n)
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
        
        if(smallest!=arr[i] && arr[i]>sec)
        {
            sec=arr[i];
        }
    }
    return sec;
}

//find the kthsmallest element in array 
//time complexity is O(nlogk)
//space complexity is O(k)
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
//time complexity is O(nlogk)
//space complexity is O(k)
int kthsmallest(int arr[], int n, int k)
{
    priority_queue<int , vector<int>, greater<int>>q;
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
//time complexity is O(nlok)
//space complexity is O(k)
class cmp 
{
    public :
    bool operator()(string a, string b)
    {
        if(a.length()!=b.length())
        return a.length()>b.length();
        
        return a>b;
    }
}
int kthsmallest(vector<string>arr, int n, int k)
{
    priority_queue<string, vector<string>, cmp>q;
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

//third largest element in array 
//time complexity is O(n)
//space complexity is O(1)
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
        if(arr[i]!=a && arr[j]!=b)
        {
            c=max(c, arr[i]);
            flage=1;
        }
    }
    if(flage==1)
    return c;
    
    return a;
}

//monotonic array (An array is monotonic if it is either monotone increasing or monotone decreasing.)
//find unique element in array bruteforce approach 
//time complexity is O(n)
//space complexity is O(n)
int unique(int arr[], int n)
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
//time complexity is O(n)
//space complexity is O(1)
int uniqueele(int arr[], int n)
{
    int ans=0;
    for(int i=0; i<n; i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}

//Non Repeating Numbers (means more than one unique element in array )
//time complexity is O(n)
//space complexity is O(n)
int allunique(int arr[], int n)
{
    unordered_map<int,int>mp;
    vector<int>ans;
    
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    for(int i=0; i<n; i++)
    {
        if(mp[arr[i]]==1)
        {
            ans.push_back(arr[i]0;
        }
    }
    return ans;
}

//unique number of occurence 
//time complexity is O(n)
//space complexity is O(n)
int uniqueocc(int arr[], int n)
{
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    
    unordered_set<int>st;
    for(auto it ; mp)
    {
        st.insert(it.second);
    }
    return st.size()==mp.size();
}

//sum of unique element in array 
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
int duplicate(int arr[], int n)
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
//time complexity is O(n)
//space complexity is O(1)
int duplicateele(int arr[], int n)
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
//time complexity is O(n)
//space complexity is O(n)
int allduplicate(int arr[], int n)
{
    unordered_map<int,int>mp;
    vector<int>ans;
    
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    for(int i=0; i<n; i++)
    {
        if(mp[arr[i]]==1)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
int allduplicateele(int arr[], int n)
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

//find the leader of array 
//time complexity is O(n)
//space complexity is O(1)
int leader(int arr[], int n)
{
    vector<int>ans;
    int index=arr[n-1];
    for(int i=n-1; i>=0; i--)
    {
        if(arr[i]<=index)
        {
            ans.push_back(arr[i]);
            index=arr[i];
        }
    }
    return ans;
}

//find the equlibrium point 
//time complexity is O(n)
//space complexity is O(1)
int equlibriumpoint(int arr[], int n)
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

//Number of Steps to Reduce a Number to Zero
//time complexity is O(n)
//space complexity is O(1)
int reducenumtozero(int n)
{
    int count=0;
    while(n!=0)
    {
        if(n%2==0)
        {
            count++;
            n=n/2;
        }
        else 
        {
            count++;
            n=n-1;
        }
    }
    return count;
}

//Longest Subarray of 1's After Deleting One Element
//time complexity is O(n)
//space complexity is O(1)
int consecutiveonedelete(int arr[], int n)
{
    int k=0;
    int i=0;
    int count=0;
    for(int j=0; j<n; j++)
    {
        if(arr[j]==0)
        {
            k--;
        }
        while(k<0)
        {
            if(arr[i]==0)
            {
                k++;
            }
            i++;
        }
        count=max(count, j-i);
    }
    return count;
}

//Max Consecutive Ones if k number of zero is filp  to one 
//time complexity is O(n)
//space complexity is O(1)
int consecutiveoneK(int arr[], int n, int k)
{
    int i=0;
    int count=0;
    for(int j=0; j<n; j++)
    {
        if(arr[j]==0)
        {
            k--;
        }
        while(k<0)
        {
            if(arr[i]==0)
            {
                k++;
            }
            i++;
        }
        count=max(count, j-i+1);
    }
    return count;
}

//maximum consecutive ones if filp atleast one zero to one 
//time complexity is O(n)
//space complexity is O(1)
int consecutiveoneflip1(int arr[], int n)
{
    int k=1;
    int i=0;
    int count=0;
    for(int j=0; j<n; j++)
    {
        if(arr[j]==0)
        {
            k--;
        }
        while(k<0)
        {
            if(arr[i]==0)
            {
                k++;
            }
            i++;
        }
        count=max(count, j-i+1);
    }
    return count;
}

//maximum consecutive ones  
//time complexity is O(n)
//space complexity is O(1)
int consecutiveone(int arr[], int n)
{
    int k=0;
    int i=0;
    int count=0;
    for(int j=0; j<n; j++)
    {
        if(arr[j]==0)
        {
            k--;
        }
        while(k<0)
        {
            if(arr[i]==0)
            {
                k++;
            }
            i++;
        }
        count=max(count, j-i+1);
    }
    return count;
}

//number of zero filled subarray 
//time complexity is O(n)
//space complexity is O(1)
int zerofilled(int arr[], int n)
{
    int count=0;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==0)
        {
            count++;
            ans+=count;
        }
        else 
        {
            count=0;
        }
    }
    return ans;
}

//nextpermutation of array 
//time complexity is O(n)
//space complexity is O(1)
void nextpermutation(int arr[], int n)
{
    int ind1;
    for(int i=n-2; i>=0; i--)
    {
        if(arr[i]<arr[i+1])
        {
            ind1=i;
            break;
        }
    }
    if(ind1<0)
    {
        reverse(arr, arr+n);
    }
    else 
    {
        int ind2=-1;
        for(int i=n-1; i>=0; i--)
        {
            if(arr[i]>arr[ind1])
            {
                ind2=i;
                break;
            }
        }
        swap(arr[ind1], arr[ind2]);
        reverse(arr+ind1+1, arr+n);
    }
}

//intersection of two array 
//time complexity is O(n+m)
//space complexity is O(n+m)
int intersection(int arr1[], int arr2[], int n, int m)
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
//time complexity is O(n+m)
//space complexity is O(n+m)
int common(int arr1[], int arr2[],int arr3[], int p int n, int m)
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
//time complexity is O(n+m)
//space complexity is O(m+n)
int union(int arr1[], int arr2[], int n, int m)
{
    unordered_map<int,int>mp;
    vector<int>ans;
    
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
//time complexity is O(n+m)
//space complexity is O(n+m)
int union(int arr1[], int arr2[], int n, int m)
{
    unordered_set<int>st;
    vector<int>ans;
    
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
//time complexity is O(n+m)
//space complexity is O(n+m)
int union(int arr1[], int arr2[], int n, int m)
{
    int i=0;
    int j=0;
    vector<int>ans;
    while(i<n && j<m)
    {
        if(arr1[i]<=arr2[j])
        {
            if(ans.size()==0 && ans.back()!=arr1[i])
            {
                ans.push_back(arr1[i]);
                i++;
            }
        }
        else 
        {
            if(ans.size()==0 && ans.back()!=arr2[j])
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
//time complexity is O(n^3)
//space complexity is O(1)
int triangle(int arr[], int n)
{
    int count=0;
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
//time complexity is O(n)
//space complexity is O(1)
int counttriangle(int arr[], int n)
{
    int count=0;
    for(int i=n-1; i>=2; i--)
    {
        int start=0;
        int end=i-1;
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
//time complexity is O(nlogn)
//space complexity is O(1)
int boatsave(int arr[], int n, int limit)
{
    int count=0;
    int start=0;
    int end=n-1;
    sort(arr, arr+n);
    while(start<=end)
    {
        if(arr[start]+arr[end]<=limit)
        {
            count++;
            start++;
            end--;
        }
        else 
        {
            count++;
            end--;
        }
    }
    return count;
}

//valid mountain array 
//time complexity is O(n)
//space complexity is O(1)
int validmountain(int arr[], int n)
{
    int i=0;
    int j=n-1;
    
    while(i<n && arr[i]<arr[i+1])
    i++;
    
    while(j>0 && arr[j]>arr[j-1])
    j--;
    
    return i==j;
}

//longest mountain array 
//time complexity is O(n)
//space complexity is O(1)
int longestmountain(int arr[], int n)
{
    int maxi=-1;
    for(int i=1; i<n-1; i++)
    {
        if(arr[i]>arr[i+1] && arr[i]>arr[i-1])
        {
            int j=i;
            int count=1;
            while(j>=0 && arr[j]>arr[j+1])
            {
                j--;
                count++;
            }
            while(i<n && arr[i]>arr[i+1])
            {
                i++;
                count++;
            }
        }
        maxi=max(maxi, count);
    }
    return maxi;
}

//contain with most water 
//time complexity is O(n)
//space complexity is O(1)
int containwater(int arr[], int n)
{
    int ans=0;
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        ans=max(min(arr[start], arr[end])*(end-start), ans);
        if(arr[start]<arr[end])
        {
            start++;
        }
        else 
        {
            end--;
        }
    }
    return ans;
}

//majority element bruteforce approach 
//time complexity is O(n^2)
//space complexity is O(1)
int majority(int arr[], int n)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
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
//time complexity is O(n)
//space complexity is O(n)
int majority2(int arr[], int n)
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
//time complexity is O(n)
//space complexity is O(1)
int majority3(int arr[], int n)
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

//majority-II 
//time complexity is O(n)
//space complexity is O(1)
int majority-II(int arr[], int n)
{
    int count1=0;
    int count2=0;
    int el1;
    int el2;
    for(int i=0; i<n; i++)
    {
        if(count1==0 && el2!=arr[i])
        {
            count1=1;
            el1=arr[i];
        }
        if(count2==0 && el1!=arr[i])
        {
            count2=1;
            el2=arr[i];
        }
        if(el1==arr[i])
        {
            count1++;
        }
        if(el2==arr[i])
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
    for(int j=0; j<n; j++)
    {
        if(el1==arr[j])
        {
            count3++;
        }
        if(el2==arr[i])
        {
            count4++;
        }
    }
    if(count3>n/3)
    {
        ans.push_back(el1);
    }
    if(count4>n/3)
    {
        ans.push_back(el2);
    }
    return ans;
}

//remove duplicate element 
//time complexity is O(n)
//space complexity is O(1)
int removeduplicate(int arr[], int n)
{
    int i=0;
    for(int j=0; j<n; j++)
    {
        if(arr[j]!=arr[i])
        {
            arr[i]=arr[j];
            i++;
        }
    }
    return i+1;
}

//second version 
//time complexity is O(n)
//space complexity is O(1)
int removeduplicate2(int arr[], int n)
{
    if(n<3)
    return n;
    
    int i=2;
    for(int j=2; j<n; j++)
    {
        if(arr[j]!=arr[i-2])
        {
            arr[i]=arr[j];
            i++;
        }
    }
    return i;
}

//remove value from array
//time complexity is O(n)
//space complexity is O(1)
int removevalue(int arr[], int n, int val)
{
    int i=0;
    for(int j=0; j<n; j++)
    {
        if(arr[j]!=val)
        {
            arr[i]=arr[j];
            i++;
        }
    }
    return i;
}

//rotate array by one place 
//time complexity is O(n)
//space complexity is O(1)
int rotatebyoneplace(int arr[], int n)
{
    int temp=arr[0];
    for(int i=1; i<n; i++)
    {
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    return arr;
}

//rotate array by d place bruteforce approach 
//time complexity is O(n)
//space complexity is O(d)
int rotatebydplace(int arr[], int n, int d)
{
    vector<int>temp;
    for(int i=0; i<d; i++)
    {
        ans.push_back(arr[i]);
    }
    for(int i=d; i<n; i++)
    {
        arr[i-d]=arr[i];
    }
    for(int i=n-d; i<n; i++)
    {
        arr[i]=temp[i-(n-d)];
    }
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
int rotatebydplace(int arr[], int n, int d)
{
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}

//squares of a sorted array bruteforce approach 
//time complexity is O(nlogn)
//space complexity is O(1)
int squares(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        arr[i]=arr[i]*arr[i];
    }
    sort(arr, arr+n);
    return arr;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
int squares2(int arr[],int n)
{
    vector<int>ans;
    int start=0;
    int end=n-1;
    for(int i=n-1; i>=0; i--)
    {
        if(abs(arr[start])>arr[end])
        {
            ans[i]=arr[start]*arr[start];
            start++;
        }
        else 
        {
            ans[i]=arr[end]*arr[end];
            end--;
        }
    }
    return ans;
}

//product of itself bruteforce approach 
//time complexity is O(n^2)
//space complexity is O(1)
int proditself(int arr[], int n)
{
    vector<int>ans;
    for(int i=0; i<n; i++)
    {
        int prod=1;
        for(int j=0; j<n; j++)
        {
            if(i==j)
            continue;
            prod*=arr[j];
        }
        ans.push_back(prod);
    }
    return ans;
}

//better approach 
//time complexity is O(n)
//space complexity is O(n)
int proditself2(int arr[], int n)
{
    vector<int>left;
    vector<int>right;
    vector<int>ans;
    
    left[0]=1;
    for(int i=1; i<n; i++)
    {
        left[i]=left[i-1]*arr[i-1];
    }
    
    right[n-1]=1;
    for(int i=n-2; i>=0; i--)
    {
        right[i]=right[i+1]*arr[i+1];
    }
    
    for(int i=0; i<n; i++)
    {
        ans[i]=left[i]*right[i];
    }
    return ans;
}

//optimal approach
//time complexity is O(n)
//space complexity is O(1)
int proditself3(int arr[], int n)
{
    vector<int>ans;
    int prod=1;
    for(int i=0; i<n; i++)
    {
        prod*=arr[i];
        ans.push_back(prod);
    }
    
    prod=1;
    for(int i=n-1; i>0 ; i--)
    {
        ans[i]=ans[i+1]*prod;
        prod*=arr[i];
    }
    ans[0]=prod;
    return ans;
}

//2824. Count Pairs Whose Sum is Less than Target 
//optimal approach 
//1679. Max Number of K-Sum Pairs
//optimal approach
//167. Two Sum II - Input Array Is Sorted 
//2006 Count Number of Pairs With Absolute Difference K
//optimal approach 
//1711. Count Good Meals (adding two element in array than equal to power of two)
//2023. Number of Pairs of Strings With Concatenation Equal to Target
//optimal approach
//two sum bruteforce approach
//time complexity is O(n^2)
//space complexity is O(1)
int two(int arr[] int n, int target)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]+arr[j]==target)
            {
                return 1;
            }
        }
    }
    return -1;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(n)
int twosum(it arr[], int n, int target)
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
    return ans;
}

//three sum bruteforce approach 
//time complexity is O(n^3)
//space complexity is O(1)
int three(int arr[] int n, int target)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if(arr[i]+arr[j]+arr[k]==target)
                {
                    return 1;
                }
            }
        }
    }
    return -1;
}

//optimal approach 
//time complexity is O(nlogn)
//space complexity is O(1)
int threesum(int arr[], int n,int target)
{
    vector<vector<int>>ans;
    sort(arr, arr+n);
    for(int i=0; i<n-1; i++)
    {
        if(i==0 && (i>0 && arr[i]!=arr[i-1]))
        {
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
                    
                    while(start<end && arr[start]==arr[start+1])
                    start++;
                    
                    while(start<end && arr[end]==arr[end-1])
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

//four sum bruteforce approach 
//time complexity is O(n^4)
//space complexity is O(1)
int four(int arr[] int n, int target)
{
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
                        return 1;
                    }
                }
            }
        }
    }
    return -1;
}

//optimal approach 
//time complexity is O(n^2)
//space complexity is O(1)
int foursum(int arr[], int n,int target)
{
    vector<vector<int>>ans;
    sort(arr, arr+n);
    for(int i=0; i<n-2; i++)
    {
        if(i==0 && (i>0 && arr[i]!=arr[i-1]))
        {
            for(int j=i+1; j<n-1; j++)
            {
                if(i==j && (j>1 && arr[j]!=arr[j-1]))
                {
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
                            
                            while(start<end && arr[start]==arr[start+1])
                            start++;
                            
                            while(start<end && arr[end]==arr[end-1])
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
        }
    }
    return ans;
}

//four-II sum bruteforce approach
//time complexity is O(n^4)
//space complexity is O(1)
int four-II(int arr1[] , int arr2[], int arr3[], int arr4[], int n)
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
//time complexity is O(n)
//space complexity is O(n)
int foursum-II(int arr1[] , int arr2[], int arr3[], int arr4[], int n)
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
//time complexity is O(n^3)
//space complexity is O(1)
int maxisubarrsum(int arr[], int n)
{
    int maxi=-1;
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
//time complexity is O(n^2)
//space complexity is O(1)
int maxisubarrsum2(int arr[], int n)
{
    int maxi=-1;
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
//time complexity is O(n)
//space complexity is O(1)
int maxisubarrsum3(int arr[], int n)
{
    int maxi=-1;
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

//maximum product of subarray bruteforce approach
//time complexity is O(n^3)
//space complexity is O(1)
int maxisubarrprod(int arr[], int n)
{
    int maxi=-1;
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
//time complexity is O(n^2)
//space complexity is O(1)
int maxisubarrprod2(int arr[], int n)
{
    int maxi=-1;
    for(int i=0; i<n; i++)
    {
        int prod=1;
        for(int j=i; j<n; j++)
        {
            prod*=arr[j];
            maxi=max(maxi, prod);
        }
    }
    return maxi;
}

//optimal approach
//time complexity is O(n)
//space complexity is O(1)
int maxisubarrprod3(int arr[], int n)
{
    int maxi=-1;
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

//maximum sum equal k bruteforce approach
//time complexity is O(n^3)
//space complexity is O(1)
int maxisubarrsumK(int arr[], int n, int k)
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
//time complexity is O(n^2)
//space complexity is O(1)
int maxisubarrsumK2(int arr[], int n, int k)
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
//time complexity is O(n)
//space complexity is O(n)
int maxisubarrsumK3(int arr[], int n, int k)
{
    int sum=0;
    int count=0;
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
//time complexity is O(n^3)
//space complexity is O(1)
int longsubarrsumK(int arr[], int n, int k)
{
    int maxlen=-1;
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
                maxlen=max(maxlen, j-i+1);
            }
        }
    }
    return maxlen;
}

//better approach 
//time complexity is O(n^2)
//space complexity is O(1)
int longsubarrsumK2(int arr[], int n, int k)
{
    int maxlen=-1;
    for(int i=0; i<n; i++)
    {
        int sum=0;
        for(int j=i; j<n; j++)
        {
            sum+=arr[j];
            if(sum==k)
            {
                maxlen=max(maxlen, j-i+1);
            }
        }
    }
    return maxlen;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
int longsubarrsumK3(int arr[], int n, int k)
{
    int sum=arr[0];
    int maxlen=-1;
    int start=0;
    int end=0;
    while(end<n)
    {
        end++;
        if(end<n)
        {
            sum+=arr[end];
        }
        if(start<=end && sum>k)
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
//time complexity is O(n^2)
//space complexity is O(1)
int minisizesubarr(int arr[], int n, int target)
{
    int mini=INT_MAX;
    for(int i=0; i<n; i++)
    {
        int sum=0;
        int len=0;
        for(int j=i; j<n; j++)
        {
            sum+=arr[j];
            len++;
        }
        if(sum>=target)
        {
            mini=min(mini, len);
            break;
        }
    }
    if(mini==INT_MAX)
    return -1;
    
    return mini;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
int minisizesubarr2(int arr[], int n, int target)
{
    int sum=0;
    int j=0;
    int mini=INT_MAX;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        while(sum>=target)
        {
            mini=min(mini, i-j+1);
            sum-=arr[j];
            j++;
        }
    }
    if(mini==INT_MAX)
    return -1;
    
    return mini;
}

//sliding window maximum bruteforce approach 
//time complexity is O(n^2)
//space complexity is O(1)
int sliding(int arr[], int n, int k)
{
    vector<int>ans;
    for(int i=0; i<=n-k; i++)
    {
        int currmax=-1;
        for(int j=i; j<k+i ; j++)
        {
            currmax=max(currmax, arr[j]);
        }
        
        ans.push_back(currmax);
    }
    return ans;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(n)
int slidingwindow(int arr[], int n, int k)
{
    vector<int>ans;
    deque<int>dq;
    
    for(int i=0; i<n; i++)
    {
        if(!dq.empty() && dq.front()==i-k)
        dq.pop_front();
        
        while(!dq.empty() && arr[dq.front()]<=arr[i])
        dq.pop_back();
        
        dq.push_back(i);
        
        if(i>=k-1)
        {
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
}

//subarray product less than k 
//time complexity is O(n)
//space complexity is O(1)
int subarrprodlessk(int arr[], int n, int k)
{
    int prod=1;
    int start=0;
    (int i=0; i<n; i++)
    {
        prod*=arr[i];
        if(prod>=k)
        {
            prod=prod/arr[start];
            start++;
        }
        count=min(count, prod);
    }
    return count;
}

//sorted unsorted continuous subarray 
//time complexity is O(n)
//space complexity is O(1)
int unsorted(int arr[], int n)
{
    int start=0;
    int end=n-1;
    while(start+1<n && arr[start]<=arr[start+1])
    start++;
    
    while(end-1>0 && arr[end-1]<=arr[end]);
    end--;
    
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=start; i<=end; i++)
    {
        mini=min(mini, arr[i]);
        maxi=max(maxi, arr[i]);
    }
    
    while(start-1>=0 && arr[start]>mini)
    start--;
    
    while(end+1<n && arr[end]<maxi)
    end++;
    
    return end-start+1;
}

//traping rain water bruteforce approach
//time complexity is O(n^2)
//space complexity is O(1)
int trap(int arr[], int n)
{
    int watertraped=0;
    for(int i=0; i<n; i++)
    {
        int j=i;
        int leftmax=0;
        int rightmax=0;
        while(j>=0 &&)
        {
            leftmax=max(leftmax, arr[j]);
            j--;
        }
        j=i;
        while(j<n)
        {
            rightmax=max(rightmax, arr[j]);
            j++;
        }
        watertraped+=max(leftmax, rightmax)-arr[i];
    }
    return watertraped;
}

//better approach 
//time complexity is O(n)
//space complexity is O(n)
int trap2(int arr[], int n)
{
    vector<int>prefix;
    vector<int>suffix;
    
    prefix[0]=arr[0];
    for(int i=1; i<n; i++)
    {
        prefix[i]=prefix[i-1]+arr[i-1];
    }
    
    suffix[n-1]=arr[n-1];
    for(int i=n-2; i>=0; i--)
    {
        suffix[i]=suffix[i+1]+arr[i+1];
    }
    
    int watertraped=0;
    for(int i=0; i<n; i++)
    {
        ans+=max(prefix[i], suffix[i])-arr[i];
    }
    return ans;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
int trap3(int arr[], int n)
{
    int watertraped=0;
    int start=0;
    int end=n-1;
    int leftmax=0;
    int rightmax=0;
    while(start<=end)
    {
        if(arr[start]<arr[end])
        {
            if(leftmax>=arr[start])
            {
                leftmax=arr[start];
            }
            else 
            {
                watertraped+=leftmax-arr[start];
            }
            start++;
        }
        else 
        {
            if(rightmax>=arr[end])
            {
                rightmax=arr[end];
            }
            else 
            {
                watertraped+=rightmax-arr[end];
            }
            end--;
        }
    }
    return watertraped;
}

//merge interval 
//insert interval 
//non overlaping interval (count how mant interval are delete to make non overlap)
//largest number  
//453. Minimum Moves to Equal Array Element
//462 Minimum Moves to Equal Array Elements-2
//1658. Minimum Operations to Reduce X to Zero







//---------------------------------------------------------------------------------------------------------------
//linear search
//time complexity is O(n)
//space complexity is O(1)
int linear(int arr[], int n, int target)
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
//time complexity is O(logn)
//space complexity is O(1)
int binary(int arr[], int n, int target)
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
//time complexity is O(logn)
//space complexity is O(1)
int orderexbinary(int arr[], int n, int target)
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
//time complexity is O(logn)
//space complexity is O(1)
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
//time complexity is O(logn)
//space complexity is O(1)
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
//time complexity is O(logn)
//space complexity is O(1)
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
//time complexity is O(logn)
//space complexity is O(1)
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
    return ans;
}

//celi value of target 
//time complexity is O(logn)
//space complexity is O(1)
int celivalue(int arr[], int n, int target)
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

//floor value of target 
//time complexity is O(logn)
//space complexity is O(1)
int floorvalue(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    int ans=n;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]<=target)
        {
            ans=mid;
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
//time complexity is O(logn)
//space complexity is O(1)
int minimumele(int arr[], int n)
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
            start=mid+1;
        }
    }
    return start;
}

//second version of minimum element 
//time complexity is O(logn)
//space complexity is O(1)
int minimumele2(int arr[], int n)
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
            start=mid+1;
        }
        else 
        {
            end--;
        }
    }
    return end;
}

//search element in rotated sorted array 
//time complexity is O(logn)
//space complexity is O(1)
int searchinrotatedarr(int arr[], int n, int target)
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
        if(arr[start]<arr[mid])
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
//time complexity is O(logn)
//space complexity is O(1)
bool searchinrotatedarr2(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
        {
            return false;
        }
        if(arr[mid]==arr[start] && arr[mid]==arr[end])
        {
            start++;
            end--;
            continue;
        }
        if(arr[start]<arr[mid])
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
//time complexity is O(logn)
//space complexity is O(1)
int square(int n)
{
    int start=1;
    int end=n;
    int ans=n;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(mid*mid<=n)
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

//find the peak element 
//time complexity is O(logn)
//space complexity is O(1)
int peak(int arr[], int n)
{
    int start=0;
    int end=n-1;
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
//time complexity is O(logn)
//space complexity is O(1)
int infinte(int arr[], int target)
{
    int start=0;
    int end=1;
    while(end<target)
    {
        int newstart=end;
        end=end+(end-start+1)*2;
        start=newstart;
    }
    return binary(arr, target, start, end);
}

//search insert position 
//time complexity is O(logn)
//space complexity is O(1)
int searchinsertpos(int arr[], int n, int target)
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

//Koko Eating Bananas
//Minimum days to make M bouquets 
//Find the Smallest Divisor Given a Threshold
//Capacity to Ship Packages within D Days
//book allocation problem 
//Aggressive cow problem 
//painter partition problem
//split array largest sum 

//--------------------------------------------------------------------------------------------------------
//cyclic sort 
//time complexity is O(n)
//space complexity is O(1)
void cyclicsort(int arr[], int ans)
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
}

//missing number 
//time complexity is O(n)
//space complexity is O(1)
int missingnumber(int arr[], int ans)
{
    int i=0;
    while(i<n)
    {
        int correct=arr[i]-1;
        if(arr[i]<n && arr[i]!=arr[correct])
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

//find all disappeared in an array
//time complexity is O(n)
//space complexity is O(1)
int alldisappeared(int arr[], int ans)
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
    return ans;
}

//first missing positive  
//time complexity is O(n)
//space complexity is O(1)
int missingPosnumber(int arr[], int ans)
{
    int i=0;
    while(i<n)
    {
        int correct=arr[i]-1;
        if(arr[i]>0 && arr[i]<=n && arr[i]!=arr[correct])
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
    return n+1;
}

//set mismatch 
//time complexity is O(n)
//space complexity is O(1)
int setmismatch(int arr[], int ans)
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
            ans.push_back(index);
            ans.push_back(index+1);
        }
    }
    return ans;
}



//-----------------------------------------------------------------------------------------------------------------------------
//print linked list 
//time complexity is O(n)
//space complexity is O(1)
void print(ListNode*head)
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
//time complexity is O(n)
//space complexity is O(1)
int lengthList(ListNode*head)
{
    if(head==NULL)
    return ;
    
    ListNode*temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

//binary of linked list 
//time complexity is O(n)
//space complexity is O(1)
int binary(ListNode*head)
{
    if(head==NULL)
    return ;
    
    ListNode*temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count*=2;
        count+=temp->val;
        temp=temp->next;
    }
    return count;
}

//reverse linked list recursive method 
//time complexity is O(n)
//space complexity is O(1)
ListNode*reverseRec(ListNode*head)
{
    if(head==NULL)
    return ;
    
    ListNode*newhead=reverseRec(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

//reverse linked list iterative method 
//time complexity is O(n)
//space complexity is O(1)
ListNode*reverseK(ListNode*head , int k)
{
    if(head==NULL)
    return ;
    
    ListNode*curr=head;
    ListNode*pre=NULL;
    int count=0;
    while(curr!=NULL && count<k)
    {
        ListNode*nextn=curr->next;
        curr->next=pre;
        pre=curr;
        curr=curr->next;
        count++;
    }
    
    if(nextn!=NULL)
    {
        head->next=reverseK(nextn, k);
    }
    return pre;
}

//reverse linked list in k group 
//time complexity is O(n)
//space complexity is O(1)
ListNode*reverse(ListNode*head)
{
    if(head==NULL)
    return ;
    
    ListNode*curr=head;
    ListNode*pre=NULL;
    while(curr!=NULL)
    {
        ListNode*nextn=curr->next;
        curr->next=pre;
        pre=curr;
        curr=curr->next;
    }
    return pre;
}

//middle of linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*middlenode(ListNode*head)
{
    if(head==NULL)
    return ;
    
    ListNode*temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    
    temp=head;
    int half=count/2;
    while(half--)
    {
        temp=temp->next;
    }
    return temp;
}

//2-method to find the middle element in list  
//time complexity is O(n)
//space complexity is O(1)
ListNode*middlenode(ListNode*head)
{
    if(head==NULL)
    return ;
    
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
//time complexity is O(n)
//space complexity is O(1)
bool loop(ListNode*head)
{
    if(head==NULL)
    return ;
    
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}

//find the starting point of loop 
//time complexity is O(n)
//space complexity is O(1)
ListNode*startingNode(ListNode*head)
{
    if(head==NULL)
    return ;
    
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            break;
        }
    }
    
    slow=head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

//remove loop from linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*deleteloop(ListNode*head)
{
    if(head==NULL)
    return ;
    
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            break;
        }
    }
    
    
    if(slow==head && fast==head)
    {
        while(fast!=slow->next)
        {
            fast=fast->next;
        }
        fast->next=NULL;
    }
    
    if(slow==fast)
    {
        slow=head;
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
    return head;
}

//remove duplicate from sorted linked list using recursive method 
//time complexity is O(n)
//space complexity is O(1)
ListNode*removeduplicate(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    ListNode*newhead=removeduplicate(head->next);
    if(head->val==newhead->val)
    {
        return newhead;
    }
    else 
    {
        head->next=newhead;
        return head;
    }
}

//remove duplicate from sorted linked list using iterative method 
//time complexity is O(n)
//space complexity is O(1)
ListNode*removeduplicate(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    ListNode*temp=head;
    while(temp!=NULL)
    {
        if(temp->val==temp->next->val)
        {
            ListNode*del=temp->next;
            temp->next=temp->next->next;
            delete del;
        }
        else 
        {
            temp=temp->next;
        }
    }
    return head;
}

//remove duplicate from unsorted linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*removeduplicate(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    unordered_set<int>st;
    ListNode*temp=head;
    ListNode*pre=NULL;
    while(temp!=NULL)
    {
        if(st.find(temp->val)!=st.end())
        {
            pre->next=temp->next;
            delete temp;
        }
        else 
        {
            st.insert(temp->val);
            pre=temp;
        }
        temp=pre->next;
    }
    return head;
}

//palindrome linked list 
//time complexity is O(n)
//space complexity is O(1)
bool palindrome(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    slow->next=reverse(slow->next);
    
    ListNode*first=head;
    ListNode*second=slow->next;
    while(second!=NULL)
    {
        if(first->val!=second->val)
        {
            return false;
        }
        first=first->next;
        second=second->next;
    }
    
    slow->next=reverse(slow->next);
    return true;
}

//merge linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*merge(ListNode*head1, ListNode*head2)
{
    if(head1==NULL)
    return head2;
    
    if(head2==NULL)
    return head1;
    
    if(head1->val<head2->val)
    {
        head1->next=merge(head1->next, head2);
        return head1;
    }
    else 
    {
        head2->next=merge(head1, head2->next);
        return head2;
    }
}

//second method to merge linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*merge(ListNode*head1, ListNode*head2)
{
    if(head1==NULL)
    return head2;
    
    if(head2==NULL)
    return head1;
    
    ListNode*duumy=new ListNode(0);
    ListNode*tail=duumy;
    
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->val<head2->val)
        {
            tail->next=head1;
            tail=tail->next;
            head1=head1->next;
        }
        else 
        {
            tail->next=head2;
            tail=tail->next;
            head2=head2->next;
        }
    }
    
    while(head1!=NULL)
    {
        tail->next=head1;
    }
    while(head2!=NULL)
    {
        tail->next=head2;
    }
    return duumy->next;
}

//merge k linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*mergeK(vector<vector<ListNode*>>list)
{
    if(list.size()==0)
    return -1;
    
    if(list.size()==1)
    return list[0];
    
    ListNode*ans=merge(list[0], list[1]);
    
    for(int i=2; i<list.size(); i++)
    {
        ans=mergeK(list[i], ans);
    }
    return ans;
}

//second method to merge k linked list 
//time complexity is O(n)
//space complexity is O(1)
class cmp 
{
    public : 
    bool operator()(ListNode*a, ListNode*b)
    {
        return a->val>b->val;
    }
}
ListNode*mergeK(vector<vector<ListNode*>>list)
{
    if(list.size()==0)
    return -1;
    
    if(list.size()==1)
    return list[0];
    
    priority_queue<ListNode*, vector<ListNode*>, cmp>q;
    ListNode*dummy=new ListNode(0);
    ListNode*tail=dummy;
    for(int i=0; i<lust.size(); i++)
    {
        if(list[i]!=NULL)
        {
            q.push(list[i]);
        }
    }
    while(q.size()==0)
    {
        ListNode*temp=q.top();
        tail->next=temp;
        tail=temp;
        q.pop();
        
        if(temp->next!=NULL)
        {
            q.push(temp->next);
        }
    }
    return dummy->next;
    
}

//intersection of linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*intersection(ListNode*head1, ListNode*head2)
{
    ListNode*a=head1;
    ListNode*b=head2;
    
    while(a!=b)
    {
        if(a==NULL)
        {
            a=head2;
        }
        else 
        {
            a=a->next;
        }
        if(b==NULL)
        {
            b=head1;
        }
        else 
        {
            b=b->next;
        }
    }
    return a;
}

//second method to find intersection of linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*intersection(ListNode*head1, ListNode*head2)
{
    ListNode*temp1=head1;
    ListNode*temp2=head2;
    
    int len1=lengthList(head1);
    int len2=lengthList(head2);
    
    if(len1>len2)
    {
        while(len1-len2)
        {
            temp1=temp1->next;
        }
    }
    if(len2>len1)
    {
        while(len2-len1)
        {
            temp2=temp2->next;
        }
    }
    
    while(temp1!=temp2)
    {
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return temp1;
}

//odd or even linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*oddeven(ListNode*head)
{
    if(head==NULL)
    return ;
    
    ListNode*oddh=head;
    ListNode*odd=head;
    ListNode*even=head->next;
    ListNode*evenh=head->next;
    while(even!=NULL && even->next!=NULL)
    {
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenh;
    return oddh;
}

//second method  to find odd and even linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*oddeven(ListNode*head)
{
    if(head==NULL)
    return ;
    
    ListNode*oddh=NULL;
    ListNode*odd=NULL;
    ListNode*even=NULL;
    ListNode*evenh=NULL;
    int count=1;
    while(head!=NULL)
    {
        if(count%2==0)
        {
            if(evenh==NULL)
            {
                evenh=head;
                even=head;
                head=head->next;
            }
            else 
            {
                even->next=head;
                even=even->next;
                head=head->next;
            }
        }
        else 
        {
            if(oddh==NULL)
            {
                oddh=head;
                odd=head;
                head=head->next;
            }
            else 
            {
                odd->next=head;
                odd=odd->next;
                head=head->next;
            }
        }
    }
    odd->next=evenh;
    return oddh;
}

//delete node where head or not given 
//time complexity is O(n)
//space complexity is O(1)
ListNode*delete(ListNode*del)
{
    ListNode*temp=del->next;
    del->val=temp->val;
    delete temp;
}

//check two linked list are identical or not 
//time complexity is O(n)
//space complexity is O(1)
bool identical(ListNode*head1, ListNode*head2)
{
    ListNode*temp1=head1;
    ListNode*temp2=head2;
    
    int len1=lengthList(head1);
    int len2=lengthList(head2);
    
    if(len1!=len2)
    {
        return false;
    }
    
    while(temp1!=temp2)
    {
        if(temp1->val!=temp2->val)
        {
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}

// Nth node from end of linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*Nthnode(ListNode*head, int n)
{
    int len=lengthList(head);
    int i=0;
    
    ListNode*temp=head;
    while(i<(len-n))
    {
        i++;
        temp=temp->next;
    }
    return temp>val;
}

//swap node pairwise 
//time complexity is O(n)
//space complexity is O(1)
ListNode*swappairwise(ListNode*head )
{
    if(head==NULL)
    return ;
    
    ListNode*curr=head;
    ListNode*pre=NULL;
    int count=0;
    while(curr!=NULL && count<2)
    {
        ListNode*nextn=curr->next;
        curr->next=pre;
        pre=curr;
        curr=curr->next;
        count++;
    }
    
    if(nextn!=NULL)
    {
        head->next=swappairwise(nextn);
    }
    return pre;
}

//swap node kth from starting and kth from end in linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*Kthnodeswap(ListNode*head, int k)
{
    ListNode*slow=head;
    ListNode*fast=head;
    ListNode*Kth=NULL;
    int count=0;
    while(count<k)
    {
        count++;
        fast=fast->next;
    }
    kth=fast;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    swap(slow->val, kth->val);
    return head;
}

//2-method 
//time complexity is O(n)
//space complexity is O(1)
ListNode*Kthnodeswap(ListNode*head, int k)
{
    ListNode*slow=head;
    ListNode*fast=head;
    ListNode*temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    
    int n=count-k;
    while(n--)
    {
        slow=slow->next;
    }
    while(k-1!=0)
    {
        fast=fast->next;
    }
    
    swap(slow->val, fast->val);
    return head;
}    

//add two linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*add(ListNode*head1, ListNode*head2)
{
    ListNode*dummy=new ListNode(0);
    ListNode*tail=dummy;
    int carry=0;
    while(head2!=NULL && head1!=NULL)
    {
        int sum=head1->val+head2->val+carry;
        carry=sum/10;
        dummy->next=new ListNode(sum%10);
        dummy=dummy->next;
        head1=head1->next;
        head2=head2->next;
    }
    
    while(head1!=NULL)
    {
        int sum=head1->val+carry;
        carry=sum/10;
        dummy->next=new ListNode(sum%10);
        dummy=dummy->next;
        head1=head1->next;
    }
    while(head2!=NULL)
    {
        int sum=head2->val+carry;
        carry=sum/10;
        dummy->next=new ListNode(sum%10);
        dummy=dummy->next;
        head2=head2->next;
    }
    if(carry==1)
    {
        dummy->next=new ListNode(carry);
    }
    return tail->next;
}

//second version 
//time complexity is O(n)
//space complexity is O(1)
ListNode*add(ListNode*head1, ListNode*head2)
{
    head1=reverse(head1);
    head2=reverse(head2);
    
    ListNode*dummy=new ListNode(0);
    ListNode*tail=dummy;
    int carry=0;
    while(head2!=NULL && head1!=NULL)
    {
        int sum=carry;
        if(head1!=NULL)
        {
            sum+=head1->val;
            head1=head1->next;
        }
        if(head2!=NULL)
        {
            sum+=head2->val;
            head2=head2->next;
        }
        
        carry=sum/10;
        tail->next=new ListNode(sum%10);
        tail=tail->next;
    }
    return dummy->next;
}

//sort linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode* sort(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    ListNode*slow=head;
    ListNode*fast=head;
    ListNode*temp=NULL;
    while(fast!=NULL && fast->next!=NULL)
    {
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    
    temp->next=NULL;
    ListNode*first=sort(head);
    ListNode*second=sort(slow);
    
    return merge(first, second);
    
}

//rotate linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*rotateList(ListNode*head, int k)
{
    if(head==NULL)
    return head;
    
    int len=1;
    ListNode*newhead=head;
    ListNode*tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
        len++;
    }
    tail->next=head;
    k=k%len;
    for(auto i=0; i<len-k; i++)
    {
        tail=tail->next;
    }
    
    newhead=tail->next;
    tail->next=NULL;
    return newhead;
}

//Partition linked List 
//time complexity is O(n)
//space complexity is O(1)
ListNode*Partition(ListNode*head, int x)
{
    if(head==NULL)
    return ;
    
    ListNode*smallh=new ListNode(0);
    ListNode*largeh=new ListNode(0);
    ListNode*small=smallh;
    ListNode*large=largeh;
    
    while(head!=NULL)
    {
        if(head->val<x)
        {
            small->next=head;
            small=small->next;
            head=head->next;
        }
        else 
        {
            large->next=head;
            large=large->next;
            head=head->next;
        }
    }
    large->next=NULL;
    smallh=largeh->next;
    return smallh->next;
}

//reorder linked list 
//time complexity is O(n)
//space complexity is O(1)
void reorder(ListNode*head)
{
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    ListNode*second=reverseIter(slow->next);
    slow->next=NULL;
    ListNode*first=head;
    
    while(second!=NULL)
    {
        ListNode*temp1=first->next;
        ListNode*temp2=second->next;
        first->next=second;
        second->next=temp1;
        first=temp1;
        second=temp2;
    }
}

//insertion sort in linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode* insertionSortList(ListNode* head) 
{
    ListNode* dummy=new ListNode(10000);
    while(head!=NULL)
    {
        ListNode* next=head->next;
        ListNode* temp=dummy;
        
        while(temp->next && temp->next->val<head->val)
        {
            temp=temp->next;
        }
        head->next=temp->next;
        temp->next=head;
        head=next;
    }
    return dummy->next; 

}



//-------------------------------------------------------------------------------------------- 
//reverse string using stack 
//time complexity is O(n)
//space complexity is O(n)
string reverse(string s)
{
    int n=s.length();
    stack<char>st;
    for(int i=0; i<n; i++)
    {
        st.push(s[i]);
    }
    
    string ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

//delete middle element in stack 
//time complexity is O(n)
//space complexity is O(n)
void slove(stack<int>st, int count, int size)
{
    if(count==size/2)
    {
        st.pop();
        return ;
    }
    
    int take=st.top();
    st.pop();
    
    slove(st, count+1, size);
    st.push(take);
    
}
void deletemiddle(stack<int>st, int n)
{
    int count=0;
    slove(st, ,count, n);
}

//valid parenthesis  {([])
//time complexity is O(n)
//space complexity is O(n)
bool isvalid(string s)
{
    int n=s.length();
    stack<char>st;
    for(int i=0; i<n; i++)
    {
        char ch=s[i];
        if(ch=='(' || ch=='{' || ch=='[')
        {
            st.push(ch);
        }
        else 
        {
            if(!st.empty())
            {
                char top=st.top();
                if((ch==')' && top=='(') || (ch=='}' && top=='{') || (ch==']' && top=='['))
                {
                    st.pop();
                }
                else 
                {
                    return false;
                }
            }
            else 
            {
                return false;
            }
        }
    }
    if(st.empty())
    {
        return true;
    }
    return false;
}

//insertatbottom in stack 
//time complexity is O(n)
//space complexity is O(n)
void slove(stack<int>st, int num)
{
    if(st.empty())
    {
        st.push(num);
        return ;
    }
    
    int take=st.top();
    st.pop();
    
    slove(st, num);
    st.push(take);
    
}
int insertatbottom(stack<int>st, int ele)
{
    slove(st, ele);
}

//reverse stack 
//time complexity is O(n)
//space complexity is O(n)
void insertbottom(stack<int>st, int num)
{
    if(st.empty())
    {
        st.push(num);
        return ;
    }
    
    int take=st.top();
    st.pop();
    
    insertbottom(st, num);
    st.push(take);
    
}
void reversestack(stack<int>st)
{
    if(st.empty())
    return ;
    
    int take=st.top();
    st.pop();
    
    reversestack(st);
    insertbottom(st, take);
}

//sort stack 
//time complexity is O(n)
//space complexity is O(n)
void sortedinsert(stack<int>st, int num)
{
    if(st.empty() || st.top()<num)
    {
        st.push(num);
        return ;
    }
    
    int take=st.top();
    st.pop();
    
    sortedinsert(st, num);
    st.push(take);
    
}
void sortstack(stack<int>st)
{
    if(st.empty())
    return ;
    
    int take=st.top();
    st.pop();
    
    sortstack(st);
    sortedinsert(st, take);
}

//redundant bracket (-,+,/ ,*)
//time complexity is O(n)
//space complexity is O(n)
bool redundant(string s)
{
    int n=s.length();
    stack<char>st;
    for(int i=0; i<n; i++)
    {
        char ch=s[i];
        if(ch=='(' || ch=='*' || ch=='+' || ch=='-' || ch=='/')
        {
            st.push(ch);
        }
        else
        {
            if(ch==')')
            {
                bool flage=true;
                if(!st.empty() && st.top()!='(')
                {
                    char top=st.top();
                    if(top=='+' || top=='-' || top=='/' || top=='*')
                    {
                        flage=false;
                    }
                    
                    st.pop();
                }
                if(flage==true)
                return true;
                
                st.pop();
            }
        }
    }
    return false;
}

//Minimum cost to make valid string {
//time complexity is O(n)
//space complexity is O(n)
int minimumcost(string s)
{
    int n=s.length();
    stack<char>st;
    for(int i=0; i<n; i++)
    {
        char ch=s[i];
        if(ch=='{')
        {
            st.push(ch);
        }
        else
        {
            if(!st.empty())
            {
                st.pop();
            }
            else 
            {
                st.push(ch);
            }
        }
    }
    
    int a=0;
    int b=0;
    while(!st.empty())
    {
        if(st.top()=='{')
        {
            b++;
        }
        else 
        {
            a++;
        }
    }
    int ans=(a+1)/2+(b+1)/2;
    return ans;
}

//Minimum Number of Swaps to Make the String Balanced  ]][[[]]][[
//132 pattern bruteforce approach
//time complexity is O(n^3)
//space complexity is O(1)
bool pattern132(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if(arr[j]>arr[k] && arr[k]>arr[i])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

//better approach 
//time complexity is O(n^2)
//space complexity is O(1)
bool pattern132(int arr[], int n)
{
    int mini=arr[0];
    for(int j=0; j<n; j++)
    {
        for(int k=j+1; k<n; k++)
        {
            if(arr[j]>arr[k] && arr[k]>mini)
            {
                return true;
            }
            
            mini=min(mini, arr[j]);
        }
    }
    return false;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(n)
bool pattern132(int arr[], int n)
{
    int thirdele=-1;
    stack<int>st;
    for(int i=0; i<n; i++)
    {
        if(arr[i]<thirdele)
        {
            return true;
        }
        while(!st.empty() && st.top()<=arr[i])
        {
            thirdele=st.top();
            st.pop();
        }
        
        st.push(arr[i]);
    }
    return false;
}

//next smaller element in array 
//time complexity is O(n)
//space complexity is O(n)
int nextsmaller(int arr[], int n)
{
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && st.top()>=arr[i])
        {
            st.pop();
        }
        
        ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}

//previous smaller element int array 
//time complexity is O(n)
//space complexity is O(n)
int nextprevious(int arr[], int n)
{
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && st.top()>=arr[i])
        {
            st.pop();
        }
        
        ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}

//next greater element in array 
//time complexity is O(n)
//space complexity is O(n)
int nextgreater(int arr[], int n)
{
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }
        
        ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}

//previous greater element in array 
//time complexity is O(n)
//space complexity is O(n)
int previousgreater(int arr[], int n)
{
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }
        
        ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}

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
//time complexity is O(n)
//space complexity is O(1)
bool ispoweroftwo(int n)
{
    return n>0 && (n&(n-1))==0;
}

//number is power of three or not
//time complexity is O(n)
//space complexity is O(1)
bool ispowerofthree(int n)
{
    if(n<0)
    return false;
    
    while(n%3==0)
    {
        n=n/3;
    }
    return n==1;
}

//number is power of four or not 
//time complexity is O(n)
//space complexity is O(1)
bool ispoweroffour(int n)
{
    return n>0 && (n&(n-1))==0 && (n%3==1);
}

//kid with the greatest number of candies (given array of candies and int extracandies return bool of vector ) 
//time complexity is O(n)
//space complexity is O(1)
int greatest(int arr[], int n, int extra)
{
    int largest=arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
        }
    }
    
    vector<bool>ans;
    for(int i=0; i<n; i++)
    {
        if(arr[i]+extra>=largest)
        {
            ans.push_back(true);
        }
        else 
        {
            ans.push_back(false);
        }
    }
}

//running sum of 1d array (this means prefix of sum ) 1,2,3,4 == 1,3,6,10
//time complexity is O(n)
//space complexity is O(1)
int runningsum(int arr[], int n)
{
    vector<int>prefix;
    prefix[0]=arr[0];
    for(int i=1; i<n; i++)
    {
        prefix[i]=prefix[i-1]+arr[i-1];
    }
    return prefix;
}

//number of good pair 
//time complexity is O(n)
//space complexity is O(1)
int goodpair(int arr[], int n)
{
    int ans=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]==arr[j])
            {
                ans++;
            }
        }
    }
    return ans;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
int goodpair2(int arr[], int n)
{
    vector<int>fre;
    for(int i=0; i<n; i++)
    {
        fre[arr[i]]++;
    }
    
    for(int i=0; i<101; i++)
    {
        ans+=fre[i]*(fre[i]-1)/2;
    }
    return ans;
}

//two out of three (this means given three array find the common element in array atleast in  two array common ) 
//time complexity is O(n)
//space complexity is O(1)
int twooutofthree(int arr1[], int arr2[], int arr3[], int n, int m,int p)
{
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>ans;
    for(int i=0; i<n; i++)
    v1[arr1[i]]=1;
    
    for(int i=0; i<m; i++)
    v2[arr2[i]]=1;
    
    for(int i=0; i<p; i++)
    v3[arr3[i]]=1;
    
    for(int i=0; i<101; i++)
    {
        if(v1[i]+v2[i]+v3[i]>=2)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

//daily Temperatures
// Maximum Product of Word Lengths


//---------------------------------------

//level order traversal 
//second version of level order traversal 
//average of level of binary tree  
//level order successor of a node in binary tree 
//zig-zag order traversal 
//right side view of binary tree 
//left side view of binary tree 
//minimum depth of binary tree 




//convert sorted array to binary search tree
//convert sorted linked list to binary search tree 
//sum of left leaf node 
//merge two binary tree 












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

