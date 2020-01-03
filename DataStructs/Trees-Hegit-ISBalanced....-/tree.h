#ifndef TREE_H
#define TREE_H

#include<iostream>
using namespace std;

// represents a node in a binary tree
template<class T>
class tnode {

private:
	T value;
	tnode<T> *left, *right;
public:
	//default constructor
	tnode(T v) :value(v), left(NULL), right(NULL)
	{}

	//constructor
	tnode(T v, tnode *lptr, tnode *rptr) :value(v), left(lptr), right(rptr)
	{}


	//accessors
	T getValue() { return value; }
	void setValue(T newValue) { value = newValue; }

	void setLeft(tnode *l) { left = l; }
	void setRight(tnode *r) { right = r; }

	tnode<T> *getLeft() { return left; }
	tnode<T> *getRight() { return right; }

	bool isLeaf() { return left == NULL && right == NULL; }

	//traversal methods
	void inorder();
	void preorder();
	void postorder();

	int depth();

	bool isComplete();
	bool isPerfect();


	int height();
	int countLeaves();
	int countInternalNodes();
	bool isHeightBalance();

};

template <class T>
void tnode<T>::inorder() {
	if (left != NULL)	left->inorder();
	cout << value << " ";
	if (right != NULL)right->inorder();
}

template <class T>
void tnode<T>::preorder() {
	cout << value << " ";
	if (left != NULL)	left->preorder();
	if (right != NULL) right->preorder();

}
template <class T>
void tnode<T>::postorder() {
	if (left != NULL)	left->postorder();
	if (right != NULL)right->postorder();
	cout << value << " ";
}


template <class T>
int tnode<T>::depth() {
	if (this->isLeaf()==true)
		return 0;

	int lDepth = (left == NULL) ? -1 : left->depth();
	int rDepth = (right == NULL) ? -1 : right->depth();

	return (lDepth > rDepth) ? lDepth + 1 : rDepth + 1;
}

template <class T>
bool tnode<T>::isComplete() {
	int h = depth();   //class method
	if (h == 0) return true;
	if (h == 1) return !(left == NULL);
	//the depth is 2 and up:
	bool has2Sons = (!(left == NULL) && !(right == NULL));
	bool case1 = false, case2 = false;
	if (has2Sons) {
		case1 = ((left->depth() == h - 1) && left->isComplete() &&
			(right->depth() == h - 2) && right->isPerfect());

		case2 = ((left->depth() == h - 1) && left->isPerfect() &&
			(right->depth() == h - 1) && right->isComplete());

	}
	return case1 || case2;
}

template <class T>
bool tnode<T>::isPerfect() {
	int h = depth();   //class method
	if (h == 0) return true;
	if (h == 1) return  !(left == NULL) && !(right == NULL);

	return (!(left == NULL) && (left->depth() == h - 1) && left->isPerfect() &&
		!(right == NULL) && (right->depth() == h - 1) && right->isPerfect());
}





template<class T>
inline int tnode<T>::countLeaves()
{
	int count = 0;
	if (this == NULL)
		return 0;
	if (this->isLeaf())
		return 1;
	return right->countLeaves() + left->countLeaves();
}

template<class T>
inline int tnode<T>::countInternalNodes()
{
	if (this==NULL) 
	return 0;
	if (this->isLeaf() == false)
		return 1 + right->countInternalNodes() + left->countInternalNodes();
	else
		return 0;
	
}



template<class T>
inline bool tnode<T>::isHeightBalance()
{
	int HighLeft, HighRight,abselot;

	if (this == NULL)
		return true;

	HighLeft = left->height();
	HighRight = right->height();
	abselot = abs(HighRight - HighLeft);

	if (abselot <= 1) {
		if (left->isHeightBalance() && right->isHeightBalance())
			return true;
		else
			return false;
	}
	else
		return false;
	
}

template<class T>
inline int tnode<T> :: height()//help function to  isHeightBalance()
{

	int HighLeftSubTree, HighRightSubTree, maximum;

	if (this == NULL)
		return 0;

	HighRightSubTree = right->height(); // the height of the right subtree
	HighLeftSubTree = left->height(); // the height of the left subtree

	if (HighRightSubTree >= HighLeftSubTree)//choose the maximum height of the two subtrees
		maximum = HighRightSubTree;
	else
		maximum = HighLeftSubTree;
	return 1 + maximum;//1 for the root
		

}


//--------------------------------------------------------------------------------//

template <typename T>
void deleteTree(tnode<T> *t)
{
	// postorder scan. delete left and right
	// subtrees of t and then node t
	if (t != NULL)
	{
		deleteTree(t->getLeft());
		deleteTree(t->getRight());
		delete t;
	}
}

#endif
