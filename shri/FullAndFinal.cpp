#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


//find middle node of list (using find length method)
ListNode*findmiddleNode(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;

    ListNode*temp=head;
    int length=0;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }

    int half=length/2;
    temp=head;
    while(half--)
    {
        temp=temp->next;
    }
    return head;
}

//or slow and fast pointer method 
ListNode*middleNode(ListNode*head)
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


//------------------------------------------------------------------------------
//reverse the list (using stack data structure) 
ListNode*reverseStack(ListNode*head)
{
    if(head==NULL || head->next==NULL)
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
        st.pop();
        temp=temp->next;
    }
    return head;
}

//or using recursion method  
ListNode*reverseRec(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;

    ListNode*newhead=reverseRec(head->next);
    ListNode*first=head->next;
    first->next=head;
    head->next=NULL;
    return newhead;
}

//or using iterative method 
ListNode*reverseIter(ListNode*head)
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
        curr=nextn;
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
    return false;
}

//using slow and fast pointer 
bool isCycleFind(ListNode*head)
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
ListNode*startpointLoop(ListNode*head)
{
    if(head==NULL)
    return NULL;

    ListNode*temp=head;
    unordered_map<ListNode*,int>mp;
    while(temp!=NULL)
    {
        if(mp.find(temp)!=mp.end())
        {
            return temp;
        }

        mp[temp]=1;
        temp=temp->next;
    }
    return NULL;
}

//using slow and fast pointer 
ListNode*startpointLoop2(ListNode*head)
{
    if(head==NULL)
    return NULL;

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
int lengthofLoop(ListNode*head)
{
    if(head==NULL)
    return 0;

    int time=1;
    unordered_map<ListNode*,int>mp;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        if(mp.find(temp)!=mp.end())
        {
            int len=time-mp[temp];
            return len;
        }

        mp[temp]=time;
        time++;
        temp=temp->next;
    }
    return 0;
}
//using slow and fast pointer 
int findlength(ListNode*head1, ListNode*head2)
{
    int count=0;
    if(head1!=head2)
    {
        head1=head1->next;
        count++;
    }
    return count;
}
int findlenghtofloop(ListNode*head)
{
    if(head==NULL)
    return 0;

    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        {
            return findlength(slow, fast);
        }
    }
    return 0;
}

//------------------------------------------------------------------------------
//check palindrome of list (using stack -or- array data structure )

bool checkPalindrome(ListNode*head)
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
        if(temp->val!=st.top())
        {
            return false;
        }

        temp=temp->next;
        st.pop();
    }

    return true;
    
}
//or use reverse of middle half of list
bool isPalindromCheck(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return true;

    ListNode*slow=head;
    ListNode*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    ListNode*newhead=reverseRec(slow->next);

    ListNode*first=head;
    ListNode*second=newhead;
    while(second!=NULL)
    {
        if(first->val!=second->val)
        return false;

        first=first->next;
        second=second->next;
    }
    
    reverseRec(newhead);
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
    if(head==NULL || head->next==NULL)
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
        temp=temp->next;
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
ListNode*sort012optimal(ListNode*head)
{
    if(head== NULL || head->next==NULL)
    return head;

    ListNode*zerohead=new ListNode(-1);
    ListNode*zero=zerohead;
    ListNode*onehead=new ListNode(-1);
    ListNode*one=onehead;
    ListNode*twohead=new ListNode(-1);
    ListNode*two=twohead;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        if(temp->val==0)
        {
            zero->next=temp;
            temp=temp->next;
            zero=zero->next;
        }
        else if(temp->val==1)
        {
             one->next=temp;
             temp=temp->next;
             one=one->next;
        }
        else 
        {
            two->next=temp;
            temp=temp->next;
            two=two->next;
        }
    }

    zero->next=(onehead->next!=NULL) ? onehead->next : twohead->next;
    one->next=twohead->next;
    two->next=NULL;

    head=zerohead->next;

    delete (zerohead);
    delete (onehead);
    delete (twohead);
    return head;
}

//------------------------------------------------------------------------------
//delete middle node (using find length of list )
ListNode*deleteMiddle(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    {
        delete head;
        return NULL;
    }

    int length=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }

    int half=(length/2)-1;
    temp=head;
    while(half--)
    {
        temp=temp->next;
    }

    ListNode*del=temp->next;
    temp->next=temp->next->next;
    delete (del);

    return head;

}

