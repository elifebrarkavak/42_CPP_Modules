#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 22;
    data.name = "Ebrar";

    uintptr_t raw = Serializer::serialize(&data);
    Data* result = Serializer::deserialize(raw);

    if (result == &data && result->id == 22)
    {
        std::cout << "Success" << std::endl;
    } else
    {
        std::cout << "Failure" << std::endl;
    }

    return 0;
}