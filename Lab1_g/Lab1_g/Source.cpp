#include <mpi.h>
#include <iostream>
#include <cstdlib>
#include <numeric>
#include <ctime> 
#include "Header.h"

using namespace std;

int* getRandomArray(int size);

int main(int argc, char **argv)
{

	int my_id, root_process, ierr, num_procs;
	MPI_Status status;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

	if (my_id == 0) {
		firstTask();
	}
	else if (my_id == 1) {
		secondTask();
	}
	else {
	}
	MPI_Finalize();
	return 0;
}

void secondTask()
{
	int size = 50;
	int *array = getRandomArray(size);
	int sum = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] % 2 == 0) {
			int element = array[i];
			sum += element * element;
		}
	}
	cout << "Task 2 " << sum;
}

void firstTask()
{
	int size = 60;
	int *array = getRandomArray(size);

	int sum = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] % 7 == 0) {
			sum += array[i];
		}
	}
	cout << "Task 1 " << sum;
}int* getRandomArray(int size) {	int *array = new int[size];

	srand((unsigned)time(0));

	for (int i = 0; i < size; i++) {
		array[i] = (rand() % 100) + 1;
		cout << array[i] << endl;
	}	return array;}