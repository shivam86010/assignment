#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


int maxcardobtain(vector<int>arr, int k)
{
    int n=arr.size();
    int leftsum=0;
    for(int i=0; i<k; i++)
    leftsum+=arr[i];

    int rightsum=0;
    int index=n-1;
    int maxsum=leftsum;
    for(int i=k-1; i>=0; i--)
    {
        leftsum-=arr[i];
        rightsum+=arr[index];
        maxsum=max(maxsum, leftsum+rightsum);
        index--;
    }
    return maxsum;
}

int fruitofbasket(vector<int>arr)
{
    int n=arr.size();
    int maxlength=INT_MIN;
    for(int i=0; i<n; i++)
    {
        unordered_map<int,int>mp;
        for(int j=i; j<n; j++)
        {
            mp[arr[i]]++;
            if(mp.size()<=2)
            {
                maxlength=max(maxlength, j-i+1);
            }
            else 
            {
                break;
            }
        }
    }
    return maxlength;
}

// 1 3 7 3 1
int fruitofbasketopt(vector<int>arr)
{
    int n=arr.size();
    int i=0;
    int j=0;
    int maxlength=-1;
    unordered_map<int,int>mp;
    while(j<n)
    {
        mp[arr[j]]++

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
            ans.push_back(-1);
        }
    }
    return ans;
}

vector<int>firstnegopt(vector<int>arr, int k)
{
    int n=arr.size();
    int i=0;
    int j=0;
    vector<int>ans;
    deque<int>dq;
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
                ans.push_back(-1);
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
bool checkAnagram(string temp, string pat)
{
    vector<int>mp;
    for(int i=0; i<temp.length(); i++)
    {
        mp[temp[i]-'a']++;
        mp[pat[i]-'a']--;
    }
    for(int i=0; i<mp.size(); i++)
    {
        if(mp[i]!=0)
        return false;
    }
    return true;
}
int countoccuranagram(string txt, string pat)
{
    int n=txt.length();
    int m=pat.length();
    int count=0;
    for(int i=0; i<n; i++)
    {
        string temp;
        for(int j=i; j<n; j++)
        {
            temp+=txt[j];

            if(temp.length()<m)
            continue;

            if(checkAnagram(temp, pat))
            {
                count++;
            }
        }
    }
    return count;
}
bool allZero(vector<int>arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]!=0)
        return false;
    }
    return true;
}
int countoccanagramopt(string txt, string pat)
{
    int n=txt.length();
    int m=pat.length();
    vector<int>mp;
    int count=0;
    int i=0;
    int j=0;

    for(int i=0; i<m; i++)
    mp[pat[i]-'a']++;

    while(j<n)
    {
        mp[txt[j]-'a']--;
        if(j-i+1==m)
        {
            if(allZero(mp))
            {
                count++;
            }

            mp[txt[i]-'a']++;
            i++;
        }
        j++;
    }
    return count;
}

int minsubarrsum(vector<int>arr, int target)
{
    int n=arr.size();
    int minlength=-1;
    for(int i=0; i<n; i++)
    {
        int sum=0;
        for(int j=i; j<n; j++)
        {
            sum+=arr[j];
            if(sum>target)
            {
                minlength=min(minlength, j-i+1);
            }
        }
    }
    return minlength;
}

int minsubarrsumopt(vector<int>arr, int target)
{
    int n=arr.size();
    int minlength=-1;
    int i=0;
    int j=0;
    int sum=0;
    while(j<n)
    {
        sum+=arr[j];

        while(sum>target)
        {
            minlength=min(minlength, j-i+1);

            sum-=arr[i];
            i++;
        }

        j++;
    }
    return minlength;
}

