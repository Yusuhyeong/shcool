/*************************************************************************************************/
/*             �ǽ�#10 : ��ü�������� ����ó�����α׷�#3 �ۼ�                                  */
/*  �ۼ��� : ������                                ��¥ : 2021�� 5�� 21��                        */
/*                                                                                               */
/* ���� ���� : ����#9�� ���뿡�� ���� ã��, InputUtil����� �߰��Ѵ�.                            */
/*             student�� subject class�� ���� ����Լ� �� ��������� �������� �ʴ� ��� �Լ���   */
/*             ���� ��� const ����Լ��� �����ϰ� const��ü�� ����� �� �ֵ��� Ȯ���Ų��.      */
/*             InputUtil class�� �����Լ��� ������ ���� ������ Inputvalue�Լ��� ��ü�Ѵ�.        */
/*************************************************************************************************/



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#include "InputUtil.h"
#include "Student.h"
#include "Subject.h"

void main() {
	Student std;
	std.InputData();
	std.PrintData();
	Subject* sub = std.SubSearch("������");
	// ������� ���������� Ž���� ���
	// �ش� ���������� �ִ� �޸� �ּҸ� ����
	if (sub != NULL) {
		sub->PrintTitle();
		sub->PrintData();
	}

	else if (sub == NULL) {
		cout << "ã�� ������ �����ϴ�." << endl;
	}
}