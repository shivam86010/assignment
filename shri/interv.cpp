#include<bits/stdc++.h>
using namespace std;




//reverse array using inbuilt function
void reverse1(int arr[], int n)
{
    reverse(arr, arr+n);
}

//reverse array 
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
            reverse(arr+i, arr+i+k);
        }
        else 
        {
            reverse(arr+i, arr+n);
        }
    }
}

//reverse integer 
int reverse5(int n)
{
    int ans=0;
    while(n!=0)
    {
        ans=ans*10+(n%10);
        n=n/10;
    }
    return ans;
}

//check array are palindrome or not 
bool palindrom(int arr[], int n)
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
    bool inc=true;
    bool dec=true;
    for(int i=1; i<n; i++)
    {
        if(arr[i]<arr[i-1])
        inc=false;
        break;
    }

    for(int i=n-2; i>=0; i--)
    {
        if(arr[i]<arr[i+1])
        dec=false;
        break;
    }

    return (inc || dec);
}

//move negative element at the end of array using bruteforce approach 
vector<int>moveneg(int arr[] , int n)
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
vector<int>movezero(int arr[], int n)
{
    vector<int>ans;
    for(int i=0; i<n; i++)
    {
        if(arr[i]!=0)
        {
            ans.push_back(arr[i]);
        }
    }

    for(int i=0; i<n; i++)
    {
        if(arr[i]==0)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

//optimal approach 
void movezeroopt(int arr[], int n)
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
//parity sort 
//O 1 2 sort 
vector<int>sort012(int arr[], int n)
{
    int count0=0;
    int count1=0;
    int count2=0;
    vector<int>ans;

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
    ans[i]=0;

    for(int i=count0; i<count0+count1; i++)
    ans[i]=1;

    for(int i=count0+count1; i<n; i++)
    ans[i]=2;

    return ans;
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
            swap(arr[start], arr[end]);
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
        else  if(arr[mid]>b)
        {
            swap(arr[start], arr[end]);
            end--;
        }
        else 
        {
            mid++;
        }
    }
}

//find the minimum element in array using bruteforce approach
int minimumel(int arr[], int n)
{
    sort(arr, arr+n);
    return arr[0];
}

//optimal approach 
int minielement(int arr[], int n)
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
int maximumel(int arr[], int n)
{
    sort(arr, arr+n);
    return arr[n-1];
}

//optimal approach
int maxielement(int arr[], int n)
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
    int largest=arr[0];
    int sec=INT_MIN;
    for(int i=1; i<n; i++)
    {
        if(arr[i]>largest)
        {
            sec=largest;
            largest=arr[i];
        }

        if(largest>arr[i]  && arr[i]>sec)
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

        if(smallest!=arr[i] && arr[i]<sec)
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
//better approach 
//optimal approach 
//majority-II  bruteforce approach 
//better approach 
//optimal approach 
//remove duplicate element 
//second version  
//remove value from array 
//left rotate array by one place brute force approach 
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
//two sum bruteforce approach 
bool twosum(int arr[], int n, int target)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]+arr[j]==target)
            {
                return true;
            }
        }
    }
    return false;
}

//optimal approach 
bool twosumopt(int arr[], int n, int target)
{
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        if(mp.find(target-arr[i])!=mp.end())
        {
            return true;
        }

        mp[arr[i]]=i;
    }
    return false;
}

//second version of two sum bruteforce approach 
vector<int>twosum1(int arr[], int n, int target)
{
    vector<int>ans;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]+arr[j]==target)
            {
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
                return ans;
            }
        }
    }
    return ans;
}

//optimal approach 
vector<int>twosumopt1(int arr[], int n, int target)
{
    vector<int>ans;
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        if(mp.find([i])!=mp.end())
        {
            ans.push_back(mp[target-arr[i]]);
            ans.push_back()
        }
    }
}

//three sum bruteforce approach 
//better approach 
//optimal approach 
//four sum bruteforce approach 
//better approach 
//optimal approach 
//four-II sum bruteforce approach 
//optimal approach 
//maximum contigous subarray sum bruteforce approach 
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
int linear(int arr[], int n, int target)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]==target)
        {
            return 1;
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
int agobinary(int arr[], int n, int target)
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

//--------------------------------------------------------------------------------------------------------
//cyclic sort 
//missing number 
//find all disappeared in an array 
//first missing positive  
//set mismatch 


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