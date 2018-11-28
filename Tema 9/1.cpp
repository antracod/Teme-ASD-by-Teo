 
#include<stdio.h> 
#include<stdlib.h>
#include <iostream>

using namespace std;

struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 

 
struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

/* A utility function to inserare a new node with given key in BST */
struct node* inserare(struct node* node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left = inserare(node->left, key); 
	else if (key > node->key) 
		node->right = inserare(node->right, key); 

	/* return the (unchanged) node pointer */
	return node; 
} 

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
}   


void afis(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		afis(root->left); 
		cout<<root->key<<'\n';
		afis(root->right); 
	} 
}

// C function to search a given key in a given BST 
struct node* cauta(struct node* root, int key) 
{ 
	// Base Cases: root is null or key is present at root 
	if (root == NULL || root->key == key) 
	return root; 
	
	// Key is greater than root's key 
	if (root->key < key) 
	return cauta(root->right, key); 

	// Key is smaller than root's key 
	return cauta(root->left, key); 
} 

int gaseste_max(struct node* root) 
{
    if(root->right == NULL)
        return root->key;
    else
        return gaseste_max(root->right);
}


// Driver Program to test above functions 
int main() 
{ 
	struct node *root = NULL; 

    /// INSERARE
	root = inserare(root, 50); 
	inserare(root, 30); 
	inserare(root, 20); 
	inserare(root, 40); 
	inserare(root, 70); 
	inserare(root, 60); 
	inserare(root, 80); 

    /// AFISARE
	afis(root); 

    /// CAUTARE 
    if(cauta(root,20)!=NULL)
        cout<<"Gasit"<<'\n';
    else
        cout<<"Nu exista"<<'\n';
    
    if(cauta(root,21)!=NULL)
        cout<<"Gasit"<<'\n';
    else
        cout<<"Nu exista"<<'\n';

    /// Afisare maximum
    cout<<gaseste_max(root);


    /// Stergere Elememt
    deleteNode(root,40);
    afis(root);

	return 0; 
} 
