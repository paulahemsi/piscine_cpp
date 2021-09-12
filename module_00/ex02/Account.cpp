/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:22:01 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/11 23:08:55 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Account.hpp"
# include <iostream>
# include <ctime> //timestamp

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


Account::Account( int initial_deposit )
{
	
}


Account::~Account( void )
{
	
}


void	Account::makeDeposit( int deposit )
{
	
}


bool	Account::makeWithdrawal( int withdrawal )
{
	
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
	std::time_t timestamp = std::time(nullptr);

	std::cout << "[" << std::asctime(std::localtime(&timestamp))
	<< timestamp << "]" <<std::endl;
}

Account::Account(void)
{
	
}
