/*************************************************************************************************/
/*             실습#8 : 객체지향방식의 성적처리프로그램#1 작성                                   */
/*  작성자 : 유수형                                날짜 : 2021년 5월 7일                         */
/*                                                                                               */
/* 문제 정의 : 여태까지 작성된 성적처리 프로그램 #7까지의 내용을 분할 컴파일을 해본다.           */
/*             student class에 관련된 내용은 학생의 정보, subject class에 관련된 내용            */
/*             은 학생이 수강한 과목에 대한 정보를 담고 있다.                                    */
/*             실습 문제 3번은 학생이 수강한 과목에 대해 입력 할 때, 수강 과목에 대한 정보       */
/*             및 평균평점을 student class의 friends함수인 ShowData()를 통해 보여준다            */
/*************************************************************************************************/



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#include "Student.h"
#include "Subject.h"

// #실습 8-1
/*
void main() {
    Subject sub1, sub2, sub3[2], * sub4;
    int i;
    sub1.Initialize();

    sub2.Initialize("사진학", 3, "A+");

    for (i = 0; i < 2; i++)
        sub3[i].Initialize("컴퓨터", 3, "C ");

    sub4 = new Subject[2];

    sub1.InputData(); // 화면에서 입력

    cout << "\n" << "sub1 정보" << "\n";
    sub1.PrintTitle(); sub1.PrintData();

    cout << "\n" << "sub2 정보" << "\n";
    sub2.PrintTitle(); sub2.PrintData();

    cout << "\n" << "sub3 정보" << "\n";
    sub3[0].PrintTitle();

    for (i = 0; i < 2; i++) sub3[i].PrintData();

    for (i = 0; i < 2; i++) (sub4 + i)->InputData();

    cout << "\n" << "sub4 정보" << "\n";
    sub4->PrintTitle();
    for (i = 0; i < 2; i++) (sub4 + i)->PrintData();

    delete[] sub4;
}
*/


// #실습 8-3
/*
void main() {
    Subject sub[2];
    sub[0].Initialize("컴퓨터", 3, "C");
    sub[1].Initialize("현대무용", 2, "A");
    Student st1, st2;
    st1.Initialize();
    st2.Initialize("홍길동", 2013909845, 2, sub);
    st1.InputData();
    cout << "\n" << "st1 정보" << "\n";
    st1.PrintData();
    cout << "\n" << "st2 정보" << "\n";
    st2.PrintData();
    st1.Remove();
}
*/


// #실습 8-5
/*
void ShowData(const Student&);

void main() {
    Student st;
    st.Initialize();
    st.InputData();
    ShowData(st);
}

void ShowData(const Student& s) { // 응용프로그램에 있는 전역함수
    cout << s.m_name << "이 수강한 과목은 총" << s.m_subnum << "개로 ";
    cout << "수강한 과목의 평균평점은" << s.m_aveGPA << "입니다.\n";
}
*/