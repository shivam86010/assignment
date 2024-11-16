//number is power of two or not 
//time complexity is O(1)
//space complexity is O(1)
bool ispoweroftwo(int n)
{
    return (n>0) && (n&(n-1))==0 ;
}

//number is power of three or not 
//time complexity is O(logn)
//space complexity is O(1)
bool ispowerofthree(int n)
{
    if(n==0)
    return false;
    
    while(n%3==0)
    {
        n/=3;
    }
    return n==1;
}

//number is power of four or not 
//time complexity is O(1)
//space complexity is O(1)
bool ispoweroffour(int n)
{
    return (n>0) && ((n & (n-1))==0) && (n%3==1);
}

//kid with the greatest number of candies (given array of candies and int extracandies return bool of vector ) 
//time complexity is O(n)
//space complexity is O(1)
int greatestcandies(int candies[], int n, int extracandies)
{
    vector<bool>ans;
    int largest=candies[0];
    for(int i=1; i<n; i++)
    {
        if(candies[i]>largest)
        {
            largest=candies[i];
        }
    }
    
    for(int i=0; i<n; i++)
    {
        if(candies[i]+extracandies>=largest)
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
//time complexity is O(n)
//space complexity is O(1)
int prefixsum(int arr[], int n)
{
    vector<int>prefix;
    prefix[0]=arr[0];
    for(int i=1; i<n; i++)
    {
        prefix[i]=prefix[i-1]+arr[i];
    }
    return prefix;
}

//number of good pair 
//time complexity is O(n^2)
//space complexity is O(1)
int goodpair(int arr[], int n)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(i==j)
            continue;
            if(arr[i]==arr[j])
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
int goodpair(int arr[], int n)
{
    int count=0;
    vector<int>fre(101 0);
    for(int i=0; i<n; i++)
    {
        fre[arr[i]]++;
    }
    
    for(int i=0; i<n; i++)
    {
        count+=fre[i]*(fre[i]-1)/2;
    }
    return count;
}


//------------------------------------------------------------------------------ 

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
int binary(ListNode*head)
{
    if(head==NULL)
    return 0;
    
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

//search target in linked list
bool search(ListNode*head, int target)
{
    if(head==NULL)
    return true;
    
    ListNode*temp=head;
    while(temp!=NULL)
    {
        if(temp->val==target)
        return true;
        
        temp=temp->next;
    }
    return false;
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
ListNode*reverse(ListNode*head)
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
int lengthList(ListNode*head)
{
    if(head==NULL)
    return 0;
    
    ListNode*temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
ListNode*reverse(ListNode*head, int k)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    int n=lengthList(head);
    if(n<k)
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
    if(next!=NULL)
    {
        head->next=reverse(nextn, k);
    }
    return pre;
}

//middle of linked list 
ListNode*middlelist(ListNode*head)
{
    if(head==NULL && head->next==NULL)
    return head;
    
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
ListNode*middlelist(ListNode*head)
{
    if(head==NULL && head->next==NULL)
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
    if(head==NULL && head->next==NULL)
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
    if(head==NULL && head->next==NULL)
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
}


//remove loop from linked list
ListNode*deleteloop(ListNode*head)
{
    if(head==NULL && head->next==NULL)
    return head;
    
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        break;
    }
    
    
    if(slow==head && fast==head)
    {
        while(fast->next!=slow)
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
ListNode*removeduplicate(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    unordered_set<ListNode*>st;
    ListNode*curr=head;
    ListNode*pre=NULL;
    while(curr!=NULL)
    {
        if(st.find(curr->val)!=st.end())
        {
            pre->next=curr->next;
            delete curr;
        }
        else 
        {
            st.insert(curr->val);
            pre=curr;
        }
        curr=pre->next;
    }
    return head;
    
}


//palindrome linked list 
bool palindrome(ListNode*head)
{
    if(head==NULL)
    return true;
    
    ListNode*slow=head;
    ListNode*fast=head;
    ListNode*pre=NULL;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    
    slow->next=reverse(slow->next);
    pre->next=NULL;
    
    ListNode*first=head;
    ListNode*mid=slow->next;
    while(mid!=NULL)
    {
        if(first->val!=mid->val)
        {
            return false;
        }
        first=first->next;
        mid=mid->next;
    }
    slow->next=reverse(slow->next);
    return true;
}

//merge linked list 
ListNode*merge(ListNode*head1, ListNode*head2)
{
    if(head2==NULL)
    return head1;
    
    if(head1==NULL)
    return head2;
    
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
ListNode*merge(ListNode*head1, ListNode*head2)
{
    if(head2==NULL)
    return head1;
    
    if(head1==NULL)
    return head2;
    
    ListNode*dummy=new ListNode(0);
    ListNode*tali=dummy;
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
    tail->next=head1;
    
    if(head2!=NULL)
    tail->next=head2;
    
    return dummy->next;
}

//merge k linked list 
ListNode*merge(ListNode*head1, ListNode*head2)
{
    if(head2==NULL)
    return head1;
    
    if(head1==NULL)
    return head2;
    
    ListNode*dummy=new ListNode(0);
    ListNode*tali=dummy;
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
    tail->next=head1;
    
    if(head2!=NULL)
    tail->next=head2;
    
    return dummy->next;
}
ListNode*merheK(vector<vector<ListNode*>>list)
{
    if(list.size()==0)
    return NULL;
    
    if(list.size()==1)
    return list[1];
    
    ListNode*ans=merge(list[0], list[1]);
    for(int i=2; i<list.size(); i++)
    {
        ans=merge(ans, list[i]);
    }
    return ans;
}

//second method to merge k linked list 
class cmp 
{
    bool operator(ListNode*a, ListNode*b)
    {
        return a>b;
    }
}
ListNode*merheK(vector<vector<ListNode*>>list)
{
    if(list.size()==0)
    return NULL;
    
    if(list.size()==1)
    return list[1];
    
    priority_queue<ListNode*, vector<ListNode*>, cmp>q;
    ListNode*dummy=new ListNode(0);
    ListNode*tail=dummy;
    for(int i=0; i<list.size(); i++)
    {
        if(list[i]!=NULL)
        {
            q.push(list[i]);
        }
    }
    
    while(q.size())
    {
        ListNode*temp=q.top();
        tail->next=temp;
        tail=temp;
        
        q.pop();
        
        if(temp->next!=NULL)
        q.push(temp->next);
    }
    return dummy->next;
}
    
//intersection of linked list 
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
        while(len2-len2)
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
ListNode*oddevenlist(ListNode*head)
{
    if(head==NULL)
    return ;
    
    ListNode*odd=NULL;
    ListNode*even=NULL;
    ListNode*oddh=NULL;
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
                head=haed->next;
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

//second method  to find odd and even linked list 
ListNode*oddevenlist(ListNode*head)
{
    if(head==NULL)
    return ;
    
    ListNode*odd=head;
    ListNode*even=head->next;
    ListNode*oddh=head;
    ListNode*evenh=head->next;
    while(even!=NULL && enev->next!=NULL)
    {
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
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
bool identicallist(ListNode*head1, ListNode*head2)
{
    ListNode*temp1=head1;
    ListNode*temp2=head2;
    int count1=0;
    int count1=0;
    while(temp1!=NULL)
    {
        count1++;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        count2++;
        temp2=temp2->next;
    }
    if(count2!=count1)
    return false;
    
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->val!=temp2->val)
        {
            return true;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}


// Nth node from end of linked list 
int lengthList(ListNode*head)
{
    int count=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
int getNthFromLast(ListNode *head, int n)
{
    int len=lengthList(head);
    int i=0;
    ListNode*temp=head;
    while(i<(len-n))
    {
        i++;
        temp=temp->next;
    }
    return temp->val;
}

//swap node pairwise 
ListNode*reverse(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    ListNode*curr=head;
    int count=0;
    ListNode*pre=NULL;
    while(curr!=NULL && count<2)
    {
        ListNode*nextn=curr->next;
        curr->next=pre;
        pre=curr;
        curr=curr->next;
    }
    if(next!=NULL)
    {
        head->next=reverse(nextn);
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
//sort linked list 
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
//Partition linked List 
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
stack<int>insertatbottom(stack<int>st, int num)
{
    slove(st, num);
    return st;
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
    st.pop();
    
    reversestack(st);
    insertbottom(st, take);
}

//sort stack 
void insertsorted(stack<int>&st, int num)
{
    if(st.empty())
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
    st.pop();
    
    sortstack(st);
    insertsorted(st, take);
}

//redundant bracket (-,+,/ ,*)
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
            if(ch=='(')
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
            mini=min(mini, arr[j]);
        }
    }
    return false;
}

//optimal approach 
bool pattern132(int arr[], int  n)
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
vector<int>nextsmaller(int arr[], int n)
{
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && st.top()>=arr[i])
        st.pop();
        
        ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}

//previous smaller element int array 
vector<int>previoussmaller(int arr[], int n)
{
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=0; i<n; i+)
    {
        while(!st.empty() && st.top()>=arr[i])
        st.pop();
        
        ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}

//next greater element in array 
vector<int>nextgreater(int arr[], int n)
{
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && st.top()<=arr[i])
        st.pop();
        
        ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}

//previous greater element in array
vector<int>previousgreater(int arr[], int n)
{
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && st.top()<=arr[i])
        st.pop();
        
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
int longest(String s)
{
    int maxi=-1;
    stack<int>st;
    int n=s.length();
    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')
        {
            st.push(i);
        }
        else 
        {
            st.pop();
            if(st.empty())
            {
                st.push(i);
            }
            else 
            {
                maxi=max(maxi, i-st.top());
            }
        }
    }
    return maxi;
}

//2 method
int longest(String s)
{
    int count=0;
    int open=0;
    int close=0;
    int n=s.length();
    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')
        {
            open++;
        }
        else 
        {
            close++;
        }
        if(close>=open)
        {
            open=0;
            close=0;
        }
        else if(open==close)
        {
            count=max(count, 2*close);
        }
    }
    
    open=0;
    close=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')
        {
            open++;
        }
        else 
        {
            close++;
        }
        if(close<=open)
        {
            open=0;
            close=0;
        }
        else if(open==close)
        {
            count=max(count, 2*close);
        }
    }
    return count;
}

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
        
        if(root->right!=NULL)
        st.push(root->right);
        
        if(root->left!=NULL)
        st.push(root->left);
        
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
    while(true)
    {
        if(node->left!=NULL)
        {
            st.push(node->left);
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
bool height(TreeNode*root)
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
int slove(TreeNode*root, int &maxi)
{
    if(root==NULL)
    return 0;
    
    int lh=slove(root->left, maxi);
    int rh=slove(root->right, maxi);
    
    maxi=max(maxi, lh+rh);
    
    return 1+max(lh, rh);
}
int diameterofBT(TreeNode*root)
{
    int maxi=0;
    slove(root, maxi);
    return maxi;
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
int maximumpathsum(TreeNode*root)
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
    
    if(root1!=NULL && root2==NULL)
    return false;
    
    if(root1==NULL && root2!=NULL)
    return false;
    
    return (root1->val==root2->val) && identical(root1->left, root2->left) && identical(root1->right, root2->right);
}

//check symmetric tree  or not 
bool identical(TreeNode*root1, TreeNode*root2)
{
    if(root1==NULL && root2==NULL)
    return true;
    
    if(root1!=NULL && root2==NULL)
    return false;
    
    if(root1==NULL && root2!=NULL)
    return false;
    
    return (root1->val==root2->val) && identical(root1->left, root2->right) && identical(root1->right, root2->left);
}
bool symmetric(TreeNode*root)
{
    return identical(root->left, root->right);
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
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            level.push_back(node->val);
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
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            level.push_back(node->val);
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
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
            sum+=(node->val);
        }
        ans.push_back(sum/size);
    }
    return ans;
}

//level order successor of a node in binary tree 
int successor(TreeNode*root, int key)
{
    if(root==NULL)
    return 0;
    
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
    
    bool lefttoright=true;
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
        
        int sum=0;
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
        
        int sum=0;
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
    
    int depth=1;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(node->left==NULL && node->right==NULL)
            return depth;
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
            
        }
        depth++;
    }
    return depth;
}

//deepest leaves sum 
int deepestleafsum(TreeNode*root)
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
            
            sum+=(node->val);
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
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        
        int maxi=INT_MIN;
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
TreeNode*buttomleft(TreeNode*root)
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
        q.push(root->left);
    }
    return root;
}


//convert sorted array to binary search tree
TreeNode*maketree(vector<int>&arr, int start, int end)
{
    if(start>end)
    return NULL;
    
    int mid=(start+end)/2;
    TreeNode*root=new TreeNode(arr[mid]);
    
    root->left=maketree(arr, start, mid-1);
    root->right=maketree(arr, mid+1, end);
    
    return root;
}
TreeNode*convertsortedarrtoBST(vector<int>num)
{
    return maketree(num, 0, num.size()-1);
}

//convert sorted linked list to binary search tree 
TreeNode*maketree(vector<int>&arr, int start, int end)
{
    if(start>end)
    return NULL;
    
    int mid=(start+end)/2;
    TreeNode*root=new TreeNode(arr[mid]);
    
    root->left=maketree(arr, start, mid-1);
    root->right=maketree(arr, mid+1, end);
    
    return root;
}
TreeNode*convertsortedlisttoBST(ListNode*head)
{
    vector<int>num;
    while(head!=NULL)
    {
        num.push_back(head->val);
        head=head->next;
    }
    
    return maketree(num, 0, num.size()-1);
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
    auto pre=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    pre->next=NULL;
    
    TreeNode*root=new TreeNode(slow->val);
    root->left=convertsortedlisttoBST(head);
    root->right=convertsortedlisttoBST(slow->next);
    
    return root;
}

//make maximum binary tree 
TreeNode*maketree(vector<int>&arr, int start, int end)
{
    if(start>end)
    return NULL;
    
    int maxi=INT_MIN;
    int maxindex=-1;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>maxi)
        {
            maxi=arr[i];
            maxindex=i;
        }
    }

    TreeNode*root=new TreeNode(maxi);
    
    root->left=maketree(arr, start, maxindex-1);
    root->right=maketree(arr, maxindex+1, end);
    
    return root;
}
TreeNode*maximumBT(vector<int>num)
{
    return maketree(num, 0, num.size()-1);
}

