/***********************************************************************************/
/*             HW#4_1 : �Լ� �����ε� �����ϱ�                                     */
/*  �ۼ��� : ������                                ��¥ : 2021�� 4��  2��          */
/*                                                                                 */
/* ���� ���� : ����� ó���� �ϴ� �Լ��� ���Ͽ� ������ ���¿� ����                 */
/*             �Լ��� ����� �ٸ��� �ϴ� �����ε� �Լ��� �����.                   */
/***********************************************************************************/

#include <iostream>
#include <cstring> // ���ڿ� �񱳸� ���� strcmp()�Լ� ���
using namespace std;

int GetMin(int a, int b); // �� ����(int��) �� �ּҰ��� ���ϴ� GetMin()�Լ�
double GetMin(double a, double b); // �� �Ǽ�(double ��)�� �ּҰ��� ���ϴ� �Լ�
string GetMin(string a, string b); // �� ���ڿ� �� ���� ���ڿ��� ���ϴ� �Լ�
int GetMin(int arr[], int size); // ������ �迭 �� �ּҰ��� ���ϴ� �Լ�

int main() {
   int value_1, value_2; // ����
   double value_3, value_4; // �Ǽ�
   string value_s1, value_s2; // ���ڿ�
   int value_arr[10]; // �迭


   cout << "�ΰ��� ������ �Է��ϼ��� :";
   cin >> value_1 >> value_2;
   
   int result_1 = GetMin(value_1, value_2);
   cout <<"�ּҰ��� " << result_1 <<"�Դϴ�.\n";


   cout << "�ΰ��� �Ǽ��� �Է��ϼ��� :";
   cin >> value_3 >> value_4;
   double result_2 = GetMin(value_3, value_4);
   cout << "�ּҰ��� " << result_2 << "�Դϴ�.\n";


   cout << "�ΰ��� ���ڿ��� �Է��ϼ��� :";
   cin >> value_s1 >> value_s2;
   string result_s = GetMin(value_s1, value_s2);
   cout << "�ּҰ��� " << result_s << "�Դϴ�.\n";


   cout << "�迭�� ���� : ";
   for (int i = 0; i < 10; i++) {
      cin >> value_arr[i];
   }
   cout << "�ּҰ��� " << GetMin(value_arr, 10) << "�Դϴ�.\n";

   return 0;
}


//�Լ� �����ε����� ���� GetMin�̶�� �ּ��� ���� ���ϴ� �Լ�
//�� �̸��� ������ �䱸�ϴ� �������� ���� ���� �Լ���
//�޶����� �ȴ�.

int GetMin(int a, int b) { // ������ ��ȯ �Լ�
    if (a < b) // ������ ���� a, b��
        return a; // a�� �� ������ a ����
    else
        return b; // b�� �� ������ b ����
}

double GetMin(double a, double b) { // �Ǽ��� ��ȯ �Լ�
    if (a < b) // �Ǽ��� ���� a, b ����
        return a; // a�� �� ������ a ����
    else
        return b; // b�� �� ������ b ����
}

string GetMin(string a, string b){ // ���ڿ� ��ȯ �Լ�
   if (a.length() > b.length()) // ���ڿ� ���� a, b�� ���� ��
      return b; // b�� �� ª���� b ����
   else 
      return a; // a�� �� ª���� a ����
}

int GetMin(int arr[], int size) { // �迭 ��ȯ �Լ�
    int min = arr[0]; // �ʱⰪ�� arr�� ù��° ���Ҹ� �ּҰ����� �д�.
    int i;
    for (i = 1; i < size; i++) { // i�� 1���� size���� �迭�� ���Ҹ� �ݺ������� ����.
        if (min > arr[i]) // ���� �ּҰ����� �� arr[i]�� min���� �۴ٸ�
            min = arr[i]; // �ּҰ��� arr[i]�� �ȴ�.
    }
    return min; // � arr[i]�� �ּҰ����� ����
}