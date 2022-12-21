/*************************************************************************************************/
/*             HW#4_3 : ������ �Լ� ���                                                         */
/*  �ۼ��� : ������                                ��¥ : 2021�� 4�� 2��                         */
/*                                                                                               */
/* ���� ���� : ������ �ִ� HW#3�� �ڵ忡�� ���־��̴� �Է��� �Լ�ȭ ���� inline                  */
/*             �Լ��� �����Ѵ�. (inputValue, PrintMenu)                                          */
/*             �л��� ��, ������ ������� �Է¹޾� �� ���� ���� �Ҵ��� ���ָ鼭                  */
/*             �Ҵ���� �л��� ����ŭ �Է��� ���� �� �ְ� �Ѵ�.                                  */
/*             �߰��� �Լ��� ����, ��Ͽ��� �����ϴ� �Լ��� �̸��� �˻��ϴ� �Լ�                 */
/*             �� ���� InputValue�Լ��� ���ο� Value���� �־� �����Ѵ�.                          */
/*             ����� �ҷ����� �Լ��� �Է¹��� �л��� ���� ���� �����Ҵ��� ����                  */
/*             �л��� ����� �ҷ��´�.                                                           */
/*************************************************************************************************/

#include <iomanip>
#include <string.h>
#include <iostream> 
using namespace std;


struct Subject { // ��������
    char SubName[30]; // �����̸�
    int Hakjum; // ��������
    char Grade[10]; // ������
    float GPA; // ��������
};

struct Student { // �л�����
    char StdName[30]; // �л��̸�
    int Hakbun; // �й�
    Subject* Sub; // ����
    float AveGPA; // ������ ��� ����
    int SubNum;// ������ �� �߰�
};

void CalcGPA(Subject& Sub); // ������ ���� ����Լ�
float CalcAveGPA(Subject* Sub, int SubNum);	// �����л� ������� ���ϴ� �Լ�
void PrintOneData(const Student& rSt); // �����л� �Ż�/���� ���      
void PrintAllData(const Student* pSt, int StudentNum); // ��ü �л� �Ż�/���� ����
Student* StdSearch(Student* pSt, int StudentNum);  // �л��� ������ ã�� �Լ�
inline void InputValue(int& i); // ���ڸ� �Է¹޾� ���־��� inputvalue�� (�л���, ����� ���)
inline void InputValue(char* str); //���ڸ� �Է¹޾� ���־��� inputvalue�� (�����, �л��� ���)
void ModifyStdInfo(Student* pSt, int StudentNum); // �л��� ������ �����ϴ� �Լ�
void PrintAllStdList(const Student* pSt, int StudentNum = 2); // � �л��� ������ ����ִ��� �����ִ� �Լ�
void InputData(Student* pSt, int StudentNum); // �л��� ������ �Է¹޴� �Լ�
inline void PrintMenu(); // �޴� ����� ���� �Լ�

