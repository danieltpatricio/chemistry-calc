#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int comp = 100;
    float aij[comp][comp], T[comp][comp], G[comp][comp], X[comp], deltaG1[comp][comp];
    float priparte[comp], segparte[comp], total[comp], resultado[comp];
    float temp;
    temp = 308.15;

    if (temp == 308.15)
    {
        deltaG1[0][0] = 0.00;
        deltaG1[0][1] = 927.63;
        deltaG1[0][2] = 1208.21;
        deltaG1[1][0] = -55.35;
        deltaG1[1][1] = 0.00;
        deltaG1[1][2] = 26.56;
        deltaG1[2][0] = 141.33;
        deltaG1[2][1] = 200.28;
        deltaG1[2][2] = 0.00;

        aij[0][0] = 0.0000;
        aij[0][1] = 0.2875;
        aij[0][2] = 0.2000;
        aij[1][0] = 0.2875;
        aij[1][1] = 0.0000;
        aij[1][2] = 0.3700;
        aij[2][0] = 0.2000;
        aij[2][1] = 0.3700;
        aij[2][2] = 0.0000;
    }

    cout << "Quantos componentes tem na mistura? ";
    cin >> comp;
    scanf("Quantos componentes tem na mistura? %d", &comp);

    for (int i = 0; i < comp; i++)
    {
        for (int j = 0; j < comp; j++)
        {
            T[i][j] = ((deltaG1[i][j]) / temp);
        }
    }
    for (int i = 0; i < comp; i++)
    {
        for (int j = 0; j < comp; j++)
        {
            priparte[i] = ((T[j][i] * G[j][i] * X[j]) / (G[j][i]) * X[j]);
        }
        for (int j = 0; j < comp; j++)
        {
            for (int l = 0; l < comp; l++)
            {
                segparte[i] = ((
                                   (X[j] * G[i][j]) /
                                   (G[l][j] * X[l])) +
                               ((T[i][j]) - (T[l][j] * G[l][j] * X[l]) / (G[l][j] * X[l])));
            }
        }
        total[i] = priparte[i] + segparte[i];
        resultado[i] = log(total[i]);
    }

    return 0;
}
