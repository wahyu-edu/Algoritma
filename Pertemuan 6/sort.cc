#include <iostream>
#include <time.h>
using namespace std;

class TSort{
private:
	template <typename T>
	void merge_split(T *data, size_t l, size_t m, size_t r){
		int n1 = (m - l + 1);
		int n2 = (r - m);

		size_t x = 0;
		size_t y = 0;
		size_t z = 0;

		T *L;
		T *R;
		//Create arrays
		L = new T[n1]; // Left
		R = new T[n2]; // Right
		//Copy data to left array
		while (x < n1){
			L[x] = data[l + x];
			x++;
		}
		//Copy data to right array
		while (y < n2){
			R[y] = data[m + 1 + y];
			y++;
		}
		//Reset variables for next loops
		x = 0;
		y = 0;
		//Set z to left
		z = l;

		while (x < n1 && y < n2){
			//Compare left array to right array
			if (L[x] <= R[y]){
				//Set data
				data[z] = L[x];
				x++;
			}
			else{
				//Set data
				data[z] = R[y];
				y++;
			}
			z++;
		}
		//Copy any remaining left array back to data array
		while (x < n1){
			//Set data array with left array data
			data[z] = L[x];
			x++;
			z++;
		}
		//Copy any remaining right array back to data array
		while (y < n2){
			//Set data array with right array data
			data[z] = R[y];
			y++;
			z++;
		}
		//Delete left and right arrays.
		delete[]L;
		delete[]R;
	}
public:
	template <typename T>
	void merge_sort(T *data, size_t l, size_t r){
		if (l >= r){
			return;
		}
		int mid = l + (r - l) / 2;
		merge_sort(data, l, mid);
		merge_sort(data, mid + 1, r);
		merge_split(data, l, mid, r);
	}

	//Bubble Sort
	template <typename T>
	void bubble_sort(T *data, const size_t r){
		T temp;
		bool swapped;
		for (size_t x = 0; x < r; x++){
			swapped = false;
			for (size_t y = x + 1; y < r; y++){
				if (data[x] >= data[y]){
					temp = data[y];
					data[y] = data[x];
					data[x] = temp;
					swapped = true;
				}
			}
			if (!swapped){
				break;
			}
		}
	}

	//Insertion Sort
	template <typename T>
	void insertion_sort(T*data, const size_t size){
		size_t x;
		size_t y;
		T key;
		for (x = 1; x < size; x++){
			key = data[x];
			y = (x - 1);
			while (y >= 0 && data[y] > key){
				data[y + 1] = data[y];
				y--;
			}
			data[y + 1] = key;
		}
	}
	//Shell sort
	template <typename T>
	void shell_sort(T*data, const size_t size){
		T da;
		size_t x;
		size_t y;
		int interval = 1;

		while (interval <= size / 3){
			interval *= (3 + 1);
		}
		while (interval > 0){
			for (x = interval; x < size; x++){
				da = data[x];
				y = x;

				while (y > interval - 1 && data[y - interval] >= da){
					data[y] = data[y - interval];
					y -=interval;
				}
				data[y] = da;
			}
			interval += (-1 * 3);
		}
	}

	//Selection Sort
	template <typename T>
	void selection_sort(T*data, const size_t size){
		T temp;
		size_t min;
		for (size_t x = 0; x < size - 1; x++){
			min = x;
			for (int y = x + 1; y < size; y++){
				if (data[y] <= data[min]){
					min = y;
				}
			}
			temp = data[x];
			data[x] = data[min];
			data[min] = temp;
		}
	}
};

template <typename T>
void Display(T *data, const size_t size){
	size_t x = 0;
	while (x < size){
		cout << data[x] << " ";
		x++;
	}
	cout << endl;
}

int main(){
	int *nums;
	float test[6] = { 1.2, 3.6, 0.1, 6.3, 10.5, 1.3 };
	int test2[5] = { 48, 12 ,32, 28, 11 };
	double test3[7] = { 10, 18, 30, 12, 4, 11, 2.5 };
	int test4[9] = { 6, 2, 9, 1, 3, 5, 8, 4, 7 };
	size_t size = 12;
	nums = new int[size];
	TSort sort;

	srand(time(NULL));

	for (int x = 0; x < size; x++){
		nums[x] = rand() % 128;
	}

	cout << "--Algoritma Merge Sort--" << endl;
	cout << "Unsorted: ";
	Display(nums, size);
	sort.merge_sort<int>(nums, 0, (size - 1));
	cout << "Sorted:   ";
	Display(nums, size);

	cout << endl << "--Algoritma Bubble Sort--" << endl;
	cout << "Unsorted: ";
	Display(test, 6);
	sort.bubble_sort<float>(test, 6);
	cout << "Sorted: ";
	Display(test, 6);

	cout << endl << "--Algoritma Selection Sort--" << endl;
	cout << "Unsorted:  ";
	Display(test2, 5);
	sort.selection_sort(test2, 5);
	cout << "Sorted:    ";
	Display(test2, 5);

	cout << endl << "--Algoritma Insertion Sort--" << endl;
	cout << "Unsorted:  ";
	Display(test3, 7);
	sort.insertion_sort<double>(test3, 7);
	cout << "Sorted:    ";
	Display(test3, 7);

	cout << endl << "--Algoritma Shell Sort--" << endl;
	cout << "Unsorted:  ";
	Display(test4, 9);
	sort.shell_sort<int>(test4, 9);
	cout << "Sorted:    ";
	Display(test4, 9);

	delete[]nums;
	
	return 0;
}