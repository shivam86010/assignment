//reverse array using inbuilt function 
//reverse array 
//reverse array pairwise 
//reverse array group size k 
//reverse integer 
//check array are palindrome or not 
//wave array 
//move negative element at the end of array using bruteforce approach 
//optimal approach 
//move zero at the end of array using bruteforce approach 
//optimal approach 
//arrange alternate sign element in array 
//parity sort 
//O 1 2 sort 
//dnf sort 
//three way partition of array 
//find the minimum element in array using bruteforce approach 
//optimal approach 
//find the maximum element in array using bruteforce approach 
//optimal approach
//second largest element in array bruteforce approach 
//optimal approach 
//second smallest element in array bruteforce approach 
//optimal approach 
//find the kthsmallest element in array 
//find the kthlargest element in array 
//Find the Kth Largest Integer in the Array
//third largest element in array 
//monotonic array (An array is monotonic if it is either monotone increasing or monotone decreasing.)
//find unique element in array bruteforce approach 
//optimal approach 
//Non Repeating Numbers (means more than one unique element in array )
//unique number of occurence 
//sum of unique element in array 
//find duplicate element in array using bruteforce approach 
//optimal approach 
//find all duplicate element in array using bruteforce approach 
//optimal approach 
//find the leader of array 
//find the equlibrium point  
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
//majority-II 
//remove duplicate element 
//second version  
//remove value from array 
//rotate array by one place  
//rotate array by d place bruteforce approach 
//optimal approach 
//squares of a sorted array bruteforce approach 
//optimal approach 
//product of itself bruteforce approach  
//better approach  
//optimal approach 
//two sum bruteforce approach 
//optimal approach 
//three sum bruteforce approach 
//optimal approach 
//four sum bruteforce approach 
//optimal approach 
//four-II sum bruteforce approach 
//optimal approach 
//maximum contigous subarray sum bruteforce approach 
//better approach
//optimal approach
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
//merge interval 
//insert interval 
//non overlaping interval (count how mant interval are delete to make non overlap)
//largest number  







//---------------------------------------------------------------------------------------------------------------
//linear search 
//binary search 
//order agnostic binary search 
//first occurence of target 
//last occurence of target 
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
    return ;

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
    return ;

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

