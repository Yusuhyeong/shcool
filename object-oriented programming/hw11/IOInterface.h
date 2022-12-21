#pragma once
#ifndef IOINTERFACE_H
#define IOINTERFACE_H
#include <iostream>
#include <string>
#include "InputUtil.h" // InputValue함수를 위한 헤더 참조
using namespace std;

class IOInterface 
{
protected:
	string m_name;
	int m_data;

public:
	IOInterface() // 디폴트 생성자
	{
		cout << "IOInterface의 디폴트 생성자 호출됨\n";
		this->m_name = "";
		this->m_data = 0;
	};
	IOInterface(string m_name) // 인자있는 생성자
	{
		cout << "IOInterface의 인자있는 생성자 호출됨\n";
		// 인자의 값을 m_name, m_data로 초기화 시킴, this포인터를 통해 초기화
		this->m_name = m_name;
		this->m_data = m_data;
	};
	~IOInterface() // 소멸자
	{
		//하는일 x
		cout << "IOInterface의 소멸자 호출됨\n";

	};
	void Inputdata() // 멤버변수의 값 입력
	{
		cout << "m_data : ";
		InputUtil::InputValue(this->m_data);
		cout << "m_name : ";
		InputUtil::InputValue(this->m_name);
	};
	void Printdata() const // 멤버변수의 값 출력
	{
		cout << "m_data : " << m_data << "\nm_name : " << m_name << "\n" << endl;
	};
	void Modify() // 멤버변수의 값 수정
	{
		cout << "수정\nm_data : ";
		InputUtil::InputValue(this->m_data);
		cout << "m_name : ";
		InputUtil::InputValue(this->m_name);
	};
	string GetName() // 접근자 함수
	{
		return m_name;
	};
	int GetData() // 접근자 함수
	{
		return m_data;
	};
};

#endif IOINTERFACE_H