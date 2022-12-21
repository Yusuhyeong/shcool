#include<iostream>
#include <iomanip>
#include<string.h>
#include<string>
#include<cstring>
#include"subject.h"
#include "InputUtil.h"
#include "IOInterface.h"

using namespace std;


Subject::Subject()
{
	cout << "Subject ����Ʈ ������ ȣ��\n";
	m_name = "";
	m_hakjum = 0;
	m_grade = "";
	m_GPA = 0.0f;
}

Subject::Subject(string name, int hakjum, string grade):IOInterface(name) // name�� hakjum�� ���� ������
{                                                                                 // IOInterface�� ��ӽ�Ű�� ������ ȣ��
	m_data = 100;
	cout << "Subject �����ִ� ������ ȣ��\n";
	m_name = name;
	m_hakjum = hakjum;
	m_grade = grade;
}

Subject::Subject(const Subject& sub)
{
	cout << "Subject ���� ������ ȣ��\n";
	m_name = sub.m_name;
	m_hakjum = sub.m_hakjum;
	m_grade = sub.m_grade;
}

Subject::~Subject()
{
	cout << "Subject �Ҹ��� ȣ��\n";
}

/*
// ������� �ʱ�ȭ
void Subject::Initialize()
{
	m_name = "";
	m_hakjum = 0;
	m_grade = "";
	m_GPA = 0.0f;
}

// �ʱⰪ���� ������� �ʱ�ȭ
void Subject::Initialize(string subname, int hakjum, string grade)
{
	m_name = subname;
	m_hakjum = hakjum;
	m_grade = grade;
}

*/

// �л��� ������ ���� ���� �Է� �Լ�
void Subject::InputData()
{
	// InputUtil����� ���ǵ� InputValue�� ���� �Է� ����
	cout << "������ �� : ";
	InputUtil::InputValue(m_name); // ���� �̸�
	cout << "\n";
	cout << "������ ���� : ";
	InputUtil::InputValue(m_hakjum); // ������ ����
	cout << "\n";
	cout << "������(A+ ~ F) : ";
	InputUtil::InputValue(m_grade); // ���� ���
	cout << "\n\n\n";

	CalcGPA(); // ���� ��޿� ���� ���� ���
}

void Subject::PrintData() const
{
	cout << "    " << m_name << "                   " << m_hakjum << "                   " << m_grade;
	cout.precision(2);
	cout << fixed;
	cout << "           " << m_GPA << endl; // CalcGPA()���� ����� ���� ������ return�� m_GPA�� ���
}

void Subject::PrintTitle() const{
	cout << "===================================================================\n";
	cout << "    �������" << setw(15) << "               ������" << setw(15) << "              ���" << setw(15) << "          ����\n";
	cout << "===================================================================\n";
}


//���� ���� ���
// ��޿� ���� ���� * ���� ��
void Subject::CalcGPA()
{
	if (m_grade == "A+") m_GPA = 4.5 * m_hakjum;
	else if (m_grade == "A") m_GPA = 4.0 * m_hakjum;
	else if (m_grade == "B+") m_GPA = 3.5 * m_hakjum;
	else if (m_grade == "B") m_GPA = 3.0 * m_hakjum;
	else if (m_grade == "C+") m_GPA = 2.5 * m_hakjum;
	else if (m_grade == "C") m_GPA = 2.0 * m_hakjum;
	else if (m_grade == "D+") m_GPA = 1.5 * m_hakjum;
	else if (m_grade == "D") m_GPA = 1.0 * m_hakjum;
	else if (m_grade == "F") m_GPA = 0;

}


// student.cpp���� ���� AveGPA�� ���� return�� �Լ�
float Subject::GetGPA() const
{
	return m_GPA;
}

// student.cpp���� ���� AveGPA�� ���� return�� �Լ�
int Subject::GetHakjum()	const
{
	return m_hakjum;
}

string Subject::GetName() const
{
	return m_name;
}


string Subject::GetGrade() const
{
	return m_grade;
}


void Subject::SetName(string x)
{
	m_name = x;
}

void Subject::SetGrade(string x)
{
	m_grade = x;
}

void Subject::SetHakjum(int x)
{
	m_hakjum = x;
}

void Subject::SetGPA(float x)
{
	m_GPA = x;
}

void Subject::Modify()
{
	cout << m_name << ", ���� : " << m_hakjum << ", ��� : " << m_grade << "�� ������ �����ϼ���.\n";
	cout << "������� : ";
	InputUtil::InputValue(m_name);
	cout << "�������� : ";
	InputUtil::InputValue(m_hakjum);
	cout << "���� ��� : ";
	InputUtil::InputValue(m_grade);
	CalcGPA();
}