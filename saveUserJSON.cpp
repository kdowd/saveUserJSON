
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using namespace std;
using namespace nlohmann;

// test json data:  https://jsonplaceholder.typicode.com/users
// video: https://www.youtube.com/watch?v=NuWQp_uAvwo


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


	vector<RelatedMovie> RelatedMovies{
		{"Rogue One", 2016}, {"Dune", 2021} };

	json UserDataAsJSON{
		{"movie", "Star Wars"},
		{"released", true},
		{"year", 1977},
		{"cast", Cast},
		{"director", Director},
		{"related_movies", RelatedMovies}
	};

	//std::cout << UserDataAsJSON.dump(4);

	ofstream myfile;
	myfile.open("example.txt");
	myfile << UserDataAsJSON;
	myfile.close();

	system("pause");
	return 0;
}







