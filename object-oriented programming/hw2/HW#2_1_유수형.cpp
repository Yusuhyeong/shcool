#include <iostream>
using namespace std;

int main()
{
	/*실습 코드 1*/
	int M[3][3] = { { 1,2,3 },{ 4,5,6 },{ 7,8,9 } }; // 2차원 배열

	int(*ptr)[3]; // int[3]을 가르키는 배열 포인터 ptr
	int *p; // 주소를 저장하는 포인터 p
	int**pt; // 주소를 가르키는 변수의 주소를 저장하는 이중 포인터 pt

	ptr = M;
	cout << "ptr : " << ptr << " M : " << M << "\n\n";
	// ptr : 00CFFDBC M : 00CFFDBC
	cout << "ptr + 1 : " << ptr + 1 << " M + 1 : " << M + 1 << "\n\n";
	// ptr + 1 : 00CFFDC8 M + 1 : 00CFFDC8
	cout << "*(ptr + 1) : " << *(ptr + 1) << " ptr[1] : " << ptr[1] << " *(M + 1) : " << *(M + 1) << " M[1] : " << M[1] << "\n\n";
	// *(ptr + 1) : 00CFFDC8 ptr[1] : 00CFFDC8 *M[1] : 00CFFDC8 *(M + 1) : 00CFFDC8
	cout << "**(ptr + 1) : " << **(ptr + 1) << " **(M + 1) : " << **(M + 1) << " *M[1] : " << *M[1] << " M[1][0] : " << M[1][0] << "\n\n";
    // **(ptr + 1) : 4 **(M + 1) : 4 * M[1] : 4 M[1][0] : 4

	p = M[0];
	cout << "p : " << p << " M[0] : " << M[0] << " *M : " << *M << "\n\n";
	// p : 00CFFDBC M[0] : 00CFFDBC *M : 00CFFDBC
	cout << "p + 1 : " << p + 1 << " M[0] + 1 : " << M[0] + 1 << " *M + 1 : " << *M + 1 << "\n\n";
	// p + 1 : 00CFFDC0 M[0] + 1 : 00CFFDC0 *M + 1 : 00CFFDC0
	cout << "*(p + 1) : " << *(p + 1) << " *(M[0] + 1) : " << *(M[0] + 1) << " *(*M + 1) : " << *(*M + 1) << "\n\n";
	// *(p + 1) : 2 *(M[0] + 1) : 2 *(*M + 1) : 2
	pt = &p; // pt = M; (X)
	cout << "*pt : " << *pt << " p : " << p << "\n\n";
	// *pt : 00CFFDBC p : 00CFFDBC
	cout << "**pt : " << **pt << " *p : " << *p << "\n\n";
	// **pt : 1 *p : 1


	return 0;
}
