// https://www.codewars.com/kata/576b93db1129fcf2200001e6/train/c

#include <vector>
using namespace std;

int sum(vector<int> numbers)
{
	if (numbers.size() == 0 || numbers.size() <= 2)
	{
		return 0;
	}
	int min = numbers[0];
	int max = numbers[0];
	int sum = 0;

	for (int i = 0; i < numbers.size(); i++)
	{
		sum += numbers[i];

		if (numbers[i] > max)
		{
			max = numbers[i];
		}

		if (numbers[i] < min)
		{
			min = numbers[i];
		}
	}

	return sum - min - max;
}