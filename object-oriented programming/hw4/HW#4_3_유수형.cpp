/*************************************************************************************************/
/*             HW#4_3 : 개선된 함수 기능                                                         */
/*  작성자 : 유수형                                날짜 : 2021년 4월 2일                         */
/*                                                                                               */
/* 문제 정의 : 기존에 있던 HW#3의 코드에서 자주쓰이는 입력을 함수화 시켜 inline                  */
/*             함수로 구현한다. (inputValue, PrintMenu)                                          */
/*             학생의 수, 수강한 과목수를 입력받아 그 수에 따른 할당을 해주면서                  */
/*             할당받은 학생의 수만큼 입력을 받을 수 있게 한다.                                  */
/*             추가된 함수인 수정, 목록에서 수정하는 함수는 이름을 검색하는 함수                 */
/*             를 통해 InputValue함수로 새로운 Value값을 넣어 수정한다.                          */
/*             목록을 불러오는 함수는 입력받은 학생의 수에 따라 동적할당을 받은                  */
/*             학생의 목록을 불러온다.                                                           */
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
    Subject* Sub; // 과목
    float AveGPA; // 교과목 평균 평점
    int SubNum;// 교과목 수 추가
};

void CalcGPA(Subject& Sub); // 교과목 평점 계산함수
float CalcAveGPA(Subject* Sub, int SubNum);	// 개인학생 평균평점 구하는 함수
void PrintOneData(const Student& rSt); // 개인학생 신상/정보 출력      
void PrintAllData(const Student* pSt, int StudentNum); // 전체 학생 신상/성적 정보
Student* StdSearch(Student* pSt, int StudentNum);  // 학생의 정보를 찾는 함수
inline void InputValue(int& i); // 숫자를 입력받아 자주쓰는 inputvalue들 (학생수, 과목수 등등)
inline void InputValue(char* str); //문자를 입력받아 자주쓰는 inputvalue들 (과목명, 학색명 등등)
void ModifyStdInfo(Student* pSt, int StudentNum); // 학생의 정보를 수정하는 함수
void PrintAllStdList(const Student* pSt, int StudentNum = 2); // 어떤 학생의 정보가 담겨있는지 보여주는 함수
void InputData(Student* pSt, int StudentNum); // 학생의 정보를 입력받는 함수
inline void PrintMenu(); // 메뉴 출력을 위한 함수

