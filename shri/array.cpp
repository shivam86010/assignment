
#include<bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------------------------------------------------
//reverse the array 
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

//--------------------------------------------------------------------------------------------------------------
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


//--------------------------------------------------------------------------------------------------------------
//reverse array group  size k 
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

//--------------------------------------------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------------------------------------
//check the array are palindrome or not 
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

//--------------------------------------------------------------------------------------------------------------
//find the maximum element in array brute force approach 
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
int minimumele2(int arr[], int n)
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

//--------------------------------------------------------------------------------------------------------------
//find the maximum element in array brute force approach 
//time complexity is O(nlogn)
//space complexity is O(1)
int miaximumele(int arr[], int n)
{
    sort(arr, arr+n);
    return arr[n-1];
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
int maximumele2(int arr[], int n)
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

//--------------------------------------------------------------------------------------------------------------
//find the second largest element in array brute force approach
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
int secondlargest2(int arr[], int n)
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
        if(largest>arr[i] && arr[i]>sec)
        {
            sec=arr[i];
        }
    }
    return sec;
}

//--------------------------------------------------------------------------------------------------------------
//find the second smallest element in array brute force approach
//time complexity is O(nlogn)
//space complexity is O(1)
int secondsmallest(int arr[], int n)
{
    sort(arr, arr+n);
    int largest=arr[0];
    int sec=-1;
    for(int i=1; i<n; i++)
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
int secondsmallest2(int arr[], int n)
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
        if(smallest!=arr[i] && arr[i]<sec)
        {
            sec=arr[i];
        }
    }
    return sec;
}

//--------------------------------------------------------------------------------------------------------------
//find the third largest element
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

//--------------------------------------------------------------------------------------------------------------
//find kthsmallest element in array
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

//--------------------------------------------------------------------------------------------------------------
//find the kthlargest element in array 
//time complexity is O(nlogk)
//space complexity is O(k)
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

//--------------------------------------------------------------------------------------------------------------
//move zero at the end of array brute force approach
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
    for(int i=sz; i<n; i++)
    {
        temp.push_back(0);
    }
    return temp;
}

//optimal approach
//time complexity is O(n)
//space complexity is O(1)
void movezero2(int arr[], int n)
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

//--------------------------------------------------------------------------------------------------------------
//moveNegative integer at the end of array brute force approach 
//time complexity is O(n)
//space complexity is O(n)
vector<int>moveneg(int arr[], int n)
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
    return temp;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
void moveneg2(int arr[], int n)
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

//--------------------------------------------------------------------------------------------------------------
//arrange array element alternate sign 
//time complexity is O(n)
//space complexity is O(1)
void arrangealternate(int arr[], int n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        while(i<n && arr[i]>0)
        i++;
        
        while(j>0 && arr[j]<0)
        j++;
        
        if(i<j)
        {
            swap(arr[i], arr[j]);
        }
    }
    int k=0;
    while(k<n && i<n)
    {
        swap(arr[i], arr[k]);
        i++;
        k+=2;
    }
}

vector<int>alternateSign(vector<int>arr)
{
    int n=arr.size();
    vector<int>pos;
    vector<int>neg;

    for(int i=0; i<n; i++)
    {
        if(arr[i]<0)
        {
            neg.push_back(arr[i]);
        }
        else
        {
            pos.push_back(arr[i]);
        }
    }

    vector<int>ans;
    for(int i=0; i<n/2; i++)
    {
        ans[2*i]=pos[i];
        ans[2*i+1]=neg[i];
    }
    return ans;
}

vector<int>optimalway(vector<int>arr)
{
    int n=arr.size();
    vector<int>pos;
    vector<int>neg;

    for(int i=0; i<n; i++)
    {
        if(arr[i]<0)
        {
            neg.push_back(arr[i]);
        }
        else
        {
            pos.push_back(arr[i]);
        }
    }

    vector<int>ans;
    if(pos.size() <neg.size())
    {
        for(int i=0; i<pos.size(); i++)
        {
            ans[2*i]=pos[i];
            ans[2*i+1]=neg[i];
        }

        int index=2*pos.size();
        
    }
}
//--------------------------------------------------------------------------------------------------------------
//sort 0 1 and 2 method-1 
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

