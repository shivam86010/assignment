
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



//reverse linked list in k group 
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

//middle of linked list 
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

//remove duplicate from sorted linked list using recursive method 
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

//remove duplicate from sorted linked list using iterative method 
//time complexity is O(n)
//space complexity is O(1)
ListNode*deletduplicate(ListNode*head)
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

//remove duplicate from unsorted linked list 
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

//palindrome linked list 
bool checkpalindrome(ListNode*head)
{
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast->next!=NULL && fast-.next->next!=NULL)
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

//check two linked list are identical or not 
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
            return true;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}


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

//swap node pairwise 
ListNode*swapPairs(ListNode* head)
{
    if(head==NULL)
    return NULL;
    
    ListNode*curr=head;
    ListNode*pre=NULL;
    ListNode*next=NULL;
    int count=0;
    while(count<2 &&curr!=0)
    {
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
        count++;
    }
    
    if(curr!=0)
    {
        head->next=swapPairs(next);
    }
    return pre;
}

//swap node kth from starting and kth from end in linked list 
ListNode*swapkth(ListNode*head, int k)
{
    ListNode*temp=head;
    ListNode*slow=head;
    ListNode*fast=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    
    int n=count-k;
    while(n--)
    {
        fast=fast->next;
    }
    
    while(k-1!=0)
    {
        slow=slow->next;
        k--;
    }
    swap(slow->val, fast->val);
    return head;
}

//2-method 
ListNode*swapkth(ListNode*head, int k)
{
    ListNode*fast=head;
    ListNode*slow=head;
    ListNode*kth=0;
    int count=1;
    while(count<k)
    {
        fast=fast->next;
        count++;
    }
    
    kth=fast;
    while(fast->next!=0)
    {
        fast=fast->next;
        slow=slow->next;
    }
    
    int temp=slow->val;
    slow->val=kth->val;
    kth->val=temp;
    return head;
}

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
ListNode* reverse(ListNode* &head)
{
    if(head==NULL  ||  head->next==NULL) 
    return head;
    
    ListNode* prev=NULL;
    ListNode* curr=head;

    while(curr != NULL)
    {
        ListNode* next= curr->next;
        curr->next= prev;
        prev= curr;
        curr=next;
    }
    return prev;
}
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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    l1=reverse(l1);
    l2=reverse(l2);
    ListNode* temp=add(l1, l2);
    return reverse(temp);
}

//sort linked list 
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
ListNode* sortList(ListNode* head) 
{
    if(head==0 || head->next==0)
    return head;
    
    ListNode*temp=0;
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=0)
    {
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    
    temp->next=0;
    ListNode*l1=sortList(head);
    ListNode*l2=sortList(slow);
    return mergelist(l1,l2);
}

//rotate linked list 
ListNode* rotateRight(ListNode* head, int k) 
{
    if(head==NULL) 
    return head;
    
    int len=1; 
    ListNode *newH=head;
    ListNode*tail=head;
    
    while(tail->next!=NULL)  
    {
        tail = tail->next;
        len++;
    }
    
    tail->next = head;

    k = k % len;
    
    for(auto i=0; i<len-k; i++) 
    tail = tail->next; 
    
    newH = tail->next; 
    tail->next = NULL;
    return newH;
}


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
ListNode*reverse(ListNode*head)
{
    ListNode*pre=0;
    ListNode*curr=head;
    ListNode*next=0;
    while(curr!=0)
    {
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
    }
    return pre;
}
void reorderList(ListNode* head) {
    //step 1 - middle of the list
    ListNode* slow=head;
    ListNode* fast=head->next;
    
    while(fast and fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    //step 2 - reverse the second half 
    ListNode*second=reverse(slow->next); 
    slow->next=NULL;
    ListNode* first=head; 
    
    //step 3 - merging the two list
    while(second)
    {
        ListNode* temp1=first->next;
        ListNode* temp2=second->next;
        first->next=second;
        second->next=temp1;
        first=temp1;
        second=temp2;
    }
}
    
//insertion sort in linked list
ListNode* insertionSortList(ListNode* head) 
{
    ListNode* dummy=new ListNode(10000);
    while(head!=NULL)
    {
        ListNode* next=head->next;
        ListNode* temp=dummy;
        
        while(temp->next && temp->next->val<head->val)
        {
            temp=temp->next;
        }
        head->next=temp->next;
        temp->next=head;
        head=next;
    }
    return dummy->next; 

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


//------------------------------------------------------------- 

//preorder traversal
//time complexity is O(n)
//space complexity is O(n)
void preorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

//iterative method of preorder traversal
//time complexity is O(n)
//space complexity is O(n)
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
        
        ans.push_back(root->val);
        
        if(root->right!=NULL)
        st.push(root->right);
        
        if(root->left!=NULL)
        st.push(root->left);
    }
    return ans;
}

//inorder traversal
//time complexity is O(n)
//space complexity is O(n)
void inorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

//iterative method to inorder traversal 
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
void postorder(TreeNode*root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    ans.push_back(root->val);
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}

//iterative method to postorder traversal 
//time complexity is O(n)
//space complexity is O(n)
vector<int>preorder(TreeNode*root)
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
    
    while(1st2.empty())
    {
        ans.push_back(st2.top());
        st2.pop();
    }
    return ans;
}

//maximum depth of binary tree 
//time complexity is O(n)
//space complexity is O(n)
int maximumdepth(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=maximumdepth(root->left);
    int rh=maximumdepth(root->right);
    
    return 1+max(lh, rh);
}

//check for balance binary tree 
//time complexity is O(n)
//space complexity is O(n)
int heigh(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=heigh(root->left);
    if(lh==-1)
    return -1;
    
    int rh=heigh(root->right);
    if(rh==-1)
    return -1;
    
    if(abs(lh-rh)>1)
    return -1;
    
    return 1+max(lh, rh);
}
bool balanceBT(TreeNode*root)
{
    return heigh(root)!=-1;
}

//diameter of binary tree
//time complexity is O(n)
//space complexity is O(n)
int heigh(TreeNode*root, int &maxi)
{
    if(root==NULL)
    return 0;
    
    int lh=heigh(root->left, maxi);
    int rh=heigh(root->right, maxi);
    
    maxi=max(maxi, lh+rh);
    
    return 1+max(lh, rh);
}
int diameter(TreeNode*root)
{
    int diam=0;
    heigh(root, diam);
    return diam;
}

