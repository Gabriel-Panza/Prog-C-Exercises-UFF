/*9. Faça a função main para funcionar com a função ordena.*/

struct aluno ALUNO
{
    int turma[100];
}
void ordena (ALUNO turma[], int tam) {
    int i, foraOrdem , jaOrdenados = 0;
    ALUNO temp;
    do {
        foraOrdem = 0;
        for (i = 0; i < 4 - 1 - jaOrdenados ; i++) {
            if (turma[i]. media > turma[i+1]. media) {
                temp = turma[i];
                turma[i] = turma[i+1];
                turma[i+1] = temp ;
                foraOrdem = 1;
            }
        }
    jaOrdenados ++;
    } while (foraOrdem);
}