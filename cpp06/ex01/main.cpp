#include "Serializer.hpp"
#include "Data.hpp"


int main()
{
	Data data = {"bob", 52};
	Data *test;
	
	std::cout<< "before serialization:\nData age: " <<data.age<<"\nData name: "<<data.name<<std::endl;

	uintptr_t lol = Serializer::serialize(&data);
	test = Serializer::deserialize(lol);

	std::cout<<"after serialization/deserialization:\nData age: "<<test->age<<"\nData name: "<<test->name<<std::endl;

}