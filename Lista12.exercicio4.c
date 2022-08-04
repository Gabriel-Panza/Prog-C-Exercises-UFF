# include <stdio.h>

int conversao_binaria(int n, int *vetor_binario, int tamanho, int tamanho_fixo) // o "tamanho_fixo" eh usado somente na ultima chamada da funcao no vetor_binario
{
    vetor_binario[tamanho] = (n % 2); // as ultimas posicoes do vetor receberao o resto dessa divisao
    n /= 2; // o "n" precisa ser divido para continuar os proximos calculos corretamente
    if(tamanho > 0) // esse "if" eh usado em todas as funcoes recursivas exceto a ultima chamada quando o tamamho for igual a zero
    {
        tamanho--; // a funcao a ser chamada recebera um tamanho decrementado
        return conversao_binaria(n, vetor_binario, tamanho, tamanho_fixo); // chama a funcao recursivamente com tamanho decrementado
    }
    if(tamanho == 0) // apenas na ultima chamada sera feito isso
    {
        int indice, binario; // binario sera para armazenar os valores convertidos em binario e valor de retorno
        binario = 0;
        for(indice = 0; indice < tamanho_fixo; indice++)
        {
            if(indice == 0)
            {
                if(vetor_binario[indice] == 0) // se o vetor tem o valor zero
                {
                    binario = 0;
                }
                else // se o vetor tem o valor 1
                {
                    binario = 1;
                }
            }
            else
            {
                if(vetor_binario[indice] == 0) // se o valor de tal posicao (indice) do vetor for igual a zero, entao acrescenta um zero ao valor de binario
                {
                    binario *= 10;
                }
                else
                {
                    binario = (binario * 10) + 1; // se o valor de tal posicao (indice) for igual a 1, entao acrescenta um "1" ao valor de binario
                }
            }
        }
        return binario;
    }
}

int main(void)
{
    int n; // numero a ser convertido em binario
    printf("Insira um valor inteiro decimal para ser convertido em binario: "); // pergunta ao usuario
    scanf("%d", &n); // leitura do numero a ser convertido em binario

    int indice, tamanho, tamanho_fixo, numero_binario;
    tamanho = 0; // zerando o tamanho do vetor
    for(indice = n; indice > 0; )
    {
        indice /= 2; // lado para especificar o tamanho do vetor
        tamanho++;
    }

    tamanho_fixo = tamanho; // usado na funcao recursiva
    int vetor_binario[tamanho]; // vetor com o tamanho encontrado anteriormente no lado
    tamanho -= 1; // decrementa o tamanho para ser usado nessa forma na funcao

    numero_binario = conversao_binaria(n, vetor_binario, tamanho, tamanho_fixo); // a funcao retornara um inteiro formatado como um "binario"
    printf("\nO numero digitado em binario eh: %d", numero_binario);
    getch();
    return 0;
}

                                            /* RESPOSTA */                                                              
// Quando digitamos um numero de mais de 10 bits, o codigo printa errado. De resto, tudo esta funcionando como deveria