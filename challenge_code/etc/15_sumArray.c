// https://www.codewars.com/kata/576b93db1129fcf2200001e6/train/c

int sum(const int numbers[/*length*/], int length)
{
    if (length == 0 || length <= 2)
	{
		return 0;
	}

	int min = numbers[0];
	int max = numbers[0];
	int sum = 0;

	for (int i = 0; i < length; i++)
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
	
	return sum - max - min;
	
}