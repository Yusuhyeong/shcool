/*************************************************************************************************/
/*             실습#10 : 객체지향방식의 성적처리프로그램#3 작성                                  */
/*  작성자 : 유수형                                날짜 : 2021년 5월 21일                        */
/*                                                                                               */
/* 문제 정의 : 과제#9의 내용에서 과목 찾기, InputUtil헤더를 추가한다.                            */
/*             student와 subject class의 내부 멤버함수 중 멤버변수를 수정하지 않는 모든 함수에   */
/*             대해 모두 const 멤버함수로 수정하고 const객체를 사용할 수 있도록 확장시킨다.      */
/*             InputUtil class에 정적함수를 구현을 위해 기존의 Inputvalue함수를 대체한다.        */
/*************************************************************************************************/



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#include "InputUtil.h"
#include "Student.h"
#include "Subject.h"

void main() {
	Student std;
	std.InputData();
	std.PrintData();
	Subject* sub = std.SubSearch("사진학");
	// 과목명이 성공적으로 탐색된 경우
	// 해당 과목정보가 있는 메모리 주소를 리턴
	if (sub != NULL) {
		sub->PrintTitle();
		sub->PrintData();
	}

	else if (sub == NULL) {
		cout << "찾는 과목이 없습니다." << endl;
	}
}