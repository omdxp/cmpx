#include <iostream>
#include <cmpx>

void print_complex(Complex *num)
{
    std::cout << num->stringify() << "\n";
}

int main(void)
{
    Complex *num = new Complex(3, -1);
    Complex *other = new Complex(-1, 0);
    print_complex(num);
    print_complex(*num * other);
    if (num == num)
    {
        std::cout << "ofc they are equal\n";
    }
}
