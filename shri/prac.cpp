

//reverse array using inbuilt function 
void reverse1(int arr[], int n)
{
    reverse(arr, arr+n);
}

//reverse array
void reverse2(int arr[] , int n)
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
void reverse4(int arr[], int n, int k)
{
    for(int i=0; i<n; i+=k)
    {
        if(i+k<n)
        {
            reverse(arr+i, arr+k);
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
        int digit=n%10;
        ans=ans*10+digit;
        n=n/10;
    }
    return ans;
}

//check array are palindrome or not
bool palindrome(int arr[] , int n)
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

//array are sorted or not 
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
vector<int>movenegative(int arr[], int n)
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
void moveneg(int arr[], int n)
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
vector<int>movezero(int arr[], int n)
{
    vector<int>ans;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>0)
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
vector<int>alternatesign(int arr[], int n)
{
    vector<int>pos;
    vector<int>neg;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>0)
        {
            pos.push_back(arr[i]);
        }
        else 
        {
            neg.push_back(arr[i]);
        }
    }
    
    for(int i=0; i<n/2; i++)
    {
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    }
    return arr;
}
//optimal approach when order is not matter 
void alternatesign2(int arr[] ,int n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        while(i<=n && arr[i]>0)
        i++;
        
        while(j>0 && arr[j]<0)
        j--;
        
        if(i<j)
        {
            swap(arr[i], arr[j]);
        }
    }
    
    if(i==0 || i==n)
    return ;
    
    int k=0;
    while(i<n && k<n)
    {
        swap(arr[i], arr[k]);
        i++;
        k+=2;
    }
}
//when order will be matter than above solution will be not work optimal approach 
vector<int>alternate(int arr[], int n)
{
    vector<int>ans(n, 0);
    int pos=0;
    int neg=1;
    for(int i=0; i<n; i++)
    {
        if(arr[i]<0)
        {
            ans[neg]=arr[i];
            neg+=2;
        }
        else 
        {
            ans[pos]=arr[i];
            pos+=2;
        }
    }
    return ans;
}

