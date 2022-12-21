#include <iostream>
using namespace std;

int main()
{
	/*실습코드 2*/

	//A
	int i1 = 10;
	int i2 = 20;
	const int* pInt1;
	pInt1 = &i1;
	*pInt1 = 30; // *pInt1이 const값

	//B
	/*
	int i1 = 10;
	int i2 = 20;
	int* const pInt2 = &i1;
	pInt2 = &i2;
	*pInt2 = 50; // pInt2가 const값
	*/

	//C
	/*
	int i1 = 10;
	int i2 = 20;
	const int* const p = &i2;
	p = &i1;
	*p = 40; // p자체가 const값이며 int자체, 값 모두 변경 불가
	* */

	return 0;
}