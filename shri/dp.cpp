
#include<bits/stdc++.h>
using namespace std;

//minimum cost climbing  stairs 
//time complexity is O(2^n)
//space complexity is O(n)
int slove(vector<int>&arr, int n)
{
    if(n==0)
    return arr[0];
    
    if(n==1)
    return arr[1];
    
    int ans=arr[n]+min(slove(arr, n-1), slove(arr, n-2));
    return ans;
}
//time complexity is O(n)
//space complexity is O(n)+O(n)
int sloveMem(vector<int>&arr, int n, vector<int>&dp)
{
    if(n==0)
    return arr[0];
    
    if(n==1)
    return arr[1];
    
    if(dp[n]!=-1)
    return dp[n];
    
    dp[n]=arr[n]+min(slove(arr, n-1 dp), slove(arr, n-2, dp));
    return dp[n];
}
//time complexity is O(n)
//space complexity is O(n)
int sloveTab(vector<int>&arr, int n)
{
    vector<int>dp(n+1, INT_MIN);
    
    dp[0]=arr[0];
    dp[1]=arr[1];
    
    for(int i=2; i<n; i++)
    {
        dp[i]=arr[i]+min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
}
//time complexity is O(n)
//space complexity is O(1)
int sloveSpace(vector<int>&arr, int n)
{
    
    int pre2=arr[0];
    int pre1=arr[1];
    
    for(int i=2; i<n; i++)
    {
        int curr=arr[i]+min(pre1, pre2);
        pre2=pre1;
        pre1=curr;
    }
    return min(pre2, pre1);
}
int minicostclimb(vector<int>&arr)
{
    int n=arr.size();
    //int ans=min(slove(arr, n-1), slove(arr, n-2));
    //vector<int>dp(n+1, -1);
    //int ans=min(sloveMem(arr, n, dp), sloveMem(arr, n, dp));
    //int ans=sloveTab(arr,n);
    return sloveSpace(arr, n);
}

//-------------------------------------------------------------------
//minimum number of coins make target 
//time complexity is O(2^n)
//space complexity is O(n)
int slove(vector<int>&arr, int x)
{
    if(x==0)
    return 0;
    
    if(x<0)
    return INT_MAX;
    
    int mini=INT_MAX;
    for(int i=0; i<arr.size(); i++)
    {
        int ans=slove(arr, x-arr[i]);
        if(ans!=INT_MAX)
        mini=min(mini, 1+ans);
    }
    return mini;
}

//time complexity is O(n)
//space complexity is O(n)+O(n)
int sloveMem(vector<int>&arr, int x, vector<int>&dp)
{
    if(x==0)
    return 0;
    
    if(x<0)
    return INT_MAX;
    
    if(dp[x]!=-1)
    return dp[x];
    
    int mini=INT_MAX;
    for(int i=0; i<arr.size(); i++)
    {
        int ans=sloveMem(arr, x-arr[i], dp);
        if(ans!=INT_MAX)
        mini=min(mini, 1+ans);
    }
    return dp[x]=mini;
}

//time complexity is O(n)
//space complexity is O(n)
int sloveTab(vector<int>&arr, int x)
{
    vector<int>dp(x+1, INT_MAX);
    dp[0]=0;
    

    for(int i=1; i<=x; i++)
    {
        for(int j=0; j<arr.size(); i++)
        {
            if(i-arr[j]>=0 && dp[i-arr[j]]!=INT_MAX)
            {
                dp[i]=min(dp[i], 1+dp[i-arr[j]]);
            }
        }
    }
    
    if(dp[x]==INT_MAX)
    return -1;
    
    return dp[x];
}

int minimumEle(vector<int>&num, int x)
{
    //int ans=slove(num, x);
    //if(ans==INT_MAX)
    //return 0;
    //return ans;
    
    vector<int>dp(x+1, -1);
    int ans=sloveMem(arr, x, dp);
    if(ans==INT_MAX)
    return 0;
    return ans;
    
    return sloveTab(nums, x);
}

//-------------------------------------------------------------------------------
//maximum sum of non adjacent element -or- house robber
//time complexity is O(2^n)
//space complexity is O(n)
int slove(vector<int>&arr, int n)
{
    if(n==0)
    retirn arr[0];
    
    if(n<0)
    return 0;
    
    int incl=arr[n]+slove(arr, n-2);
    int excl=slove(arr, n-1);
    return max(incl, excl);
}

//time complexity is O(n)
//space complexity is O(n)+O(n)
int sloveMem(vector<int>&arr, int n, vector<int>&dp)
{
    if(n==0)
    retirn arr[0];
    
    if(n<0)
    return 0;
    
    if(dp[n]!=-1)
    return dp[n];
    
    int incl=arr[n]+slove(arr, n-2, dp);
    int excl=slove(arr, n-1, dp);
    return dp[n]=max(incl, excl);
}

//time complexity is O(n)
//space complexity is O(n)
int sloveTab(vector<int>&arr)
{
    int n=arr.size();
    vector<int>dp(n+1, 0);
    
    dp[0]=arr[0];
    
    for(int i=1; i<n; i++)
    {
        int incl=arr[i]+dp[i-2];
        int excl=dp[i-1];
        dp[i]=max(incl, excl);
    }
    return dp[n-1];
}

//time complexity is O(n)
//space complexity is O(1)
int sloveSpace(vector<int>&arr)
{
    int n=arr.size();
    
    int pre2=0;
    int pre1=arr[0];
    
    for(int i=1; i<n; i++)
    {
        int incl=arr[i]+pre2;
        int excl=pre2;
        int ans=max(incl, excl);
        pre2=pre1;
        pre1=ans;
    }
    return pre1;
}
int maxisunofadj(vector<int>&num)
{
    int n=num.size();
    //int ans=slove(num, n-1);
    //vector<int>dp(n+1, -1);
    //int ans=sloveMem(num, n-1, dp);
    //return sloveTab(arr, n-1);
    return sloveSpace(num);
}

//--------------------------------------------------------------------------------- 
//cut rod into segment in x y z 
//time complexity is O(2^n)
//space complexity is O(n)
int slove(int n, int x, int y, int z)
{
    if(n<0)
    return INT_MIN;
    
    if(n==0)
    return 0;
    
    int a=1+slove(n-x, x, y, z);
    int b=1+slove(n-y, x, y, z);
    int c=1+slove(n-z, x, y, z);
    
    int ans=max(a, max(b, c));
    return ans;
}

//time complexity is O(n)
//space complexity is O(n)+O(n)
int sloveMem(int n, int x, int y, int z, vector<int>&dp)
{
    if(n<0)
    return INT_MIN;
    
    if(n==0)
    return 0;
    
    if(dp[n]!=-1)
    return dp[n];
    
    int a=1+slove(n-x, x, y, z, dp);
    int b=1+slove(n-y, x, y, z, dp);
    int c=1+slove(n-z, x, y, z, dp);
    
    dp[n]=max(a, max(b, c));
    return dp[n];
}

//time complexity is O(n)
//space complexity is O(n)
int sloveTab(int n, int x, int y, int z)
{
    vector<int>dp(n+1, INT_MIN);
    
    dp[n]=0;
    
    for(int i=1; i<=n; i++)
    {
        if(i-x>0)
        dp[i]=max(dp[i] ,1+dp[i-x])
        
        if(i-y>0)
        dp[i]=max(dp[i], 1+dp[i-y]);
        
        if(i-z>0)
        dp[i]=max(dp[i], 1+dp[i-z]);
    }
    
    if(dp[n]<0)
    return 0;
    
    return dp[n];
}
int cutsegment(int n, int x, int y, int z)
{
    //int ans=slove(n, x, y, z);
    //if(ans<0)
    //return 0;
    //return ans;
    
    //vector<int>dp(n+1, -1);
    //int ans=sloveMem(n, x, y, z, dp);
    //if(ans<0)
    //return 0;
    //return ans;
    
    return sloveTab(n, x, y, z);
}

//---------------------------------------------------------------------------------- 
//combination sum IV
//time complexity is O(2^n)
//space complexity is O(n)
int slove(vector<int>&arr, int target)
{
    if(target<0)
    return 0;
    
    if(target==0)
    return 1;
    
    int an=0;
    for(int i=0; i<arr.size(); i++)
    {
        ans+=slove(arr, target-arr[i]);
    }
    return ans;
}

//time complexity is O(n)
//space complexity is O(n)+O(n)
int sloveMem(vector<int>&arr, int target, vector<int>&dp)
{
    if(target<0)
    return 0;
    
    if(target==0)
    return 1;
    
    if(dp[target]!=-1)
    return dp[target];
    
    int an=0;
    for(int i=0; i<arr.size(); i++)
    {
        ans+=slove(arr, target-arr[i], dp);
    }
    return dp[target]=ans;
}

//time complexity is O(n)
//space complexity is O(n)
int sloveTab(vector<int>&arr, int target)
{
    vector<int>dp(target+1, 0);
    
    dp[0]=1;
    
    for(int i=1; i<=target; i++)
    {
        for(int j=0; j<arr.size(); j++)
        {
            if(i-arr[j]>=0)
            dp[i]+=dp[i-arr[j]];
        }
    }
    return dp[target];
}

int combinationsum4(vector<int>&arr, int target)
{
    //return slove(arr, target);
    
    //vector<int>dp(target+1, -1);
    //return sloveMem(arr, target, dp);
    
    return sloveTab(arr, target);
}

//-------------------------------------------------------------------------------- 
//get minimum number to make perfect squares 
//time complexity is O(2^n)
//space complexity is O(n)
int slove(int n)
{
    if(n==0)
    return 0;
    
    int ans=n;
    for(int i=1; i*i<=n; i++)
    {
        ans=min(ans, 1+slove(n-i*i));
    }
    return ans;
}

//time complexity is O(n)
//space complexity is O(n)+O(n)
int sloveMem(int n, vector<int>&dp)
{
    if(n==0)
    return 0;
    
    if(dp[n]!=-1)
    return dp[n];
    
    int ans=n;
    for(int i=1; i*i<=n; i++)
    {
        ans=min(ans, 1+slove(n-i*i, dp));
    }
    return dp[n]=ans;
}

//time complexity is O(n)
//space complexity is O(n)
int sloveTab(int n)
{
    vector<int>dp(n+1, INT_MAX);
    dp[0]=0;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j*j<=n; j++)
        {
            if(i-j*j>=0)
            dp[i]=min(dp[i], 1+dp[i-j*j]);
        }
    }
    return dp[n];
}
int minimumnum(int n)
{
    //return slove(n)
    
    vector<int>dp(n+1, -1);
    return sloveMem(n, dp);
}

