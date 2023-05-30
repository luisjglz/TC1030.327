class Student : public Person
{
    std::string address;
    std::string dept;

public:
    std::string getAddress() { return address; };
    std::string getDept() { return dept; };

    Student()
    {
        address = "";
        dept = "Mi dept por default";
    };

    Student(std::string ad, std::string de)
    {
        address = ad;
        dept = de;
    };
};