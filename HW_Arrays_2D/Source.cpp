#include<iostream>
#include<ctime>


using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

#define TASK_1_2
//#define TASK_3_1D_TO_2D
//#define TASK_3_ANOTHER_WAY
//#define TASK_4

void main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

	const int ROWS = 8;
	const int COLS = 5;

	int arr[ROWS][COLS];
	int minRand, maxRand;

	cout << "Введите нижнюю границу числового диапазона для заполнения массива: "; cin >> minRand;
	cout << "Введите верхнюю границу числового диапазона для заполнения массива: "; cin >> maxRand;

#ifdef TASK_1_2

	int Sum = 0;
	int max = 0;
	int min = maxRand - 1;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;

			Sum = Sum + arr[i][j];

			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}

			if (arr[i][j] <= min)
			{
				min = arr[i][j];
			}
		}
	}

	cout << endl;
	cout << "Заполним массив случайными числами в указанном числовом диапазоне: " << endl << endl;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}

	cout << endl;

	cout << "Сумма элементов массива равна: " << Sum << endl;
	cout << "Среднее арифметическое элементов массива равно: " << (float)Sum / (ROWS * COLS) << endl;
	cout << "Максимальное значение элемента массива: " << max << endl;
	cout << "Минимальное значение элемента массива: " << min << endl;

	cout << endl;

	int buffer;

	for (int i = 0; i < ROWS; i++) // У меня такое ощущение, что эта моя сортировка работает только потому, что двумерный массив в памяти
	{								// записан, как одномерный. И я не уверен, что она корректна. Но сортирует без ошибок.
		for (int j = 0; j < COLS; j++)
		{

			if (arr[i][j + 1] < arr[i][j])
			{
				if (arr[i][j] == arr[ROWS - 1][COLS - 1]) // чтобы не выйти за выделенный диапазон памяти
				{
					break;
				}
				buffer = arr[i][j + 1];
				arr[i][j + 1] = arr[i][j];
				arr[i][j] = buffer;
				j = -1;
				i = 0;

			}
		}
	}

	cout << "Отсортируем массив по возрастанию: " << endl << endl;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
#endif // TASK_1_2

#ifdef TASK_3_1D_TO_2D

	int const n = ROWS * COLS;
	int arr_1D[n];

	for (int i = 0; i < n; i++)
	{
		arr_1D[i] = rand() % (maxRand - minRand) + minRand;

		for (int j = 0; j < i; j++)
		{
			if (arr_1D[i] == arr_1D[j])
			{
				i--;
				break;
			}
		}
	}

	int k = 0;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = arr_1D[k];
			k++;
		}
	}

	cout << endl;

	// Вывод массива 2D из УНИКАЛЬНЫХ чисел на экран:

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
#endif // TASK_3_1D_TO_2D

#ifdef TASK_3_ANOTHER_WAY
	cout << endl;

	int candidate; // очень важная переменная ))

	for (int k = 0; k < ROWS; k++)
	{
		for (int l = 0; l < COLS; l++)
		{
			arr[k][l] = rand() % (maxRand - minRand) + minRand;
			candidate = arr[k][l]; // чтобы отвязаться в условии в цикле j от значения l для не первой строки и проверять всю строку
			for (int i = 0; i <= k; i++) //i <= k чтобы преверять от 0 до текущей строки
			{
				if (k > 0) // когда строка не первая
				{
					for (int j = 0; j < COLS; j++)
					{
						if (candidate == arr[i][j])
						{
							if (k == i && l == j) break; // не сравнивать себя самого
							else
							{
								l--; // откатить индекс столбца для повторного заполнения
								i = k; // для выхода сразу из цикла i,т.к.
								break; // повтор найден
							}
						}
					}
				}
				else
				{
					for (int j = 0; j < l; j++)
					{
						if (arr[k][l] == arr[i][j])
						{
							l--;
							break;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
#endif // TASK_3_ANOTHER_WAY

#ifdef TASK_4
	int count_double = 0;
	int candidate = minRand;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}

	cout << endl;
	cout << "Заполним массив случайными числами в указанном числовом диапазоне: " << endl << endl;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}

	cout << endl;

	while (candidate < maxRand)
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				if (candidate == arr[i][j])
				{
					count_double++;
				}
			}

		}

		if (count_double > 1)
		{
			if (candidate < 10)
			{
				cout << "Есть повтор:  " << candidate << " повторяется " << count_double << " раз(а)" << endl;
			}
			if (candidate >= 10)
			{
				cout << "Есть повтор: " << candidate << " повторяется " << count_double << " раз(а)" << endl;
			}
			candidate++;
			count_double = 0;

		}
		else
		{
			candidate++;
			count_double = 0;
		}
	}
#endif // TASK_4

}