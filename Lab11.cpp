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

// Function to analyze the array and display lowest, highest, total, average and standard deviation

void analyzeArray(double numbers[], int count)
{
	if (count == 0)
	{
		cout << "No numbers to analyze." << endl;
		return;
	}
	double lowest = numbers[0];
	double highest = numbers[0];
	double total = 0.0;
	for (int i = 0; i < count; i++)
	{
		if (numbers[i] < lowest)
			lowest = numbers[i];
		if (numbers[i] > highest)
			highest = numbers[i];
		total += numbers[i];
	}
	double average = total / count;
	double sumOfSquares = 0.0;
	for (int i = 0; i < count; i++)
	{
		sumOfSquares += pow(numbers[i] - average, 2);
	}
	double standardDeviation = sqrt(sumOfSquares / count);
	cout << "Lowest: " << lowest << endl;
	cout << "Highest: " << highest << endl;
	cout << "Total: " << total << endl;
	cout << "Average: " << average << endl;
	cout << "Standard Deviation: " << standardDeviation << endl;
}