//-------------------------------------------------------------------------------------- 
//largest squares from a matrix
//time complexity is O(2^n*m)
//space complexity is O(n*m)
int slove(vector<vector<int>&mat, int i, int j, int &maxi)
{
    if(i>=mat.size() || j>=mat[0].size())
    return 0;
    
    int right=slove(mat, i, j+1, maxi);
    int diagonal=slove(mat, i+1, j+1, maxi);
    int down=slove(mat, i+1, j, maxi);
    
    if(mat[i][j]==1)
    {
        int ans=min(right, min(diagonal, down));
        maxi=max(maxi, ans);
        return ans;
    }
    else 
    {
        return 0;
    }
}

//time complexity is O(n*m)
//space complexity is O(n*m)+O(n*m)
int sloveMem(vector<vector<int>&mat, int i, int j, int &maxi, vector<vector<int>>&dp)
{
    if(i>=mat.size() || j>=mat[0].size())
    return 0;
    
    int right=sloveMem(mat, i, j+1, maxi, dp);
    int diagonal=sloveMem(mat, i+1, j+1, maxi, dp);
    int down=sloveMem(mat, i+1, j, maxi, dp);
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    if(mat[i][j]==1)
    {
        dp[i][j]=min(right, min(diagonal, down));
        maxi=max(maxi, ans);
        return dp[i][j];
    }
    else 
    {
        return dp[i][j]=0;
    }
}

