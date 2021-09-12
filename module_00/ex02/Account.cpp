/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:22:01 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/12 00:17:51 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Account.hpp"
# include <iostream>
# include <ctime> //timestamp


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*
** STATIC
*/
int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}


int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}


int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}


int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}


void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << Account::getNbAccounts();
	std::cout << Account::getTotalAmount();
	std::cout << Account::getNbDeposits();
	std::cout << Account::getNbWithdrawals();
}


Account::Account( int initial_deposit )	:	_accountIndex(_nbAccounts),
											_amount(initial_deposit),
											_nbDeposits(0),
											_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_amount += this->_amount;
}


Account::~Account( void )
{
	Account::_nbAccounts--;
	Account::_amount -= this->_amount;
}


void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits++;
	this->_amount += deposit;
}


bool	Account::makeWithdrawal( int withdrawal )
{
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	return (true);
	//TODO false when withdrawal is not possible
}


int		Account::checkAmount( void ) const
{
	return (this->_amount);
}


void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << this->_accountIndex;
	std::cout << this->_amount;
	std::cout << this->_nbDeposits;
	std::cout << this->_nbWithdrawals;
}

/*
** PRIVATE
*/
void	Account::_displayTimestamp( void )
{
	std::time_t timestamp = std::time(0);

	std::cout << "[" << std::asctime(std::localtime(&timestamp))
	<< timestamp << "]" <<std::endl;
}

Account::Account(void)
{
	
}
