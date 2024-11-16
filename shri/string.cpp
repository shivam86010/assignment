#include<bits/stdc++.h>
using namespace std;
//reverse a string   //string s=abcde o/p=edcba
//time complexity is O(n)
//space complexity is O(1)
void reverse11(string s)
{
    int n=s.length();
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

//reverse the word in string  Input: s = "the sky is blue"
//Output: "blue is sky the"
//time complexity is O(n)
//space complexity is O(1)
string reverse2(string s)
{
    int n=s.length();
    int i=0;
    string ans;
    while(i<n)
    {
        while(i<n && s[i]==' ')
        i++;
        
        
        //this is edge case where in the reverse the word than first and last position will space than this edge case will be 
        //remove the space 
        if(i>=n)
        break;
        
        int j=i+1;
        while(j<n && s[j]!=' ')
        j++;
        string sub=s.substr(i, j-i);
        if(ans.length()==0)
        ans=sub;
        else
        ans=sub+" "+ans;
        i=j+1;
    }
    return ans;
}

//reverse each word in the sentence  i/p=ram is good boy   o/p=mar si doog yob
//time complexity is O(n)
//space complexity is O(1)
string reverse2(string s)
{
    int n=s.length();
    int i=0;
    int j=0;
    while(i<n)
    {
        while(j<n && s[j]!=' ')
        j++;
        reverse(s.begin()+i, s.begin()+j);
        i=j+1;
        j=i;
    }
    return s;
}

//reverse string with k group and skip the k and than again reverse k group 
//Input: s = "abcdefg", k = 2
//Output: "bacdfeg"
//time complexity is O(n)
//space complexity is O(1)
string reverse4(string s, int k)
{
    int n=s.length();
    for(int i=0; i<n; i+=2*k)
    {
        if(i+k<n)
        {
            reverse(s.begin()+i, s.begin()+i+k);
        }
        else
        {
            reverse(s.begin()+i, s.end());
        }
    }
    return s;
}
//check wether string is palindrome or not 
//time complexity is O(n)
//space complexity is O(1)
bool palindrome(string s)
{
    int n=s.length();
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        if(s[start]!= s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

//string is rotation 
//time complexity is O(n)
//space complexity is O(1)
bool rotateString(string s, string goal)
{
    int len1=s.length();
    int len2=goal.length();
    if(len1!=len2)
    return false;
    
    string temp=s+s;
    if(temp.find(goal)!=string::npos)
    {
        return true;
    }
    return false;
}

//spliting string with equal zero and one 
//time complexity is O(n)
//space complexity is O(1)
bool spliting(string str)
{
    int n=str.length();
    int count0=0;
    int count1=0;
    int count=0;
    for(int i=0; i<n; i++)
    {
        if(str[i]==0)
        count0++;
        else
        count1++;
        if(count0!=count1)
        {
            count++;
        }
    }
    if(count!=count0)
    {
        return -1;
    }
    return count;
}

//check string or angram or not //angram means both string contain same character as well same frequency of character 
//time complexity is O(nlogn)
//space complexity is O(1)
bool angram(string s1, string s2)
{
    int len1=s1.length();
    int len2=s2.length();
    if(len1!=len2)
    return false;
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return (s1==s2);

}

//optimal approach 
//time complexity is O(n)
//space complexity is O(1)
bool angram(string s1, string s2)
{
    int len1=s1.length();
    int len2=s2.length();
    
    if(len1!=len2)
    return false;

    int count[256]={0};
    for(int i=0; i<len1; i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for(int i=0; i<256; i++)
    {
        if(count[i]!=0)
        return false;
    }
    return true;
}

//non repeating character in string 
//time complexity is O(n)
//space complexity is O(n)
string nonrepeating(string str)
{
    int n=str.length();
    unordered_map<char, int>mp;
    for(int i=0; i<n; i++)
    {
        mp[str[i]]++;
    }
    for(int i=0; i<n; i++)
    {
        if(mp[str[i]]==1)
        {
            return str[i];
        }
    }
    return -1;
}

//is subsequence 
//time complexity is O(n)
//space complexity is O(1)
bool issubsequence(string s1, string s2)
{
    int len1=s1.length();
    int len2=s2.length();
    int i=0;
    int j=0;
    for(int i=0; i<len1 &&j<len2; i++)
    {
        if(s1[i]==s2[j])
        j++;
    }
    return (j==len2);
}

//Find first repeated character
//time complexity is O(n)
//space complexity is O(n)
string firstrepeated(string str)
{
    string ans;
    int n=str.length();
    unordered_map<char, int>mp;
    for(int i=0; i<n; i++)
    {
        mp[str[i]]++;
        if(mp[str[i]]>1)
        {
            ans=str[i];
            break;
        }
    }
    if(ans.length() ==' ')
    return "-1";
    return ans;
}

//Isomorphic Strings ----->  Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//time complexity is O(n)
//space complexity is O(256)
bool isIsomorphic(string s, string t)
{
    int n=s.length();
    int m=t.length();
    if(n!=m)
    return false;
    
    int m1[256]={0};
    int m2[256]={0};
    for(int i=0; i<n; i++)
    {
        //if the characters is first time occure than store the occurance other wise goto else if part
        if(!m1[s[i]] && !m2[t[i]])
        {
            m1[s[i]]=t[i];
            m2[t[i]]=s[i];
        }
        else if(m1[s[i]]!=t[i])
        return false;
    }
    return true;
}

//print sequence when press mobile keypad  Example== gfg-43334 
//time complexity is O(n)
//space complexity is O(1)m
string printsequence(string s)
{
    string str[26]={"2","22","222", "3","33","333","4","44","444", "5", "55", "555", "6", "66", "666", "7","77","777", "8","88",
    "888","9","99", "999"};
    
    string ans;
    int n=s.length();
    for(int i=0; i<n; i++)
    {
        if(s[i]==' ')
        {
            ans=ans+'0';
        }
        else
        {
            int j=s[i]-'A';
            ans=ans+str[j];
        }
    }
    return ans;
    
}








