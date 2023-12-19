#include <iostream>
#include <cstdlib>
#include <list>
#include <algorithm>
#include <chrono>

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define SIZE 100000

int i, n = SIZE;
int list[SIZE], temp[SIZE];
int comp[SIZE];
int sorted[SIZE];

enum Sorting {
	SELECTION,
	INSERTION,
	BUBBLE,
	SHELL,
	MERGE,
	QUICK,
	HEAP,
	MAXVALUE
};

// SelectionSort
void SelectionSort(int list[], int n) {
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[least])least = j;
		SWAP(list[i], list[least], temp);
	}
}

// InsertionSort
void InsertionSort(int list[], int n) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
	}
}

// BubbleSort
void BubbleSort(int list[], int n) {
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
	}
}

// ShellSort
void inc_insertion_sort(int list[], int first, int last, int gap) {
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}

void ShellSort(int list[], int n) {
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap);
	}

}

// MergeSort
void Merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i > mid)
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void MergeSort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(list, left, mid);
		MergeSort(list, mid + 1, right);
		Merge(list, left, mid, right);
	}
}

// QuickSort
int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (low <= right && list[low] < pivot);
		do
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}

void QuickSort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		QuickSort(list, left, q - 1);
		QuickSort(list, q + 1, right);
	}
}

// HeapSort
void heapify(int list[], int size, int root) {
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	int temp = list[root];

	if (left < size && list[left] > list[largest])
		largest = left;
	if (right < size && list[right] > list[largest])
		largest = right;
	if (largest != root) {
		SWAP(list[root], list[largest], temp);
		heapify(list, size, largest);
	}
}

void HeapSorting(int list[], int n) {
	int temp = list[0];

	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(list, n, i);
	for (int i = n - 1; i > -0; i--) {
		SWAP(list[0], list[i], temp);
		heapify(list, i, 0);
	}
}

void CheckSorting(int num) {
	switch (num) {
	case SELECTION:
		SelectionSort(list, n);
		std::cout << "SelectionSort : ";
		break;
	case INSERTION:
		InsertionSort(list, n);
		std::cout << "InsertionSort : ";
		break;
	case BUBBLE:
		BubbleSort(list, n);
		std::cout << "BubbleSort : ";
		break;
	case SHELL:
		ShellSort(list, n);
		std::cout << "ShellSort : ";
		break;
	case MERGE:
		MergeSort(list, 0, n);
		std::cout << "MergeSort : ";
		break;
	case QUICK:
		QuickSort(list, 0, n - 1);
		std::cout << "QuickSort : ";
		break;
	case HEAP:
		HeapSorting(list, n);
		std::cout << "HeapSort : ";
		break;
	}
}

int main() {
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		list[i] = rand() % 50000;
		temp[i] = list[i];
	}

	for (int num = 0; num < static_cast<int>(Sorting::MAXVALUE); num++) {
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		CheckSorting(num);
		std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
		std::cout << sec.count() << "s" << std::endl;

		for (i = 0; i < n; i++)
			list[i] = temp[i];
	}

	return 0;
}