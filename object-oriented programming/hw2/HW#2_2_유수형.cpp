#include <iostream>
using namespace std;

int main()
{
	/*�ǽ��ڵ� 2*/

	//A
	int i1 = 10;
	int i2 = 20;
	const int* pInt1;
	pInt1 = &i1;
	*pInt1 = 30; // *pInt1�� const��

	//B
	/*
	int i1 = 10;
	int i2 = 20;
	int* const pInt2 = &i1;
	pInt2 = &i2;
	*pInt2 = 50; // pInt2�� const��
	*/

	//C
	/*
	int i1 = 10;
	int i2 = 20;
	const int* const p = &i2;
	p = &i1;
	*p = 40; // p��ü�� const���̸� int��ü, �� ��� ���� �Ұ�
	* */

	return 0;
}