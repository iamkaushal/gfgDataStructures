#include<bits/stdc++.h>
using namespace std;

struct node
{
	struct node *left;
	int data ;
	struct node *right;
};

struct node* NewNode(int value)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->left = NULL;
	temp->data = value;
	temp->right = NULL;

	return temp;
}

void preorder(struct node* root)
{
	if(root == NULL) return;

	cout << root->data << " ";
	if(root->left != NULL) preorder(root->left);
	if(root->right != NULL) preorder(root->right);
}

int main()
{
	#ifndef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	struct node *root = NewNode(5);
	root->left = NewNode(11);
	root->left->left = NewNode(7);
	root->left->right = NewNode(9);
	root->right = NewNode(10);
	root->right->right = NewNode(22);
	root->right->left = NewNode(23);

	preorder(root);

	return 0;
}