#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout<<"I love having extra bacon for my 7XL-double-cheese burger. I really do!"
            <<std::endl;
}

void Harl::info(void)
{
    std::cout<<"I cannot believe adding extra bacon costs more money."
            <<std::endl;
}

void Harl::warning(void){
    std::cout<<"I think I deserve to have some extra bacon for free."
            <<std::endl;
}

void Harl::error(void){
    std::cout<<"This is unacceptable! I want to speak to the manager now."
            <<std::endl;
}

void Harl::complain(std::string level)
{
    std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*function[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int stage = -1;
	for (int i = 0; i < 4; i++)
	{
		if (options[i] == level){
			stage = i;
			break;
		}
	}

   switch(stage)
   {
	   	default:
	   		std::cerr<<"[ Probably complaining about insignificant problems ]"<<std::endl;
			break;
		case 0:
			std::cout<<"[ "<<options[0]<<" ]"<<std::endl;
			(this->*function[0])();
		case 1:
			std::cout<<"[ "<<options[1]<<" ]"<<std::endl;
			(this->*function[1])();
		case 2:
			std::cout<<"[ "<<options[2]<<" ]"<<std::endl;
			(this->*function[2])();
		case 3:
			std::cout<<"[ "<<options[3]<<" ]"<<std::endl;
			(this->*function[3])();
   }
}
