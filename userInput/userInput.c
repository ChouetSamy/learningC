#include <stdio.h>

int main()
{
  int userInput;//délcaration de variable en C, on précise le type
  //ici le type est un entier
  printf("veuillez choisir un nombre entier\n");
  scanf("%d",&userInput);
  //on prend un double en entrée pour simplifié l'input de l'user
  //on utilise & pour pointer vers l'addresse mémoire de userInput car
  //le type n'est pas le même
  printf("%d", userInput);//on ressort un double
  return 0;
}