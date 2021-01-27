/**
 * Calcule le total d'une facture
 *
 * @file exemple_fonctionnel.cpp
 *
 * @brief calcul de facture en prog fonctionnelle
 *
 * @author Frédérik Taleb
 * Contact: taleb.frederik@carrefour.cegepvicto.ca
 *
 */

#include <iostream>


float calculTaxe(float prix)
{
	float prixAvecMonnaie(prix * 100);
	float prixArrondi(std::round(prixAvecMonnaie));
	return prixArrondi / 100;
}

float calculSousTotal(int indexItem, float tabPrixItems[], int nbItems)
{
	if (indexItem < nbItems)
	{
		float prix = tabPrixItems[indexItem];
		float sousTotal = calculSousTotal(++indexItem, tabPrixItems, nbItems);
 		return prix + sousTotal;
	}
	else
	{
		return 0.0f;
	}
}

float calculTotal(float tabPrixItems[], int nbItems)
{
	return calculTaxe(calculSousTotal(0, tabPrixItems, nbItems));
}

void afficheTotal(float tabPrixItems[], int nbItems)
{
	std::cout << "Votre total: " << calculTotal(tabPrixItems, nbItems) << "$";
}

int main()
{
	float tabPrixItems[]{ 3.95f, 15.05f, 10.00f };

	afficheTotal(tabPrixItems, std::size(tabPrixItems));
}
