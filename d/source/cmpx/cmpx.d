module cmpx.cmpx;

import std.format;
import std.math;

struct Complex
{
	double re, im;

	this(double re, double im)
	{
		this.re = re;
		this.im = im;
	}

	unittest
	{
		auto num = Complex(0, 0);
		assert(num.re == 0);
		assert(num.im == 0);
		num.re = 1;
		assert(num.re == 1);
	}

	string toString() const @safe pure
	{
		string res;

		if (this.re == 0 && this.im == 0)
			return "0";
		res ~= format("( %.2f", this.re);
		if (this.im >= 0)
			res ~= " + ";
		else
			res ~= " - ";
		if (this.im == 1 || this.im == -1)
			res ~= "i )";
		else
			res ~= format("%.2fi )", this.im);
		return res;
	}

	unittest
	{
		auto num = Complex(0, 0);
		assert(num.toString == "0");
		num = Complex(1, -1);
		assert(num.toString == "( 1.00 - i )");
	}

	auto opBinary(string op, R)(const R rhs) const @safe
	{
		static if (op == "+")
			return Complex(this.re + rhs.re, this.im + rhs.im);
		else static if (op == "-")
			return Complex(this.re - rhs.re, this.im - rhs.im);
		else static if (op == "*")
			return Complex(this.re * rhs.re - this.im * rhs.im, this.re * rhs.im + this.im * rhs.re);
		else static if (op == "/")
		{
			auto den = rhs * rhs.con;
			auto num = this * ths.con;
			try
			{
				return Complex(num.re / den.re, num.im / den.re);
			}
			catch (Exception e)
			{
				throw e;
			}
		}
		else
			static assert(0, "Operator " ~ op ~ " not implemented");
	}

	bool opEquals(R)(const R other) const
	{
		return this.mod == other.mod;
	}

	unittest
	{
		auto num = Complex(1, 1);
		auto num2 = Complex(1, 2);
		assert(num != num2);
	}

	auto con() const
	{
		return Complex(this.re, -this.im);
	}

	unittest
	{
		auto num = Complex(1, 1);
		assert(num.con == Complex(1, -1));
	}

	double mod() const @safe nothrow
	{
		return sqrt(re * re + im * im);
	}

	unittest
	{
		auto num = Complex(1, 0);
		assert(num.mod == 1);
	}

	int opCmp(R)(const R other) const
	{
		if (this.mod < other.mod)
			return -1;
		else if (this.mod > other.mod)
			return 1;
		else
			return 0;
	}

	unittest
	{
		auto num = Complex(3, 4);
		auto num2 = Complex(1, 2);
		assert(num > num2);
	}

	auto opUnary(string op : "-")()
	{
		this.re *= -1, this.im *= -1;
		return Complex(this.re * -1, this.im * -1);
	}

	unittest
	{
		auto num = Complex(1, 1);
		assert(-num == Complex(-1, -1));
	}

	size_t toHash() const @nogc @safe pure nothrow
	{
		size_t hash = 0;
		hash ^= cast(size_t)(re * 319);
		hash ^= cast(size_t)(im * 319);
		return hash;
	}
}
