#include <iostream>
#include <string>

using namespace std;

class Worker
{
private:

	string surname_name;
	string position;
	int year_of_employment;
	int salary;

public:

	Worker() = default;

	explicit Worker(string surname_name, string position, int year_of_employment, int salary)
	{
		set_surname_name(surname_name);
		set_position(position);
		set_year_of_employment(year_of_employment);
		set_salary(salary);
	}

	inline void set_surname_name(string surname_name)
	{
		this->surname_name = surname_name;
	}
	string get_surname_name() const
	{
		return surname_name;
	}

	inline void set_position(string position)
	{
		this->position = position;
	}
	string get_position() const
	{
		return position;
	}

	inline void set_year_of_employment(int year_of_employment)
	{
		this->year_of_employment = year_of_employment;
	}
	int get_year_of_employment()
	{
		return year_of_employment;
	}

	inline void set_salary(int salary)
	{
		this->salary = salary;
	}
	int get_salary() const
	{
		return salary;
	}
};