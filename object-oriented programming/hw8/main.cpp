/*************************************************************************************************/
/*             �ǽ�#8 : ��ü�������� ����ó�����α׷�#1 �ۼ�                                   */
/*  �ۼ��� : ������                                ��¥ : 2021�� 5�� 7��                         */
/*                                                                                               */
/* ���� ���� : ���±��� �ۼ��� ����ó�� ���α׷� #7������ ������ ���� �������� �غ���.           */
/*             student class�� ���õ� ������ �л��� ����, subject class�� ���õ� ����            */
/*             �� �л��� ������ ���� ���� ������ ��� �ִ�.                                    */
/*             �ǽ� ���� 3���� �л��� ������ ���� ���� �Է� �� ��, ���� ���� ���� ����       */
/*             �� ��������� student class�� friends�Լ��� ShowData()�� ���� �����ش�            */
/*************************************************************************************************/



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#include "Student.h"
#include "Subject.h"

// #�ǽ� 8-1
/*
void main() {
    Subject sub1, sub2, sub3[2], * sub4;
    int i;
    sub1.Initialize();

    sub2.Initialize("������", 3, "A+");

    for (i = 0; i < 2; i++)
        sub3[i].Initialize("��ǻ��", 3, "C ");

    sub4 = new Subject[2];

    sub1.InputData(); // ȭ�鿡�� �Է�

    cout << "\n" << "sub1 ����" << "\n";
    sub1.PrintTitle(); sub1.PrintData();

    cout << "\n" << "sub2 ����" << "\n";
    sub2.PrintTitle(); sub2.PrintData();

    cout << "\n" << "sub3 ����" << "\n";
    sub3[0].PrintTitle();

    for (i = 0; i < 2; i++) sub3[i].PrintData();

    for (i = 0; i < 2; i++) (sub4 + i)->InputData();

    cout << "\n" << "sub4 ����" << "\n";
    sub4->PrintTitle();
    for (i = 0; i < 2; i++) (sub4 + i)->PrintData();

    delete[] sub4;
}
*/


// #�ǽ� 8-3
/*
void main() {
    Subject sub[2];
    sub[0].Initialize("��ǻ��", 3, "C");
    sub[1].Initialize("���빫��", 2, "A");
    Student st1, st2;
    st1.Initialize();
    st2.Initialize("ȫ�浿", 2013909845, 2, sub);
    st1.InputData();
    cout << "\n" << "st1 ����" << "\n";
    st1.PrintData();
    cout << "\n" << "st2 ����" << "\n";
    st2.PrintData();
    st1.Remove();
}
*/


// #�ǽ� 8-5
/*
void ShowData(const Student&);

void main() {
    Student st;
    st.Initialize();
    st.InputData();
    ShowData(st);
}

void ShowData(const Student& s) { // �������α׷��� �ִ� �����Լ�
    cout << s.m_name << "�� ������ ������ ��" << s.m_subnum << "���� ";
    cout << "������ ������ ���������" << s.m_aveGPA << "�Դϴ�.\n";
}
*/