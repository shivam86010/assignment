#include<bits/stdc++.h>
using namespace std;
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
stack<int>insertatbottom(stack<int>st, int num)
{
   slove(st, num);
   return st;
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
    if(st.empty() || st.top()<num)
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

//the celebrity problem 
bool knows(vector<vector<int>>&arr, int a, int b, int n)
{
    if(arr[a][b]==1)
    return true;
    else 
    return false;
}
int celebrity(vector<vector<int>>&arr, int n)
{
    stack<int>st;
    //step 1= push all element in stack 
    for(int i=0; i<n; i++)
    st.push(i);

    //step 2=element are compaire 
    while(st.size()>1)
    {
        int a=st.top();
        st.pop();

        int b=st.top();
        st.pop();

        if(knows(arr,a, b,n))
        {
            st.push(b);
        }
        else 
        {
            st.push(a);
        }
    }
    
    int ans=st.top();
    //step 3 is single elemnt in stack is potiential celebrity 
    int zerocount=0;
    for(int i=0; i<n; i++)
    {
        if(arr[ans][i]==0)
        zerocount++;
    }

    if(zerocount!=n)
    return -1;

    int onecount=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i][ans]==1)
        onecount++;
    }

    if(onecount!=n-1)
    return -1;

    return ans;
}

//n stack into a single array 
class nstack
{
    int *arr;
    int *top;
    int *next;

    int n, s;
    int freeslot;

    public :
    nstack(int N, int S)
    {
        n=N;
        s=S;
        arr=new int[s];
        top=new int[n];
        next=new int[s];

        //top initialise 
        for(int i=0; i<n; i++)
        top[i]=-1;

        for(int i=0; i<s; i++)
        {
            next[i]=i+1;
        }
        next[s-1]=-1;

        freeslot=0;
    }

    bool push(int x, int m)
    {
        //check overflow
        if(freeslot==-1)
        return false;

        //find index 
        int index=freeslot;
        //update freeslot 
        freeslot=next[index];
        //insert element into array 
        next[index]=x;
        //update next 
        next[index]=top[m-1];
        //update top 
        top[m-1]=index;

        return true;
    }

    int pop(int m)
    {
        //check underflow 
        if(top[m-1]==-1)
        return -1;

        int index=top[m-1];
        top[m-1]=next[index];
        next[index]=freeslot;
        freeslot=index;

        return arr[index];
    }
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