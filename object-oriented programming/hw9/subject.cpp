#include<iostream>
#include <iomanip>
#include<string.h>
#include<string>
#include<cstring>
#include"subject.h"

using namespace std;

// 학생의 과목정보 입력 받는 함수 중 int변수에 대한 입력 함수
void Subject::InputValue(int& i)
{
	cin >> i;
	cin.ignore();
}

// 학생의 과목정보 입력 받는 함수 중 string변수에 대한 입력 함수
void Subject::InputValue(string& str)
{
	getline(cin, str);
}

Subject::Subject()
{
	m_name = "";
	m_hakjum = 0;
	m_grade = "";
	m_GPA = 0.0f;
}

Subject::Subject(string name, int hakjum, string grade)
{
	m_name = name;
	m_hakjum = hakjum;
	m_grade = grade;
}

Subject::Subject(const Subject& sub)
{
	m_name = sub.m_name;
	m_hakjum = sub.m_hakjum;
	m_grade = sub.m_grade;
}

Subject::~Subject()
{

}

/*
// 멤버변수 초기화
void Subject::Initialize()
{
	m_name = "";
	m_hakjum = 0;
	m_grade = "";
	m_GPA = 0.0f;
}

// 초기값으로 멤버변수 초기화
void Subject::Initialize(string subname, int hakjum, string grade)
{
	m_name = subname;
	m_hakjum = hakjum;
	m_grade = grade;
}

*/

// 학생의 교과목에 대한 정보 입력 함수
void Subject::InputData()
{

	cout << " 교과목 명 : ";
	InputValue(m_name); // 과목 이름
	cout << "\n";
	cout << " 과목학 점수 : ";
	InputValue(m_hakjum); // 과목학 점수
	cout << "\n";
	cout << "과목등급(A+ ~ F) : ";
	InputValue(m_grade); // 과목 등급
	cout << "\n\n\n";

	CalcGPA(); // 과목 등급에 대한 평점 계산
}

void Subject::PrintData()
{
	CalcGPA(); // 과목 평점 계산을 하고

	cout << "    " << m_name << "                   " << m_hakjum << "                   " << m_grade;
	cout.precision(2);
	cout << fixed;
	cout << "           " << m_GPA << endl; // CalcGPA()에서 계산한 과목 평점을 return한 m_GPA값 출력
}

void Subject::PrintTitle() {
	cout << "==============================================================================\n";
	cout << "교과목명" << setw(15) << "학점수" << setw(15) << "등급" << setw(15) << "평점\n";
	cout << "==============================================================================\n";
}


//과목 평점 계산
// 등급에 따른 점수 * 학점 수
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

// student.cpp에서 쓰일 AveGPA를 위한 return값 함수
float Subject::GetGPA()
{
	return m_GPA;
}

// student.cpp에서 쓰일 AveGPA를 위한 return값 함수
int Subject::GetHakjum()
{
	return m_hakjum;
}

string Subject::GetName() {
	return m_name;
}


string Subject::GetGrade() {
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
	cout << m_name << ", 학점 : " << m_hakjum << ", 등급 : " << m_grade << "의 정보를 수정하세요.\n";
	cout << "교과목명 : ";
	InputValue(m_name);
	cout << "과목학점 : ";
	InputValue(m_hakjum);
	cout << "과목 등급 : ";
	InputValue(m_grade);
	CalcGPA();	
}