/*************************************************************************************************/
/*             실습#11 : 객체지향방식의 성적처리프로그램#4 작성                                  */
/*  작성자 : 유수형                                날짜 : 2021년 5월 28일                        */
/*                                                                                               */
/* 문제 정의 : 과제#10의 내용에서 과목을 찾은후 과목의 정보를 수정한다.                          */
/*             student 와 subject class는 IOInterface에 상속되고 생성자를 통해 상속된 변수에 대  */
/*             한 생성을 확인한다. 이때 상속된 변수가 무엇인지 실습문제 3번을 통해 확인한다.     */
/*************************************************************************************************/



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#include "InputUtil.h"
#include "student.h"
#include "subject.h"
#include "IOInterface.h"

/*
void main() {
	Student std;
	cout << std.GetData() << "\n"; // IOInterface Class에서 상속받은 멤버함수 호출
}
*/

/*
void main() {
	Subject sub("컴퓨터", 3, "C");
	cout << "-----------------------------\n";
	cout << "m_data : " << sub.GetData(); // Subject class에서 IOInterface에 m_data값 100으로 고정
	cout << "\n교과목 이름 : " << sub.GetName(); // subject에 대해서 name에 대한 변수 상속 -> 컴퓨터 출력
	cout << "\n부모클래스의 이름 : " << sub.IOInterface::GetName(); // sub는 IOInterface에 상속된 상태로 생성되고 IOInterface의 GetName함수를 호출 -> GetName의 return value는 컴퓨터
	cout << "\n-----------------------------\n\n";

	Student std("홍길동", 2013909845, 1, &sub);
	cout << "-----------------------------\n";
	cout << "m_data : " << std.GetData(); // Student class에서 IOInterface에 m_data값 300으로 고정
	cout << "\n학생 이름 : " << std.GetName(); // student에 대해서 name에 대한 변수 상속 -> 홍길동 출력
	cout << "\n부모클래스의 이름 : " << std.IOInterface::GetName(); // std는 IOInterface에 상속된 상태로 생성되고 IOInterface의 GetName함수를 호출 -> GetName의 return value는 홍길동
	cout << "\n-----------------------------\n\n";
}
*/

/*
void main() {
	Subject sub("컴퓨터", 3, "C");
	Student std("홍길동", 20138342, 1, &sub);
	std.PrintData();
	std.Modify(); // Student Class의 멤버변수 값 수정
	std.PrintData();
}
*/