#include <algorithm>
#include<iostream>
#include <fstream>
#include <string>

using namespace std;


struct node {
	int passengerID;
	struct node *left;
	struct node *right;
	int height;
};
class PassengerTree {
public:
	node* treeRoot;
	int numOfNodes;

	int getNodeHeight(node *);
	int calcBalanceFactor(node *);
	node *RR(node *);
	node *LL(node *);
	node *LR(node*);
	node *RL(node *);
	node * balanceTree(node *);
	void UpdateHeight(node *);

	void RemoveTree(node* root);
	node* RemoveNode(node* del,int id);

	int Check_(int id);

	node* min(node* tree);

	node * insertNode(node*, int);
	bool IsExist(int id);
	void displayTree();
	void preorder(node *);

	int HeghitOfTree();

	~PassengerTree();

	PassengerTree() {
		numOfNodes = 0;
		treeRoot = NULL;
		
	}
};