#include<iostream>
#include<string>
#include"student.h"
#include"subject.h"

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


// 동적으로 할당된 메모리 해제(m_sub)
void Student::Remove()
{
	delete[]m_sub;
}

// 학생에 대한 정보 입력 함수
void Student::InputData()
{

	cout << "이름 : ";
	InputValue(m_name);
	cout << "\n";
	cout << "학번 : ";
	InputValue(m_hakbun);
	cout << "\n";
	cout << "과목수 : ";
	InputValue(m_subnum);
	cout << "\n\n";
	cout << "수강한 과목" << m_name << "개와 각 교과목명, 과목등급을 입력하세요\n" << endl;
	m_sub = new Subject[m_subnum];
	for (int i = 0; i < m_subnum; i++)
		(m_sub + i)->InputData(); // 수강한 과목의 개수, 교과목명, 과목 등급을 입력 받을 땐 subject class에서 입력받는다.
	CalcAveGPA(); // 입력받은 과목에 대한 평균평점 계산
}

// 학생 정보 출력
void Student::PrintData()
{
	

	cout << "======================================================================" << endl;
	cout << "이름 : " << m_name << "  학번 : " << m_hakbun << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "  교과목명                학점수              등급        평점     " << endl;
	cout << "----------------------------------------------------------------------" << endl;
	for (int i = 0; i < m_subnum; i++)
	{
		(m_sub + i)->CalcGPA(); // 정보를 출력하기전 입력한 학생의 과목의 평점을 계산하고
		CalcAveGPA(); // 평균 평점을 계산한 뒤
		(m_sub + i)->PrintData(); // 학생의 과목 정보를 출력한다.
		cout << "\n";
	}
	cout << "======================================================================" << endl;
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