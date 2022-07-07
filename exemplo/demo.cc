#include<saudacao/saudacao.hh>
#include<iostream>

int main(int argc, char const *argv[])
{
    std::string msg = "mundo";
    if (argc == 2){
        msg = argv[1];
    }
    
    saudacao::Saudacao teste(msg);

    teste.ola_mundo();

    return 0;
}
