//Header files
#include<iostream>
#include<fstream>

//Declare namespace
using namespace std;

//Declare globle variable
int quickcount = 0;

//Declare ofstream file as global
ofstream selectionfile, bubblefile, quickfile, linearfile;


//Declare MyAlgorithms class
class MyAlgorithms
{

public:
	//Declare selection sort function
	void selection(int arrays[], int count);

	//Declare bubble sort function
	void bubble(int arrayb[], int count);
	
	//Declare quick sort function
	void quick(int arrayq[], int low, int high,int count);
	
	//Declare partition function for quick sort
	int partition(int arrayq[], int low, int high,int count);
	
	//Declare linear search function
	void linear(int arrayl[], int count, int num);
};

//Selection sort function
void MyAlgorithms::selection(int arrays[],int count)
{
	//Declare variable
	int count1 = 0;

	//for loop
	for (int i = 0; i < count; i++)
	{
		//Declare variable
		int min = i;
		
		//for loop
		for (int j = i + 1; j < count; j++)
		{
			//Checking condition
			if (arrays[j] < arrays[min])
			{
				//assigning value
				min = j;

				//Increment count1
				count1 = count1 + 1;
			}
		}
		//swap values
		swap(arrays[i], arrays[min]);
		
	}
	//sending values to excel file
	selectionfile << count << "," << count1 << "\n";

}

//Bubble sort function
void MyAlgorithms::bubble(int arrayb[], int count)
{
	//Declare variable
	int count2 = 0;

	//for loop
	for (int i = 0; i < count - 1; i++)
	{
		//for loop
		for (int j = count - 1; j > i; j--)
		{
			//condition checking
			if (arrayb[j] < arrayb[j - 1])
			{
				//increment count2
				count2 = count2 + 1;

				//swap values
				swap(arrayb[j], arrayb[j - 1]);
				
				//increment count2
				count2 = count2 + 1;
			}
			
		}
	}
	//sending values to excel file
	bubblefile << count << "," << count2 << "\n";

}

//Quick sort function
void MyAlgorithms::quick(int arrayq[], int low, int high,int count)
{
	//condition checking
	if (low < high)
	{
		//increment quickcount value
		quickcount = quickcount + 1;

		//calling partition function and assigning value
		int pivot = partition(arrayq, low, high,count);

		//calling quick function
		quick(arrayq, low, pivot - 1,count);

		//calling quick function
		quick(arrayq, pivot + 1, high,count);
	}
	
}

//Partition function
int MyAlgorithms::partition(int arrayq[], int low, int high,int count)
{
	//assign value
	int pivot = arrayq[high];
	
	//assign value
	int i = (low - 1);

	//for loop
	for (int j = low; j <= high - 1; j++)
	{
		//condition checking
		if (arrayq[j] <= pivot)
		{
			//increment quickcount value
			quickcount = quickcount + 1;

			//swap values
			swap(arrayq[i], arrayq[j]);
			
			//increment quickcount value
			quickcount = quickcount + 1;

		//increment i value
			i++;
		}
		
	}

	//swap values
	swap(arrayq[i + 1], arrayq[high]);

	//return values
	return (i + 1);
}

//Linear search function
void MyAlgorithms::linear(int arrayl[], int count, int num)
{
	//assign values
	int linearcount = 0;

	//for loop
	for (int a = 0; a < count; a++)
	{
		//condition checking
		if (arrayl[a] == num)
		{
			//break
			break;
		}
		//increment linearcount value
		linearcount = linearcount + 1;
	}

	//sending values to excel file
	linearfile << count << "," << linearcount << "\n";
}

//permutation function
void permutation(int m, int size, int*array)
{
	//creating dma for arrays
	int *duparrays = new int[size];
	int *duparrayb = new int[size];
	int *duparrayq = new int[size];
	int *duparrayl = new int[size];

	for (int i = 0; i < size; i++)
	{
		//assigning values to new arrays
		duparrays[i] = array[i];
		duparrayb[i] = array[i];
		duparrayq[i] = array[i];
		duparrayl[i] = array[i];

	}

	//condition checking
	if (m == 0)
	{
		//declare objects
		MyAlgorithms obj1, obj2, obj3, obj4;

		//calling functions
		obj1.selection(duparrays, size);
		obj2.bubble(duparrayb, size);
		obj3.quick(duparrayq, 0, size,size);

		//sending values to excel file
		quickfile << size << "," << quickcount << "\n";
		
		//assigning value
		quickcount = 0;

		//calling function
		obj4.linear(duparrayl, size, size);
	}
	//condition checking
	else
	{
		//for loop
		for (int i = m - 1; i >= 0; i--)
		{
			//swap values
			swap(array[i], array[m - 1]);

			//calling function
			permutation(m - 1, size, array);
			
			//swap values
			swap(array[i], array[m - 1]);
		}
	}

}

//main function
int main()
{
	//open excel files
	selectionfile.open("Selection Sort.csv");
	bubblefile.open("Bubble Sort.csv");
	quickfile.open("Quick Sort.csv");
	linearfile.open("Linear Search.csv");

	//write output in the excel files
	selectionfile << "Values,Number of steps\n";
	bubblefile << "Values,Number of steps\n";
	quickfile << "Values,Number of steps\n";
	linearfile << "Values,Number of steps\n";

	//for loop
	for (int z = 1; z < 8; z++)
	{
		//declare dma for arrays
		int*array = new int[z];

		//for loop
		for (int j = z; j > 0; j--)
		{
			//assign values to array
			array[j - 1] = j;
		}

		//calling functions
		permutation(z, z, array);

		//delete dma
		delete[] array;

	}
	//wait until users input
	system("pause");
	return 0;

}