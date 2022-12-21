/*************************************************************************************************/
/*             HW#7 : vector 클래스 사용해보기                                                   */
/*  작성자 : 유수형                                날짜 : 2021년 4월 30일                        */
/*                                                                                               */
/* 문제 정의 : 단어를 입력받아 단어가 등장하는 빈도수 세어 이를 해당 단어와 함께                 */
/*             저장하는 프로그램 을 작성한다.                                                    */
/*             단어, 단어 빈도 수에 대한 구조체 WORD를 구성하고                                  */
/*             단어, 단어 빈도 수를 저장할 vector 클래서를 구성하고                              */
/*             ctrl+z를 통해 프로그램이 종료 할 수 있도록 한다.                                  */
/*************************************************************************************************/




#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct WORD {
    string str; //각 단어의 내용
    int count; //각 단어의 사용 빈도
};

vector<WORD*> words; // WORD 구조체 포인터를 저장하는 벡터 객체

int CountWords(string buffer);
void PrintWords();
void RemoveAll();

int main(void) {
    cout << "문자열 입력(종료: Ctrl+Z)\n";
    string buffer; // 입력받을 문자열

    while (cin >> buffer) {
        if (buffer == "^Z") // 입력받은 버퍼가 Ctrl+Z라면
            break;          // 입력 종료
        CountWords(buffer); // 단어 세기, vector 안에 해당 단어가 있는지 검색 후
                            // 해당 단어가 발견되면 해당 단어의 빈도수를 1씩 증가시킴
                            // 단어가 발견되지 않으면 vector에 단어 추가 후 빈도수 1로 설정
    }

    PrintWords(); // 단어가 발견되지 않으면 vector에 단어 추가 후 빈도수 1로 설정
    RemoveAll(); // 동적 할당된 단어들을 해제.

    return 0;
}

int CountWords(string buffer) { // 단어의 수를 세는 함수
    int i = 0;
    WORD* temp;
    temp = new WORD;
    temp->str = buffer; // 입력 받은 문자
    temp->count = 1; // 그 문자의 개수

    while (i < words.size()) { // 실제 문자열이 있는 개수만큼
        if (words.empty()) // 문자열이 비어있는지 확인
            break; // while문 나가기
        if (words[i]->str == temp->str) { // 입력 받았던 문자와 입력 받은 문자를 비교 후 같으면
            ++words[i]->count; // 입력 받았던 문자에 대한 count값 증가
            delete temp; // temp 해제
            return 1;
        }
        i++; // 다음 단어
    }
    words.push_back(temp); // words에 temp 원소 삽입
    return 0;
}

void PrintWords() { // 단어와 단어의 빈도 수 출력
    cout << "===================\n";
    for (int i = 0; i < words.size(); i++) { // 입력받은 문자의 개수 만큼
        cout << words[i]->str << " : " << words[i]->count << "\n";
        //      입력받은문자       :         개수
    }
    cout << "===================\n";
}

void RemoveAll() { // 동적할당된 배열 해제
    for (int i = 0; i < words.size(); i++) // 입력받은 문자의 개수 만큼
        delete words[i]; // 동적할당 해제
}