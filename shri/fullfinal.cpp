// #include<bits/stdc++.h>
// using namespace std;

// ListNode*reverseStack(ListNode*head)
// {
//     if(head==null || head->next==null)
//     return head;

//     stack<int>st;
//     ListNode*temp=head;
//     while(temp!=null)
//     {
//         st.push(temp->val);
//         temp=temp->next;
//     }

//     temp=head;
//     while(temp!=null)
//     {
//         temp->val=st.top();
//         st.pop();
//         temp=temp->next;
//     }
//     return head;
// }

// ListNode*reverseRec(ListNode*head)
// {
//     if(head==null || head->next==null)
//     return head;

//     ListNode*newhead=reverseRec(head->next);
//     ListNode*first=head->next;
//     first->next=head;
//     head->next=null;

//     return newhead;
// }

// ListNode*reverseIterative(ListNode*head)
// {
//     if(head==null || head->next==null)
//     return head;

//     ListNode*curr=head;
//     ListNode*prev=null;
//     while(curr!=null)
//     {
//         ListNode*nextn=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=nextn;
//     }
//     return prev;
// }

// ListNode*findmiddle(ListNode*head)
// {
//     if(head==null || head->next==null)
//     return head;

//     int len=0;
//     ListNode*temp=head;
//     while(temp!=null)
//     {
//         len++;
//         temp=temp->next;
//     }

//     int half=len/2;
//     temp=head;
//     while(half--)
//     {
//         temp=temp->next;
//     }
//     return temp;
// }

// ListNode*middlePointer(ListNode*head)
// {
//     if(head==null || head->next==null)
//     return head;

//     ListNode*slow=head;
//     ListNode*fast=head;
//     while(fast!=null && fast->next!=null)
//     {
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     return slow;
// }

// bool isCycleMap(ListNode*head)
// {
//     if(head==null)
//     return false;

//     ListNode*temp=head;
//     unordered_map<ListNode*,int>mp;
//     while(temp!=null)
//     {
//         if(mp.find(temp)!=mp.end())
//         {
//             return true;
//         }

//         mmp[temp]=1;
//         temp=temp->next;
//     }
//     return false;
// }

// bool isCyclePointer(ListNode*head)
// {
//     if(head==null)
//     return false;

//     ListNode*slow=head;
//     ListNode*fast=head;
//     while(fast!=null && fast->next!=null)
//     {
//         slow=slow->next;
//         fast=fast->next->next;

//         if(slow==fast)
//         return true;
//     }

//     return false;
// }

// ListNode*removeDuplicate(ListNode*head)
// {
//     if(head==null || head->next==null)
//     return head;

//     vector<int>arr;
//     ListNode*temp=head;
//     while(temp!=null)
//     {
//         if(arr.size()==0 || arr.back()!=temp->val)
//         {
//             arr.push_back(temp->val);
//         }
        
//         temp=temp->next;
//     }

//     temp=head;
//     ListNode*prev=null;
//     int index=0;
//     while(temp!=null)
//     {
//         temp->val=arr[index];
//         i++;
//         prev=temp;
//         temp=temp->next;
//     }

//     ListNode*deleteNode=prev->next;
//     prev->next=null;
//     delete deleteNode;

//     return head;
// }

// //using recursion 
// ListNode*removeDupRec(ListNode*head)
// {
//     if(head==null || head->next==null)
//     return head;

//     ListNode*newhead=removeDupRec(head->next);
//     if(head->val==newhead->val)
//     {
//         delete head;
//         return newhead;
//     }

//     head->next=newhead;
//     return head;
// }

// //iterative method 
// ListNode*removeduplicateit(ListNode*head)
// {
//     if(head==null || head->next==null)
//     return head;

//     ListNode*curr=head;
//     while(curr!=null && curr->next!=null)
//     {
//         if(curr->val==curr->next->val)
//         {
//             ListNode*temp=curr->next;
//             curr->next=curr->next->next;
//             delete temp;
//         }

//         temp=temp->next;
//     }
//     return head;
// }

