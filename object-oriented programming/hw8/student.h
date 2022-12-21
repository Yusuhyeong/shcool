#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<string.h>
#include<iostream>
#include"subject.h"
#include<iomanip>
#include<cstring>
#include<string>
using namespace std;

class Student
{
protected:
	string m_name; // �л���
	int m_hakbun; // �й�
	int m_subnum; // ������ ���� ��
	Subject* m_sub; // ������ �����
	float m_aveGPA; // ������ ������� ��� ����

public:
	void Initialize(); // ������� �ʱ�ȭ
	void Initialize(string, int, int, Subject*); // ���ڰ����� ������� �ʱ�ȭ
	void Remove(); // �����޸� ���� (m_sub)
	void InputValue(int&);
	void InputValue(string&);
	void InputData(); // ������� �� �Է�
	void PrintData(); // ������� �� ���
	void CalcAveGPA(); // ��� ���� ���
	float GetAveGPA();
	friend void ShowData(const Student& s); // �л��� ������ ���� ���� ������ ����ϴ� friend�Լ�

};

#endif STUDENT_H