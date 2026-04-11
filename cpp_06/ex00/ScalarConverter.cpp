#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{

}

void ScalarConverter::convert(const std::string& param)
{
    if (param == "nan" || param == "nanf" || param == "+inf" || 
        param == "+inff" || param == "-inf" || param == "-inff" || param == "-nan" || param == "-nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (param == "nan" || param == "nanf" || param == "-nan" || param == "-nanf")
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;    
        }
        else 
        {
            int i = 0;

            if (param[0] == '-')
                i = -1;
            if (i == 0)
            {
                std::cout << "float: inff" << std::endl;
                std::cout << "double: inf" << std::endl;
            }
            else
            {
                std::cout << "float: -inff" << std::endl;
                std::cout << "double: -inf" << std::endl;
            }
        }
        return ;
    }

    try 
    {
        if (param.length() > 1 && (param != "inf" && param != "inff")) 
        {
            bool hasDecimal = false;
            bool hasF = false;
            size_t i = 0;
            if (param[i] == '+' || param[i] == '-') i++;

            for (; i < param.length(); i++) 
            {
                if (param[i] == '.') 
                {
                    if (hasDecimal)
                        throw std::exception();
                    hasDecimal = true;
                } 
                else if (param[i] == 'f') 
                {
                    if (hasF || i != param.length() - 1) 
                        throw std::exception();
                    hasF = true;
                } 
                else if (!isdigit(param[i])) 
                   throw std::exception();
            }
        }

        double val = std::stod(param);

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