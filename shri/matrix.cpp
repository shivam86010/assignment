//find the lucky number in matrix (lucky element means minimum in row and maximum in column)
//time complexity is O(n*m)
int luckyelement(vector<vector<int>>mat)
{
    int n=mat.size();
    int m=mat[0].size();
    vector<int>ans;
    
    for(int i=0; i<n; i++)
    {
        int mini=INT_MAX;
        int minindex=-1;
        for(int j=0; j<m; j++)
        {
            if(mat[i][j]<mini)
            {
                mini=mat[i][j];
                minindex=j;
            }
        }
        
        int maxi=-1;
        for(int j=0; j<n; j++)
        {
            if(mat[j][minindex]>maxi)
            maxi=mat[j][minindex];
        }
        
        if(maxi==mini)
        ans.push_back(maxi);
    }
    return ans;
}


//matrix diagonal sum 
//time complexity is O(n)
//space complexity is O(1)
int diagonalsum(vector<vector<int>>mat)
{
    int totalsum=0;
    int n=mat.size();
    for(int i=0; i<n; i++)
    {
        totalsum+=mat[i][i];
        totalsum+=mat[i][n-i-1];
    }
    
    if(n%2!=0) //odd ke case mai common element will be remove 
    {
        totalsum-=mat[n/2][n/2];
    }
}

//spiral matrix 
//time complexity is O(n*m)
//space complexity is O(n)
int spiraltraversal(vector<vector<int>>mat)
{
    int n=mat.size();
    int m=mat[0].size();
    int top=0;
    int bottom=n-1;
    int left=0;
    int right=m-1;
    vector<int>ans;
    //These conditions are added to check if the matrix is a single column or a single row. So, whenever the elements in a 
    //single row are traversed they cannot be traversed again backward so the condition is checked in the right-to-left loop.
    //When a single column is present, the condition is checked in the bottom-to-top loop as elements from bottom to top cannot 
    //be traversed again.


    while(top<=bottom && left<=right)
    {
        for(int i=left; i<=right; i++)
        {
            ans.push_back(mat[top][i]);
        }
        top++;
        
        for(int i=top; i<=bottom; i++)
        {
            ans.push_back(mat[i][right]);
        }
        right--;
        
        if(top<=bottom) //if only row than no need for go to back 
        {
            for(int i=right; i>=left; i--)
            {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        
        if(left<=right) //no top 
        {
            for(int i=bottom; i>=top; i--)
            {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
}

//spiral matrix-II (in this problem only gives n and create matrix )
//time complexity is O()
//space complexity is O(n*m)
int spiraltraversal-II(int n)
{
    int top=0;
    int bottom=n-1;
    int left=0;
    int right=n-1;
    int index=1;
    vector<vector<int>>ans(n, vector<int>(n,1));
    
    while(top<=bottom && left<=right)
    {
        for(int i=left; i<=right; i++)
        {
            ans[top][i]=index;
            index++;
        }
        top++;
        
        for(int i=top; i<=bottom; i++)
        {
            ans[i][right]=index;
            index++;
        }
        right--;
        
        for(int i=right; i>=left; i--)
        {
            ans[bottom][i]=index;
            index++;
        }
        bottom--;
        
        for(int i=bottom; i>=top; i--)
        {
            ans[i][left]=index;
            index++;
        }
        left++;
    }
    return ans;
}


//find kth smallest elements in sorted matrix brute force approach 
//time complexity is O(nlogk)
//space complexity is O(k)
int kthsmallest(vector<vector<int>>mat, int k)
{
    priority_queue<int>q;    //max heap 
    for(int i=0; i<mat.size(); i++)
    {
        for(int j=0; j<mat[0].size(); j++)
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
//time complexity is O(nlogn)
//space complexity is O(1)
int kthsmallest(vector<vector<int>>mat)
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

//reshape the matrix 
//time complexity is O(n*m)
//space complexity is O(n*m)
int reshape(vector<vector<int>>mat, int r, int c)
{
    vector<vector<int>>ans(r, vector<int>(c));
    int n=mat.size();
    int m=mat[0].size();
    
    if(n*m!=r*c)
    return mat;
    
    int row=0;
    int col=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            ans[row][col]=mat[i][j];
            col++;
            if(clo==c)
            {
                row++;
                col=0;
            }
        }
    }
    return ans;
}

//flipping image in matrix
//time complexity is O(n*m)
//space complexity is O(1)
int flipping(vector<vector<int>>mat)
{
    int n=mat.size();
    int m=mat[0].size();
    
    for(int i=0; i<n; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            mat[i][j]^=1;
        }
    }
    return mat;
}

//find the kth weakest row in matrix 
int countsoldier(vector<int>&v)
{
    int start=0;
    int end=v.size()-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(v[mid]==0)
        {
            end=mid-1;
        }
        else 
        {
            start=mid+1;
        }
    }
    return start;
}
int kthweakestrow(vector<vector<int>>mat, int k)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>>q; //max heap 
    
    for(int i=0; i<mat.size(); i++)
    {
        q.push({countsoldier(mat[i]), i}); //queue will store the slodier and row number 
        if(q.size()>k)
        {
            q.pop();
        }
    }
    
    vector<int>ans;
    while(!q.empty())
    {
        ans.push_back(q.top().second);
        q.pop();
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

//count negative number in sorted matrix brute force approach 
//time complexity is O(n*m)
//space complexity is O(1)
int countnegative(vector<vector<int>>mat)
{
    int n=mat.size();
    int m=mat[0].size();
    
    int count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mat[i][j]<0)
            {
                count++;
            }
        }
    }
    return count;
}

//optimal approach 
//time complexity is O(nlogn)
//space complexity is O(1)
int countnegative(vector<vector<int>>mat)
{
    int n=mat.size();
    int count=0;
    
    for(int i=0; i<n; i++)
    {
        count+=upper_bound(mat[i].rbegin(), mat[i].rend(), -1)-mat[i].rbegin();
    }
    return count;
}

//toepitz matrix 
//time complexity is O(n*m)
//space complexity is O(1)
bool istoepitz(vector<vector<int>>mat)
{
    int n=mat.size();
    int m=mat[0].size();
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mat[i][j]!=mat[i+1][j+1])
            {
                return false;
            }
        }
    }
    return true;
}