//time complexity is O(n*m)
//space complexity is O(n*m)
int sloveTab(vector<vector<int>>&mat, int &maxi)
{
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    
    for(int i=n-1; i>=0; i--)
    {
        for(int j=m-1; j>=0; j--)
        {
            int right=dp[i][j];
            int diagonal=dp[i+1][j+1];
            int down=dp[i+1][j];
            
            if(mat[i][j]==1)
            {
                dp[i][j]=1+min(right, min(diagonal, down));
                maxi=max(maxi, dp[i][j]);
            }
            else 
            {
                dp[i][j]=0;
            }
        }
    }
    return dp[0][0];
}

//time complexity is O(n*m)
//space complexity is O(m)
int sloveSO(vector<vector<int>>&mat, int &maxi)
{
    int n=mat.size();
    int m=mat[0].size();
    vector<int>curr(m+1, 0);
    vector<int>next(m+1, 0);
    
    for(int i=n-1; i>=0; i--)
    {
        for(int j=m-1; j>=0; j--)
        {
            int right=curr[j+1];
            int diagonal=next[j+1];
            int down=curr[j];
            
            if(mat[i][j]==1)
            {
                curr[j]=1+min(right, min(diagonal, down));
                maxi=max(maxi, curr[j]);
            }
            else 
            {
                curr[j]=0;
            }
        }
        next=curr;
    }
    return next[0];
}
int largestsquare(vector<vector<int>&mat)
{
    int n=mat.size();
    int m=mat[0].size();
    //int maxi=0;
    //slove(mat, 0, 0 maxi);
    //return maxi;
    
    //int maxi=0;
    //vector<vector<int>>dp(n, vector<int>(m, -1));
    //sloveMem(mat, 0, 0, maxi, dp);
    //return maxi;
    
    //int maxi=0;
    //sloveTab(mat, maxi);
    //return maxi;
    
    int maxi=0;
    sloveSO(mat, maxi);
    return maxi;
}

