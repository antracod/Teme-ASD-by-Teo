 
#include<stdio.h> 
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

struct node 
{ 
	char key[1000]; 
	struct node *left, *right; 
}; 

struct node *newNode(char item[1000],int n) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	
    for(int i=0;i<n;i++)
    {
        temp->key[i] = item[i];
    }
	temp->left = temp->right = NULL; 
	return temp; 
} 

struct node* inserare(struct node* node, char key[1000],int n) 
{ 
	if (node == NULL) 
        return newNode(key,n); 
	if (strcmp(key, node->key)<=0) 
		node->left = inserare(node->left, key , n); 
	else if (strcmp(key , node->key)>0) 
		node->right = inserare(node->right, key , n); 
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

int main() 
{ 
	struct node *root = NULL; 
    int n=3;
    /// INSERARE
	root = inserare(root, "abc", 3); 
	inserare(root, "bca" , 3); 
	inserare(root, "efc" , 3); 
	inserare(root, "ads" , 3); 
	inserare(root, "pas", 3); 
	inserare(root, "asd" , 3);     
	inserare(root, "pas" , 3); 

    /// AFISARE
    afis(root);

	return 0; 
} 
