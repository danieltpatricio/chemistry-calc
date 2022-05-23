#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int comp = 3;
    float aij[comp][comp], T[comp][comp], G[comp][comp], X[comp], deltaG1[comp][comp], lnGij[comp][comp];
    float priparte[comp], segparte[comp], pripartesup[comp], priparteinf[comp], total[comp], resultado[comp];
    float prisegpartesup[comp], prisegparteinf[comp], segsegpartesup[comp], segsegparte[comp], totalsegparte[comp];
    double temp = 308.15;

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

    cout << "Quantos componentes tem na mistura? ";
    cin >> comp;
    cout << "Temperatura: 308,15 K\n";

    cout << "Coloque as fra��es molares: \n";
    cout << "�gua: ";
    cin >> X[0];
    cout << "Propanol: ";
    cin >> X[1];
    cout << "Etil Acetato: ";
    cin >> X[2];

    // for(int i=0;i<3;i++)
    //   cout << fixed << setprecision(3) << X[i] << " ";

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
            lnGij[i][j] = -1 * aij[i][j] * T[i][j];
            G[i][j] = exp(lnGij[i][j]);
        }
    }

    cout << "PARA O PRIMEIRO ELEMENTO\n";
    for (int j = 0; j < comp; j++)
    {
        pripartesup[0] += T[j][0] * G[j][0] * X[j];
        priparteinf[0] += G[j][0] * X[j];
    }

    priparte[0] = pripartesup[0] / priparteinf[0];
    //  cout << pripartesup[0] << "       " << priparteinf[0] << endl;

    // cout << priparte[0] << endl;

    for (int j = 0; j < comp; j++)
    {
        prisegpartesup[0] = X[j] * G[0][j];
        for (int l = 0; l < comp; l++)
        {
            prisegparteinf[0] += X[l] * G[l][j];
            segsegpartesup[0] += T[l][j] * G[l][j] * X[l];
        }
        segparte[j] = ((prisegpartesup[0] / prisegparteinf[0]) * (T[0][j] - (segsegpartesup[0] / prisegparteinf[0])));
        totalsegparte[0] += segparte[j];
        cout << totalsegparte[0] << "     ";
    }
    cout << endl;
    cout << priparte[0] << endl;
    total[0] = priparte[0] + totalsegparte[0];
    cout << total[0] << endl;
    resultado[0] = exp(total[0]);
    cout << resultado[0] << endl;
    /*    cout << "PARA O SEGUNDO ELEMENTO\n";
            for(int j=0;j<comp;j++){
                pripartesup[1] += T[j][1]*G[j][1]*X[j];
                priparteinf[1] += G[j][1]*X[j];
        }
        priparte[1] = pripartesup[1] / priparteinf[0];

        cout << "PARA O TERCEIRO ELEMENTO\n";
            for(int j=0;j<comp;j++){
                pripartesup[2] += T[j][2]*G[j][2]*X[j];
                priparteinf[2] += G[j][2]*X[j];
        }
    */
    return 0;
}
