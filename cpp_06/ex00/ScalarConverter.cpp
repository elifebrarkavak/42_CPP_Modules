#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal)
{
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || 
        literal == "+inff" || literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (literal.find("nan") != std::string::npos)
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else 
        {
            std::string res;

            if (literal[0] == '+') 
            {
                res = "inf";
            } 
            else 
            {
                res = "-inf";
            }
            std::cout << "float: " << res << "f" << std::endl;
            std::cout << "double: " << res << std::endl;
        }
        return ;
    }

    try 
    {
        double val = std::stod(literal);

        std::cout << "char: ";

        if (val < std::numeric_limits<char>::min() || val > std::numeric_limits<char>::max() || std::isnan(val))
            std::cout << "impossible" << std::endl;
        else if (!isprint(static_cast<char>(val)))
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(val) << "'" << std::endl;

        std::cout << "int: ";

        if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max() || std::isnan(val))
            std::cout << "impossible" << std::endl;
        else
            std::cout << static_cast<int>(val) << std::endl;

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
        std::cout << "double: " << val << std::endl;

    } catch (...)
    {
        std::cout << "Error: Conversion impossible" << std::endl;
    }
}