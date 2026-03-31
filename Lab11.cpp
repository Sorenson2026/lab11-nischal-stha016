/* A program that read the numbers from the file and read them into an array then display : lowest, highest, total, average and the standard devoiation of the numbers.
* By Nischal Shrestha
* Date: 2026/03/21
*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int SIZE = 100;

// Function prototypes
int readFile(const string& filename, double numbers[], int& count);
double findLowest(double numbers[], int count);
double findHighest(double numbers[], int count);
void analyzeArray(double numbers[], int count);

// Main function
int main()
{
	double numbers[SIZE];
	int count;
	string filename;
	cout << "Enter the file name: ";
	cin >> filename;
	readFile(filename, numbers, count);
	analyzeArray(numbers, count);
	return 0;
}

// Function to read numbers from a file into an array
int readFile(const string& filename, double numbers[], int& count)
{
	ifstream file(filename);
	if (!file)
	{
		cerr << "Error opening file!" << endl;
		exit(1);
	}
	count = 0;
	while (file >> numbers[count])
	{
		count++;
	}
	file.close();
	return count;
}

// Function to find the lowest number in the array
double findLowest(double numbers[], int count)
{
	double lowest = numbers[0];
	for (int i = 1; i < count; i++)
	{
		if (numbers[i] < lowest)
		{
			lowest = numbers[i];
		}
	}
	return lowest;
}

// Function to find the highest number in the array
double findHighest(double numbers[], int count)
{
	double highest = numbers[0];
	for (int i = 1; i < count; i++)
	{
		if (numbers[i] > highest)
		{
			highest = numbers[i];
		}
	}
	return highest;
}

void analyzeArray(double numbers[], int count)
{
	double lowest = findLowest(numbers, count);
	double highest = findHighest(numbers, count);
	/*double total = calculateTotal(numbers, count);
	double average = calculateAverage(numbers, count);
	double stddev = calculateStandardDeviation(numbers, count, average);

	
	
	cout << "Total: " << total << endl;
	cout << "Average: " << average << endl;
	cout << "Standard Deviation: " << stddev << endl; */
	cout << "Lowest: " << lowest << endl;
	cout << "Highest: " << highest << endl;
}

