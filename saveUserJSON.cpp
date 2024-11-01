
#include <iostream>
#include <fstream>
#include <random>
#include "nlohmann/json.hpp"

using namespace std;
using namespace nlohmann;

string getMessage();


struct Person {
	std::string name;
	int born;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Person, name, born)

struct RelatedMovie {
	std::string name;
	int year;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(RelatedMovie, name, year)

int main() {
	Person Director{ "George Lucas", 1944 };
	vector<string> Cast{ "Mark Hamill", "Harrison Ford","Carrie Fisher" };
	Cast.push_back("KJ Dowd");


	vector<RelatedMovie> RelatedMovies{ {"Rogue One", 2016}, {"Dune", 2021} };
	RelatedMovies.push_back({ "Blade Runner", 1996 });

	json UserDataAsJSON{
		{"movie", "Star Wars"},
		{"released", true},
		{"year", 1977},
		{"cast", Cast},
		{"director", Director},
		{"related_movies", RelatedMovies},
		{"message", getMessage()}
	};

	//std::cout << UserDataAsJSON.dump(4);

	ofstream myfile;

	// make random file name


	// stronger random
	random_device strongerRand;
	string numToStringRandom = to_string(strongerRand());

	string fileName = "user_";
	fileName.append(numToStringRandom).append(".txt");

	myfile.open(fileName);
	myfile << UserDataAsJSON;
	myfile.close();

	return 0;
}


string getMessage() {
	return "Hello World";
}











