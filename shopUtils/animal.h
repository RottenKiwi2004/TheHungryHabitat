#ifndef animal_h
#define animal_h

#include "animalSpecies.h"

class Animal
{
private:
    std::string species;
    std::string getSpeciesString(enum AnimalSpecies);

public:
    Animal(enum AnimalSpecies);
    Animal();
    std::string getSpecies();
};

Animal::Animal(enum AnimalSpecies species)
{
    this->species = this->getSpeciesString(species);
}

Animal::Animal()
{
    this->species = "UnknownSpecies";
}

std::string Animal::getSpeciesString(enum AnimalSpecies species)
{
    switch (species)
    {
    case FallowDeer:
        return "FallowDeer";
    case TasmanianDevil:
        return "TasmanianDevil";
    case Koala:
        return "Koala";
    case Dingo:
        return "Dingo";
    case RedDeer:
        return "RedDeer";
    case Emu:
        return "Emu";
    case EuropeanRabbit:
        return "EuropeanRabbit";
    case GreenSeaTurtle:
        return "GreenSeaTurtle";
    case Mulgara:
        return "Mulgara";
    case Platypus:
        return "Platypus";
    case WanderingAlbatross:
        return "WanderingAlbatross";
    case ShortBeakeEchidna:
        return "ShortBeakeEchidna";
    case SaltwaterCrocodile:
        return "SaltwaterCrocodile";
    case SpinnerDolphin:
        return "SpinnerDolphin";
    case BlackFlyingFox:
        return "BlackFlyingFox";
    case Kangaroo:
        return "Kangaroo";
    case PlaShaDoAustralia:
        return "PlaShaDoAustralia";
    case UnknownSpecies:
    default:
        return "UnknownSpecies";
    }
}

std::string Animal::getSpecies()
{
    return this->species;
}
#endif
