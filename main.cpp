#include <iostream>
#include <string>

float calcula_media(float *, int);

#define TOTAL_NOTAS_SIZE 3

#if defined(_WIN32)
    #define PRINT "cls"
#elif defined(__linux__)
    #define PRINT "clear"
#endif 

int total_alunos = 0;
int media_escola = 5;

class Aluno {
    public:
        std::string nome;
        int idade;
        std::string sexo;
        float notas[TOTAL_NOTAS_SIZE];
};

int main() {
    std::cout << "Quantos alunos no total? " << std::endl;
    std::cin >> total_alunos;

    std::cout << "Qual a media da escola? " << std::endl;
    std::cin >> media_escola;

    system(PRINT);

    Aluno alunos[total_alunos];
    
    for (int i = 0; i < total_alunos; i++) {
        std::cout << "Qual o nome do " << i + 1 << " aluno? " << std::endl;
        std::cin >> alunos[i].nome;

        std::cout << "Qual a idade do " << alunos[i].nome << " ? " << std::endl;
        std::cin >> alunos[i].idade;
        
        std::cout << "Qual o sexo do " << alunos[i].nome << " ? " << std::endl;
        std::cin >> alunos[i].sexo;

        for (int j = 0; j < TOTAL_NOTAS_SIZE; j++) {
            std::cout << "Qual a " << j + 1 << " nota do " << alunos[i].nome << " ? " << std::endl;
            std::cin >> alunos[i].notas[j];
        }
        system(PRINT);
    }
    
    for (int i = 0; i < total_alunos; i++) {
        float nota_aluno = calcula_media(alunos[i].notas, TOTAL_NOTAS_SIZE);
        std::cout << "----------------------------" << std::endl;
        std::cout << "Nome: " << alunos[i].nome << std::endl;
        std::cout << "idade: " << alunos[i].idade << std::endl;
        std::cout << "sexo: " << alunos[i].sexo << std::endl;

        //Print notas
        //for (int j = 0; j < TOTAL_NOTAS_SIZE; j++) {
        //    std::cout << "Nota " << j + 1 << ": " << alunos[i].notas[j] << std::endl;
        //}
        
        std::cout << "Media do aluno: " << nota_aluno << std::endl; 

        if (nota_aluno < media_escola) {
            std::cout << "Status: Reprovado" << std::endl;
        } else {
            std::cout << "Status: Aprovado" << std::endl;
        }
    }
    std::cout << "----------------------------" << std::endl;
}

float calcula_media(float *lista, int arr_size) {
    if (arr_size == 0) return 0.0f;
    float soma = 0.0f;

    for (int i = 0; i < arr_size; i++) {
        soma += lista[i];
    } 
    return soma / arr_size;
}
