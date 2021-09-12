/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:22:01 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/12 02:04:22 by phemsi-a         ###   ########.fr       */
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
	std::cout	<< "accounts:"
				<< Account::getNbAccounts()
				<< ";total:"
				<< Account::getTotalAmount()
				<< ";deposits:"
				<< Account::getNbDeposits()
				<< ";withdrawals:"
				<< Account::getNbWithdrawals()
				<< std::endl;
}


Account::Account( int initial_deposit )	:	_accountIndex(_nbAccounts),
											_amount(initial_deposit),
											_nbDeposits(0),
											_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;

	_displayTimestamp();
	std::cout	<< "index:"
				<< this->_accountIndex
				<< ";amount:"
				<< this->_amount
				<< ";created"
				<< std::endl;
}


Account::~Account( void )
{
	_displayTimestamp();
	std::cout	<< "index:"
				<< this->_accountIndex
				<< ";amount:"
				<< this->_amount
				<< ";closed"
				<< std::endl;
	Account::_nbAccounts--;
	Account::_amount -= this->_amount;
}


void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	_displayTimestamp();
	std::cout	<<"index:"
				<< this->_accountIndex
				<< ";p_amount:"
				<< this->_amount - deposit
				<< ";deposit:"
				<< deposit
				<< ";amount:"
				<< this->_amount
				<< ";nb_deposits:"
				<< this->_nbDeposits
				<< std::endl;
}


bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout	<<"index:"
				<< this->_accountIndex
				<< ";p_amount:"
				<< this->_amount;
	if (this->_amount >= withdrawal)
	{
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout	<< ";withdrawal:"
					<< withdrawal
					<< ";amount:"
					<< this->_amount
					<< ";nb_withdrawals:"
					<< this->_nbWithdrawals
					<< std::endl;
		return (true);
	}
	std::cout	<< ";withdrawal:refused"
				<< std::endl;
	return (false);
}


int		Account::checkAmount( void ) const
{
	return (this->_amount);
}


void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<<"index:"
				<< this->_accountIndex
				<< ";amount:"
				<< this->_amount
				<< ";deposits:"
				<< this->_nbDeposits
				<< ";withdrawals:"
				<< this->_nbWithdrawals
				<< std::endl;
}

/*
** PRIVATE
*/
void	Account::_displayTimestamp( void )
{
	std::time_t timestamp = std::time(0);

	std::cout << "[" << std::localtime(&timestamp)
	<< timestamp << "]";
}

Account::Account(void)
{
	
}