int main(void)
{
    int StdNum;
    cout << "학생수를 입력하세요 : "; // 학생의 수를 몇명으로 할 것인지 정합니다.
    InputValue(StdNum); // inline함수 inputValue를 통해 학생의 수를 입력받습니다.
    cout << "\n\n";
    Student* stu = new Student[StdNum]; // 입력받은 학생수에 따라 동적할당을 받습니다.
    PrintMenu();


    while (1) // 반복문의 재생으로 menu_id가 6일경우
    {         //프로그램을 종료합니다라는 문구와 함께 break문으로 while문을 나갑니다.
        int menu_id; // 메뉴를 선택할 수 있는 변수

        cout << "\n원하는 기능을 입력하세요 : "; // menu_id 입력을 위한 문구와 cin을 통해 값을 받는다.
        InputValue(menu_id); // 몇번 메뉴를 이용할 것인지 InputValue를 통해 받습니다.
        cout << "\n\n";

        if (menu_id == 1) // menu_id = 1일때
        {
            InputData(stu, StdNum); // 학생 정보를 입력받는 함수를 따로 구현하여 1번 메뉴에 넣습니다.
            PrintMenu(); // 자주쓰이는 PrintMenu를 while문에 넣음으로써 while문이 끝날때마다 호출하는 것이 아니라 메뉴가 끝날때마다 다시 호출합니다.
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
                PrintAllData(stu, StdNum); // 전체 학생의 정보를 출력하는 PrintAllData함수
                PrintMenu();
            }
        }

        else if (menu_id == 3) // menu_id가 3일 때
        {
            Student* SearchStd; // 입력받을 학생의 이름
            cout << "학생 이름을 입력하세요 : ";
            SearchStd = StdSearch(stu, StdNum); // 학생의 이름을 입력받아 그 학생에 대한 정보가 있는지 확인
            if (SearchStd != NULL)
                PrintOneData(*SearchStd); // 확인 후 입력받은 학생의 정보가 있다면 PrintOneData를 통해 그 학생의 정보만 출력
            PrintMenu();
        }

        else if (menu_id == 4) //  menu_id가 4일 때
        {
            PrintAllStdList(stu, StdNum); // 학생의 정보가 들어가 있는 학생을 불러옵니다.
            PrintMenu();
        }

        else if (menu_id == 5)
        {
            cout << "검색 할 학생 이름 : ";
            ModifyStdInfo(stu, StdNum); // 검색한 학생의 이름을 ModifyStdInfo함수에서 검색해 수정할 정보를 입력합니다.
            PrintMenu();
        }

        else if (menu_id == 6) // menu_id가 3일 경우 프로그램을 종료합니다.
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

inline void PrintMenu()
{
    cout << "==== 메뉴 ====\n";
    cout << "1. 학생 성적 입력\n"; // menu_id가 1일 경우 학생 성적을 입력할 수 있는 프로그램이 실행됩니다.
    cout << "2. 전체 학생 성적 보기\n"; // muenu_id가 2일 경우 학생 성적을 출력 할 수 있는 스포그램이 실행됩니다.
    cout << "3. 학생 이름 검색\n"; // 학생의 이름을 검색하여 학생에 대한 정보를 불러옵니다.
    cout << "4. 전체 학생 목록 보기\n"; // 정보가 들어있는 학생의 목록을 불러옵니다.
    cout << "5. 학생 정보 수정\n"; // 학생을 검색하여 이름과 학번을 수정합니다.
    cout << "6. 프로그램 종료\n"; // menu_id가 3일 경우 프로그램 종료 문구와 함께 break문으로 프로그램을 종료합니다.
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

float CalcAveGPA(Subject* Sub, int StudentNum) //평균 평점을 계산하는 함수
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

Student* StdSearch(Student* pSt, int StudentNum) // 학생의 이름을 통해 검색하는 함수
{
    int i;
    char name[50]; // 학생 이름을 입력할 변수
    InputValue(name);
    for (i = 0; i < StudentNum; i++)	// 학생 StudentNum명에 대한 정보를 입력받습니다.
    {
        if (strcmp(name, pSt[i].StdName) == 0) //입력한 name과 StudrntName를 비교해서 0(두개가 같을때)
            return &pSt[i]; //출력
        else
            continue;
    }
}

void ModifyStdInfo(Student* pSt, int StudentNum)
{
    pSt = StdSearch(pSt, StudentNum); // 검색을 위해 입력받은 학생의 이름을 찾습니다.
    cout << " < " << pSt->StdName << ", " << pSt->Hakbun << " > " << "의 정보를 수정하세요.\n";
    cout << "이름 : "; // 수정되는 학생의 이름을
    InputValue(pSt->StdName); // 넣습니다.
    cout << "\n";
    cout << "학번 :"; // 수정되는 학생의 학번을
    InputValue(pSt->Hakbun); // 넣습니다.
}

void PrintAllStdList(const Student* pSt, int StudentNum) // 정보가 있는 학생의 목록을 불러오는 함수
{
    cout << "===================================\n";
    cout << "\n";
    cout << "학번              이름";
    cout << "\n";
    cout << "===================================\n";
    cout << "\n";
    for (int i = 0; i < StudentNum; i++) // 입력받은 학생의 수 만큼 불러옵니다.
    {
        cout << pSt[i].Hakbun << "     " << pSt[i].StdName;
        cout << "\n";
        cout << "\n";
    }
    cout << "===================================\n";
    cout << "\n";
}

inline void InputValue(char* str) // 자주쓰이는 문자열 입력을 inline함수로 구현
{
    cin >> str;
}

inline void InputValue(int& i) // 자주쓰이는 숫자 입력을 inline함수로 구현
{
    cin >> i;
}

void InputData(Student* pSt, int StudentNum) // 학생의 정보를 입력받는 함수
{
    int i, j;
    float sum = 0;
    for (i = 0; i < StudentNum; i++) // StudentNum명의 학생 수만큼 입력합니다.
    {
        //학생의 이름, 학번, 수강한 과목에 대한 정보를 입력 합니다.
        cout << "*" << i + 1 << " 번째 학생 이름과 학번을 입력하세요." << "\n";
        cout << "이름 : ";
        InputValue(pSt[i].StdName);
        cout << "학번 : ";
        InputValue(pSt[i].Hakbun);
        cout << "\n\n\n";
        cout << "과목 수를 입력하세요 : ";
        InputValue(pSt[i].SubNum);
        pSt[i].Sub = new Subject[pSt[i].SubNum]; // 입력받은 과목수 만큼을 동적할당 합니다.
        cout << "수강한 과목" << pSt[i].SubNum << "개와 각 교과목명, 과목학점, 과목등급을 입력하세요." << "\n";

        for (j = 0; j < pSt[i].SubNum; j++)
        {
            // 따로 만든 stu에 대해 [j]값의 순서에 따라
            // [i]번째 학생의 
            cout << "교과목명 : ";
            InputValue(pSt[i].Sub[j].SubName); // 과목명
            cout << "과목학점수 : ";
            InputValue(pSt[i].Sub[j].Hakjum); // 과목의 학점
            cout << "과목등급(A+ ~ F) : ";
            InputValue(pSt[i].Sub[j].Grade); // 과목의 등급을 
                                             //입력합니다.
            cout << "\n";
            CalcGPA(pSt[i].Sub[j]); //i번째 학생이 있는 과목의 점수를 부여하는 함수를 이용합니다.
            pSt[i].Sub[j].GPA = pSt[i].Sub[j].GPA * pSt[i].Sub[j].Hakjum; // 학생의 평점을 계산해 줍니다.
        }
        pSt[i].AveGPA = CalcAveGPA(pSt[i].Sub, pSt[i].SubNum); // 이때 수강한 학생의 과목평균평점은
        cout << "\n\n\n";                                      // CalcAveGPA함수를 통해 i번째에 있는 학생의 평균평점을 순차적으로 계산합니다.
    }

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
    for (int i = 0; i < rSt.SubNum; i++)  // 학생이 각각 가지고 있는 교과목 3개의 정보를 출력합니다.
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

void PrintAllData(const Student* pSt, int StudentNum) // 모든 학생의 정보를 출력하는 함수
{
    for (int i = 0; i < StudentNum; i++) // PrintOneData가 한명의 학생을 출력합니다.
        PrintOneData(pSt[i]);            // StudentNum명의 학생에 대한 정보를 입력 받으므로 for문을 이용해 StudentNum명의 학생 정보가 출력됩니다.
}