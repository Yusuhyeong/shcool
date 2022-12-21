#include<iostream>
#include <iomanip>
#include<string>
#include <cstring>
#include"student.h"
#include"subject.h"
#include "InputUtil.h"
#include "IOInterface.h"

using namespace std;

// 학생의 정보 입력 받는 함수 중 int변수에 대한 입력 함수
void Student::InputValue(int& i)
{
	cin >> i;
	cin.ignore(); // 입력 버퍼 제거
}


// 학생의 정보 입력 받는 함수 중 string변수에 대한 입력 함수
void Student::InputValue(string& str)
{
	cin >> str; // string문자열 입력
}
/*
// 멤버변수 초기화
void Student::Initialize()
{
	m_name = "유수형";
	m_hakbun = 2016039016;
	m_subnum = 1;
}


// 초기값으로 멤버변수 초기화
void Student::Initialize(string name, int hakbun, int subnum, Subject* sub)
{
	m_name = name;
	m_hakbun = hakbun;
	m_subnum = subnum;
	m_sub = sub;
}
*/

//디폴트 생성자
Student::Student()
{
	cout << "Student 디폴트 생성자 호출\n";
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0;
}

// 인자있는 생성자
Student::Student(string name, int hakbun, int subnum, Subject* sub):IOInterface(name) // name과 subnum에 대한 변수를
{                                                                                             // IOInterface에 상속시키고 생성자 호출
	m_data = 300;
	cout << "Student 인자있는 생성자 호출\n";
	m_name = name;
	m_hakbun = hakbun;
	m_subnum = subnum;
	m_sub = new Subject[m_subnum]; // 과목정보에 대한 동적 할당



	for (int i = 0; i < m_subnum; i++)
	{
		m_sub[i].SetName(sub[i].GetName());
		m_sub[i].SetHakjum(sub[i].GetHakjum());
		m_sub[i].SetGrade(sub[i].GetGrade());
		m_sub[i].SetGPA(sub[i].GetGPA());
	}
}

// 소멸자
Student::~Student()
{
	cout << "Student 소멸자 호출\n";
	delete[] m_sub;
	m_sub = NULL;
}

// 복사생성자
Student::Student(const Student& std)
{
	cout << "Student 복사 생성자 호출\n";
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
// 동적으로 할당된 메모리 해제(m_sub)
void Student::Remove()
{
	delete[]m_sub;
}
*/

// 학생에 대한 정보 입력 함수
void Student::InputData()
{
	// InputUtil헤더에 정의된 InputValue를 통해 입력 받음
	cout << "이름 : ";
	InputUtil::InputValue(m_name);
	cout << "\n";
	cout << "학번 : ";
	InputUtil::InputValue(m_hakbun);
	cout << "\n";
	cout << "과목수 : ";
	InputUtil::InputValue(m_subnum);
	cout << "\n\n";
	cout << "수강한 과목" << m_subnum << "개와 각 교과목명, 과목등급을 입력하세요\n" << endl;
	m_sub = new Subject[m_subnum];
	for (int i = 0; i < m_subnum; i++)
		(m_sub + i)->InputData(); // 수강한 과목의 개수, 교과목명, 과목 등급을 입력 받을 땐 subject class에서 입력받는다.
	CalcAveGPA(); // 입력받은 과목에 대한 평균평점 계산
}

// 학생 정보 출력
void Student::PrintData()
{


	cout << "==============================\n";
	cout << "이름 : " << m_name << endl;
	cout << "학번 : " << m_hakbun << endl;
	cout << "==============================\n";    cout << "\n";
	cout << "교과목명";
	cout.width(14);
	cout << "                학점수";
	cout.width(14);
	cout << "                등급";
	cout.width(14);
	cout << "        평점" << endl;
	cout << "===================================================================" << endl;

	for (int i = 0; i < m_subnum; i++)
	{
		(m_sub + i)->CalcGPA(); // 정보를 출력하기전 입력한 학생의 과목의 평점을 계산하고
		CalcAveGPA(); // 평균 평점을 계산한 뒤
		(m_sub + i)->PrintData(); // 학생의 과목 정보를 출력한다.
		cout.width(10);
		cout << "\n";
	}
	cout << "===================================================================" << endl;
	cout << "                                                    평균평점 : " << m_aveGPA;
	cout << "\n";
}

// 학생의 교과목에 대한 평균 평점 계산 함수
void Student::CalcAveGPA()
{
	int i = 0;
	float sum = 0.0;
	float k = 0;
	float result = 0.0;

	for (i = 0; i < m_subnum; i++)
	{
		(m_sub + i)->CalcGPA(); // subject class의 평점을 계산
		sum = (m_sub + i)->GetGPA() + sum; // 평점을 모두 더한 후 sum값에 넣는다.
		k = (m_sub + i)->GetHakjum() + k; // 학점 수 를 모두 더한 후 k값에 넣는다.
	}
	result = sum / k; // sum값과 k값을 나눈 값 = 평균 평점
	m_aveGPA = result;
}

// 학생의 교과목 정보 출력을 위한 m_aveGPA return
float Student::GetAveGPA()
{
	return m_aveGPA;
}

// 학생의 이름 출력을 위한 m_name return
string Student::GetName() {
	return m_name;
}

// 학생의 학번 출력을 위한 m_hakbun return
int Student::GetHakbun() {
	return m_hakbun;
}

// 학생의 과목 개수 출력을 위한 m_subnum return
int Student::GetSubNum() {
	return m_subnum;
}


// 생성자에 쓰일 접근자 함수 Set함수

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


// 정보 수정을 위한 함수
void Student::Modify()
{
	string st;
	cout << "수정(학생정보/과목정보/모두) : "; // string st에 대해 수정할 정보 검색
	InputUtil::InputValue(st);
	if (st == "학생정보")
	{
		// student class 변수 변경
		cout << "\n";
		cout << m_name << " " << m_hakbun << "의 정보를 수정하세요\n";
		cout << "이름 : ";
		InputUtil::InputValue(m_name);
		cout << "학번 : ";
		InputUtil::InputValue(m_hakbun);

	}
	else if (st == "과목정보")
	{
		string subst;
		cout << "\n수정할 과목의 이름을 입력하세요.\n";
		cout << "과목명 : ";
		InputUtil::InputValue(subst); //과목 이름을 입력받고
		Subject* targetsub = SubSearch(subst); //과목 서치
		if (targetsub != NULL) { //targetsub에 수정할 과목정보가 들어있으면
			targetsub->Modify(); //그 과목정보를 수정
			CalcAveGPA();
		}
	}
	else if (st == "모두")
	{
		cout << "\n";
		cout << m_name << " " << m_hakbun << "의 정보를 수정하세요.\n";
		cout << "이름 : ";
		InputUtil::InputValue(m_name);
		cout << "학번 : ";
		InputUtil::InputValue(m_hakbun);
		cout << "\n";
		for (int i = 0; i < m_subnum; i++)
			m_sub[i].InputData(); //각 과목마다 값 재입력받기
		CalcAveGPA();
	}
}

// 학생이 수강한 과목을 검색하는 함수
Subject* Student::SubSearch(string subname)
{
	for (int i = 0; i < m_subnum; i++) // 수강한 과목 수 만큼 반복문을 돌며
	{
		if ((m_sub + i)->GetName() == subname) // 입력받은 과목의 이름과 학생이 가지고 있는 과목의 이름을 비교
		{
			return (m_sub + i); // 학생이 가지고 있는 과목중 같은 것이 있다면 그 과목을 return
		}
	}

	return NULL;
}