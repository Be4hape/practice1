#include "MyFunct.h"

bool IsUpper(char a) {
	if ('A' <= a && a <= 'Z') {
		return true;
	}
	else {
		return false;
	}
}

bool IsLower(char a) {
	if ('a' <= a && a <= 'z') {
		return true;
	}
	else {
		return false;
	}
}

bool IsAlpha(char a) {
	//if ('a' <= a && a <= 'z' || 'A' <= a && a <= 'Z') {
	//	printf("¾ËÆÄºªÀÓ");
	//	return true;
	//}
	if (IsUpper(a) == true || IsLower(a) == true) {
		return true;
	}
	else {
		return false;
	}
}

bool IsNumber(char a) {
	if ('0' <= a && a <= '9') {
		return true;
	}
	else {
		return false;
	}
}