#include<iostream>
#include <iomanip>
#include<string.h>
#include<string>
#include<cstring>
#include"subject.h"

using namespace std;

// �л��� �������� �Է� �޴� �Լ� �� int������ ���� �Է� �Լ�
void Subject::InputValue(int& i)
{
	cin >> i;
	cin.ignore();
}

// �л��� �������� �Է� �޴� �Լ� �� string������ ���� �Է� �Լ�
void Subject::InputValue(string& str)
{
	getline(cin, str);
}

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

// �л��� ������ ���� ���� �Է� �Լ�
void Subject::InputData()
{

	cout << " ������ �� : ";
	InputValue(m_name); // ���� �̸�
	cout << "\n";
	cout << " ������ ���� : ";
	InputValue(m_hakjum); // ������ ����
	cout << "\n";
	cout << "������(A+ ~ F) : ";
	InputValue(m_grade); // ���� ���
	cout << "\n\n\n";

	CalcGPA(); // ���� ��޿� ���� ���� ���
}

void Subject::PrintData()
{
	CalcGPA(); // ���� ���� ����� �ϰ�

	cout << "    " << m_name << "                   " << m_hakjum << "                   " << m_grade;
	cout.precision(2);
	cout << fixed;
	cout << "           " << m_GPA << endl; // CalcGPA()���� ����� ���� ������ return�� m_GPA�� ���
}

void Subject::PrintTitle() {
	cout << "==============================================================================\n";
	cout << "�������" << setw(15) << "������" << setw(15) << "���" << setw(15) << "����\n";
	cout << "==============================================================================\n";
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
float Subject::GetGPA()
{
	return m_GPA;
}

// student.cpp���� ���� AveGPA�� ���� return�� �Լ�
int Subject::GetHakjum()
{
	return m_hakjum;
}