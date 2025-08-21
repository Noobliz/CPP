/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:41:38 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/21 15:13:18 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout<<"string adress: "<<&string<<std::endl;
    std::cout<<"ptdr points to adress: "<<stringPTR<<std::endl; // OR ADDRESS OF PTR??
    std::cout<<"ref adress: "<<&stringREF<<std::endl;

    std::cout<<"string content: "<<string<<std::endl;
    std::cout<<"ptdr points to value: "<<*stringPTR<<std::endl;
    std::cout<<"ref to string: "<<stringREF<<std::endl;

    return (0);
}