#include<bits/stdc++.h>
using namespace std;

struct node
{
	struct node *left;
	int data;
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


void inorderdfs(struct node *root)
{
	if(root == NULL) return;

	if(root->left != NULL)
		inorderdfs(root->left);

	cout << root->data << " ";

	if(root->right != NULL)
		inorderdfs(root->right);
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

	inorderdfs(root);


	return 0;
}