int main(void)
{
    int StdNum;
    cout << "�л����� �Է��ϼ��� : "; // �л��� ���� ������� �� ������ ���մϴ�.
    InputValue(StdNum); // inline�Լ� inputValue�� ���� �л��� ���� �Է¹޽��ϴ�.
    cout << "\n\n";
    Student* stu = new Student[StdNum]; // �Է¹��� �л����� ���� �����Ҵ��� �޽��ϴ�.
    PrintMenu();


    while (1) // �ݺ����� ������� menu_id�� 6�ϰ��
    {         //���α׷��� �����մϴٶ�� ������ �Բ� break������ while���� �����ϴ�.
        int menu_id; // �޴��� ������ �� �ִ� ����

        cout << "\n���ϴ� ����� �Է��ϼ��� : "; // menu_id �Է��� ���� ������ cin�� ���� ���� �޴´�.
        InputValue(menu_id); // ��� �޴��� �̿��� ������ InputValue�� ���� �޽��ϴ�.
        cout << "\n\n";

        if (menu_id == 1) // menu_id = 1�϶�
        {
            InputData(stu, StdNum); // �л� ������ �Է¹޴� �Լ��� ���� �����Ͽ� 1�� �޴��� �ֽ��ϴ�.
            PrintMenu(); // ���־��̴� PrintMenu�� while���� �������ν� while���� ���������� ȣ���ϴ� ���� �ƴ϶� �޴��� ���������� �ٽ� ȣ���մϴ�.
        }
        else if (menu_id == 2) // menu_id�� 2�� ��
        {
            if (stu[0].Hakbun == NULL) // ���� �л������� �Է��� �����Ͱ� ���ٸ�
            {
                cout << "�л����� ������ �Է��� �ڿ� ����� �� �ֽ��ϴ�.\n\n"; // ��� ������ �����ݴϴ�.
            }                                                                // ������ ���� �� �ٽ� while������ ���ư� ���ϴ� �޴��� �����ϴ� ���α׷��� ����˴ϴ�.
            else // �л� ������ ����� �Է��� �Ǿ��ִٸ�
            {
                cout << "��ü �л� ���� ����\n";
                cout << "===================================================\n";
                PrintAllData(stu, StdNum); // ��ü �л��� ������ ����ϴ� PrintAllData�Լ�
                PrintMenu();
            }
        }

        else if (menu_id == 3) // menu_id�� 3�� ��
        {
            Student* SearchStd; // �Է¹��� �л��� �̸�
            cout << "�л� �̸��� �Է��ϼ��� : ";
            SearchStd = StdSearch(stu, StdNum); // �л��� �̸��� �Է¹޾� �� �л��� ���� ������ �ִ��� Ȯ��
            if (SearchStd != NULL)
                PrintOneData(*SearchStd); // Ȯ�� �� �Է¹��� �л��� ������ �ִٸ� PrintOneData�� ���� �� �л��� ������ ���
            PrintMenu();
        }

        else if (menu_id == 4) //  menu_id�� 4�� ��
        {
            PrintAllStdList(stu, StdNum); // �л��� ������ �� �ִ� �л��� �ҷ��ɴϴ�.
            PrintMenu();
        }

        else if (menu_id == 5)
        {
            cout << "�˻� �� �л� �̸� : ";
            ModifyStdInfo(stu, StdNum); // �˻��� �л��� �̸��� ModifyStdInfo�Լ����� �˻��� ������ ������ �Է��մϴ�.
            PrintMenu();
        }

        else if (menu_id == 6) // menu_id�� 3�� ��� ���α׷��� �����մϴ�.
        {
            cout << "���α׷��� �����մϴ�.\n";
            break; // break������ while�� Ż��
        }
        else
        {
            return 0; // ���α׷� ����
        }
    }
}

inline void PrintMenu()
{
    cout << "==== �޴� ====\n";
    cout << "1. �л� ���� �Է�\n"; // menu_id�� 1�� ��� �л� ������ �Է��� �� �ִ� ���α׷��� ����˴ϴ�.
    cout << "2. ��ü �л� ���� ����\n"; // muenu_id�� 2�� ��� �л� ������ ��� �� �� �ִ� �����׷��� ����˴ϴ�.
    cout << "3. �л� �̸� �˻�\n"; // �л��� �̸��� �˻��Ͽ� �л��� ���� ������ �ҷ��ɴϴ�.
    cout << "4. ��ü �л� ��� ����\n"; // ������ ����ִ� �л��� ����� �ҷ��ɴϴ�.
    cout << "5. �л� ���� ����\n"; // �л��� �˻��Ͽ� �̸��� �й��� �����մϴ�.
    cout << "6. ���α׷� ����\n"; // menu_id�� 3�� ��� ���α׷� ���� ������ �Բ� break������ ���α׷��� �����մϴ�.
}

