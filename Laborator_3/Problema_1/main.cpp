#include "Math.h"
#include <iostream>

int main()
{
    std::cout<<"3+3= "<<Math::Add(3,3)<<std::endl;
    std::cout<<"1+2+3= "<<Math::Add(1,2,3)<<std::endl;
    std::cout<<"2.2+3.5= "<<Math::Add(2.2, 3.5)<<std::endl;
    std::cout<<"1.2+3.4+5.2= "<<Math::Add(1.2, 3.4, 5.2)<<std::endl;
    std::cout<<"3*5= "<<Math::Mul(3,5)<<std::endl;
    std::cout<<"2*3*5= "<<Math::Mul(2,3,5)<<std::endl;
    std::cout<<"2.2*2.4*4.9= "<<Math::Mul(2.2,2.4,4.9)<<std::endl;
    std::cout<<"3.3*1.2*7.32= "<<Math::Mul(3.3,1.2,7.32)<<std::endl;
    std::cout<<"1+2+3+4+5+6+7+8+9+10= "<<Math::Add(10,1,2,3,4,5,6,7,8,9,10)<<std::endl;

    const char* s1="OOP";
    const char* s2="rimavara frumoasa!";
    const char* s3=Math::Add(s1,s2);

    if(s3==nullptr)
        std::cout<<"Unul dintre siruri este vid"<<std::endl;
    else
    {
        std::cout<<s3<<std::endl;
        delete [] s3;
    }
    return 0;
}