//maximum path sum
//time complexity is O(n)
//space complexity is O(n)
int slove(TreeNode*root, int &maxi)
{
    if(root==NULL)
    return 0;
    
    int lh=max(0, slove(root->left, maxi));
    int rh=max(0, slove(root->right, maxi));
    
    maxi=max(maxi, root->val+lh+rh);
    
    return root->val+max(lh, rh);
}
int maximumpathsum(TreeNode*root)
{
    int maxi=0;
    slove(root, maxi);
    return maxi;
}

//check two tree is identical/same  or not
//time complexity is O(n)
//space complexity is O(n)
bool identical(TreeNode*root1, TreeNode*root2)
{
    if(root1==NULL && root2==NULL)
    return true;
    
    if(root1!=NULL && root2==NULL)
    return false;
    
    if(root==NULL && root2!=NULL)
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
    
    if(root==NULL && root2!=NULL)
    return false;
    
    return (root1->val==root2->val) && identical(root1->left, root2->right) && identical(root1->right, root2->left);
}
bool symmetric(TreeNode*root)
{
    return identical(root->left, root->right);
}


//level order traversal 
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
vector<vector<int>>zig-zag(TreeNode*root)
{
    vector<vector<int>>ans;
    if(root==NULL)
    return ans;
    
    int lefttoright=true;
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
        lefttoright=!=lefttoright;
        ans.push_back(level);
    }
    return ans;
}


//right side view of binary tree
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
int deepestsum(TreeNode*root)
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
//time complexity is O(n)
//space complexity is O(n)
vector<int>largestvalinrow(TreeNode*root)
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
//time complexity is O(n)
//space complexity is O(n)
TreeNode*bottomleft(TreeNode*root)
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
    return root->val;
}

//convert sorted array to binary search tree
//time complexity is O(n)
//space complexity is O(n)
TreeNode*makebinary(vector<int>&arr, int start, int end)
{
    if(start>end)
    return NULL;
    
    int mid=(start+end)/2;
    TreeNode*root=new TreeNode(arr[mid]);
    
    root->left=makebinary(arr, start, mid-1);
    root->right=makebinary(arr, mid+1, end);
    
    return root;
}
TreeNode*convertsortedarrtoBST(vector<int>num)
{
    return makebinary(num, 0, num.size()-1);
}

//convert sorted linked list to binary search tree 
//time complexity is O(n)
//space complexity is O(n)
TreeNode*makebinary(vector<int>&arr, int start, int end)
{
    if(start>end)
    return NULL;
    
    int mid=(start+end)/2;
    TreeNode*root=new TreeNode(arr[mid]);
    
    root->left=makebinary(arr, start, mid-1);
    root->right=makebinary(arr, mid+1, end);
    
    return root;
}
TreeNode*convertsortedlisttoBST(ListNode*head)
{
    vector<int>ans;
    while(head!=NULL)
    {
        ans.push_back(head->val);
        head=head->next;
    }
    
    return makebinary(ans, 0, ans.size()-1);
}

//second mathod 
//time complexity is O(n)
//space complexity is O(n)
TreeNode*convertsortedlisttoBST(ListNode*head)
{
    if(head==NULL)
    return NULL;
    
    if(head->next==NULL)
    return new TreeNode(head->val);
    
    auto slow=head;
    auto fast=head;
    auto pre=NULL;
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
//time complexity is O(n)
//space complexity is O(n)
TreeNode*makemaxitree(vector<int>&arr, int start, int end)
{
    if(start>end)
    return NULL;
    
    int maxi=INT_MIN;
    int maxindex=-1;
    for(int i=start; i<=end; i++)
    {
        if(arr[i]>maxi)
        {
            maxi=arr[i];
            maxindex=i;
        }
    }
    
    TreeNode*root=new TreeNode(maxi);
    
    root->left=makemaxitree(arr, start, maxindex-1);
    root->right=makemaxitree(arr, maxindex+1, end);
    
    return root;
}
TreeNode*maximumBT(vector<int>&arr)
{
    return makemaxitree(arr, 0, arr.size()-1);
}

//construct binary tree from preorder and inorder
//time complexity is O(n)
//space complexity is O(n)
TreeNode*maketree(vector<int>preorder, vector<int>inorder, int ps, int pe, int is,int ie, unordered_map<int,int>&mp)
{
    if(ps>pe || is>ie)
    return NULL;
    
    TreeNode*root=new TreeNode(preorder[ps]);
    int pos=mp[root];
    int left=pos-is;
    
    root->left=maketree(preorder, inorder, ps+1, ps+left, is, pos-1, mp);
    root->right=maketree(preorder, inorder, ps+left+1, pe, pos+1, ie, mp);
    
    return root;
}
TreeNode*constructBt(vector<int>preorder, vector<int>inorder)
{
    if(preorder.size()!=inorder.size())
    return NULL;
    
    unordered_map<int,int>mp;
    for(int i=0; i<inorder.size(); i++)
    mp[inorder[i]]=i;
    
    return maketree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1,mp);
}

//construct binary tree from inorder and postorder 
//time complexity is O(n)
//space complexity is O(n)
TreeNode*maketree(vector<int>postorder, vector<int>inorder, int ps, int pe, int is,int ie, unordered_map<int,int>&mp)
{
    if(ps>pe || is>ie)
    return NULL;
    
    TreeNode*root=new TreeNode(postorder[pe]);
    int pos=mp[root];
    int left=pos-is;
    
    root->left=maketree(postorder, inorder, ps, ps+left-1, is, pos-1, mp);
    root->right=maketree(postorder, inorder, ps+left, pe-1, ie, mp);
    
    return root;
}
TreeNode*constructBt(vector<int>postorder, vector<int>inorder)
{
    if(postorder.size()!=inorder.size())
    return NULL;
    
    unordered_map<int,int>mp;
    for(int i=0; i<inorder.size(); i++)
    mp[inorder[i]]=i;
    
    return maketree(preorder, inorder, 0, postorder.size()-1, 0, inorder.size()-1,mp);
}

//path sum 
//time complexity is O(n)
//space complexity is O(n)
bool pathsum(TreeNode*root, int targetsum)
{
    if(root==NULL)
    return true;
    
    if(root->left==NULL && root->right==NULL && targetsum-root->val==0)
    return true;
    
    return pathsum(root->left, targetsum-root->val) || pathsum(root->right, targetsum-root->val);
}

//path sum-II
//time complexity is O(n)
//space complexity is O(n)
vector<vector<int>>ans;
vector<int>path;
void slove(TreeNode*root, int sum, int targetsum)
{
    if(root==NULL)
    return ;
    
    sum+=root->val;
    path.push_back(root->val);
    if(sum==targetsum)
    {
        ans.push_back(path);
        return ;
    }
    
    slove(root->left, sum, targetsum);
    slove(root->right, sum, targetsum);
    path.pop_back();
}
vector<vector<int>pathsum-II(TreeNode*root, int targetsum)
{
    int sum=0;
    slove(root, sum, targetsum);
    return ans;
}

