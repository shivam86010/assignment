
//reverse array using inbuilt function 
//reverse array 
//reverse array pairwise 
//reverse array group size k 
//reverse integer 
//check array are palindrome or not 
//wave array (given sorted array convert wave from)
//array are sorted or not 
//move negative element at the end of array using bruteforce approach 
//optimal approach 
//move zero at the end of array using bruteforce approach 
//optimal approach 
//arrange alternate sign element in array 
//parity sort 
//O 1 2 sort 
//dnf sort 
//three way partition of array
void threeway(int arr[], int n, int a, int b)
{
    int start=0;
    int mid=0;
    int end=n-1;
    while(mid<end)
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
//optimal approach 
//find the maximum element in array using bruteforce approach 
//optimal approach
//second largest element in array bruteforce approach 



























//optimal approach


//second smallest element in array bruteforce approach 
//optimal approach 
//find the kthsmallest element in array 
//find the kthlargest element in array 
//Find the Kth Largest Integer in the Array
//third largest element in array 
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
        return arr[i];
    }
    return -1;
}
int uniquebetter(int arr[], int n)
{
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }

    for(auto it : mp)
    {
        if(it.second==1)
        return it.first;
    }
    return -1;
}
int uniqueoptimal(int arr[], int n)
{
    int ans=0;
    for(int i=0; i <n; i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}
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

        if(count>1)
        {
            return arr[i];
        }
    }
    return -1;
}
int duplicatebetter(int arr[], int n)
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
int optimal(int arr[], int n)
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
















//better approach 
//optimal approach 
//Non Repeating Numbers (means more than one unique element in array )
//unique number of occurence 
//sum of unique element in array 
//find duplicate element in array using bruteforce approach 
//better approach 
//optimal approach 
//find all duplicate element in array using bruteforce approach 
//optimal approach 
//contain duplicate (this means if any element in array are duplicate than return true other wise false) brute force approach(n^2) 
//better approach (sorting)
//optimal approach (hashmap)
//contain duplicate --II (given k find the arr[i]==arr[j] and i-j<=k )
//contain duplicate-- III (given k and t find two element abs(arr[j]-arr[j]<=t && abs(i-j)<=k))
// concatenation of array 
//second method
//find the leader of array 
//find the equlibrium point  
//number of steps to reduce a number to zero
//longest subarray of 1's after deleting one element
//max consecutive ones if k number of zero is filp  to one  
//maximum consecutive ones if filp atleast one zero to one 
//maximum consecutive ones  
//number of zero filled subarray 
//nextpermutation of array 
//intersection of two array 
//common element 
//union of two array hashmap 
//using hash set 
//using two pointer 
//valid triangle  bruteforce approach  
//optimal approach 
//boat save people 
//valid mountain array 
//longest mountain array 
//contain with most water 
//majority element bruteforce approach 

int majoritybrute(int arr[], int n)
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

        if(count==n/2)
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
        if(it.second==n/2)
        {
            return it.first;
        }
    }
    return -1;
} 
//optimal approach 
int majorityoptimal(int arr[], int n)
{
    int el;
    int count=0;
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
    for(int i=0; i<n; i++)
    {
        if(el==arr[i])
        {
            count1++;
        }
    }

    if(count1==n/2)
    return el;

    return -1;
}
//majority-II  bruteforce approach 




int majority(int arr[], int n)
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

        if(count>n/3)
        return arr[i];
    }
    return -1;
}

