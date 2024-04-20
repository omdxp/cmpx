#include <cmpx>

std::string Complex::stringify() const
{
    std::stringstream ss;
    if (this->re == 0 && this->im == 0)
        return "0";
    ss << "( " << this->re;
    if (this->im >= 0)
        ss << " + ";
    else
        ss << " - ";
    if (this->im == 1 || this->im == -1)
        ss << "i )";
    else
        ss << this->im << "i )";
    return ss.str();
}

Complex *Complex::operator+(Complex *other)
{
    double re = this->re + other->re;
    double im = this->im + other->im;
    return new Complex(re, im);
}

Complex *Complex::operator-(Complex *other)
{
    double re = this->re - other->re;
    double im = this->im - other->im;
    return new Complex(re, im);
}

Complex *Complex::operator*(Complex *other)
{
    double re = this->re * other->re - this->im * other->im;
    double im = this->re * other->im + this->im * other->re;
    return new Complex(re, im);
}

Complex *Complex::operator/(Complex *other)
{
    Complex *den = *other * other->con();
    Complex *num = *this * other->con();
    try
    {
        return new Complex(num->re / den->re, num->im / den->re);
    }
    catch (const std::exception &e)
    {
        throw e;
    }
}

bool Complex::operator>(Complex *other) const
{
    return this->mod() > other->mod();
}

bool Complex::operator>=(Complex *other) const
{
    return this->mod() >= other->mod();
}

bool Complex::operator<(Complex *other) const
{
    return !(this >= other);
}

bool Complex::operator<=(Complex *other) const
{
    return !(this > other);
}

bool Complex::operator==(Complex *other) const
{
    return (this->re == other->re) && (this->im == other->im);
}

bool Complex::operator!=(Complex *other) const
{
    return !(this == other);
}

void Complex::operator+=(Complex *other)
{
    this->re += other->re, this->im += other->im;
}

void Complex::operator-=(Complex *other)
{
    this->re -= other->re, this->im -= other->im;
}

void Complex::operator*=(Complex *other)
{
    this->re = this->re * other->re - this->im * other->im;
    this->im = this->re * other->im + this->im * other->re;
}

void Complex::operator/=(Complex *other)
{
    Complex *den = *other * other->con();
    Complex *num = *this * other->con();
    try
    {
        this->re = num->re / den->re;
        this->im = num->im / den->re;
    }
    catch (const std::exception &e)
    {
        throw e;
    }
}

double Complex::mod() const
{
    return sqrt(pow(this->re, 2) + pow(this->im, 2));
}

Complex *Complex::con()
{
    return new Complex(this->re, -this->im);
}