//construct binary tree from preorder and inorder 
TreeNode*slove(vector<int>preorder, vector<int>inorder, int ps, int pe, int is, int ie, unordered_map<int,int>&mp)
{
    if(ps>pe || is>ie)
    return NULL;
    
    TreeNode*root=new TreeNode(preorder[ps]);
    int pos=mp[root];
    int left=pos-is;
    
    root->left=slove(preorder, inorder, ps+1, ps+left-1, is, pos-1, mp);
    root->right=slove(preorder, inorder, ps+left+1, pe, pos+1, ie, mp);
    
    return root;
}
TreeNode*constructBT(vector<int>preorder, vector<int>inorder)
{
    if(preorder.size()!=inorder.size())
    return NULL;
    
    unordered_map<int,int>mp;
    for(int i=0; i<inorder.size(); i++)
    mp[inorder[i]]=i;
    
    return slove(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, mp);
}

//construct binary tree from inorder and postorder 
TreeNode*slove(vector<int>postorder, vector<int>inorder, int ps, int pe, int is, int ie, unordered_map<int,int>&mp)
{
    if(ps>pe || is>ie)
    return NULL;
    
    TreeNode*root=new TreeNode(postorder[pe]);
    int pos=mp[root];
    int left=pos-is;
    
    root->left=slove(preorder, inorder, ps, ps+left, is, pos-1, mp);
    root->right=slove(preorder, inorder, ps+left+1, pe-1, pos+1, ie, mp);
    
    return root;
}
TreeNode*constructBT(vector<int>postorder, vector<int>inorder)
{
    if(postorder.size()!=inorder.size())
    return NULL;
    
    unordered_map<int,int>mp;
    for(int i=0; i<inorder.size(); i++)
    mp[inorder[i]]=i;
    
    return slove(postorder, inorder, 0, postorder.size()-1, 0, inorder.size()-1, mp);
}