vector<int>twosumbrute(vector<int>arr, int target)
{
    vector<int>ans;
    int n=arr.size();
    for(int i=0; i<n; i++)
    {
        for(int j=i+1;j<n; j++)
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
vector<int>twosumopt(vector<int>arr, int target)
{
    int n=arr.size();
    vector<int>ans;
    unordered_map<int, int>mp;
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

vector<vector<int>>threesumbrute(vector<int>arr, int target)
{
    int n=arr.size();
    vector<vector<int>>ans;
    sort(arr.begin(), arr.end());
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

vector<vector<int>>foursumbrute(vector<int>arr, int target)
{
    int n=arr.size();
    vector<vector<int>>ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++)
    {
        if(i>0 && arr[i]==arr[i-1])
        continue;
        
        for(int j=i+1; j<n; j++)
        {
            if(j!=i+1 && arr[j]==arr[j-1])
            continue;

            int start=j+1;
            int end=n-1;
            int sum=target-arr[i]+arr[j];

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

vector<int>unionmap(vector<int>arr1, vector<int>arr2)
{
    int n=arr1.size();
    int m=arr2.size();

    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    mp[arr1[i]]++;

    for(int j=0; j<m; j++)
    mp[arr2[j]]++;

    vector<int>ans;
    for(auto it : mp)
    {
        ans.push_back(it.first);
    }
    return ans;
}

vector<int>uniontwopinter(vector<int>arr1, vector<int>arr2)
{
    int n=arr1.size();
    int m=arr2.size();
    vector<int>ans;
    int i=0;
    int j=0;
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            if(ans.size()==0 || ans.back()!=arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else 
        {
            if(ans.size()==0 || ans.back()!=arr2[j])
            {
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(i<n)
    {
        ans.push_back(arr1[i]);
        i++;
    }

    while(j<m)
    {
        ans.push_back(arr2[j]);
        j++;
    }
    return ans;
}

vector<int>intersection(vector<int>arr1, vector<int>arr2)
{
    int n=arr1.size();
    int m=arr2.size();
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

int uniquebrute(vector<int>arr)
{
    int n=arr.size();
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
        {
            return arr[i];
        }
    }
    return -1;
}
int uniquebetter(vector<int>arr)
{
    int n=arr.size();
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
int uniqueopt(vector<int>arr)
{
    int n=arr.size();
    int ans=0;
    for(int i=0; i<n; i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}

int subarrsumbrute(vector<int>arr)
{
    int n=arr.size();
    int maxisum=-1;
    for(int i=0; i<n; i++)
    {
        int sum=0;
        for(int j=i; j<n; j++)
        {
            sum+=arr[j];
            maxisum=max(maxisum, sum);
        }
    }
    return maxisum;
}

int subarrsumoptmal(vector<int>arr)
{
    int n=arr.size();
    int sum=0;
    int maxisum=-1;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        maxisum=max(maxisum, sum);

        if(sum<0)
        {
            sum=0;
        }
    }
    return maxisum;
}
int majorityelement(vector<int>arr)
{
    int n=arr.size();
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

        if(count>n/2)
        {
            return arr[i];
        }
    }
    return -1;
}

int majoritybetter(vector<int>arr)
{
    int n=arr.size();
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }

    for(auto it :mp)
    {
        if(it.second>n/2)
        {
            return it.first;
        }
    }
    return -1;
}
int majorityopt(vector<int>arr)
{
    int n=arr.size();
    int el;
    int count=0;
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
        if(el==arr[i])
        {
            count1++;
        }
    }

    if(count>n/2)
    return el;

    return -1;
}

int subarrsumk(vector<int>arr, int k)
{
    int n=arr.size();
    int maxlength=-1;
    for(int i=0; i<n; i++)
    {
        int sum=0;
        for(int j=i; j<n; j++)
        {
            sum+=arr[j];
            if(sum==k)
            {
                maxlength=max(maxlength, j-i+1);
            }
        }
    }
    return maxlength;
}
int subarrsumkbetter(vector<int>arr, int k)
{
    int n=arr.size();
    unordered_map<int,int>mp;
    int maxlength=-1;
    int i=0;
    int j=0;
    int sum=0;
    while(j<n)
    {
        sum+=arr[j];
        if(sum==k)
        {
            maxlength=max(maxlength, j-i+1);
        }

        while(mp.find(sum)!=mp.end())
        {
            maxlength=max(maxlength, i-mp[sum]);

            sum-=arr[i];
            i++;
        }

        if(mp.find(sum)==mp.end())
        mp[sum]=j;
        j++;
    }
    return maxlength;
}

int maxsubarrsumkoptmal(vector<int>arr, int k)
{
    int n=arr.size();
    int maxlength=-1;
    int i=0;
    int j=0;
    int sum=0;
    while(j<n)
    {
        sum+=arr[j];

        if(sum==k)
        {
            maxlength=max(maxlength, j-i+1);

            sum-=arr[i];
            i++;
        }

        j++;
    }
    return maxlength;
}

//-------------------------------- stack------------------- 
void helper(stack<int>st, int num)
{
    if(st.empty())
    {
        st.push(num);
        return ;
    }

    int take=st.top();
    st.pop();

    helper(st, num);
    st.push(take);
}
void insertbottom(stack<int>st, int num)
{
    helper(st, num);
}

void insertsortedway(stack<int>st, int num)
{
    if(st.empty() || st.top()<num)
    {
        st.push(num);
        return ;
    }

    int take=st.top();
    st.pop();

    insertsortedway(st, num);
    st.push(take);
}
void sortstack(stack<int>st)
{
    if(st.empty())
    return ;

    int take=st.top();
    st.pop();

    sortstack(st);
    insertsortedway(st, take);
}

bool isvalidparent(string s)
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
                if((ch==')' && top=='(')|| (ch=='}' && top=='{') ||(ch==']' && top=='['))
                {
                    st.pop();
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

//--------------------------------------------------------------------------------------- 
ListNode*findmiddle(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;

    int len=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }

    int half=len/2;
    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
    }
    return temp;
}
ListNode*findmiddleOpt(ListNode*head)
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

ListNode*reversestack(ListNode*head)
{
    if(head==NULL  || head->next==NULL)
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
        temp=temp->next;
    }
    return head;
}
ListNode*reverseRec(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;

    ListNode*newhead=reverseRec(head->next);
    head->next->next=newhead;
    head->next=NULL;
    return newhead;
}

ListNode*reverseIterate(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;

    ListNode*curr=head;
    ListNode*prev=NULL;
    while(curr!=NULL)
    {
        ListNode*nextn=curr->next;
        curr->next=prev;
        prev=curr;
        curr=curr->next;
    }
    return prev;
}


//------------------------------------------------------------------------------
//detect a cycle in list (using hashmap)
bool isCycle(ListNode*head)
{
    if(head==NULL)
    return false;

    ListNode*temp=head;
    unordered_map<ListNode*, int>mp;
    while(temp!=NULL)
    {
        if(mp.find(temp)!=mp.end())
        {
            return true;
        }

        mp[temp]=1;
        temp=temp->next;
    }
    return temp;
}
//using slow and fast pointer 
bool isCycleopt(ListNode*head)
{
    if(head==NULL)
    return false;

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

//------------------------------------------------------------------------------
//starting point of loop in list (using hashmap)
ListNode*startingPointLoop(ListNode*head)
{
    if(head==NULL)
    return NULL;

    ListNode*temp=head;
    unordered_map<ListNode*, int>mp;
    while(temp!=NULL)
    {
        if(mp.find(temp)!=mp.end())
        {
            return temp;
        }

        mp[temp]++;
        temp=temp->next;
    }
    return NULL;
}
//using slow and fast pointer 
ListNode*startPointLoopOPT(ListNode*head)
{
    if(head==NULL)
    return head;

    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        {
            slow=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

//------------------------------------------------------------------------------
//length of loop in list  (using hashmap)
int lenofLoop(ListNode*head)
{
    if(head==NULL)
    return 0;

    ListNode*temp=head;
    int time=0;
    unordered_map<ListNode*, int>mp;
    while(temp!=NULL)
    {
        if(mp.find(temp)!=mp.end())
        {
            return (time-mp[temp]);
        }

        mp[temp]=time;
        time++;
        temp=temp->next;
    }
    return 0;
}
//using slow and fast pointer 

//------------------------------------------------------------------------------
//check palindrome of list (using stack -or- array data structure )
bool palindrome(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return true;

    ListNode*temp=head;
    stack<int>st;
    while(temp!=NULL)
    {
        st.push(temp->val);
        temp=temp->next;
    }

    temp=head;
    while(temp!=NULL)
    {
        if(st.top()!=temp->val)
        return false;

        st.pop();
        temp=temp->next;
    }
    return true;
}
//or use reverse of middle half of list 
ListNode*reverse(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;

    ListNode*curr=head;
    ListNode*prev=NULL;
    while(curr!=NULL)
    {
        ListNode*nextn=curr->next;
        curr->next=prev;
        prev=curr;
        curr=curr->next;
    }
    return prev;
}
bool isPlaindromeopt(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;

    ListNode*slow=head;
    ListNode*fast=head;
    slow=slow->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    ListNode*mid=reverse(slow);
    ListNode*first=head;

    while(mid!=NULL)
    {
        if(first->val!=mid->val)
        return false;

        mid=mid->next;
        first=first->next;
    }

    reverse(slow);
    return true;
}

//------------------------------------------------------------------------------
//segrregate odd and even list (using store  in array )
//or change link method 
//make odd and even list and than  merge them 

//------------------------------------------------------------------------------
//sort 0's , 1's, 2's list (using count method )
ListNode*sort012(ListNode*head)
{
    if(head==NULL || head->next!=NULL)
    return head;

    int count0=0;
    int count1=0;
    int count2=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        if(temp->val==0)
        {
            count0++;
        }
        else if(temp->val==1)
        {
            count1++;
        }
        else 
        {
            count2++;
        }
    }

    temp=head;
    while(temp!=NULL)
    {
        while(count0--)
        {
            temp->val=0;
            temp=temp->next;
        }

        while(count1--)
        {
            temp->val=1;
            temp=temp->next;
        }

        while(count2--)
        {
            temp->val=2;
            temp=temp->next;
        }
    }
    return head;
}
//or make seprate list of 0 , 1 and 2 
ListNode*sort012opt(ListNode*head)
{
    if(head==NULL || head->next!=NULL)
    return head;

    ListNode*zerohead=new ListNode(0);
    ListNode*zero=zerohead;
    ListNode*onehead=new ListNode(0);
    ListNode*one=onehead;
    ListNode*twohead=new ListNode(0);
    ListNode*two=twohead;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        if(temp->val==0)
        {
            zero->next=temp;
            zero=zero->next;
            temp=temp->next;
        }
        else if(temp->val==1)
        {
            one->next=temp;
            one=one->next;
            temp=temp->next;
        }
        else 
        {
            two->next=temp;
            temp=temp->next;
            two=two->next;
        }
    }

    zero->next=onehead->next!=NULL ? onehead->next : twohead->next;
    onehead->next=twohead->next;
    two->next=NULL;

    head=zerohead->next;
    delete (onehead);
    delete (zerohead);
    delete (twohead);
    return head;
}

//------------------------------------------------------------------------------
//delete middle node (using find length of list )
ListNode*deleteMiddle(ListNode*head)
{
    if(head==NULL)
    return NULL;

    if(head->next==NULL)
    {
        delete (head);
        return NULL;
    }

    int len=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }

    temp=head;
    int half=(len/2)-1;
    while(half--)
    {
        temp=temp->next;
    }

    ListNode*del=temp->next;
    temp->next=temp->next->next;

    delete del;

    return head;

}
//or using fast and slow pointer 
ListNode*delmiddleopt(ListNode*head)
{
    if(head==NULL)
    return NULL;

    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }

    ListNode*slow=head;
    ListNode*fast=head;
    slow=slow->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    ListNode*del=slow->next;
    slow->next=slow->next->next;

    delete (del);
    return head;
}

//------------------------------------------------------------------------------
//find intersection of two list (using difference of two list )
int findlength(ListNode*head)
{
    int len=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
}
ListNode*intersection(ListNode*head1, ListNode*head2)
{
    if(head1==NULL || head2==NULL)
    return NULL;

    ListNode*temp1=head1;
    ListNode*temp2=head2;
    int len1=findlength(head1);
    int len2=findlength(head2);

    if(len1<len2)
    {
        int diff=len1-len2;
        while(diff--)
        {
            temp1=temp1->next;
        }
    }
    else 
    {
        int diff=len2-len1;
        while(diff--)
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
// or using set data structure 
ListNode*intersectionset(ListNode*head1, ListNode*head2)
{
    if(head1==NULL || head2==NULL)
    return NULL;

    unordered_set<ListNode*>st;
    ListNode*temp1=head1;
    while(temp1!=NULL)
    {
        st.insert(temp1);
        temp1=temp1->next;
    }

    ListNode*temp2=head2;
    while(temp2!=NULL)
    {
        if(st.find(temp2)!=st.end())
        {
            return temp2;
        }

        temp2=temp2->next;
    }
    return NULL;
}
// or using two pointer method 
ListNode*intersectionopt(ListNode*head1, ListNode*head2)
{
    if(head1==NULL || head2==NULL)
    return NULL;

    ListNode*temp1=head1;
    ListNode*temp2=head2;

    while(temp1!=temp2)
    {

    }
}

//------------------------------------------------------------------------------
//Add Two list (using stack data structure)
//or using two pointer method 


