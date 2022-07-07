#include<saudacao/saudacao.hh>

namespace saudacao{
    
    Saudacao::Saudacao(std::string msg){
        mensagem = msg;
    }

    void Saudacao::ola_mundo(){
        std::cout << "Olá " << mensagem << std::endl;
    }
};