void CalcGPA(Subject& Sub)
{

    if (Sub.Grade[0] == 'A') // A�������� ������ ��쿡
    {
        if (Sub.Grade[1] == '+') // +��ȣ�� ���� ��� 4.5
            Sub.GPA = 4.5;
        Sub.GPA = 4.0; // �׷��� ���� ��� 4.0�� �ο�
    }
    else if (Sub.Grade[0] == 'B') // B�������� ������ ��쿡
    {
        if (Sub.Grade[1] == '+') // +��ȣ�� ���� ��� 3.5
            Sub.GPA = 3.5;
        Sub.GPA = 3.0; // �׷��� ���� ��� 3.0�� �ο�
    }
    else if (Sub.Grade[0] == 'C') // C�������� ������ ��쿡
    {
        if (Sub.Grade[1] == '+') // +��ȣ�� ���� ��� 2.5
            Sub.GPA = 2.5;
        Sub.GPA = 2.0f; // �׷��� ���� ��� 2.0�� �ο�
    }
    else if (Sub.Grade[0] == 'D') // D�������� ������ ��쿡
    {
        if (Sub.Grade[1] == '+') // +��ȣ�� ���� ��� 1.5
            Sub.GPA = 1.5;
        Sub.GPA = 1.0; // �׷��� ���� ��� 1.0�� �ο�
    }
    else
    {
        Sub.GPA = 0; // �������� 0������ �ο�
    }
}

float CalcAveGPA(Subject* Sub, int StudentNum) //��� ������ ����ϴ� �Լ�
{
    //���� ���� �ʱⰪ �ο�
    float sum = 0;
    int i;
    float avg = 0;

    for (i = 0; i < 3; i++)
    {
        sum = sum + (Sub + i)->GPA; // �������� ������ ��� Subject ������ Sub���� GPA�� ��ġ�� ��ĭ�� �ű�� ���� ���Ѵ�.
    }
    avg = sum / 3.0; // sum�� ���� ���� 3���� ������ avg�� ���ϰ�

    return avg; // avg�� ����
}

Student* StdSearch(Student* pSt, int StudentNum) // �л��� �̸��� ���� �˻��ϴ� �Լ�
{
    int i;
    char name[50]; // �л� �̸��� �Է��� ����
    InputValue(name);
    for (i = 0; i < StudentNum; i++)	// �л� StudentNum�� ���� ������ �Է¹޽��ϴ�.
    {
        if (strcmp(name, pSt[i].StdName) == 0) //�Է��� name�� StudrntName�� ���ؼ� 0(�ΰ��� ������)
            return &pSt[i]; //���
        else
            continue;
    }
}

void ModifyStdInfo(Student* pSt, int StudentNum)
{
    pSt = StdSearch(pSt, StudentNum); // �˻��� ���� �Է¹��� �л��� �̸��� ã���ϴ�.
    cout << " < " << pSt->StdName << ", " << pSt->Hakbun << " > " << "�� ������ �����ϼ���.\n";
    cout << "�̸� : "; // �����Ǵ� �л��� �̸���
    InputValue(pSt->StdName); // �ֽ��ϴ�.
    cout << "\n";
    cout << "�й� :"; // �����Ǵ� �л��� �й���
    InputValue(pSt->Hakbun); // �ֽ��ϴ�.
}

void PrintAllStdList(const Student* pSt, int StudentNum) // ������ �ִ� �л��� ����� �ҷ����� �Լ�
{
    cout << "===================================\n";
    cout << "\n";
    cout << "�й�              �̸�";
    cout << "\n";
    cout << "===================================\n";
    cout << "\n";
    for (int i = 0; i < StudentNum; i++) // �Է¹��� �л��� �� ��ŭ �ҷ��ɴϴ�.
    {
        cout << pSt[i].Hakbun << "     " << pSt[i].StdName;
        cout << "\n";
        cout << "\n";
    }
    cout << "===================================\n";
    cout << "\n";
}

inline void InputValue(char* str) // ���־��̴� ���ڿ� �Է��� inline�Լ��� ����
{
    cin >> str;
}

inline void InputValue(int& i) // ���־��̴� ���� �Է��� inline�Լ��� ����
{
    cin >> i;
}

