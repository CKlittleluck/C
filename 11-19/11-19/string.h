#include<iostream>
using namespace std;
#include<assert.h>

class String
{
public:
	String(const char* str = "")
	{

		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	//编译器生成的默认拷贝构造函数
    String(const String& s)
		:_str(s._str)
		{}

	//深拷贝
	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
		(
		strcpy(_str, s._str);
		)


	
	String& operator = (const String& s)
	{
		if (this != &s)
		{
			//1
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);

			//2
			char* temp = new char[strlen(s._str) + 1];
			strcpy(temp, s._str);
			delete[] _str;
			_str = temp;
		}
		return *this;
	}


		//深拷贝
		String(const String& s)
			: _str(nullptr)
		{
			String strTemp(s._str);
			swap(_str, strTemp._str);
		}

		String& operator = (String s)
		{
			swap(_str, s._str);
			return *this;
		}

		~String()
		{
			Release();
		}


		String& operator = (const String& s)
		{
			if (this != &s)
			{
				Release();
				_str = s._str;
				_pcount = s._pcount;
				++* _pcount;
			}
			return *this;
		}

		char& operator[](size_t index)
		{

			if (GetRef() > 1)
			{
				SubRef();
				char* temp = new char[strlen(_str) - 1];
				strcpy(temp, _str);

				_pcount = new int(1);
				_str = temp;

			}
			return _str[index];
		}

		const char& operator[](size_t index)const
		{
			return _str[index];
		}



private:

	void AddRef()
	{
		++* _pcount;
	}

	int& SubRef()
	{
		--* _pcount;
		return *_pcount;
	}

	int& GetRef()
	{
		return *_pcount;
	}

	void Release()
	{
		if (--*_pcount == 0 && _str)
		{
			delete[] _str;
			_str = nullptr;

			delete _pcount;
			_pcount = nullptr;
		}
	}




private:
	char* _str;
	int* _pcount;
};


namespace bite
{
	class string
	{
	public:
		typedef char* iterator;
	public:
		string(const char* str = "")
		{
			if (nullptr == str)
				str = "";

			_capacity = strlen(str);
			_size = _capacity;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s)
			:_str(nullptr)
			, _capacity(0)
			, _size(0)

		{
			string strTemp(s._str);
			this->swap(strTemp);
		}
		string(size_t n, char ch = char())
			:_str(new char[n + 1])
			, _capacity(n)
			, _size(n)
		{
			memset(_str, ch, n);
			_str[n] = '\0';
		}
		

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_capacity, s._capacity);
			std::swap(_size, s._size);
		}

		string& operator = (string& s)
		{
			swap(s);
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_capacity = 0;
				_size = 0;
			}
		}
		iterator begin()
		{
			return _str;

		}

		iterator end()
		{
			return _str + _size;
		}
		
		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		bool empty() const
		{
			return 0 == _size;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		void resize(size_t newsize, char ch)
		{
			size_t oldsize = _size;
			if (newsize > oldsize)
			{
				if (newsize > _capacity)
				{
					reserve(_capacity * 2);
				}
				memset(_str + oldsize, newsize - oldsize, ch);
			}
			_str[newsize] = '\0';
			_size = newsize;
		}


		void reserve(size_t newcapacity)
		{
			if (newcapacity > capacity())
			{
				char* temp = new char[newcapacity + 1];
				strcpy(temp, _str);
				delete[] _str;
				_str = temp;
				_capacity = newcapacity;
			}
		}

		//acess

		char &operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}

		const char &operator[](size_t index) const
		{
			assert(index < _size);
			return _str[index];
		}


		//+=

		string& operator+=(char ch)
		{
			if (_size == _capacity)
				reserve(_capacity * 2);
			_str[_size++] = ch;
			_str[_size] = '\0';
			return *this;
		}
		string& operator+=(const char* str);


		string& operator+=(const string& s)
		{
			*this += s._str;
			return *this;
		}

		void push_back(char ch)
		{
			*this += ch;
		}


		string& append(const string& s)
		{
			*this += s;
			return *this;
		}

		size_t find(char ch, size_t pos = 0)
		{
			if (pos >= _size)
				return npos;
			for (size_t index = pos; index < _size; ++index)
			{
				if (_str[index] == ch)
					return index;
			}
			return npos;
		}


		size_t rfind(char ch, size_t pos = npos)
		{
			if (pos == npos)
				pos = _size - 1;
			for (int index = pos; index >= 0; --index)
			{
				if (_str[index] == ch)
					return index;
			}
			return npos;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static size_t npos;
	};

	size_t string::npos = -1;
}

int main()
{
	string s("kangknag");
	_CrtDumpMemoryLeaks();
	return 0;
}