//Tree.h
#ifndef __BINARYTREE_H
#define __BINARYTREE_H
#include <random>
#include <iostream>
using namespace std;

//структура узла (дл€ реализации без MyTree, используетс€ в MyTree)
struct Node {
	double data;
	Node* leftTree = nullptr;
	Node* rightTree = nullptr;

	//деструктор, удалит дерево если удалить кроень
	~Node();
};

//собранные в класс MyTree функции дл€ удобного вызова
class MyTree
{
private:
	int size = 0;
	Node* root = nullptr;
public:
	//конструктор
	MyTree(int n = 0);

	//удал€ет дерево
	void deleteTree();

	//удал€ет дерево, затем создает новое
	void createTree(int n);

	//выводит дерево с поворотом против часовой стрелки
	void printTree();

	//считает среднее значение левого поддерева
	double averageLeft();

	//считает среднее значение правого поддерева
	double averageRight();

	//деструктор, удал€ет дерево
	~MyTree();

	//тестировочна€ программа
	static void test();
};

//—оздает дерево (дл€ реализации без MyTree, используетс€ в createTree())
Node* createNodes(int n);

//печатает дерево (дл€ реализации без MyTree, используетс€ в printTree())
void printNodes(Node* root, int level = 0, int L = 10);

//считает сумму дерева (дл€ срзнач, используетс€ в Average*())
double sumTree(Node* root);
#endif // !__BINARYTREE_H



