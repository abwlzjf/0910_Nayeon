#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

void GenerateArrayTree(int *tree) {
	int list[] = { 1,2,9,3,5,10,13,4,6,7,8,11,12,14,15 };
	for (int i = 0;i < 15;i++) {
		tree[i] = list[i];
	}

	for (int i = 0;i < 15;i++) {
		printf("%d ", tree[i]);
	}
	printf("\n\n");
}

void ArrayPreOrder(int* tree, int index) {
	if (index >= 15 || tree[index] == -1) {
		return;
	}
	printf("%d ", tree[index]);
	ArrayPreOrder(tree, 2 * index + 1);
	ArrayPreOrder(tree, 2 * index + 2);
}

void ArrayInOrder(int* tree, int index) {
	if (index >= 15 || tree[index] == -1) {
		return;
	}
	ArrayInOrder(tree, 2 * index + 1);
	printf("%d ", tree[index]);
	ArrayInOrder(tree, 2 * index + 2);
}

void ArrayPostOrder(int* tree, int index) {
	if (index >= 15 || tree[index] == -1) {
		return;
	}
	ArrayPostOrder(tree, 2 * index + 1);
	ArrayPostOrder(tree, 2 * index + 2);
	printf("%d ", tree[index]);
}

void ArrayOrders(int* tree) {
	ArrayPreOrder(tree,0);printf("\n");
	ArrayInOrder(tree,0);printf("\n");
	ArrayPostOrder(tree,0);printf("\n");
}

void PlaceNode(TreeNode* tree, int direction, int data) {
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->data = data;
	newNode->left = newNode->right = NULL;

	if (direction == 0) {
		tree->left = newNode;
	}
	else {
		tree->right = newNode;
	}
}

void GenerateLinkTree(TreeNode* root) {
	PlaceNode(root, 0, 2);
	PlaceNode(root, 1, 9);

	PlaceNode(root->left, 0, 3);
	PlaceNode(root->left, 1, 5);
	PlaceNode(root->right, 0, 10);
	PlaceNode(root->right, 1, 13);

	PlaceNode(root->left->left, 0, 4);
	PlaceNode(root->left->left, 1, 6);
	PlaceNode(root->left->right, 0, 7);
	PlaceNode(root->left->right, 1, 8);
	PlaceNode(root->right->left, 0, 11);
	PlaceNode(root->right->left, 1, 12);
	PlaceNode(root->right->right, 0, 14);
	PlaceNode(root->right->right, 1, 15);
}

void LinkPreOrder(TreeNode* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		LinkPreOrder(root->left);
		LinkPreOrder(root->right);
	}
}

void LinkInOrder(TreeNode* root) {
	if (root != NULL) {
		LinkInOrder(root->left);
		printf("%d ", root->data);
		LinkInOrder(root->right);
	}
}

void LinkPostOrder(TreeNode* root) {
	if (root != NULL) {
		LinkPostOrder(root->left);
		LinkPostOrder(root->right);
		printf("%d ", root->data);
	}
}

void LinkOrders(TreeNode* root) {
	LinkPreOrder(root);printf("\n");
	LinkInOrder(root);printf("\n");
	LinkPostOrder(root);
}
int main() {
	int arr[15];
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = 1;

	GenerateArrayTree(arr);
	GenerateLinkTree(root);

	ArrayOrders(arr);
	printf("\n");
	LinkOrders(root);
}