//path sum
bool pathsum(TreeNode*root, int target)
{
    if(root==NULL)
    return true;
    
    if(root->left==NULL && root->right==NULL && target-root->val==0)
    return true;
    
    return pathsum(root->left, target-root->val) || pathsum(root->right, target-root->val);
}

//path sum-II
vector<vector<int>>ans;
vector<int>path;
void slove(TreeNode*root, int sum, int target)
{
    if(root==NULL)
    return ;
    
    sum+=root->val;
    path.push_back(root->val);
    if(sum==target)
    {
        ans.push_back(path);
        return ;
    }
    
    slove(root->left, sum, target);
    slove(root->right, sum, target);
    
    path.pop_back();
}
vector<vector<int>>pathsum-II(TreeNode*root, int target)
{
    int sum=0;
    slove(root, sum, target);
    return ans;
}

//binary tree path 
void slove(TreeNode*root, string temp, vector<string>&ans)
{
    if(root==NULL)
    return ;
    
    if(root->left!=NULL && root->right!=NULL)
    {
        temp+=(to_string(root->val)+"->");
    }
    else 
    {
        temp+=(to_string(root->val));
        ans.push_back(temp);
        return ;
    }
    
    slove(root->left, temp, ans);
    slove(root->right, temp, ans);
}
vector<string>binaryPath(TreeNode*root)
{
    vector<string>ans;
    string temp="";
    slove(root, temp, ans);
    return ans;
}