int majoritybetter(int arr[], int n)
{
    unordered_map<int, int>mp;
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
int majorityopt(int arr[], int n)
{
    int count1=0;
    int count2=0;
    int el1, el2;
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
        if(el1==arr[i])
        {
            count3++;
        }
        else if(el2==arr[i])
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

ListNode*swapPair(ListNode*head)
{
    if(head==null || head->next==null)
    return head;

    ListNode*curr=head;
    ListNode*pre=nullptr;
    int count=0;
    while(curr!=null && count<2)
    {
        ListNode*nextn=curr->next;
        curr->next=pre;
        pre=curr;
        curr=curr->next;
        count++;
    }
    return pre;
}
void checkpalindrome(int arr[], int n)
{
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        if(arr[start]!=arr[end])
        return false;

        start++;
        end--;
    }
    return true;
}
bool isPalindrome(ListNode*head)
{
    if(head==null || head->next==null)
    return true;

    vector<int>ans;
    ListNode*temp=head;
    while(temp!=null)
    {
        ans.push_back(temp->val);
        temp=temp->next;
    }

    int ispain= checkpalindrome(ans, ans.size()-1);

     if(isPain)
     {
        return true;
     }
     return false;
}

ListNode*reverse(ListNode*head)
{
    if(head==null || head->next==null)
    return head;

    ListNode*curr=head;
    ListNode*pre=null;
    while(curr->next!=null)
    {
        ListNode*nextn=curr->next;
        curr->next=pre;
        pre=curr;
        curr=curr->next;
    }
    return pre;
}
bool checkPalindrome(ListNode*head)
{
    if(head==null || head->next==null)
    return true;

    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=null && fast->next!=null)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    reverse(slow->next);
    
    ListNode*temp1=head;
    ListNode*temp2=sloe->next;

    while(temp1!=null && temp2!=null )
    {
        if(temp1->val!=temp2->val)
        return false;

        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
    
}

vector<int>coommon(int arr1[], int arr2[], int arr3[], int n)
{
    int i=0;
    int j=0;
    int k=0;
    int ptr1=INT_MIN;
    int ptr2=INT_MIN;
    int ptr3=INT_MIN;
    while(i<n && j<n && k<n)
    {
        while(i<n && arr1[i]==ptr1)
        i++;

        while(j<n && arr2[j]==ptr2)
        j++;

        while(k<n && arr3[k]==ptr3)
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
vector<int>union(int arr1[], int arr2[], int n, int m)
{
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
        
    }
}

















//better approach 
//optimal approach 

//second version  
//remove value from array 
//left rotate array by one place brute force approach
void leftrotat(int arr[], int n)
{
    int temp=arr[0];
    for(int i=1; i<n; i++)
    {
        arr[i-1]=arr[i];
    }

    arr[n-1]=temp;
}
void leftrotatebrute(int arr[], itn n, int d)
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

    for(int i=d; i<n; i++)
    {
        arr[i-(n-d)]=arr[i];
    }
}
int secondlarget(int arr[], int n)
{
    int larget=arr[0];
    int sec=INT_MIN;
    for(int i=1; i<n; i++)
    {
        if(arr[i]>larget)
        {
            sec=larget;
            larget=arr[i];
        }
        else if(larget>arr[i] && arr[i]>sec)
        {
            sec=arr[i];
        }
    }
    return sec;
}
void sortcolor(int arr[], int n)
{
    int start=0;
    int mid=0;
    int end=n-1;
    while(mid<end)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid], arr[start]);
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

void rightrotoptimal(int arr[], int n, int d)
{
    reverse(arr, arr+d)
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}



















//optimal approach  
//right rotate array by one place brute force approach 
//optimal approach  
//left rotate array by d place bruteforce approach 
//optimal approach 
//right rotate array by d place bruteforce approach 
//optimal approach 
//squares of a sorted array bruteforce approach 
//optimal approach 
//product of itself bruteforce approach  
//better approach5  
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
//two sum bruteforce approach 
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
int twosumbetter(int arr[], int n, int target)
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

