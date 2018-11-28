 
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

struct node* inserare(struct node* node, int key) 
{ 
	if (node == NULL) 
        return newNode(key); 
	if (key < node->key) 
		node->left = inserare(node->left, key); 
	else if (key > node->key) 
		node->right = inserare(node->right, key); 
	return node; 
} 

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
    while (current->left != NULL) 
        current = current->left; 
    return current; 
} 

struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL)
     return root; 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
    else
    { 
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
        struct node* temp = minValueNode(root->right); 
        root->key = temp->key; 
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

struct node* cauta(struct node* root, int key) 
{ 
	if (root == NULL || root->key == key) 
	    return root; 
	if (root->key < key) 
	    return cauta(root->right, key); 
    else
	    return cauta(root->left, key); 
} 

int gaseste_max(struct node* root) 
{
    if(root->right == NULL)
        return root->key;
    else
        return gaseste_max(root->right);
}


int main() 
{ 
	struct node *root = NULL; 

    /// INSERARE
	root = inserare(root, 50); 
	inserare(root, 33); 
	inserare(root, 21); 
	inserare(root, 40); 
	inserare(root, 76); 
	inserare(root, 61);     
	inserare(root, 89); 

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
