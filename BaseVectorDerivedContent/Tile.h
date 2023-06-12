class Tile{
    int num;
    public:
    virtual void print()=0;
    int getNum(){
        return num;
    };
    void setNum(int n){
        num = n;
    };
};