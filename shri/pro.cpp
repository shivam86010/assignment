#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>second(TreeNode*root)
{
    vector<vector<int>>ans;
    if(root==null)
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

            if(node->left!=null)
            q.push(node->left);

            if(node->right!=null)
            q.push(node->right);

            level.push_back(node->val);
        
        }
        ans.push_back(level);
    }
    return ans;
}

vector<vector<int>>foursumopt(int arr[], int n, int target)
{
    sort(arr, arr+n);
    vector<vector<int>>ans;
    for(int i=0; i<n-2; i++)
    {
        if(i==0 && arr[i]==arr[i-1])
        continue;

        for(int j=i+1; j<n-1; j++)
        {
            if(j!=i && arr[j]==arr[j-1])
            continue;

            int start=j+1;
            int end=n-1;
            int sum=target-(arr[i]+arr[j]);

            while(start<end)
            {
                if(arr[start]+arr[end]==sum)
                {
                    vector<int>temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[start]);
                    temp.push_back(arr[end]);
                    start++;
                    end--;

                    while(satart<end && arr[start]==arr[start-1])
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


int foursum2opt(int arr1[], int arr2[], int arr3[], int arr4[], int n)
{
    unorder_map<int,int>mp;
    for(auto l : arr3)
    {
        for(auto m : arr4)
        {
            mp[l+m]++;
        }
    }

    int count=0;
    for(auto i : arr2)
    {
        for(auto j : arr1)
        {
            count+=(j-i);
        }
    }
    return count; 
}



//object.freeze();
//object.seal();

//function definition -or- function declaration 
function abc()
{
    console.log("ram is good boy");
}

//function definition -or- function expression 
const say=function abc()
{
    console.log("ram is good boy");
}

//anonymous function 
let x=function()
{
    console.log("hii")
}

//arrow fuction 
//iifec
//local scope and global scope
//higher order function 
//callback function 
//settimeout
//settimeinterval
//cleartimeout
//event loop 
//callback queue 
//return function with closoure 
//difference with method and function 


/* 


//callback hell 

console.log("ram");
console.log("is good");
console.log("boy");



setTimeout(function(){
    console.log("hello");
}, 5000);

suppose create a e-commerce website 
const cart=["shoes", "pants", "kurta"];

createOrder
proceedTopayment 
showOrderSummary 
updatewallet

api.createOrder(cart, function(){
    
    api.proceedTopayment(function(){
        
        api.showOrderSummary(function(){
            
            api.updatewallet();
        })
    })
})

importance of callback 
callback are like super powerful way of handling asynchronous operation in javascript 
in fact asynchronous programming in javascript exist beccause callback exist 

issues with callback 
1-- callback hell 
2-- inversion control 
we have given the control of this function to another function we don't know whether that function
will ever execute or callback or not .


//promises 
promises are use to handling asynchronous code in javascript 

---------------------------------------------------------------------------------------------------------------- 
Callback Hell (Pyramid of Doom): This is a situation where callbacks are nested within callbacks, leading to code that's hard to read and debug.
2️⃣ Inversion of Control: This is when you hand over control of your code to a third party (usually a library or a third-party API). This can lead to trust issues and makes error handling difficult.
🔹 The introduction of Promises in JavaScript provided a solution to these problems.
🔹 A Promise is an object that represents the eventual completion or failure of an asynchronous operation. It has three states:
1️⃣ Pending: The Promise's outcome hasn't yet been determined.
2️⃣ Fulfilled: The asynchronous operation has been completed, and the Promise has a resulting value.
3️⃣ Rejected: The asynchronous operation failed, and the Promise will never be fulfilled.
🔹 Once a Promise is fulfilled or rejected, it becomes immutable, meaning its state can't change.
🔹 We use the .then() method to schedule a callback to be run once the Promise is fulfilled or rejected.
🔹 To avoid the Pyramid of Doom, we can chain Promises, allowing our code to expand vertically rather than horizontally. This is done using the .then() method.
🔹 A common mistake developers make is forgetting to return a value during Promise chaining. Always remember to return a value, as this will be used by the next .then() in the chain.  

*/







