/*
 * @Author: your name
 * @Date: 2021-02-10 16:41:01
 * @LastEditTime: 2021-02-10 17:22:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \npb\DesignPattern\DependenceInversionPrinciple\DependenceInversionPrinciple.cpp
 */

#include <iostream>
#include <thread>


class Reader
{
private:
     
public:
    Reader(){} 
    ~Reader(){}

    virtual void ReadText() = 0;
    virtual void PalyBall(){}
    virtual void YoGa(){}
};
 

class Book : public Reader
{
private:
    std::string _name;

public:
    Book(std::string name):_name(name) {
        std::cout << "read book name : " << _name << std::endl;
    }

    ~Book(){
        std::cout << "read book over " << std::endl;
    }

    void ReadText() {
        std::cout << "this book name : "
                << _name 
                << "is new book"
                << std::endl;
    }
};


class NewPaper : public Reader
{
private:
    std::string _name;

public:
    NewPaper(std::string name):_name(name) {
        std::cout << "read newpaper name : " << _name << std::endl;
    }

    ~NewPaper(){
        std::cout << "read newpaper over " << std::endl;
    }

    void ReadText() {
        std::cout << "this newpaper name : "
                << _name 
                << "is new newpaper"
                << std::endl;
    }
};
 

class Reciter
{
private:
    Reader *_Ireader;
public:
    Reciter(Reader *Ireader):_Ireader(Ireader) {}

    void Read() {
        _Ireader->ReadText();
    }
    
    ~Reciter(){}
};

// class Mother : public Reader
// {
// private:
     
// public:
//     Mother() {}
//     ~Mother() {}
// };
 

// class Father
// {
// private:
  
// public:
//     Father() {

//     }
//     ~Father() {

//     }
    
// };



int main() 
{
    Reciter myReciter(new NewPaper("南方日报"));
    myReciter.Read();

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    return 0; 
}

