#include<bits/stdc++.h>
using namespace std; 

//subset
//time Complexity is O(2^n)
//space Complexity is O(n) //height of recursion tree is space Complexity
void slove(vector<vector<int>>&arr, int index, vector<vector<int>>&ans, vector<int>temp)
{
    if(index==arr.size())
    {
        ans.push_back(temp);
        return ;
    }
    
    temp.push_back(arr[index]);
    slove(arr, index+1, ans, temp);
    temp.pop_back();
    
    slove(arr, index+1, ans, temp);
}
vector<vector<int>>findallsubset(vector<int>&arr)
{
    vector<vector<int>>ans;
    vector<int>temp;
    slove(arr, 0, ans, temp);
    return ans;
}

//subset-II
//time Complexity is O(2^n)
//space Complexity is O(n) 
void slove(vector<int>arr, int index, vector<vector<int>>&ans, vector<int>temp)
{
    if(index==arr.size())
    {
        ans.push_back(temp);
        return ;
    }
    
    //include 
    temp.push_back(arr[index]);
    slove(arr, index+1, ans, temp);
    temp.pop_back();
    
    //exclude 
    while(index+1<arr.size() && arr[index]==arr[index+1]) 
    index++;
    slove(arr, index+1, ans, temp);
}
vector<vector<int>>subsetII(vector<int>&num)
{
    sort(num.begin(), num.end());
    vector<vector<int>>ans;
    vector<int>temp;
    slove(num, 0, ans, temp);
}


//permutation  of array 
//time Complexity is O(n*n!)
//space Complexity is O(n)
void slove(vector<int>&arr, int index, vector<vector<int>>&ans)
{
    if(index==arr.size())
    {
        ans.push_back(arr);
        return ;
    }
    
    for(int j=index; j<arr.size(); j++)
    {
        swap(arr[j], arr[index]);
        
        slove(arr, index+1, ans);
        
        swap(arr[j], arr[index]);
    }
}
vector<vector<int>>permutation(vector<int>&num)
{
    vector<vector<int>>ans;
    slove(num, 0, ans);
    return ans;
}

//permutation-II     //given duplicate element in array 
//time Complexity is O(n*n!)
//space Complexity is O(n)
void slove(vector<int>&arr, int index, vector<vector<int>>&ans)
{
    if(index==arr.size())
    {
        ans.push_back(arr);
        return ;
    }
    
    unordered_set<int>st;
    for(int j=index; j<arr.size(); j++)
    {
        if(st.find(arr[j])!=st.end())
        continue; 
        
        st.insert(arr[j]);
        swap(arr[j], arr[index]);
        slove(arr, index+1, ans);
        swap(arr[j], arr[index]);
    }
}
vector<vector<int>>permutationII(vector<int>&num)
{
    sort(num.begin(), num.end());
    vector<vector<int>>ans;
    slove(num, 0, ans);
    return ans;
}

//combination //given n and k find all possible combination
//time Complexity is O(2^n)
//space Complexity is O(2^n) 
void slove(int index, int n, int k, vector<vector<int>>&ans, vector<int>temp)
{
    if(k==0)
    {
        ans.push_back(temp);
        return ;
    }
    
    if(index>n)
    return ;
    
    temp.push_back(index);
    slove(index+1, n, k-1, ans, temp);
    temp.pop_back();
    
    slove(index+1, n, k, ans, temp);
}
vector<vector<int>>combination(int n, int k)
{
    vector<vector<int>>ans;
    vector<int>temp;
    slove(1,n, k, ans, temp);
    return ans;
}

//combination sum (in array one number use unlimited time to makeing target)
void slove(int index, int sumtillnow, int target, vector<int>arr, vector<vector<int>>&ans, vector<int>temp)
{
    if(sumtillnow==target)
    {
        ans.push_back(temp);
        return ;
    }
    
    if(sumtillnow>target)
    return ;
    
    sumtillnow+=arr[index];
    temp.push_back(arr[index]);
    slove(index, sumtillnow, target, arr, ans, temp);
    sumtillnow-=arr[index];
    temp.pop_back();
    
    slove(index+1, sumtillnow, target, arr, ans, temp);
}
vector<vector<int>>combinationsum(vector<int>&arr, int target)
{
    vector<vector<int>>ans;
    vector<int>temp;
    slove(0, 0, target, arr, ans, temp);
    return ans;
}

//combination sum-II (given array and target in this case array contain duplicate element and one element can use one time only)
void slove(int index, int sum, int target, vector<int>arr, vector<vector<int>>&ans, vector<int>temp)
{
    if(sum==target)
    {
        ans.push_back(temp);
        return ;
    }
    
    if(sum>target)
    return ;
    
    if(index==n)
    return ;
    
    sum+=arr[index];
    temp.push_back(arr[index]);
    slove(index+1, sum, target, arr, ans, temp);
    sum-=arr[index];
    temp.pop_back();
    
    while(index+1<arr.size() && arr[index]==arr[index+1])
    index++;
    slove(index+1, sum, target, arr, ans, temp);
}
vector<vector<int>>combinationsum-II(vector<int>&num, int target)
{
    sort(num.begin(), num.end());
    vector<vector<int>>ans;
    vector<int>target;
    int sum=0;
    slove(0, sum, target, arr, ans, temp);
    return ans;
}

//combination sum-III (given n and k  select k number from (1 to 9) and sum will be equal to n)
//time Complexity is O(2^k)
//space Complexity is O(k)
void slove(int index, int sum, int n, int k, vector<int>temp, vector<vector<int>>&ans)
{
    if(sum>n)
    return ;
    
    if(k==0)
    {
        if(sum==n)
        {
            ans.push_back(temp);
        }
        return ;
    }
    
    if(index==10)
    return ;
    
    sum+=index;
    temp.push_back(index);
    slove(index+1, sum, n, k-1, temp, ans);
    sum-=index;
    temp.pop_back();
    
    slove(index+1, sum, n, k, temp, ans);
}
vector<vector<int>>combinationsum-III(int n, int k)
{
    vector<vector<int>>ans;
    vector<int>temp;
    int sum=0;
    slove(0, sum, n, k, temp, ans);
    return ans;
}

//letter combination of phone number 
//time Complexity is O(3^n)
//space Complexity is O(n)
void slove(int index, string s, string temp, vector<string>&ans, unordered_map<char, string>&mp)
{
    if(index==s.size())
    {
        ans.push_back(temp);
        return ;
    }
    
    string str=mp[s[index]];
    
    for(int j=0; j<str.length(); j++)
    {
        temp.push_back(str[j]);
        slove(index+1, s, temp, ans, mp);
        temp.pop_back();
    }
}
vector<string>phonenumber(string s)
{
    unordered_map<char, string>mp;
    mp['2']="abc";
    mp['3']="def";
    mp['4']="ghi";
    mp['5']="jkl";
    mp['6']="mno";
    mp['7']="pqrs";
    mp['8']="tuv";
    mp['9']="wxyz";
    
    vector<string>ans;
    string temp;
    slove(0, s, temp, ans, mp);
    return ans;
}


