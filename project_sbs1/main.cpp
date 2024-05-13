#include <stdio.h>
#include <Windows.h> // GetasyncKeyState ���

#include "Graphic.h"
#include "Deltatime.h"

int main() {
	//���� ���α׷��� �⺻ ���� 
	
	//1.�ʱ�ȭ(initialize) > ��ġ �˻�, �ʷε� �� ���� �غ�
	InitGraphic(NULL, 0, 0, 1000, 1000);
	InitdeltaTime();

	//���� �߽� ��ǥ ����
	float x = 100, y = 200;
	float speed = 100;

	//���� ���� �ݺ���
	while (true) { 
		Clear(0, 0, 0);

		//2.������Ʈ > ���� �̵���ǥ, ü�� ��, , �Ӽ� ����
		deltaTimeUpdate();
		////�ȼ� �׸���
		//SetPixel(100, 100, 255, 0, 0);

		////�ȼ��� �簢�� �׸���
		//for (int i = 0; i < 100; ++i) {
		//	for (int j = 0; j < 200; ++j) {
		//		SetPixel(j, i, 0, 255, 255);
		//	}
		//}

		////����, ��, �簢�� �׸���
		//DrawLine(100, 100, 200, 2500, 0, 0, 255);
		//DrawCircle(200, 400, 300, 0, 0, 255);
		//DrawRect(100, 200, 400, 500, 0, 0, 255);

		//�̵��ϴ� �� >> ���� ��ǥ ���� >> ������Ʈ
		//x = x + 0.1;
		//y = y + 0.1;
		DrawCircle(x, y, 100, 0, 255, 255);

		//GetasyncKeyState �Լ� ����
		//GetAsyncKeyState(0x25); // 0x25 ���� ȭ��ǥ ����Ű �ڵ� ��
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

		//3. ��� ���(Rendering) > �̵� ��ǥ, ĳ���� ��� '''   
		Render();
	}

	//4. ���� ����.��ġ ��� ��, ���� ������ ����
	ExitGraphic();
	return  0;	
}