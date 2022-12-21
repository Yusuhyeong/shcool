/***********************************************************************************/
/*             HW#4_2 : 함수 템플릿 이해하기                                       */
/*  작성자 : 유수형                                날짜 : 2021년 4월  2일          */
/*                                                                                 */
/* 문제 정의 : 동일한 알고리즘을 받는 함수에 대하여 변수형에 따라                  */
/*             작동하며 결과값이 다를 순 있지만 같은 함수에서 구현                 */
/*             되기 위해 함수 템플릿을 이용하여 변수형 구분없이 같은               */
/*             함수에서 작동되도록 구현해 본다.                                    */
/***********************************************************************************/



#include <iostream>
using namespace std;
#define size 5 // 5개의 값을 위한 size 5로 고정

// 함수 템플릿 구현
template <typename T> void Sort(T* arr, int SIZE) // arr에 들어가는 변수 형은 다르겠지만 T* arr를 통해 다른 변수형이 들어와도
{                                                 // 같은 알고리즘으로 구현되되록 한다.
	T tmp;
	for (int i = 0; i < SIZE - 1; i++) // 비교를 당할 값과
	{
		for (int j = 0; j < SIZE - 1 - i; j++) // 비교를 할 값
		{
			if (arr[j] > arr[j + 1]) // 두값을 비교하여
			{
				tmp = arr[j]; // 작은값이 왼쪽으로 가도록 정렬
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}

	}
}

int main()
{
	double array[size];
	int menu;
	while (1) {
		cout << "1.정수 정렬" << "\n";
		cout << "2.실수 정렬" << "\n";
		cout << "3.종료" << "\n";
		cout << "메뉴 선택 : ";
		cin >> menu;
		cout << "\n";
		if (menu == 1) // 1번 메뉴 선택시 정수 정렬
		{
			cout << "5개의 정수를 입력하세요 : ";
			for (int i = 0; i < size; i++)
			{
				cin >> array[i];
			}
			Sort(array, size); // 성수형에 관한 정렬 (array[i]값을 int형 변수로 입력받음)

			cout << "정렬 결과 : ";
			for (int i = 0; i < size; i++) // 정렬된 알고리즘을 통해 array 출력
			{
				cout << array[i] << " ";
			}
			cout << endl;
		}
		else if (menu == 2) // 2번 메뉴 선택시 실수 정렬
		{
			cout << "5개의 실수를 입력하세요 : ";
			for (int i = 0; i < size; i++)
			{
				cin >> array[i];
			}
			Sort(array, size); // 실수형에 관한 정렬 (array[i]값을 double형 변수로 입력받음)

			cout << "정렬 결과 : ";
			for (int i = 0; i < size; i++) // 정렬된 알고리즘을 통해 array 출력
			{
				cout << array[i] << " ";
			}
			cout << endl;
		}
		else if (menu == 3) // 3번 메뉴 선택시 프로그램 종료
		{
			cout << "프로그램을 종료합니다.";
			cout << endl;
			break;
		}
		else // 다른 메뉴 선택시 error표시
		{
			cout << "잘못된 입력입니다.\n\n";
		}

	}

	return 0;
}