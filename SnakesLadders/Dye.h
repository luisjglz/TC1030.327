class Dye{
    
    int number;
    public:
    int roll(){
        srand(time(0)); 
        int randi = (rand()%6)+1;
        return randi;
    }
};