//sum root to leaf number (node 1->2->3==123 and so on )
void slove(TreeNode*root, int sum, int ans)
{
    if(root==NULL)
    return ;
    
    sum=sum*10+root->val;
    if(root->left==NULL && root->right==NULL)
    {
        ans+=sum;
        return ;
    }
    
    if(root->left!=NULL)
    slove(root->left, sum, ans);
    
    if(root->right!=NULL)
    slove(root->right, sum, ans);
}
int sumofroottoleaf(TreeNode*root)
{
    int sum=0;
    int ans;
    slove(root, sum, ans);
    return ans;
}

//count complete tree node 
int countcomplete(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=countcomplete(root->left);
    int rh=countcomplete(root->right);
    
    return 1+max(lh, rh);
}

//invert binary tree 
TreeNode*convertBT(TreeNode*root)
{
    if(root==NULL)
    return NULL;
    
    convertBT(root->left);
    convertBT(root->right);
    
    swap(root->left, root->right);
    
    return root;
}

//sum of left leaf node
void slove(TreeNode*root, int sum)
{
    if(root==NULL)
    return ;
    
    if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL)
    sum+=root->left->val;
    
    slove(root->left, sum);
    slove(root->right, sum);
}
int sumofleft(TreeNode*root)
{
    int sum=0;
    slove(root, sum);
    return sum;
}

