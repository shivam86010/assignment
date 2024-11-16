#include<bits/stdc++.h>
using namespace std;
//--------------------------------------------------------------------------------
//print the node of linked list 
//time complexity is O(n)
//space complexity is O(1)
void printNode(ListNode*head)
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

//--------------------------------------------------------------------------------------
//find the length of linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*lengtList(ListNode*head)
{
    if(head==NULL)
    return -1;
    
    int count=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

//--------------------------------------------------------------------------------- 
//find the binary number of linked list 
//time complexity is O(n)
//space complexit is O(1)
int binaraynumber(ListNode*head)
{
    int ans=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        ans*=2;
        ans+=(temp->val);
        temp=temp->next;
    }
    return ans;
}

//--------------------------------------------------------------------------------------
//find the middle of linked list 
//time complexity is O(2n)
//space complexity is O(1)
ListNode*middleNode(ListNode*head)
{
    if(head==NULL && head->next==NULL)
    return head;
    
    int count=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    int half=count/2;
    temp=head;
    while(half--)
    {
        temp=temp->next;
    }
    return temp;
    
}

//optimal approach to find the middle node of linked ListNode
//time complexity is O(n)
//space complexity is O(1)
ListNode*middleNode(ListNode*head)
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


//---------------------------------------------------------------------------------------------
//cyclic in linked list or not 
//time complexity is O(n)
//space complexity is O(1)
bool cyclicList(ListNode*head)
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

//---------------------------------------------------------------------------------------------------
//starting point in cylic of linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*startingNode(ListNode*head)
{
    if(head==NULL)
    return head;
    
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        {
            break;
        }
    }
    ListNode*ptr1=slow;
    ListNode*ptr2=fast;
    while(ptr1!=ptr2)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return ptr1;
}


