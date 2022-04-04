#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:
    
    int two_pointers(vector<string>&A) {
        int n = A.size();
        vector<double>arr;
        for(int i = 0; i<n; i++) {
            double curr_num = stod(A[i]);
            arr.push_back(curr_num);
        }
        int l = 0, r = n - 1;
        sort(arr.begin(), arr.end());
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            double curr_val = arr[l] + arr[mid] + arr[r];
            if(curr_val <= 1.0) l++;
            else if(curr_val >= 2.0) r--;
            else return 1;
        }
        return 0;
    }
    int solve(vector<string>&A);


};

bool f(double a, double b, double c) {
    return (1 < (a + b + c)) and ((a + b + c) < 2);
}

double get_value(double a, double b, double c) {
    return a + b + c;
}

int Solution::solve(vector<string> &A) {
    // required value to return 1 < a + b + c < 2
    int n = A.size();
    map<double, int>hsh;
    vector<double>arr;
    for(int i = 0; i<n; i++) {
        double val = stod(A[i]);
        arr.push_back(val);
        hsh[val]++;
    }   

    /**
    A) `a \in X, b \in X, C \in X` 
    B) `a \in X, b \in X, C \in Y` 
    C) `a \in X, b \in X, C \in Z` 
    D) `a \in X, b \in Y, C \in Y` 
    E) `a \in X, b \in Y, C \in Z`

    x = (0, 2/3) 
    */

    
    vector<vector<double>>buckets(3);
    for(auto i: arr) {
        if(i > 0 and i < (2.0/3.0)) {
            buckets[0].push_back(i);
        }
        if(i >= (2.0/3.0) and i <= (1.0)) {
            buckets[1].push_back(i);
        }
        if(i > 1.0 and i < 2.0) {
            buckets[2].push_back(i);
        }
    }

    for(int i = 0; i<3; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }
    // case 1
    if(buckets[0].size() > 2) {
        int sz = buckets[0].size();
        if(f(buckets[0][n-1], buckets[0][n-2], buckets[0][n-3]))
            return 1;
    }

    // case 3
    if(buckets[0].size() > 1 and buckets[2].size()) {
        if(f(buckets[0][0], buckets[0][1], buckets[0][2]))
            return 1;
    }

    // case 4
    if(buckets[0].size() and buckets[1].size() > 1) {
        if(f(buckets[0][0], buckets[1][0], buckets[1][1]))
            return 1;
    }

    // case 5
    if(buckets[0].size() and buckets[1].size() and buckets[2].size()) {
        if(f(buckets[0][0], buckets[1][0], buckets[2][0]))
            return 1;
    }

    
    // case 2
    // further need to divide into x1 x2 x3

    return 0;
}

/*
int Solution::solve(vector<string> &arr) {
int n=arr.size(),i;
vector<float>v;
for(i=0;i<n;i++)
{
    v.push_back(stof(arr[i]));
}
float a=v[0],b=v[1],c=v[2];

float mx=0;
for(i=3;i<n;i++)
{
    if(a+b+c<2 && a+b+c>1)
        return 1;
    else if(a+b+c>2)
    {
        if(a>b && a>c)
            a=v[i];
        else if(b>a && b>c)
            b=v[i];
        else
            c=v[i];
    }
    else
    {
        if(a<b && a<c)
            a=v[i];
        else if(b<a && b<c)
            b=v[i];
        else
            c=v[i];

    }
}
if(a+b+c>1 && a+b+c<2)
    return 1;
else
    return 0;
}

*/



signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
 
    return 0;
}