//sort 0 1 and 2 using DNF algorithm 
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

//--------------------------------------------------------------------------------------------------------------
//three way partition array 
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

//--------------------------------------------------------------------------------------------------------------
//find the unique element in array using brute force approach 
//time complexity is O(nlogn)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(1)
int uniqueele2(int arr[], int n)
{
    int ans=0;
    for(int i=0; i<n; i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}

//--------------------------------------------------------------------------------------------------------------
//find the unique number of occurence 
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
    for(auto it : mp)
    {
        st.insert(it.second);
    }
    return st.size()==mp.size();
}

//--------------------------------------------------------------------------------------------------------------
//find the sum of unique element 
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

//--------------------------------------------------------------------------------------------------------------
//find the duplicate element in array brute force approach 
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//find all duplicate element in array brute force approach 
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//wave array 
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


//--------------------------------------------------------------------------------------------------------------
//find the leader of array 
//time complexity is O(n)
//space complexity is O(1)
vector<int> leader(int arr[], int n)
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

//--------------------------------------------------------------------------------------------------------------
//find the equlibrium point in array 
//time complexity is O(n)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//maximum consecutive one in array 
//time complexity is O(n)
//space complexity is O(1)
int consecutive(int arr[], int n)
{
    int count=0;
    int maxi=INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==1)
        {
            count++;
            maxi=max(maxi, count);
        }
        else
        {
            count=0;
        }
    }
    return maxi;
}

//--------------------------------------------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------------------------------------
//nextpermutation of array 
//time complexity is O(n)
//space complexity is O(1)
void nextpermutation(int arr[], int n)
{
    int ind1=-1;
    for(int i=n-2; i>=0; i--)
    {
        if(arr[i]<arr[i+1])
        {
            ind1=i;
            break;
        }
    }
    if(ind1<1)
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

//--------------------------------------------------------------------------------------------------------------
//intersection of two array 
//time complexity is O(n+m)
//space complexity is O(n+m)
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

//--------------------------------------------------------------------------------------------------------------
//common element 
//time complexity is O(n+m+p)
//space complexity is O(n+m+p)
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


//----------------------------------------------------------------------------------------------------
//union of array using hash map 
//time complexity is O((n+m)log(m+n))
//space complexity is O(n+m)
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

//union of array using set 
//time complexity is O((n+m)log(m+n))
//space complexity is O(n+m)
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

//union of array using two pointer 
//time complexity is O(n+m)
//space complexity is O(n+m)
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

//--------------------------------------------------------------------------------------------------------------
//product of array brute force approach 
//time complexity is O(nlogn)
//space complexity is O(1)
int product(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        arr[i]=arr[i]*arr[i];
    }
    sort(arr, arr+n);
    return arrr;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
int product2(int arr[], int n)
{
    int start=0;
    itn end=n-1;
    vector<int>ans;
    for(int i=n-1; i>=0; i--)
    {
        if(abs(arr[start]) >arr[end])
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

//--------------------------------------------------------------------------------------------------------------
//boat to save people 
//time complexity is O(nlogn)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//valid triangle number brute force approach
//time complexity is O(n)
//space complexity is O(1)
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
//time complexity is O(n)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//valid mountain array
//time complexity is O(n)
//space complexity is O(1)
int validmountain(int arr[], int n)
{
    int start=0;
    int end=n-1;
    while(start+1<n-1 && arr[start]<arr[start+1])
    start++;
    
    while(end-1>0 && arr[end]<arr[end-1])
    end--;
    
    return start==end;
    
}

//--------------------------------------------------------------------------------------------------------------
//longest mountain array 
//time complexity is O(n)
//space complexity is O(1)
int longestmountain(int arr[], int n)
{
    int maxi=INT_MIN;
    for(int i=1; i<n-1; i++)
    {
        if(arr[i]>arr[i+1] && arr[i]>arr[i-1])
        {
            int j=i;
            int count=1;
            while(j>0 && arr[j]>arr[j-1])
            {
                count++;
                j--;
            }
            while(i<n-1 && arr[i]>arr[i+1])
            {
                count++;
                i++;
            }
            maxi=max(maxi, count);
        }
    }
    return maxi;
}

//--------------------------------------------------------------------------------------------------------------
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
            satrt++;
        }
        else
        {
            end--;
        }
    }
    return ans;
}

