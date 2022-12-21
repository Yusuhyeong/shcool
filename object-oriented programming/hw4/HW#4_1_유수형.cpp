/***********************************************************************************/
/*             HW#4_1 : 함수 오버로딩 이해하기                                     */
/*  작성자 : 유수형                                날짜 : 2021년 4월  2일          */
/*                                                                                 */
/* 문제 정의 : 비슷한 처리를 하는 함수에 대하여 변수의 형태에 따라                 */
/*             함수의 기능을 다르게 하는 오버로딩 함수를 만든다.                   */
/***********************************************************************************/

#include <iostream>
#include <cstring> // 문자열 비교를 위해 strcmp()함수 사용
using namespace std;

int GetMin(int a, int b); // 두 정수(int형) 중 최소값을 구하는 GetMin()함수
double GetMin(double a, double b); // 두 실수(double 형)중 최소값을 구하는 함수
string GetMin(string a, string b); // 두 문자열 중 작은 문자열을 구하는 함수
int GetMin(int arr[], int size); // 정수형 배열 중 최소값을 구하는 함수

int main() {
   int value_1, value_2; // 정수
   double value_3, value_4; // 실수
   string value_s1, value_s2; // 문자열
   int value_arr[10]; // 배열


   cout << "두개의 정수를 입력하세요 :";
   cin >> value_1 >> value_2;
   
   int result_1 = GetMin(value_1, value_2);
   cout <<"최소값은 " << result_1 <<"입니다.\n";


   cout << "두개의 실수를 입력하세요 :";
   cin >> value_3 >> value_4;
   double result_2 = GetMin(value_3, value_4);
   cout << "최소값은 " << result_2 << "입니다.\n";


   cout << "두개의 문자열을 입력하세요 :";
   cin >> value_s1 >> value_s2;
   string result_s = GetMin(value_s1, value_s2);
   cout << "최소값은 " << result_s << "입니다.\n";


   cout << "배열의 원소 : ";
   for (int i = 0; i < 10; i++) {
      cin >> value_arr[i];
   }
   cout << "최소값은 " << GetMin(value_arr, 10) << "입니다.\n";

   return 0;
}


//함수 오버로딩으로 인해 GetMin이라는 최소의 값을 구하는 함수
//의 이름은 같지만 요구하는 변수형에 따라 들어가는 함수가
//달라지게 된다.

int GetMin(int a, int b) { // 정수형 반환 함수
    if (a < b) // 정수형 변수 a, b비교
        return a; // a가 더 작으면 a 리턴
    else
        return b; // b가 더 작으면 b 리턴
}

double GetMin(double a, double b) { // 실수형 반환 함수
    if (a < b) // 실수형 변수 a, b 리턴
        return a; // a가 더 작으면 a 리턴
    else
        return b; // b가 더 작으면 b 리턴
}

string GetMin(string a, string b){ // 문자열 반환 함수
   if (a.length() > b.length()) // 문자열 변수 a, b의 길이 비교
      return b; // b가 더 짧으면 b 리턴
   else 
      return a; // a가 더 짧으면 a 리턴
}

int GetMin(int arr[], int size) { // 배열 반환 함수
    int min = arr[0]; // 초기값은 arr의 첫번째 원소를 최소값으로 둔다.
    int i;
    for (i = 1; i < size; i++) { // i가 1부터 size까지 배열의 원소를 반복문으로 돈다.
        if (min > arr[i]) // 만약 최소값으로 둔 arr[i]가 min보다 작다면
            min = arr[i]; // 최소값은 arr[i]가 된다.
    }
    return min; // 어떤 arr[i]를 최소값으로 리턴
}