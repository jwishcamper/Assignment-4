#include <iostream>
using namespace std;

template <class T>
struct node{
	T data;
	node<T> *left, *right;
};
template <class T>
class BST{
		node<T>* root;
		void insert(node<T>*&,T&);
		void printPreOrder(node<T>*);
		void printPostOrder(node<T>*);
		void printInOrder(node<T>*);
		T search(node<T>*, T&);
		void deleteNode(node<T>*&, T&);
		int height(node<T>*);
		T findMax(node<T>*,T&);
		T findMin(node<T>*,T&);
		int sumValues(node<T>*);
		int countNodes(node<T>*);
		int countParents(node<T>*);
		int max(int,int);
	public:
		BST(){root=NULL;}
		void insert(T&);
		void printPreOrder();
		void printInOrder();
		void printPostOrder();
		T search(T&);
		void deleteNode(T&);
		int height();
		T findMax(T&);
		T findMid(T&);
		T findMin(T&);
		int sumValues();
		int countNodes();
		int countParents();
};
template <class T>
int BST<T>::max(int x, int y){
	if(x>y)
		return x;
	else 
		return y;
}
template <class T>
int BST<T>::height(){
	return height(root);
}
template <class T>
int BST<T>::height(node<T>* p){
	if(p==NULL)
		return -1;
	else
		return 1 + max(height(p->left),height(p->right));
}
template <class T>
int BST<T>::countNodes(){
	return countNodes(root);
}
template <class T>
int BST<T>::countNodes(node<T>* p){
	if(p==NULL)
		return 0;
	else
		return 1+countNodes(p->left)+countNodes(p->right);
}
template <class T>
int BST<T>::countParents(){
	return countParents(root);
}
template <class T>
int BST<T>::countParents(node<T>* p){
	if(p==NULL)
		return 0;
	else if(p->left!=NULL||p->right!=NULL)
		return 1+countParents(p->left)+countParents(p->right);
}
template <class T>
int BST<T>::sumValues(){
	return sumValues(root);
}
template <class T>
int BST<T>::sumValues(node<T>* p){
	if(p==NULL)
		return 0;
	else
		return p->data+sumValues(p->left)+sumValues(p->right);
}
template <class T>
void BST<T>::deleteNode(T& item){
	deleteNode(root,item);
}
template <class T>
void BST<T>::deleteNode(node<T>*& p, T& item){
	if(p==NULL)
		return;
	if(item<p->data)
		deleteNode(p->left,item);
	else if(item>p->data)
		deleteNode(p->right,item);
	else{
		if(p->left!=NULL&&p->right!=NULL){ //delete node with 2 children
			T max = findMax(p->left,item);
			p->data=max;
			deleteNode(p->left,max);
		}
		else { //not 2 children
			node<T>* q=p;
			if(p->left!=NULL) //delete node with 1 left child
				p=p->left;
			else if(p->right!=NULL) //delete node with 1 right child
				p=p->right;
			else //delete leaf node
				p=NULL;
			delete q;
		}
	}
}
template <class T>
T BST<T>::search(T& item){
	return search(root, item);
}
template <class T>
T BST<T>::search(node<T>* p, T& item){
	if(p==NULL)
		return item; 
	else if(item<p->data)
		return search(p->left,item);
	else if(item>p->data)
		return search(p->right,item);
	else
		return p->data;
}
template <class T>
T BST<T>::findMax(T& e){
	return findMax(root,e);
}
template <class T>
T BST<T>::findMax(node<T>* p,T& e){
	if(p==NULL)
		return e;
	else if(p->right==NULL)
		return p->data;
	else
		return findMax(p->right,e);
}
template <class T>
T BST<T>::findMid(T& e){
	return root->data;
}
template <class T>
T BST<T>::findMin(T& e){
	return findMin(root,e);
}
template <class T>
T BST<T>::findMin(node<T>* p,T& e){
	if(p==NULL)
		return e;
	else if(p->left==NULL)
		return p->data;
	else
		return findMin(p->left,e);
}
template <class T>
void BST<T>::insert(T& item){
	insert(root,item);
}
template <class T>
void BST<T>::insert(node<T>*& p,T& item){
	if(p==NULL){
		p=new node<T>;
		p->data=item;
		p->left=NULL;
		p->right=NULL;
	}
	else if(item<p->data)
		insert(p->left,item);
	else
		insert(p->right,item);
}
template <class T>
void BST<T>::printPreOrder(){
	printPreOrder(root);
}
template <class T>
void BST<T>::printPreOrder(node<T>* p){
	if(p!=NULL){
		cout<<p->data;
		printPreOrder(p->left);
		printPreOrder(p->right);
	}
}
template <class T>
void BST<T>::printPostOrder(){
	printPostOrder(root);
}
template <class T>
void BST<T>::printPostOrder(node<T>* p){
	if(p!=NULL){
		printPostOrder(p->left);
		printPostOrder(p->right);
		cout<<p->data;
	}
}
template <class T>
void BST<T>::printInOrder(){
	printInOrder(root);
}
template <class T>
void BST<T>::printInOrder(node<T>* p){
	if(p!=NULL){
		printInOrder(p->left);
		cout<<p->data;
		printInOrder(p->right);
	}
}