//second version of two sum bruteforce approach 
int twosumoptimal(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        if(arr[start]+arr[end]==target)
        {
            return 1;
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
    return -1;
}

//optimal approach 
//three sum bruteforce approach 
int threesumbrute(int arr[], int n, int target)
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
//better approach 
//optimal approach 
int threesumoptimal(int arr[], int n, int target)
{
    sort(arr, arr+n);
    vector<vector<int>>ans;
    for(int i=0; i<n-1; i++)
    {
        if(i>0 && arr[i]==arr[i-1])
        continue;

        int start=0;
        int end=n-1;
        int sum=target-arr[i];

        if(start<end)
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
int foursum(int arr[], int n, int target)
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
        return -1;
    }
}
//better approach 
//optimal approach 
int optimal(int arr[], int n, int target)
{
    vector<vector<int>>ans;
    sort(arr, arr+n);
    for(int i=0; i<n-2; i++)
    {
        if(i>0 && arr[i]==arr[i-1])
        continue;

        for(int j=i; j<n-1; j++)
        {
            if(j!=i+1 && arr[j]==arr[j-1])
            continue;

            int start=0;
            int end=n-1;
            int sum=target-(arr[i]+arr[j]);

            if(start<=end)
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

                    while(start<=end && arr[end]==arr[end+1])
                    end--;
                }
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






















//four-II sum bruteforce approach 

int foursum(int arr[], int n, int target)
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
        return -1;
    }
}























//optimal approach 
//maximum contigous subarray sum bruteforce approach 
 1 2 3 4 5 6  7 
int maxisubarrsum(int arr[], int n)
{
    int maxi=INT_MIN;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int sum=0;
            for(int k=i; k<j ; k++)
            {
                
            }
        }
    }
}
























//better approach
//optimal approach
//print all maximum subarray sum
//maximum product of subarray bruteforce approach
//better approach
//optimal approach
//maximum sum equal k bruteforce approach
//better approach 
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
//merge interval brute force approach 
//optimal approach 
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
//better approach 
//optimal approach 
//longest consecutive sequence in an array brute force approach
//better approach 
//optimal approach 
//length of the longest subarray with zero Sum 
//count inversion bruteforce approach
//optimal approach 




//---------------------------------------------------------------------------------------------------------------
//linear search 
//binary search 

2 4 6 8 9 12 
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
        else if(arr[mid]>target)
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
int firstoccurence(int arr[], int n, int number)
{
    int start=0;
    int end=n-1;
    int res;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==number)
        {
            res=mid;
            end=mid+1;
        }
        else if(arr[mid]>number)
        {
            end=mid-1;
        }
        else 
        {
            start=mid+1;
        }
    }
    return ans;
}

int lastocc(int arr[], int n, int num)
{
    int start=0;
    int end=n-1;
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==num)
        {
            ans=mid;
            start=mid+1;
        }
        else if(arr[mid]>num)
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

int orderofag(int arr[], int n, itn target)
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
        else if(arr[mid]>target)
        {
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}



























//order agnostic binary search 

int orderagn(vector<int>arr, int target)
{
    int n=arr.size();
    int start=0;
    int end=n-1;
    // int ans=-1;
    while(start<=end)
    {
        int mis=start+(end-start)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]> target)
        {
            end=mid-1;
        }
        else 
        {
            start=mid+1;
        }
    }
    retiurn -1;
}

