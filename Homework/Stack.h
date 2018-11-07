#pragma once
#include <iostream>
using namespace std;
class mStack
{
	int *a;
	int size;
	int left;
	int	right;
public:
	mStack(int _size)
	{
		size = _size;
		left = -1;
		right = size;
		a = new int[size];
	}
	void init(int _size)
	{
		size = _size;
		left = -1;
		right = size;
		a = new int[size];
	}
	mStack(const mStack &p) {
		size = p.size;
		left = p.left;
		right = p.right;
		a = new int[size];
		for (int i = 0; i <= left; i++)
		{
			a[i] = p.a[i];
		}
		for (int i = size - 1; i >= right; i--)
		{
			a[i] = p.a[i];
		}
	}
	
	void push(int Elem, int n) {
		if (Full()) throw "cTeK TIoJIoH";
		if (n == 0)
		{
			left++;
			a[left] = Elem;
		}
		if (n == 1)
		{
			right--;
			a[right] = Elem;
		}
	}

	bool empty(int n) {
		if (n == 0) return left == -1;
		if (n == 1) return right == size;
		else throw - 1;
	}

	bool Full() {
		return (left == right);
	}

	int pop(int n) {
		if (empty(n)) throw "TIycTou cTeK";
		if (n == 0)
		{
			left--;
			return a[left + 1];
		}
		if (n == 1)
		{
			right++;
			return a[right - 1];
		}
		else throw - 3;
	}
	void clr(int n)
	{
		if (n == 0)left = -1;
		if (n == 1)right = size;
	}
	~mStack()
	{
		delete[] a;
	}
};




class Calc
{
	mStack un_do;
	int Value;
	bool active;
public:
	Calc(int _size):un_do(_size) {
		Value = 0;
		active = true;
	}

	int plus(int Elem) {
		active = true;
		un_do.push(Value,0);
		un_do.clr(1);
		Value = Value + Elem;
		return Value;
	}
	int minus(int Elem) {
		active = true;
		un_do.push(Value,0);
		un_do.clr(1);
		Value = Value - Elem;
		return Value;
	}
	int fundo() {
		active = false;
		un_do.push(Value,1);
		Value = un_do.pop(0);
		return Value;
	}

	int fdo() {
		if (active == true) return Value;
		un_do.push(Value,0);
		Value = un_do.pop(1);
		return Value;
	}

	friend ostream &operator<<(ostream &ostr, Calc &s)
	{
		ostr << "Value = " << s.Value << endl;
			return ostr;
	}
	void clr()
	{
		un_do.clr(0);
		un_do.clr(1);
		Value = 0;
		active = true;
	}
	void newmem(int size)
	{
		un_do.~mStack();
		clr();
		un_do.init(size);
	}
};