//------------------------------------------------------------------------------- 
//min score triangulation of polygon
int slove(vector<int>&arr, int i, int j)
{
    if(i+1==j)
    return 0;
    
    int ans=INT_MAX;
    for(int k=i+1; k<j; k++)
    {
        ans=min(ans, arr[i]*arr[j]*arr[k]+slove(arr, i, k)+slove(arr, k, j));
    }
    return ans;
}
int sloveMem(vector<int>&arr, int i, int j, vector<vector<int>>&dp)
{
    if(i+1==j)
    return 0;
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    int ans=INT_MAX;
    for(int k=i+1; k<j; k++)
    {
        ans=min(ans, arr[i]*arr[j]*arr[k]+sloveMem(arr, i, k dp)+sloveMem(arr, k, j, dp));
    }
    return dp[i][j]=ans;
}
int sloveTab(vector<int>&arr)
{
    int n=arr.size();
    vector<vector<int>>dp(n, vector<int>(n, 0));
    
    for(int i=n-1; i>=0; i--)
    {
        for(int j=i+2; j<n; j++)
        {
            int ans=INT_MAX;
            for(int k=i+1; k<j; k++)
            {
                ans=min(ans, arr[i]*arr[j]*arr[k]+dp[i][k]+dp[k][j]);
            }
            dp[i][j]=ans;
        }
    }
    return dp[0][n-1];
}
int mintriangulation(vector<int>&arr)
{
    int n=arr.size();
    //return slove(arr, 0, n-1);
    
    //vector<vector<int>>dp(n, vector<int>(n, -1));
    //return sloveMem(arr, 0, n-1, dp);
    
    return sloveTab(arr);
}