//merge two binary tree 
TreeNode*merge(TreeNode*root1, TreeNode*root2)
{
    if(root1==NULL)
    return root2;
    
    if(root2==NULL)
    return root1;
    
    TreeNode*temp=new TreeNode(root1->val+root2->val);
    temp->left=merge(root1->left, root2->left);
    temp->right=merge(root1->right, root2->right);
    
    return temp;
}


//search in binary search tree recusive solution ---700
TreeNode*searchinBST(TreeNode*root, int key)
{
    if(root==NULL)
    return NULL;
    
    while(true)
    {
        if(root->val==key)
        {
            return root;
        }
        if(root->val>key)
        {
            root=root->left;
        }
        else 
        {
            root=root->right;
        }
    }
    return NULL;
}

//iterative solution
TreeNode*searchinBST(TreeNode*root, int key)
{
    if(root==NULL)
    return NULL;
    
    if(root->val==key)
    return root;
    
    if(root->val>key)
    {
        return searchinBST(root->left, key);
    }
    else 
    {
        return searchinBST(root->right, key);
    }
}

//find the ceil in a binary search tree 
int ceilvalue(TreeNode*root, int key)
{
    int ceil=-1;
    while(root!=NULL)
    {
        if(root->val==key)
        {
            ceil=root->val;
            return ceil;
        }
        if(key>root->val)
        {
            root=root->right;
        }
        else 
        {
            ceil=root->val;
            root=root->left;
        }
    }
    return ceil;
}

//find floor in binary search tree 
int floorvalue(TreeNode*root, int key)
{
    int floor=-1;
    while(root!=NULL)
    {
        if(root->val==key)
        {
            floor=root->val;
            return floor;
        }
        if(key>root->val)
        {
            floor=root->val;
            root=root->right;
        }
        else 
        {
            root=root->left;
        }
    }
    return floor;
}

//insert into a binary search tree recusive method ----701
TreeNode*insertintoBST(TreeNode*root, int key)
{
    if(root==NULL)
    return new TreeNode(key);
    
    if(root->val>key)
    {
        return insertintoBST(root->left, key);
    }
    else 
    {
        return insertintoBST(root->right, key);
    }
    return root;
}

