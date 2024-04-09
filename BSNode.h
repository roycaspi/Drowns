#pragma once
template <class T>
class BSNode
{
private:
	T value;
	BSNode<T>* left;
	BSNode<T>* right;
public:
	BSNode(const T& v, BSNode<T>* l, BSNode<T>*r):value(v), left(l), right(r) {}
	~BSNode() {}
	T& getValue() { return value; }
	void setValue(const T& newvalue) { value = newvalue; }
	BSNode<T>* getLeft() { return left; }
	const BSNode<T>* getLeft() const { return left; }
	void setLeft(BSNode<T>* newn) { left = newn; }
	BSNode<T>* getRight() { return right; }
	const BSNode<T>* getRight() const { return right; }
	void setRight(BSNode<T>* newn) { right = newn; }
};

