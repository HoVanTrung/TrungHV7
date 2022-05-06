/*
Viết function như template dưới đây và call function trong hàm main()
int* get_even_num(int* arr, int* sz)
- Function: get_even_num:  trả về mảng chỉ chứa các số chẵn
- Parameter:
	+ arr:[I] vùng nhớ chứa mảng số nguyên
	+ sz:[O] kích thước của mảng chứa số chẵn
- Return: trả về con trỏ trỏ đến vùng nhớ chứa các số chẵn.

*/
#include <iostream>

using namespace std;

int* get_even_num(int* arr, int* sz)
{
	int n = _msize(arr) / sizeof(int);
	*sz = n;
	int* _pArray = new int(*sz);
	int count = 0;
	

	for (int idx = 0; idx < n; idx++)
	{
		if (*(arr + idx) % 2 == 0)
		{
			_pArray[count] = *(arr + idx);
			count++;
		}
		else {
			(*sz)--;
		}
	}
	return _pArray;
}

int main()
{
	int* pArray;
	int sz;
	int n;
	do
	{
		cout << "Nhap so phan tu cua mang: ";
		cin >> n;
	} while (n <= 0);

	pArray = new int[n];
	cout << endl;
	for (int idx = 0; idx < n; idx++)
	{
		cout << "A[" << idx << "] = ";
		cin >> *(pArray + idx);
	}
	int* Even = get_even_num(pArray, &sz);
	cout << "So phan tu mang chan la sz = " << sz;
	cout << "\nMang phan tu so chan la: ";
	for (int idx = 0; idx < sz; idx++) {
		cout << Even[idx] << " ";
	}
	
	delete[] pArray;
	return 0;
}
