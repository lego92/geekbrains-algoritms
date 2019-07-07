/*
 *	Хецелиус Олег Валерьевич
 *
 *	1. Рассчитать и вывести индекс массы тела по формуле I = m / (h * h), где m – масса тела в килограммах,
 *	   h – рост в метрах.
 *  2. Написать программу нахождения корней заданного квадратного уравнения.
 *  3. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе со словом «год», «года» или «лет».
 *  4. Даны числовые координаты двух полей шахматной доски (x1, y1, x2, y2).
 *     Требуется определить, относятся ли к поля к одному цвету или нет.
 *  5. Автоморфные числа. Натуральное число называется автоморфным,
 *     если оно равно последним цифрам своего квадрата. Например, 25 ^ 2 = 625.
 *     Напишите функцию, которая выводит на экран все автоморфные числа, меньше десяти тысяч
 */

#include <stdio.h>
#include <math.h>

// вычисляет индекс массы тела
float BMI(float weight, float height)
{
	return weight / (height * height);
}

// решает квадратное уравнение
void quadrEq(float a, float b, float c)
{
	float dis;	// дискриминант
	float x1,x2;// корни уравнения

	dis = b*b - 4*a*c;
	if(dis > 0)
	{
		x1 = (-b + sqrt(dis))/(2*a);
		x2 = (-b - sqrt(dis))/(2*a);
		printf("Уравнение имеет два корня : %.2f и %.2f\n", x1, x2);
	}
	else if (dis == 0)
	{
		x1 = -b / (2*a);
		x2 = x1;
		printf("Уравнение имеет два одинаковых корня : %.2f и %.2f\n", x1, x2);
	}
	else
	{
		printf("У уравнения нет корней :(\n");
	}
}

// корректно выводит возраст
void ageGuru(int age)
{
	int lastDigit;	// последняя цифра в возрасте

	lastDigit = age % 10;

	switch (lastDigit)
	{
		case 1:
			printf("Возраст - %d год\n", age);
			break;
		case 2:
		case 3:
		case 4:
			printf("Возраст - %d года\n", age);
			break;
		default:
			printf("Возраст - %d лет\n", age);
	}
}

// определяет одного цвета поля шахматной доски или нет
int isSameColor(int x1, int y1, int x2, int y2)
{
	if((((x1 + y1) % 2 == 0) && ((x2 + y2) % 2 == 0)) || (((x1 + y1) % 2 != 0) && ((x2 + y2) % 2 != 0))) return 1;
	else return 0;
}

// выводит автоморфные числа меньше десяти тысяч
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
	printf("Индекс массы тела при массе %.1f кг и росте %.2f м равен %.2f\n", 85.5, 1.71, BMI(85.5, 1.71));
	quadrEq(1,4,-14);
	ageGuru(20);
	printf("Поле с координатами [%d;%d] %s цвета с полем с координатами [%d;%d]\n" , 3, 2, (isSameColor(3,2,6,7)) ? "одного" : "разного", 6, 7);
	getAutomorphicNumbers();
	return 0;
}
