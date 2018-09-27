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

void Insert(struct node *root, int value)
{
	queue<struct node* > q;
	q.push(root);

	while(!q.empty())
	{
		struct node *temp = q.front();
		q.pop();

		if(!temp->left)
		{
			temp->left = NewNode(value);
			break;
		}

		else q.push(temp->left);

		if(!temp->right)
		{
			temp->right = NewNode(value);
			break;
		}

		else q.push(temp->right);
	}
}

void Inorder(struct node *root)
{
	if(!root) return;

	Inorder(root->left);
	cout << root->data << " " ;
	Inorder(root->right);
}


int main()
{
	#ifndef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	struct node *root = NewNode(10);
	// root->left = NewNode(11);
	// root->left->left = NewNode(7);

	cout << "Inorder Before Insertion" << endl;

	Inorder(root);

	Insert(root, 11);
	Insert(root, 7);
	Insert(root, 9);
	Insert(root, 15);
	Insert(root, 8);
	
	cout << endl << "Inorder after Insertion" << endl;

	Inorder(root);

	return 0;
}