// ListNode*remdupunsortedlist(ListNode*head)
// {
//     if(head==null || head->next==null)
//     return head;

//     vector<int>arr;
//     ListNode*temp=head;
//     while(temp!=null)
//     {
//         if(temp.size()==0 || temp.back()!=temp->val)
//         {
//             arr.push_back(temp->val);
//         }

//         temp=temp->next;
//     }

//     ListNode*prev=null;
//     temp=head;
//     int index=0;
//     while(temp!=null)
//     {
//         temp->val=arr[index];
//         prev=temp;
//         temp=temp->next;
//         index++;
//     }

//     ListNode*curr=prev->next;
//     prev->next=null;
//     delete curr;

//     return head;
// }


//---------------------------------------------------------------- 
#include<bits/stdc++.h>
using namespace std;

//time complexity is O(n^2)
//space complexity is O(1)
int minimumsize(vector<int>arr, int target){
    int n=arr.size();
    int minilen=INT_MAX;
    for(int i=0; i<n; i++)
    {
        int sum=0;
        for(int j=i; j<n; j++)
        {
            sum+=arr[j];
            if(sum>=target)
            {
                minilen=min(minilen, j-i+1);
                break;
            }
        }
    }
    return minilen;
}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
int optimalway(vector<int>arr, int target)
{
    int n=arr.size();
    int i=0;
    int j=0;
    int sum=0;
    int minlen=INT_MAX;
    while(j<n)
    {
        sum+=arr[j];

        if(sum>=target)
        {
            minlen=min(minlen, j-i+1);

            sum-=arr[i];
            i++;
        }

        j++;
    }
    return minlen;
}

//count occurrence of anagrams 
bool isAnagrams(string s1, string s2)
{
    vector<int>freq(26, 0);
    for(int i=0; i<s1.length(); i++)
    freq[s1[i]-'a']++;

    for(int i=0; i<s2.length(); i++)
    freq[s2[i]-'a']--;

    for(int i=0; i<26; i++)
    {
        if(freq[i]!=0)
        return false;
    }
    return true;
}
int countAnagram(string txt, string pat)
{
    int n=txt.length();
    int m=pat.length();

    if(m>n)
    return 0;

    int count=0;
    for(int i=0; i<=n-m; i++)
    {
        string substr="";
        for(int j=i; j<=i+m; j++)
        {
            substr+=txt[j];
        }

        if(isAnagrams(substr, pat))
        {
            count++;
        }
    }
    return count;
}

int countoccAnagram(string txt, string pat)
{
    int n=txt.length();
    int m=pat.length();

    if(m>n)
    return 0;

    unordered_map<char, int>mp;
    for(int i=0; i<m; i++)
    {
        mp[pat[i]]++;
    }

    int count=0;
    for(int i=0; i<n-m; i++)
    {
        unordered_map<char,int>temp=mp;
        bool isAnagram=true;

        for(int j=i; j<i+m; j++)
        {
            temp[txt[j]]--;
            if(temp.find(txt[j])==temp.end())
            {
                isAnagram=false;
                break;
            }

            if(temp[txt[j]]==0)
            {
                temp.erase(txt[j]);
            }
        }

        if(isAnagram && temp.empty())
        {
            count++;
        }
    }
    return count;
}

int optimalwayAnagram(string txt, string pat)
{
    int n=txt.length();
    int m=pat.length();

    if(m>n)
    return 0;

    vector<int>freq(26, 0);
    vector<int>window(26, 0);

    for(int i=0; i<m; i++)
    freq[pat[i]-'a']++;

    int i=0;
    int j=0;
    int k=pat.length();
    int count=0;
    while(j<n)
    {
        window[txt[j]-'a']++;

        if(j-i+1<k)
        j++;

        if(j-i+1==k)
        {
            if(freq==window)
            {
                count++;
            }

            window[txt[i]-'a']--;
            i++;
            j++;
        }
    }
    return count;
}

