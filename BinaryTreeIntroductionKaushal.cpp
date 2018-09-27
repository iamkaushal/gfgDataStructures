#include<bits/stdc++.h>
using namespace std;

struct node 
{
	struct node *left;
	int data;
	struct node *right;
};



int main()
{
	#ifndef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	struct node *root = (struct node*)malloc(sizeof(struct node));
	root->data = 1;
	root->left = root->right = NULL;

	return 0;
}