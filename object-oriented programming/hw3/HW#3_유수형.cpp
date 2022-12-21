/*************************************************************************************************/
/*             HW#3 : ����ü,���۷���,�Լ���������                                               */
/*  �ۼ��� : ������                                ��¥ : 2021�� 3�� 26��                        */
/*                                                                                               */
/* ���� ���� : ������ �ִ� HW#1�� �ڵ忡�� ����ü�� ������ ������ ���� ���۷���,                 */
/*             �Լ����������� �̿��Ͽ� �ڵ带 �����Ѵ�.                                          */
/*             ���� ���� ������ �Լ��� �л��� ������ ����ϴ� �Լ�, �л��� ����                  */
/*             �� ����ϴ� �Լ�, �л��� �̸��� �Է¹޾� ã�� �Լ��� ����� ����                  */
/*             �� �Լ��� �������� �� ���� ���鼭 � ���ڸ� �̿��Ͽ� ���ȭ ��                  */
/*              �� �����Ͽ���  �ϴ����� ���� ������ ����.                                        */
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
    Subject Sub[3]; // ����
    float AveGPA; // ������ ��� ����
};

void PrintMenu(); // �޴� ����� ���� �Լ�
void CalcGPA(Subject& Sub); // ������ ���� ����Լ�
float CalcAveGPA(Subject* Sub);	// �����л� ������� ���ϴ� �Լ�
void PrintOneData(const Student& rSt); // �����л� �Ż�/���� ���      
void PrintAllData(const Student* pSt); // ��ü �л� �Ż�/���� ����
Student* StdSearch(Student* pSt, int StudentNum);  // �л��� ������ ã�� �Լ�


int main(void)
{
    while (1) // �ݺ����� ������� menu_id�� 3�ϰ��
    {         //���α׷��� �����մϴٶ�� ������ �Բ� break������ while���� �����ϴ�.
        int menu_id; // �޴��� ������ �� �ִ� �Լ�

        PrintMenu();
        cout << "\n���ϴ� ����� �Է��ϼ��� : "; // menu_id �Է��� ���� ������ cin�� ���� ���� �޴´�.
        cin >> menu_id;
        cout << "\n\n";
        struct Student stu[2]; // �л� ������ ���� student����ü�� stu[2]�� 2���� �л��� ������ ���� �� �ֽ��ϴ�.

        if (menu_id == 1) // menu_id = 1�϶�
        {

            for (int i = 0; i < 2; i++)
            {
                //�л��� �̸�, �й�, ������ ���� ���� ������ �Է� �մϴ�.
                cout << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
                cout << "�̸� : ";
                cin >> stu[i].StdName;
                cout << "�й� : ";
                cin >> stu[i].Hakbun;

                cout << "\n\n ������ ����3���� �� �������, ��������, �������� �Է��ϼ���.\n";
                for (int j = 0; j < 3; j++)
                {
                    // ���� ���� stu�� ���� [j]���� ������ ����
                    // [i]��° �л��� 
                    cout << "������� : ";
                    cin >> stu[i].Sub[j].SubName; // �����
                    cout << "���������� : ";
                    cin >> stu[i].Sub[j].Hakjum; // ������ ����
                    cout << "������(A+~F) : ";
                    cin >> stu[i].Sub[j].Grade; // ������ ���
                                                // �� �Է��մϴ�.
                    CalcGPA(stu[i].Sub[j]); // i��° �л��� �ִ� ������ ������ �ο��ϴ� �Լ��� �̿��մϴ�.
                    stu[i].Sub[j].GPA = stu[i].Sub[j].GPA * stu[i].Sub[j].Hakjum; // �л��� ������ ����� �ݴϴ�.

                    stu[i].AveGPA = CalcAveGPA(stu[i].Sub);
                }
                stu[i].AveGPA = CalcAveGPA(stu[i].Sub); // �̶� ������ �л��� �������������
                cout << "\n\n\n";                       // CalcAveGPA�Լ��� ���� i��°�� �ִ� �л��� ��������� ���������� ����մϴ�.
            }
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
                PrintAllData(stu); // ��ü �л��� ������ ����ϴ� PrintAllData�Լ�
            }
        }

        else if (menu_id == 3) // menu�� 3�� ��
        {
            Student* SearchStd; // �Է¹��� �л��� �̸�
            cout << "�л� �̸��� �Է��ϼ��� : ";
            SearchStd = StdSearch(stu, 2); // �л��� �̸��� �Է¹޾� �� �л��� ���� ������ �ִ��� Ȯ��
            if (SearchStd != NULL) PrintOneData(*SearchStd); // Ȯ�� �� �Է¹��� �л��� ������ �ִٸ� PrintOneData�� ���� �� �л��� ������ ���
        }

        else if (menu_id == 4) // menu_id�� 3�� ��� ���α׷��� �����մϴ�.
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

void PrintMenu()
{
    cout << "==== �޴� ====\n";
    cout << "1. �л� ���� �Է�\n"; // menu_id�� 1�� ��� �л� ������ �Է��� �� �ִ� ���α׷��� ����˴ϴ�.
    cout << "2. ��ü �л� ���� ����\n"; // muenu_id�� 2�� ��� �л� ������ ��� �� �� �ִ� �����׷��� ����˴ϴ�.
    cout << "3. �л� �̸� �˻�\n"; // �л��� �̸��� �˻��Ͽ� �л��� ���� ������ �ҷ��ɴϴ�.
    cout << "4. ���α׷� ����\n"; // menu_id�� 3�� ��� ���α׷� ���� ������ �Բ� break������ ���α׷��� �����մϴ�.
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

float CalcAveGPA(Subject* Sub) //��� ������ ����ϴ� �Լ�
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
    for (int i = 0; i < 3; i++)  // �л��� ���� ������ �ִ� ������ 3���� ������ ����մϴ�.
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

void PrintAllData(const Student* pSt) // ��� �л��� ������ ����ϴ� �Լ�
{
    for (int i = 0; i < 2; i++)
        PrintOneData(pSt[i]); // PrintOneData�� �Ѹ��� �л��� ����մϴ�.
}                             // 2���� �л��� ���� ������ �Է� �����Ƿ� for���� �̿��� 2���� �л� ������ ��µ˴ϴ�.

Student* StdSearch(Student* pSt, int StudentNum)
{
    int i;
    char name[50]; // �л� �̸��� �Է��� ����
    cin >> name;
    for (i = 0; i < 2; i++)	// �л� 2�� ���� ������ �Է¹޽��ϴ�.
    {
        if (strcmp(name, pSt[i].StdName) == 0) //�Է��� name�� StudrntName�� ���ؼ� 0(�ΰ��� ������)
            return &pSt[i]; //���
        else
            continue;
    }
}
