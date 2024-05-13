#include <stdio.h>
#include <Windows.h> // GetasyncKeyState 헤더

#include "Graphic.h"
#include "Deltatime.h"

int main() {
	//게임 프로그래밍 기본 구조 
	
	//1.초기화(initialize) > 장치 검색, 맵로드 등 게임 준비
	InitGraphic(NULL, 0, 0, 1000, 1000);
	InitdeltaTime();

	//원의 중심 좌표 변수
	float x = 100, y = 200;
	float speed = 100;

	//게임 동작 반복문
	while (true) { 
		Clear(0, 0, 0);

		//2.업데이트 > 게임 이동좌표, 체력 등, , 속성 갱신
		deltaTimeUpdate();
		////픽셀 그리기
		//SetPixel(100, 100, 255, 0, 0);

		////픽셀로 사각형 그리기
		//for (int i = 0; i < 100; ++i) {
		//	for (int j = 0; j < 200; ++j) {
		//		SetPixel(j, i, 0, 255, 255);
		//	}
		//}

		////직선, 원, 사각형 그리기
		//DrawLine(100, 100, 200, 2500, 0, 0, 255);
		//DrawCircle(200, 400, 300, 0, 0, 255);
		//DrawRect(100, 200, 400, 500, 0, 0, 255);

		//이동하는 원 >> 원의 좌표 갱신 >> 업데이트
		//x = x + 0.1;
		//y = y + 0.1;
		DrawCircle(x, y, 100, 0, 255, 255);

		//GetasyncKeyState 함수 연습
		//GetAsyncKeyState(0x25); // 0x25 왼쪽 화살표 가상키 코드 값
		//0x25 >> VK_LEFT, 0x26 >> VK_UP ' ' ' 
		short reft	= GetAsyncKeyState(VK_LEFT);
		short right	= GetAsyncKeyState(VK_RIGHT);
		short up	= GetAsyncKeyState(VK_UP);
		short down	= GetAsyncKeyState(VK_DOWN);

		float dist = DeltaTime() * speed;

		if (reft != 0) {
			x = x - dist;
		}
		if (right != 0) {
			x = x + dist;
		}
		if (up != 0) {
			y = y - dist;
		}
		if (down != 0) {
			y = y + dist;
		}

		//3. 장면 출력(Rendering) > 이동 좌표, 캐릭터 출력 '''   
		Render();
	}

	//4. 게임 종료.장치 사용 끝, 게임 데이터 저장
	ExitGraphic();
	return  0;	
}