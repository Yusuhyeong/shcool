#pragma once
#ifndef IOINTERFACE_H
#define IOINTERFACE_H
#include <iostream>
#include <string>
#include "InputUtil.h" // InputValue�Լ��� ���� ��� ����
using namespace std;

class IOInterface 
{
protected:
	string m_name;
	int m_data;

public:
	IOInterface() // ����Ʈ ������
	{
		cout << "IOInterface�� ����Ʈ ������ ȣ���\n";
		this->m_name = "";
		this->m_data = 0;
	};
	IOInterface(string m_name) // �����ִ� ������
	{
		cout << "IOInterface�� �����ִ� ������ ȣ���\n";
		// ������ ���� m_name, m_data�� �ʱ�ȭ ��Ŵ, this�����͸� ���� �ʱ�ȭ
		this->m_name = m_name;
		this->m_data = m_data;
	};
	~IOInterface() // �Ҹ���
	{
		//�ϴ��� x
		cout << "IOInterface�� �Ҹ��� ȣ���\n";

	};
	void Inputdata() // ��������� �� �Է�
	{
		cout << "m_data : ";
		InputUtil::InputValue(this->m_data);
		cout << "m_name : ";
		InputUtil::InputValue(this->m_name);
	};
	void Printdata() const // ��������� �� ���
	{
		cout << "m_data : " << m_data << "\nm_name : " << m_name << "\n" << endl;
	};
	void Modify() // ��������� �� ����
	{
		cout << "����\nm_data : ";
		InputUtil::InputValue(this->m_data);
		cout << "m_name : ";
		InputUtil::InputValue(this->m_name);
	};
	string GetName() // ������ �Լ�
	{
		return m_name;
	};
	int GetData() // ������ �Լ�
	{
		return m_data;
	};
};

#endif IOINTERFACE_H