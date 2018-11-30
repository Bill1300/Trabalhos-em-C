#include<stdio.h>
#include<math.h>
#include<string.h>

//ASCII > UTF-8
int ai = 160;
int ui = 163;
int as = 198;
int ei = 130;
int cc = 135;
int os = 147;

char a[16]; //Vetor base para a converção da tabela ASCII

//Printa varios espaçamentos para limpar a tela
void clean(){
    for(int n=0; n < 20; n++){
        printf("\n");
    }
}

//Printa as opções do menu inicial
void inicial(){
    printf("\n Op%c%ces:\n",cc,os);
    printf("\n 1- Bin%crio para Decimal\n", ai);
    printf("\n 2- Decimal para Bin%crio\n", ai);
    printf("\n 3- Decimal para Hexadecimal\n");
    printf("\n 4- Hexadecimal para Decimal\n");
    printf("\n 5- Bin%crio para Hexadecimal\n", ai);
    printf("\n 6- Hexadecimal para Bin%crio\n", ai);
}

//Printa um vetor
void print_vet(long int*vet, int n){
    printf("\n Os valores respectivamente s%co: ", as);
    for (int i = 0; i < n; i++){
        printf("\n %ld", vet[i]);
    }
}

//Converte um numero decimal para binario
long int convert_dec_to_bin(long int dec){
    if (dec == 0){ //Caso de parada
        return 0;
    }
    else{
        return(dec % 2 + 10 * convert_dec_to_bin(dec / 2)); //Lógica de conversão
    }
}

//Converte um numero binario para decimal
long int convert_bin_to_dec(long int bin){
    if(!(bin / 10)){ //Caso de parada
        return (bin);
    }
    return(bin % 10 + convert_bin_to_dec(bin / 10) * 2); //Lógica de conversão
}

//Convert um numero hexadecimal para decimal
long int convert_hex_to_dec(char*hex, int i, int n){
    long int x, decimal = 0;
    if(n > 0){ //Caso de parada
        if(hex[i]>='0' && hex[i]<='9'){  //Converte a tabela ASCII quando for letra ou numero
            x = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f'){
            x = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F'){
            x = hex[i] - 65 + 10;
        }
        decimal = convert_hex_to_dec(hex,i+1, n-1) + x * pow(16,n-1); //Lógica de conversão
    }
    return decimal;
}

//Converte um numero hexadecimal para binario
long int convert_hex_to_bin(char*hex, int n){ //Ponte com duas funções para converter
    long int dec = convert_hex_to_dec(hex, 0, n);
    long int bin = convert_dec_to_bin(dec);
    return bin;
}

//Converte um numero decimal para hexadecimal
void convert_dec_to_hex(int n, char *hex, int i){
    if(!n){ //Caso de parada
        return;
    }
    hex[i] = a[n%16];
    convert_dec_to_hex(n/16, hex, i-1); //Lógica de conversão
}