//binary tree path 
//time complexity is O(n)
//space complexity is O(n)
void slove(TreeNode*root, string temp, vector<string>&ans)
{
    if(root==NULL);
    return ;
    
    temp+=(to_string(root->val)+"->");
    if(root->left==NULL && root->right==NULL)
    {
        temp+=(to_string(root->val));
        ans.push_back(temp);
        return ;
    }
    
    if(root->left!=NULL)
    slove(root->left, temp, ans);
    
    if(root->right!=NULL)
    slove(root->right, temp, ans);
}
vector<string>binarytreePath(TreeNode*root)
{
    vector<string>ans;
    string s;
    slove(root, s, ans);
    return ans;
}

//sum root to leaf number (node 1->2->3==123 and so on )
//time complexity is O(n)
//space complexity is O(n)
void slove(TreeNode*root, int sum, int &ans)
{
    if(root==NULL);
    return ;
    
    sum=sum*10+root->val;
    if(root->left==NULL && root->right==NULL)
    {
        ans+=sum;
        return;
    }
    
    if(root->left!=NULL)
    slove(root->left, sum, ans);
    
    if(root->right!=NULL)
    slove(root->right, sum, ans);
}
int sumroottoleaf(TreeNode*root)
{
    int sum=0;
    int ans;
    slove(root, sum, ans);
    return ans;
}

//count complete tree node 
//time complexity is O(n)
//space complexity is O(n)
int countNodes(TreeNode*root)
{
    if(root==NULL)
    return 0;

    int lh=countNodes(root->left);
    int rh=countNodes(root->right);

    return 1+lh+rh;
}

//second method using level order traversal 
//time complexity is O(n)
//space complexity is O(n)
int countNodes(TreeNode*root)
{
    if(root==NULL)
    return 0;
     
    int count=0;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        
        count+=size;
        
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(node->right);
        }
    }
    return count;
}

//invert binary tree
//time complexity is O(n)
//space complexity is O(n)
TreeNode*invertBT(TreeNode*root)
{
    if(root=NULL)
    return NULL;
    
    invertBT(root->left);
    invertBT(root->right);
    
    swap(root->left, root->right);
    
    return rot;
}

//sum of left leaf node 
//time complexity is O(n)
//space complexity is O(n)
void slove(TreeNode*root, int &sum)
{
    if(root==NULL)
    return ;

    if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL)
    sum+=root->left->val;

    slove(root->left, sum);
    slove(root->right, sum);
}
int sumOfLeftLeaves(TreeNode* root) 
{
    int sum=0;
    slove(root, sum);
    return sum;
}
    
//merge two binary tree
//time complexity is O(n)
//space complexity is O(n)
TreeNode*merge(TreeNode*root1, TreeNode*root2)
{
    if(root1==NULL)
    return root2;
    
    if(root2==NULL)
    return root1;
    
    TreeNode*temp=new TreeNode(root1->val+root2->val);
    temp->left=merge(root1->left, root2->left);
    temp->right=merge(root2->right, root2->right);
    
    return temp;
}

//search in binary search tree recusive solution ---700
//time complexity is O(n)
//space complexity is O(n)
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

