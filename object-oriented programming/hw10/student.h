#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<string.h>
#include<iostream>
#include"subject.h"
#include<iomanip>
#include<cstring>
#include<string>
#include "InputUtil.h"

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
	Student();
	Student(string name, int hakbun, int subnum, Subject* sub);
	Student(const Student& std);
	~Student();
	//void Remove(); // �����޸� ���� (m_sub)
	void InputValue(int&);
	void InputValue(string&);
	void InputData(); // ������� �� �Է�
	void PrintData(); // ������� �� ���
	void CalcAveGPA(); // ��� ���� ���
	friend void ShowData(const Student& s); // �л��� ������ ���� ���� ������ ����ϴ� friend�Լ�
	string GetName();
	int GetHakbun();
	int GetSubNum();
	float GetAveGPA();
	void Modify(); // �л�����, ��������, ��θ� ���� �����ϴ� �Լ�
	void SetName(string);
	void SetHakbun(int);
	void SetSubNum(int);
	void SetaveGPA(float);
	Subject* SubSearch(string subname);         //����� �˻�
};

#endif STUDENT_H