bool isAllZero(vector<int>arr)
{
    for(int i=0; i<26; i++)
    {
        if(arr[i]!=0)
        return false;
    }

    return true;
}
int optimalwayAnagram(string txt, string pat)
{
    int n=txt.length();
    int m=pat.length();

    if(m>n)
    return 0;

    vector<int>freq(26, 0);

    for(int i=0; i<m; i++)
    freq[pat[i]-'a']++;

    int i=0;
    int j=0;
    int k=pat.length();
    int count=0;
    while(j<n)
    {
        freq[txt[j]-'a']++;

        if(j-i+1<k)
        j++;

        if(j-i+1==k)
        {
            if(isAllZero(freq))
            {
                count++;
            }

            freq[txt[i]-'a']--;
            i++;
        }
    }
    return count;
}

//---------------------------------------------------- 
#include<bits/stdc++.h>
using namespace std;

bool isAllSame(vector<int>&freq, vector<int>&window)
{
    for(int i=0; i<256; i++)
    {
        //this condition means required character frequency is more 
        //and same chararacter frequency in window is less than return 
        //false
        if(freq[i]>window[i]) 
        return false;
    }
    return true;
}
string minwindowsubstr(string s, string t)
{
    int n=s.length();
    int m=t.length();

    if(m>n)
    return " ";

    vector<int>freq(256, 0);
    for(int i=0; i<m; i++)
    freq[t[i]]++;

    int minlength=INT_MAX;
    string ans=" ";

    for(int i=0; i<n; i++)
    {
        vector<int>window(256, 0);
        for(int j=i; j<n; j++)
        {
            window[t[j]]++;

            if(j-i+1<m)
            continue;

            if(isAllSame(freq, window))
            {
                int windowlen=j-i+1;
                if(windowlen<minlength)
                {
                    minlength=windowlen;
                    ans=substr(i, windowlen);
            
                }
                break;
            }
        }
    }
    return ans;
}


//optimal way  
string minwindowoptimal(string s, string t)
{
    int n=s.length();
    int m=t.length();

    if(m>n)
    return " ";

    unordered_map<char,int>mp;
    for(int i=0; i<m; i++)
    mp[t[i]]++;

    int minlength=INT_MAX;
    int requiredcount=m;
    int startindex=0;
    int i=0;
    int j=0;
    while(j<n)
    {
        if(mp[s[j]]>0)
        requiredcount--;

        mp[s[j]]--;

        while(requiredcount==0)
        {
            if(j-i+1<minlength)
            {
                minlength=j-i+1;
                startindex=i;
            }

            if(mp[s[i]]>0)
            requiredcount++;

            mp[s[i]]++;
            i++;
        }

        j++;
    }

    return minlength==INT_MAX ? " " : substr(startindex, minlength);
}

vector<int>firstNeg(vector<int>arr, int k)
{
    int n=arr.size();

    vector<int>ans;
    for(int i=0; i<n-k; i++)
    {
        bool isNeg=false;
        int neg=0;
        for(int j=i; j<i+k ;j++)
        {
            if(arr[j]<0)
            {
                neg=arr[j];
                isNeg=true;
                break;
            }

            ans.push_back(neg);
        }

        if(!isNeg)
        {
            ans.push_back(0);
        }
    }
    return ans;
}

vector<int>firstNegOptimal(vector<int>arr, int k)
{
    int n=arr.size();

    deque<int>dq;
    vector<int>ans;
    int i=0;
    int j=0;
    while(j<n)
    {
        if(arr[j]<0)
        dq.push_back(arr[j]);

        if(j-i+1==k)
        {
            if(!dq.empty())
            {
                ans.push_back(dq.front());
            }
            else
            {
                ans.push_back(0);
            }

            if(arr[i]<0 && !dq.empty())
            {
                dq.pop_front();
            }

            i++;
        }

        j++;
    }
    return ans;
}

bool isVowel(char ch)
{
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}
int maximumvowel(string s, int k)
{
    int n=s.length();
    int count=0;

    int maxicount=INT_MIN;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; i++)
        {
            
            if(isVowel(s[j]) && j-i+1==k)
            {
                count++;
            }
            maxicount=max(maxicount, count);
        }
    }
    return maxicount;
}