//iterative solution 
//time complexity is O(n)
//space complexity is O(n)
TreeNode*searchinBST2(TreeNode*root, int key)
{
    if(root==NULL)
    return NULL;
    
    while(true)
    {
        if(root->val==key)
        {
            return root;
        }
        else if(root->val>key)
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

//find the ceil in a binary search tree 
//time complexity is O(logn)
//space complexity is O(1)
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
        if(root->val>key)
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
//time complexity is O(logn)
//space complexity is O(1)
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
        if(root->val>key)
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
//time complexity is O(n)
//space complexity is O(n)
TreeNode*insertBST(TreeNode*root, int key)
{
    if(root==NULL)
    return new TreeNode(key);
    
    if(root->val>key)
    {
        return insertBST(root->left, key);
    }
    else 
    {
        return insertBST(root->right, key);
    }
    return root;
}

//iterative method 
//time complexity is O(n)
//space complexity is O(n)
TreeNode*insertBST(TreeNode*root, int key)
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
//time complexity is O(n)
//space complexity is O(n)
TreeNode*findrightchild(TreeNode*root)
{
    if(root==NULL)
    return root;
    
    return findrightchild(root->right);
}
TreeNode*helper(TreeNode*root)
{
    if(root->left==NULL)
    return root->right;
    
    if(root->right==NULL)
    return root->left;
    
    TreeNode*rightchild=root->right;
    TreeNode*lastrightchild=findrightchild(root->left);
    lastrightchild->right=rightchild;
    
    return root->left;
}
TreeNode*deleteBST(TreeNode*root, int key)
{
    if(root==NULL)
    return root;
    
    if(root->val==key)
    return helper(root);
    
    TreeNode*node=root;
    while(root!=NULL)
    {
        if(root->val>key)
        {
            if(root->left!=NULL && root->left->val==key)
            {
                root->left=helper(root->left);
                break;
            }
            else 
            {
                root=root->left;
            }
        }
        else 
        {
            if(root->right!=NULL && root->right->val==key)
            {
                root->right=helper(root->right);
                break;
            }
            else 
            {
                root=root->right;
            }
        }
    }
    return root;
}

//valid binary search tree --- 98
//time complexity is O(n)
//space complexity is O(n)
bool slove(TreeNode*root, int mini, int maxi)
{
    if(root==NULL)
    return true;
    
    if(root->val>=maxi && root->val<=mini)
    return false;
    
    return slove(root->left, mini, root->val) && slove(root->right, root->val, maxi);
}
bool validBST(TreeNode*root)
{
    return slove(root, LONG_MIN, LONG_MAX);
}

//recover binary search tree means (swaping two node with changing the structure ) --- 99
//kth smallest element in binary search tree  brute force approach  ---230 
//time complexity is O(nlogn)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
void inorder(TreeNode*root, int count, int &ans, int k)
{
    if(root==NULL)
    return ;
    
    inorder(root->left, count, ans, k);
    
    count++;
    if(count==k)
    {
        ans=root->val;
        return ;
    }
    
    inorder(root->right, count, ans, k);
}
int kthsmallest(TreeNode*root, int k)
{
    int ans;
    int count=0;
    inorder(root, count, ans, k);
    return ans;
}


//find the second minimum node in binary tree 
//time complexity is O(n)
//space complexity is O(n)
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
    vector<int>ans;
    preorder(root, ans);
    sort(ans.begin(), ans.end());
    int mini=ans[0];
    
    int sec=-1;
    for(int i=1; i<n; i++)
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
//time complexity is O(n)
//space complexity is O(n)
TreeNode*bsttogreater(TreeNode*root int sum=0)
{
    if(root==NULL)
    return NULL;
    
    bsttogreater(root->right, sum);
    
    sum+=root->val;
    root->val=sum;
    
    bsttogreater(root->left, sum);
    
    return root;
}

//trim binary search tree means(given a range when node node value not lie in range than simply delete) --- 669 
//time complexity is O(n)
//space complexity is O(n)
TreeNode*trimBST(TreeNode*root, int low, int high)
{
    if(root==NULL)
    return NULL;
    
    if(root->val>=low && root->val<=high)
    {
        root->left=trimBST(root->left, low, high);
        root->right=trimBST(root->right, low, high);
        return root;
    }
    if(root->val<=low)
    {
        return trimBST(root->right, low, high);
    }
    else if(root->val>=high)
    {
        return trimBST(root->left, low, high);
    }
    return root;
}

//count good node in binary tree (good means root to till node node value will be maximum than this node will be good node) --1448
//time complexity is O(n)
//space complexity is O(n)
void slove(TreeNode*root, int &count, int maxi)
{
    if(root==NULL)
    return ;
    
    if(root->val>=maxi)
    {
        count++;
        maxi=root->val;
    }
    
    if(root->left!=NULL)
    slove(root->left, count, maxi);
    
    if(root->right!=NULL)
    slove(root->right, count, ans);
}
int countgoodBT(TreeNode*root)
{
    int count=0;
    slove(root, count, root->val);
    return count;
}

//smallest subtree with all the depest node ---865 
//time complexity is O(n)
//space complexity is O(n)
int height(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=height(root->left);
    int rh=height(root->right);
    
    return 1+max(lh, rh);
}
TreeNode*smallestsubtree(TreeNode*root)
{
    if(root==NULL)
    return NULL;
    
    int lefth=height(root->left);
    int righth=height(root->right);
    
    if(lefth==righth)
    return root;
    
    if(lefth>righth)
    {
        return smallestsubtree(root->left);
    }
    else 
    {
        return smallestsubtree(root->right);
    }
    return root;
}

//lowest common ancestor of deepest leaves(both have same solution)  ----1123 
//time complexity is O(n)
//space complexity is O(n)
int height(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    int lh=height(root->left);
    int rh=height(root->right);
    
    return 1+max(lh, rh);
}
TreeNode*smallestsubtree(TreeNode*root)
{
    if(root==NULL)
    return NULL;
    
    int lefth=height(root->left);
    int righth=height(root->right);
    
    if(lefth==righth)
    return root;
    
    if(lefth>righth)
    {
        return smallestsubtree(root->left);
    }
    else 
    {
        return smallestsubtree(root->right);
    }
    return root;
}

//increasing order search tree brute force approach  ------- 897 
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
void slove(TreeNode*root, TreeNode*&dummy)
{
    if(root==NULL)
    return ;
    
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
//time complexity is O(n)
//space complexity is O(n)
int lowestcommonance(TreeNode*root, TreeNode*p, TreeNode*q)
{
    if(root==NULL || root==p || root==q)
    return root;
    
    int left=lowestcommonance(root->left, p, q);
    int right=lowestcommonance(root->right, p, q);
    
    if(left==NULL)
    {
        return right;
    }
    else if(right==NULL)
    {
        return left;
    }
    else 
    {
        return root;
    }
}

//lowest common ancestor of binary search tree
//time complexity is O(n)
//space complexity is O(n)
int lowestcommonance(TreeNode*root, TreeNode*p, TreeNode*q)
{
    if(root==NULL)
    return NULL;
    
    
    if(root->val<p->val && root->val<=q->val)
    {
        return lowestcommonance(root->right, p, q);
    }
    else 
    {
        return lowestcommonance(root->left, p, q);
    }
    return root;
}


//------------------------------------------------------------------------- 


//-------------------------------------------------------------------------------------------- 
//reverse string using stack
//time complexity is O(n)
//space complexity is O(n)
string reverse(string s)
{
    int n=s.length();
    stack<char>st;
    for(int i=0; i<n; i++)
    {
        st.push(s[i]);
    }
    
    string ans;
    while(st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

//delete middle element in stack 
//time complexity is O(n)
//space complexity is O(n)
void slove(stack<int>st, int count, int size)
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
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
void slove(stack<int>st, int num)
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
vector<int>insertatbottom(stack<int>st, int ele)
{
    slove(st, ele);
    return st;
}

//reverse stack 
//time complexity is O(n)
//space complexity is O(n)
void insertbottom(stack<int>st, int num)
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
//time complexity is O(n)
//space complexity is O(n)
void insertsorted(stack<int>st, int num)
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
//time complexity is O(n)
//space complexity is O(n)
bool redundant(string s)
{
    int n=s.length();
    stack<char>st;
    for(int i=0; i<n; i++)
    {
        char ch=s[i];
        if(ch=='(' || ch=='+' || ch=='*' || ch=='-' || ch=='/')
        {
            st.push(ch);
        }
        else 
        {
            if(ch==')')
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

//minimum cost to make valid string {
//time complexity is O(n)
//space complexity is O(n)
int minicost(string s)
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
    int ans=(b+1)/2+(a+1)/2;
    return ans;
}


//132 pattern bruteforce approach 
//time complexity is O(n^3)
//space complexity is O(1)
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
//time complexity is O(n^2)
//space complexity is O(1)
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
        }
        mini=min(mini, arr[j]);
    }
    return false;
}

//optimal approach
//time complexity is O(n)
//space complexity is O(n)
bool pattern132(int arr[], int n)
{
    stack<int>st;
    int thirdel=-1;
    for(int i=0; i<n; i++)
    {
        if(arr[i]<thirdel)
        {
            return true;
        }
        while(!st.empty() && st.top()<=arr[i])
        {
            thirdel=st.top();
            st.pop();
        }
        st.push(arr[i]);
    }
    return false;
}

//next smaller element in array
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
vector<int>previoussmaller(int arr[], int n)
{
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && st.top()>=arr[i])
        st.pop();
        
        ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}

//next greater element in array 
//time complexity is O(n)
//space complexity is O(n)
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
//time complexity is O(n)
//space complexity is O(n)
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

//next greater-I
//time complexity is O(n)
//space complexity is O(n)
vector<int>nextgreater(vector<int>num1, vector<int>num2)
{
    unordered_map<int,int>mp;
    stack<int>st;
    int n=num2.size();
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && st.top()<=num2[i])
        st.pop();
        
        int ans=(st.empty()) ? -1 : st.top();
        mp.insert({num2[i], ans});
        st.push(num2[i]);
    }
    
    vector<int>ans;
    for(auto it : num1)
    {
        ans.push_back(mp[it]);
    }
    return ans;
}

//next greater-II 
//time complexity is O(n)
//space complexity is O(n)
vector<int>nextgreater2(vector<int>num)
{
    vector<int>ans(n, -1);
    for(int i=2*n; i>=0; i--)
    {
        while(!st.empty() && st.top()<=num[i%n])
        st.pop();
        
        if(!st.empty() && (i<n))
        ans[i]=st.top();
        
        st.push(num[i%n]);
    }
    return ans;
}

//next greater-III 
//time complexity is O(n)
//space complexity is O(n)
int nextgreater3(int n)
{
    int x=n;
    string num=to_string(x);
    int i=num.size()-2;
    while(i>=0 && num[i]>=num[i+1])
    {
        i--;
    }
    
    if(i==-1)
    return -1;
    
    int j=num.size()-1;
    while(num[i]>=num[j])
    {
        j--;
    }
    
    swap(num[i], num[j]);
    reverse(num.begin()+i+1, num.end());
    
    long ans=stol(num);
    if(ans>INT_MAX)
    return -1;
    
    return ans;
}

//daily temperatures 
//time complexity is O(n)
//space complexity is O(n)
vector<int>temperatures(vector<int>&temp)
{
    vector<int>ans(n, 0);
    stack<int>st;
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && temp[st.top()]<=temp[i])
        st.pop();
        
        if(!st.empty())
        ans[i]=st.top()-i;
        
        st.push(i);
    }
    return ans;
}

