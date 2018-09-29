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
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->left = NULL;
	temp->right = NULL;
	temp->data = value;

	return temp;
}

void Inorder(struct node *root)
{
	if(!root) return;

	Inorder(root->left);
	cout << root->data << " " ;
	Inorder(root->right);
}


void deleterightmost(struct node *root, struct node *dnode)
{
	queue<struct node *> q;
	q.push(root);

	while(!q.empty())
	{
		struct node *temp = q.front();
		q.pop();

		if(temp->right != NULL)
		{				
			if(temp->right == dnode)
			{
				temp->right = NULL;
				free(dnode);
			}
			else q.push(temp->right);
		}


		if(temp->left != NULL)
		{
			if(temp->left == dnode)
			{
				temp->left = NULL;
				free(dnode);
			}
			else q.push(temp->left);
		}
	}

}


void deletion(struct node *root, int key)
{
	queue<struct node*> q;
	q.push(root);

	struct node *temp ;
	struct node *key_node = NULL;

	while(!q.empty())
	{
		temp = q.front();
		q.pop();

		if(temp->data == key)
			key_node = temp;
		
		if(temp->left != NULL) q.push(temp->left);
		if(temp->right != NULL) q.push(temp->right);
	}

	key_node->data = temp->data ;
	deleterightmost(root,temp);
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


	cout << "tree before deletion " << endl;
	Inorder(root);

	cout << "tree after deletion" << endl;
	deletion(root, 22);
	Inorder(root);

	return 0;
}