//or using fast and slow pointer 
ListNode*delmiddleNode(ListNode*head)
{
    if(head==NULL ||  head->next==NULL)
    {
        delete head;
        return NULL;
    }

    ListNode*slow=head;
    ListNode*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
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
//remove Nth node from end (using find length of list )
//or use two pointer method first to n step and than both will run simultaneously

//------------------------------------------------------------------------------ 
//sort list (using array data structure) 
//using merge sort  

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

    int length1=findlength(head1);
    int length2=findlength(head2);

    ListNode*temp1=head1;
    ListNode*temp2=head2;
    if(length1<<length2)
    {
        int diff=length2-length1;
        while(diff--)
        {
            temp2=temp2->next;
        }
    }
    else 
    {
        int diff=length1-length2;
        while(diff--)
        {
            temp1=temp1->next;
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
ListNode*findintersection(ListNode*head1, ListNode*head2)
{
    if(head1==NULL || head2==NULL)
    return NULL;

    ListNode*temp1=head1;
    ListNode*temp2=head2;
    unordered_map<ListNode*, int>mp;
    while(temp1!=NULL)
    {
        mp[temp1]=1;
        temp1=temp1->next;
    }

    while(temp2!=NULL)
    {
        if(mp.find(temp2)!=mp.end())
        {
            return temp2;
        }
        temp2=temp2->next;
    }
    return NULL;
}

// or using two pointer method 
ListNode*intersectionoptimal(ListNode*head1, ListNode*head2)
{
    if(head1==NULL || head2==NULL)
    return NULL;

    ListNode*temp1=head1;
    ListNode*temp2=head2;
    while(temp1!=temp2)
    {
        if(temp1==NULL) 
        temp1=head2;
        else 
        temp1=temp1->next;

        if(temp2==NULL) 
        temp2=head2;
        else 
        temp2=temp2->next;
    }
    return temp1;
}

//------------------------------------------------------------------------------
//Add Two list (using stack data structure)
ListNode*AddTwoList(ListNode*head1, ListNode*head2)
{
    if(head1==NULL)
    return head2;

    if(head2==NULL)
    return head1;

    stack<int>st1, st2;
    ListNode*temp1=head1;
    ListNode*temp2=head2;
    while(temp1!=NULL)
    {
        st1.push(temp1->val);
        temp1=temp1->next;
    }

    while(temp2!=NULL)
    {
        st2.push(temp2->val);
        temp2=temp2->next;
    }

    ListNode*dummy=new ListNode(-1);
    ListNode*tail=dummy;
    int carry=0;
    while(!st1.empty() && !st2.empty())
    {
        int sum=carry;

        if(!st1.empty())
        {
            sum+=st1.top();
            st1.pop();
        }

        if(!st2.empty())
        {
            sum+=st2.top();
            st2.pop();
        }

        ListNode*newhead=new ListNode(sum%10);
        carry=sum/10;
        tail->next=newhead;
        tail=tail->next;
    }

    if(carry)
    tail->next=new ListNode(carry);

    return dummy->next;
}

//or using two pointer method 
ListNode*addtwolistoptimal(ListNode*head1, ListNode*head2)
{
    if(head1==NULL)
    return head2;

    if(head2==NULL)
    return head1;

    ListNode*temp1=head1;
    ListNode*temp2=head2;
    ListNode*dummy=new ListNode(-1);
    ListNode*tail=dummy;
    int carry=0;
    while(temp1!=NULL && temp2!=NULL)
    {
        int sum=carry;
        if(temp1!=NULL) sum+=temp1->val;
        if(temp2!=NULL) sum+=temp2->val;

        ListNode*newhead=new ListNode(sum%10);
        tail->next=newhead;
        carry=sum/10;
        tail=tail->next;

        if(temp1!=NULL) temp1=temp1->next;

        if(temp2!=NULL) temp2=temp2->next;
    }

    if(carry)
    tail->next=new ListNode(carry);

    return dummy->next;
}

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
ListNode*makearrtolist(vector<int>arr)
{
    ListNode*dummy=new ListNode(-1);
    ListNode*tail=dummy;

    for(int i=0; i<arr.size(); i++)
    {
        tail->next=new ListNode(arr[i]);
        tail=tail->child;
    }
    
    return dummy-child;
}
ListNode*flattening(ListNode*head)
{
    if(head==NULL ||head->next==NULL)
    return head;

    vector<int>arr;

    while(head!=NULL)
    {
        ListNode*temp=head;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->child;
        }
        head=head->next;
    }

    sort(arr.begin(), arr.end());

    return makearrtolist(arr);
}
//or using recursion 

//------------------------------------------------------------------------------
//reverse k group of list (using array or stack data structure) 
//or using recursion 
//or using iterative 

//------------------------------------------------------------------------------
// merge two sorted list (using array data structure)
ListNode*makeListFromArray(vector<int>&arr)
{
    ListNode*dummy=new ListNode(-1);
    ListNode*tail=dummy;

    for(int i=0; i<arr.size(); i++)
    {
        tail->next=new ListNode(arr[i]);
        tail=tail->next;
    }

    return dummy->next;
}
ListNode*mergeTwoSortedList(ListNode*head1, ListNode*head2)
{
    if(head1==NULL)
    return head2;

    if(head2==NULL)
    return head1;

    vector<int>arr;
    ListNode*temp1=head1;
    ListNode*temp2=head2;

    while(temp1!=NULL)
    {
        arr.push_back(temp1->val);
        temp1=temp1->next;
    }

    while(temp2!=NULL)
    {
        arr.push_back(temp2->val);
        temp2=temp2->next;
    }

    sort(arr.begin(), arr.end());

    return makeListFromArray(arr);
}
//or using recursion 
ListNode*mergeListRec(ListNode*head1, ListNode*head2)
{
    if(head1==NULL)
    return head2;

    if(head2==NULL)
    return head1;

    if(head1->val<head2->val)
    {
        head1->next=mergeListRec(head1->next, head2);
        return head1;
    }
    else 
    {
        head2->next=mergeListRec(head1, head2->next);
        return head2;
    }
}

//or using iterative 
ListNode*mergeListIterative(ListNode*head1, ListNode*head2)
{
    if(head1==NULL)
    return head2;

    if(head2==NULL)
    return head1;

    ListNode*dummy=new ListNode(-1);
    ListNode*tail=dummy;
    ListNode*temp1=head1;
    ListNode*temp2=head2;
    while(temp1!=NULL && temp2!= NULL)
    {
        if(temp1->val<temp2->val)
        {
            tail->next=temp1;
            temp1=temp1->next;
            tail=tail->next;
        }
        else 
        {
            tail->next=temp2;
            temp2=temp2->next;
            tail=tail->next;
        }
    }

    if(temp1!=NULL) 
    tail->next=temp1;

    if(temp2!=NULL)
    tail->next=temp2;

    return dummy->next;
}

//------------------------------------------------------------------------------
//merege k sorted list (using array data structure)
//using merge two list method 
//or using min heap data structure 

//------------------------------------------------------------------------------
//swap node in pairwise (using array data structure) 
void reversepairarr(vector<int>&arr)
{
    int n=arr.size();
    for(int i=0; i<n; i+=2)
    {
        if(i+1<n)
        {
            swap(arr[i], arr[i+1]);
        }
    }
}
ListNode*swappairwise(ListNode*head)
{
    if(head==NULL ||head->next==NULL)
    return head;

    vector<int>arr;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        arr.push_back(temp->val);
        temp=temp->next;
    }

    reversepairarr(arr);

    int index=0;
    temp=head;
    while(temp!=NULL)
    {
        temp->val=arr[index];
        index++;
        temp=temp->next;
    }
    return head;
}
//or using recursion 
ListNode*swappairwiseRec(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;

    ListNode*curr=head;
    ListNode*prev=NULL;
    int count=0;
    ListNode*nextn=NULL;
    while(curr!=NULL && count<2)
    {
        nextn=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextn;
        count++;
    }

    if(nextn!=NULL)
    {
        head->next=swappairwiseRec(head->next);
    }
    return prev;
}
// or use reverse function method 

//------------------------------------------------------------------------------
//Swapping Nodes in a Linked List kth from start or end (using array data structure) 
int findlengthoflist(ListNode*head)
{
    int length=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    return length;
}
ListNode*swapkthstart(ListNode*head, int k)
{
    if(head==NULL || k==0 || head->next==NULL)
    return head;

    int len=findlengthoflist(head);
    ListNode*temp1=head;
    ListNode*temp2=head;
    int len1=len-k;
    while(len--)
    {
        temp1=temp1->next;
    }

    while(len1--)
    {
        temp2=temp2->next;
    }

    swap(temp1->val , temp2->val);

    return head;
}
// or two pointer method 
ListNode*swapkthstartend(ListNode*head, int k)
{
    if(head==NULL || head->next==NULL || k==0)
    return head;

    vector<int>arr;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        arr.push_back(temp->val);
        temp=temp->next;
    }

    int n=arr.size();
    swap(arr[n-k], arr[k]);
    
    int index=0;
    temp=head;
    while(temp!=NULL)
    {
        temp->val=arr[index];
        index++;
        temp=temp->next;
    }
    return head;
}

//------------------------------------------------------------------------------