int main(){
    // Variaveis constantes:
    int opcao, saida = 1;
    long int bin, dec;
    char hexa[10];
    long int vet[10];
    while (saida != 0){ //Loop para repetir caso o usuario deseje
        printf("\n Conversor de Casa Num%crica\n", ei);
        inicial();
        printf("\n 7- Convers%co de Conjunto de N%cmeros\n", as, ui);
        printf("\n\n");
        scanf("%d", &opcao);
        clean();
        //Lista de opções referente a escolha do usuario:
        if (opcao == 1){
            printf("\n Insira o n%cmero Bin%crio que deseja converter para Decimal: ", ui, ai);
            scanf("%ld", &bin);
            long int dec_convertido = convert_bin_to_dec(bin); //Chamada da função
            printf("\n O n%cmero decimal referente a %ld é: %ld", bin, dec_convertido);
            printf("\n");
        }
        else if (opcao == 2){
            printf("\n Insira o n%cmero Decimal que deseja converter para Bin%crio: ", ui, ai);
            scanf("%ld", &dec);
            long int bin_convertido = convert_dec_to_bin(dec); //Chamada da função
            printf("\n O n%cmero Bin%crio referente a %ld %c: %ld", ui, ai, dec, ei, bin_convertido);
            printf("\n");
        }
        else if (opcao == 3){
            for(int i = 0; i < 16; i++){ //Caso para identificar se vai ser uma letra ou numero
                if(i < 10){
                    a[i] = i + '0';
                }
                else{
                    a[i] = i - 10 + 'A';
                }
            }
            printf("\n Insira o numero Decimal que deseja converter para Hexadecimal: ");
            scanf("%ld", &dec);
            int nDigits = floor(log2(dec) / log2(16)) + 1; //Identifica o tamanho da string apartir do numero decimal
            char n_hex[nDigits];
            n_hex[nDigits] = '\0'; //Marca o fim da string
            convert_dec_to_hex(dec, n_hex, nDigits-1); //Chamada da função
            printf("\n O valor Hexadecimal referente a %ld é: %s", dec, n_hex);
            printf("\n");
        }

        else if (opcao == 4){
            printf("\n Insira o n%cmero Hexadecimal que deseja converter para Decimal: ",ui);
            scanf("%s", hexa);
            int tamanho = strlen(hexa); //Identifica o tamanho da string
            long int dec_convertido = convert_hex_to_dec(hexa, 0, tamanho); //Chamada da função
            printf("\n O n%cmero Decimal referente a %s %c: %ld", ui, hexa, ei, dec_convertido);
            printf("\n");
        }

        else if (opcao == 5){
            for(int i = 0; i < 16; i++){ //Caso para identificar se vai ser uma letra ou numero
                if(i < 10){
                    a[i] = i + '0';
                }
                else{
                    a[i] = i - 10 + 'A';
                }
            }
            printf("\n Insira o n%cmero Bin%crio que deseja converter para Hexadecimal: ", ui, ai);
            scanf("%ld", &bin);
            dec = convert_bin_to_dec(bin); //Chamada da função
            int nDigits = floor(log2(dec) / log2(16)) + 1; //Identifica o tamanho da string apartir do numero decimal
            char n_hex[nDigits];
            n_hex[nDigits] = '\0'; //Marca o fim da string
            convert_dec_to_hex(dec, n_hex, nDigits-1); //Chamada da função
            printf("\n O valor Hexadecimal referente a %ld %c: %s", bin, ei, n_hex);
            printf("\n");
        }

        else if (opcao == 6){
            printf("\n Insira o n%cmero Hexadecimal que deseja converter para Bin%crio: ", ui, ai);
            scanf("%s", hexa);
            int tamanho = strlen(hexa); //Identifica o tamanho da string
            long int bin_convertido = convert_hex_to_bin(hexa, tamanho); //Chamada da função
            printf("\n O n%cmero Bin%crio referente a %s %c: %ld", ui, ai, hexa, ei, bin_convertido);
            printf("\n");
        }

        else if (opcao == 7){
            int qtd, resp;
            long int aux;
            printf("\n De qual casa decimal para qual deseja escolher ?\n");
            inicial();
            printf("\n\n");
            scanf("%d", &resp); //Tipo de converção
            printf("\n Quantos valores deseja converter ?\n");
            printf("\n\n");
            scanf("%d", &qtd); //Numero do grupo para a converção
            if (resp == 1){
                for (int n = 0; n < qtd; n++){
                    printf("\n Insira seu %dº valor: ", n);
                    scanf("%ld", &aux);
                    vet[n] = convert_bin_to_dec(aux); //Chamada da função
                }
                print_vet(vet, qtd); //Printa o vetor convertido
                printf("\n");
            }
            else if (resp == 2){
                for (int n = 0; n < qtd; n++){
                    printf("\n Insira seu %dº valor: ", n);
                    scanf("%ld", &aux);
                    vet[n] = convert_dec_to_bin(aux); //Chamada da função
                }
                print_vet(vet, qtd); //Printa o vetor convertido
                printf("\n");
            }
            else if (resp == 3){
                for(int i = 0; i < 16; i++){ //Caso para identificar se vai ser uma letra ou numero
                    if(i < 10){
                        a[i] = i + '0';
                    }
                    else{
                        a[i] = i - 10 + 'A';
                    }
                }
                for(int n = 0; n < qtd; n++){
                    printf("\n Insira o n%cmero Decimal que deseja converter para Hexadecimal: ", ui);
                    scanf("%ld", &dec);
                    int nDigits = floor(log2(dec) / log2(16)) + 1; //Identifica o tamanho da string apartir do numero decimal
                    char n_hex[nDigits];
                    n_hex[nDigits] = '\0'; //Marca o fim da string
                    convert_dec_to_hex(dec, n_hex, nDigits-1); //Chamada da função
                    printf("\n O valor Hexadecimal referente a %ld %c: %s", dec, ei, n_hex);
                    printf("\n");
                }
            }
            else if (resp == 4){
                for(int n = 0; n < qtd; n++){
                    printf("\n Insira o n%cmero Hexadecimal que deseja converter para Decimal: ", ui);
                    scanf("%s", hexa);
                    int tamanho = strlen(hexa); //Identifica o tamanho da string
                    long int dec_convertido = convert_hex_to_dec(hexa, 0, tamanho); //Chamada da função
                    printf("\n O n%cmero decimal referente a %s %c: %ld",ui, hexa,ei, dec_convertido);
                    printf("\n");
                }
            }
            else if (resp == 5){
                for(int i = 0; i < 16; i++){ //Caso para identificar se vai ser uma letra ou numero
                    if(i < 10){
                        a[i] = i + '0';
                    }
                    else{
                        a[i] = i - 10 + 'A';
                    }
                }
                for(int n = 0; n < qtd; n++){
                    printf("\n Insira o n%cmero Bin%crio que deseja converter para Hexadecimal: ", ui);
                    scanf("%ld", &bin);
                    dec = convert_bin_to_dec(bin); //Chamada da função
                    int nDigits = floor(log2(dec) / log2(16)) + 1; //Identifica o tamanho da string apartir do numero decimal
                    char n_hex[nDigits];
                    n_hex[nDigits] = '\0'; //Marca o fim da string
                    convert_dec_to_hex(dec, n_hex, nDigits-1); //Chamada da função
                    printf("\n O valor Hexadecimal referente a %ld %c: %s", bin, ei, n_hex);
                    printf("\n");
                }
            }
            else if (resp == 6){
                for(int n = 0; n < qtd; n++){
                    printf("\n Insira o n%cmero Hexadecimal que deseja converter para Bin%crio: ", ui, ai);
                    scanf("%s", hexa);
                    int tamanho = strlen(hexa); //Identifica o tamanho da string
                    long int bin_convertido = convert_hex_to_bin(hexa, tamanho); //Chamada da função
                    printf("\n O n%cmero Bin%crio referente a %s %c: %ld", ui, ai, hexa, ei, bin_convertido);
                    printf("\n");
                }
            }
            else{
                printf("\n Ação Inv%clida!\n\n",ai); //Print caso a opção selecionado não seja valida
            }
        }
        else{
            printf("\n Ação Inv%clida!\n\n",ai); //Print caso a opção selecionado não seja valida
        }
        printf("\n\n");
        printf("\n Se deseja fazer outra conver%c%co digite 1, sen%co digite 0: ", cc, as, as);
        clean();
        scanf("%d", &saida); //Resposta para a saida ou não do loop
    }
    return (0);
}
