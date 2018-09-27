#include<bits/stdc++.h>
using namespace std;

struct node
{
	struct node *left ;
	int data ;
	struct node *right;
};

void bfs(struct node *root)
{
	queue<struct node *> q;
	q.push(root);

	while(!q.empty())
	{
		struct node *temp = q.front();
		q.pop();

		cout << temp->data << " " ;

		if(temp->left != NULL)
			q.push(temp->left);

		if(temp->right != NULL)
			q.push(temp->right);
	} 
}

struct node * NewNode(int value)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->left = NULL;
	temp->data = value;
	temp->right = NULL;

	return temp;
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
	root->right->left = NewNode(22);

	bfs(root);

	return 0;

}