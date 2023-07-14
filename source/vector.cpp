#include <iostream>
#include "vector.hpp"

Vector::Vector(int n) : _size(0), _capacity(n), _resizeFactor(2)
{	
	try
	{
		this->_begin = new int[n];

	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
		exit(1);
	}
	catch (...)
	{
		std::cerr << "something get wrong...";
		exit(1);
	}
}

int Vector::size() const
{
	return this->_size;
}

int Vector::capacity() const
{
	return this->_capacity;
}

bool Vector::empty() const
{
	return (this->_size == 0);
}

void Vector::assign(int val)
{
	try
	{
		for (int i = 0; i < this->size(); i++)
			this->_begin[i] = val;
	}
	catch(std::out_of_range& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void Vector::clear()
{
	try
	{
		for (int i = 0; i < this->size(); i++)
			this->_begin[i] = NULL;
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void Vector::push_back(const int& val)
{
	try
	{
		if (this->size() >= this->capacity())
			reserve(this->capacity() * this->_resizeFactor);
		this->_begin[this->size()] = val;
		this->_size++;
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void Vector::pop_back()
{
	try
	{
		this->_begin[this->size() - 1] = NULL;
		this->_size--;
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void Vector::reserve(int n)
{
	try
	{
		int* temp = new int[n];
		for (int i = 0; i < this->size(); i++)
			temp[i] = this->_begin[i];
		delete[] this->_begin;
		this->_begin = temp;
		this->_capacity = n;
	}
	catch(std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
		exit(1);
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "something get wrong...";
		exit(1);
	}
}

void Vector::resize(int n)
{
	try
	{
		if (n < this->size())
		{
			int* temp = this->_begin + n;
			delete[] temp;
		}
		else if (n > this->size() && n < this->capacity())
		{
			for (int i = this->size(); i < n; i++)
				this->_begin[i] = -1;
		}
		else if (n > this->capacity())
		{
			this->reserve(n);
			for (int i = this->size(); i < n; i++)
				this->_begin[i] = -1;
		}
		this->_size = n;
		this->_capacity = n;
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void Vector::resize(int n, const int& val)
{
	try
	{
		if (n < this->size())
		{
			int* temp = this->_begin + n;
			delete[] temp;
		}
		else if (n > this->size() && n < this->capacity())
		{
			for (int i = this->size(); i < n; i++)
				this->_begin[i] = val;
		}
		else if (n > this->capacity())
		{
			this->reserve(n);
			for (int i = this->size(); i < n; i++)
				this->_begin[i] = val;
		}
		this->_size = n;
		this->_capacity = n;
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

bool Vector::operator==(const Vector& other) const
{
	try
	{
		if (this == &other)
			return true;
		else if ((this->capacity() != other.capacity()) && (this->size() != other.size()))
			return false;
		else
		{
			for (int i = 0; i < this->size(); i++)
			{
				if (this->_begin[i] != other._begin[i])
					return false;
			}
		}
		return true;
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

Vector& Vector::operator=(const Vector& other)
{
	try
	{
		if (!(*this == other))
		{
			this->_size = other.size();
			this->_capacity = other.capacity();
			this->_begin = new int[capacity()];
			this->_resizeFactor = other._resizeFactor;
			for (int i = 0; i < size(); i++)
				this->_begin[i] = other._begin[i];
		}
		return *this;
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
		exit(1);
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "something get wrong...";
		exit(1);
	}
}

Vector::~Vector()
{
	delete[] this->_begin;
}


const int& Vector::operator[](int index) const
{
	try
	{
		return this->_begin[index];
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}



std::ostream& operator<< (std::ostream& out, const Vector& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		out << v[i] << " ";
	}
	out << std::endl;
	return out;
}