//--------------------------------------------------------------------------------------------------------------
//majority element brute force approach 
//time complexity is O(n)
//space complexity is O(1)
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
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//second version majority 
//time complexity is O(n)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//two sum array brute force approach 
//time complexity is O(n^2)
//space complexity is O(1)
int twosum(int arr[], int n, int target)
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
//time complexity is O(nlogn)
//space complexity is O(n)
int twosum2(int arr[], int , int target)
{
    unordered_map<int,int>mp;
    vector<int>ans;
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
//--------------------------------------------------------------------------------------------------------------
//three sum of array brute force approach 
//time complexity is O(n^3)
//space complexity is O(1)
int threesum(int arr[], int n, int target)
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
    return 1;
}

//optimal approach 
//time complexity is O(nlogn)
//space complexity is O(1)
int threesum2(int arr[], int n, int target)
{
    vector<vector<int>>ans;
    sort(arr, arr+n);
    for(int i=0; i<n; i++)
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

//--------------------------------------------------------------------------------------------------------------
//four sum of array brute force approach 
//time complexity is O(n^4)
//space complexity is O(1)
int foursum(int arr[], int n, itn target)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                for(int p=k+1; p<n; p++)
                {
                    if(arr[i]+arr[j]+arr[k]+arr[k]==target)
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
int foursum2(int arr[], int n, int target)
{
    vector<vector<int>>ans;
    sort(arr, arr+n);
    for(int i=0; i<n-2; i++)
    {
        if(i==0 || (i>0 && arr[i]!=arr[i-1]))
        {
            for(int j=i+1; j<n-1; j++)
            {
                if(j==i+1 && (j>1 && arr[j]!=arr[j-1]))
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

//--------------------------------------------------------------------------------------------------------------
//four sum-2 of array brute force approach 
//time complexity is O(n^4)
//space complexity is O(1)
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
//time complexity is O(n^2)
//space complexity is O(n)
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

//--------------------------------------------------------------------------------------------------------------
//remove duplicate from sorted array 
//time complexity is O(n)
//space complexity is O(1)
int removeduplicate(int arr[], int n)
{
    int i=0;
    for(int j=1; j<n; j++)
    {
        if(arr[i]!=arr[j])
        {
            arr[i]=arr[j];
            i++;
        }
    }
    return i+1;
}

//--------------------------------------------------------------------------------------------------------------
//second version of remove duplicate in sorted array 
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

//--------------------------------------------------------------------------------------------------------------
//remove element in array 
//time complexity is O(n)
//space complexity is O(1)
int removeval(int arr[], int n, int val)
{
    int i=0;
    for(itn j=0; j<n; j++)
    {
        if(arr[j]!=val)
        {
            arr[i]=arr[j];
            i++;
        }
    }
    return i;
}

//--------------------------------------------------------------------------------------------------------------
//rotate array by one position 
//time complexity is O(n)
//space complexity is O(1)
void rotatebyoneplace(int arr[], int n)
{
    int temp=arr[i];
    for(int i=1; i<n; i++)
    {
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}

//--------------------------------------------------------------------------------------------------------------
//rotate array by d position brute force approach 
//time complexity is O(n)
//space complexity is O(d)
void rotatebydplace(int arr[], int n,int d)
{
    vector<int>temp;
    for(int i=0; i<d; i++)
    {
        temp.push_back(arr[i]);
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
void rotatebydplace(int arr[], int n,int d)
{
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}

//--------------------------------------------------------------------------------------------------------------
//maximum contigous subarray sum brute force approach 
//time complexity is O(n^3)
//space complexity is O(1)
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
//time complexity is O(n^2)
//space complexity is O(1)
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
//time complexity is O(n)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//maximum product of subarray brute force approach
//time complexity is O(n^3)
//space complexity is O(1)
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
//time complexity is O(n^2)
//space complexity is O(1)
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
//time complexity is O(n)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//subarray sum equal k brute force approach 
//time complexity is O(n^3)
//space complexity is O(1)
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
//time complexity is O(n^2)
//space complexity is O(1)
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
//time complexity is O(n)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//longest subarray sum k brute force approach 
//time complexity is O(n^3)
//space complexity is O(1)
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
//time complexity is O(n^2)
//space complexity is O(1)
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
//time complexity is O(n)
//space complexity is O(1)
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


//--------------------------------------------------------------------------------------------------------------
//sort array by pairity
//time complexity is O(n)
//space complexity is O(1)
void pairity(int arr[], int n)
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

//--------------------------------------------------------------------------------------------------------------
//linear search 
//time complexity is O(n)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//binaray search 
//time complexity is O(nlogn)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//order agnostic binaray search 
//time complexity is O(nlogn)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//first occurence of target 
//time complexity is O(nlogn)
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

//--------------------------------------------------------------------------------------------------------------
//last occurence of target
//time complexity is O(nlogn)
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

//--------------------------------------------------------------------------------------------------------------
//lowerbound of target 
//time complexity is O(nlogn)
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

//--------------------------------------------------------------------------------------------------------------
//upperbound of target 
//time complexity is O(nlogn)
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
    return -1;
}

//--------------------------------------------------------------------------------------------------------------
//celli of value 
//time complexity is O(nlogn)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//floor of value 
//time complexity is O(nlogn)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//minimum in sorted rotated array 
//time complexity is O(nlogn)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//second version 
//time complexity is O(nlogn)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//search in sorted rotated array 
//time complexity is O(nlogn)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//second version 
//time complexity is O(nlogn)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//find the peak element 
//time complexity is O(nlogn)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//search insert position
//time complexity is O(nlogn)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//find the position of an element in a sorted array of infinite array 
//time complexity is O(nlogn)
//space complexity is O(1)
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

//----------------------------------------------------------------------------------------------------------
//Koko Eating Bananas problem 
//time complexity is O(n*log(max))
//space complexity is O(1)
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

//-------------------------------------------------------------------------------------------------------------
//Minimum days to make M bouquets
//time complexity is O(N((max-min)))
//space complexity is O(1)
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

//-------------------------------------------------------------------------------------------------------------
//Find the Smallest Divisor Given a Threshold
//time complexity is O(n*(log(max)))
//space complexity is O(1)
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

//----------------------------------------------------------------------------------------------------------- 
//Capacity to Ship Packages within D Days
// time complexity is O(N*(log(sum-max+1)))
//space complexity is O(1)
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

//-------------------------------------------------------------------------------------------------------------
//book allocation problem 
//time complexity is O(n*(log(sum-max+1)))
//space complexity is O(1)
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

//------------------------------------------------------------------------------------------------ 
//agressive cow problem 
//time complexity is O()
//space complexity is O(1)
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


//-------------------------------------------------------------------------------------------------
//paint's partition problem 
//time complexity is O(n*(log(sum-max+1)))
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------
//split largest subarray sum 
//time complexity is O(n*(log(sum-max+1)))
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//cyclic sort
//time complexity is O(n)
//space complexity is O(1)
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

//--------------------------------------------------------------------------------------------------------------
//find missing number
//time complexity is O(n)
//space complexity is O(1)
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



//--------------------------------------------------------------------------------------------------------------
//find all disappeared in array 
//time complexity is O(n)
//space complexity is O(1)
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


//--------------------------------------------------------------------------------------------------------------
//first missing positive number 
//time complexity is O(n)
//space complexity is O(1)
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



//--------------------------------------------------------------------------------------------------------------
//setmismatch 
//time complexity is O(n)
//space complexity is O(1)
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

//sorted unsorted array 
//time complexity is O(n)
//space complexity is O(1)
int unsortedsubarray(int arr[], int n)
{
    int start=0;
    int end=n-1;
    while(start+1<=n && arr[start]<=arr[start+1])
    start++;
    
    while(end-1>=0 && arr[end]<=arr[end-1])
    end--;
    
    if(start==n-1)
    return 0;
    
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=start; i<=end; i++)
    {
        mini=min(mini, arr[i]);
        maxi=max(maxi, arr[i]);
    }
    
    while(start-1>=0 && arr[start-1]>mini)
    start--;
    
    while(end+1<=n && arr[end+1]<maxi)
    end++;
    
    return start-end+1;
}
//-------------------------------------------------------------------------------------
//subarray product is less than k 
//time complexcity is O(n)
//space complexcity is O(1)
int productsubarray(int arr[], int n, int k)
{
    int i=0;
    //int j=0;
    int count=0;
    int prod=1;
    for(int j=0; j<n; j++)
    {
        prod*=arr[j];
        //product is less than k than 
        //count+=(j-i+1);
        if(prod>=k)
        {
            prod/=arr[i];
            i++;
        }
        count+=(j-i+1);
    }
    return count;
}

//merge interval 
//time complexity is O(nlogn)
//space complexity is O(1)
vector<vector<int>>merge(vector<vector<int>>interval)
{
    vector<vector<int>>ans;
    
    if(interval.size()==0)
    return ans;
    
    sort(interval.begin(), interval.end(),[](vector<int>&a, vector<int>&b)
    {
        return a[0]<b[0];
    });
    
    vector<int>curr=interval[0];
    
    for(int i=0; i<interval.size(); i++)
    {
        if(curr[1]<interval[i][0]) //this non overlaping condition 
        {
            ans.push_back(curr);
            curr=interval[i];
        }
        else 
        {
            curr[1]=max(curr[1], interval[i][1]);
        }
    }
    ans.push_back(curr);
    return ans;
}

//insert interval 
//time complexity is O(n)
//space complexity is O(1)
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
//time complexity is O(nlogn) 
//space complexity is (1)
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
//time complexity is (nlogn)
//--or-- time complexity is (lengthof(longeststring)*nlogn)  if considering string comparision and length of string is large 
//space complexity is O(1)
bool cmp(string &a, string &b)
{
    return a+b>b+a;
}
string largestnumber(vector<int>num)
{
    vector<string>ans;
    for(int i=0; i<num.size(); i++)
    {
        ans.push_back(to_string(num[i]));
    }
    sort(ans.begin(), ans.end(), cmp);
    
    if(ans[0]=="0")
    return "0";
    
    string s=" ";
    for(string it : ans)
    {
        s+=it;
    }
    return s;
    
}

//1679. Max Number of K-Sum Pairs
int maxinumberksum(int arr[], int n, int k)
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

//optimal approach 
int maxinumberksum(int arr[], int n, int k)
{
    int count=0;
    sort(arr, arr+n);
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
        else if(arr[start]+arr[end]<k)
        {
            start++;
        }
        else 
        {
            end--;
        }
    }
    return count;
}

//2824. Count Pairs Whose Sum is Less than Target 
int countpair(int arr[], int n, int target)
{
    int count=0;
    int n=num.size();
    for(int i=0; i<n-1; i++)
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
            count+=end-start;
            start++;
        }
        else 
        {
            end--;
        }
    }
    return count;
}

//1711. Count Good Meals
int countgoodmeal(int arr[], int n)
{
    vector<int>pow;
    int p=1;
    for(int i=0; i<22; i++)
    {
        pow.push_back(p);
        p*=2;
    }
    
    unordered_map<int,int>mp;
    long long count=0;
    for(auto it : arr)
    {
        for(auto x : pow)
        {
            if(mp.count(x-it))
            count+=mp[x-it];
        }
        mp[it]++;
    }
    return count%(int)(1e9+7);
}

//2023. Number of Pairs of Strings With Concatenation Equal to Target
int numOfPairs(vector<string>&arr, string target) 
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
int numOfPairs(vector<string>&arr, string target)     
{
    int count=0;
    unordered_map<string , int>mp;
    for(auto it : arr)
    {
        mp[it]++;
    }
    
    for(int i=0; i<target.size(); i++)
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

//2006 Count Number of Pairs With Absolute Difference K
int countKDifference(vector<int>&arr, int k) 
{
    int n=arr.size();
    int count=0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(abs(nums[i]-nums[j])==k)
            {
                count++;
            }
        }
    }
    return count;
}

//optimal approach 
int countKDifference(vector<int>&arr, int k) 
{
    unordered_map<int, int>mp;
    int count=0;
    // |x - y| = k => y = x + k or y = x - k
        
    for (auto it : arr) 
    {
        count+=mp[it+k] + mp[it-k];
        // If y1 and/or y2 is present, they can form a pair with x
        mp[num]++;
    }
    return count;
}

//167. Two Sum II - Input Array Is Sorted 
int twosum-11(int arr[], int n, int target)
{
    int start=0;
    int end=arr.size()-1;
    while(start<end)
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

//453. Minimum Moves to Equal Array Elements
int minimummove(int arr[], int n)
{
    sort(nums.begin(), nums.end());
    int start=0;
    int end=nums.size()-1;
    int count=0;
    while(start<end)
    {
        count+=nums[end]-nums[start];
        start++;
        end--;
    }
    return count;
}

//453. Minimum Moves to Equal Array Elements
int minimummove(int arr[], int n)
{
    sort(arr, arr+n);
    int count=0;
    for(int i=0; i<n; i++)
    {
        count+=arr[i]-arr[0];
    }
    return count;
}

//462 Minimum Moves to Equal Array Elements-2
int minimummove(int arr[], int n)
{
    sort(nums.begin(), nums.end());
    int start=0;
    int end=nums.size()-1;
    int count=0;
    while(start<end)
    {
        count+=nums[end]-nums[start];
        start++;
        end--;
    }
    return count;
}
//1658. Minimum Operations to Reduce X to Zero
int minOperations(vector<int>& nums, int x) 
{
    int sum=0; 
    int n=nums.size();
    for (auto it : nums) 
    sum += it;
    int target = sum - x;
    int currSum = 0;
    int maxLen=0;
    int i = 0; //starting index of subarray
    bool found = false;
    for (int j = 0; j < n; j++) 
    {
        currSum += nums[j];
            
        //shrinking our window
        while (i <= j && currSum > target) 
        {
            currSum -= nums[i];
            i += 1;
        }
        if (currSum == target) 
        {
            found = true;
            maxLen = max(maxLen, j - i + 1);
        }
    }
    return found ? n - maxLen : -1;
}




//contain duplicate (this means if any element in array are duplicate than return true other wise false) brute force approach(n^2) 
bool containduplicate(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]==arr[j])
            {
                return true;
            }
        }
    }
    return false;
}

