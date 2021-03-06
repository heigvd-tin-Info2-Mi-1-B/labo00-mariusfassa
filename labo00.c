/* HEIG-VD - INFO2 - L00 - labo00
 *
 * Auteur:      Marius Fassa
 * Fichier:     labo00.c
 * Compilateur: VS2019
 *
 * Description
 * Programme qui :
 * -Affiche le nombre d'arguments donn�s au programme.
 * -Affiche la liste des arguments donn�s au programme (un argument par ligne).
 * -Renvoie un code retour �gal au nombre d'arguments.
 *
 * Remarque(s)
 * 
 *
 * Modifications
 * Date         Auteur  Commentaires
 * 18.02.2020   FAM     Creation du programme
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

//taille max du tableau de char
#define MAX 200

int main(void)
{
    //declaration et initalisation des variables
    char chtab[MAX];
    uint32_t i, nbArguments;
    i = 0;
    nbArguments = 0;
    bool espDetect = true;

    //entree de la serie d'arguement par l'utilisateur,
    //stocke dans chtab
    //erreur si le gets() rentre plus de 200 char dans chtab
    gets(chtab);

    //compte le nombre d'arguments
    while (chtab[i] != '\0') 
    {
        //detect un espace, declenche un statut "espace a ete detecte"
        if (chtab[i] == ' ')
        {
            espDetect = true;
        }
        
        //si espace detecte et le caractere est graphique, ++ au compteur d'argument
        //et remise a false le statut "espace a ete detecte"
        if (espDetect == true && isgraph((int)chtab[i]) != 0)
        {
            nbArguments++;
            espDetect = false;
        }
        i++;
    }
    //affichage du nombre d'arguments
    printf("%d\n", nbArguments);

    //remise � l'etat initial de ces 2 variable pour reutilisation
    i = 0;
    espDetect = true;

    //ecrit un argument par ligne
    while (chtab[i] != '\0') 
    {
        //remise a la ligne lorsqu'un espace est detecte
        //evite plusieurs retour a la ligne si plusieurs espace a la suite
        if (chtab[i] == ' ' && espDetect == false)
        {
            espDetect = true;
            printf("\n");
        }

        if (isgraph((int)chtab[i]) != 0)
        {
            putchar((int)chtab[i]);
            espDetect = false;
        }
        i++;

    }

    printf("\n\n");
    system("PAUSE");

    return EXIT_SUCCESS;
}