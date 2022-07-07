#ifndef SAUDACAO_HH_
#define SAUDACAO_HH_

#include <iostream>

namespace saudacao{
    class Saudacao
    {
        public:
            Saudacao(std::string msg);
            void ola_mundo();
        private:
             std::string mensagem;
    };
}

#endif // SAUDACAO_HH_