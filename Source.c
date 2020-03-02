#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

const double RAND_MAX_F = RAND_MAX;
double get_rand() 
{
  return rand() / RAND_MAX_F;
}  
//------------------------------------------------------------------
double get_rand_range(const double min, const double max) 
{
  return get_rand() * (max - min) + min;
}
//------------------------------------------------------------------
int Kol(int n)
{
  int i = 0;

  while (n > 0){
    n = n / 10;
    i++;
  }
  return i;
}
//------------------------------------------------------------------
int Signed(double x, int n,int k)
{

  int tek;
  double drob;
  drob = trunc((x - trunc(x))*pow(10, k));
  tek = (int)drob;
  tek = abs(tek);
  if (tek< n)
  {
    return tek;
  }
  else
  {
    return -1;
  }
}
//------------------------------------------------------------------
int main(int argc, char*argv[])
{
  if (argc != 4)
  {
    printf("Warning");
    return 1;
  }
  srand(time(NULL));

  int n;//колличество чисел
  int i, k;// индекс счетчика и колличество цифр в n
  double min, max;// лева€ и права€ границы области в которой генерируетс€ числа
  double  Res; //  переменна€ хран€ща€ результат
  double*Array;// указатель на динамический массив
  Res = 0;

  n = atoi(argv[1]);
  min = atof(argv[2]);
  max = atof(argv[3]);
  k = Kol(n);
  Array = (double*)malloc(n*sizeof(double));
  /*==========================================*/
  for (i = 0; i < n; i++)
  {
    Array[i] = get_rand_range(min, max);
    printf("%i %lf\n",i, Array[i]);
  }
  /*==========================================*/
  for (i = 0; i < n; i++)
  {
    int num;//номер получаемый из дробной части элемента
    num = Signed(Array[i], n, k);
    if (num != -1)
    { 
      Res = Res - Array[num];
      Array[num] = 0;
    }
  }
  /*============================================*/
  for (i = 0; i < n; i++)
  {
    Res = Res + Array[i];
  }
  printf("%lf", Res);
  return 0;
}