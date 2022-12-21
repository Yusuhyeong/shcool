/*************************************************************************************************/
/*             HW#6 : ���ڿ�                                                                     */
/*  �ۼ��� : ������                                ��¥ : 2021�� 4�� 16��                        */
/*                                                                                               */
/* ���� ���� : ������ �ִ� HW#4�� �ڵ忡�� �迭�� �Է¹޴� �������� getline�� ����               */
/*             ���ڿ� �Է��� �ް� ���� �迭�� �ԷµǴ� ������ ��� string ���ڿ���               */
/*             ���� �޵��� �Ѵ�.                                                                 */
/*             ������ �ִ� ModifyStdInfo�Լ��� �л����� �Ӹ� �ƴ϶� ������ ������                */
/*             �������� ������ �� �ֵ��� �ڵ带 �����Ѵ�.                                        */
/*************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string.h>
#include<string> // getline����
#include<cstring>
using namespace std;


struct Subject { // ��������
    string SubName; // �����̸� (string���� ����)
    int Hakjum; // ��������
    string Grade; // ������
    float GPA; // ��������
};

struct Student { // �л�����
    string StdName; // �л��̸� (string���� ����)
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
inline void InputValue(string& str); //���ڸ� �Է¹޾� ���־��� inputvalue�� (�����, �л��� ���)
void ModifyStdInfo(Student* pSt, int StudentNum); // �л��� ������ �����ϴ� �Լ�
void PrintAllStdList(const Student* pSt, int StudentNum = 2); // � �л��� ������ ����ִ��� �����ִ� �Լ�
void InputData(Student* pSt, int StudentNum); // �л��� ������ �Է¹޴� �Լ�
inline void PrintMenu(); // �޴� ����� ���� �Լ�
Subject* SubSearch(const Student* pSt); // �������� ������ �ʿ��� search�� ���� �Լ�

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
            else if (SearchStd == NULL)
                cout << "�л��� ������ �����ϴ�.\n";
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
    int result = 0;

    for (i = 0; i < StudentNum; i++)
    {
        sum = sum + (Sub + i)->GPA; // �������� ������ ��� Subject ������ Sub���� GPA�� ��ġ�� ��ĭ�� �ű�� ���� ���Ѵ�.
        result = result + Sub[i].Hakjum;
    }
    avg = sum / result; // sum�� ���� ���� result���� ������ avg�� ���ϰ�

    return avg; // avg�� ����
}

Student* StdSearch(Student* pSt, int StudentNum) // �л��� �̸��� ���� �˻��ϴ� �Լ�
{
    int i;
    string name; // �л� �̸��� �Է��� ����
    InputValue(name);

    for (i = 0; i < StudentNum; i++)	// �л� StudentNum�� ���� ������ �Է¹޽��ϴ�.
    {
        if (name == pSt[i].StdName)			//�Է��� name�� StudrntName�� ���ؼ� 0(�ΰ��� ������)
            return &pSt[i];					//���
        else
            continue;
    }

    return NULL;
}

void ModifyStdInfo(Student* pSt, int StudentNum)
{
    Student* Searchstd = StdSearch(pSt, StudentNum); // �˻��� ���� �Է¹��� �л��� �̸��� ã���ϴ�.

    if (Searchstd != NULL)
    {
        string Type; // "�л�����" �Ǵ� "��������" ���ڿ� ����� string
        cout << "����(�л�����/��������):";
        InputValue(Type); // Type�� �Է�
        cout << "\n";
        if (Type == "�л�����") // Type���� �Է¹��� ���ڿ��� "�л�����"�� ���
        {
            cout << Searchstd->StdName << Searchstd->Hakbun << "�� ������ �����ϼ���\n"; // �Է¹��� [�л��̸�]�� [�й�]�� ����
            cout << "�̸� : ";
            InputValue(Searchstd->StdName); // �л��� �̸��� �ֽ��ϴ�.
            cout << "\n";
            cout << "�й� :"; 
            InputValue(Searchstd->Hakbun); // �л��� �й��� �ֽ��ϴ�
        }
        else if (Type == "��������") // Type���� �Է¹��� ���ڿ��� "��������"�� ���
        {
            string Name; // �˻��� ���� ���� String
            cout << "�˻��� ���� �̸� : ";
            InputValue(Name); // ������ ������ �̸��� �Է��մϴ�.
            if (Searchstd->Sub->SubName == Name) // �Է��� ������ �̸��� ���� �˻��� �л��� ������ ������ ��
            {
                Subject* Sub = SubSearch(Searchstd);

                cout << Searchstd->Sub->SubName << ", ���� : " << Searchstd->Sub->Hakjum << ", ��� : " << Searchstd->Sub->Grade << "�� ������ �����ϼ���";
                cout << "\n\n";
                cout << "������� : ";
                InputValue(Searchstd->Sub->SubName);
                cout << "���������� : ";
                InputValue(Searchstd->Sub->Hakjum);
                cout << "������(A+ ~ F) : ";
                InputValue(Searchstd->Sub->Grade);
                cout << "\n";
                for (int i = 0; i < StudentNum; i++)
                {   
                    for (int j = 0; j < pSt[i].SubNum; j++)
                    {
                        CalcGPA(pSt[i].Sub[j]); // �Է¹��� ������ ��޺� ���� ��� ��
                        pSt[i].Sub[j].GPA = pSt[i].Sub[j].GPA * pSt[i].Sub[j].Hakjum; // ���� ���

                    }
                    Searchstd->AveGPA = CalcAveGPA(Searchstd->Sub, Searchstd->SubNum); // ������� ����
                }
            }
            else // �Է¹��� ������ ���� ���
            {
                cout << "\n\n";
                cout << "�ش� ������ �����ϴ�.";
                cout << "\n\n";
            }
        }
    }
    else // �˻��ϴ� �л��� �̸��� ���� ���
        cout << "�߸� �Է��ϼ̽��ϴ�.\n\n";
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

inline void InputValue(string& str) // ���־��̴� ���ڿ� �Է��� inline�Լ��� ����
{
    getline(cin, str);
}

inline void InputValue(int& i) // ���־��̴� ���� �Է��� inline�Լ��� ����
{
    cin >> i;
    cin.ignore(); // �Է¹��� ����
}

void InputData(Student* pSt, int StudentNum) // �л��� ������ �Է¹޴� �Լ�
{
    int i, j;
    float sum = 0;
    for (i = 0; i < StudentNum; i++) // StudentNum���� �л� ����ŭ �Է��մϴ�.
    {
        //�л��� �̸�, �й�, ������ ���� ���� ������ �Է� �մϴ�.
        cout << i + 1 << " ��° �л� �̸��� �й��� �Է��ϼ���." << "\n";
        cout << "�̸� : ";
        InputValue(pSt[i].StdName);
        cout << "�й� : ";
        InputValue(pSt[i].Hakbun);
        cout << "\n\n\n";
        cout << "���� ���� �Է��ϼ��� : ";
        InputValue(pSt[i].SubNum);
        pSt[i].Sub = new Subject[pSt[i].SubNum]; // �Է¹��� ����� ��ŭ�� �����Ҵ� �մϴ�.
        cout << "������ ���� " << pSt[i].SubNum << "���� �� �������, ��������, �������� �Է��ϼ���." << "\n";

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

Subject* SubSearch(const Student* pSt)
{
    string Sub; // �˻��� �����

    for (int i = 0; i < pSt->SubNum; i++) // ����� ��ŭ �ݺ�
    {
        if (Sub == pSt->Sub[i].SubName) // �˻��� ����� ������ ������ �̸��� ������
            return &pSt->Sub[i]; // ���� return
        else continue;
    }
}