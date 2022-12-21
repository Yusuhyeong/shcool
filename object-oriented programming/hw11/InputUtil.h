#pragma once
#ifndef INPUTUTIL_H
#define INPUTUTIL_H
#include <iostream>
#include <string>
using namespace std;

class InputUtil {
public:
	inline static void InputValue(int& i) {
		do cin >> i;
		while (!CheckType());
	};
	inline static void InputValue(string& str) {
		getline(cin, str);
		//string��ü�� �Է��� ���۰� ���� ����
	};
	inline static void InputValue(char* ch) {
		do cin >> ch;
		while (!CheckType());
	};
	inline static void InputValue(float& f) {
		do cin >> f;
		while (!CheckType());
	};
	inline static void InputValue(double& d) {
		do cin >> d;
		while (!CheckType());
	};

	// ������ �ڷ��� üũ �� �Է� ���� Ȯ�� �Լ�
	static bool CheckType() {
		if (cin.fail()) {
			cout << "�߸��� ���� �ԷµǾ����ϴ�." << endl;
			cin.clear();
			cin.ignore(10, '\n'); // ���۸� �����.
			return false; // ���� ��ȯ
		}
		cin.clear();
		cin.ignore(10, '\n'); // �Է¹��۸� ���� ��
		return true; // ���� ��ȯ
	};
};

#endif INPUTUTIL_H