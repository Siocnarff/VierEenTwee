#include "HumanResources.h"

#include <utility>
#include <random>

using namespace ppl;

Person* HumanResources::hire(std::string job) {
	return source(std::move(job));
}

std::string HumanResources::randomName() {
    std::string names[50] = {"Dani Dabbs",
                           "Jennell Julia",
                           "Corazon Croteau",
                           "Lorita Lindsey",
                           "Vanda Veras",
                           "Stephenie Soller",
                           "Natividad Nichol",
                           "Alvin Adamek",
                           "Lanora Lafon",
                           "Leona Langdon",
                           "Merri Milner",
                           "Earlean Ellingwood",
                           "Mei Mounsey",
                           "Shawnda Stickel",
                           "Else Elfrink",
                           "Kena Kopecky",
                           "Merrill Mizrahi",
                           "Felice Flanary",
                           "Elfreda Ellison",
                           "Arlie Arline",
                           "Karoline Kott",
                           "Hilton Hashimoto",
                           "Norene Norman",
                           "Tiera Turpen",
                           "Charmaine Cordova",
                           "Dahlia Depaz",
                           "Shanda Sama",
                           "Deedra Digiacomo",
                           "Natalya Nathaniel",
                           "Nikole Narvaez",
                           "Josefine Jonson",
                           "Malissa Monaco",
                           "Vida Vannatter",
                           "Mollie Masterson",
                           "Hiroko Howson",
                           "Caren Courtney",
                           "Elenor Edmund",
                           "Mitzi Mangels",
                           "Gaylord Gannaway",
                           "Johnathon Justus",
                           "Ericka Eckler",
                           "Newton Nicely",
                           "Kati Kinnan",
                           "Cesar Charron",
                           "Sharolyn Skowron",
                           "Belen Burbach",
                           "Rosalva Rosenblum",
                           "Jarod Jiron",
                           "Courtney Coursey",
                           "Ali Andrus"};
    return names[int(rand() % 50)];
}

HumanResources::HumanResources() = default;
