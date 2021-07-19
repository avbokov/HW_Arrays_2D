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

	cout << "������� ������ ������� ��������� ��������� ��� ���������� �������: "; cin >> minRand;
	cout << "������� ������� ������� ��������� ��������� ��� ���������� �������: "; cin >> maxRand;

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
	cout << "�������� ������ ���������� ������� � ��������� �������� ���������: " << endl << endl;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}

	cout << endl;

	cout << "����� ��������� ������� �����: " << Sum << endl;
	cout << "������� �������������� ��������� ������� �����: " << (float)Sum / (ROWS * COLS) << endl;
	cout << "������������ �������� �������� �������: " << max << endl;
	cout << "����������� �������� �������� �������: " << min << endl;

	cout << endl;

	int buffer;

	for (int i = 0; i < ROWS; i++) // � ���� ����� ��������, ��� ��� ��� ���������� �������� ������ ������, ��� ��������� ������ � ������
	{								// �������, ��� ����������. � � �� ������, ��� ��� ���������. �� ��������� ��� ������.
		for (int j = 0; j < COLS; j++)
		{

			if (arr[i][j + 1] < arr[i][j])
			{
				if (arr[i][j] == arr[ROWS - 1][COLS - 1]) // ����� �� ����� �� ���������� �������� ������
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

	cout << "����������� ������ �� �����������: " << endl << endl;

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

	// ����� ������� 2D �� ���������� ����� �� �����:

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

	int candidate; // ����� ������ ���������� ))

	for (int k = 0; k < ROWS; k++)
	{
		for (int l = 0; l < COLS; l++)
		{
			arr[k][l] = rand() % (maxRand - minRand) + minRand;
			candidate = arr[k][l]; // ����� ���������� � ������� � ����� j �� �������� l ��� �� ������ ������ � ��������� ��� ������
			for (int i = 0; i <= k; i++) //i <= k ����� ��������� �� 0 �� ������� ������
			{
				if (k > 0) // ����� ������ �� ������
				{
					for (int j = 0; j < COLS; j++)
					{
						if (candidate == arr[i][j])
						{
							if (k == i && l == j) break; // �� ���������� ���� ������
							else
							{
								l--; // �������� ������ ������� ��� ���������� ����������
								i = k; // ��� ������ ����� �� ����� i,�.�.
								break; // ������ ������
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
	cout << "�������� ������ ���������� ������� � ��������� �������� ���������: " << endl << endl;

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
				cout << "���� ������:  " << candidate << " ����������� " << count_double << " ���(�)" << endl;
			}
			if (candidate >= 10)
			{
				cout << "���� ������: " << candidate << " ����������� " << count_double << " ���(�)" << endl;
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