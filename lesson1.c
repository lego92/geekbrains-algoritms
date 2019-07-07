/*
 *	�������� ���� ����������
 *
 *	1. ���������� � ������� ������ ����� ���� �� ������� I = m / (h * h), ��� m � ����� ���� � �����������,
 *	   h � ���� � ������.
 *  2. �������� ��������� ���������� ������ ��������� ����������� ���������.
 *  3. ������ ������� �������� (�� 1 �� 150 ���) � ������� ��� ������ �� ������ ����, ����� ��� ����.
 *  4. ���� �������� ���������� ���� ����� ��������� ����� (x1, y1, x2, y2).
 *     ��������� ����������, ��������� �� � ���� � ������ ����� ��� ���.
 *  5. ����������� �����. ����������� ����� ���������� �����������,
 *     ���� ��� ����� ��������� ������ ������ ��������. ��������, 25 ^ 2 = 625.
 *     �������� �������, ������� ������� �� ����� ��� ����������� �����, ������ ������ �����
 */

#include <stdio.h>
#include <math.h>

// ��������� ������ ����� ����
float BMI(float weight, float height)
{
	return weight / (height * height);
}

// ������ ���������� ���������
void quadrEq(float a, float b, float c)
{
	float dis;	// ������������
	float x1,x2;// ����� ���������

	dis = b*b - 4*a*c;
	if(dis > 0)
	{
		x1 = (-b + sqrt(dis))/(2*a);
		x2 = (-b - sqrt(dis))/(2*a);
		printf("��������� ����� ��� ����� : %.2f � %.2f\n", x1, x2);
	}
	else if (dis == 0)
	{
		x1 = -b / (2*a);
		x2 = x1;
		printf("��������� ����� ��� ���������� ����� : %.2f � %.2f\n", x1, x2);
	}
	else
	{
		printf("� ��������� ��� ������ :(\n");
	}
}

// ��������� ������� �������
void ageGuru(int age)
{
	int lastDigit;	// ��������� ����� � ��������

	lastDigit = age % 10;

	switch (lastDigit)
	{
		case 1:
			printf("������� - %d ���\n", age);
			break;
		case 2:
		case 3:
		case 4:
			printf("������� - %d ����\n", age);
			break;
		default:
			printf("������� - %d ���\n", age);
	}
}

// ���������� ������ ����� ���� ��������� ����� ��� ���
int isSameColor(int x1, int y1, int x2, int y2)
{
	if((((x1 + y1) % 2 == 0) && ((x2 + y2) % 2 == 0)) || (((x1 + y1) % 2 != 0) && ((x2 + y2) % 2 != 0))) return 1;
	else return 0;
}

// ������� ����������� ����� ������ ������ �����
void getAutomorphicNumbers()
{
	int currentNumber;
	int s;
	int flag;

	for(int i = 1; i < 10000; i++)
	{
		 currentNumber = i;
		 s = i * i;
		 flag = 1;

         while(currentNumber > 0)  // 25 ^ 2 = 625
         {
        	 if(currentNumber % 10 == s % 10)
        	 {
        		 currentNumber /= 10;
        		 s /= 10;
        	 }
        	 else
        	 {
        		 flag = 0;
        		 break;
        	 }
         }

         if(flag) printf("%d\n", i);
	}
}

int main()
{
	printf("������ ����� ���� ��� ����� %.1f �� � ����� %.2f � ����� %.2f\n", 85.5, 1.71, BMI(85.5, 1.71));
	quadrEq(1,4,-14);
	ageGuru(20);
	printf("���� � ������������ [%d;%d] %s ����� � ����� � ������������ [%d;%d]\n" , 3, 2, (isSameColor(3,2,6,7)) ? "������" : "�������", 6, 7);
	getAutomorphicNumbers();
	return 0;
}
