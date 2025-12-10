#include "PmergeMe.hpp"

void mergeVector(std::vector<int>& arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	std::vector<int> L(n1), R(n2);
	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	int i = 0, j = 0;
	int k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void	mergeSortVector(std::vector<int>& arr, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	mergeSortVector(arr, left, mid);
	mergeSortVector(arr, mid + 1, right);
	mergeVector(arr, left, mid, right);
}

void	mergeDeque(std::deque<int>& arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::deque<int> L(n1), R(n2);
	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	int i = 0, j = 0;
	int k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void	mergeSortDeque(std::deque<int>& arr, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	mergeSortDeque(arr, left, mid);
	mergeSortDeque(arr, mid + 1, right);
	mergeDeque(arr, left, mid, right);
}