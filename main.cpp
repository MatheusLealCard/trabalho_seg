// Caros espectadores caso estiver no windows, usa a flag pro c++11 ou maior v
// Caros amigos que estiverem no dev c++, vá em "Ferramentas(ou tools)", continua... 
// selecione a opcao "compilador(ou compiler options)"
// marca a opcao "adicionar os seguintes comandos(ou add the folowing commands when calling the compiler)"
// se tiver marcado deixa
// no campo do texto(se tiver algo la so dar um espaco) coloca -std=c++11 clica em ok e compila e roda

#include <iostream>
#include <vector>
#include <string>
#include <limits>

#if defined(_WIN32)
    #define PRINT "cls"
#elif defined(__linux__)
    #define PRINT "clear"
#endif

int total_alunos;
int total_notas;
int media_escola;
int alunos_reprovados;
int alunos_aprovados;
int total_feminino;
int total_masculino;
float percentual_aprovados;
float total_todos;
float media_turma;

class Aluno {
    public:
        std::string nome;
        int idade;
        std::string sexo;
        std::vector<float> notas;
        bool aprovado;
};

void get_alunos_data(Aluno &a);
float calcula_media(std::vector<float>& nota);
void list_alunos(Aluno &a);

int main() {
    std::cout << "Quantos alunos no total? " << std::endl;
    std::cin >> total_alunos;

    std::cout << "Quantas notas no total? " << std::endl;
    std::cin >> total_notas;

    std::cout << "Qual a media da escola? " << std::endl;
    std::cin >> media_escola;

    std::vector<Aluno> alunos(total_alunos);
    
    system(PRINT);

    for (int i = 0; i < total_alunos; i++) {
        get_alunos_data(alunos[i]);
    }
   
    for (int i = 0; i < total_alunos; i++) {
        float nota_aluno = calcula_media(alunos[i].notas);
        list_alunos(alunos[i]);
        std::cout << "Media do aluno: " << nota_aluno << std::endl; 
        if (nota_aluno < media_escola) {
            alunos[i].aprovado = false;
            std::cout << "Status: Reprovado" << std::endl;
        } else {
            alunos[i].aprovado = true;
            std::cout << "Status: Aprovado" << std::endl;
        }
        if (alunos[i].aprovado == 0) {
            alunos_reprovados += 1;
        }
    }
    std::cout << "----------------------------" << std::endl;
    
    alunos_aprovados = total_alunos - alunos_reprovados;
    percentual_aprovados = (float)alunos_aprovados / total_alunos * 100.0f;
    total_feminino = total_alunos - total_masculino;

    std::cout << "Total alunos reprovados: " << alunos_reprovados << std::endl;
    std::cout << "Taxa de aprovacao: " << percentual_aprovados << "%" << std::endl;
    std::cout << "Homens no total: " << total_masculino << std::endl;
    std::cout << "Mulheres no total: " << total_feminino << std::endl;

    for (int i  = 0; i < total_alunos; i++) {
        for (int j = 0; j < total_notas; j++) {
            total_todos += alunos[i].notas[j];
        }
    }
    media_turma = total_todos / (total_alunos * total_notas);

    std::cout << "Total aritmetica turma: " << media_turma << std::endl;
}

// nao entendi por que o template nao pode ficar nos meus prototipos, por isso nao ta la em cima
template <typename T>
T falha_input(const std::string &pergunta, const std::string &erro_mensagem) {
    T valor;
    while(true) {
        std::cout << pergunta << std::endl;
        std::cin >> valor;
        if (std::cin.fail()) {
            std::cin.clear();
            // cin loop infinito se buffer nao vazio
            // LEMBRETE isso aqui em bxo faz o sgyunte: numeric_limits percorre o tamanho do buffer do cin
            // se digitar o type errado e o cin antigo foi abc ele percorre esses 4bytes contanu o \n
            // entao nao aumenta o tempo de execucao, a nao ser que escrevam a biblia inteira no cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << erro_mensagem << std::endl;   
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return valor;
}

void get_alunos_data(Aluno &a) {
    int i = 0;
    a.notas.resize(total_notas);
    
    // resolver o nome do aluno depois
    a.nome = falha_input<std::string>("Qual o nome do aluno? ", "Apenas letras");
    a.idade = falha_input<int>("Qual a idade do aluno? ", "Apenas numeros inteiros");
    a.sexo = falha_input<std::string>("Qual o sexo do aluno(M/F)?", "Apenas M/F");
  
    a.notas.resize(total_notas);
    for (int j = 0; j < total_notas; j++) {
        // falta colocar o check aq, preguicoso
        a.notas[j] = falha_input<float>("Qual a nota", "apenas floats");
    }
    system(PRINT);
}

void list_alunos(Aluno &a) {
    std::cout << "----------------------------" << std::endl;
    std::cout << "Nome: " << a.nome << std::endl;
    std::cout << "Idade: " << a.idade << std::endl;
    std::cout << "Sexo: " << a.sexo << std::endl;

    // se for l é mulher kkkk, resolve ai dpois
    if (a.sexo == "M" || a.sexo == "m") {
        total_masculino += 1;
    }     
    // qr ver todas as notas? me apag
    //for (int j = 0; j < total_notas; j++) {
    //    //std::cout << nota[j] << std::endl;
    //    std::cout << "Nota " << j + 1 << ": " << a.notas[j] << std::endl;
    //}
}

float calcula_media(std::vector<float>& nota) {
    float soma = 0.0f;
    
    for (float n : nota) {
        soma += n;
    }
    return soma / nota.size();
}
