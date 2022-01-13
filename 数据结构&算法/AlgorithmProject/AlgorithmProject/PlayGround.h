#pragma once
#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <iostream>
#include "SortTestHelper.h"

using namespace std;

namespace PlayGround
{
	// Quick Sort
	template<typename T>
	int __patition(T arr[], int l, int r)
	{
		T v = arr[l];
		int i = l + 1, j = r;

		while (true)
		{
			while (i < r && arr[i] < v)
			{
				i++;
			}
			while (j > l && arr[j] > v)
			{
				j--;
			}
			if (i >= j)
			{
				break;
			}

			swap(arr[i], arr[j]);
			i++;
			j--;
		}

		swap(arr[l], arr[j]);
		return j;
	}

	template<typename T>
	void __quickSort(T arr[], int l, int r)
	{
		if (l >= r)
		{
			return;
		}

		int p = __patition(arr, l, r);
		

		//SortTestHelper::printArray(arr, r - l + 1);

		__quickSort(arr, l , p - 1);
		__quickSort(arr, p + 1, r);
	}

	// Quick Sort
	template<typename T>
	void __quick(T arr[], int low, int high)
	{
		if (high <= low) return;
		int i = low;
		int j = high + 1;
		int key = arr[low];
		while (true)
		{
			/*���������ұ�key���ֵ*/
			while (arr[++i] < key)
			{
				if (i == high) {
					break;
				}
			}
			/*���������ұ�keyС��ֵ*/
			while (arr[--j] > key)
			{
				if (j == low) {
					break;
				}
			}
			if (i >= j) break;
			/*����i,j��Ӧ��ֵ*/
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		/*����ֵ��j��Ӧֵ����*/
		arr[low] = arr[j];
		arr[j] = key;
		__quick(arr, low, j - 1);
		__quick(arr, j + 1, high);
	}

	template<typename T>
	void quickSort(T arr[], int n)
	{
		__quickSort(arr, 0 , n - 1);
		//__quick(arr, 0, n - 1);
	}
}


#endif // !PLAYGROUND_H
