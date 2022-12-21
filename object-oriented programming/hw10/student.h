#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<string.h>
#include<iostream>
#include"subject.h"
#include<iomanip>
#include<cstring>
#include<string>
#include "InputUtil.h"

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
	Student();
	Student(string name, int hakbun, int subnum, Subject* sub);
	Student(const Student& std);
	~Student();
	//void Remove(); // 동적메모리 해제 (m_sub)
	void InputValue(int&);
	void InputValue(string&);
	void InputData(); // 멤버변수 값 입력
	void PrintData(); // 멤버변수 값 출력
	void CalcAveGPA(); // 평균 평점 계산
	friend void ShowData(const Student& s); // 학생이 수강한 과목에 대한 정보를 출력하는 friend함수
	string GetName();
	int GetHakbun();
	int GetSubNum();
	float GetAveGPA();
	void Modify(); // 학생정보, 과목정보, 모두를 통해 수정하는 함수
	void SetName(string);
	void SetHakbun(int);
	void SetSubNum(int);
	void SetaveGPA(float);
	Subject* SubSearch(string subname);         //과목명 검색
};

#endif STUDENT_H
