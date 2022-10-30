#ifndef __BINARYTREE_H
#define __BINARYTREE_H
#include <random>
#include <iostream>
using namespace std;

//структура узла (для реализации без MyTree, используется в MyTree)
struct Node {
	double data;
	Node* leftTree = nullptr;
	Node* rightTree = nullptr;

	//деструктор, удалит дерево если удалить кроень
	~Node();
};

//собранные в класс MyTree функции для удобного вызова
class MyTree
{
private:
	int size = 0;
	Node* root = nullptr;
public:
	//конструктор
	MyTree(int n = 0);

	//удаляет дерево
	void deleteTree();

	//удаляет дерево, затем создает новое
	void createTree(int n);

	//выводит дерево с поворотом против часовой стрелки
	void printTree();

	//считает среднее значение левого поддерева
	double averageLeft();

	//считает среднее значение правого поддерева
	double averageRight();

	//деструктор, удаляет дерево
	~MyTree();

	//тестировочная программа
	static void test();
};

//вспомогательная функция, добавляет запись в дерево сортировки
Node* addBinarySort(double x, Node* root);

//вспомогательная функция, создает сбалансированное дерево нужного размера
Node* createAVLNodes(int n);

//вспомогательная функция, возвращает указатель на элемент под номером n при обходе в глубину
Node* getData(int& n, Node* root);

//Создает дерево (для реализации без MyTree, используется в createTree())
Node* createNodes(int n);

//печатает дерево (для реализации без MyTree, используется в printTree())
void printNodes(Node* root, int level = 0, int L = 10);

//считает сумму дерева (для срзнач, используется в Average*())
double sumTree(Node* root);
#endif // !__BINARYTREE_H



