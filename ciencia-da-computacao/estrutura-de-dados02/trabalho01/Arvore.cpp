#include <iostream>

using namespace std;

class Pessoa
{
protected:
    int idade;
    string nome;
    Pessoa *filhoEsquerdo;
    Pessoa *filhoDireito;

public:
    Pessoa();
    Pessoa(string nm, int idd);
    string getNome();
    void setNome(string nm);
    int getIdade();
    void setIdade(int idd);
    Pessoa *getFilhoEsquerdo();
    void setFilhoEsquerdo(Pessoa *fe);
    Pessoa *getFilhoDireito();
    void setFilhoDireito(Pessoa *fd);
    void insereNovoElemento(Pessoa *novo);
    void removerElemento(Pessoa *n, int d);
    void preOrdem();
    void preOrdem(Pessoa *inicio);
    void emOrdem();
    void emOrdem(Pessoa *inicio);
    void posOrdem();
    void posOrdem(Pessoa *inicio);
    void libMem(Pessoa *inicio);
};

Pessoa::Pessoa()
{
    nome = "";
    idade = 0;
    filhoEsquerdo = filhoDireito = NULL;
}

Pessoa::Pessoa(string nm, int idd)
{
    nome = nm;
    idade = idd;
    filhoEsquerdo = filhoDireito = NULL;
}

string Pessoa::getNome()
{
    return nome;
}

void Pessoa::setNome(string nm)
{
    nome = nm;
}

int Pessoa::getIdade()
{
    return idade;
}

void Pessoa::setIdade(int idd)
{
    idade = idd;
}

Pessoa *Pessoa::getFilhoEsquerdo()
{
    return filhoEsquerdo;
}

void Pessoa::setFilhoEsquerdo(Pessoa *fe)
{
    filhoEsquerdo = fe;
}

Pessoa *Pessoa::getFilhoDireito()
{
    return filhoDireito;
}

void Pessoa::setFilhoDireito(Pessoa *fd)
{
    filhoDireito = fd;
}

void Pessoa::insereNovoElemento(Pessoa *novo)
{
    if (novo->idade < this->idade)
    {
        if (this->filhoEsquerdo == NULL)
        {
            cout << "Inserindo novo elemento (" << novo->nome << " : " << novo->idade << ") � esquerda de: ";
            cout << this->nome << " : " << this->idade << endl;
            this->filhoEsquerdo = novo;
        }
        else
        {
            this->filhoEsquerdo->insereNovoElemento(novo);
        }
    }
    else
    {
        if (this->filhoDireito == NULL)
        {
            cout << "Inserindo novo elemento (" << novo->nome << " : " << novo->idade << ") � direita de: ";
            cout << this->nome << " : " << this->idade << endl;
            this->filhoDireito = novo;
        }
        else
        {
            this->filhoDireito->insereNovoElemento(novo);
        }
    }
}

void Pessoa::removerElemento(Pessoa *n, int d)
{
    bool found = false;
    if (n != NULL)
    {
        Pessoa *curr = NULL;
        Pessoa *parent = NULL;
        curr = n;
        while (curr != NULL)
        {
            if (curr->idade == d)
            {
                found = true;
                break;
            }
            else
            {
                parent = curr;
                if (d > curr->idade)
                {
                    curr = curr->filhoDireito;
                }
                else
                {
                    curr = curr->filhoEsquerdo;
                }
            }
        }
        if ((curr->filhoEsquerdo == NULL && curr->filhoDireito != NULL) || (curr->filhoEsquerdo != NULL && curr->filhoDireito == NULL))
        {
            if (curr->filhoEsquerdo == NULL && curr->filhoDireito != NULL)
            {
                if (parent->filhoEsquerdo == curr)
                {
                    parent->filhoEsquerdo = curr->filhoDireito;
                    delete curr;
                }
                else
                {
                    parent->filhoDireito = curr->filhoDireito;
                    delete curr;
                }
            }
            else
            {
                if (parent->filhoEsquerdo == curr)
                {
                    parent->filhoEsquerdo = curr->filhoEsquerdo;
                    delete curr;
                }
                else
                {
                    parent->filhoDireito = curr->filhoEsquerdo;
                    delete curr;
                }
            }
            return;
        }
        if (curr->filhoEsquerdo == NULL && curr->filhoDireito == NULL)
        {
            if (parent->filhoEsquerdo == curr)
            {
                parent->filhoEsquerdo = NULL;
            }
            else
            {
                parent->filhoDireito = NULL;
                delete curr;
                return;
            }
        }
        if (curr->filhoEsquerdo != NULL && curr->filhoDireito != NULL)
        {
            Pessoa *chkr = NULL;
            chkr = curr->filhoDireito;
            if ((chkr->filhoEsquerdo == NULL) && (chkr->filhoDireito == NULL))
            {
                curr = chkr;
                delete chkr;
                curr->filhoDireito = NULL;
            }
            else
            {
                if ((curr->filhoDireito)->filhoEsquerdo != NULL)
                {
                    Pessoa *lcurr = NULL;
                    Pessoa *lcurrp = NULL;
                    lcurrp = curr->filhoDireito;
                    lcurr = (curr->filhoDireito)->filhoEsquerdo;
                    while (lcurr->filhoEsquerdo != NULL)
                    {
                        lcurrp = lcurr;
                        lcurr = lcurr->filhoEsquerdo;
                    }
                    curr->idade = lcurr->idade;
                    curr->nome = lcurr->nome;
                    lcurrp->filhoEsquerdo = lcurr->filhoDireito;
                    delete lcurr;
                }
                else
                {
                    Pessoa *tmp = NULL;
                    tmp = curr->filhoDireito;
                    curr->idade = tmp->idade;
                    curr->nome = tmp->nome;
                    curr->filhoDireito = tmp->filhoDireito;
                    delete tmp;
                }
            }
            return;
        }
    }
}
void Pessoa::preOrdem()
{
    cout << "Dados: " << this->getNome() << " : " << this->getIdade() << endl;
    preOrdem(this->getFilhoEsquerdo());
    preOrdem(this->getFilhoDireito());
}

