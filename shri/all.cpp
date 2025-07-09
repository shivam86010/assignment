
#include<bits/stdc++.h>
using namespace std;

int minimumsizesubarrsum(vector<int>arr, int target)
{
    int mini=INT_MAX;
    for(int i=0; i<n; i++)
    {
        int sum=0;
        for(int j=i; j<n; j++)
        {
            sum+=arr[j];
            mini=min(mini, j-i+1);
        }
    }
    return mini;
}

int maximumpoint(vector<int>arr, int k)
{
    int leftsum=0;
    int rightsum=0;
    // int maxisum=INT_MIN;
    int n=arr.size();

    for(int i=0; i<k; i++)
    leftsum+=arr[i];

    int index=n-1;
    int maxisum=leftsum;
    for(int i=k; k>=0; i--)
    {
        leftsum-=arr[i];
        rightsum+=arr[index];
        index--;
        maxisum=max(maxisum, leftsum+rightsum);
    }
    return maxisum;
}

vector<int>slidingwindow(vector<int>arr, int k)
{
    int n=arr.size();
    vector<int>ans;
    for(int i=0; i<n-k; i++)
    {
        int maximum=-1;
        for(int j=i; j<i+k; j++)
        {
            maximum=max(maximum, arr[j]);
        }

        ans.push_back(maximum);
    }
    return ans;
}

int longesrsubstr(string s)
{
    int n=s.size();
    int maxlen=INT_MIN;
    for(int i=0; i<n; i++)
    {
        unordered_map<char, int>mp;
        for(int j=i; j<n; j++)
        {
            if(mp.find(s[j])!=mp.end())
            {
                break;
            }

            maxlen=max(maxlen, j-i+1);
        }
    }
    return maxlen;
}

vector<int>negative(vector<int>num, int k)
{
    vector<int>ans;
    int n=num.size();
    for(int i=0; i<n-k; i++)
    {
        bool isNeg=false;
        for(int j=i; j<i+k; j++)
        {
            if(num[j]<0)
            {
                ans.push_back(num[j]);
                isNeg=true;
                break;
            }
        }

        if(!isNeg)
        {
            ans.push_back(0);
        }
    }
    return ans;
}

//optimal approach 
vector<int>optimalway(vector<int>temp, int k)
{
    int n=temp.size();
    dequeue<int>dq;
    int left=0;
    int right=0;
    vector<int>result;
    while(right<n)
    {
        if(right-left+1==k)
        {
            if(!dq.empty())
            {
                result.push_back(dq.front());
            }
            else {
                result.push_back(0);
            }
            if(temp[left]<0)
            {
                dq.pop_front();
                left++;
            }
        }

        if(temp[right]<0)
        {
            dq.push_back(temp[right]);
        }
        right++;
    }

    return result;
}