//---------------------------------------------------------------------------------------------- 
//count derangement 
//time complexity is O(2^n)
//space complexity is O(n)
int slove(int n)
{
    if(n==1)
    return 0;
    
    if(n==2)
    return 1;
    
    int ans=(n-1)*(slove(n-1)+slove(n-2));
    return ans;
}

//time complexity is O(n)
//space complexity is O(n)+O(n)
int sloveMem(int n, vector<int>&dp)
{
    if(n==1)
    return 0;
    
    if(n==2)
    return 1;
    
    if(dp[n]!=-1)
    return dp[n];
    
    dp[n]=(n-1)*(slove(n-1, dp)+slove(n-2, dp));
    return dp[n];
}

//time complexity is O(n)
//space complexity is O(n)
int sloveTab(int n)
{
    vector<int>dp(n+1, 0);
    dp[1]=0;
    dp[2]=1;
    
    for(int i=3; i<=n; i++)
    {
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}

//time complexity is O(n)
//space complexity is O(1)
int sloveSO(int n)
{
    int pre2=0;
    int pre1=1;
    
    for(int i=3; i<=n; i++)
    {
        int ans=(i-1)*(pre1+pre2);
        pre2=pre1;
        pre1=ans;
    }
    return pre1;
}
int countderangement(int n)
{
    //return slove(n);
    
    //vector<int>dp(n+1, -1);
    //return sloveMem(n, dp);
    
    //return sloveTab(n);
    
    return sloveSO(n);
}

//---------------------------------------------------------------------------------------- 
//longest increasing subsequence
//time complexity is O(2^n)
//space complexity is O(n)
int slove(int arr[], int n, int curr, int pre)
{
    if(curr==n)
    return 0;
    
    int incl=0;
    if(pre==-1 || arr[curr]>arr[pre])
    incl=1+slove(arr, n, curr+1, curr);
    
    int exc=slove(arr, n, curr+1, pre);
    
    return max(incl, exc);
}

//time complexity is O(n)
//space complexity is O(n)+O(n)
int sloveMem(int arr[], int n, int curr, int pre, vector<vector<int>>&dp)
{
    if(curr==n)
    return 0;
    
    if(dp[curr][pre+1]!=-1)
    dp[curr][pre+1];
    
    int incl=0;
    if(pre==-1 || arr[curr]>arr[pre])
    incl=1+slove(arr, n, curr+1, curr, dp);
    
    int exc=slove(arr, n, curr+1, pre, dp);
    
    return dp[curr][pre+1]= max(incl, exc);
}

//time complexity is O(n)
//space complexity is O(n)
int sloveTab(int arr[], int n)
{
    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
    
    for(int curr=n-1; curr>=0; curr--)
    {
        for(int pre=curr-1; pre>=-1; pre--)
        {
            int incl=0;
            if(pre==-1 || arr[curr]>arr[pre])
            incl=1+dp[curr+1][curr+1];
            
            int exc=dp[curr+1][pre+1];
            
            dp[curr][pre+1]=max(incl, exc);
        }
    }
    return dp[0][-1+1];
}

//time complexity is O(n)
//space complexity is O(n)
int sloveSO(int arr[], int n)
{
    vector<int>nextRow(n+1, 0);
    vector<int>currRow(n+1, 0);
    
    for(int curr=n-1; curr>=0; curr--)
    {
        for(int pre=curr-1; pre>=-1; pre--)
        {
            int incl=0;
            if(pre==-1 || arr[curr]>arr[pre])
            incl=1+nextRow[curr+1];
            
            int exc=nextRow[pre+1];
            
            currRow[pre+1]=max(incl, exc);
        }
        nextRow=currRow;
    }
    return nextRow[-1+1];
}

//time complexity is O(n*logn)
//space complexity is O(n)
int sloveOptimal(int arr[], int n)
{
    if(n==0)
    return 0;
    
    vector<int>ans;
    ans.push_back(arr[0]);
    
    for(int i=1; i<n; i++)
    {
        if(arr[i]>ans.back())
        ans.push_back(arr[i]);
        
        else 
        {
            int index=lower_bound(ans.begin(), ans.end(), arr[i])-ans.begin();
            ans[index]=arr[i];
        }
    }
    return ans.size();
}
int longestsubsquence(int arr[], int n)
{
    //slove(arr, n, 0, -1);
    
    //vector<vector<int>>dp(n, vector<int>(n+1, -1));
    //sloveMem(arr, n, 0, -1, dp);
    
    //return sloveTab(arr, n);
    
    //return sloveSO(arr, n);
    
    //return sloveoptimal(arr, n);
    
    return sloveoptimal(arr, n);
}

//-----------------------------------------------------------------------------------------
//russian doll envelope problem 
class cmp 
{
    bool operator(vector<int>&a, vector<int>&b)
    {
        if(a[0]==b[0])
        return a[1]>b[1]
        
        return a[0]<b[0];
    }
}
//time complexity is O(nlogn)
//space complexity is O(n)
int slove(vector<vector<int>>&arr, int n)
{
    if(n==0)
    return 0;
    
    vector<int>ans;
    ans.push_back(arr[0][0]);
    for(int i=1; i<n; i++)
    {
        if(arr[i][1]>ans.back())
        ans.push_back(arr[i][1]);
        
        else 
        {
            int index=lower_bound(ans.begin(), ans.end(), arr[i][1])-ans.begin();
            ans[index]=arr[i][1];
        }
    }
    return ans.size();
}
int maxienvelope(vector<vector<int>>&arr)
{
    int n=arr.size();
    sort(arr.begin(), arr.end(), cmp);
    return slove(arr, n);
}

//second method 
//time complexity is O(nlogn)
//space complexity is O(n)
int maxienvelope(vector<vector<int>>&arr)
{
    sort(arr.begin(), arr.end(), cmp);
    vector<int>ans;
    for(auto it : arr)
    {
        int height=it[1];
        int index=lower_bound(ans.begin(), ans.end(), height)-ans.begin();
        if(index==ans.size())
        ans.push_back(height);
        
        ans[index]=height;
    }
}

//--------------------------------------------------------------------------------------- 
//0/1 knapsack problem 
//time complexity is O(n*w)
//space complexity is O(n)
int slove(vector<int>&wt, vector<int>&wt, int index, int capacity)
{
    if(index==0)
    {
        if(wt[0]<=capacity)
        return val[0];
        
        return 0;
    }
    
    int incl=0;
    if(wt[index]<=capacity)
    incl=val[index]+slove(wt, val, index-1, capacity-val[index]);
    
    int exc=slove(wt, val, index-1, capacity);
    
    return max(incl, exc);
    
    
}

//time complexity is O(n*w)
//space complexity is O(n*w) + O(n)
int sloveMem(vector<int>&wt, vector<int>&wt, int index, int capacity, vector<vector<int>>&dp)
{
    if(index==0)
    {
        if(wt[0]<=capacity)
        return val[0];
        
        return 0;
    }
    
    if(dp[index][capacity]!=-1)
    return dp[index][capacity];
    
    int incl=0;
    if(wt[index]<=capacity)
    incl=val[index]+slove(wt, val, index-1, capacity-val[index], dp);
    
    int exc=slove(wt, val, index-1, capacity, dp);
    
    return dp[index][capacity]=max(incl, exc);
    
    
}
int sloveTab(vector<int>&wt, vector<int>&val, int index, int capacity)
{
    vector<vector<int>>dp(index+1, vector<int>(capacity+1, 0));
    
    //base analyes
    for(int i=wt[0]; i<=capacity; i++)
    {
        if(wt[0]<=capacity)
        dp[0][w]=val[0];
        
        dp[0][w]=0;
    }
    
    for(int index=1; index<n; index++)
    {
        for(int w=0; w<=capacity; w++)
        {
            int incl=0;
            if(wt[index]<=w)
            incl=val[index]+dp[index-1][w-val[index]];
            
            int exc=dp[index-1][w]];
            
            dp[index][w]=max(incl, exc);
        }
    }
    return dp[n-1][capacity];
}
int sloveSO(vector<int>&wt, vector<int>&val, int index, int capacity)
{
    vector<int>pre(capacity+1, 0);
    vector<int>curr(capacity+1, 0);
    
    //base analyes
    for(int i=wt[0]; i<=capacity; i++)
    {
        if(wt[0]<=capacity)
        pre[w]=val[0];
        
        pre[w]=0;
    }
    
    for(int index=1; index<n; index++)
    {
        for(int w=0; w<=capacity; w++)
        {
            int incl=0;
            if(wt[index]<=w)
            incl=val[index]+pre[w-val[index]];
            
            int exc=pre[w]];
            
            curr[w]=max(incl, exc);
        }
        pre=curr;
    }
    return pre[capacity];
}

