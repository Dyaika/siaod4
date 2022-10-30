#ifndef __BINARYTREE_H
#define __BINARYTREE_H
#include <random>
#include <iostream>
using namespace std;

//��������� ���� (��� ���������� ��� MyTree, ������������ � MyTree)
struct Node {
	double data;
	Node* leftTree = nullptr;
	Node* rightTree = nullptr;

	//����������, ������ ������ ���� ������� ������
	~Node();
};

//��������� � ����� MyTree ������� ��� �������� ������
class MyTree
{
private:
	int size = 0;
	Node* root = nullptr;
public:
	//�����������
	MyTree(int n = 0);

	//������� ������
	void deleteTree();

	//������� ������, ����� ������� �����
	void createTree(int n);

	//������� ������ � ��������� ������ ������� �������
	void printTree();

	//������� ������� �������� ������ ���������
	double averageLeft();

	//������� ������� �������� ������� ���������
	double averageRight();

	//����������, ������� ������
	~MyTree();

	//������������� ���������
	static void test();
};

//��������������� �������, ��������� ������ � ������ ����������
Node* addBinarySort(double x, Node* root);

//��������������� �������, ������� ���������������� ������ ������� �������
Node* createAVLNodes(int n);

//��������������� �������, ���������� ��������� �� ������� ��� ������� n ��� ������ � �������
Node* getData(int& n, Node* root);

//������� ������ (��� ���������� ��� MyTree, ������������ � createTree())
Node* createNodes(int n);

//�������� ������ (��� ���������� ��� MyTree, ������������ � printTree())
void printNodes(Node* root, int level = 0, int L = 10);

//������� ����� ������ (��� ������, ������������ � Average*())
double sumTree(Node* root);
#endif // !__BINARYTREE_H



