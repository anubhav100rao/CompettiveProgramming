#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int partition(vector<int>&arr, int low, int high) {
    int i = low, j = high, pivot = arr[low];

    while(i <= j) {
        while(i <= j and arr[i] <= pivot) i++;
        while(i <= j and arr[j] > pivot) j--;
        if(i <= j) swap(arr[i], arr[j]);
    }
    /**
     * left pivot element
     * middle pivot element
     * last pivot element
     * randomised quick sort
     */
    swap(arr[low], arr[j]);
    
    return j;
}
// two ways implemented for quick sort
int partition_maintain(vector<int>&a, int low, int high) {
        int n = a.size();
        vector<int>result(high - low + 1, 0);
        int pivot = a[0];
        int idx = 0;
        for(int i = 0; i<n; i++) {
            if(a[i] < pivot) {
                result[idx] = a[i];
                idx++;
            }
        }

        for(int i = 0; i<n; i++) {
            if(a[i] == pivot) {
                result[idx] = a[i];
                idx++;
            }
        }

        for(int i = 0; i<n; i++) {
            if(a[i] > pivot) {
                result[idx] = a[i];
                idx++;
            }
        }

        for(int i: result)
            cout << i << " ";
}


void quick_sort(vector<int>&arr, int low, int high) {
    if(low >= high) return;

    int pivot = partition(arr, low, high);

    quick_sort(arr, low, pivot);
    quick_sort(arr, pivot + 1, high);
}


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


/*

int arr[] = new int[n];

int arr[][] = new int[n][m];


3 4
1 2 3 4
9 10 11 12 
5 6 7 8

0 1 2 3
8 

Scanner sc = new Scanner();
int n = sc.nextInt();
int m = sc.nextInt();

int arr[][] = new int[n][m];

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) 
        arr[i][j] = sc.nextInt();

int min = arr[0][0];

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (min > arr[i][j])
            min = arr[i][j];

for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) 
        System.out.print(arr[i][j] - min + " " );
    System.out.println("");
}







int mx = 0;

for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++)
        sum += arr[i][j];

    if (sum > mx)
        mx = sum;
}

System.out.println(mx);




5 
5 2 3 4 5

0 1 2 3 4


int n = sc.nextInt();

int arr[] = new int[n];
for (int i = 0; i < n; i++) 
    arr[i] = sc.nextInt();

int min = arr[0];

for (int i = 0; i < n; i++)
    if (arr[i] < min)
        min = arr[i];

for (int i = 0; i < n; i++)  
    System.out.print(arr[i] - min + " ");


*/