//---------------------------------------------------------------------------------------
//reverse linked list using recursive method 
//time complexity is O(n)
//space complexity is O(n) this is auxiliary stack space
ListNode*reverseRec(ListNode*head)
{
    if(head==NULL && head->next==NULL)
    return head;
    
    ListNode*newhead=reverseRec(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

//reverse linked list iterative way 
//time complexity is O(n)
//space complexity is O(1)
ListNode*reverseIter(ListNode*head)
{
    if(head==NULL && head->next==NULL)
    return head;
    
    ListNode*curr=head;
    ListNode*pre=-1;
    while(curr!=NULL)
    {
        ListNode*nextn=curr->next;
        curr->next=pre;
        pre=curr;
        curr=curr->next;
    }
    return pre;
}

//---------------------------------------------------------------------------------------------------
//reverse k group linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode* reverseKGroup(ListNode* head, int k)
{
    if(head==NULL)
    return NULL;
    
    ListNode*curr=head;
    ListNode*pre=NULL;
    ListNode*nextn=NULL;
    int count=0;
    while(curr!=NULL && count<k)
    {
        nextn=curr->next;
        curr->next=pre;
        pre=curr;
        curr=nextn;
        count++;
    }
    
    if(nextn!=NULL)
    {
        head->next=reverseKGroup(nextn, k);
    }
    return pre;
    
}


//--------------------------------------------------------------------------------------------
//intersection of linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*intersectionNode(ListNode*head1, ListNode*head2)
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

//second method to find the intersection of linked list 
//time complexity is O(n)
//space complexity is O(1)
ListNode*intersectionNode(ListNode*head1, ListNode*head2)
{
    int len1=lengtList(head1);
    int len2=lengtList(head2);
    ListNode*ptr1=head1;
    ListNode*ptr2=head2;
    if(len1>len2)
    {
        while(len1-len2)
        {
            ptr1=ptr1->next;
        }
    }
    if(len2>len1)
    {
        while(len2-len1)
        {
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=ptr2)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return ptr1;
}


//------------------------------------------------------------------------------------------------
//check linked list or palindrome or not 
//time complexity is    
bool checkpalindrome(ListNode*head)
{
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=reverseIter(slow->next);
    ListNode*start=head;
    ListNode*mid=slow->next;
    while(mid!=NULL)
    {
        if(start->val!=mid->val)
        {
            return false;
        }
        start=start->next;
        mid=mid->next;
    }
    slow->next=reverseIter(slow->next);
    return true; 
}

//--------------------------------------------------------------------------------------------------------
//merge linked list 
//time complexity is O(n+m)
//space complexity is O(1)
ListNode*merge(ListNode*head1, ListNode*head2)
{
    if(head1==NULL)
    return head2;
    
    if(head2==NULL)
    return head1;
    
    ListNode*dummy=new ListNode(-1);
    ListNode*tail=dummy;
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
    while(head1!=NULL)
    {
        tail->next=head1;
    }
    while(head2!=NULL)
    {
        tail->next=head2;
    }
    return dummy->next;
}

//merge linked list using recursive method 
//time complexity is O(n+m)
//space complexity is O(n+m) this is auxiliary stack space 
void mergelist(ListNode*head1, ListNode*head2)
{
    if(head1==NULL)
    return head2;
    
    if(head2==NULL)
    return head1;
    
    if(head1->val < head2->val)
    {
        head1->next=mergelist(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next=mergelist(head1, head2->next);
        return head2;
    }
}
ListNode*mergeListNode(ListNode*head1, ListNode*head2)
{
    return mergelist(head1, head2);
}


//----------------------------------------------------------------------------------------------------
//merge k linked list using merge two linked list and than agin merge with another linked list 
void mergeList(ListNode*head1, ListNode*head2)
{
    if(head1==NULL)
    return head2;
    
    if(head2==NULL)
    return head1;
    
    if(head1->val < head2->val)
    {
        head1->next=mergeList(head1->next, head2);
        return head1;
    }
    else{
        head2->next=mergeList(head1, head2->next);
        return head2;
    }
}
ListNode*mergeKList(vector<ListNode*>& lists)
{
    if(lists.size()==0)
    return NULL;
    
    if(lists.size()==1)
    return lists[0];
    
    ListNode*ans=mergeList(lists[0],lists[1]);
    for(int i=2; i<lists.size(); i++)
    {
        ans=mergeKList(lists[i], ans);
    }
    return ans;
}

//optimal approach to merge k linked list 
//time complexity is O(nlogk)
//space complexity is O(k)
class cmp
{
    public: 
    bool operator()(ListNode*a, ListNode*b)
    {
        return a->val > b->val;
    }
}
ListNode* mergeKLists(vector<ListNode*>& lists)
{
    priority_queue<ListNode* ,vector<ListNode*>, cmp>q;
    ListNode*dummy=new ListNode(-1);
    ListNode*tail=dummy;
    for(int i=0; i<lists.size(); i++)
    {
        if(lists[i]!=NULL)
        {
            q.push(lists[i]);
        }
    }
    while(q.size()==NULL)
    {
        ListNode*temp=q.top();
        tail->next=temp;
        tail=temp;
        q.pop();
        if(temp->next!=NULL)
        {
            q.push(temp->next);
        }
    }
    return dummy->next;
}

//---------------------------------------------------------------------------------------
//odd and even linked list in this method change the link of node 
//time complexity is O(n)
//space complexity is O(1)
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

//2-method odd even node  this separate the odd and even linked list than at the end add the both 
//time complexity is O(n)
//space complexity is O(1)
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

//------------------------------------------------------------------------------------------------------
//check the two list are identical or not 
//time complexity is O(n)
//space complexity is O(1)
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
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}

//---------------------------------------------------------------------------------------
//deletduplicate in the list using recursive way 
//time complexity is O(n)
//space complexity is O(1)
ListNode*deletduplicate(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    ListNode*newhead=deletduplicate(head->next);
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

//deletduplicate in the list using iterative way 
//time complexity is O(n)
//space complexity is O(1)

ListNode*removeduplicate(ListNode*head)  
{
    if(head==NULL && head->next==NULL)
    return head;
    
    ListNode*temp=head;
    while(temp->next!=NULL)
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

//---------------------------------------------------------------------------------------------------------
//remove loop from linked list 
//time complexity is O(n)
//space complexity is O(1)
void deleteLoop(ListNode*head)
{
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        break;
    }
    
    //this is exceptional case will be occure 
    if(slow==head || fast==head)
    {
        while(fast->next!=slow)
        {
            fast=fast->next;
        }
        fast->next=NULL;
    }
    
    //normal case will be occure 
    else if(slow==fast)
    {
        slow=head;
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
}

//-----------------------------------------------------------------------------------------------------------//
// Nth node from end of linked list 
//time complexity is O(n)
//space complexity is O(1)
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

//------------------------------------------------------------------------------------------------------------
// remove duplicate from unsorted linked list 
//time complexity is O(n)
//space complexity is O(n)

ListNode*removeduplicateun(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    unordered_set<int>st;
    ListNode*temp=head;
    ListNode*pre=NULL;
    while(temp!=NULL)
    {
        if(st.find(temp->data)!=st.end())
        {
            pre->next=temp->next;
            delete temp;
        }
        else
        {
            st.insert(temp->data);
            pre=temp;
        }    
        temp=pre->next;
    }
    return head;
}


//--------------------------------------------------------------------------------------------------------
//delete node from linked list without head only given delete node 
//time complexity is O(1)
//space complexity is O(1)
void deleteNode(ListNode *del)
{
    ListNode*temp=del->next;
    del->val=temp->val;
    del->next=temp->next;
    delete temp;
}


//sort linked list 0 1 2 
ListNode*sort012(ListNode*head)
{
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
        else if(temp->val==2)
        {
            count2++;
        }
        temp=temp->next;
    }
    
    temp=head;
    while(temp!=NULL)
    {
        if(count0!=0)
        {
            temp->val=0;
            count0--;
        }
        else if(count1!=0)
        {
            temp->val=1;
            count1--;
        }
        else if(count2!=0)
        {
            temp->val=2;
            count2--;
        }
        temp=temp->next;
    }
    return head;
}

//second method 
ListNode*sort012(ListNode*head)
{
    ListNode*zerohead=new ListNode(0);
    ListNode*zerotail=zerohead;
    ListNode*onehead=new ListNode(0);
    ListNode*onetail=onehead;
    ListNode*onehead=new ListNode(0);
    ListNode*twotail=twohead;
    
    ListNode*temp=head;
    while(temp!=NULL)
    {
        if(temp->val==0)
        {
            zerotail->next=temp;
            zerotail=zerotail->next;
        }
        else if(temp->val==1)
        {
            onetail->next=temp;
            onetail=onetail->next;
        }
        else if(temp->val==2)
        {
            twotail->next=temp;
            twotail=twotail->next;
        }
        temp=temp->next;
    }
    
    if(onehead->next!=NULL)
    {
        zerotail->next=onehead->next;
    }
    else
    {
        zerotail->next=twohead->next;
    }
    
    onetail->next=twohead->next;
    twotail->next=NULL;
    
    head=zerohead->next;
    delete(zerohead);
    delete(onehead);
    delete(twohead);
    return head;
}


//flattening of linked list 
//time complexity is O(n)
//space complexity is O(1)
Node* mergeTwoLists(Node* a, Node* b) 
{
    
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL) 
    {
        if(a->data < b->data) 
        {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else 
        {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    
    if(a!=NULL) 
    temp->bottom = a; 
    else 
    temp->bottom = b; 
    
    return res -> bottom; 
    
}
Node *flatten(Node *root)
{
   
    if (root == NULL || root->next == NULL) 
    return root; 
  
    root->next = flatten(root->next);
    root = mergeTwoLists(root, root->next); 
    return root; 
}
