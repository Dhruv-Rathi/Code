
#include<iostream>
using namespace std;
#define INT_MIN -1e9
#define INT_MAX 1e9

class Node
{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
};
 
int max(int a, int b);
 
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially
                      // added at leaf
    return(node);
}
 
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
 
    // Return new root
    return x;
}
 
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    // Update heights
    x->height = max(height(x->left),   
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
Node* insert(Node* node, int key)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                        height(node->right));
 
    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
 
void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int findMax(Node* root) 
{ 
    // Base case 
    if (root == NULL) 
    return INT_MIN; 
   
    int res = root->key; 
    int lres = findMax(root->left); 
    int rres = findMax(root->right); 
    if (lres > res) 
    res = lres; 
    if (rres > res) 
    res = rres; 
    return res; 
}

int findMin(Node *root){
	if(root == NULL) return INT_MAX;

	int res = root->key;
	int lres = findMin(root->left);
	int rres = findMin(root->right);
	if(lres<res)
		res = lres;
	if(rres<res)
		res = rres;
	return res;
}
int counNodes(struct Node *root)
{
    struct Node *current, *pre;
  
    // Initialise count of nodes as 0
    int count = 0;
  
    if (root == NULL)
        return count;
  
    current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            // Count node if its left is NULL
            count++;
  
            // Move to its right
            current = current->right;
        }
        else
        {
            /* Find the inorder predecessor of current */
            pre = current->left;
  
            while (pre->right != NULL &&
                   pre->right != current)
                pre = pre->right;
  
            /* Make current as right child of its
               inorder predecessor */
            if(pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
  
            /* Revert the changes made in if part to
               restore the original tree i.e., fix
               the right child of predecessor */
            else
            {
                pre->right = NULL;
  
                // Increment count if the current
                // node is to be visited
                count++;
                current = current->right;
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
  
    return count;
}
int findMedian(struct Node *root)
{
   if (root == NULL)
        return 0;
  
    int count = counNodes(root);
    int currCount = 0;
    struct Node *current = root, *pre, *prev;
  
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            // count current node
            currCount++;
  
            // check if current node is the median
            // Odd case
            if (count % 2 != 0 && currCount == (count+1)/2)
                return prev->key;
  
            // Even case
            else if (count % 2 == 0 && currCount == (count/2)+1)
                return (prev->key);
  
            // Update prev for even no. of nodes
            prev = current;
  
            //Move to the right
            current = current->right;
        }
        else
        {
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
  
            /* Make current as right child of its inorder predecessor */
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
  
            /* Revert the changes made in if part to restore the original
              tree i.e., fix the right child of predecessor */
            else
            {
                pre->right = NULL;
  
                prev = pre;
  
                // Count current node
                currCount++;
  
                // Check if the current node is the median
                if (count % 2 != 0 && currCount == (count+1)/2 )
                    return current->key;
  
                else if (count%2==0 && currCount == (count/2)+1)
                    return (prev->key);
  
                // update prev node for the case of even
                // no. of nodes
                prev = current;
                current = current->right;
  
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
}
 
int main(){
	cout<<"1. Insert\n2. Find max\n3. Find min\n4. Find median\n5. Print in non-decreasing order\n6. Exit\n";
	Node *root = NULL;
	while(1){
		int ch; cin>>ch;
		int e;
		if(ch == 1){
            cout<<"Write element to be inserted: ";
            cin>>e;
            root  = insert(root, e);
            cout<<"List in non-increasing order: (";
            preOrder(root);
            cout<<")\n";
        } 
		else if(ch == 2){
            cout<<"Maximum: "<<findMax(root)<<'\n';
        }	
		
		else if(ch == 3){
            cout<<"Minimum: "<<findMin(root)<<'\n';
        }
		else if(ch == 4){
            cout<<"Median: "<<findMedian(root)<<'\n';
        }
		
		else if(ch == 5){cout<<"List in non-decreasing order: ";}
		else{cout<<"Program exits";
			return 0;
        }
	}
	
	
}	