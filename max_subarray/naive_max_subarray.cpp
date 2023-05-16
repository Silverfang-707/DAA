#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
#include<time.h>

struct details
{
    int low;
    int high;
    int sum;
};

details find_maximum_subarray(vector<int> a)
{
    int i, j, n, max_left,max_right, max_sum,curr_sum;
    details d;
    max_sum = INT_MIN;
    n = a.size();
    for(i=0;i<n;i++)
    {
        curr_sum = a[i];
        // size of sub_array is 1 and ith element is part of it
        if(curr_sum>max_sum)
        {
            max_sum = curr_sum;
            max_left = i;
            max_right = i;
        }
        // size of subarray will be from 2 to n - i and ith element is part of it
        for(j=i+1;j<n;j++)
        {
            curr_sum += a[j];
            if(curr_sum>max_sum)
            {
                max_sum = curr_sum;
                max_left = i;
                max_right = j;
            }
        }
    }
    d.low = max_left;
    d.high = max_right;
    d.sum = max_sum;
    return d;
}

int main()
{
    srand(time(0));
    vector<int> A;
    int low,high,n,i,ele;
    details ans;
    cout<<"Enter the Number of elements: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        A.push_back(-10+rand()%10);
    }
    cout<<"Finished IP\n";
    ans = find_maximum_subarray(A);
    cout<<"low: "<<ans.low<<" "<<"High: "<<ans.high<<" "<<"Sum: "<<ans.sum<<endl;
}