int knapsack(vector<int>& wt, vector<int>& val, int n, int W)
{
    //return slove(wt, val, n-1, w);
    
    //vector<vector<int>>dp(n, vector<int>(w+1, -1));
    //return sloveMem(wt, val n, w, dp);
    
    //return sloveTab(wt, val, n, w);
    
    return sloveSO(wt, val, n, w);
}

//-------------------------------------------------------------------------------------- 
//longest common subsequence 
int slove(string &a, string &b, int i, int j)
{
    if(i==a.length())
    return 0;
    
    if(j==b.length())
    return 0;
    
    int ans=0;
    if(a[i]==b[j])
    {
        ans=1+slove(a, b, i+1, j+1);
    }
    else 
    {
        ans=max(slove(a, b, i+1, j), slove(a, b, i, j+1));
    }
    return ans;
}
int sloveMem(string &a, string &b, int i, int j, vector<vector<int>>&dp)
{
    if(i==a.length())
    return 0;
    
    if(j==b.length())
    return 0;
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    int ans=0;
    if(a[i]==b[j])
    {
        ans=1+slove(a, b, i+1, j+1, dp);
    }
    else 
    {
        ans=max(slove(a, b, i+1, j, dp), slove(a, b, i, j+1, dp));
    }
    return dp[i][j]=ans;
}
int sloveTab(string &a, string &b)
{
    vector<vector<int>>&dp(a.length()+1, vector<int>(b.length()+1, 0));
    
    for(int i=a.length()-1; i>=0; i--)
    {
        for(int j=b.length()-1; j>=0; j--)
        {
            
            int ans=0;
            if(a[i]==b[j])
           {
                ans=1+dp[i+1][j+1];
           }
           else 
           {
                ans=max(dp[i+1][j], dp[i][j+1]);
           }
           dp[i][j]=ans;
        }
    }
    return dp[0][0];
}
int sloveSO(string &a, string &b)
{
    vector<int>next(b.length()+1, 0);
    vector<int>curr(b.length()+1, 0);
    
    for(int i=a.length(); i>=0; i--)
    {
        for(int j=b.length(); j>=0; j--)
        {
            
            int ans=0;
            if(a[i]==b[j])
           {
                ans=1+next[j+1];
           }
           else 
           {
                ans=max(next[j], curr[j+1]);
           }
           curr[j]=ans;
        }
        next=curr;
    }
    return next[0];
}
int longestcommonsubsq(string text1, string text2)
{
    //return slove(text2, text2, 0, 0);
    
    //vector<vector<int>>dp(text1.length(), vector<int>(b.length(), -1));
    //return slove(text1, text2, 0, 0, dp);
    
    return sloveTab(text1, text2)
}

