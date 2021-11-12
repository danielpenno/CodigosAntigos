#include <iostream>
#include <cstdlib>

using namespace std;

struct no
{
    int idade;
    struct no *filhoEsquerdo;
    struct no *filhoDireito;
} * raiz;

class Pessoa
{
public:
    int altura(no *);
    int diferenca(no *);
    no *rotacao_dd(no *);
    no *rotacao_ee(no *);
    no *rotacao_ed(no *);
    no *rotacao_de(no *);
    no *balancear(no *);
    no *dois_filhos(no *);
    no *inserir(no *, int);
    no *excluir(no *, int);
    void visualizar(no *, int);
    void emOrdem(no *);
    void preOrdem(no *);
    void posOrdem(no *);
    void libMem(no *);
    Pessoa()
    {
        raiz = NULL;
    }
};

int main()
{
    int opcao, valor;
    Pessoa avl;
    while (1)
    {
        cout << "===============================================================================" << endl;
        cout << "1. Inserir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Em Ordem" << endl;
        cout << "4. Pre Ordem" << endl;
        cout << "5. Pos Ordem" << endl;
        cout << "6. Sair" << endl;
        cout << "===============================================================================" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            raiz = avl.inserir(raiz, valor);
            system("cls");
            break;
        case 2:
            cout << "Digite o valor a ser deletado: ";
            cin >> valor;
            raiz = avl.excluir(raiz, valor);
            system("cls");
            break;
        case 3:
            system("cls");
            if (raiz == NULL)
            {
                cout << "===============================================================================" << endl;
                cout << "Arvore esta vazia!" << endl;
                break;
            }
            cout << "===============================================================================" << endl;
            cout << "Caminho em Ordem:" << endl;
            avl.emOrdem(raiz);
            cout << endl;
            break;
        case 4:
            system("cls");
            if (raiz == NULL)
            {
                cout << "===============================================================================" << endl;
                cout << "Arvore esta vazia!" << endl;
                break;
            }
            cout << "===============================================================================" << endl;
            cout << "Caminho em PRE Ordem:" << endl;
            avl.preOrdem(raiz);
            cout << endl;
            break;
        case 5:
            system("cls");
            if (raiz == NULL)
            {
                cout << "===============================================================================" << endl;
                cout << "Arvore esta vazia!" << endl;
                break;
            }
            cout << "===============================================================================" << endl;
            cout << "Caminho em POS Ordem:" << endl;
            avl.posOrdem(raiz);
            cout << endl;
            break;
        case 6:
            return 0;
            break;
        }
    }
    avl.libMem(raiz);
    return 0;
}

int Pessoa::altura(no *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int altura_e = altura(temp->filhoEsquerdo);
        int altura_d = altura(temp->filhoDireito);
        int max_altura = max(altura_e, altura_d);
        h = max_altura + 1;
    }
    return h;
}

int Pessoa::diferenca(no *temp)
{
    int altura_e = altura(temp->filhoEsquerdo);
    int altura_d = altura(temp->filhoDireito);
    int fator = altura_e - altura_d;
    return fator;
}

no *Pessoa::rotacao_dd(no *pai)
{
    no *temp;
    temp = pai->filhoDireito;
    pai->filhoDireito = temp->filhoEsquerdo;
    temp->filhoEsquerdo = pai;
    return temp;
}

no *Pessoa::rotacao_ee(no *pai)
{
    no *temp;
    temp = pai->filhoEsquerdo;
    pai->filhoEsquerdo = temp->filhoDireito;
    temp->filhoDireito = pai;
    return temp;
}

no *Pessoa::rotacao_ed(no *pai)
{
    no *temp;
    temp = pai->filhoEsquerdo;
    pai->filhoEsquerdo = rotacao_dd(temp);
    return rotacao_ee(pai);
}

no *Pessoa::rotacao_de(no *pai)
{
    no *temp;
    temp = pai->filhoDireito;
    pai->filhoDireito = rotacao_ee(temp);
    return rotacao_dd(pai);
}

no *Pessoa::balancear(no *temp)
{
    int fator = diferenca(temp);
    if (fator > 1)
    {
        if (diferenca(temp->filhoEsquerdo) > 0)
        {
            temp = rotacao_ee(temp);
        }
        else
        {
            temp = rotacao_ed(temp);
        }
    }
    else if (fator < -1)
    {
        if (diferenca(temp->filhoDireito) > 0)
        {
            temp = rotacao_de(temp);
        }
        else
        {
            temp = rotacao_dd(temp);
        }
    }
    return temp;
}
no *Pessoa::dois_filhos(no *n)
{
    if (n == NULL)
    {
        return NULL;
    }
    else if (n->filhoEsquerdo == NULL)
    {
        return n;
    }
    else
    {
        return dois_filhos(n->filhoEsquerdo);
    }
}

no *Pessoa::inserir(no *raiz, int busca)
{
    if (raiz == NULL)
    {
        raiz = new no;
        raiz->idade = busca;
        raiz->filhoEsquerdo = NULL;
        raiz->filhoDireito = NULL;
        return raiz;
    }
    else if (busca < raiz->idade)
    {
        raiz->filhoEsquerdo = inserir(raiz->filhoEsquerdo, busca);
        raiz = balancear(raiz);
    }
    else if (busca >= raiz->idade)
    {
        raiz->filhoDireito = inserir(raiz->filhoDireito, busca);
        raiz = balancear(raiz);
    }
    return raiz;
}

no *Pessoa::excluir(no *raiz, int busca)
{
    no *temp = NULL;
    if (raiz == NULL)
    {
        return raiz;
    }
    else if (busca < raiz->idade)
    {
        raiz->filhoEsquerdo = excluir(raiz->filhoEsquerdo, busca);
        raiz = balancear(raiz);
    }
    else if (busca > raiz->idade)
    {
        raiz->filhoDireito = excluir(raiz->filhoDireito, busca);
        raiz = balancear(raiz);
    }
    else
    {
        if (raiz->filhoEsquerdo == NULL && raiz->filhoDireito == NULL)
        {
            temp = raiz;
            delete temp;
            raiz = NULL;
        }
        else if (raiz->filhoEsquerdo == NULL)
        {
            temp = raiz;
            raiz = temp->filhoDireito;
            delete temp;
        }
        else if (raiz->filhoDireito == NULL)
        {
            temp = raiz;
            raiz = temp->filhoEsquerdo;
            delete temp;
        }
        else
        {
            temp = dois_filhos(raiz->filhoDireito);
            raiz->idade = temp->idade;
            raiz->filhoDireito = excluir(raiz->filhoDireito, raiz->idade);
        }
    }
    return raiz;
}

void Pessoa::emOrdem(no *arvore)
{
    if (arvore == NULL)
    {
        return;
    }
    emOrdem(arvore->filhoEsquerdo);
    cout << "[" << arvore->idade << "]  ";
    emOrdem(arvore->filhoDireito);
}

void Pessoa::preOrdem(no *arvore)
{
    if (arvore == NULL)
    {
        return;
    }
    cout << "[" << arvore->idade << "]  ";
    preOrdem(arvore->filhoEsquerdo);
    preOrdem(arvore->filhoDireito);
}

void Pessoa::posOrdem(no *arvore)
{
    if (arvore == NULL)
    {
        return;
    }
    posOrdem(arvore->filhoEsquerdo);
    posOrdem(arvore->filhoDireito);
    cout << "[" << arvore->idade << "]  ";
}

void Pessoa::libMem(no *arvore)
{
    if (arvore != NULL)
    {
        libMem(arvore->filhoEsquerdo);
        libMem(arvore->filhoDireito);
        delete arvore;
    }
}