//iterative method 
TreeNode*insertintoBST(TreeNode*root, int key)
{
    if(root==NULL)
    return new TreeNode(key);
    
    TreeNode*node=root;
    while(node!=NULL)
    {
        if(node->val>key)
        {
            if(node->left!=NULL)
            {
                node=node->left;
            }
            else 
            {
                node->left=new TreeNode(key);
                break;
            }
        }
        else 
        {
            if(node->right!=NULL)
            {
                node=node->right;
            }
            else 
            {
                node->right=new TreeNode(key);
                break;
            }
        }
    }
    return root;
}
    
//delete node in binary search tree ---450 
TreeNode*findlastright(TreeNode*root)
{
    if(root==NULL)
    return root;
    
    return findlastright(root->right);
}
TreeNod*helper(TreeNode*root)
{
    if(root->left==NULL)
    return root->right;
    
    if(root->right==NULL)
    return root->left;
    
    TreeNode*lastright=root->right;
    TreeNode*lastrightchild=findlastright(root->left);
    lastrightchild->right=lastright;
    
    return root->left;
}
TreeNode*deleteNode(TreeNode*root, int key)
{
    if(root==NULL)
    return NULL;
    
    if(root->val==key)
    return helper(root);
    
    TreeNode*node=root;
    while(node!=NULL)
    {
        if(node->val>key)
        {
            if(node->left!=NULL && node->left->val==key)
            {
                node->left=helper(node->left);
                break;
            }
            else 
            {
                node=node->left;
            }
        }
        else 
        {
            if(node->right!=NULL && node->right->val==key)
            {
                node->right=helper(node->right);
                break;
            }
            else 
            {
                node=node->right;
            }
        }
    }
    return root;
}

//valid binary search tree --- 98
bool slove(TreeNode*root, int mini, int maxi)
{
    if(root==NULL)
    return true;
    
    if(root->val>maxi && root->val<mini)
    return false;
    
    return slove(root->left, mini, root->val) && slove(root->right, root->val, maxi);
}
bool validBST(TreeNode*root)
{
    return slove(root, LONG_MIN, LONG_MAX);
}

//recover binary search tree means (swaping two node with changing the structure ) --- 99
//kth smallest element in binary search tree  brute force approach  ---230 
void preorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
int kthsmallest(TreeNode*root, int k)
{
    vector<int>ans;
    preorder(root, ans);
    sort(ans.begin(), ans.end());
    return ans[k-1];
}

//better approach 
void inorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
int kthsmallest(TreeNode*root, int k)
{
    vector<int>ans;
    inorder(root, ans);
    return ans[k-1];
}

//optimal approach 
void slove(TreeNode*root, int &ans, int count, int k)
{
    if(root==NULL)
    return ;
    
    slove(root->left, ans, count, k);
    
    count++;
    if(count==k)
    {
        ans=root->val;
        return ;
    }
    
    slove(root->right, ans, count, k);
}
int kthsmallest(TreeNode*root, int k)
{
    int ans;
    int count=0;
    preorder(root, ans, count, k);
    return ans;
}


//find the second minimum node in binary tree 
void preorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
int secondmini(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    vector<int>ans;
    preorder(root, ans);
    sort(ans.begin(), ans.end());
    int mini=ans[0];
    
    int sec=-1;
    for(int i=1; i<ans.size(); i++)
    {
        if(ans[i]!=mini)
        {
            sec=ans[i];
            break;
        }
    }
    return sec;
}

//convert binary search tree to greater tree --538 
TreeNode*convertBSTTOgreater(TreeNode*root, int sum=0)
{
    if(root==NULL)
    return NULL;
    
    convertBSTTOgreater(root->right);
    
    sum+=root->val;
    root->val=sum;
    
    convertBSTTOgreater(root->left);
    
    return root;
}

//trim binary search tree means(given a range when node node value not lie in range than simply delete) --- 669 
TreeNode*trimeBST(TreeNode*root, int low, int high)
{
    if(root==NULL)
    return NULL;
    
    if(root->val>=low && root->val<=high)
    {
        root->left=trimeBST(root->left, low, high);
        root->right=trimeBST(root->right, low, high);
        return root;
    }
    if(root->val<low)
    {
        return trimeBST(root->right, low, high);
    }
    else if(root->val>high)
    {
        return trimeBST(root->left, low, high);
    }
}

