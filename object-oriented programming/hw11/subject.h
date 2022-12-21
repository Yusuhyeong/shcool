#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H
using namespace std;

#include "IOInterface.h"

class Subject : public IOInterface // IOInterface�� ���
{
protected:
	string m_name; // �����
	int m_hakjum; // ����
	string m_grade; // ���
	float m_GPA; // ����

public:
	Subject();
	Subject(string name, int hakjum, string grade);
	Subject(const Subject& sub);
	~Subject();
	//void Initialize(); // ������� �ʱ�ȭ
	//void Initialize(string, int, string); // ���ڰ����� ������� �ʱ�ȭ

	void InputData(); // ������� �� �Է�
	// ���������� InputValue()�̿�
	void PrintTitle() const; // ��������� ���� title Text ���
	void PrintData() const; // ������� �� ���
	void CalcGPA(); // ���� ���
	float GetGPA() const;
	string GetName() const;
	string GetGrade() const;
	int GetHakjum() const;
	void Modify(); // ���� ���� ����
	void SetName(string);
	void SetHakjum(int);
	void SetGrade(string);
	void SetGPA(float);
};

#endif SUBJECT_H