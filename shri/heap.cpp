
#include<bits/stdc++.h>
using namespace std;
class stack 
{
    public : 
    int *arr;
    int size;
    int top;
    
    stack(int size)
    {
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    
    void push(int val)
    {
        if(size-top>1)
        {
            top++;
            arr[top]=val;
        }
        else 
        {
            cout<<"stack overflow"<<endl;
        }
    }
    
    void pop()
    {
        if(top>=0)
        {
            top--;
        }
        else 
        {
            cout<<"stack underflow"<<endl;
        }
    }
    
    int peak()
    {
        if(top<size && top>=0)
        return arr[top];
        else 
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    
    bool isempty()
    {
        if(top==-1)
        return true;
        else 
        return false;
    }
};


//two stack into a single array 
class twostack 
{
    public : 
    int *arr;
    int size;
    int top1;
    int top2;
    
    twostack(int s)
    {
        this->size=s;
        arr=new int[s];
        top1=-1;
        top2=s;
    }
    
    //push into stack 1
    void push1(int num)
    {
        if(top2-top1>1)
        {
            top1++;
            arr[top1]=num;
        }
    }
    
    //push into stack 2
    void push2(int num)
    {
        if(top2-top1>1)
        {
            top2--;
            arr[top2]=num;
        }
    }
    
    //pop from stack 1
    int pop1()
    {
        if(top1>=0)
        {
            int ans=arr[top1];
            top1--;
            return ans;
        }
        else 
        {
            return -1;
        }
    }
    
    //pop from stack 2
    int pop2()
    {
        if(top2<size)
        {
            int ans=arr[top2];
            top2++;
            return ans;
        }
        else 
        {
            return -1;
        }
    }
    
};

//stack implement using linked list 
class Node
{
    public :
    int data;
    Node*next;
    
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

class stack 
{
    Node*top;
    int size;
    
    public :
    stack()
    {
        top=NULL;
        size=0;
    }
    
    void push(int val)
    {
        Node*temp=new Node(val);
        if(temp==NULL)
        {
            cout<"stack is overflow"<<endl;
            return ;
        }
        temp->next=top;
        top=temp;
        size++;
    }
    
    void pop()
    {
        if(top==NULL)
        {
            cout<"stack is overflow"<<endl;
            return ;
        }
        else 
        {
            Node*temp=top;
            top=top->next;
            delete temp;
            size--;
        }
    }
    
    int peak()
    {
        if(top==NULL)
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        else 
        {
            return top->data;
        }
    }
    
    bool isempty()
    {
        return top==NULL;
    }
    
    int sizeofstack()
    {
        return size;
    }
};


//reverse string using stack 
string  reverse(string s)
{
    int n=s.length();
    stack<char>st;
    for(int i=0; i<n; i++)
    {
        st.push(s[i]);
    }
    
    string ans;
    while(!s.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

//---or---
void reverse2(vector<char>&s)
{
    stack<char>st;
    for(int i=0; i<s.size(); i++)
    {
        st.push(s[i]);
    }

    int i=0;
    while(!st.empty())
    {
        s[i]=st.top();
        i++;
        st.pop();
    }
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

//valid parenthesis (((())))
bool checkbal(string s)
{
    stack<char>st;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else 
        {
            if(st.empty())
            return false;
            else 
            st.pop();
        }
    }
    return st.empty();
}

//----or--- 
bool checkbal2(string s)
{
    int open=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            open++;
        }
        else 
        {
            if(open==0)
            return false;
            else 
            open--;
        }
    }
    return open==0;
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
            if(!st.empty())
            {
                char top=st.top();
                if((ch=='}' && top=='{') || (ch==')' && top=='(') || (ch==']' && top=='['))
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
    {
        return true;
    }
    return false;
}

//insert at bottom in stack 
void slove(stack<int>&st, int ele)
{
    if(st.empty())
    {
        st.push(ele);
        return ;
    }
    
    int take=st.top();
    st.pop();
    
    slove(st, ele);
    st.push(take);
    
}
int insertatbottom(stack<int>st, int num)
{
   slove(st, num);
}

//-- or---
stack<int>insertatbottom(stack<int>&st, int x)
{
    stack<int>temp;
    while(!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }

    st.push(x);
    while(!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
    return st;
}

//make the array beautiful (if adjcent are different than remove both)
//arr={2,3,5,-4,6,-2,-8,9} o/p={2,9}
vector<int>makebeautiful(vector<int>arr)
{
    stack<int>st;

    for(int i=0; i<arr.size(); i++)
    {
        if(st.empty())
        {
            st.push(arr[i]);
        }
        else if(arr[i]>=0)
        {
            if(st.top()>=0)
            st.push(arr[i]);
            else 
            st.pop();
        }
        else 
        {
            if(st.top()<0)
            st.push(arr[i]);
            else  
            st.pop();
        }
    }
    
    vector<int>ans(st.size());
    int i=st.size()-1;
    while(!st.empty())
    {
        ans[i]=st.top();
        i--;
        st.pop();
    }
    return ans;
}

//string mainpulation (if array adjecent string same than remove )
int stringmani(vector<string>arr)
{
    stack<string>st;
    for(int i=0; i<arr.size(); i++)
    {
        if(st.empty())
        {
            st.push(arr[i]);
        }
        else if(st.top()==arr[i])
        {
            st.pop();
        }
        else 
        {
            st.push(arr[i]);
        }
    }
    return st.size();
}

//reverse stack 
void insertatbottomm(stack<int>st, int num)
{
    if(st.empty())
    {
        st.push(num);
        return ;
    }
    
    int take=st.top();
    st.pop();
    
    insertatbottomm(st, num);
    st.push(take);
    
}
void reversestack(stack<int>st)
{
    if(st.empty())
    return ;
    
    int take=st.top();
    st.pop();
    
    reversestack(st);
    insertatbottomm(st, take);
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
bool isredundant(string s)
{
    int n=s.length();
    stack<char>st;
    for(int i=0; i<n; i++)
    {
        char ch=s[i];
        if(ch=='(' || ch=='-' || ch=='+' || ch=='/' || ch=='*')
        {
            st.push(ch);
        }
        else 
        {
            if(ch==')')
            {
                bool flage=true;
                while( st.top()!='(')
                {
                    char top=st.top();
                    if(top=='-' || top=='+' || top=='*' || top=='/')
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
int Minimumcost(string s)
{
    int n=s.length();
    if(n%2!=0)
    return -1;
    
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
            if(!st.empty() && st.top()=='{')
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
    for(int j=0; j<n-1; j++)
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
bool pattern132(int arr[], int n)
{
    int thirdele=0;      //this is arr[k]
    stack<int>st;   //stck contain arr[j]
    for(int i=n-1; i>=0; i--)
    {
        if(arr[i]<thirdele)
        {
            return true;
        }
        while(!st.empty() && st.top()<arr[i])
        {
            thirdele=st.top();
            st.pop();
        }
        
        st.push(arr[i]);
    }
    return false;
}

//next smaller element array 
vector<int> nextsmaller(int arr[], int n)
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

//previous smaller element array
vector<int> presmallerele(int arr[], int n)
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

//next greater element array
vector<int>nextgreaters(vector<int>arr, int n)
{
    vector<int>ans(n, -1);
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]>arr[i])
            {
                ans[i]=arr[i];
                break;
            }
        }
    }
    return ans;
}

vector<int> nextgreater(int arr[], int n)
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
vector<int> pregreater(int arr[], int n)
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
vector<int> nextsmallerr(int arr[], int n)
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
vector<int> presmallerelee(int arr[], int n)
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
    vector<int>next(n)=nextsmallerr(height, n);
    vector<int>pre(n)=presmallerelee(height, n);
    
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

//next greater element 2 
//pending 

//stock span problem 
vector<int> stockspane(int price[], int n)
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
        {
            ans.push_back(i+1);
        }
        else 
        {
            ans.push_back(i-st.top());
        }
        
        st.push(i);
    }
    return ans;
}

//traping raing water 
//time complexity is O(n^2)
//space complexity is O(1)
int trap(int arr[], int n)
{
    int trappedwater=0;
    for(int i=0; i<n; i++)
    {
        int j=i;
        int maxleft=0;
        int maxright=0;
        while(j>=0)
        {
            maxleft=max(maxleft, arr[j]);
            j--;
        }
        j=i;
        while(i<n)
        {
            maxright=max(maxright, arr[j]);
            j++;
        }
        
        trappedwater+=min(maxleft, maxright)-arr[i];
    }
    return trappedwater;
}


//time complexity is O(n)
//space complexity is O(2*n)
int trap(int arr[], int n)
{
    int prefix[n];
    int suffix[n];
    
    prefix[0]=arr[0];
    for(int i=1; i<n; i++)
    {
        prefix[i]=max(prefix[i-1], arr[i]);
    }
    
    suffix[n-1]=arr[n-1];
    for(int i=n-2; i>=0; i--)
    {
        suffix[i]=max(suffix[i+1], arr[i]);
    }
    
    int trappedwater=0;
    for(int i=0; i<n; i++)
    {
        trappedwater+=min(suffix[i], prefix[i])-arr[i];
    }
    return trappedwater;
}


//time complexity is O(n)
//space complexity is O(1)
int trap(int arr[], int n)
{
    int trappedwater=0;
    int leftmax=0;
    int rightmax=0;
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        if(arr[start]<=arr[end])
        {
            if(leftmax>=arr[start])
            {
                leftmax=arr[start];
            }
            else 
            {
                trappedwater+=leftmax-arr[start];
            }
            start++;
        }
        else 
        {
            if(rightmax>=arr[end])
            {
                rightmax=arr[end];
            }
            else 
            {
                trappedwater+=rightmax-arr[end];
            }
            end--;
        }
    }
    return trappedwater;
}

//Evaluate Reverse Polish Notation
int revPolishNot(vector<string>token)
{
    stack<int>st;
    for(int i=0; i<token.size(); i++)
    {
        if(token[i]=='-' || token[i]=='+' || token[i]=='*' || token[i]=='/')
        {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            
            if(token[i]=='+')
            {
                st.push(b+a);
            }
            else if(token[i]=='-')
            {
                st.push(b-a);
            }
            else if(token[i]=='*')
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
            st.push(stoi(token[i]));
        }
    }
    return st.top();
}

//generate parentheses (given n)
void slove(vector<string>&v, int n, int openc, int closec, string s)
{
    if(openc==n && closec==n)
    {
        v.push_back(s);
        return ;
    }
    
    if(openc<n)
    {
        slove(v, n, openc+1, closec, s+'(');
    }
    if(closec<openc)
    {
        slove(v, n, openc, closec+1, s+')');
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string>v;
    int openc=0;
    int closec=0;
    slove(v, n, openc, closec, "");
    return v;
}

//longest valid parentheses  )()())--->4
int longestvalid(string s)
{
    int n=s.length();
    stack<int>st;
    st.push(-1);
    int maxlen=0;
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
                maxlen=max(maxlen, i-st.top());
            }
        }
    }
    return maxlen;
}

//2-method 
int longestvalid(string s)
{
    int n=s.length();
    int open=0;
    int close=0;
    int maxlen=0;
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
        if(close==open)
        {
            maxlen=max(maxlen, 2*close);
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
            maxlen=max(maxlen, 2*open);
        }
        else if(open>=close)
        {
            open=0;
            close=0;
        }
    }
    return maxlen;
}

//remove invalid parentheses  ()())()--->(())(), ()()()
vector<string>ans;
unordered_map<string ,int>mp;
int getinvalid(string s)
{
    int n=s.length();
    stack<char>st;
    for(int i=0; i<n; i++)
    {
        char ch=s[i];
        if(ch=='(')
        {
            st.push(ch);
        }
        else 
        {
            if(st.size()>0 && st.top()=='(')
            {
                st.pop();
            }
            else 
            {
                st.push(ch);
            }
        }
    }
    return st.size();
}
void slove(string s, int minIn)
{
    
    if(mp[s]!=0)
    return ;
    else
    mp[s]++;
    
    if(minIn<0)
    return ;
    
    if(minIn==0)
    {
        if(getinvalid(s)==0)
        {
            ans.push_back(s);
            return ;
        }
    }
    
    for(int i=0; i<s.length(); i++)
    {
        string left=s.substr(0, i);
        string right=s.substr(i+1);
        slove(left+right, minIn-1);
    }
    return ;
}
vector<string> removeInvalidParentheses(string s)
{
    slove(s, getinvalid(s));
    return ans;
}

//remove k digit 
//time complexity is O(n^2)
//space complexity is O(n) 
string removekdigit(string s, int k)
{
    int n=s.length();
    if(k>=n)
    return "0";
    
    stack<char>st;
    for(int i=0; i<n; i++)
    {
        if(st.empty())
        {
            st.push(s[i]);
        }
        else 
        {
            if(!st.empty() && st.top()>s[i] && k>0)
            {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
    }
    
    //this is spacial case if k is not zero and element in stack than simply largest element will be delete 1,4,3,2,7,8 k=4
    while(k>0)
    {
        st.pop();
        k--;
    }
    
    if(st.empty())
    return "0";
    
    string ans;
    while(!st.empty())
    {
        ans=st.top()+ans;
        st.pop();
    }
    
    int i=0;
    while(ans[i]=='0')
    {
        i++;
    }
    
    return (ans.substr(i)==" ") ? "0" : ans.substr(i);
}

//Minimum Remove to Make Valid Parentheses  
string miniremoveisvalid(string s)
{
    stack<char>st;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            st.push(i);
        }
        else if(s[i]==')')
        {
            if(st.empty()) //this mean first closing bracket / extra closing bracket 
            {
                s[i]='#';
            }
            else 
            {
                st.pop();
            }
        }
    }
    
    while(!st.empty()) //extra opening bracket 
    {
        s[st.top()]='#';
        st.pop();
    }
    
    string ans;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]!='#')
        {
            ans.push_back(s[i]);
        }
    }
    return ans;
}