bool findfixedbound(vector<int>arr, int n, int mink, int maxk)
{

}
int countfixedbound(vector<int>arr, int mink, int maxk)
{
    int n=arr.size();
    if(n==0 || n==1)
    return 0;

    int count=0;

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int m=j-i+1;

            if(m==1)
            continue;

            if(findfixedbound(arr, m, mink, maxk))
            {
                count++;
            }
        }
    }
    return count;
}

int countsubarrfinxedbound(vector<int>arr, int mink, int maxk)
{
    int n=arr.size();

    if(n==0 || n==1)
    return 0;
 
    int defaultindex=-1;
    int total=-1;
    int maxindex=-1;
    int minkindex=-1;

    for(int i=0; i<n; i++)
    {
        if(arr[i]<mink && arr[i]>maxk)
        defaultindex=i;

        if(arr[i]==mink)
        minkindex=i;

        if(arr[i]==maxk)
        maxindex=i;

        int way=min(maxindex, minkindex);

        total+=(defaultindex-way);
    }
    return total;
}

vector<int>kradiussubarr(vector<int>arr, int k)
{
    int n=arr.size();
    if(k==0)
    return arr;

    vector<int>ans(n, -1);
    if(2*k+1>n)
    return ans;

    for(int i=k; i<=n-k; i++)
    {
        int sum=0;
        for(int j=i-k; j<i+k; j++)
        {
            sum+=arr[j];
        }

        ans[i]=sum/(2*k+1);
    }
    return ans;
}

vector<int>betterapproach(vector<int>arr, int k)
{
    int n=arr.size();
    vector<int>ans(n, -1);

    if(k==0)
    return arr;


    if(2*k+1>n)
    return ans;

    vector<int>prefix;
    prefix[0]=arr[0];

    for(int i=1; i<n; i++)
    prefix[i]=prefix[i-1]+arr[i-1];

    int sum=0;

    for(int i=k; i<n-k; i++)
    {
        sum+=prefix[i+k]-prefix[i-k];
        ans[i]=sum/(2*k+1);
    }
    return ans;
}


vector<int>optimalapp(vector<int>arr, int k)
{
    int n=arr.size();
    vector<int>ans(n, -1);

    if(k==0)
    return arr;

    if(2*k+1>n)
    return ans;

    int left=0;
    int right=2*k;
    int i=k;
    int sum=0;
    for(int i=left; i<right; i++)
    sum+=arr[i];
    
    ans[i]=sum/(2*k+1);

    i++;

    while(right<n)
    {
        int remove=arr[left-1];
        int add=arr[right+1];

        sum+=add-remove;

        ans[i]=sum/(2*k+1);
        i++;
        left++;
        right++;
    }

    return ans;
}

//------------------------------------------------------------ 
int maxcard(vector<int>arr, int k)
{
    int n=arr.size();
    int leftsum=0;

    for(int i=0; i<k; i++)
    {
        leftsum+=arr[i];
    }

    int maxisum=leftsum;
    int rightindex=n-1;
    int rightsum=0;
    for(int i=k-1; i>=0; i--)
    {
        leftsum-=arr[i];
        rightsum+=arr[rightindex];

        maxisum=max(maxisum, leftsum+rightsum);
        rightindex=-1;
    }
    return maxisum;
}

int maxlengthofnonrepetingchar(string str)
{
    int n=str.length();

    int maxlength=INT_MIN;
    for(int i=0; i<n; i++)
    {
        unordered_map<char, int>mp;
        for(int j=i; j<n; j++)
        {
            if(mp.find(str[j])==mp.end())break;

            maxlength=max(maxlength, j-i+1);
            mp[str[j]]=1;
        }
    }
    return maxlength;
}

