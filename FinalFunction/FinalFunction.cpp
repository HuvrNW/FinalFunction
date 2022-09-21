
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// ������ 1 ��� ������
void type_of(int num);
void type_of(double num);
void type_of(char num);

// ������ 2 ��������. ����� �� � �� �.
int sum_AB(int num1, int num2);

// ������ 3 ����� � ���������� � �������.
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end);
template <typename T>
void show_arr(T arr[], const int length);
template <typename T>
void middle_sort(T arr[], const int length);

// ������ 4 ����� �������.
template <typename T>
void move_arr(T arr[], const int length, int num);

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	// ������ 1 ��� ������
	/*std::cout << " ������ 1.\n";
	std::cout << " 12 - ";
	type_of(12);
	std::cout << " 9.11 - ";
	type_of(9.11);
	std::cout << " \'T\' - ";
	type_of('T');
	std::cout << "\n\n";
	*/

	// ������ 2 ��������. ����� �� � �� �.
	/*std::cout << " ������� 2 ����� --> ";
	std::cin >> n >> m;
	std::cout << " ����� ����� �� " << n << " �� " << m << " = " << sum_AB(n, m) << "\n\n";
	*/

	// ������ 3 ����� � ���������� � �������.
	/*std::cout << " ����������� ������: \n";
	const int size3 = 20;
	int arr3[size3];
	fill_arr(arr3, size3, -20, 21);
	show_arr(arr3, size3);
	middle_sort(arr3, size3);
	std::cout << " ������������� ������: \n";
	show_arr(arr3, size3);
	std::cout << "\n";
	*/

	// ������ 4 ����� �������.
	std::cout << " ����������� ������: \n";
	const int size4 = 5;
	int arr4[size4]{ 1, 2, 3, 4, 5};
	show_arr(arr4, size4);
	std::cout << " ������� ���-�� �������: ";
	std::cin >> n;
	move_arr(arr4, 5, n);
	std::cout << " �������� ������: ";
	show_arr(arr4, size4);

	return 0;
}

//������ 1 ��� ������
void type_of(int num) {
	std::cout << "INT\n";
}
void type_of(double num) {
	std::cout << "DOUBLE\n";
}
void type_of(char num) {
	std::cout << "CHAR\n";
}

// ������ 2. ��������.����� �� � �� �.
int sum_AB(int A, int B) {
	if (B == A + 1)
		return A + B;
	return sum_AB(A, B - 1) + B;
}

// ������ 3 ����� � ���������� � �������.
//��������� ������ ���������� ������� �� ��������� �� begin �� end.
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
// ����� ������� � �������.
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
	//������ ������������� �������
	for (int i = 0; i < length; i++)
		if (arr[i] < 0) {
			x = i;
			break;
		}
	//��������� ������������� �������
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] < 0) {
			y = i;
			break;
		}
	//����������� ����������.
	/*for (int i = y - 1; i > x + 1; i--)
		for (int j = x + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j+1]);
				*/
	//������� ����������
	std::sort(arr + x + 1, arr + y - 1);
}

// ������ 4 ����� �������.
template <typename T>
void move_arr(T arr[], const int length, int num) {
	if (num >= 0) //������ ������
		for(int j = 0; j < num; j++)
			for (int i = length - 2; i >= 0; i--)
				std::swap(arr[i], arr[i + 1]);
	else //������ �����
		for (int j = num; j < 0; j++)
			for (int i = 0; i < length - 1; i++)
				std::swap(arr[i], arr[i + 1]);
}