#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 22;
    data.name = "Ebrar";
    data.value = "42.42f";

    std::cout << "Adres: " << &data << std::endl;
    std::cout << "Veri:  " << data.id << ", " << data.name << ", " << data.value << std::endl;

    std::cout << "-------------Serializer----------------" << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Raw (uintptr_t): " << raw << std::endl;
    std::cout << "Veri:  " << data.id << ", " << data.name << ", " << data.value << std::endl;
    
    std::cout << "-------------Deserializer----------------" << std::endl;
    Data* result = Serializer::deserialize(raw);
    std::cout << "Deserializer Adres:    " << result << std::endl;
    std::cout << "Veri:  " << result->id << ", " << result->name << ", " << result->value << std::endl;

    if (result == &data && result->id == 22 && result->name == "Ebrar" && result->value == "42.42f")
    {
        std::cout << "Serializer Process Success!!" << std::endl;
    }
    else
    {
        std::cout << "Serializer Process Failure!!" << std::endl;
    }

    return 0;
}
