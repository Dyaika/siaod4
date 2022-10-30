#include "Tree.h"

Node* createNodes(int n)
{
	if (n <= 0) {
		return nullptr;
	}
	int nl, nr;
	nl = n / 2;//половина левая
	nr = n - nl - 1;//остаток за вычетом текущего элемента
	Node* cur = new Node;
	cur->data = rand() % 1000 / 2.1;
	cur->leftTree = createNodes(nl);
	cur->rightTree = createNodes(nr);
	return cur;
}

void printNodes(Node* root, int level, int L)
{
	if (root) {
		printNodes(root->rightTree, level + 1, L);
		for (int i = 0; i < level * L; i++) {
			cout << " ";
		}
		cout << root->data << "\n";
		printNodes(root->leftTree, level + 1, L);
	}
}

double sumTree(Node* root)
{
	double sum = 0.0;
	if (root) {
		sum += root->data;
		if (root->leftTree) {
			sum += sumTree(root->leftTree);
		}
		if (root->rightTree) {
			sum += sumTree(root->rightTree);
		}
	}
	return sum;
}

MyTree::MyTree(int n)
{
	createTree(n);
}

void MyTree::deleteTree()
{
	if (root) {
		delete root;
	}
	root = nullptr;
	size = 0;
}

void MyTree::createTree(int n)
{
	deleteTree();
	if (n < 0) {
		n = 0;
	}
	size = n;
	root = createNodes(n);

}

MyTree::~MyTree()
{
	deleteTree();
	//cout << "\n|\n";
}

void MyTree::test()
{
	int n;
	MyTree t;
	int task = 1;
	cout << "Welcome to test program. Empty tree was created.";
	while (task > 0 and task < 6) {
		cout << "\n1) Print tree\n2) Create tree\n3) Delete tree\n4) Average left\n5) Average right\n";
		cin >> task;
		switch (task)
		{
		case 1:
			t.printTree();
			cout << "---completed---\n";
			break;
		case 2:
			cout << "n = ";
			cin >> n;
			cout << "---created---\n";
			t.createTree(n);
			break;
		case 3:
			t.deleteTree();
			cout << "---deleted---\n";
			break;
		case 4:
			cout << "Average left: " << t.averageLeft() << "\n";
			cout << "---computed---\n";
			break;
		case 5:
			cout << "Average right: " << t.averageRight() << "\n";
			cout << "---computed---\n";
			break;
		default:
			break;
		}
	}
	cout << "---exit---\n";
}

void MyTree::printTree()
{
	if (!root) {
		cout << "(empty)\n";
	}
	else {
		printNodes(root);
	}
}

double MyTree::averageLeft()
{
	if (root) {
		return sumTree(root->leftTree) / (size / 2);
	}
	return 0;
}

double MyTree::averageRight()
{
	if (root) {
		return sumTree(root->rightTree) / (size - size / 2 - 1);
	}
	return 0;
}

Node::~Node()
{
	if (leftTree) {
		delete leftTree;
		leftTree = nullptr;
	}
	if (rightTree) {
		delete rightTree;
		rightTree = nullptr;
	}
	//cout << "\n~\n";
}
