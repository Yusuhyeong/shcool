/*************************************************************************************************/
/*             HW#7 : vector Ŭ���� ����غ���                                                   */
/*  �ۼ��� : ������                                ��¥ : 2021�� 4�� 30��                        */
/*                                                                                               */
/* ���� ���� : �ܾ �Է¹޾� �ܾ �����ϴ� �󵵼� ���� �̸� �ش� �ܾ�� �Բ�                 */
/*             �����ϴ� ���α׷� �� �ۼ��Ѵ�.                                                    */
/*             �ܾ�, �ܾ� �� ���� ���� ����ü WORD�� �����ϰ�                                  */
/*             �ܾ�, �ܾ� �� ���� ������ vector Ŭ������ �����ϰ�                              */
/*             ctrl+z�� ���� ���α׷��� ���� �� �� �ֵ��� �Ѵ�.                                  */
/*************************************************************************************************/




#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct WORD {
    string str; //�� �ܾ��� ����
    int count; //�� �ܾ��� ��� ��
};

vector<WORD*> words; // WORD ����ü �����͸� �����ϴ� ���� ��ü

int CountWords(string buffer);
void PrintWords();
void RemoveAll();

int main(void) {
    cout << "���ڿ� �Է�(����: Ctrl+Z)\n";
    string buffer; // �Է¹��� ���ڿ�

    while (cin >> buffer) {
        if (buffer == "^Z") // �Է¹��� ���۰� Ctrl+Z���
            break;          // �Է� ����
        CountWords(buffer); // �ܾ� ����, vector �ȿ� �ش� �ܾ �ִ��� �˻� ��
                            // �ش� �ܾ �߰ߵǸ� �ش� �ܾ��� �󵵼��� 1�� ������Ŵ
                            // �ܾ �߰ߵ��� ������ vector�� �ܾ� �߰� �� �󵵼� 1�� ����
    }

    PrintWords(); // �ܾ �߰ߵ��� ������ vector�� �ܾ� �߰� �� �󵵼� 1�� ����
    RemoveAll(); // ���� �Ҵ�� �ܾ���� ����.

    return 0;
}

int CountWords(string buffer) { // �ܾ��� ���� ���� �Լ�
    int i = 0;
    WORD* temp;
    temp = new WORD;
    temp->str = buffer; // �Է� ���� ����
    temp->count = 1; // �� ������ ����

    while (i < words.size()) { // ���� ���ڿ��� �ִ� ������ŭ
        if (words.empty()) // ���ڿ��� ����ִ��� Ȯ��
            break; // while�� ������
        if (words[i]->str == temp->str) { // �Է� �޾Ҵ� ���ڿ� �Է� ���� ���ڸ� �� �� ������
            ++words[i]->count; // �Է� �޾Ҵ� ���ڿ� ���� count�� ����
            delete temp; // temp ����
            return 1;
        }
        i++; // ���� �ܾ�
    }
    words.push_back(temp); // words�� temp ���� ����
    return 0;
}

void PrintWords() { // �ܾ�� �ܾ��� �� �� ���
    cout << "===================\n";
    for (int i = 0; i < words.size(); i++) { // �Է¹��� ������ ���� ��ŭ
        cout << words[i]->str << " : " << words[i]->count << "\n";
        //      �Է¹�������       :         ����
    }
    cout << "===================\n";
}

void RemoveAll() { // �����Ҵ�� �迭 ����
    for (int i = 0; i < words.size(); i++) // �Է¹��� ������ ���� ��ŭ
        delete words[i]; // �����Ҵ� ����
}