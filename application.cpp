#include "Worker_Provider.h"

int main()
{
	//Worker("Madik Rostyslav", "Chief", 2012, 35000),
	//Worker("Kovalchyk Vladyslav", "Programmer", 2015, 25000),
	//Worker("Plahotniuk Darya", "HR manager", 2017, 10000)	
	try {
		int size;
		cout << "Enter a size of array : ";
		cin >> size;
		if (size <= 0) {
			throw exception("Error size <= 0");
		}
		Worker* obj = new Worker[size];
		for (size_t i = 0; i < size; ++i)
		{
			string surname_name;
			cout << "Enter a surname name : ";
			cin >> surname_name;
			if (surname_name.empty())
			{
				throw exception("Error : surname name is empty");
			}
			string position;
			cout << "Enter a position : ";
			cin >> position;
			if (position.empty())
			{
				throw exception("Error : position is empty");
			}
			int year_of_employment;
			cout << "Enter a year of employment : ";
			cin >> year_of_employment;
			if (year_of_employment <= 0)
			{
				throw exception("Error : year of employment <= 0");
			}
			int salary;
			cout << "Enter a salary : ";
			cin >> salary;
			if (salary <= 0)
			{
				throw exception("Error : salary <= 0");
			}
			obj[i] = Worker(surname_name, position, year_of_employment, salary);
			cout << endl;
		}
		for (size_t i = 0; i < size; i++) {
			cout << "All workers" << endl;
			cout << "Surname Name: " << obj[i].get_surname_name() << endl;
			cout << "Position: " << obj[i].get_position() << endl;
			cout << "Year of employment: " << obj[i].get_year_of_employment() << endl;
			cout << "Salary: " << obj[i].get_salary() << endl;
			cout << endl;
		}
		cout << "Output:"
			"\n1 - a list of employees whose work experience at this enterprise exceeds the specified number of years"
			"\n2 - a list of employees whose salary exceeds the specified"
			"\n3 - a list of employees who hold a given position" << endl;
		int num = 0;
		cout << "Enter a number : " << endl;
		cin >> num;
		if (num <= 0)
		{
			throw exception("Error : num <= 0");
		}
		switch (num)
		{
		case 1:
			WorkerProvider::Print_givenMin_experience(obj, size);
			break;
		case 2:
			WorkerProvider::Print_givenMin_salary(obj, size);
			break;
		case 3:
			WorkerProvider::Print_givenPosition(obj, size);
			break;
		default: throw exception("Error : num > 3");
			break;
		}
		delete[] obj;
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
		cout << "outer error" << endl;
	}
	catch (...)
	{
		cout << " Basik Error" << endl;
	}
	return 0;
}

