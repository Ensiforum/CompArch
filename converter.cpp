#include "converter.h"

#include <QDebug>

Converter::Converter(int system, const std::string& num)
{
    init_system = system;
    negative = 0;
    number = QVector<int>();
    size_t start = 0;
    if(num[0] == '-')
        start = negative = 1;
    for(size_t i = start; i < num.size(); ++i)
        number.push_back(charToInt(num[i]));
}

void Converter::changeNumber(const std::string &num)
{
    number.clear();
    negative = 0;
    size_t start = 0;
    if(num[0] == '-')
        start = negative = 1;
    for(size_t i = start; i < num.size(); ++i)
        number.push_back(charToInt(num[i]));
}

int Converter::charToInt(char c) const
{
    if(c >= '0' && c <= '9' && (c - '0') < init_system)
        return c - '0';
    if(c >= 'A' && c <= 'Z' && (c - 'A') < init_system)
        return c - 'A' + 10;
    return -1;
}

char Converter::intToChar(int dig) const
{
    if(dig >= 0 && dig <= 9)
        return dig + '0';
    return dig + 'A' - 10;
}

int Converter::nextNumber(int final_system)
{
    int ans = 0;
    for (size_t i = 0; i < number.size(); ++i)
    {
        ans = ans * init_system + number[i];
        number[i] = ans / final_system;
        ans = ans % final_system;
    }
    return ans;
}

bool Converter::zero() const
{
    for (size_t i = 0; i < number.size() ; ++i)
    {
        if(number[i] != 0)
            return 0;
    }
    return 1;
}

std::string Converter::convertTo(int final_system)
{
    QVector<int> accum;
    int size = 0;
    do
    {
        accum.push_back(nextNumber(final_system));
        ++size;
    }while(!zero());
    std::string ans = "";
    for (int i = accum.size() - 1; i >= 0; --i )
    {
        ans += intToChar(accum[i]);
    }
    if(negative)
        ans = '-' + ans;
    return ans;
}
