/*************************************************************************************************/
/*             �ǽ�#11 : ��ü�������� ����ó�����α׷�#4 �ۼ�                                  */
/*  �ۼ��� : ������                                ��¥ : 2021�� 5�� 28��                        */
/*                                                                                               */
/* ���� ���� : ����#10�� ���뿡�� ������ ã���� ������ ������ �����Ѵ�.                          */
/*             student �� subject class�� IOInterface�� ��ӵǰ� �����ڸ� ���� ��ӵ� ������ ��  */
/*             �� ������ Ȯ���Ѵ�. �̶� ��ӵ� ������ �������� �ǽ����� 3���� ���� Ȯ���Ѵ�.     */
/*************************************************************************************************/



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#include "InputUtil.h"
#include "student.h"
#include "subject.h"
#include "IOInterface.h"

/*
void main() {
	Student std;
	cout << std.GetData() << "\n"; // IOInterface Class���� ��ӹ��� ����Լ� ȣ��
}
*/

/*
void main() {
	Subject sub("��ǻ��", 3, "C");
	cout << "-----------------------------\n";
	cout << "m_data : " << sub.GetData(); // Subject class���� IOInterface�� m_data�� 100���� ����
	cout << "\n������ �̸� : " << sub.GetName(); // subject�� ���ؼ� name�� ���� ���� ��� -> ��ǻ�� ���
	cout << "\n�θ�Ŭ������ �̸� : " << sub.IOInterface::GetName(); // sub�� IOInterface�� ��ӵ� ���·� �����ǰ� IOInterface�� GetName�Լ��� ȣ�� -> GetName�� return value�� ��ǻ��
	cout << "\n-----------------------------\n\n";

	Student std("ȫ�浿", 2013909845, 1, &sub);
	cout << "-----------------------------\n";
	cout << "m_data : " << std.GetData(); // Student class���� IOInterface�� m_data�� 300���� ����
	cout << "\n�л� �̸� : " << std.GetName(); // student�� ���ؼ� name�� ���� ���� ��� -> ȫ�浿 ���
	cout << "\n�θ�Ŭ������ �̸� : " << std.IOInterface::GetName(); // std�� IOInterface�� ��ӵ� ���·� �����ǰ� IOInterface�� GetName�Լ��� ȣ�� -> GetName�� return value�� ȫ�浿
	cout << "\n-----------------------------\n\n";
}
*/

/*
void main() {
	Subject sub("��ǻ��", 3, "C");
	Student std("ȫ�浿", 20138342, 1, &sub);
	std.PrintData();
	std.Modify(); // Student Class�� ������� �� ����
	std.PrintData();
}
*/