//2-method 
string miniremoveisvalid(string s)
{
    int n=s.length();
    int count=0;
    for(int i=0; i<n; i++)  //a)b(c)d
    {
        if(s[i]=='(')
        {
            count++;
        }
        else if(s[i]==')')
        {
            if(count==0)
            {
                s[i]='#';
            }
            else 
            {
                count--;
            }
        }
    }
    
    count=0;
    for(int i=n-1; i>=0; i--)   //a(b(c)d
    {
        if(s[i]==')')
        {
            count++;
        }
        else if(s[i]=='(')
        {
            if(count==0)
            {
                s[i]='#';
            }
            else 
            {
                count--;
            }
        }
    }
    
    string ans;
    for(int i=0; i<n; i++)
    {
        if(s[i]!='#')
        {
            ans.push_back(s[i]);
        }
    }
    return ans;
}

//score of Parentheses  ()=1  (a)=2*a
int score(string s)
{
    stack<char>st;
    int score=0;
    for(auto ch : s)
    {
        if(ch=='(')
        {
            st.push(score);
            score=0;
        }
        else 
        {
            score=st.top()+max(2*score, 1);
            st.pop();
        }
    }
    return score;
}

//minimum add to make Parentheses valid  ((( ==3 
int minimumaddvalid(string s)
{
    int n=s.length();
    stack<char>st;
    for(int i=0; i<n; i++)
    {
        char ch=s[i];
        if(ch=='(')
        {
            st.push(ch);
        }
        else 
        {
            if(st.empty() || st.top()==')')
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
int minimumaddvalid(string s)
{
    int n=s.length();
    int open=0;
    int close=0;
    for(int i=0; i<n; i++)
    {
        if(ch=='(')
        {
            open++;
        }
        else 
        {
            if(st.empty() || st.top()==')')
            {
                close++;
            }
            else 
            {
                open--;
            }
        }
    }
    return open+close;
}

//3-method 
int minimumaddvalid(string s)
{
    int n=s.length();
    int count=0;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        char ch=s[i];
        if(ch=='(')
        {
            count++;
        }
        else 
        {
            count--;
        }
    }
    if(count<0)
    {
        ans++;
        count++;
    }
    
    return ans+count;
}

//print bracket number 
//s=(aa(bdc))p(de) // o/p=122133 
vector<int>printbracketno(string s)
{
    stack<char>st;
    vector<int>ans;
    int count=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            count++;
            st.push(count);
            ans.push_back(count);
        }
        else if(s[i]==')')
        {
            ans.push_back(st.top());
            st.pop();
        }
    }
    return ans;
}