int betterway(string str)
{
    int n=str.size();
    vector<int>freq(256, 0);

    int i=0;
    int j=0;
    int maxlength=INT_MIN;
    while(j<n)
    {
        freq[str[j]]++;

        while(freq[str[j]]==1)
        {
            if(freq[str[j]]>i)
            {
                i++;
            }
        }

        maxlength=max(maxlength, j-i+1);
        j++;
    }
    return maxlength;
}

vector<int>firstneg(vector<int>arr, int k)
{
    int n=arr.size();
    vector<int>ans;
    for(int i=0; i<n-k; i++)
    {
        bool isNeg=true;
        for(int j=i; j<i+k; j++)
        {
            if(arr[j]<0)
            {
                ans.push_back(arr[j]);
                break;
            }
        }
    }
}


vector<int>twosum(vector<int>arr, int target)
{
    int n=arr.size();

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

vector<int>twosumoptimal(vector<int>arr, int target)
{
    int n=arr.size();
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

bool twosumoptimalsecond(vector<int>arr, int target)
{
    int n=arr.size();
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        if(arr[start]+arr[end]==target)
        {
            return true;
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
    return false;
}

vector<vector<int>>threesum(vector<int>arr, int target)
{
    int n=arr.size();
    

    unordered_set<vector<int>>st;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if(arr[i]+arr[j]+arr[k]==target)
                {
                    vector<int>temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    sort(arr.begin(), arr.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(), st.end());
    return ans;
}

int fruitebrute(vector<int>arr)
{
    int n=arr.size();
    int maxlength=INT_MIN;
    for(int i=0; i<n ; i++)
    {
        unordered_map<int,int>mp;
        for(int j=i; j<n; j++)
        {
            mp[arr[j]]++;

            if(mp.size()>2)
            break;
            
            maxlength=max(maxlength, j-i+1);
        }
    }
    return maxlength;
}

int fruitoptimal(vector<int>arr)
{
    int n=arr.size();
    unordered_map<int,int>mp;
    int i=0;
    int j=0;
    int maxlength=INT_MIN;
    while(j<n)
    {
        mp[arr[j]]++;

        if(mp.size()>2)
        {
            while(mp.size()>2)
            {
                mp[arr[i]]--;
                if(mp[arr[i]]==0)
                mp.erase(arr[i]);

                i++;
            }
        }

        maxlength=max(maxlength, j-i+1);
        j++;
    }
    return maxlength;
}

int longestsubstring(string s)
{
    int n=s.size();
    int maxlength=INT_MIN;
    for(int i=0; i<n; i++)
    {
        unordered_map<char, int>mp;
        for(int j=i; j<n; j++)
        {
            mp[s[j]]++;

            if(mp.find(s[j])!=mp.end())
            break;

            maxlength=max(maxlength, j-i+1);
        }
    }
    return maxlength;
}

int longestsubstringoptimal(string s)
{
    int n=s.length();
    unordered_map<char, int>mp;
    int maxlength=INT_MIN;
    int i=0;
    int j=0;
    while(j<n)
    {
        if(mp.find(s[j])!=mp.end())
        {
            if(mp[s[j]]>=i)
            {
                i=mp[s[j]]+1;
            }
        }

        mp[s[j]]=i;
        maxlength=max(maxlength, j-i+1);
        j++;
    }
    return maxlength;
}

int maxicardobtain(vector<int>arr, int k)
{
    int n=arr.size();
    int leftsum=0;
    for(int i=0; i<k; i++)
    {
        leftsum+=arr[i];
    }

    int rightsum=0;
    int maxisum=leftsum;
    int index=n-1;
    for(int i=k-1; i>=0; i--)
    {
        leftsum-=arr[i];
        rightsum+=arr[index];
        index--;

        maxisum=max(maxisum, leftsum+rightsum);
    }
    return maxisum;
}

int maximumone(vector<int>arr, int k)
{
    int n=arr.size();
    int maxlength=INT_MIN;
    for(int i=0; i<n; i++)
    {
        int zerocount=0;
        for(int j=i; j<n; j++)
        {
            if(arr[j]==0)
            zerocount++;

            if(zerocount>k)
            break;

            maxlength=max(maxlength, j-i+1);
        }
    }
    return maxlength;
}

int maximumonebetter(vector<int>arr, int k)
{
    int n=arr.size();
    int i=0;
    int j=0;
    int maxlength=INT_MIN;
    int zerocount=0;
    while(j<n)
    {
        if(arr[j]==0)
        zerocount++;

        if(zerocount>k)
        {
            if(arr[i]==0)
            zerocount--;
            i++;
        }
       
        if(zerocount<=k)
        maxlength=max(maxlength, j-i+1);
    }
    return maxlength;
}

vector<vector<int>>optimalwayso(vector<int>arr, int target)
{
    sort(arr.begin(), arr.end());
    int n=arr.size();
    vector<vector<int>>ans;
    for(int i=0; i<n; i++)
    {
        if(i>0 && arr[i]==arr[i-1])
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


int majorityoptimal(vector<int>arr)
{
    int n=arr.size();
    vector<int>ans;

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
        else if(count1==0 && el1!=arr[i])
        {
            count1=1;
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
        count3++;

        if(el2==arr[i])
        count4++;
    }

    if(count3>n/3)
    ans.push_back(el1);

    if(count4>n/3)
    ans.push_back(el2);
}

int fruitbrute(vector<int>arr, int k)
{
    int n=arr.size();
    int maxlength=INT_MIN;
    for(int i=0; i<n; i++)
    {
        unordered_map<int,int>mp;
        for(int j=i; j<n; j++)
        {
            mp[arr[j]]++;

            if(mp.size()>2)
            break;

            maxlength=max(maxlength, j-i+1);
        }
    }
    return maxlength;
}

int fruitoptimal(vector<int>arr, int k)
{
    int n=arr.size();
    unordered_map<int,int>mp;
    int i=0;
    int j=0;
    int maxlength=INT_MIN;
    while(j<n)
    {
        mp[arr[j]]++;

        while(mp.size()>2)
        {
            mp[arr[i]]--;
            if(mp[arr[i]]==0)
            mp.erase(arr[i]);

            i++;
        }

        if(mp.size()<=2)
        maxlength=max(maxlength, j-i+1);
        i++;
    }
    return maxlength;
}


int maximumcard(vector<int>arr, int k)
{
    int n=arr.size();
    int maxisum=INT_MIN;
    int leftsum=0;
    for(int i=0; i<k; i++)
    leftsum+=arr[i];

    int index=n-1;
    maxisum=leftsum;
    int rightsum=0;
    for(int i=k-1; i>=0; i--)
    {
        rightsum+=arr[index];
        leftsum-=arr[i];
        maxisum=max(maxisum, leftsum+rightsum);
        index--;
    }
    return maxisum;
}

int longestsubstring(string s)
{
    int n=s.length();
    int maxlength=INT_MIN;
    for(int i=0; i<n; i++)
    {
        unordered_map<char, int>mp;
        for(int j=i; j<n; j++)
        {
            if(mp.find(s[j])!=mp.end())
            break;

            mp[s[j]]=1;
            maxlength=max(maxlength, j-i+1);
        }
    }
    return maxlength;
}


int optimalapp(string s)
{
    int n=s.size();
    int i=0;
    int j=0;
    int maxlength=INT_MIN;
    unordered_map<char, int>mp;
    while(j<n)
    {
        mp[s[j]]++;
        if(mp.find(s[j])!=mp.end())
        {
            if(mp[s[j]]>=i)
            {
                i=mp[s[j]]+1;
            }
        }

        maxlength=max(maxlength, j-i+1);
        j++;
    }
    return maxlength;
}

int maxone(vector<int>arr, int k)
{
    int n=arr.size();
    int maxlength=0;
    for(int i=0; i<n; i++)
    {
        int zerocount=0;
        for(int j=i; j<n; j++)
        {
            if(arr[j]==0)
            zerocount++;

            if(zerocount>k)
            break;

            if(zerocount<=k)
            maxlength=max(maxlength, j-i+1);
        }
    }
    return maxlength;
}

int betterapp(vector<int>arr, int k)
{
    int n=arr.size();
    int maxlength=INT_MIN;
    int i=0;
    int j=0;
    int zerocount=0;
    while(j<n)
    {
        if(arr[j]==0)
        zerocount++;

        while(zerocount>k)
        {
            if(arr[i]==0)
            zerocount--;
            i++;
        }
        
        if(zerocount<=k)
        maxlength=max(maxlength, j-i+1);
        j++;
    }
    return maxlength
}

int maxoneoptimal(vector<int>arr, int k)
{
    int n=arr.size();
    int i=0;
    int j=0;
    int maxlength=INT_MIN;
    int zerocount=0;
    while(j<n)
    {
        if(arr[j]==0)
        zerocount++;

        if(zerocount>k)
        {
            if(arr[i]==0)
            zerocount--;

            i++;
        }

        if(zerocount<=k)
        maxlength=max(maxlength, j-i+1);
        j++;
    }
    return maxlength;
}

int maxreplacemnt(string s, int k)
{
    int n=s.size();
    int maxlength=INT_MIN;
    for(int i=0; i<n; i++)
    {
        unordered_map<char, int>mp;
        int maxfeq=-1;
        for(int j=i; j<n; j++)
        {
            mp[s[j]]++;
            maxfeq=max(maxfeq, mp[s[j]]);

            if((j-i+1)-maxfeq<=k)
            maxlength=max(maxlength, j-i+1);
        }
    }
}

//-------------------------------------------------------------- 
int maximumcardobtain(vector<int>arr, int k)
{
    int n=arr.size();
    int leftsum=0;
    int maxsum=INT_MIN;
    for(int i=0; i<k; i++)
    {
        leftsum+=arr[i];
    }
    
    maxsum=leftsum;
    int rightsum=0;
    int index=n-1;
    for(int i=k-1; i>=0; i--)
    {
        leftsum-=arr[i];
        rightsum+=arr[index];
        maxsum=max(maxsum, leftsum+rightsum);
        index--;
    }
    return maxsum;
}

int longestsubstringbrute(string s)
{
    int n=s.size();
    int maxlength=INT_MIN;
    for(int i=0; i<n; i++)
    {
        unordered_map<char, int>mp;
        for(int j=i; j<n; j++)
        {
            if(mp.find(s[j])!=mp.end())
            break;

            mp[s[j]]++;
            maxlength=max(maxlength, j-i+1);
        }
    }
    return maxlength;
}

int optimalapproach(string s)
{
    int n=s.size();
    int i=0;
    int j=0;
    int maxlength=INT_MIN;
    unordered_map<char, int>mp;
    while(j<n)
    {
        mp[s[j]]++;
        while(mp.find(s[j])!=mp.end())
        {
            if(mp[s[j]]>=i)
            {
                i=mp[s[j]]+1;
            }
        }

        maxlength=max(maxlength, j-i+1);
        j++;
    }
    return maxlength;
}

int fruitebrute(vector<int>arr)
{
    int n=arr.size();
    int maxlength=INT_MIN;
    for(int i=0; i<n; i++)
    {
        unordered_map<int,int>mp;
        for(int j=i; j<n; j++)
        {
            if(mp.size()>2)
            break;

            if(mp.size()<=2)
            maxlength=max(maxlength, j-i+1);

            mp[arr[j]]++;
        }
    }
    return maxlength;
}

int betterway(vector<int>arr)
{
    int n=arr.size();
    int i=0;
    int j=0;
    int maxlength=INT_MIN;
    unordered_map<int,int>mp;
    while(j<n)
    {
        mp[arr[j]]++;
        while(mp.size()>2)
        {
            mp[arr[i]]--;

            if(mp[arr[i]]==0)
            mp.erase(arr[i]);

            i++;
        }

        if(mp.size()<=2)
        maxlength=max(maxlength, j-i+1);

        j++;
    }
    return maxlength;
}

int optimalapproach(vector<int>arr)
{
    int n=arr.size();
    int i=0;
    int j=0;
    int maxlength=INT_MIN;
    unordered_map<int,int>mp;
    while(j<n)
    {
        mp[arr[j]]++;
        if(mp.size()>2)
        {
            mp[arr[i]]--;
            if(mp[arr[i]]==0)
            mp.erase(arr[i]);

            i++;
        }

        if(mp.size()<=2)
        maxlength=max(maxlength, j-i+1);

        j++;
    }
    return maxlength;
}

int maxone(vector<int>arr, int k)
{
    int n=arr.size();
    int maxlength=INT_MIN;
    for(int i=0; i<n; i++)
    {
        int zerocount=0;
        for(int j=i; j<n; j++)
        {
            if(arr[j]==0)
            zerocount++;

            if(zerocount>k)
            break;
            
            if(zerocount<=k)
            maxlength=max(maxlength, j-i+1);
        }
    }
    return maxlength;
}


int betterway(vector<int>arr, int k)
{
    int n=arr.size();
    int i=0;
    int j=0;
    int zerocount=0;
    int maxlength=INT_MIN;
    while(j<n)
    {
        if(arr[j]==0)
        zerocount++;

        while(zerocount>k)
        {
            if(arr[i]==0)
            zerocount--;

            i++;
        }

        if(zerocount<=k)
        maxlength=max(maxlength, j-i+1);

        j++;
    }
    return maxlength;
}

int optimalway(vector<int>arr, int k)
{
    int n=arr.size();
    int i=0;
    int j=0;
    int  zerocount=0;
    int maxlength=INT_MIN;
    while(j<n)
    {
        if(arr[j]==0)
        zerocount++;

        if(zerocount>k)
        {
            if(arr[i]==0)
            zerocount--;

            i++;
        }

        if(zerocount<=k)
        maxlength=max(maxlength, j-i+1);

        j++;
    }
    return maxlength;
}

int minimumsizesubarrsum(vector<int>arr, int target)
{
    int n=arr.size();
    int minlength=INT_MAX;
    for(int i=0; i<n; i++)
    {
        int sum=0;
        for(int j=i; j<n; j++)
        {
            sum+=arr[j];
            if(sum>=target)
            minlength=min(minlength, j-i+1);
        }
    }
    return minlength;
}

int optmalapproach(vector<int>arr, int target)
{
    int n=arr.size();
    int minlength=INT_MAX;
    int i=0;
    int j=0;
    int sum=0;
    while(j<n)
    {
        sum+=arr[j];

        if(sum>=target)
        {
            minlength=min(minlength, j-i+1);

            sum-=arr[i];
            i++;
        }
        j++;
    }
    return minlength;
}

vector<int>firstneg(vector<int>arr, int k)
{
    int n=arr.size();
    vector<int>ans;
    for(int i=0; i<n-k; i++)
    {
        bool isNeg=false;
        for(int j=i; j<i+k; j++)
        {
            if(arr[j]<0)
            {
                ans.push_back(arr[j]);
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

vector<int>optimalwayfirst(vector<int>arr, int k)
{
    int n=arr.size();
    int i=0;
    int j=0;
    deque<int>dq;
    vector<int>ans;
    while(j<n)
    {
        if(arr[j]<0)
        dq.push_back(arr[j]);

        if(j-i+1==k)
        {
            if(!dq.empty())
            {
                ans.push_back(dq.front());
            }
            else 
            {
                ans.push_back(0);
            }

            if(arr[i]<0 && !dq.empty())
            {
                dq.pop_front();
                i++;
            }
        }
        j++;
    }
    return ans;
}

vector<int>slidingwindow(vector<int>arr, int k)
{
    int n=arr.size();
    vector<int>ans;

    if(k==1 || n<k)
    return arr;

    for(int i=0; i<n-k; i++)
    {
        int maxele=INT_MIN;
        for(int j=i; j<i+k; j++)
        {
            maxele=max(maxele, arr[j]);

            ans.push_back(maxele);
        }
    }
    return ans;
}


