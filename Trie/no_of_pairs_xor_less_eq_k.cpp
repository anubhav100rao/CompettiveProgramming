// C++ program to implement
// the above approach

#include <bits/stdc++.h>
using namespace std;

// Structure of Trie
struct TrieNode
{
	// Stores binary representation
	// of numbers
	TrieNode *child[2];

	// Stores count of elements
	// present in a node
	int cnt;
	
	// Function to initialize
	// a Trie Node
	TrieNode() {
		child[0] = child[1] = NULL;
		cnt = 0;
	}
};


// Function to insert a number into Trie
void insertTrie(TrieNode *root, int N) {
	
	// Traverse binary representation of X
	for (int i = 31; i >= 0; i--) {
		
		// Stores ith bit of N
		bool x = (N) & (1 << i);
		
		// Check if an element already
		// present in Trie having ith bit x
		if(!root->child[x]) {
			
			// Create a new node of Trie.
			root->child[x] = new TrieNode();
		}
		
		// Update count of elements
		// whose ith bit is x
		root->child[x]->cnt+= 1;
		
		// Update root
		root= root->child[x];
	}
}


// Function to count elements
// in Trie whose XOR with N
// less than K
int cntSmaller(TrieNode * root,
				int N, int K)
{
	
	// Stores count of elements
	// whose XOR with N less than K
	int cntPairs = 0;
	
	// Traverse binary representation
	// of N and K in Trie
	for (int i = 31; i >= 0 &&
					root; i--) {
									
		// Stores ith bit of N						
		bool x = N & (1 << i);
		
		// Stores ith bit of K
		bool y = K & (1 << i);
		
		// If the ith bit of K is 1
		if (y) {
			
			// If an element already
			// present in Trie having
			// ith bit (x)
			if(root->child[x]) {
					cntPairs +=
					root->child[x]->cnt;
			}
		
			root =
				root->child[1 - x];
		}
		
		// If the ith bit of K is 0
		else{
			
			// Update root
			root = root->child[x];
		}
	}
	return cntPairs;
}

// Function to count pairs that
// satisfy the given conditions
int cntSmallerPairs(int arr[], int N,
							int K) {
	
	// Create root node of Trie
	TrieNode *root = new TrieNode();
	
	// Stores count of pairs that
	// satisfy the given conditions
	int cntPairs = 0;
	
	// Traverse the given array
	for(int i = 0;i < N; i++){
		
		// Update cntPairs
		cntPairs += cntSmaller(root,
						arr[i], K);
		
		// Insert arr[i] into Trie
		insertTrie(root, arr[i]);
	}
	return cntPairs;
}

// Driver Code
int main()
{
	int arr[] = {3, 5, 6, 8};
	int K= 7;
	int N = sizeof(arr) / sizeof(arr[0]);
	
	cout<<cntSmallerPairs(arr, N, K);
}