//get minimum at the pop 
void getminpop(int arr[], int n)
{
    stack<int>st;
    for(int i=0; i<n; i++)
    {
        if(i==0)
        st.push(arr[i]);
        else 
        st.push(min(arr[i], st.top()));
    }

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
















//-------------------- 
int countleaf(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    if(root->left==NULL && root->right==NULL)
    return 1;
    
    return countleaf(root->left)+countleaf(root->right);
}

void slove(TreeNode*root)
{
    if(root==NULL)
    return ;
    
    if(root->left==NULL && root->right==NULL)
    {
        count++;
        return ;
    }
    
    slove(root->left, count);
    slove(root->right, count);
}
int countleafnode(TreeNode*root)
{
    int count=0;
    slove(root, count);
    return count;
}

int countnonleaf(TreeNode*root)
{
    if(root==NULL)
    return 0;
    
    if(root->left==NULL && root->right==NULL)
    return 0;
    
    return 1+countnonleaf(root->left)+countnonleaf(root->right);
}

bool parent(TreeNode*root, int a, int b)
{
    if(root==NULL)
    return false;
    
    if(root->left!=NULL && root->right!=NULL)
    {
        if(root->left->val==a && root->right->val==b)
        return true;
        
        if(root->left->val==b && root->right->val==a)
        return true;
    }
    
    return parent(root->left, a, b) || parent(root->right, a, b);
}
bool cousine(TreeNode*root, int b, int b)
{
    queue<TreeNode*>q;
    q.push(root);
    int l1=-1;
    int l2=-1;
    int level=0;
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0; i<size; i++)
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(node->val==a)
            l1=level;
            
            if(node->val==b)
            l2=level;
            
            if(node->left!=NULL)
            q.push(node->left);
            
            if(node->right!=NULL)
            q.push(nde->right);
        }
        level++;
        if(l1!=l2)
        return false;
        
        if(l1!=-1 && l2!=-1)
        break;
    }
    return !parent(root, a, b);
}

