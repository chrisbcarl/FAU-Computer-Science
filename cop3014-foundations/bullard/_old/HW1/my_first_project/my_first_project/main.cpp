#include "my_first_project.h"
#include "namespace1.h"
#include "namespace2.h"
#include "namespace3.h"
#include "chris_carl_library.h"

int main()
{
	print_string("my_first_project.cpp output:");
	my_first_project();
	print_string("namespace1.cpp output:");
	namespace1();
	print_string("namespace2.cpp output:");
	namespace2();
	print_string("namespace3.cpp output:");
	namespace3();
	exit();
	return 0;
}