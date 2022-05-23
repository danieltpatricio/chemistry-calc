#include <iostream>
#include <math.h>
#include <stdio.h>
#include "fort.h"

using namespace std;


int main() {
  setlocale(LC_ALL, "");
  string COMP[3] = { "Agua", "Propanol", "Etil Acetato" };
  int COMP_LEN = (sizeof(COMP)/sizeof(*COMP));
  float aij[COMP_LEN][COMP_LEN], T[COMP_LEN][COMP_LEN], G[COMP_LEN][COMP_LEN], X[COMP_LEN], deltaG1[COMP_LEN][COMP_LEN];
  float temp = 308.15;
  float result = 0;
  float comp_fm [] = {0.0, 0.0, 0.0};
  ft_table_t *table = ft_create_table();
  /* Set "header" type for the first row */
  ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);

  ft_write_ln(table, "N", "Driver", "Time", "Avg Speed");

  ft_write_ln(table, "1", "Ricciardo", "1:25.945", "222.128");
  ft_write_ln(table, "2", "Hamilton", "1:26.373", "221.027");
  ft_write_ln(table, "3", "Verstappen", "1:26.469", "220.782");

  printf("%s\n", ft_to_string(table));
  ft_destroy_table(table);

  if (temp == 308.15) {
    deltaG1[0][0] = 0.00;
    deltaG1[0][1] = 927.63;
    deltaG1[0][2] = 927.63;
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

  for (int i = 0; i < COMP_LEN; i++) {
    cout << "Qual é a fração molar da(o) " << COMP[i] << "? ";
    scanf("%f", &comp_fm[i]);
    cout << comp_fm[i] << "\n";
  }

  for (int i = 0; i <= COMP_LEN; i++) {
    for (int j = 0; j <= COMP_LEN; j++) {
      result = (comp_fm[j] * T[i][j] * G[i][j]) + (comp_fm[j] * T[i][j] * G[i][j]) + (comp_fm[j] * T[i][j] * G[i][j]);
      cout << "Resultado de [i][j]: " << result << "\n";
    }
  }

  return 0;
}