void Pessoa::preOrdem(Pessoa *inicio)
{
    if (inicio != NULL)
    {
        cout << "Dados: " << inicio->getNome() << " : " << inicio->getIdade() << endl;
        preOrdem(inicio->getFilhoEsquerdo());
        preOrdem(inicio->getFilhoDireito());
    }
}

void Pessoa::emOrdem()
{
    emOrdem(this->getFilhoEsquerdo());
    cout << "Dados: " << this->getNome() << " : " << this->getIdade() << endl;
    emOrdem(this->getFilhoDireito());
}

void Pessoa::emOrdem(Pessoa *inicio)
{
    if (inicio != NULL)
    {
        emOrdem(inicio->getFilhoEsquerdo());
        cout << "Dados: " << inicio->getNome() << " : " << inicio->getIdade() << endl;
        emOrdem(inicio->getFilhoDireito());
    }
}

void Pessoa::posOrdem()
{
    posOrdem(this->getFilhoEsquerdo());
    posOrdem(this->getFilhoDireito());
    cout << "Dados: " << this->getNome() << " : " << this->getIdade() << endl;
}

void Pessoa::posOrdem(Pessoa *inicio)
{
    if (inicio != NULL)
    {
        posOrdem(inicio->getFilhoEsquerdo());
        posOrdem(inicio->getFilhoDireito());
        cout << "Dados: " << inicio->getNome() << " : " << inicio->getIdade() << endl;
    }
}

void Pessoa::libMem(Pessoa *inicio)
{
    if (inicio != NULL)
    {
        libMem(inicio->getFilhoEsquerdo());
        libMem(inicio->getFilhoDireito());
        delete inicio;
    }
}

int main(int argc, char **argv)
{
    Pessoa *raiz = NULL;
    string nome;
    int i, idade;
    Pessoa *novo;
    for (i = 0; i < 6; i++)
    {
        novo = new Pessoa();
        cout << "Novo cadastro:" << endl;
        cout << "Nome: ";
        cin >> nome;
        novo->setNome(nome);
        cout << "Idade: ";
        cin >> idade;
        novo->setIdade(idade);
        if (raiz == NULL)
        {
            raiz = novo;
        }
        else
        {
            raiz->insereNovoElemento(novo);
        }
        cout << endl;
    }
    cout << "Caminho em PRE Ordem:" << endl;
    raiz->preOrdem();
    cout << endl
         << "Caminho em Ordem:" << endl;
    raiz->emOrdem();
    cout << endl
         << "Caminho em POS Ordem:" << endl;
    raiz->posOrdem();
    raiz->removerElemento(raiz, 50);
    cout << endl
         << "Caminho em PRE Ordem:" << endl;
    raiz->preOrdem();
    cout << endl
         << "Caminho em Ordem:" << endl;
    raiz->emOrdem();
    cout << endl
         << "Caminho em POS Ordem:" << endl;
    raiz->posOrdem();
    raiz->libMem(raiz);
    return 0;
}
