/*************************************************************************************************/
/*             HW#3 : 구조체,레퍼런스,함수인자전달                                               */
/*  작성자 : 유수형                                날짜 : 2021년 3월 26일                        */
/*                                                                                               */
/* 문제 정의 : 기존에 있던 HW#1의 코드에서 구조체로 생성된 변수를 통해 레퍼런스,                 */
/*             함수인자전달을 이용하여 코드를 보안한다.                                          */
/*             각각 새로 생성된 함수는 학생의 정보를 출력하는 함수, 학생의 총점                  */
/*             을 계산하는 함수, 학생의 이름을 입력받아 찾는 함수를 만들어 각각                  */
/*             의 함수의 연관성을 잘 따져 보면서 어떤 인자를 이용하여 모듈화 하                  */
/*              며 구현하여야  하는지에 대해 생각해 본다.                                        */
/*************************************************************************************************/

#include <iomanip>
#include <string.h>
#include <iostream> 
using namespace std;


struct Subject { // 과목정보
    char SubName[30]; // 과목이름
    int Hakjum; // 과목학점
    char Grade[10]; // 과목등급
    float GPA; // 과목평점
};

struct Student { // 학생정보
    char StdName[30]; // 학생이름
    int Hakbun; // 학번
    Subject Sub[3]; // 과목
    float AveGPA; // 교과목 평균 평점
};

void PrintMenu(); // 메뉴 출력을 위한 함수
void CalcGPA(Subject& Sub); // 교과목 평점 계산함수
float CalcAveGPA(Subject* Sub);	// 개인학생 평균평점 구하는 함수
void PrintOneData(const Student& rSt); // 개인학생 신상/정보 출력      
void PrintAllData(const Student* pSt); // 전체 학생 신상/성적 정보
Student* StdSearch(Student* pSt, int StudentNum);  // 학생의 정보를 찾는 함수


int main(void)
{
    while (1) // 반복문의 재생으로 menu_id가 3일경우
    {         //프로그램을 종료합니다라는 문구와 함께 break문으로 while문을 나갑니다.
        int menu_id; // 메뉴를 선택할 수 있는 함수

        PrintMenu();
        cout << "\n원하는 기능을 입력하세요 : "; // menu_id 입력을 위한 문구와 cin을 통해 값을 받는다.
        cin >> menu_id;
        cout << "\n\n";
        struct Student stu[2]; // 학생 정보를 위한 student구조체에 stu[2]로 2명의 학생의 정보를 받을 수 있습니다.

        if (menu_id == 1) // menu_id = 1일때
        {

            for (int i = 0; i < 2; i++)
            {
                //학생의 이름, 학번, 수강한 과목에 대한 정보를 입력 합니다.
                cout << i + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
                cout << "이름 : ";
                cin >> stu[i].StdName;
                cout << "학번 : ";
                cin >> stu[i].Hakbun;

                cout << "\n\n 수강한 과목3개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
                for (int j = 0; j < 3; j++)
                {
                    // 따로 만든 stu에 대해 [j]값의 순서에 따라
                    // [i]번째 학생의 
                    cout << "교과목명 : ";
                    cin >> stu[i].Sub[j].SubName; // 과목명
                    cout << "과목학점수 : ";
                    cin >> stu[i].Sub[j].Hakjum; // 과목의 학점
                    cout << "과목등급(A+~F) : ";
                    cin >> stu[i].Sub[j].Grade; // 과목의 등급
                                                // 을 입력합니다.
                    CalcGPA(stu[i].Sub[j]); // i번째 학생이 있는 과목의 점수를 부여하는 함수를 이용합니다.
                    stu[i].Sub[j].GPA = stu[i].Sub[j].GPA * stu[i].Sub[j].Hakjum; // 학생의 평점을 계산해 줍니다.

                    stu[i].AveGPA = CalcAveGPA(stu[i].Sub);
                }
                stu[i].AveGPA = CalcAveGPA(stu[i].Sub); // 이때 수강한 학생의 과목평균평점은
                cout << "\n\n\n";                       // CalcAveGPA함수를 통해 i번째에 있는 학생의 평균평점을 순차적으로 계산합니다.
            }
        }
        else if (menu_id == 2) // menu_id가 2일 때
        {
            if (stu[0].Hakbun == NULL) // 만약 학생정보를 입력한 데이터가 없다면
            {
                cout << "학생들의 성적을 입력한 뒤에 사용할 수 있습니다.\n\n"; // 라는 문구를 보여줍니다.
            }                                                                // 문구가 끝난 뒤 다시 while문으로 돌아가 원하는 메뉴를 선택하는 프로그램이 실행됩니다.
            else // 학생 정보가 제대로 입력이 되어있다면
            {
                cout << "전체 학생 성적 보기\n";
                cout << "===================================================\n";
                PrintAllData(stu); // 전체 학생의 정보를 출력하는 PrintAllData함수
            }
        }

        else if (menu_id == 3) // menu가 3일 때
        {
            Student* SearchStd; // 입력받을 학생의 이름
            cout << "학생 이름을 입력하세요 : ";
            SearchStd = StdSearch(stu, 2); // 학생의 이름을 입력받아 그 학생에 대한 정보가 있는지 확인
            if (SearchStd != NULL) PrintOneData(*SearchStd); // 확인 후 입력받은 학생의 정보가 있다면 PrintOneData를 통해 그 학생의 정보만 출력
        }

        else if (menu_id == 4) // menu_id가 3일 경우 프로그램을 종료합니다.
        {
            cout << "프로그램을 종료합니다.\n";
            break; // break문으로 while문 탈출
        }
        else
        {
            return 0; // 프로그램 종료
        }
    }
}

