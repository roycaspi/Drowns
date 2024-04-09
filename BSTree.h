#pragma once
#include "BSNode.h"
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

template <class T>
class BSTree
{
private:
	BSNode<T>* root;
	void rec_insert(BSNode<T>* root, const T& value) //recursive insert
	{
		if (root->getValue() > value) //go left
		{
			if (root->getLeft() == NULL)
			{
				root->setLeft(new BSNode<T>(value, NULL, NULL));
			}
			else
				rec_insert(root->getLeft(), value);
		}
		else  if (root->getValue() < value) //go right
		{
			if (root->getRight() == NULL)
			{
				root->setRight(new BSNode<T>(value, NULL, NULL));
			}
			else
				rec_insert(root->getRight(), value);
		}
		else
		{
			root->setValue(value);
		}
	}
	T* rec_search(BSNode<T>* root, const T& value) //recursive search
	{
		if (root == NULL)
			return NULL;
		if (root->getValue() > value) //go left
		{
			return rec_search(root->getLeft(), value);
		}
		else  if (root->getValue() < value) //go right
		{
			return rec_search(root->getRight(), value);
		}
		else
		{
			return &root->getValue();
		}
	}
	T* rec_min(BSNode<T>* root) //recursive get min
	{
		if (root->getLeft() == NULL)
			return &root->getValue();
		else
			return rec_min(root->getLeft());
	}
	T* rec_max(BSNode<T>* root) //recursive get max
	{
		if (root->getRight() == NULL)
			return &root->getValue();
		else
			return rec_max(root->getRight());
	}
	bool rec_remove(BSNode<T>* root, BSNode<T>* parent, const T& value) //recursive remove
	{
		if (root == NULL)
		{
			return false;
		}
		else  if (root->getValue() == value)
		{
			if (root->getLeft() == NULL && root->getRight() == NULL) //the node is a leaf
			{
				if (parent != NULL)
				{
					if (parent->getLeft() == root)
						parent->setLeft(NULL);
					if (parent->getRight() == root)
						parent->setRight(NULL);
				}
				else
				{
					this->root = NULL;
				}
				delete root;
			}
			else if (root->getLeft() != NULL && root->getRight() != NULL) //the node has two sons
			{
				T* succ = rec_min(root->getRight());
				remove(*succ);
				root->setValue(*succ);
			}
			else //the node has only one son
			{
				BSNode<T>* child = (root->getLeft() != NULL) ? root->getLeft() : root->getRight();
				if (parent != NULL)
				{
					if (root == parent->getLeft())
					{
						parent->setLeft(child);
					}
					else
						parent->setRight(child);
				}
				else
					this->root = child;
				delete root;
			}
			return true;
		}
		else if(root->getValue() < value)
		{
			return rec_remove(root->getRight(), root, value);
		}
		else if (root->getValue() > value)
		{
			return rec_remove(root->getLeft(), root, value);
		}
	}
	void rec_clear(BSNode<T>* root) //recursive clear
	{
		if (root->getLeft() != NULL)
		{
			rec_clear(root->getLeft());
		}
		if (root->getRight() != NULL)
			rec_clear(root->getRight());
		delete &root->getValue();
		delete root;
		return;
	}
	void rec_print(BSNode<T>* root) const //recursive print
	{
		if (root->getLeft() != NULL)
		{
			rec_print(root->getLeft());
		}
		cout << *root->getValue() << endl;
		if (root->getRight() != NULL)
		{
			rec_print(root->getRight());
		}
	}
	void rec_size(BSNode<T>* root, int& size) const //recursive get size
	{
		if (root->getLeft() != NULL)
		{
			rec_print(root->getLeft());
		}
		if (root->getRight() != NULL)
		{
			rec_print(root->getRight());
		}
		size++;
	}
public:
	BSTree():root(NULL) {}
	~BSTree() { clear(); }
	void insert(const T& value) 
	{ 
		if (root == NULL)
			root = new BSNode<T>(value, NULL, NULL);
		else
			rec_insert(root, value);	
	}
	BSNode<T>* getRoot() const { return root; }
	T* search(const T& value)
	{
		return rec_search(root, value);
	}
	T* min()
	{
		if (root == NULL)
			return NULL;
		else
			return rec_min(root);
	}
	T* max()
	{
		if (root == NULL)
			return NULL;
		else
			return rec_max(root);
	}
	bool remove(const T& value)
	{
		return rec_remove(root, NULL, value);
	}
	void clear()//todo: check if correct
	{
		if (root != NULL)
		{
			rec_clear(root);
			root = NULL;
		}
		else
			return;
	}
	void print() const //todo: check if correct
	{
		if (root != NULL)
			rec_print(root);
		else
			cout << "Empty" << endl;
	}
	int size() const//todo: finish
	{
		int* size;
		if (root == NULL)
			return 0;
		else
			rec_size(size);
	}
};

