#include <windows.h>
#include "Deltatime.h"

float StartTime, EndTime, deltatime;

void InitdeltaTime() {
	//delta timeº¯¼ö
	StartTime = GetTickCount64() / 1000.0f;
	EndTime   = GetTickCount64() / 1000.0f;
	deltatime = 0;
}

void deltaTimeUpdate() {
	EndTime   = GetTickCount64() / 1000.0f;
	deltatime = EndTime - StartTime;
	StartTime = GetTickCount64() / 1000.0f;
}

float DeltaTime() {
	return deltatime;
}