//count good node in binary tree (good means root to till node node value will be maximum than this node will be good node) --1448
void slove(TreeNode*root, int &count, int maxi)
{
    if(root==NULL)
    return ;
    
    if(root->val>=maxi)
    {
        count++;
        maxi=root->val;
    }
    
    slove(root->left, count, maxi);
    slove(root->right, count, maxi);
}
int countgood(TreeNode*root)
{
    int count=0;
    slove(root, count, root->val);
    return count;
}

//smallest subtree with all the depest node ---865 
int height(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=height(root->left);
    int rh=height(root->right);
    
    return 1+max(lh, rh);
}
TreeNode*lowestcommon(TreeNode*root)
{
    if(root==NULL)
    return NULL;
    
    int lefth=height(root->left);
    int righth=height(root->right);
    
    if(lefth==righth)
    {
        return root;
    }
    if(lefth>righth)
    {
        return lowestcommon(root->left);
    }
    else 
    {
        return lowestcommon(root->right);
    }
    return root;
}

//lowest common ancestor of deepest leaves(both have same solution)  ----1123
int height(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=height(root->left);
    int rh=height(root->right);
    
    return 1+max(lh, rh);
}
TreeNode*lowestcommon(TreeNode*root)
{
    if(root==NULL)
    return NULL;
    
    int lefth=height(root->left);
    int righth=height(root->right);
    
    if(lefth==righth)
    {
        return root;
    }
    if(lefth>righth)
    {
        return lowestcommon(root->left);
    }
    else 
    {
        return lowestcommon(root->right);
    }
    return root;
}

//increasing order search tree brute force approach  ------- 897
void preorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
TreeNode*increasing(TreeNode*root)
{
    vector<int>ans;
    preorder(root, ans);
    sort(ans.begin(), ans.end());
    
    TreeNode*dummy=new TreeNode(0);
    TreeNode*tail=dummy;
    
    for(auto it : ans)
    {
        tail->right=new TreeNode(it);
        tail=tail->right;
    }
    return dummy->right;
}

//optimal approach 
TreeNode*slove(TreeNode*root, TreeNode*dummy)
{
    if(root==NULL)
    return NULL;
    
    slove(root->left, dummy);
    
    dummy->right=root->val;
    dummy=dummy->right;
    
    slove(root->right, dummy);
}
TreeNode*increasing(TreeNode*root)
{
    TreeNode*dummy=new TreeNode(0);
    TreeNode*tail=dummy;
    slove(root, dummy);
    return tail->right;
}
    
//lowest common ancestor of binary tree
int lowestcommonancestor(TreeNode*root, TreeNode*p, TreeNode*q)
{
    if(root==NULL)
    return 0;
    
    int lh=lowestcommonancestor(root);
    int rh=lowestcommonancestor(root);
    
    if(lh==NULL)
    {
        return rh;
    }
    else if(rh==NULL)
    {
        return lh;
    }
    else  
    {
        return root;
    }
}

//lowest common ancestor of binary search tree
int lowestcommonancestor(TreeNode*root, TreeNode*p, TreeNode*q)
{
    if(root==NULL)
    return 0;
    
    if(root->val<p->val && root->val<q->val)
    {
        return lowestcommonancestor(root->left, p, q);
    }
    else 
    {
        return lowestcommonancestor(root->right, p, q);
    }
    return root;
}


//--------------------------------------------------- 

//basic calculater-II
//time complexity is O(n)
//space complexity is O(1)
int calculate(string s) 
{
    int n= s.length();
    if (n== 0) 
    return 0;
    int currentNumber = 0;
    int lastNumber = 0;
    int ans= 0;
    char sign = '+';
    for (int i=0; i<n; i++) 
    {
        char currentChar = s[i];
        if (isdigit(currentChar)) 
        {
            currentNumber = (currentNumber * 10) + (currentChar - '0');
        }
        if (!isdigit(currentChar) && !iswspace(currentChar) || i==n- 1) 
        {
            if (sign == '+' || sign == '-') 
            {
                result += lastNumber;
                lastNumber = (sign == '+') ? currentNumber : -currentNumber;
            } 
            else if (sign == '*') 
            {
                lastNumber = lastNumber * currentNumber;
            } 
            else if (sign == '/') 
            {
                lastNumber = lastNumber / currentNumber;
            }
                
            sign = currentChar;
            currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;  
    }
}
