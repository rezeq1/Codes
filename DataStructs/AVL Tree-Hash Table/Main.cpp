#include "FlightTable.h"



int Len(string name_file);
int reverse(int num);
int h1(int k, int size);
int h2(int k, int size);
int SetPassenger1(int id, int*arr, int size);
int SetPassenger2(int id, int*arr, int size);
void OutputSteps(string file_name, int*arr, int size);

int main() {
	string FileName1 = "input.txt", FileName2 = "input2.txt", FileName3 = "output1.txt";
	int size = Len(FileName1);
	int *arr, *temp, counter = 0, *steps;
	arr = new int[size];
	steps = new int[size];
	for (int i = 0;i < size;i++)
		arr[i] = 0;

	FlightTable a(size);
	a.InputFile(FileName1);
	temp=a.FinalPassengers(FileName1, FileName2, FileName3);

	for (int i = 0;i < size;i++)
		steps[i] = SetPassenger1(temp[i], arr, size);

	for (int i = 0;i < size;i++)
		cout << arr[i] << endl;
	cout << "***********************" << endl;
	//for (int i = 0;i < size;i++)
	//	cout << steps[i]<< endl;
	OutputSteps("Ads", steps, size);
	delete arr;
	delete temp;
	delete steps;
	//cout << "*******" << endl << counter;

	

	/*
	FlightTable a(size);

	a.InputFile(FileName1);

	a.OutputTaple(FileName3);

	a.OutputAverage(FileName3, a.AvergSteps(FileName2));

	a.FinalPassengers(FileName1,FileName2, FileName3);
	*/

	
	system("pause");
	return 0;
}

int Len(string name_file)
{
	ifstream size(name_file);
	char letter;
	int id, count = 0;
	if (size.is_open())
	{
		while (size >> id)
		{
			count++;
			size >> letter;

		}

		size.close();
	}
	else cout << "Unable to open file";
	return count;
}


int reverse(int num)
{
	int reverse = 0,Sharet ;
	while (num != 0)
	{
		Sharet = num % 10;
		reverse = reverse * 10 + Sharet;
		num = num / 10;
	}
	return reverse;
}

int h1(int k,int size)
{
	return  k % size;
}

int h2(int k, int size)
{
	return  reverse(k) % size;
}

int SetPassenger2(int id, int * arr,int size)
{
	int index = h2(id, size), flag = 0, i = 0, count = 0;
	if (arr[index] == 0)
	{

		arr[index] = id;
		return count;
	}
	else
	{
		while (flag == 0)
		{

			i++;
			if (index + i < size  && index - i >= 0)
			{
				if (arr[index + i] == 0)
				{
					arr[index + i] = id;
					return count + 1;
				}
				else if (arr[index - i] == 0)
				{
					arr[index - i] = id;
					return count + 2;
				}
				count += 2;
			}
			else
			{
				if (index + i == size)
				{
					while (arr[index - i] != 0) {
						i++;
						count++;
					}
					arr[index - i] = id;
					return count + 1;

				}
				else
				{

					while (arr[index + i] != 0) {
						i++;
						count++;
					}
					arr[i + index] = id;
					return count + 1;
				}
			}
		}

	}
}

void OutputSteps(string file_name, int * arr, int size)
{
	int Step1, Step2, Step3, Step4, count = 0;
	Step1 =	int(size / 2);
	Step2 = int((size*3) / 4);
	Step3 = int(size - sqrt(size));
	Step4 = int(sqrt(size));

	for (int i = 0;i < Step1;i++)
		count += arr[i];
	cout <<count << endl;
	count = 0;

	for (int i = 0;i < Step2;i++)
		count += arr[i];
	cout << count << endl;
	count = 0;

	for (int i = 0;i < Step3;i++)
		count += arr[i];
	cout << count << endl;
	count = 0;

	for (int i = size-Step4;i < size;i++)
		count += arr[i];
	cout <<count << endl;

}

int SetPassenger1(int id, int * arr, int size)
{
	int index = h1(id, size), flag = 0, i = 0, count = 0;
	if (arr[index] == 0)
	{	
		
		arr[index] = id;
		return count;
	}
	else
	{
		while (flag == 0)
		{

			i++;
			if (index + i< size  && index - i>=0) 
			{
				if (arr[index + i] == 0)
				{
					arr[index + i] = id;
					return count + 1;
				}
				else if (arr[index - i] == 0)
				{
					arr[index - i] = id;
					return count + 2;
				}
				count += 2;
			}
			else
			{
				if (index + i == size)
				{
					while (arr[index-i] != 0) {
						i++;
						count++;
					}
					arr[index - i] = id;
					return count + 1;

				}
				else 
				{
				
					while (arr[index+i] != 0) {
						i++;
						count++;
					}
					arr[i+index] = id;
					return count + 1;
				}
			}
		}

	}

}