//diagonal traversed 
int diagonal(vector<vector<int>mat)
{
    int n=mat.size(); 
    int m=mat[0].size();
    int row=0;
    int col=0;
    bool up=true;
    vector<int>result;
    while(row<n and col<m)
    {
        if(up==true)
        {
            while(row>0 and col<m-1)
            {
               result.push_back(mat[row][col]);
               row--;
               col++;
            }
            result.push_back(mat[row][col]);
            if(col==m-1)
            {
                row++;
            }
            else
            {
                col++;
            }
        }
        else
        {
            while(col>0 and row<n-1)
            {
                result.push_back(mat[row][col]);
                row++;
                col--;
            }
            result.push_back(mat[row][col]);
            if(row==n-1)
            {
                col++;
            }
            else
            {
                row++;
            }
        }
        up=!up; 
      }
    return result;
}

//second method 
//time complexity is O(n*m)
//space complexity is O(1)
int diagonal(vector<vector<int>>mat)
{
    int n=mat.size(); 
    int m=mat[0].size();
    int row=0;
    int col=0;
    vector<int>ans;
    for(int i=0; i<n*m; i++)
    {
        ans.push_back(mat[row][col]);
        if((row+col)%2==0)
        {
            if(col==m-1)
            {
                row++;
            }
            else if(row==0)
            {
                col++;
            }
            else 
            {
                row--;
                col++;
            }
        }
        else 
        {
            if(row==n-1)
            {
                col++;
            }
            else if(col==0)
            {
                row++;
            }
            else 
            {
                row++;
                col--;
            } 
        }
    }
    return ans;

}









