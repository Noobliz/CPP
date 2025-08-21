/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisux <lisux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:52:17 by lguiet            #+#    #+#             */
/*   Updated: 2025/05/23 14:50:28 by lisux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";created" <<std::endl;

}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";closed" << std::endl;
}


void    Account::_displayTimestamp( void )
{
    time_t    time = std::time(NULL);
    char    time_fmt[19];

    std::strftime(time_fmt, 19, "[%Y%m%d_%H%M%S] ", std::gmtime(&time));
    std::cout << time_fmt;
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals << std::endl;

}

void Account::makeDeposit(int deposit)
{
	if (deposit <= 0){
		std::cerr<<"index:"<<_accountIndex<<" deposit should be superior to 0"<<std::endl;
		return ;
	}
	int p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";p_amount:" << p_amount
				<< ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal <= 0){
		std::cerr<<"index:"<<_accountIndex<<" withdrawal should be superior to 0"<<std::endl;
		return false;
	}
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:refused"
				<< std::endl;
		return false;
	}
	int p_amount = _amount;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals
			<< std::endl;
	return true;
}