//largest rectangle area in histogram 
//time complexity is O(n)
//space complexity is O(n)
int nextsmaller(int arr[], int n)
{
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
int presmallerele(int arr[], int n)
{
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}

int areaofrectangle(int height[], int n)
{
    vector<int>next(n)=nextsmaller(height, n);
    vector<int>pre(n)=presmallerele(height, n);
    
    int area=INT_MIN;
    for(int i=0; i<n; i++)
    {
        int length=height[i];
        if(next[i]==-1)
        {
            next[i]=n;
        }
        
        int breadth=next[i]-pre[i]-1;
        area=max(area, length*breadth);
    }
    return area;
}


//stock span problem //same as previous greater
//time complexity is O(n)
//space complexity is O(n)
vector<int>calculateSpan(int price[], int n)
{
    vector<int>ans;
    stack<int>st;
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && price[st.top()]<=price[i])
        {
            st.pop();
        }
        if(st.empty())
        ans.push_back(i+1);
        else
        ans.push_back(i-st.top());
        st.push(i);
    }
    return ans;
}

//online stock span problem 
//time complexity is O(n)
//space complexity is O(n)
stack<pair<int,int>>st;
int next(int price)
{
    int ans=1;
    while(!st.empty() && st.top().first<=price)
    {
        auto x=st.top();
        st.pop();
        
        int second=x.second;
        ans+=second;
    }
    st.push({price, ans});
    return ans;
}

//Evaluate Reverse Polish Notation
//time complexity is O(n)
//space complexity is O(n)
int evalRVPN(vector<string>&expr)
{
    stack<long long>st;
    for(int i=0; i<expr.size(); i++)
    {
        if(expr[i]=='*' || expr[i]=='+' || expr[i]=='-' || expr[i]=='/')
        {
            long long a=st.top();
            st.pop();
            
            long long b=st.top();
            st.pop();
            
            if(expr[i]=="+")
            {
                st.push(b+a);
            }
            else if(expr[i]=="-")
            {
                st.push(b-a);
            }
            else if(expr[i]=="*")
            {
                st.push(b*a);
            }
            else
            {
                st.push(b/a);
            }
        }
        else 
        {
            st.push(stoi(expr[i])); //this convert String to interge 
        }
    }
    return st.top();
}

//generate parentheses (given n)
//time complexity is O(n)
//space complexity is O(n)
void slove(int open, int close, int n, vector<String>&ans, String temp)
{
    if(open==n && close==n)
    {
        ans.push_back(temp);
        return ;
    }
    
    if(open<n)
    slove(open+1, close, n, ans, temp+'(');
    
    if(close<open)
    slove(open, close+1, n, ans, temp+')');
}
vector<String>generate(int n)
{
    vector<string>ans;
    string temp=" ";
    slove(0, 0, n, ans, temp);
    return ans;
}

//longest valid parentheses  )()())--->4
//time complexity is O(n)
//space complexity is O(n)
int longestvalid(string s)
{
    stack<char>st;
    int maxi=INT_MIN;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            st.push(i);
        }
        else 
        {
            if(st.empty())
            {
                st.push(i);
            }
            else 
            {
                maxi=max(maxi, i-st.top());
            }
            st.pop();
        }
    }
    return maxi;
}

//2 method
//time complexity is O(n)
//space complexity is O(1)
int longestvalid2(string s)
{
    int open=0;
    int close=0;
    int maxi=INT_MIN;
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
        if(open==close)
        {
            maxi=max(maxi, 2*close);
        }
        else if(close>=open)
        {
            open=0;
            close=0;
        }
    }
    
    open=0;
    close=0;
    for(int i=n-1; i>=0; i--)
    {
        if(s[i]=='(')
        {
            open++;
        }
        else 
        {
            close++;
        }
        if(open==close)
        {
            maxi=max(maxi, 2*open);
        }
        else if(open>=close)
        {
            open=0;
            close=0;
        }
    }
    return maxi;
}

//remove invalid parentheses  ()())()--->(())(), ()()()
//time complexity is O(n)
//space complexity is O(n)
unordered_map<string, int>mp;
vector<string>ans;
int getinvalid(string s)
{
    stack<char>st;
    int i=0;
    while(i<s.size())
    {
        if(s[i]=='(')
        {
            st.push('(');
        }
        else if(s[i]==')')
        {
            if(st.size()>0 && st.top()=='(')
            {
                st.pop();
            }
            else 
            {
                st.push(')')
            }
        }
        i++;
    }
    return st.size();
}
void slove(string s, int invalid)
{
    if(mp[s]!=0)
    {
        return ;
    }
    else 
    {
        mp[s]++;
    }
    
    if(invalid<0)
    return ;
    
    if(invalid==0)
    {
        if(!getinvalide(s))
        ans.push_back(s);
        return ;
    }
    
    for(int i=0; i<s.size(); i++)
    {
        string left=s.substr(0, i);
        string right=s.substr(i+1);
        slove(left+right, invalid-1);
    }
}
vector<string>invalidparn(string s)
{
    slove(s, getinvalide(s));
    return ans;
}