//second version of alternate sign arrangement when not equal positve and negative element 
movenegative<int>alternate(int arr[], int n)
{
    vector<int>pos;
    vector<int>neg;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>0)
        {
            pos.push_back(arr[i]);
        }
        else 
        {
            neg.push_back(arr[i]);
        }
    }
    
    if(pos.size()>neg.size())
    {
        for(int i=0; i<neg.size(); i++)
        {
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        
        int index=neg.size()*2;
        for(int i=neg.size(); i<pos.size(); i++)
        {
            arr[index]=pos[i];
            index++;
        }
    }
    else 
    {
        for(int i=0; i<pos.size(); i++)
        {
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        
        int index=pos.size()*2;
        for(int i=pos.size(); i<neg.size(); i++)
        {
            arr[index]=neg[i];
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
void sort012(int arr[], int n)
{
    int conunt0=0;
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
int maximum(int arr[], int n)
{
    sort(arr, arr+n);
    return arr[n-1];
}

//optimal approach
int maximumele(int arr[], int n)
{
    int maxi=arr[0];
    for(int i=1; i<n; i++)
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
int secondsmallestele(int arr[], int n)
{
    int smallest=INT_MAX;
    int sec=INT_MAX;
    for(int i=0; i<n; i++)
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
class cmp
{
    bool operator()(string &a, string &b)
    {
        if(a.length()>b.length())
        return a.length()<b.length();
        
        return a<b;
    }
}
string kthsmallestele(vector<string>arr, int n, int k)
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
int thirdlergest(int arr[], int n)
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
    
    if(flage==1)
    return c;
    
    return a;
}

//monotonic array (An array is monotonic if it is either monotone increasing or monotone decreasing.)
bool monotonic(int arr[], int n)
{
    bool inc=false;
    bool dec=false;
    for(int i=0; i<n; i++)
    {
        if(arr[i]<arr[i+1])
        inc=true;
        
        if(arr[i]>arr[i+1])
        dec=true;
    }
    
    if(inc==true && dec==true)
    return false;
    
    return true;
}

//find unique element in array bruteforce approach 
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
vector<int> allunique(int arr[], int n)
{
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    
    vector<int>ans;
    for(int i=0; i<n; i++)
    {
        if(mp[arr[i]]==1)
        {
            ans.push_back(arr[i]);
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
        st.push(it.second);
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
int duplicateele(int arr[], int n)
{
    int ans=0
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
int allduplicate(int arr[], int n)
{
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    
    vector<int>ans;
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

//contain duplicate (this means if any element in array are duplicate than return true other wise false) brute force approach(n^2) 
//better approach (sorting)
//optimal approach (hashmap)
//contain duplicate --II (given k find the arr[i]==arr[j] and i-j<=k )
//contain duplicate-- III (given k and t find two element abs(arr[j]-arr[j]<=t && abs(i-j)<=k))
// concatenation of array 
//second method
//find the leader of array 
vector<int>leader(int arr[], int n)
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
        int rightsum=totalsum -leftsum-arr[i];
        if(leftsum==rightsum)
        {
            return arr[i];
        }
        
        leftsum+=arr[i];
    }
    return -1;
}

//number of steps to reduce a number to zero
int stepstoreduce0(int n)
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

//longest subarray of 1's after deleting one element
int maxiconsedelone0(int arr[], int n)
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
        count=max(count, j-i);
    }
    return count;
}

//max consecutive ones if k number of zero is filp  to one 
int maxiconseflipk(int arr[], int n, int k)
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
int maxiconseflip10(int arr[], int n)
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
int maxiconse(int arr[], int n)
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
int common(int arr1[], int arr2[], int arr3[], int n, int m, int p)
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
int union(int arr1[], int arr2[], int n, int m)
{
    unordered_set<int>st;
    vector<int>ans;
    
    for(int i=0; i<n; i++)
    {
        st.push(arr1[i]);
    }
    for(int i=0; i<m; i++)
    {
        st.push(arr2[i]);
    }
    for(auto it : st)
    {
        ans.push_back(it);
    }
    return ans;
}

//using two pointer 
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
int boatsave(int arr[], int n, int limit)
{
    sort(arr, arr+n);
    int start=0;
    int end=n-1;
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
int validmountain(int arr[], int n)
{
    int i=0;
    int j=n-1;
    while(i+1<n && arr[i]<arr[i+1])
    i++;
    
    while(j-1>0 && arr[j-1]<arr[j])
    j--;
    
    return i==j;
}

//longest mountain array 
int longmountain(int arr[], int n)
{
    int maxi=-1;
    for(int i=1; i<n-1; i++)
    {
        if(arr[i]>arr[i+1] && arr[i]>arr[i-1])
        {
            int j=i;
            int count=1;
            while(j>=0 && arr[j]>arr[j-1])
            {
                j--;
                count++;
            }
            while(j<n && arr[j]>arr[j+1])
            {
                j++;
                count++;
            }
        }
        maxi=max(maxi, count);
    }
    return maxi;
}

//contain with most water 
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
int majority-II(int arr[], int n)
{
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    for(auto it : mp)
    {
        if(it.second>n/3)
        {
            return it.first;
        }
    }
    return -1;
}

//optimal approach
int majority2-II(int arr[], int n)
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
        else if(count2==0 && el1!=arr[i])
        {
            count2=0;
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
    for(int j=0; j<n; j++)
    {
        if(el1==arr[j])
        {
            count3++;
        }
        if(el2==arr[j])
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
    return i+1;
}

//remove value from array 
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
int rotatebyoneplace(int arr[], int n)
{
    int temp=arr[0];
    for(int i=1; i<n; i++)
    {
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    rotate arr;
}

//rotate array by d place bruteforce approach
int rotatebydplace(int arr[], int n, int d)
{
    vector<int>ans;
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
        arr[i]=ans[i-(n-d)];
    }
}

//optimal approach 
int rotatebydplace(int arr[], int n, int d)
{
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}

//squares of a sorted array bruteforce approach 
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
int squares(int arr[], int n)
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
int productofitself(int arr[], int n)
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
int productofitself2(int arr[], int n)
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
int productofitself3(int arr[], int n)
{
    vector<int>ans;
    int prod=1;
    for(int i=0; i<n; i++)
    {
        prod*=arr[i];
        ans.push_back(prod);
    }
    
    prod=1;
    for(int i=n-1; i>0; i--)
    {
        ans[i]=ans[i+1]*prod;
        prod*=arr[i];
    }
    ans[0]=prod;
    return ans;
}

//count pairs whose sum is less than target 
//optimal approach 
//max number of K-sum pairs bruteforce approach (in this problem deleting pair )
//better approach 
//optimal approach
//two sum II - input array is sorted 
int twosum-II(int arr[], int n, int target)
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

//count number of pairs with absolute difference K
//optimal approach 
//count good meals (adding two element in array than equal to power of two)
//number of pairs of strings with concatenation equal to target
//optimal approach
//two sum bruteforce approach 
int two(int arr[], int n, int target)
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
int twosum(int arr[], int n, int target)
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
int three(int arr[], int n, int target)
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
vector<vector<int>>threesum(int arr[], int n, int target)
{
    sort(arr, arr+n);
    vector<vector<int>>ans;
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
                    tem.push_back(arr[i]);
                    tem.push_back(arr[start]);
                    tem.push_back(arr[end]);
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
int four(int arr[], int n, int target)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                for(int p=k+1<n; p++)
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
vector<vector<int>>foursum(int arr[], int n, int target)
{
    sort(arr, arr+n);
    vector<vector<int>>ans;
    for(int i=0; i<n-2; i++)
    {
        if(i==0 && (i>0 && arr[i]!=arr[i-1]))
        {
            for(int j=i+1; j<n-1; j++)
            {
                if(j==i && (j>1 && arr[j]!=arr[j-1]))
                {
                    int start=j+1;
                    int end=n-1;
                    int sum=target-(arr[i]+arr[j]);
                    
                    while(start<end)
                    {
                        if(arr[start]+arr[end]==sum)
                        {
                            vector<int>temp;
                            tem.push_back(arr[i]);
                            tem.push_back(arr[j]);
                            tem.push_back(arr[start]);
                            tem.push_back(arr[end]);
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
int four-II(int arr1[], int arr2[], int arr3[], int arr4[], int n)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                for(int p=k+1<n; p++)
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
int foursum-II(int arr1[], int arr2[], int arr3[], int arr4[], int n)
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
int maxisubarrsum2(int arr[], int n)
{
    int maxi=-1;
    for(int i=0; i<n; i++)
    {
        int sum=0;
        for(int j=i; j<n; j++)
        {
            sum+=arr[i];
            maxi=max(maxi, sum);
        }
    }
    return maxi;
}


//optimal approach
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
    for(int i=n-1; i>0; i--)
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
int maxisubarrsumK3(int arr[], int n, int k)
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
int longsubarrsumK(int arr[], int n)
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
int longsubarrsumK2(int arr[], int n)
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
int longsubarrsumK3(int arr[], int n)
{
    int maxlen=-1;
    int sum=arr[0];
    int start=0;
    int end=n-1;
    while(start<=end)
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
            if(sum>=target)
            {
                mini=min(mini, len);
                break;
            }
        }
    }
    
    if(mini==INT_MAX)
    return 0;
    
    return mini;
}

//optimal approach  
int minisizesubarr2(int arr[], int n, int k)
{
    int mini=INT_MAX;
    int start=0;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        while(sum>=target)
        {
            mini=min(mini, i-start+1);
            sum-=arr[start];
            start++;
        }
    }
    
    if(mini==INT_MAX)
    return 0;
    
    return mini;
}

//sliding window maximum bruteforce approach 
int sliding(int arr[], int n, int k)
{
    vector<int>ans;
    for(int i=0; i<n-k; i++)
    {
        int currmax=INT_MIN;
        for(int j=i; j<k-i; j++)
        {
            currmax=max(currmax, arr[j]);
        }
        ans.push_back(currmax);
    }
    return ans;
}

//optimal approach 
int slidingwindow(int arr[], int n)
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
int subarrprodlessk(int arr[], int n, int target)
{
    int prod=1;
    int mini=-1;
    int j=0;
    for(int i=0; i<n; i++)
    {
        prod*=arr[i];
        if(prod>=target)
        {
            prod=prod/arr[j];
            j++;
        }
        mini=min(mini, i-j+1);
    }
    return mini;
}

//sorted unsorted continuous subarray 
int unsorted(int arr[], int n)
{
    int start=0;
    int end=n-1;
    while(start+1<n && arr[start]<arr[start+1])
    start++;
    
    while(end-1>0 && arr[end-1]<arr[end])
    end--;
    
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=start; i<=end; i++)
    {
        mini=min(mini, arrr[i]);
        maxi=max(maxi, arrr[i]);
    }
    
    while(start-1>0 && arr[start]>mini)
    start--;
    
    while(end+1<n && arr[end]<maxi)
    end++;
    
    return end-start+1;
}

//traping rain water bruteforce approach 
int trapint(int arr[], int n)
{
    int watertraped=0;
    for(int i=0; i<n; i++)
    {
        int leftmax=0;
        int rightmax=0;
        int j=i;
        while(j>=0)
        {
            leftmax=max(leftmax, arrr[j]);
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
int traping(int arr[], int n)
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
        watertraped+=max(prefix[i], suffix[i])-arr[i];
    }
    return watertraped;
}

//optimal approach
int traping(int arr[], int n)
{
    int leftmax=0;
    int rightmax=0;
    int start=0;
    int end=n-1;
    int watertraped=0;
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
//linear search
int linear(int arr[] , int n, int target)
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
int orderbinary(int arr[], int n, int target)
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
    int ans=-1;
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
    int ans=-1;
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
int ceilvalue(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    int ans=-1;
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
int miniinrotated(int arr[], int n)
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
int miniinrotated2(int arr[], int n)
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
int searchinrotated(int arr[], int n, int target)
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
bool searchinrotated2(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
        {
            return true;
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
int square(int n)
{
    int start=0;
    int end=n-1;
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
int searchinsertpos(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    int ans=-1;
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
//Minimum days to make M bouquets 
//Find the Smallest Divisor Given a Threshold
//Capacity to Ship Packages within D Days
//book allocation problem 
//Aggressive cow problem 
//painter partition problem
//split array largest sum 

//--------------------------------------------------------------------------------------------------------
//cyclic sort 
void cyclicsort(int arr[], int n)
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
int missingnumber(int arr[], int n)
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
vector<int>alldisappeared(int arr[], int n)
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
int missingposnumber(int arr[], int n)
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
vector<int>setmismatch(int arr[], int n)
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
int lengthList(ListNode*head)
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
int binary(ListNode*head)
{
    if(head==NULL)
    return 0;
    
    int count=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        count*=2;
        count+=temp->val;
        temp=temp->next;
    }
    return count;
}

//reverse linked list recursive method
ListNode*reverseRec(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    ListNode*newhead=reverseRec(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

//reverse linked list iterative method 
ListNode*reverseIter(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
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
    
//reverse linked list in k group
ListNode*reverseK(ListNode*head, int k)
{
    if(head==NULL || head->next==NULL)
    return head;
    
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
 
//middle of linked list 
ListNode*middle(ListNode*head)
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
    
    temp=head;
    int half=count/2;
    while(half--)
    {
        temp=temp->next;
    }
    return temp;
}

//2-method to find the middle element in list 
ListNode*middle(ListNode*head)
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
bool loop(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
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
ListNode*starting(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
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
ListNode*removeloop(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
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
ListNode*removeduplicate2(ListNode*head)
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
            ListNode*del=temp->next;
            temp->next=temp->next->next;
            delete del;
        }
        else 
        {
            st.push(temp->val);
            pre=temp;
        }
    }
}

//palindrome linked list 
bool palindrome(ListNode*head)
{
    ListNode*slow=head;
    ListNode*fast=head;
    ListNode*pre=NULL;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    
    pre->next=NULL;
    ListNode*first=head;
    ListNode*second=reverse(slow->next);
    if(second!=NULL)
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
ListNode*mergeRec(ListNode*head1, ListNode*head2)
{
    if(head1==NULL)
    return head2;
    
    if(head2==NULL)
    return head1;
    
    if(head1->val<head2->val)
    {
        head1->next=mergeRec(head1->next, head2);
        return head1;
    }
    else 
    {
        head2->next=mergeRec(head1, head2->next);
        return head2;
    }
}

//second method to merge linked list 
ListNode*mergeIter(ListNode*head1, ListNode*head2)
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
    
    if(head1!=NULL)
    {
        tail->next=head1;
    }
    if(head2!=NULL)
    {
        tail->next=head2;
    }
    return duumy->next;
}

//merge k linked list 
ListNode*merge(vector<vector<ListNode*>>list)
{
    if(list.size()==0)
    return NULL;
    
    if(list.size()==1)
    return list[0];
    
    ListNode*ans=merge(list[0], list[1]);
    for(int i=2; i<list.size(); i++)
    {
        ans=merge(list[i], ans);
    }
    return ans;
}

//second method to merge k linked list 
ListNode*merge(vector<vector<ListNode*>>list)
{
    if(list.size()==0)
    return NULL;
    
    if(list.size()==1)
    return list[0];
    
    for(int i=0; i<list.size(); i++)
    {
        if(list[i]!=NULL)
        {
            st.push(list[i]);
        }
    }
    
    while(st.size()==0)
    {
        
    }
}

//intersection of linked list 
ListNode*intersection(ListNode*head1, ListNode*head2)
{
    int len1=lengthList(head1);
    int len2=lengthList(head2);
    
    ListNode*temp1=head1;
    ListNode*temp2=head2;
    
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
        temp1=temp->next;
        temp2=temp2->next;
    }
    return temp1;
}


//second method to find intersection of linked list 
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

//odd or even linked list 
ListNode*oddeven(ListNode*head)
{
    ListNode*oddh=head;
    ListNode*odd=oddh;
    ListNode*evenh=head->next;
    ListNode*even=evenh;
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
ListNode*oddeven2(ListNode*head)
{
    ListNode*oddh=NULL;
    ListNode*odd=NULL;
    ListNode*evenh=NULL;
    ListNode*even=NULL;
    int count=1;
    while(head!=NULL)
    {
        if(count%2==0)
        {
            if(evenh==NULL)
            {
                evenh=head;
                even=evenh;
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
                odd=oddh;
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
    return head;
}

//delete node where head or not given 
ListNode*deletenode(ListNode*del)
{
    ListNode*temp=del->next;
    del->val=temp->val;
    del->next=temp->next->next;
    delete temp;
}

//check two linked list are identical or not 
bool identical(ListNode*head1, ListNode*head2)
{
    if(head2==NULL && head1==NULL)
    return true;
    
    if(head1!=NULL || head2!=NULL)
    return false;
    
    int len1=lengthList(head1);
    int len2=lengthList(head2);
    if(len1!=len2)
    return false;
    
    ListNode*temp1=head1;
    ListNode*temp2=head2;
    while(head2!=NULL && head1!=NULL)
    {
        if(temp1->val!=temp2->val)
        {
            return false;
        }
        temp1=temp->next;
        temp2=temp2->next;
    }
    return false;
}

// Nth node from end of linked list 
//swap node pairwise 
ListNode*swappairwise(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
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
        head->next=reverseK(nextn);
    }
    return pre;
}
 
//swap node kth from starting and kth from end in linked list 
//2-method 
//add two linked list 
ListNode*add(ListNode*head1, ListNode*head2)
{
    ListNode*dummy=new ListNode(0);
    ListNode*tail=dummy;
    int carry=0;
    while(head1!=NULL && head2!=NULL)
    {
        int sum=carry+head1->val+head2->val;
        carry=sum/10;
        tail->next=new ListNode(sum%10);
        tail=tail->next;
        head1=head1->next;
        head2=head2->next;
    }
    while(head1!=NULL)
    {
        int sum=carry+head1->val;
        carry=sum/10;
        tail->next=new ListNode(sum%10);
        tail=tail->next;
        head1=head1->next;
    }
    while(head2!=NULL)
    {
        int sum=carry+head2->val;
        carry=sum/10;
        tail->next=new ListNode(sum%10);
        tail=tail->next;
        head2=head2->next;
    }
    if(carry==1)
    {
        tail->next=new ListNode(carry);
    }
    return dummy->next;
}

//second version 
ListNode*add(ListNode*head1, ListNode*head2)
{
    head1=reverse(head1);
    head2=reverse(head2);
    
    ListNode*dummy=new ListNode(0);
    ListNode*tail=dummy;
    int carry=0;
    while(head1!=NULL && head2!=NULL)
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
//rotate linked list 


//Partition linked List 
ListNode*Partition(ListNode*head, int x)
{
    ListNode*largeh=new ListNode(0);
    ListNode*large=largeh;
    ListNode*smallh=new ListNode(0);
    ListNode*small=smallh;
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
    small->next=largeh->next;
    return smallh->next;
}

//reorder linked list 
//insertion sort in linked list
//sort 0s 1s 2s linked list  
//flattening of linked list 



//-------------------------------------------------------------------------------------------- 
//reverse string using stack 
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
void slove(stack<int>&st, int count, int size)
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
    slove(st, count, n);
}

//valid parenthesis  {([])
bool parenthesis(string s)
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
                    return true;
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
    return true;
    
    return false;
}

//insertatbottom in stack 
void slove(stack<int>&st, int num)
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
void insertatbottom(stack<int>st, int ele)
{
    slove(st, ele);
}

//reverse stack 
void insertbottom(stack<int>&st, int num)
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
    reversestack(st);
    insertbottom(st, take);
}

//sort stack 
void insertsorted(stack<int>&st, int num)
{
    if(st.empty() || st.top()<num)
    {
        st.push(num);
        return ;
    }
    
    int take=st.top();
    st.pop();
    
    insertsorted(st, num);
    st.push(take);
}
void sortstack(stack<int>st)
{
    if(st.empty())
    return ;
    
    int take=st.top();
    sortstack(st);
    insertsorted(st, take);
}

//redundant bracket (-,+,/ ,*)
bool parenthesis(string s)
{
    int n=s.length();
    stack<char>st;
    
    for(int i=0; i<n; i++)
    {
        char ch=s[i];
        if(ch=='(' || ch=='*' || ch=='+' || ch=='-' || ch==/)
        {
            st.push(ch);
        }
        else 
        {
            if(!st.empty())
            {
                bool flage=true;
                if(!st.empty() && st.top()!='(')
                {
                    char top=st.top();
                    if(top=='*' || top=='+' || top=='-' || top=='/')
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
int minimumcost(string s)
{
    int n=s.length();
    stack<int>st;
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
                st.puhs(ch);
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
    int ans=(b+1)/2+(a+1)/2;
    return ans;
}

//Minimum Number of Swaps to Make the String Balanced  ]][[[]]][[
//132 pattern bruteforce approach 
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
            mini=min(mini, arrr[j]);
        }
    }
    return false;
}

//optimal approach 
bool pattern132(int arr[], int n)
{
    int thirdele=-1;
    stack<int>st;
    for(int i=0; i<n; i++)
    {
        if(arr[i],thirdele)
        {
            return true;
        }
        while(!st.empty() && st.top()<=arr[i])
        {
            thirdele=st.top();
            st.pop()
        }
        st.push(arr[i]);
    }
    return false;
}

//next smaller element in array 
int nextsmaller(int arr[], int n)
{
    vector<int>ans;
    stock<int>st;
    st.push(-1);
    for(int i=n-1; i>=0; i--)
    {
        if(!st.empty() && st.top()>=arr[i])
        {
            st.pop();
        }
        
        ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}

//previous smaller element int array 
int previoussmaller(int arr[], int n)
{
    vector<int>ans;
    stock<int>st;
    st.push(-1);
    for(int i=0; i<n; i++)
    {
        if(!st.empty() && st.top()>=arr[i])
        {
            st.pop();
        }
        
        ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}

//next greater element in array 
int nextgreater(int arr[], int n)
{
    vector<int>ans;
    stock<int>st;
    st.push(-1);
    for(int i=n-1; i>=0; i--)
    {
        if(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }
        
        ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}

//previous greater element in array
int previousgreater(int arr[], int n)
{
    vector<int>ans;
    stock<int>st;
    st.push(-1);
    for(int i=0; i<n; i++)
    {
        if(!st.empty() && st.top()<=arr[i])
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
bool ispoweroftwo(int n)
{
    return n>0 && (n&(n-1))==0;
}

//number is power of three or not 
bool powerofthree(int n)
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
bool poweroffour(int n)
{
    return n>0 && (n&(n-1))==0 && (n%3==1);
}

//kid with the greatest number of candies (given array of candies and int extracandies return bool of vector ) 
vector<bool>greatest(int arr[], int n, int etra)
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
        if(arr[i]+extra>largest)
        {
            ans.push_back(true);
        }
        else 
        {
            ans.push_back(false);
        }
    }
    return ans;
}

//running sum of 1d array (this means prefix of sum ) 1,2,3,4 == 1,3,6,10
vector<int>running(int arr[], int n)
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
int goodpair(int arr[], int n)
{
    int count=0;
    fo(int i=0; i<n; i++)
    {
        for(int j=i+1;  j<n; j++)
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
int goodpair(int arr[], int n)
{
    int count=0;
    vector<int>freq;
    for(int i=0; i<n; i++)
    {
        freq[arr[i]]++;
    }
    
    for(int i=0; i<100; i++)
    {
        count+=(freq[i]*(freq[i]-1))/2;
    }
    return count;
}

//two out of three (this means given three array find the common element in array atleast in  two array common ) 
vector<int>twoourthree(int arr1[], int arr2[], int arr3[], int n, int m, int p)
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
    
    for(int i=1; i<=100; i++)
    {
        if(v1[i]+v2[i]+v3[i]>2)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

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

//preorder traversal 
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
        
        if(root->left!=NULL)
        st.push(root->left);
        
        if(root->right!=NULL)
        st.push(root->right);
        
        ans.push_back(root->val);
    }
    return ans;
}

//inorder traversal 
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
    st.push(root);
    while(true)
    {
        if(node->left!=NULL)
        {
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
        ans.push_back(st2.top());
        st2.pop();
    }
    return ans;
}

//maximum depth of binary tree 
int maximumdepth(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=maximumdepth(root->left);
    int rh=maximumdepth(root->right);
    
    return 1+max(lh, rh);
}

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
int height(tree*root, int &maxi)
{
    if(root==NULL)
    return 0;
    
    int lh=height(root->left, maxi);
    int rh=height(root->right, maxi);
    
    maxi=max(maxi, lh+rh);
    
    return 1+max(lh, rh);
}
int diameterBT(TreeNode*root)
{
    int diameter=0;
    height(root, diameter);
    return diameter;
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
int maximumpath(TreeNode*root)
{
    int maxi=0;
    pathsum(root, maxi);
    return maxi;
}

//check two tree is identical/same  or not
bool identical(TreeNode*root1, TreeNode*root2)
{
    if(root1==NULL && root2==NULL)
    return true;
    
    if(root1==NULL && root2!=NULL)
    return false;
    
    if(root1!=NULL && root2==NULL)
    return false;
    
    return (root1->val==root2->val) && identical(root1->left, root2->left) && identical(root1->right, root2->right);
}

//check symmetric tree  or not 
bool issame(TreeNode*root1, TreeNode*root2)
{
    if(root1==NULL && root2==NULL)
    return true;
    
    if(root1==NULL && root2!=NULL)
    return false;
    
    if(root1!=NULL && root2==NULL)
    return false;
    
    return (root1->val==root2->val) && issame(root1->left, root2->left) && issame(root1->right, root2->right);
}
bool symmetric(TreeNode*root)
{
    return issame(root->left, root->right);
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

//average of level of binary tree  
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

//level order successor of a node in binary tree 
int successor(TreeNode*root, int key)
{
    vector<vector<int>>ans;
    if(root==NULL)
    return ans;
    
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
vector<vector<int>>zig-zag(TreeNode*root)
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
            
            int index=lefttoright ? i : size-1-i;
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

//right side view of binary tree 
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
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            if(i==size-1)
            ans.push_back(node->val);
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
            
            sum+=node->val;
        }
    }
    return sum;
}

//find largest value in each row
vector<int>largest(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    int maxi=INT_MIN;
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
            
            maxi=max(maxi, node->val);
        }
        ans.push_back(maxi);
    }
    return ans;
}

//find bottom left tree value 
int bottomleft(TreeNode*root)
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
        q.push(root->left );
    }
    return root->val;
}

//convert sorted array to binary search tree
TreeNode*makeTree(vector<int>&arr, int start, int end)
{
    if(start>end)
    return ;
    
    int mid=(start+end)/2;
    TreeNode*root=new TreeNode(arr[mid]);
    
    root->left=makeTree(arr, start, mid-1);
    root->right=makeTree(arr, mid+1, end);
    
    return root;
}
TreeNode*convertsortedarrtoBST(vector<int>&arr)
{
    return makeTree(arr, 0, arr.size()-1);
}

//convert sorted linked list to binary search tree 
TreeNode*makeTree(vector<int>&arr, int start, int end)
{
    if(start>end)
    return ;
    
    int mid=(start+end)/2;
    TreeNode*root=new TreeNode(arr[mid]);
    
    root->left=makeTree(arr, start, mid-1);
    root->right=makeTree(arr, mid+1, end);
    
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
    
    return makeTree(ans, 0, ans.size()-1);
}

//second mathod 
TreeNode*convertsortedlisttoBST(ListNode*head)
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
    
    root->left=convertsortedlisttoBST(head);
    root->right=convertsortedlisttoBST(slow->next)
    
    return root;
}

//make maximum binary tree 
TreeNode*makeTree(vector<int>&arr, int start, int end)
{
    if(start>end)
    return ;
    
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
    
    root->left=makeTree(arr, start, maxindex-1);
    root->right=makeTree(arr, maxindex+1, end);
    
    return root;
}
TreeNode*maximumBT(vector<int>&arr)
{
    return makeTree(arr, 0, arr.size()-1);
}

//construct binary tree from preorder and inorder
TreeNode*makeBT(vector<int>&preorder, vector<int>&inorder, int ps, int pe, int is, int ie, unordered_map<int,int>&mp)
{
    if(ps>pe || is>ie)
    return NULL;
    
    TreeNode*root=new TreeNode(preorder[ps]);
    int pos=mp[root];
    int left=pos-is;
    
    root->left=makeBT(preorder, inorder, ps, ps+left-1, is, pos-1, mp);
    root->right=makeBT(preorder, inorder, ps+left+1, pe, pos+1, ie, mp);
    
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
    
    return makeBT(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
}

//construct binary tree from inorder and postorder 
TreeNode*makeBT(vector<int>&postorder, vector<int>&inorder, int ps, int pe, int is, int ie, unordered_map<int,int>mp)
{
    if(ps>pe || is>ie)
    return NULL;
    
    TreeNode*root=new TreeNode(postorder[pe]);
    int pos=mp[root];
    int left=pos-is;
    
    root->left=makeBT(postorder, inorder, ps, ps+left-1, is, pos-1, mp);
    root->right=makeBT(postorder, inorder, ps+left+1, pe-1, pos+1, ie, mp);
    
    return root;
}
TreeNode*constructBT(vector<int>postorder, vector<int>inorder)
{
    if(postorder.size()!=inorder.size())
    return NULL;
    
    unordered_map<int,int>mp;
    for(int i=0; i<inorder.size(); i++)
    {
        mp[inorder[i]]=i;
    }
    
    return makeBT(preorder, inorder, 0, postorder.size()-1, 0, inorder.size()-1);
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
void slove(TreeNode*root, int targetsum, int sum)
{
    if(root==NULL)
    return ;
    
    path.push_back(root->val);
    sum+=root->val;
    if(root->left==NULL && root->right==NULL && targetsum==sum)
    {
        ans.push_back(path);
    }
    
    slove(root->left, targetsum, sum);
    slove(root->right, targetsum, sum);
    path.pop_back();
}
vector<vector<int>>pathsumBT(TreeNode*root, int targetsum)
{
    int sum=0;
    slove(root, targetsum, sum);
    return ans;
}

//binary tree path 
//sum root to leaf number (node 1->2->3==123 and so on )
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
//lowest common ancestor of deepest leaves(both have same solution)  ----1123 
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

