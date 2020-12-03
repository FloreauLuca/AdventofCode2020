// Day1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>

int main()
{
    std::string str;
    std::vector<int> list;
    int i = 0;
    while (i != -1) {
        std::cin >> i;
        if (i != -1)
        {
            list.push_back(i);
        }
    }
    for (int i = 0; i < list.size(); ++i) {
        for (int j = i; j < list.size(); ++j) {
            for (int k = j; k < list.size(); ++k) {
                if (list[i] + list[j] + list[k] == 2020) {
                    std::cout << list[i] << std::endl;
                    std::cout << list[j] << std::endl;
                    std::cout << list[k] << std::endl;
                    std::cout << list[i] * list[j] * list[k] << std::endl;
                }
            }
        }
    }
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
