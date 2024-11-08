#include <iostream>
using namespace std;
// representanod a estrutura base da arvore
struct No
{
    int valor;
    No *esq;
    No *dir;
};

// criando a raiz no escopo global valendo null
No *raiz = NULL;

// funcao para inserir um valor na estrutura da arvore
void inserir(int valor)
{

    // criando o elemento com o valor a ser inserido!
    No *el = (No *)malloc(sizeof(No));
    el->valor = valor;
    el->dir = NULL;
    el->esq = NULL;

    // caso não exista arvore, a raiz é o proprio elemento
    if (raiz == NULL)
        raiz = el;
    else
    {
        No *aux = raiz; // no auxiliar que percore a estrutura
                        // a estrutura
        while (true)
        {
            if (valor < aux->valor)
            {
                if (aux->esq == NULL)
                {
                    aux->esq = el;
                    return;
                }
                aux = aux->esq; // caso n ache posição valida continua navegar para esq
            }

            else if (valor > aux->valor)
            {
                if (aux->dir == NULL)
                {
                    aux->dir = el;
                    return;
                }
                aux = aux->dir;
            }
        }
    }
}

int main()
{
    // utilizando o metodo de inserir
    inserir(15);
    inserir(7);
    inserir(21);
    inserir(13);
    inserir(11);
    inserir(5);
    return 0;
}