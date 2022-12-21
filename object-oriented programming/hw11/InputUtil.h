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
		//string객체의 입력은 버퍼가 남지 않음
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

	// 변수의 자료형 체크 및 입력 버퍼 확인 함수
	static bool CheckType() {
		if (cin.fail()) {
			cout << "잘못된 값이 입력되었습니다." << endl;
			cin.clear();
			cin.ignore(10, '\n'); // 버퍼를 지운다.
			return false; // 오류 반환
		}
		cin.clear();
		cin.ignore(10, '\n'); // 입력버퍼를 지운 후
		return true; // 정상값 반환
	};
};

#endif INPUTUTIL_H