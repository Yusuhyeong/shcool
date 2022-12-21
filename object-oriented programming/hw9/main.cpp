/*************************************************************************************************/
/*             실습#9 : 객체지향방식의 성적처리프로그램#2 작성                                   */
/*  작성자 : 유수형                                날짜 : 2021년 5월 14일                        */
/*                                                                                               */
/* 문제 정의 : 과제#8의 내용에서 수정, 생성자, 소멸자를 추가한다.                                */
/*             student class 내부의 생성자는 과목정보에 대한 내용도 가져올 수 있도록             */
/*             깊은 복사를 유도한다. 접근자 함수를 통해 각각 동적 할당 받은 주소에               */
/*             과목에 대한 정보를 복사하여 넣어준다.                                             */
/*             과목정보, 학생정보, 모든 정보에 대한 수정을 modify를 통해 구현한다.               */
/*************************************************************************************************/



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#include "Student.h"
#include "Subject.h"

void main() {
	Subject sub1("컴퓨터", 3, "C");
	Subject sub2(sub1);
	cout << "\n" << "sub1 정보" << "\n";
	sub1.PrintData();
	cout << "\n" << "sub2 정보" << "\n";
	sub2.PrintData();
	sub2.Modify();
	Student st1;
	Student st2("홍길동", 2013909845, 1, &sub1);
	Student st3("김성령", 2015909845, 1, &sub2);
	st1 = st2;
	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData();
	cout << "\n" << "st2 정보" << "\n";
	st2.PrintData();
	st2.Modify();
	cout << "\n" << "수정된 st2 정보" << "\n";
	st2.PrintData();
	st1.PrintData();
	cout << "\n" << "st3 정보" << "\n";
	st3.PrintData();
}