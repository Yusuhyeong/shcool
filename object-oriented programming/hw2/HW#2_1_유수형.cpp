#include <iostream>
using namespace std;

int main()
{
	/*�ǽ� �ڵ� 1*/
	int M[3][3] = { { 1,2,3 },{ 4,5,6 },{ 7,8,9 } }; // 2���� �迭

	int(*ptr)[3]; // int[3]�� ����Ű�� �迭 ������ ptr
	int *p; // �ּҸ� �����ϴ� ������ p
	int**pt; // �ּҸ� ����Ű�� ������ �ּҸ� �����ϴ� ���� ������ pt

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
