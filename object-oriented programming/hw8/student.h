#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<string.h>
#include<iostream>
#include"subject.h"
#include<iomanip>
#include<cstring>
#include<string>
using namespace std;

class Student
{
protected:
	string m_name; // 학생명
	int m_hakbun; // 학번
	int m_subnum; // 수강한 과목 수
	Subject* m_sub; // 수강한 과목들
	float m_aveGPA; // 수강한 과목들의 평균 평점

public:
	void Initialize(); // 멤버변수 초기화
	void Initialize(string, int, int, Subject*); // 인자값으로 멤버변수 초기화
	void Remove(); // 동적메모리 해제 (m_sub)
	void InputValue(int&);
	void InputValue(string&);
	void InputData(); // 멤버변수 값 입력
	void PrintData(); // 멤버변수 값 출력
	void CalcAveGPA(); // 평균 평점 계산
	float GetAveGPA();
	friend void ShowData(const Student& s); // 학생이 수강한 과목에 대한 정보를 출력하는 friend함수

};

#endif STUDENT_H