// C++ program for Huffman Coding
#include <bits/stdc++.h>
using namespace std;
//vector< pair<char,string> >vs;
// A Huffman tree node
struct MinHeapNode {

	// One of the input characters
	char data;

	// Frequency of the character
	unsigned freq;

	// Left and right child pointer
	MinHeapNode *left, *right;

    ///initialize
	MinHeapNode(char c, unsigned f)

	{
		left = right = NULL;
		data = c;
		freq = f;
	}
};

// For comparison of
// two heap nodes (needed in min heap)
struct compare {

	bool operator()(MinHeapNode* l, MinHeapNode* r)

	{
		return (l->freq > r->freq);
	}
};

// Prints huffman codes from
// the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, string str)
{

	if (!root)
		return;

	if (root->data != '$'){
		cout << root->data << ": " << str << "\n";
		//char ch = root->data;
		//vs.push_back(make_pair(ch,str));
	}

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
	struct MinHeapNode *Left, *Right, *Top;

	// Create a min heap & inserts all characters of data[]
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));

	// Iterate while size of heap doesn't become 1
	while (minHeap.size() != 1) {

		// Extract the two minimum
		// freq items from min heap
		Left = minHeap.top();
		minHeap.pop();

		Right = minHeap.top();
		minHeap.pop();

		// Create a new internal node with
		// frequency equal to the sum of the
		// two nodes frequencies. Make the
		// two extracted node as left and right children
		// of this new node. Add this node
		// to the min heap '$' is a special value
		// for internal nodes, not used
		Top = new MinHeapNode('$', Left->freq + Right->freq);

		Top->left = Left;
		Top->right = Right;

		minHeap.push(Top);
	}

	// Print Huffman codes using
	// the Huffman tree built above
	printCodes(minHeap.top(), "");
}

// Driver program to test above functions
int main()
{

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	HuffmanCodes(arr, freq, size);
	/*
	sort(vs.begin(),vs.end());
	for(int i=0;i<vs.size();i++)
    {
        cout << vs[i].first << ' ' << vs[i].second << '\n';
    }*/

	return 0;
}

