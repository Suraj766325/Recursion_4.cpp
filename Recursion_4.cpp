// Q1) Given an integer array containing unique numbers, return power set, containing all the subsets of the set. [Leetcode 78]
#include<iostream>
#include<vector>
using namespace std;
void subset(vector<int>&original,vector<int>ans,vector<vector<int>>&v,int idx,int n)
{
    if(idx==n){
        v.push_back(ans);
        return;
    }
    subset(original,ans,v,idx+1,n);
    ans.push_back(original[idx]);
    subset(original,ans,v,idx+1,n);
}
int main()
{
    vector<int>original={1,2,3};
    vector<vector<int>>v;
    subset(original,{},v,0,original.size());
    for(vector<int>ele:v)
    {
        for(int num:ele)
        cout<<num<<" ";
    cout<<endl;
    }
}




// Q2) Given an integer array which may contain duplicate numbers, return power set, containing all the subsets of the set. [Leetcode 90]
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void subset(vector<int>&original,vector<int>ans,vector<vector<int>>&v,int i,int n,bool flag){
    if(i==n){
        v.push_back(ans);
        return;
    }
    if(i==n-1)
    {
        subset(original,ans,v,i+1,n,true);
        ans.push_back(original[i]);
        if(flag==true) subset(original,ans,v,i+1,n,true);
    }
    else if(original[i]==original[i+1])
    {
        subset(original,ans,v,i+1,n,false);
        ans.push_back(original[i]);
        if(flag==true) subset(original,ans,v,i+1,n,true);
    }
    else{
        subset(original,ans,v,i+1,n,true);
        ans.push_back(original[i]);
        if(flag==true) subset(original,ans,v,i+1,n,true);
    }
}
int main()
{
    vector<int>original={1,2,2};
    sort(original.begin(),original.end());
    vector<vector<int>>v;
    subset(original,{},v,0,original.size(),true);
    for(vector<int>ele:v)
    {
        for(int num:ele)
        cout<<num<<" ";
    cout<<endl;
    }
}




// Q3) Program to find the factorial of a given number.
#include<iostream>
using namespace std;
int fact(int n)
{
    if(n==1) return 1;
    return n*fact(n-1);
}
int main()
{
    cout<<fact(5);
}




// Q4) Program to convert a decimal number to binary.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void binary(vector<int>&v,int n)
{
    if(n==1){
        v.push_back(1);
        return;
    }
    v.push_back(n%2);
    binary(v,n/2);
}
int main()
{
    vector<int>v;
    binary(v,10);
    reverse(v.begin(),v.end());
    for(int ele:v) cout<<ele<<" ";
}