//reverse linked list recursive method 
ListNode*reverseRec(ListNode*head)
{
    if(head==null || head->next==null)
    return head;

    ListNode*newhead=reverseRec(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

//reverse linked list iterative method 
ListNode*reverse(ListNode*head)
{
    if(head==null || head->next==null)
    return head;

    ListNode*curr=head;
    ListNode*pre=NULL;
    while(curr!=null)
    {
        listnode*nextn=curr->next;
        curr->next=pre;
        pre=curr;
        curr=curr->next;
    }
    return pre;
}

//reverse linked list in k group 
ListNode*reverse(ListNode*head, int k)
{
    if(head==null || head->next==null)
    return head;

    ListNode*curr=head;
    ListNode*pre=NULL;
    int count=0;
    while(curr!=null && count<k)
    {
        ListNode*nextn=curr->next;
        curr->next=pre;
        pre=curr;
        curr=curr->next;
        int count++;
    }

    if(nextn!=null)
    {
        head->next=reverse(nextn, k);
    }
    return pre;
}

//middle of linked list 
ListNode*middlenode(ListNode*head)
{
    if(head==NULL)
    return ;

    ListNode*slow=head;
    ListNode8fast=head;
    while(fast!=null && fast->next!=null)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

//2-method to find the middle element in list  
ListNode*middlenode(ListNode*head)
{
    if(head==NULL)
    return ;

    ListNode*slow=head;
    int count=0;
    while(slow!=null)
    {
        count++;
        slow=slow->next;
    }

    slow=head;
    int half=count/2;
    while(half--)
    {
        temp=temp->next;
    }
    return temp;
}

//cyclic in linked list  
bool loop(ListNode*head)
{
    if(head==NULL)
    return ;

    ListNode*slow=head;
    ListNode8fast=head;
    while(fast!=null && fast->next!=null)
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
ListNode*startingpoint(ListNode*head)
{
    if(head==NULL)
    return ;

    ListNode*slow=head;
    ListNode8fast=head;
    while(fast!=null && fast->next!=null)
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
    return slow;
}

//remove loop from linked list 
ListNode*deleteloop(ListNode*head)
{
    if(head==NULL)
    return ;

    ListNode*slow=head;
    ListNode8fast=head;
    while(fast!=null && fast->next!=null)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            break;
        }
    }

    if(slow==head || fast==head)
    {
        while(fast!=slow->next)
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
ListNode*removeduplivateRec(ListNode*head)
{
    if(head==NULL || head->next==null)
    return head;

    ListNode*newhead=removeduplivateRec(head->next);
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
ListNode*removeduplivateRec(ListNode*head)
{
    if(head==NULL || head->next==null)
    return head;

    ListNode*temp=head;
    while(temp!=null)
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
ListNode*removeduplivateRec(ListNode*head)
{
    if(head==NULL || head->next==null)
    return head;

    unordered_set<int>st;
    ListNode*temp=head;
    ListNode*pre=NULL;
    while(temp!=NULL)
    {
        if(st.find(temp->val)!=st.end())
        {
            pre->next=temp->next;
            delete temp;
        }
        else 
        {
            st.push(temp->val);
            pre=temp;
        }
        temp=temp->next;
    }
    return head;
}

//palindrome linked list 
bool palindrome(ListNode*head)
{
    if(head==NULL)
    return ;

    ListNode*slow=head;
    ListNode8fast=head;
    while(fast!=null && fast->next!=null)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    slow->next=reverse(slow->next);
    Listnode*first=head;
    listnode*second=slow->next;
    while(second!=null)
    {
        if(first->val!=second->val)
        {
            return false;
        }
        first=first->next;
        second=second->next;
    }

    slow->next=reverse(slow->next);
    return true;
}

//merge linked list 
ListNode*merge(ListNode*head1, ListNode*head1)
{
    if(head1==null)
    return head2;

    if(head2==null)
    return head1;

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
ListNode*merge(ListNode*head1, ListNode*head1)
{
    if(head1==null)
    return head2;

    if(head2==null)
    return head1;

    listnode*dummy=new listnode(0);
    listnode*tail=dummy;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->val<head2->val)
        {
            tail->next=head1;
            tail=tail=>next;
            head1=head1->next;
        }
        else 
        {
            tail->next=head2;
            tail=tail->next;
            head2=head2->next;
        }
    }

    while(head1!=null)
    {
        tail->next=head1;
    }
    while(head2!=null)
    {
        tail->next=head2;
    }
    return dummy->next;
}

//merge k linked list 
//second method to merge k linked list 
//intersection of linked list 
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

//second method to find intersection of linked list 
ListNode*intersection(ListNode*head1, ListNode*head2)
{
    int len1=lengthList(head1);
    int len2=lengthList(head2);

    ListNode*temp1=head1;
    ListNode*temp2=head2;

    if(len1>len2)
    {
        while(len1-len2)
        {
            temp1=temp1->next;
        }
    }
    if(len2>len1)
    {
        while(len2-len1)
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

//odd or even linked list 
ListNode*oddeven(ListNode*head)
{
    if(head==NULL)
    return ;

    ListNode*odd=head;
    ListNode*even=head;
    ListNode*oddh=head->next;
    ListNode*evenh=head->next;
    while(even!=NULL && even->next!=NULL)
    {
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenh;
    return oddh;
}

//second method  to find odd and even linked list 
ListNode*oddeven(ListNode*head)
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
                head=head->next;
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

//delete node where head or not given 
ListNode*deletenode(ListNode*del)
{
    ListNode*temp=del->next;
    del->val=temp->val;
    del->next=temp->next->next;
    delete temp;
}

//check two linked list are identical or not
bool identical(ListNode*head1, ListNode*head2)
{
    int len1=lengthList(head1);
    int len2=lengthList(head2);

    ListNode*temp1=head1;
    ListNode*temp2=head2;

    if(len1!=len2)
    {
        return false;
    }

    while(temp1!=temp2)
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

// Nth node from end of linked list 
//swap node pairwise 
//swap node kth from starting and kth from end in linked list 
//2-method 
//add two linked list 
ListNode*intersection(ListNode*head1, ListNode*head2)
{
    ListNode*dummy=new ListNode(0);
    ListNode*tail=head;
    int carry=0;
    while(head1!=NULL && head2!=NULL)
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
    return tail;
        
}

//second version 
ListNode*intersection(ListNode*head1, ListNode*head2)
{
    head1=reverse(head1);
    head2=reverse(head2);
     
    ListNode*dummy=new ListNode(0);
    ListNode*tail=dummy;
    int carry=0; 
    while(head1!=NULL && head2!=NULL)
    {
        int sum=carry;
        if(head1!=NULL)
        {
            sum+=head1->val;
            head1=head1->next;
        }
        if(head2!=NULL)
        {
            sum+=head2->val;
            head2=head2->next;
        }

        carry=sum/10;
        tail->next=new ListNode(sum%10);
        tail=tail->next;
    }
    return dummy->next;
}

//sort linked list 
ListNode*sortlist(ListNode*head)
{
    if(head==NULL)
    return ;

    ListNode*slow=head;
    ListNode*fast=head;
    ListNode*temp=NULL;
    while(fast->next!=null && fast->next->next!=null)
    {
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    temp->next=NULL;
    ListNode*start=sortlist(head);
    ListNode*second=sortlist(slow->next);
    return merge(start, second);

}

//rotate linked list 
ListNode*rotatelist(ListNode*head, int k)
{
    if(head==NULL || head->next==NULL)
    return head;

    ListNode*newhead=head;
    ListNode8tail=head;
    while(count<k)
    {
        
    }

}

//Partition linked List 
ListNode*partition(ListNode*head, int x)
{
    ListNode*largeh=new ListNode(0);
    ListNode*large=largeh;
    ListNode*smallh=new ListNode(0);
    ListNode*small=smallh;

    while(head!=NULL)
    {
        if(head->val<x)
        {
            small->next=head;
            small=small->next;
            head=had->next;
        }
        else 
        {
            large->next=head;
            large=large->next;
            head=head->next;
        }
    }
    large->next=NULL;
    small->next=largeh->next;
    return smallh->next;
}

//reorder linked list 
ListNode*reorder(ListNode*head)
{
    if(head==NULL)
    return ;

    ListNode*slow=head;
    ListNode*fast=head;
    ListNode*temp=NULL;
    while(fast!=null && fast->next!=null)
    {
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    temp->next=NULL;

    ListNode*first=head;
    ListNode*second=reverse(slow->next);
    while(second!=NULL)
    {
        ListNode*temp1=first->next;
        ListNode*temp2=second->next;
        temp1=second;
        second-
    }

}

//insertion sort in linked list 




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
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

//delete middle element in stack 
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
bool isvalid(string s)
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
            if(!st,empty())
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

//insert at bottom in stack 
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
void insertatbottom(stack<int>st, int ele)
{
    slove(st, ele);
}

//reverse stack 
void insertbottom(stack<int>st, int num)
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
void insertsorted(stack<int>st, int num)
{
    if(st.empty() && st.top()<num)
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
bool isreduant(string s)
{
    int n=s.length();
    stack<char>st;
    for(int i=0; i<n; i++)
    {
        char ch=s[i];
        if(ch=='(' || ch=='*' || ch=='/' || ch=='+' || ch=='-')
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
                    if(top=='*' || top=='/' || top=='+' || top=='-')
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
            mini=min(mini arr[j]);
        }
    }
    return false;
}

//optimal approach 
bool pattern132(int arr[], int n)
{
    int thirdele=0;
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
int nextsmaller(int arr[], int n)
{
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && st.top()>=arr[i])
        {
            st.pop();
        }

        ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}

//previous smaller element int array 
int previoussmaller(int arr[], int n)
{
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && st.top()>=arr[i])
        {
            st.pop();
        }

        ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}

//next greater element in array 
int nextgreater(int arr[], int n)
{
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }

        ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}

//previous greater element in array 
int previousgreater(int arr[], int n)
{
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }

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
bool ispoweroftwo(int n)
{
    return n>0 && (n&(n-1))==0;
}

//number is power of three or not 
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
bool ispoweroffour(int n)
{
    return n>0 && (n&(n-1))==0 && (n%3==1);
}

//kid with the greatest number of candies (given array of candies and int extracandies return bool of vector )
vector<bool>greatest(int arr[], int n, int extra)
{
    vector<bool>ans;
    int largest=arr[0];
    for(int i=0; i<n; i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
        }
    }

    for(int i=0; i<n; i++)
    {
        if(arr[i]+extra>=largest)
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
vector<int>prefixsum(int arr[], int n)
{
    vector<int>prefix;
    prefix[0]=arr[0];
    for(int i=0; i<n; i++)
    {
        prefix[i]=prefix[i-1]+arr[i];
    }
    return prefix;
}

//number of good pair 
int goodpair(int arr[], int n)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

//optimal approach
int goodpair2(int arr[], int n)
{
    int count=0;
    vector<int>mp(101,0);
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }

    for(int i=0; i<=100; i++)
    {
        count+=mp[i]+(mp[i]-1)/2;
    }
    return count;
} 

//two out of three (this means given three array find the common element in array atleast in  two array common ) 
int twooutofthree(int arr1[], int arr2[], int arr3[], itn n, int m, int p)
{
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>ans;
    for(int i=0; i<n; i++)
    v1[arr1[i]]++;

    for(int i=0; i<m; i++)
    v2[arr2[i]]++;

    for(int i=0; i<p; i++)
    v3[arr3[i]]++;

}

//daily Temperatures
int dailytemperatures(int arr[], int n)
{
    vector<int>ans(n, 0);
    stack<int>st;
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && arr[st.top]<=arr[i])
        {
            st.pop();
        }
        if(!st.empty())
        {
            ans[i]=st.top()-i;
        }
        st.push(i);
    }
    return ans;

}

//--------------------------------------------------------------- 
/*
//preoder traversal 
void preorder(ListNode*root)
{
    if(root==NULL)
    return ;

    print(root);
    preorder(root->left);
    preorder(rrot->right);
}

//inorder traversal 
void inorder(ListNode*root)
{
    if(root==NULL)
    return;

    inorder(root->left);
    print(root);
    inorder(root->right);
}

//postorder traversal 
void postorder(ListNode*root)
{
    if(root==NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    print(root);
}

//level order traversal 
vector<vecto<int>>levelorder(ListNode*root)
{
    vector<vector<int>>ans;
    if(root==NULL)
    return ans;

    queue<ListNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        for(int i=0; i<size; i++)
        {
            int top=q.front();
            q.pop();
            if(top->left!=NULL)
            {
                q.push(top->left);
            }
            if(top->right!=NULL)
            {
                q.push(root->right);
            }
            level.push_back(top);
        }
        ans.push_back(level);
    }
    return ans;
}

//iterative way of preorder traversal 
void preorder(ListNode*root)
{
    if(root==NULL)
    return ;

    stack<ListNode*>st;

}

//height or depth of tree 
int depthoftree(ListNode*root)
{
    if(root==NULL)
    return ;

    int left=depthoftree(root->left);
    int right=depthoftree(root->right);
    return 1+max(left right);
}

//
*/






#include<bits/stdc++.h>
using namespace std;
//find the kth smallest element in a sorted matrix bruteforce approach 
//time complexity is O(n^2logk)
//space complexity is O(k)
int kthsmallest(vector<vector<int>>mat, int k)
{
    int n=mat.size();
    int m=mat[0].size();
    priority_queue<int>q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            q.push(mat[i][j]);
            if(q.size()>k)
            {
                q.pop();
            }
        }
    }
    return q.top();
}

//optimal approach 
//time complexity is O(log(n*m))
//space complexity is O(1)
int kthsmallest(vector<vector<int>>mat, int k)
{
    int n=mat.size();
    int start=mat[0][0];
    int end=mat[n-1][n-1];
    while(start<end)
    {
        int mid=start+(end-start)/2;
        int count=0;
        for(int i=0; i<n; i++)
        {
            count+=upper_bound(mat[i].begin(), mat[i].end(), mid)-mat[i].begin();
        }
        if(count<k)
        {
            start=mid+1;
        }
        else 
        {
            end=mid;
        }
    }
    return start;
}

//Kth Smallest Number in Multiplication Table bruteforce approach 
//time complexity is O(m*nlog(m*n))
//space complexity is O(n*m) table space
int kthNumber(int m, int n, int k)
{
    vector<int>v;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            v.ans.push_back(i*j);
        }
    }
    
    sort(v.begin(), v.end());
    return v[k-1];
}

//better approach
//time complexity is O(m*nlog(m*n))
//space complexity is O(k) queue space  O(n*m) table space
int kthNumber(int m, int n, int k)
{
    vector<int>v;
    priority_queue<int>q;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            v.push_back(i*j);
        }
    }
    
    for(int i=0; i<v.size(); i++)
    {
        q.push(arr[i]);
        if(q.size()>k)
        {
            q.pop();
        }
    }
    return q.top();
}

//optimal approach 
//time complexity is O(m*log(m*n))
//space complexity is O(1)
int kthNumber(int m, int n, int k)
{
    int start=1;
    int end=m*n;
    int ans=0;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        int count=0;
        for(int i=1; i<=m; i++)
        {
            count+=min(mid/i, n);
        }
        if(count>=k)
        {
            ans=mid;
            end=mid-1;
        }
        else 
        {
            start=mid+1;
        }
    }
    return ans;
}

