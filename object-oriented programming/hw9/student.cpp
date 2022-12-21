#include<iostream>
#include <iomanip>
#include<string>
#include <cstring>
#include"student.h"
#include"subject.h"

using namespace std;

// �л��� ���� �Է� �޴� �Լ� �� int������ ���� �Է� �Լ�
void Student::InputValue(int& i)
{
	cin >> i;
	cin.ignore(); // �Է� ���� ����
}


// �л��� ���� �Է� �޴� �Լ� �� string������ ���� �Է� �Լ�
void Student::InputValue(string& str)
{
	cin >> str; // string���ڿ� �Է�
}
/*
// ������� �ʱ�ȭ
void Student::Initialize()
{
	m_name = "������";
	m_hakbun = 2016039016;
	m_subnum = 1;
}


// �ʱⰪ���� ������� �ʱ�ȭ
void Student::Initialize(string name, int hakbun, int subnum, Subject* sub)
{
	m_name = name;
	m_hakbun = hakbun;
	m_subnum = subnum;
	m_sub = sub;
}
*/

//����Ʈ ������
Student::Student()
{
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0;
}

// �����ִ� ������
Student::Student(string name, int hakbun, int subnum, Subject* sub)
{
	m_name = name;
	m_hakbun = hakbun;
	m_subnum = subnum;
	m_sub = new Subject[m_subnum]; // ���������� ���� ���� �Ҵ�



	for (int i = 0; i < m_subnum; i++)
	{
		m_sub[i].SetName(sub[i].GetName());
		m_sub[i].SetHakjum(sub[i].GetHakjum());
		m_sub[i].SetGrade(sub[i].GetGrade());
		m_sub[i].SetGPA(sub[i].GetGPA());
	}
}

// �Ҹ���
Student::~Student()
{
	delete[] m_sub;
	m_sub = NULL;
}

// ���������
Student::Student(const Student& std)
{
	m_name = std.m_name;
	m_hakbun = std.m_hakbun;
	m_subnum = std.m_subnum;
	m_sub = new Subject[m_subnum];
	for (int i = 0; i < m_subnum; i++)
	{
		m_sub[i].SetName(std.m_sub[i].GetName());
		m_sub[i].SetHakjum(std.m_sub[i].GetHakjum());
		m_sub[i].SetGrade(std.m_sub[i].GetGrade());
		m_sub[i].SetGPA(std.m_sub[i].GetGPA());
	}
}

/*
// �������� �Ҵ�� �޸� ����(m_sub)
void Student::Remove()
{
	delete[]m_sub;
}
*/

// �л��� ���� ���� �Է� �Լ�
void Student::InputData()
{

	cout << "�̸� : ";
	InputValue(m_name);
	cout << "\n";
	cout << "�й� : ";
	InputValue(m_hakbun);
	cout << "\n";
	cout << "����� : ";
	InputValue(m_subnum);
	cout << "\n\n";
	cout << "������ ����" << m_name << "���� �� �������, �������� �Է��ϼ���\n" << endl;
	m_sub = new Subject[m_subnum];
	for (int i = 0; i < m_subnum; i++)
		(m_sub + i)->InputData(); // ������ ������ ����, �������, ���� ����� �Է� ���� �� subject class���� �Է¹޴´�.
	CalcAveGPA(); // �Է¹��� ���� ���� ������� ���
}

// �л� ���� ���
void Student::PrintData()
{


	cout << "======================================================================" << endl;
	cout << "�̸� : " << m_name << "  �й� : " << m_hakbun << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "  �������                ������              ���        ����     " << endl;
	cout << "----------------------------------------------------------------------" << endl;
	for (int i = 0; i < m_subnum; i++)
	{
		(m_sub + i)->CalcGPA(); // ������ ����ϱ��� �Է��� �л��� ������ ������ ����ϰ�
		CalcAveGPA(); // ��� ������ ����� ��
		(m_sub + i)->PrintData(); // �л��� ���� ������ ����Ѵ�.
		cout << "\n";
	}
	cout << "======================================================================" << endl;
	cout << "                                                    ������� : " << m_aveGPA;
	cout << "\n";
}

// �л��� ������ ���� ��� ���� ��� �Լ�
void Student::CalcAveGPA()
{
	int i = 0;
	float sum = 0.0;
	float k = 0;
	float result = 0.0;

	for (i = 0; i < m_subnum; i++)
	{
		(m_sub + i)->CalcGPA(); // subject class�� ������ ���
		sum = (m_sub + i)->GetGPA() + sum; // ������ ��� ���� �� sum���� �ִ´�.
		k = (m_sub + i)->GetHakjum() + k; // ���� �� �� ��� ���� �� k���� �ִ´�.
	}
	result = sum / k; // sum���� k���� ���� �� = ��� ����
	m_aveGPA = result;
}

// �л��� ������ ���� ����� ���� m_aveGPA return
float Student::GetAveGPA()
{
	return m_aveGPA;
}

// �л��� �̸� ����� ���� m_name return
string Student::GetName() {
	return m_name;
}

// �л��� �й� ����� ���� m_hakbun return
int Student::GetHakbun() {
	return m_hakbun;
}

// �л��� ���� ���� ����� ���� m_subnum return
int Student::GetSubNum() {
	return m_subnum;
}


// �����ڿ� ���� ������ �Լ� Set�Լ�

void Student::SetName(string x)
{
	m_name = x;
}


void Student::SetHakbun(int x)
{
	m_hakbun = x;
}


void Student::SetSubNum(int x)
{
	m_subnum = x;
}


void Student::SetaveGPA(float x)
{
	m_aveGPA = x;
}


// ���� ������ ���� �Լ�
void Student::Modify()
{
	string st;
	cout << "����(�л�����/��������/���) : "; // string st�� ���� ������ ���� �˻�
	InputValue(st);
	if (st == "�л�����")
	{
		// student class ���� ����
		cout << "\n";
		cout << m_name <<" "<< m_hakbun << "�� ������ �����ϼ���\n";
		cout << "�̸� : ";
		InputValue(m_name);
		cout << "�й� : ";
		InputValue(m_hakbun);

	}
	else if (st == "��������")
	{
		// subject class ���� ����
		cout << "\n";
		m_sub->Modify();
		CalcAveGPA();
	}
	else if (st == "���")
	{
		cout << "\n";
		cout << m_name << " " << m_hakbun << "�� ������ �����ϼ���\n";
		cout << "�̸� : ";
		InputValue(m_name);
		cout << "�й� : ";
		InputValue(m_hakbun);
		cout << "\n";
		m_sub->Modify();
		CalcAveGPA();
	}
}