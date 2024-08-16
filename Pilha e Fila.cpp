/*Considere uma pilha P vazia e uma fila F não vazia.
Utilizando apenas as operações inserir/enfileirar e remover/desenfileirar de ambas as estruturas, escreva uma função que inverta a ordem dos elementos da fila.*/

#include<stdio.h>

struct No
{
    int valor;
    No* prox;

    No()
    {
        prox = NULL;
    }

    No(int _valor)
    {
        valor = _valor;
        prox = NULL;
    }

};

struct Fila
{
    No* inicio;
    No* fim;
    int n;

    Fila()
    {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void enfileirar(int valor)
    {
        No* novo = new No(valor);
        if(inicio == NULL)
        {
            inicio = novo;
            fim = novo;
        }
        else
        {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void desenfileirar()
    {
        if (n == 0) return;
        if (n == 1)
        {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    int frenteFila(){
        if(n == 0) return 0;
        return inicio->valor;
    }
};

struct Pilha
{
    No* inicio;
    int tam;

    Pilha()
    {
        inicio = NULL;
        tam = 0;
    }

    void empilhar (int valor)
    {
        No* novo = new No(valor);
        if(inicio == NULL)
        {
            inicio = novo;
        }
        else
        {
            novo->prox = inicio;
            inicio = novo;
        }
        tam++;
    }

    void desempilhar(){
        if (tam == 0) return;
        if (tam == 1)
        {
            delete(inicio);
            inicio = NULL;
            tam--;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        tam--;
    }

    void inverter(Fila& f){
        while(f.n > 0){
            empilhar(f.frenteFila());
            f.desenfileirar();
        }
    }

    void imprimir()
    {
        No* aux = inicio;
        if(aux != NULL)
        {
            printf("%d", aux->valor);
            aux = aux->prox;
            desempilhar();
        }
        while(aux != NULL)
        {
            printf(" %d", aux->valor);
            aux = aux->prox;
            desempilhar();
        }
        printf("\n");
    }

};

int main()
{
    Fila f;
    Pilha p;
    int quantidade;

    printf("Digite a quantidade de elementos que quer inserir na fila:\n");
    scanf("%d", &quantidade);

    while(quantidade--){
        int valor;
        scanf("%d", &valor);
        f.enfileirar(valor);
    }

    p.inverter(f);
    printf("Fila invertida\n");
    p.imprimir();

    return 0;
}
