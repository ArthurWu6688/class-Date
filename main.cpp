#include <iostream>
using namespace std;

class Date {
public:
	Date(int year=1900,int month=1,int day=1)
		:_year(year)
		,_month(month)
		,_day(day){
		if (year < 0 || month <= 0 || month>13 || day <= 0 || day > GetMonthDay(year, month)) {
			cerr << "非法日期，请重新输入!" << endl;
			exit(-1);
		}
	}

	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	~Date() {

	}

	void PrintData() {
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	inline int GetMonthDay(int year,int month) {
		static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = arr[_month];
		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			return 29;
		}
		return day;
	}

	Date& operator=(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	Date& operator+=(int day) {
		if (day < 0) {
			while (day < 0) {
				_day -= 1;
				if (_day < 1) {
					--_month;
					if (_month<1) {
						--_year;
						_month = 12;
					}
					_day = GetMonthDay(_year, _month);
				}
				++day;
			}
		}
		else {
			_day += day;
			while (_day > GetMonthDay(_year, _month)) {
				_day -= GetMonthDay(_year, _month);
				++_month;
				if (_month > 12) {
					++_year;
					_month = 1;
				}
			}
		}
		return *this;
	}

	Date& operator-=(int day) {
		return this->operator+=(-day);
	}

	Date& operator+(int day) {
		return this->operator+=(day);
	}

	Date& operator-(int day) {
		return this->operator-=(day);
	}

	Date& operator++() {
		return *this + 1;
	}

	Date operator++(int) {
		Date temp(*this);
		++* this;
		return temp;
	}

	Date& operator--() {
		return *this - 1;
	}

	Date operator--(int) {
		Date temp(*this);
		--* this;
		return temp;
	}

	bool operator>(const Date& d) {
		if (_year > d._year) {
			return true;
		}
		else if (_year < d._year) {
			return false;
		}
		else {
			if (_month > d._month) {
				return true;
			}
			else if (_month < d._month) {
				return false;
			}
			else {
				if (_day > d._day) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}

	bool operator==(const Date& d) {
		if ((_year == d._year) && (_month == d._month) && (_day == d._day)) {
			return true;
		}
		return false;
	}

	bool operator<(const Date& d) {
		return !(*this > d || *this == d);
	}

	bool operator>=(const Date& d) {
		return !(*this < d);
	}

	bool operator<=(const Date& d) {
		return !(*this > d);
	}

	bool operator!=(const Date& d) {
		return !(*this == d);
	}

	int operator-(const Date& d) {
		int count = 0;
		Date temp(*this);
		if (temp < d) {
			while (temp != d) {
				++temp;
				++count;
			}
		}
		else if (temp > d) {
			while (temp != d) {
				--temp;
				++count;
			}
		}
		return count;
	}
	
private:
	int _year;
	int _month;
	int _day;
};

int main() {
	Date d(2020,3,5);
	

	return 0;
}