#include<memory>
#include<string>
class a
{
    public:
    int age;
    std::string name;

};

int main()
{

    std::shared_ptr<a>ptr(new a);
    ptr->name = "sb";
    ptr->age = 52;
    return 0;
}