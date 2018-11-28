 
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


void afis(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		afis(root->left); 
		cout<<root->key<<'\n';
		afis(root->right); 
	} 
}

void afis_inter(struct node *root,int k1,int k2)
{
    if(root!=NULL)
    {
    if( root->key>k1 && root->key<k2)
        cout<<root->key<<" ";
    if( root->key<k2)
        afis_inter(root->right,k1,k2);
    if(root->key>k1)
        afis_inter(root->left,k1,k2);
    }
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
    
    /// Cautare in interval k1 < x < k2
    int k1=30,k2=80;
    cout<<"@";
    afis_inter(root,k1,k2);
	return 0; 
} 