//remove k digit 
//time complexity is O(n^2)
//space complexity is O(n) 
//this is spacial case if k is not zero and element in stack than simply largest element will be delete 1,4,3,2,7,8 k=4
//Minimum Remove to Make Valid Parentheses   lee(t(co)d)e) 


//2-method 
//score of Parentheses  ()=1  (a)=2*a

//minimum number of swaps to make the string balanced 
//time complexity is O(n)
//space complexity is O(n)
int miniswap(string s)
{
    string<char>st;
    for(int i=0; i<s.size(); i++)
    {
        char ch=s[i];
        if(ch=='(')
        {
            st.push(ch);
        }
        else 
        {
            if(!st.empty() && st.top()=='(')
            {
                st.pop();
            }
            else 
            {
                st.push(ch);
            }
        }
    }
    
    int total=st.size();
    int close=total/2;
    return (close+1)/2;
}

//second method  
//time complexity is O(n)
//space complexity is O(n)
int miniswap(string s)
{
    int ans=0;
    int count=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='[')
        {
            count++;
        }
        else 
        {
            count--;
        }
        if(count<0)
        {
            ans++;
            count=1;
        }
    }
    return ans;
}

//minimum add to make Parentheses valid  ((( ==3  
//time complexity is O(n)
//space complexity is O(n)
int minAddToMakeValid(string s) 
{
    stack<char>st;
    for(int i=0; i<s.size(); i++)
    {
        if(ch=='(')
        {
            st.push(ch);
        }
        else 
        {
            if(st.empty() && st.top()==')')
            {
                st.push(ch);
            }
            else 
            {
                st.pop();
            }
        }
    }
    return st.size();
} 

//2-method 
//time complexity is O(n)
//space complexity is O(1)
int minAddToMakeValid(string s)
{
    int open=0;
    int close=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            open++;
        }
        else 
        {
            if(open>0)
            {
                open--;
            }
            else 
            {
                close++;
            }
        }
    }
    return (open+close);
}


//minimum insertions to balance a parentheses string ( one open ke crossponding 2 close will be add ) (()))) 
//time complexcity is O(n)
//space complexcity is O(1)
int miniinsertion(string s)
{
    int n=s.size();
    int count=0;
    int ans;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')  //open bracket will be arrive
        {
            count++;
        }
        else  //close will be arrive
        {
            if(i+1<n && s[i+1]==')') //this means ))
            {
                i++;
                if(count>0)
                {
                    count--;
                }
                else 
                {
                    ans++;
                }
            }
            else //directly closeing will be start 
            {
                if(count>0)
                {
                    count--;
                    ans++;
                }
                else  //this indicate phale open aa chuka hai 
                {
                    ans+=2;
                }
            }
        }
    }
    ans+=(2*count);
    return ans;
}

//basic calculater 
//time complexity is O(n)
//space complexity is O(n)
int calculater(string s)
{
    int sum=0;
    int sign=1;
    stack<int>st;
    for(int i=0; i<n; i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            int num=0;
            while(i<n && s[i]>='0' && s[i]<='9')
            {
                num=num*10+(s[i]-'0');
                i++;
            }
            sum+=num*sign;
            i--;
        }
        else if(s[i]=='+')
        {
            sign=1;
        }
        else if(s[i]=='-')
        {
            sign=-1;
        }
        else if(s[i]=='(')
        {
            st.push(sum);
            st.push(sign);
            sum=0;
            sign=1;
        }
        else if(s[i]==')')
        {
            sum=st.top()*sum;
            st.top();
            sum+=st.top();
            st.pop();
        }
    }
    return sum;
}

//calculater -II 
//time complexity is O(n)
//space complexity is O(n)
int calculater-II(string s)
{
    int n=s.size();
    if(n==0)
    return 0;
    
    stack<int>st;
    int currentnum=0;
    char operation='+';
    for(int i=0; i<n; i++)
    {
        char currentchar=s[i];
        if(isdigit(currentchar))
        {
            currentnum=(currentnum*10)+(currentnum-'0');
        }
        if(!isdigit(currentchar) && !iswspace(currentchar) || i==n-1)
        {
            if(operation=='-')
            {
                st.push(-currentnum);
            }
            else if(operation=='+')
            {
                st.push(currentnum);
            }
            else if(operation=='*')
            {
                int top=st.top();
                st.pop();
                
                st.push(top*currentnum);
            }
            else if(operation=='/')
            {
                int top=st.top();
                st.pop();
                
                st.push(top/currentnum);
            }
        }
        operation=currentchar;
        currentnum=0;
    }
    
    int ans=0;
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    return ans;
}

//simplify path 
//time complexity is O(n)
//space complexity is O(n)
string simplifyPath(string path)
{
    stack<string>st;
    string ans;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='/')
        continue;
        
        string temp;
        while(i<s.size() && s[i]!='/')
        {
            temp+=s[i];
            i++;
        }
        
        if(temp==".")
        continue;
        else if(temp=="..")
        {
            if(!st.empty())
            {
                st.pop();
            }
        }
        else 
        {
            st.push(temp);
        }
    }
    
    while(!st.empty())
    {
        ans="/"+st.top()+ans;
        st.pop();
    }
    
    if(ans.size()==0)
    return '/';
    
    return ans;
}

//--------------------------------------------------- 



