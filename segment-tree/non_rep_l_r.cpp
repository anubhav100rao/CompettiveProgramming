// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 9;
const int N = 1e5 + 5;

// Merge sort of pair type for storing
// prev and next occurrences of element
vector<vector<pair<int, int> > > segtree(4 * N);

// Stores the occurrences
vector<pair<int, int> > occurrences(N);

// Finds occurrences
vector<set<int> > pos(N);

int n;

// Function to build merge sort tree
void build(int node = 0, int l = 0,
		int r = n - 1)
{

	// For leaf node, push the prev &
	// next occurrence of the lth node
	if (l == r) {
		segtree[node].push_back(occurrences[l]);
		return;
	}

	int mid = (l + r) / 2;

	// Left recursion call
	build(2 * node + 1, l, mid);

	// Right recursion call
	build(2 * node + 2, mid + 1, r);

	// Merging the left child and right child
	// according to the prev occurrence
	merge(segtree[2 * node + 1].begin(),
		segtree[2 * node + 1].end(),
		segtree[2 * node + 2].begin(),
		segtree[2 * node + 2].end(),
		back_inserter(segtree[node]));

	// Update the next occurrence
	// with prefix maximum
	int mx = 0;

	for (auto& i : segtree[node]) {

		// Update the maximum
		// next occurrence
		mx = max(mx, i.second);
        
		// Update the next occurrence
		// with prefix max
		i.second = mx;
	}
}

// Function to check whether an
// element is present from x to y
// with frequency 1
bool query(int x, int y, int node = 0,
		int l = 0, int r = n - 1)
{
	// No overlap condition
	if (l > y || r < x || x > y)
		return false;

	// Complete overlap condition
	if (x <= l && r <= y) {

		// Find the first node with
		// prev occurrence >= x
		auto it = lower_bound(segtree[node].begin(),
							segtree[node].end(),
							make_pair(x, -1));

		// No element in this range with
		// previous occurrence less than x
		if (it == segtree[node].begin())
			return false;

		else {

			it--;

			// Check if the max next
			// occurrence is greater
			// than y or not
			if (it->second > y)
				return true;
			else
				return false;
		}
	}

	int mid = (l + r) / 2;
	bool a = query(x, y, 2 * node + 1, l, mid);
	bool b = query(x, y, 2 * node + 2, mid + 1, r);

	// Return if any of the
	// children returned true
	return (a | b);
}

// Function do preprocessing that
// is finding the next and previous
// occurrences
void preprocess(int arr[])
{

	// Store the position of
	// every element
	for (int i = 0; i < n; i++) {
		pos[arr[i]].insert(i);
	}

	for (int i = 0; i < n; i++) {

		// Find the previous
		// and next occurrences
		auto it = pos[arr[i]].find(i);
		if (it == pos[arr[i]].begin())
			occurrences[i].first = -INF;

		else
			occurrences[i].first = *prev(it);

		// Check if there is no next occurrence
		if (next(it) == pos[arr[i]].end())

			occurrences[i].second = INF;
		else
			occurrences[i].second = *next(it);
	}

	// Building the merge sort tree
	build();
}

// Function to find whether there is a
// number in the subarray with 1 frequency
void answerQueries(int arr[],
				vector<pair<int, int> >& queries)
{
	preprocess(arr);

	// Answering the queries
	for (int i = 0; i < queries.size(); i++) {
		int l = queries[i].first - 1;
		int r = queries[i].second - 1;

		bool there = query(l, r);

		if (there == true)
			cout << "Yes\n";

		else
			cout << "No\n";
	}
}

// Driver Code
int main()
{
	int arr[] = { 1, 2, 1, 2, 3, 4 };
	n = sizeof(arr) / sizeof(arr[0]);

	vector<pair<int, int> > queries = { { 1, 4 }, { 1, 5 } };

	answerQueries(arr, queries);
}