//--------------------------------------------------------------------------------------------- 
//longest palindromic subsequence 
int slove(string &a, string &b)
{
    vector<int>next(b.length()+1, 0);
    vector<int>curr(b.length()+1, 0);
    
    for(int i=a.length()-1; i>=0; i--)
    {
        for(int j=b.length()-1; j>=0; j--)
        {
            int ans=0;
            if(a[i]==b[j])
            {
                ans=1+next[j+1];
            }
            else 
            {
                ans=max(next[j], curr[j+1]);
            }
            curr[j]=ans;
        }
        next=curr;
    }
    return next[0];
}
int longestpalindromic(string s)
{
    string revs=s;
    reverse(revs.begin(), revs.end());
    
    int ans=slove(s, revs);
    return ans;
}

//-------------------------------------------------------------------------------------------- 
//edit distance 
int slove(string &a, string &b, int i, int j)
{
    if(i==a.length())
    return b.length()-j;
    
    if(j==b.length())
    return a.length()-i;
    
    int ans=0;
    if(a[i]==b[j])
    {
        return slove(a, b, i+, j+1);
    }
    else 
    {
        int insert=1+slove(a, b, i, j+1);
        int update=1+slove(a b, 1+1, j);
        int replace=1+slove(a, b, i+1, j+1);
        
        ans= min(insert, min(update, replace));
    }
    return ans;
}
int sloveMem(string &a, string &b, int i, int j, vector<vector<int>>&dp)
{
    if(i==a.length())
    return b.length()-j;
    
    if(j==b.length())
    return a.length()-i;
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    int ans=0;
    if(a[i]==b[j])
    {
        return slove(a, b, i+, j+1, dp);
    }
    else 
    {
        int insert=1+slove(a, b, i, j+1, dp);
        int update=1+slove(a b, 1+1, j, dp);
        int replace=1+slove(a, b, i+1, j+1, dp);
        
        ans= min(insert, min(update, replace));
    }
    return dp[i][j]=ans;
}
int sloveTab(string &a, string &b)
{
    vector<vector<int>>dp(a.length()+1, vector<int>(b.length()+1, 0));
    
    for(int j=0; j<b.length(); j++)
    {
        dp[a.length()][j]=b.length()-j;
    }
    
    for(int i=0; i<a.length(); i++)
    {
        dp[i][b.length()]=a.length()-i;
    }
    
    for(int i=a.length()-1; i>=0; i--)
    {
        for(int j=b.length()-1; j>=0; j--)
        {
            int ans=0;
            if(a[i]==b[j])
            {
                ans=dp[i+1][j+1];
            }
            else 
            {
                int insert=1+dp[i][j+1];
                int update=1+dp[i+1][j];
                int replace=1+dp[i+1][j+1];
                
                ans=max(insert, min(update, replace));
            }
            dp[i][j]=ans;
        }
    }
    return dp[0][0];
}
int sloveSO(string &a, string &b)
{
    vector<int>next(b.length()+1, 0);
    vector<int>curr(b.length()+1, 0);
    
    for(int j=0; j<b.length(); j++)
    {
        next[j]=b.length()-j;
    }
    
    
    for(int i=a.length()-1; i>=0; i--)
    {
        for(int j=b.length()-1; j>=0; j--)
        {
            curr[b.length()]=a.length()-i;
            
            int ans=0;
            if(a[i]==b[j])
            {
                ans=next[j+1];
            }
            else 
            {
                int insert=1+curr[j+1];
                int update=1+next[j];
                int replace=1+next[j+1];
                
                ans=max(insert, min(update, replace));
            }
            curr[j]=ans;
        }
        next=curr;
    }
    return next[0];
}
int mindistance(string word1, string word2)
{
    //return slove(word1, word2, 0, 0);
    
    //vector<vector<int>>dp(word1.length(), vector<int>(word2.length(), -1));
    //return sloveMem(word1, word2, 0, 0, dp);
    
    //return sloveTab(word1, word2);
    
    if(word1.length()==0)
    return word2.length();
    
    if(word2.length()==0)
    return word1.length();
    
    return sloveSO(word1, word2);
}








