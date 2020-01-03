#include "PassengerTree.h"

int PassengerTree::getNodeHeight(node *root)
{
	if (root != NULL) {

		int Hleft = getNodeHeight(root->left);
		int	HRight = getNodeHeight(root->right);

		if (Hleft >= HRight)
			return  1+Hleft;
		else
			return  1 + HRight;
	}
	return 0;
}

int PassengerTree::calcBalanceFactor(node *root)
{
	int Hleft = getNodeHeight(root->left);
	int HRight = getNodeHeight(root->right);
	return  Hleft - HRight;
}

node * PassengerTree::RR(node * new_node)
{
	node *temp;
	temp = new_node->right;
	new_node->right = temp->left;
	temp->left = new_node;

	return temp;
}

node * PassengerTree::LL(node *new_node)
{
	node *temp;
	temp = new_node->left;
	new_node->left = temp->right;
	temp->right = new_node;

	return temp;
}

node * PassengerTree::LR(node *new_node)
{
	 node *temp;
	 temp = new_node->left;
	new_node->left = RR(temp);

	return LL(new_node);
}



node * PassengerTree::RL(node *new_node)
{
	node *temp;
	temp = new_node->right;
	new_node->right = LL(temp);

	return RR(new_node);
}

node * PassengerTree::balanceTree(node *root)
{

	if (calcBalanceFactor(root) < -1) {
		if (calcBalanceFactor(root->right) > 0)
			root = RL(root);
		else
			root = RR(root);
	}
	else if (calcBalanceFactor(root) > 1) {
		if (calcBalanceFactor(root->left) > 0)
			root = LL(root);
		else
			root = LR(root);
	}
	UpdateHeight(root);
	return root;
}

void PassengerTree::UpdateHeight(node * tree)
{
	tree->height = getNodeHeight(tree);
	if (tree->left != NULL)
		UpdateHeight(tree->left);

	if (tree->right != NULL)
		UpdateHeight(tree->right);
}

node* PassengerTree::min(node* tree)
{
	node* temp = tree;

	while (temp->left != NULL)
		temp = temp->left;

	return temp;
}

node * PassengerTree::insertNode(node *root, int id)
{

	
	if (root != NULL)
	{
		if (id < root->passengerID) {
			root->left = insertNode(root->left, id);
			root = balanceTree(root);
		}
		else 
		{
			root->right = insertNode(root->right, id);
			root = balanceTree(root);
		}
	}
	else
	{
		root = new node;
		root->passengerID = id;
		root->left = NULL;
		root->right = NULL;
		numOfNodes += 1;
		root->height = 1;
		return root;
	}

	UpdateHeight(root);

	return root;
}

bool PassengerTree::IsExist(int id)
{
	node* root = treeRoot;

	while (root != NULL)
	{
		if (root->passengerID < id)
			root = root->right;
		else if (root->passengerID > id)
			root = root->left;
		else
			return true;

	}
	return false;
}

void PassengerTree::displayTree()
{
	preorder(treeRoot);
}

void PassengerTree::preorder(node *tree)
{
	if (tree == NULL)
		return ;
	cout << tree->passengerID << "  h: "<<tree->height<<endl;

	if (tree->left != NULL)
	preorder(tree->left);

	if (tree ->right != NULL)
	preorder(tree->right);
}


int PassengerTree::HeghitOfTree()
{
	
	return getNodeHeight(treeRoot);
}

PassengerTree::~PassengerTree()
{
	if (treeRoot!=NULL)
		RemoveTree(treeRoot);
}

void PassengerTree::RemoveTree(node* root)
{
	if (root != NULL)
	{
		RemoveTree(root->left);
		RemoveTree(root->right);
		delete root;
	}

}

node* PassengerTree::RemoveNode(node * del,int id)
{

		if (del == NULL)
			return del;

		if (id < del->passengerID)
			del->left = RemoveNode(del->left, id);

		else if (id > del->passengerID)
			del->right = RemoveNode(del->right, id);
		else
		{
			if ((del->left == NULL) || (del->right == NULL))
			{
				node *temp = del->left ? del->left : del->right;

				if (temp == NULL)
				{
					temp = del;
					del = NULL;
				}
				else
					*del = *temp;
				free(temp);
			}
			else
			{
				node* temp = min(del->right);
				del->passengerID = temp->passengerID;
				del->right = RemoveNode(del->right, temp->passengerID);
			}
		}

		if (del == NULL)
			return del;

		UpdateHeight(del);
		int balance = calcBalanceFactor(del);
		if (balance > 1 && calcBalanceFactor(del->left) >= 0)
			return LL(del);

		if (balance > 1 && calcBalanceFactor(del->left) < 0)
		{
			del->left = RR(del->left);
			return LL(del);
		}

		if (balance < -1 && calcBalanceFactor(del->right) <= 0)
			return RR(del);

		if (balance < -1 && calcBalanceFactor(del->right) > 0)

		{
			del->right = LL(del->right);
			return RR(del);
		}

		return del;
	
}

int PassengerTree::Check_(int id)
{
	int count = 0;
	node* root = treeRoot;
	
		while (root != NULL) 
		{
			if (root->passengerID < id)
			{
				root = root->right;
				count++;
			}
			else if (root->passengerID > id)
			 {
				root = root->left;
				count++;
			 }
			else
			{
				return count + 1;
			}
		}
		return treeRoot->height+1;
		
	
}



