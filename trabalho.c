#include <stdio.h>
#include <stdlib.h>
#define MAX 500

struct info
{
    char data[10];
    float tempmedia;
    float precipi;
    float umid;
    float vel_vento;
};

void exibirMenu() {
    printf("\n========== MENU ==========\n");
    printf("1. Registrar dados climaticos\n");
    printf("2. Gerar relatorios mensais\n");
    printf("3. Gerar relatorios anuais\n");
    printf("4. Detectar comportamentos fora do padrao\n");
    printf("==========================\n");
    printf("Escolha uma opcao: ");
}

struct info* registrardados(struct info *info_clima, int *quantidade){
    struct info *locar = realloc(info_clima, (*quantidade + 1) *sizeof(struct info));
    if (locar == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return info_clima;
    }
    info_clima = locar;
    printf("Data(dd/mm/aaaa): ");
    fgets(info_clima[*quantidade].data, 10, stdin);
    printf("Temperatura media: ");
    scanf("%f", &info_clima[*quantidade].tempmedia);
    getchar();
    printf("Precipatacao: ");
    scanf("%f", &info_clima[*quantidade].precipi);
    getchar();
    printf("Umidade: ");
    scanf("%f", &info_clima[*quantidade].umid);
    getchar();
    printf("Velocidade do vento(km/h): ");
    scanf("%f", &info_clima[*quantidade].vel_vento);
    getchar();
}

int main(){
    struct info *info_clima = NULL;
    char loc[MAX+1];
    int opcao;
    int quantidade=0;
    char resposta[1];
    FILE *dados_c;
        //ERROR
    printf("Digite o nome do estado: ");
    fgets(loc, MAX+1, stdin);
    
    while (1)
    {
        exibirMenu();
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
        case 1:
            info_clima = registrardados(info_clima, &quantidade);
            break;
        
        default:
            printf("Opção inválida! Tente novamente.\n");
        }

    }
    
}