void PrintMenu()
{
    cout << "==== 메뉴 ====\n";
    cout << "1. 학생 성적 입력\n"; // menu_id가 1일 경우 학생 성적을 입력할 수 있는 프로그램이 실행됩니다.
    cout << "2. 전체 학생 성적 보기\n"; // muenu_id가 2일 경우 학생 성적을 출력 할 수 있는 스포그램이 실행됩니다.
    cout << "3. 학생 이름 검색\n"; // 학생의 이름을 검색하여 학생에 대한 정보를 불러옵니다.
    cout << "4. 프로그램 종료\n"; // menu_id가 3일 경우 프로그램 종료 문구와 함께 break문으로 프로그램을 종료합니다.
}

void CalcGPA(Subject& Sub)
{

    if (Sub.Grade[0] == 'A') // A학점으로 시작할 경우에
    {
        if (Sub.Grade[1] == '+') // +기호가 붙을 경우 4.5
            Sub.GPA = 4.5;
        Sub.GPA = 4.0; // 그렇지 않은 경우 4.0을 부여
    }
    else if (Sub.Grade[0] == 'B') // B학점으로 시작할 경우에
    {
        if (Sub.Grade[1] == '+') // +기호가 붙을 경우 3.5
            Sub.GPA = 3.5;
        Sub.GPA = 3.0; // 그렇지 않을 경우 3.0을 부여
    }
    else if (Sub.Grade[0] == 'C') // C학점으로 시작할 경우에
    {
        if (Sub.Grade[1] == '+') // +기호가 붙을 경우 2.5
            Sub.GPA = 2.5;
        Sub.GPA = 2.0f; // 그렇지 않을 경우 2.0을 부여
    }
    else if (Sub.Grade[0] == 'D') // D학점으로 시작할 경우에
    {
        if (Sub.Grade[1] == '+') // +기호가 붙을 경우 1.5
            Sub.GPA = 1.5;
        Sub.GPA = 1.0; // 그렇지 않을 경우 1.0을 부여
    }
    else
    {
        Sub.GPA = 0; // 나머지는 0학점을 부여
    }
}

float CalcAveGPA(Subject* Sub) //평균 평점을 계산하는 함수
{
    //사용될 변수 초기값 부여
    float sum = 0;
    int i;
    float avg = 0;

    for (i = 0; i < 3; i++)
    {
        sum = sum + (Sub + i)->GPA; // 교과목의 정보가 담긴 Subject 포인터 Sub에서 GPA의 위치를 한칸씩 옮기며 합을 구한다.
    }
    avg = sum / 3.0; // sum에 대한 값을 3으로 나누어 avg를 구하고
    return avg; // avg를 리턴
}

void PrintOneData(const Student& rSt) // 학생의 정보를 출력해주는 함수
{
    // 한 학생에 대한 정보를 출력하기 위한 것이므로 rSt를 따로 선언
    cout << "===================================================\n";
    cout << "\n";
    cout << "이름 : " << rSt.StdName;
    cout.width(10);
    cout << "  학번 : " << rSt.Hakbun << "\n";
    cout << "===================================================\n";    cout << "\n";
    cout << "과목명";
    cout.width(14); 
    cout << "과목학점";
    cout.width(11); 
    cout << "과목등급";
    cout.width(11); 
    cout << "과목평점" << "\n";
    cout << "===================================================\n";    cout << "\n";
    for (int i = 0; i < 3; i++)  // 학생이 각각 가지고 있는 교과목 3개의 정보를 출력합니다.
    {
        // 학생이 가지고 있는 과목 정보에 따라
        // 교과목, 학점, 성적, 평점을 출력합니다.
        cout.precision(2); // 소수점 2자리 고정을 위한 문구입니다.
        cout << fixed;
        cout.width(10);
        cout << rSt.Sub[i].SubName;
        cout.width(10);
        cout << rSt.Sub[i].Hakjum;
        cout.width(10);
        cout << rSt.Sub[i].Grade;
        cout.width(10);
        cout << rSt.Sub[i].GPA;
        cout << "\n";
    }
    cout << "===================================================\n";    cout << "\n";
    cout.width(40);
    cout << "평균평점";
    cout.width(10);
    cout << rSt.AveGPA;
    cout << "\n";
}

void PrintAllData(const Student* pSt) // 모든 학생의 정보를 출력하는 함수
{
    for (int i = 0; i < 2; i++)
        PrintOneData(pSt[i]); // PrintOneData가 한명의 학생을 출력합니다.
}                             // 2명의 학생에 대한 정보를 입력 받으므로 for문을 이용해 2명의 학생 정보가 출력됩니다.

Student* StdSearch(Student* pSt, int StudentNum)
{
    int i;
    char name[50]; // 학생 이름을 입력할 변수
    cin >> name;
    for (i = 0; i < 2; i++)	// 학생 2명에 대한 정보를 입력받습니다.
    {
        if (strcmp(name, pSt[i].StdName) == 0) //입력한 name과 StudrntName를 비교해서 0(두개가 같을때)
            return &pSt[i]; //출력
        else
            continue;
    }
}
