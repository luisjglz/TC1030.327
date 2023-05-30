class Teacher : public Person{
    std::string rank;
    std::string dept;
    std::string course;
    public:
    std::string getRank(){ return rank; };
    std::string getDept(){ return dept; };
    std::string getCourse(){ return course; };
    
};