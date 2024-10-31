
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

	system("pause");
	return 0;
}