//better approach (sorting)
bool containduplicate2(int arr[], int n)
{
    sort(arr, arr+n);
    for(int i=1; i<n; i++)
    {
        if(arr[i]==arr[i-1])
        {
            return true;
        }
    }
    return false;
}

//optimal approach (hashmap)
bool containduplicate3(int arr[], int n)
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
            return true;
        }
    }
    return false;
}

//contain duplicate --II (given k find the arr[i]==arr[j] and i-j<=k )
bool containduplicate-II(int arr[], int n, int k)
{
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        if(mp.find(arr[i])!=mp.end())
        {
            if(abs(mp[arr[i]]-i)<=k)
            {
                return true;
            }
        }
        mp[arr[i]]=i;
    }
    return false;
}

//contain duplicate-- III (given k and t find two element abs(arr[j]-arr[j]<=t && abs(i-j)<=k))
bool containduplicate-III(int arr[], int n, int t, int k)
{
    set<int>st(arr, arr+n);
    if(t==0 && n=st.size())
    return false;
    
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<i+1+k; j++)
        {
            if(j>=n)
            break;
            if(abs(long long)arr[i]-arr[j])<=t)
            {
                return true;
            }
        }
    }
    return false;
}

// concatenation of array 
int concatenation(vector<int>num)
{
    vector<int>ans;
    int n=num.size();
    for(int i=0; i<n; i++)
    {
        ans.push_back(num[i]);
    }
    for(int i=0; i<n; i++)
    {
        ans.push_back(num[i]);
    }
    return ans;
}

//second method
int concatenation(vector<int>num)
{
    int n=num.size();
    for(int i=0; i<n; i++)
    {
        num.push_back(num[i]);
    }
    return num;
}