//Find the Kth Largest Integer in the Array
//time complexity is O(n*logk)
//space complexity is O(1)
class cmp 
{
    public :
    bool operator(string&a, string&b)
    {
        if(a.length()!=b.length())
        a.length()>b.length();
        
        return a>b;
    }
}
string kthlargestnumber(vector<string>num, int k)
{
    priority_queue<string, vector<string>,cmp>q;    //minheap
    for(auto it : num)
    {
        q.push(it);
        if(q.size()>k)
        {
            q.pop();
        }
    }
    return q.top();
}


//search in 2d matrix bruteforce approach 
//time complexity is O(n*m)
//space complexity is O(1)
bool searchinmatrix(vector<vector<int>>mat, int target)
{
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mat[i][j]==target)
            {
                return true;
            }
        }
    }
    return false;
}

//better approach 
//time complexity is O(n*(logm))
//space complexity is O(1)
bool binarysearch(vector<int>&num, int target)
{
    int n=num.size();
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
        {
            return true;
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
    return false;
}
bool searchinmatrix(vector<vector<int>>mat, int target)
{
    int n=mat.size();
    for(int i=0; i<n; i++)
    {
        bool flage=binarysearch(mat[i] ,target);
        if(flage)
        return true;
    }
    return false;
}

//optimal approach 
//time complexity is O(log(n*m))
//space complexity is O(1)
bool searchinmatrix(vector<vector<int>mat, int target)
{
    if(mat.size()==0)
    return false;
    
    int n=mat.size();
    int m=mat[0].size();
    int string=0;
    int end=n*m-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(mat[mid/m][mid%m]==target)
        {
            return true;
        }
        else if(mat[mid/m][mid%m]<target)
        {
            start=mid+1;
        }
        else 
        {
            end=mid-1;
        }
    }
    return false;
}

//second version 
//time complexity is O(n+m)
//space complexity is O(1)
bool searchinmatrixII(vector<vector<int>>mat, int target)
{
    int n=mat.size();
    int m=mat[0].size();
    int row=0;
    int col=m-1;
    while(row<n && col>=0)
    {
        if(mat[row][col]==target)
        {
            return true;
        }
        else if(mat[row][col]<target)
        {
            row++;
        }
        else 
        {
            col--;
        }
    }
    return false;
}




