#include<cstring>
#include<istream>

class String
{
private:
	static const int _BUFFER_SIZE = 1000;
	// Contains length including the terminate symbol
	int _length = 0;
	char* _stringptr = nullptr;

	void _set(const char* const str) {
		delete[] _stringptr;
		_length = strlen(str) + 1;
		_stringptr = new char[_length];
		strcpy(_stringptr, str);
	}

public:
	// Default constructor
	String() { _set(""); }
	// Initializing constructor
	String(const char* const str) { _set(str); }
	// Copy constructor
	String(const String& other) {
		_set(other);
	}
	// Destructor
	~String() { delete[] _stringptr; }

	// length getter(notice: length includes the terminate symbol)
	int getLength() { return _length; }

	void readFromStream(std::istream& is) {
		char temp[_BUFFER_SIZE];

		is >> temp;
		_set(temp);
	}

	// conversion to char*
	operator char* () const {
		return _stringptr;
	}
	// referring to as str[1]...
	char& operator[](int index) {
		return _stringptr[index];
	}

	// assignment operator
	String& operator=(const String& other) {
		if (this == &other) return *this; // Self-assignment check

		_set(other);

		return *this;
	}

	//appending operator
	String& operator+=(const char* const operand) {
		String other = operand;

		int newLength = _length + other.getLength();

		char* result = new char[newLength];
		strcpy(result, _stringptr);
		strcat(result, other);

		_set(result);
		delete[] result;

		return *this;
	}

	String& operator+=(char operand) {
		char* charArr = new char[2];
		charArr[0] = operand;
		charArr[1] = '\0';
		operator+=(charArr);
		delete[] charArr;

		return *this;
	}
};