void InputData(Student* pSt, int StudentNum) // �л��� ������ �Է¹޴� �Լ�
{
    int i, j;
    float sum = 0;
    for (i = 0; i < StudentNum; i++) // StudentNum���� �л� ����ŭ �Է��մϴ�.
    {
        //�л��� �̸�, �й�, ������ ���� ���� ������ �Է� �մϴ�.
        cout << "*" << i + 1 << " ��° �л� �̸��� �й��� �Է��ϼ���." << "\n";
        cout << "�̸� : ";
        InputValue(pSt[i].StdName);
        cout << "�й� : ";
        InputValue(pSt[i].Hakbun);
        cout << "\n\n\n";
        cout << "���� ���� �Է��ϼ��� : ";
        InputValue(pSt[i].SubNum);
        pSt[i].Sub = new Subject[pSt[i].SubNum]; // �Է¹��� ����� ��ŭ�� �����Ҵ� �մϴ�.
        cout << "������ ����" << pSt[i].SubNum << "���� �� �������, ��������, �������� �Է��ϼ���." << "\n";

        for (j = 0; j < pSt[i].SubNum; j++)
        {
            // ���� ���� stu�� ���� [j]���� ������ ����
            // [i]��° �л��� 
            cout << "������� : ";
            InputValue(pSt[i].Sub[j].SubName); // �����
            cout << "���������� : ";
            InputValue(pSt[i].Sub[j].Hakjum); // ������ ����
            cout << "������(A+ ~ F) : ";
            InputValue(pSt[i].Sub[j].Grade); // ������ ����� 
                                             //�Է��մϴ�.
            cout << "\n";
            CalcGPA(pSt[i].Sub[j]); //i��° �л��� �ִ� ������ ������ �ο��ϴ� �Լ��� �̿��մϴ�.
            pSt[i].Sub[j].GPA = pSt[i].Sub[j].GPA * pSt[i].Sub[j].Hakjum; // �л��� ������ ����� �ݴϴ�.
        }
        pSt[i].AveGPA = CalcAveGPA(pSt[i].Sub, pSt[i].SubNum); // �̶� ������ �л��� �������������
        cout << "\n\n\n";                                      // CalcAveGPA�Լ��� ���� i��°�� �ִ� �л��� ��������� ���������� ����մϴ�.
    }

}

void PrintOneData(const Student& rSt) // �л��� ������ ������ִ� �Լ�
{
    // �� �л��� ���� ������ ����ϱ� ���� ���̹Ƿ� rSt�� ���� ����
    cout << "===================================================\n";
    cout << "\n";
    cout << "�̸� : " << rSt.StdName;
    cout.width(10);
    cout << "  �й� : " << rSt.Hakbun << "\n";
    cout << "===================================================\n";    cout << "\n";
    cout << "�����";
    cout.width(14);
    cout << "��������";
    cout.width(11);
    cout << "������";
    cout.width(11);
    cout << "��������" << "\n";
    cout << "===================================================\n";    cout << "\n";
    for (int i = 0; i < rSt.SubNum; i++)  // �л��� ���� ������ �ִ� ������ 3���� ������ ����մϴ�.
    {
        // �л��� ������ �ִ� ���� ������ ����
        // ������, ����, ����, ������ ����մϴ�.
        cout.precision(2); // �Ҽ��� 2�ڸ� ������ ���� �����Դϴ�.
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
    cout << "�������";
    cout.width(10);
    cout << rSt.AveGPA;
    cout << "\n";
}

void PrintAllData(const Student* pSt, int StudentNum) // ��� �л��� ������ ����ϴ� �Լ�
{
    for (int i = 0; i < StudentNum; i++) // PrintOneData�� �Ѹ��� �л��� ����մϴ�.
        PrintOneData(pSt[i]);            // StudentNum���� �л��� ���� ������ �Է� �����Ƿ� for���� �̿��� StudentNum���� �л� ������ ��µ˴ϴ�.
}