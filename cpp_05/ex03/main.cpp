#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Intern      intern;
    Bureaucrat  b("CEO", 1);
    AForm* form;

    std::cout << "--- TEST 1 ---" << std::endl;

    form = intern.makeForm("presidential pardon", "Arthur Dent");
    if (form)
    {
        b.signForm(*form);
        b.executeForm(*form);
        delete form;
    }

    std::cout << "\n--- TEST 2 ---" << std::endl;

    form = intern.makeForm("unknown form", "Nobody");
    if (form)
        delete form;

    return 0;
}