//Longest Subarray with given Sum K(Positives)
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        for (int j = i; j < n; j++) { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            long long s = 0;
            for (int K = i; K <= j; K++) {
                s += a[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        long long s = 0; // Sum variable
        for (int j = i; j < n; j++) { // ending index
            // add the current element to
            // the subarray a[i...j-1]:
            s += a[j];

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}

//Longest Subarray with sum K | [Postives and Negatives]
int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        for (int j = i; j < n; j++) { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            int s = 0;
            for (int K = i; K <= j; K++) {
                s += a[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}
int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        int s = 0;
        for (int j = i; j < n; j++) { // ending index
            // add the current element to
            // the subarray a[i...j-1]:
            s += a[j];

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}
int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}






//Merge two Sorted Arrays Without Extra Space
void merge(long long arr1[], long long arr2[], int n, int m) {

    //Declare a 3rd array and 2 pointers:
    long long arr3[n + m];
    int left = 0;
    int right = 0;

    int index = 0;

    //Insert the elements from the 2 arrays
    // into the 3rd array using left and right
    // pointers:

    while (left < n && right < m) {
        if (arr1[left] <= arr2[right]) {
            arr3[index] = arr1[left];
            left++, index++;
        }
        else {
            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    // If right pointer reaches the end:
    while (left < n) {
        arr3[index++] = arr1[left++];
    }

    // If left pointer reaches the end:
    while (right < m) {
        arr3[index++] = arr2[right++];
    }

    // Fill back the elements from arr3[]
    // to arr1[] and arr2[]:
    for (int i = 0; i < n + m; i++) {
        if (i < n) arr1[i] = arr3[i];
        else arr2[i - n] = arr3[i];
    }
}
void merge(long long arr1[], long long arr2[], int n, int m) {

    //Declare 2 pointers:
    int left = n - 1;
    int right = 0;

    //Swap the elements until arr1[left] is
    // smaller than arr2[right]:
    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else {
            break;
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}
void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(long long arr1[], long long arr2[], int n, int m) {
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}








//pascal triangle 
//version 1
int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

//version 2
int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void pascalTriangle(int n) {
    // printing the entire row n:
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "n";
}

void pascalTriangle(int n) {
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

//version 3 
vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}


int getSingleElement(vector<int> &arr) {
    // Size of the array:
    int n = arr.size();

    //Run a loop for selecting elements:
    for (int i = 0; i < n; i++) {
        int num = arr[i]; // selected element
        int cnt = 0;

        //find the occurrence using linear search:
        for (int j = 0; j < n; j++) {
            if (arr[j] == num)
                cnt++;
        }

        // if the occurrence is 1 return ans:
        if (cnt == 1) return num;
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}



//-------------------------------------------------- 







//Starting point of loop in a Linked List
Node* detectLoop(Node* head) {


    Node* temp = head;


    unordered_map<Node*, int> mp;
 
 
    while(temp!=NULL){
        // check if temp has been encountered again
        if(mp.count(temp)!=0){
            // A loop is detected hence return temp
            return temp;
        }
        // store temp as visited
        mp[temp] = 1;
        // iterate through the list
        temp = temp->next;
    }

    // If no loop is detected, return nullptr
    return nullptr; 
}
Node* firstNode(Node* head) {


    Node* slow = head;  
    Node* fast = head;  
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;        
        fast = fast->next->next;  
        
        if (slow == fast) 
        {
            slow = head; 
            while (slow != fast)
            {
                slow = slow->next;  
                fast = fast->next;  
            }
            return slow;  
        }
    }
    return NULL; 
}

//Detect a Cycle in a Linked List

bool detectLoop(Node* head) {
    
    // Initialize a pointer 'temp'
    // at the head of the linked list
    Node* temp = head;  
    
    // Create a map to keep track of
    // encountered nodes
    std::unordered_map<Node*, int> nodeMap;  

    // Step 2: Traverse the linked list
    while (temp != nullptr) {
        // If the node is already in the
        // map, there is a loop
        if (nodeMap.find(temp) != nodeMap.end()) {
            return true;
        }
        // Store the current node
        // in the map
        nodeMap[temp] = 1;
        
        // Move to the next node
        temp = temp->next;  
    }

    // Step 3: If the list is successfully traversed 
    // without a loop, return false
    return false;
}










 

//flatten linked list 
Node* mergeTwoLists(Node* a, Node* b) {
    
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    
    if(a) temp->bottom = a; 
    else temp->bottom = b; 
    
    return res -> bottom; 
    
}
Node *flatten(Node *root)
{
   
        if (root == NULL || root->next == NULL) 
            return root; 
  
        // recur for list on right 
        root->next = flatten(root->next); 
  
        // now merge 
        root = mergeTwoLists(root, root->next); 
  
        // return the root 
        // it will be in turn merged with its left 
        return root; 
}

//rotate linked list 
node* rotateRight(node* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    for(int i=0;i<k;i++) {
        node* temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}
node* rotateRight(node* head,int k) {
    if(head == NULL||head->next == NULL||k == 0) return head;
    //calculating length
    node* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        ++length;
        temp = temp->next;
    }
    //link last node to first node
    temp->next = head;
    k = k%length; //when k is more than length of list
    int end = length-k; //to get end of the list
    while(end--) temp = temp->next;
    //breaking last node link and pointing to NULL
    head = temp->next;
    temp->next = NULL;
        
    return head;
}

Node* getKthNode(Node* temp, int k){
    // Decrement K as we already
    // start from the 1st node
    k -= 1; 

    // Decrement K until it reaches
    // the desired position
    while(temp != NULL && k > 0){
        // Decrement k as temp progresses
        k--; 
        
        // Move to the next node
        temp = temp -> next; 
    }
    
    // Return the Kth node
    return temp; 
}

// Function to reverse nodes in groups of K
Node* kReverse(Node* head, int k){
    // Initialize a temporary
    // node to traverse the list
    Node* temp = head; 

    // Initialize a pointer to track the
    // ;ast node of the previous group
    Node* prevLast = NULL; 
    
    // Traverse through the linked list
    while(temp != NULL){
        // Get the Kth node of the current group
        Node* kThNode = getKthNode(temp, k); 

        // If the Kth node is NULL
        // (not a complete group)
        if(kThNode == NULL){
            // If there was a previous group,
            // link the last node to the current node
            if(prevLast){
                prevLast -> next = temp; 
            }
            
            // Exit the loop
            break; 
        }
        
        // Store the next node
        // after the Kth node
        Node* nextNode = kThNode -> next; 

        // Disconnect the Kth node
        // to prepare for reversal
        kThNode -> next = NULL; 

        // Reverse the nodes from
        // temp to the Kth node
        reverseLinkedList(temp); 
        
        // Adjust the head if the reversal
        // starts from the head
        if(temp == head){
            head = kThNode;
        }else{
            // Link the last node of the previous
            // group to the reversed group
            prevLast -> next = kThNode; 
        }

        // Update the pointer to the
        // last node of the previous group
        prevLast = temp; 

        // Move to the next group
        temp = nextNode; 
    }
    
    // Return the head of the
    // modified linked list
    return head; 
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
    }
};


node* intersectionPresent(node* head1,node* head2) {
    while(head2 != NULL) {
        node* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;
}
node* intersectionPresent(node* head1,node* head2) {
     unordered_set<node*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;

}
node* intersectionPresent(node* head1,node* head2) {
    node* d1 = head1;
    node* d2 = head2;
    
    while(d1 != d2) {
        d1 = d1 == NULL? head2:d1->next;
        d2 = d2 == NULL? head1:d2->next;
    }
    
    return d1;
}

Node* DeleteNthNodefromEnd(Node* head, int N) {
    if (head == NULL) {
        return NULL;
    }
    int cnt = 0;
    Node* temp = head;

    // Count the number of nodes in the linked list
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    // If N equals the total number of
    // nodes, delete the head
    if (cnt == N) {
        Node* newhead = head->next;
        delete (head);
        return newhead;
    }

    // Calculate the position of the node to delete (res)
    int res = cnt - N;
    temp = head;

    // Traverse to the node just before the one to delete
    while (temp != NULL) {
        res--;
        if (res == 0) {
            break;
        }
        temp = temp->next;
    }

    // Delete the Nth node from the end
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
}

Node* DeleteNthNodefromEnd(Node* head, int N) {
    // Create two pointers, fastp and slowp
    Node* fastp = head;
    Node* slowp = head;

    // Move the fastp pointer N nodes ahead
    for (int i = 0; i < N; i++)
        fastp = fastp->next;

    // If fastp becomes NULL,
    // the Nth node from the end is the head
    if (fastp == NULL)
        return head->next;

    // Move both pointers until fastp reaches the end
    while (fastp->next != NULL) {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    // Delete the Nth node from the end
    Node* delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
}

bool isPalindrome(Node* head) {
    // Create an empty stack
    // to store values
    stack<int> st;

    // Initialize a temporary pointer
    // to the head of the linked list
    Node* temp = head;

    // Traverse the linked list and
    // push values onto the stack
    while (temp != NULL) {
        
        // Push the data from the
        // current node onto the stack
        st.push(temp->data); 
        
         // Move to the next node
        temp = temp->next;  
    }

    // Reset the temporary pointer back
    // to the head of the linked list
    temp = head;

    // Compare values by popping from the stack
    // and checking against linked list nodes
    while (temp != NULL) {
        if (temp->data != st.top()) {
            
            // If values don't match,
            // it's not a palindrome
            return false; 
        }
        
        // Pop the value from the stack
        st.pop();         
        
        // Move to the next node
        // in the linked list
        temp = temp->next; 
    }

     // If all values match,
     // it's a palindrome
    return true;
}
bool isPalindrome(Node* head) {
    // Check if the linked list is empty
    // or has only one node
    if (head == NULL || head->next == NULL) {
        
         // It's a palindrome by definition
        return true; 
    }
    
    // Initialize two pointers, slow and fast,
    // to find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    
    // Traverse the linked list to find the
    // middle using slow and fast pointers
    while (fast->next != NULL && fast->next->next != NULL) {
        
        // Move slow pointer one step at a time
        slow = slow->next;  
        
        // Move fast pointer two steps at a time
        fast = fast->next->next;  
    }
    
    // Reverse the second half of the
    // linked list starting from the middle
    Node* newHead = reverseLinkedList(slow->next);
    
    // Pointer to the first half
    Node* first = head;  
    
     // Pointer to the reversed second half
    Node* second = newHead; 
    while (second != NULL) {
        
        // Compare data values of 
        // nodes from both halves
        
        // If values do not match,
        // the list is not a palindrome
        if (first->data != second->data) {
            
            // Reverse the second half 
            // back to its original state
            reverseLinkedList(newHead);  
            
            // Not a palindrome
            return false;
        }
        
         // Move the first pointer
        first = first->next; 
        
        // Move the second pointer
        second = second->next;  
    }
    
    // Reverse the second half
    // back to its original state
    reverseLinkedList(newHead);  
    
    // The linked list is a palindrome
    return true;  
}
//-------------------------------------------------------------- 





//Count Number of Nodes in a Binary Tree
void inorder(TreeNode* root, int &count) 
{
    if (root == NULL) 
    return;

    count++;

    inorder(root->left, count);

    inorder(root->right, count);
}
int countNodes(TreeNode* root)
{
    if (root == NULL) 
    return 0;

    int count = 0;
    inorder(root, count);
    return count;
}

int findHeightLeft(TreeNode* node) 
{
    int height = 0;
    while (node)
    {
        height++;
        node = node->left;
    }
    return height;
}
int findHeightRight(TreeNode* node) 
{
    int height = 0;
    while (node) 
    {
        height++;
        node = node->right;
    }
    return height;
}
int countNodes(TreeNode* root) 
{
    if (root == NULL) 
    return 0;

    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    if (lh == rh) 
    {
        // binary tree ie. 2^h - 1
        return (1 << lh) - 1; 
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}




// children's sum .
void changeTree(TreeNode* root) 
{
    if (root == NULL) 
    return;

    int child = 0;
    if (root->left) 
    {
        child += root->left->val;
    }
    if (root->right) 
    {
        child += root->right->val;
    }

    if (child >= root->val)
    {
        root->val = child;
    } 
    else 
    {
        // If the sum is smaller, update the child with the current node's value.
        if(root->left) 
        {
            root->left->val = root->val;
        } 
        else if (root->right) 
        {
            root->right->val = root->val;
        }
    }

    changeTree(root->left);
    changeTree(root->right);


    int tot = 0;
    if (root->left) 
    {
        tot += root->left->val;
    }
    if (root->right) 
    {
        tot += root->right->val;
    }

    if (root->left || root->right) 
    {
        root->val = tot;
    }
}

//Maximum Width of a Binary Tree

int widthOfBinaryTree(TreeNode* root) 
{
    if (root==NULL) 
    return 0;

    int ans = 0;

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) 
    {
        int size = q.size();
        int mmin = q.front().second;
        
        // Store the first and last positions of nodes in the current level
        int first, last;
        
        for (int i = 0; i < size; i++) 
        {
            int cur_id = q.front().second - mmin;
            TreeNode* node = q.front().first;
            q.pop();
            
            if (i == 0) 
            first = cur_id;
            
            if (i == size - 1) 
            last = cur_id;
            
            if (node->left) 
            q.push({node->left, cur_id * 2 + 1});
            
            if (node->right) 
            q.push({node->right, cur_id * 2 + 2});
            
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}



//Print Root to Node Path in a Binary Tree    
bool getPath(TreeNode* root, vector<int>& arr, int x) 
{
    if(root==NULL)
    return false;
  
    arr.push_back(root->val);
    
    if (root->val == x) 
    return true;
  
    if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) 
    return true;

    arr.pop_back();
    return false;
}
vector<int> solve(TreeNode*root, int B) 
{
    vector<int> arr;

    if (root== NULL) 
    return arr;

    getPath(root, arr, B);

    return arr;
}



