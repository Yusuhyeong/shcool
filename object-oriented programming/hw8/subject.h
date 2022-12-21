#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H
using namespace std;

class Subject
{
protected:
	string m_name; // �����
	int m_hakjum; // ����
	string m_grade; // ���
	float m_GPA; // ����

public:
	void Initialize(); // ������� �ʱ�ȭ
	void Initialize(string, int, string); // ���ڰ����� ������� �ʱ�ȭ
	void InputValue(int&);
	void InputValue(string&);
	void InputData(); // ������� �� �Է�
	// ���������� InputValue()�̿�
	void PrintTitle(); // ��������� ���� title Text ���
	void PrintData(); // ������� �� ���
	void CalcGPA(); // ���� ���
	float GetGPA();
	int GetHakjum();
};

#endif SUBJECT_H