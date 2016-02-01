#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

int main(int argc, char * argv[])
{
	int i, j;
	int number;
	int temp;
	unsigned long long count[10];
	double fraction;
	std::ofstream output_file;

	srand(time(NULL));
	output_file.open("data.txt");

	for (i = 0; i < 10; i++)
		count[i] = 0;

	output_file << "Frequency of 0 to 9 with 100, 1 000, 10 000, 100 000, 1 000 000 runs: \n";
	for (i = 1; i <= 1000000; i++)
	{
		number = rand() % 10;
		++count[number];	
		if (i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000)
		{
			for (j = 0; j < 10; j++)
			{
				fraction = static_cast<double>(count[j]) / static_cast<double>(i);
				output_file << fraction << "\t";
			}
			output_file << "\n";
		}
	}

	for (i = 0; i < 10; i++)
		count[i] = 0;

	output_file << "Frequency of 0 to 99 with 1 000, 10 000, 100 000, 1 000 000, 10 000 000 runs: \n";
	for (i = 1; i <= 10000000; i++)
	{
		number = rand() % 100;
		for (j = 1; j <= 10; j++)
		{
			if (number < j * 10)
			{
				++count[j - 1];
				break;
			}
		}
		if (i == 1000 || i == 10000 || i == 100000 || i == 1000000 || i == 10000000)
		{
			for (j = 0; j < 10; j++)
			{
				fraction = static_cast<double>(count[j]) / static_cast<double>(i);
				output_file << fraction << "\t";
			}
			output_file << "\n";
		}
	}

	for (i = 0; i < 10; i++)
		count[i] = 0;

	output_file << "Frequency of 0 to 999 with 10 000, 100 000, 1 000 000, 10 000 000, 100 000 000 runs: \n";
	for (i = 1; i <= 100000000; i++)
	{
		number = rand() % 1000;
		for (j = 1; j <= 10; j++)
		{
			if (number < j * 100)
			{
				++count[j - 1];
				break;
			}
		}
		if (i == 10000 || i == 100000 || i == 1000000 || i == 10000000 || i == 100000000)
		{
			for (j = 0; j < 10; j++)
			{
				fraction = static_cast<double>(count[j]) / static_cast<double>(i);
				output_file << fraction << "\t";
			}
			output_file << "\n";
		}
	}

	output_file.close();
	return 0;
}