void leftviewrec(TreeNode*root, int level, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    if(level==ans.size())
    ans.push_back(root->val);
    
    leftviewrec(root->left, level+1, ans);
    leftviewrec(root->right, level+1, ans);
}
vector<int>leftrec(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    leftviewrec(root, 0, ans);
    return ans;
}


void rightviewrec(TreeNode*root, int level, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    if(level==ans.size())
    ans.push_back(root->val);
    
    rightviewrec(root->right, level+1, ans);
    rightviewrec(root->left, level+1, ans);
}
vector<int>rightrec(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    
    rightviewrec(root, 0, ans);
    return ans;
}


bool palindreome(string s, int start, int end)
{
    if(start>=end)
    return true;
    
    if(s[start]!=s[end])
    return false;
    
    return palindreome(s, start+1, end-1);
}

int countvowel(string str, int index)
{
    if(index==-1)
    return 0;
    
    if(str[index]=='a' || str[index]=='e' || str[index]=='i' || str[index]=='o' || str[index]=='u')
    return 1+countvowel(str, index-1);
    
    else 
    return countvowel(str, index-1);
}

void lowertoupper(string &str, int index)
{
    if(index==-1)
    return ;
    
    str[index]='A'+str[index]-'a';
    lowertoupper(str, index-1);
}


int linearsearch(int arr[], int index, int target, int n)
{
    if(index==n)
    return -1;
    
    if(arr[index]==target)
    return index;
    
    return linearsearch(arr, index+1, target, n);
}


int binarysearch(int arr[], int start,int end int target)
{
    if(start>end)
    return -1;
    
    int mid=(start+end)/2;
    
    if(arr[mid]==target)
    return mid;
    
    if(arr[mid]<target)
    return binarysearch(arr, mid+1, end, target); 
    else 
    return binarysearch(arr, start, mid-1, target)
}



//merge sort 
void merge(vector<int>&arr, int low, int mid, int high)
{
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else 
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++)
    arr[i]=temp[i-low];
}
void mergesort(vector<int>&arr, int low, int high)
{
    if(low>=high)
    return;

    int mid=(low+high)/2;
    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int partition(vector<int>&arr, int low, int high)
{
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(arr[i]=pivot && i<=high-1)
        i++;
        while(arr[j]>pivot && j>=low+1)
        j--;

        if(i<j)
        swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void quicksort(vector<int>&arr, int low, int high)
{
    if(low>=high)
    return ;
    int pivot=partition(arr, low, high);
    quicksort(arr, low, pivot-1);
    quicksort(arr, pivot+1, high);
}