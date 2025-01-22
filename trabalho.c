#include <stdio.h>
#include <stdlib.h>
#define MAX 500

struct info
{
    char data[11];
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
    printf("5. Sair\n");
    printf("==========================\n");
    printf("Escolha uma opcao: ");
}

struct info* registrardados(struct info *info_clima, int *quantidade, FILE *dados_c){
    struct info *locar = realloc(info_clima, (*quantidade + 1) *sizeof(struct info));
    if (locar == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return info_clima;
    }
    info_clima = locar;
    printf("Data(dd/mm/aaaa): ");
    fgets(info_clima[*quantidade].data, 11, stdin);
    printf("Temperatura media: ");
    scanf("%f", &info_clima[*quantidade].tempmedia);
    getchar();
    printf("Precipitacao: ");
    scanf("%f", &info_clima[*quantidade].precipi);
    getchar();
    printf("Umidade: ");
    scanf("%f", &info_clima[*quantidade].umid);
    getchar();
    printf("Velocidade do vento(km/h): ");
    scanf("%f", &info_clima[*quantidade].vel_vento);
    getchar();
    fprintf(dados_c, "Data: %s\nTemperatura Media: %.2f°C\nPrecipitação: %.1f mm\nUmidade: %.2f\nVelocidade do vento: %.2f km/h", info_clima[*quantidade].data, info_clima[*quantidade].tempmedia, info_clima[*quantidade].precipi,info_clima[*quantidade].umid, info_clima[*quantidade].vel_vento);
}

int main(){
    struct info *info_clima = NULL;
    char loc[MAX+1];
    int opcao;
    int quantidade=0;
    char resposta[1];
    FILE *dados_c;
    dados_c = fopen("dados_climaticos.txt", "w");
    if (dados_c == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
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
            info_clima = registrardados(info_clima, &quantidade, dados_c);
            break;
        




        case 5:
            printf("Encerrando o programa...");

        default:
            printf("Opção inválida! Tente novamente.\n");
            return 0;
        }

    }
    return 0;
}