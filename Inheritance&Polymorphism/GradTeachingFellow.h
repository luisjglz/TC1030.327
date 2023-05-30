class GradTeachingFellow : public Student, public Teacher{
    std::string supervisor;

    public:

    std::string getSupervisor(){
        return supervisor;
    }
};