#ifndef CONVERTER_H
#define CONVERTER_H

#include <QVector>
#include <string>

class Converter
{
private:
    QVector<int> number;
    int init_system;
    bool negative;
public:
    Converter(int system, const std::string& num);
    std::string convertTo(int final_system);
    void changeNumber(const std::string& num);
protected:
    int nextNumber(int final_system);
    int charToInt(char c) const;
    char intToChar(int num) const;
    bool zero() const;

};

#endif // CONVERTER_H