int firstocc(vector<int>arr, int target)
{
    int n=arr.size();
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

int lastoccurence(vector<int>arr, int target)
{
    int n=arr.size();
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

int lowerboundapply(vector<int>arr, int target)
{
    int n=arr.size();
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




















//first occurence of target 
//last occurence of target 
//lowerbound of target 
//upperbound of target 
//celi value of target 
//floor value of target 
//find the minimum element in sorted rotated array 
//second version of minimum element 
//search element in rotated sorted array 
int searchinRotate(int arr[], int n, int target)
{
      int start=0;
      int end=n-1;
      while(start<=end)
      {
        int mid=start+(end-start)/2;
         if(arr[start]==arr[mid] && arr[mid]==arr[end])
         {
            start++;
            end--;
         }

         if(arr[mid]==target)
         {
            return 1;
         }
         else if(arr[mid]>target)
         {
            start=mid+1;
         }
         else 
         {
            end=mid;
         }
      }
      return -1;
}

























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

//--------------------------------------------------------------------------------------------------------
//cyclic sort 
//missing number 
//find all disappeared in an array 
//first missing positive  
//set mismatch 


//-----------------------------------------------------------------------------------------------------------------------------


















//find middle node of list (using find length method)
//or slow and fast pointer method  

//------------------------------------------------------------------------------
//reverse the list (using stack data structure) 
//or using recursion method  
//or using iterative method  

//------------------------------------------------------------------------------
//detect a cycle in list (using hashmap)
//using slow and fast pointer 

//------------------------------------------------------------------------------
//starting point of loop in list (using hashmap)
//using slow and fast pointer 

//------------------------------------------------------------------------------
//length of loop in list  (using hashmap)
//using slow and fast pointer 

//------------------------------------------------------------------------------
//check palindrome of list (using stack -or- array data structure )
//or use reverse of middle half of list 

//------------------------------------------------------------------------------
//segrregate odd and even list (using store  in array )
//or change link method 
//make odd and even list and than  merge them 

//------------------------------------------------------------------------------
//sort 0's , 1's, 2's list (using count method )
//or make seprate list of 0 , 1 and 2 

//------------------------------------------------------------------------------
//delete middle node (using find length of list )
//or using fast and slow pointer 

//------------------------------------------------------------------------------
//remove Nth node from end (using find length of list )
//or use two pointer method first to n step and than both will run simultaneously

//------------------------------------------------------------------------------ 
//sort list (using array data structure) 
//using merge sort  

//------------------------------------------------------------------------------
//find intersection of two list (using difference of two list )
// or using set data structure 
// or using two pointer method 

//------------------------------------------------------------------------------
//Add Two list (using stack data structure)
//or using two pointer method 

//------------------------------------------------------------------------------
// Add 1 to list (using reverse function )
// or using recursion 
// using stack data structure 

//-----------------------------------------------------------------------------
//rotate list by k place (using array data structure) 
//or using link change method 
// or rotate 1 node at a time 

//------------------------------------------------------------------------------
// flattening list (using array data structure)
//or using recursion 

//------------------------------------------------------------------------------
//reverse k group of list (using array or stack data structure) 
//or using recursion 
//or using iterative 

//------------------------------------------------------------------------------
// merge two sorted list (using array data structure)
//or using recursion 
//or using iterative 

//------------------------------------------------------------------------------
//merege k sorted list (using array data structure)
//using merge two list method 
//or using min heap data structure 

//------------------------------------------------------------------------------
//swap node in pairwise (using array data structure) 
//or using recursion 
// or use reverse function method 

//------------------------------------------------------------------------------
//Swapping Nodes in a Linked List kth from start or end (using array data structure) 
// or two pointer method 

//------------------------------------------------------------------------------
//remove duplicate node from sortedt list (using array )
//using recursion 
//using link change 

//---------------------------------------------------------------------------------
//


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
//iterative method of preorder traversal 
//inorder traversal using recursive 
//iterative method to inorder traversal 
//postorder traversal using recursive 
//iterative method to postorder traversal using 2 stack 
//using single stack 
//all preoder , inorder and postorder traversal in single iteration
//maximum depth of binary tree using recursion 
//using level order 
//check for balance binary tree 
//diameter of binary tree 
//maximum path sum 
//check two tree is identical/same  or not 
//check symmetric tree  or not
//level order traversal 
//second version of level order traversal 
//zig-zag order traversal 
//average of level of binary tree  
//level order successor of a node in binary tree(successor means given a key value find the right value of given key)
//right side view of binary tree 
//left side view of binary tree 
//maximum level sum of a binary tree
//Kth largest sum in a binary tree 
//minimum depth of binary tree
//deepest leaves sum 
//find largest value in each row
//find bottom left tree value 
//convert sorted array to binary search tree
//convert sorted linked list to binary search tree 
//second mathod 
//make maximum binary tree 
//construct binary tree from preorder and inorder 
//construct binary tree from inorder and postorder 
//path sum 
//path sum-II
//binary tree path
//sum root to leaf number (node 1->2->3==123 and so on )
//count total node in a complete binary tree 
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
//lowest common ancestor of binary tree 
//lowest common ancestor of binary search tree
//minimum number of operations to sort a binary tree by level (2471)
//cousins of binary tree
//verical order traversal 
//top view of binary tree 
//bottom view of binary tree
//print root to node path in binary tree 
//maximum width of binary tree
//children sum property in binary tree 1 963

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


//------------------------------------------------------------------------------ 
/*
largest element in array using sorted method 
using single iteration 

second largest element in array using sorted method 
using two iteration 
using single iteration

array are sorted or not 

remove element (given array and val remove all occurence and return size of array )

remove duplicate from sorted array array using set or map 
using two pointer method 

remove duplicate from unsorted array using sorted array 
using set and map 
using pointer method 

left rotate the array by one position 

left rotate the array by d place using extra space 
using reverse method 

move zero at the end of array using take extra sapce 
take two pointer method 

union of two araay using set and map 
using two pointer method 

intersection of two array 

common element from three array 

maximum consecutive one 

find unique element in array  using nested loop 
using map 
using xor method 



2 sum array are unsorted using nested loop 
using map 

2 sum array are are sorted using nested loop 
using binary search method 
two pointer method method 


sort o, 1, 2 using inbuilt soting method 
count method  
DNF algorithm 

majority element (n/2) using nested loop 
using map 
using moore voting algorithm 

majority element (n/3) using nested loop 
using map 
using moore voting algorithm  

maximum subarray(contigous part of array ) sum gemerate all possible subarray 
using nested 2 loop 
using kadane algorithm 

rearrenge array element by sign (take pos and neg array and push into and than positive element at even index and negative element at odd index)
take another array and push positive at even index and negative at odd index 
second version positive element and negative are not equal 




















misssing number where n is (1 to n) using nested loop 
using total sum method 
using cycly sort method 
using xor method 
using hash map method 






















































































































/*
short circuting (false && true)

what is javascropt 
JavaScript is a scripting language that enables you to create dynamically updating content, control multimedia, animate images,
and pretty much everything else.
A scripting language is a programming language designed for integrating and communicating with other programming languages.
programming language that executes tasks within a special run-time environment(js engine) by an interpreter instead of a compiler do not
require the compilation step

there are two way to add js in code 
head of html 
down of body html code 

variable name in js follow camelcase like firstcharacter of variableare small letter and  other start with capital letter 
ex : firstName 
data type 
primitive typr : string number boolean undefine null 
reference type : object array function 

Equality operator 
loose equalit (==) check only value 
strict equalit (===) check value and type

obeject in js : obeject is real world entity that contain method and property 
ex : human , property age,  name, method : runing, reading, hearing 
const human={
    firstName : "shivam",
    lastName: "singh",
    age: 22,
    
    read: function(){
        console.log("human are read");
    }
};

with the help of (.) access the object method and property 
object creation 
factory function 

function createHuman(name, ag)
{
    return human={
        firstName : name -or- name,
        age: ag, -or- ag,
        
        read: function(){
            console.log("human are read");
        }
    };
}

let obj1=createHuman("shivam", 22);


constructor function follow pascal rule ->first letter of every word is capital 
function CreateHuman(name, age)
{
    this.name=name,
    this.age=age,
    
    this.read=function(){
        console.log("human are read book ");
    }
}

let obj2=new CreateHuman("shivam", age);
//add new property 
obj2.color="white";
console.log(obj2);

//delete property
delete obj2.color;
console.log(obj2);

undefined : indicates that a variable has been declared but not given a value, 
not defined : indicates that a variable does not exist.

let and const are hoisted but remain uninitialized until their declaration is reached, leading to a Temporal Dead Zone (TDZ).

The Temporal Dead Zone (TDZ) is a behavior in JavaScript that refers to the time between  point where the variable is declared and initialized.
During this time, any attempt to access the variable will result in a ReferenceError.

{
  console.log(x); // ReferenceError: Cannot access 'x' before initialization
  let x = 5;
  console.log(x); // 5
}

{
  console.log(y); // ReferenceError: Cannot access 'y' before initialization
  const y = 10;
  console.log(y); // 10
}

Why Does the Temporal Dead Zone Exist?
The TDZ helps enforce a safer coding practice by preventing the use of variables before they are explicitly declared and 
initialized. It reduces the chances of bugs caused by accessing undefined or unintended values.




//--------------------------------------------------------------- 
/*
reverse linked list 
    reverse linked list 2 
    reverse linked list in k group 
    swap node in pair

find middle node in linked list 
    delete middle in linked list
    linked contain loop or not 
    starting point in cylic of linked list 
    remove loop in linked list 
    palindrome linked list 

*/



















































*/




















































*/
