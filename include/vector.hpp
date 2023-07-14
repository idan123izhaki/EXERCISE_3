#pragma once

class Vector
{
	int* _begin;
	int _size;
	int _capacity;
	int _resizeFactor;

public:
	//task_1_1
	Vector(int n = 1);
	int size() const;
	int capacity() const;
	bool empty() const;
	void assign(int);
	void clear();
	//task_1_2
	void push_back(const int&);
	void pop_back();
	void reserve(int);
	void resize(int);
	void resize(int, const int&);
	//task_1_3
	bool operator==(const Vector& v) const;
	Vector& operator=(const Vector& v);
	~Vector();
	//task_1_4
	const int& operator[](int index) const;

	//prints the elements in vecrtor
	friend std::ostream& operator<< (std::ostream&, const Vector&);
};