
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Задача 1 Тип данных
void type_of(int num);
void type_of(double num);
void type_of(char num);

// Задача 2 Рекурсия. Сумма от А до В.
int sum_AB(int num1, int num2);

// Задача 3 Поиск и сортировка в массиве.
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end);
template <typename T>
void show_arr(T arr[], const int length);
template <typename T>
void middle_sort(T arr[], const int length);

// Задача 4 Сдвиг массива.
template <typename T>
void move_arr(T arr[], const int length, int num);

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	// Задача 1 Тип данных
	/*std::cout << " Задача 1.\n";
	std::cout << " 12 - ";
	type_of(12);
	std::cout << " 9.11 - ";
	type_of(9.11);
	std::cout << " \'T\' - ";
	type_of('T');
	std::cout << "\n\n";
	*/

	// Задача 2 Рекурсия. Сумма от А до В.
	/*std::cout << " Введите 2 числа --> ";
	std::cin >> n >> m;
	std::cout << " Сумма чисел от " << n << " до " << m << " = " << sum_AB(n, m) << "\n\n";
	*/

	// Задача 3 Поиск и сортировка в массиве.
	/*std::cout << " Изначальный массив: \n";
	const int size3 = 20;
	int arr3[size3];
	fill_arr(arr3, size3, -20, 21);
	show_arr(arr3, size3);
	middle_sort(arr3, size3);
	std::cout << " Окончательный массив: \n";
	show_arr(arr3, size3);
	std::cout << "\n";
	*/

	// Задача 4 Сдвиг массива.
	std::cout << " Изначальный массив: \n";
	const int size4 = 5;
	int arr4[size4]{ 1, 2, 3, 4, 5};
	show_arr(arr4, size4);
	std::cout << " Введите кол-во сдвигов: ";
	std::cin >> n;
	move_arr(arr4, 5, n);
	std::cout << " Итоговый массив: ";
	show_arr(arr4, size4);

	return 0;
}

//Задача 1 Тип данных
void type_of(int num) {
	std::cout << "INT\n";
}
void type_of(double num) {
	std::cout << "DOUBLE\n";
}
void type_of(char num) {
	std::cout << "CHAR\n";
}

// Задача 2. Рекурсия.Сумма от А до В.
int sum_AB(int A, int B) {
	if (B == A + 1)
		return A + B;
	return sum_AB(A, B - 1) + B;
}

// Задача 3 Поиск и сортировка в массиве.
//Заполняет массив случайными числами из диапазона от begin до end.
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
// Вывод массива в консоль.
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename T>
void middle_sort(T arr[], const int length) {
	int x = 0, y = 0;
	//Первый отрицательный элемент
	for (int i = 0; i < length; i++)
		if (arr[i] < 0) {
			x = i;
			break;
		}
	//Последний отрицательный элемент
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] < 0) {
			y = i;
			break;
		}
	//Пузырьковая сортировка.
	/*for (int i = y - 1; i > x + 1; i--)
		for (int j = x + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j+1]);
				*/
	//Быстрая сортировка
	std::sort(arr + x + 1, arr + y - 1);
}

// Задача 4 Сдвиг массива.
template <typename T>
void move_arr(T arr[], const int length, int num) {
	if (num >= 0) //Сдвиги вправо
		for(int j = 0; j < num; j++)
			for (int i = length - 2; i >= 0; i--)
				std::swap(arr[i], arr[i + 1]);
	else //Сдвиги влево
		for (int j = num; j < 0; j++)
			for (int i = 0; i < length - 1; i++)
				std::swap(arr[i], arr[i + 1]);
}