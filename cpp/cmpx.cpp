#include <cmpx>

std::string Complex::stringify()
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
