//Aluno: Luiz Gustavo Klitzke

#include <stdio.h>

#define MAX_N 50

long n, x, y;

struct Ponto
{
    long x = 0;
    long y = 0;
};

Ponto aPontos[MAX_N];

//Zero = Colineares | Positivo = Curva pra Esquera | Negativo = Curva pra direita
long CalculaProdutoVetorial(const Ponto& p1, const Ponto& p2, const Ponto& p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) - 
           (p2.y - p1.y) * (p3.x - p1.x);
}

int main()
{
    while (scanf("%d", &n) && n)
    {
        for (long idxEntrada = 0; idxEntrada < n; ++idxEntrada)
        {
            Ponto& regPonto = aPontos[idxEntrada];
            scanf("%d %d", &regPonto.x, &regPonto.y);
        }

        bool bTemPontoCritico = false;
        const long lPrimeiroProdutoVetorial = CalculaProdutoVetorial(aPontos[0], aPontos[1], aPontos[2]);

        for (long idxPonto = 1; idxPonto < n; ++idxPonto)
        {
            const Ponto& p1 = aPontos[idxPonto];
            const Ponto& p2 = aPontos[(idxPonto + 1) % n];
            const Ponto& p3 = aPontos[(idxPonto + 2) % n];

            const long lProduto = CalculaProdutoVetorial(p1, p2, p3);

            if (lPrimeiroProdutoVetorial >= 0 && lProduto < 0 ||
                lPrimeiroProdutoVetorial < 0  && lProduto > 0)
            {
                bTemPontoCritico = true;
                break;
            }
        }

        if (bTemPontoCritico)
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}