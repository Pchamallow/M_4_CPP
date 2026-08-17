// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Mon Jul 06 17:40:15 2026                      //
//                Last update : Wed Jul 07 12:54:06 2026                      //
//                Made by : Pauline "Po" Swirgiel <ps@gbu.com>                //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

// Initialisation statics -> begin all at 0
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account:: _displayTimestamp( void ){
	time_t timeNow = time(0);
	tm *date = localtime(&timeNow);
	int year = date->tm_year + 1900;
	int month = date->tm_mon + 1;
	int day = date->tm_mday;
	int hour = date->tm_hour;
	int min = date->tm_min;
	int sec = date->tm_sec;

	std::cout << "[" << year;
	std::cout << std::setfill('0');
	std::cout << std::setw(2) << month << std::setw(2) << day;
	std::cout << "_" << std::setw(2) << hour;
	std::cout << std::setw(2) << min;
	std::cout << std::setw(2) << sec;
	std::cout << "] ";
}

Account:: Account ( int initial_deposit )
{
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	++_nbAccounts;
	_totalAmount += initial_deposit;
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
}

Account:: ~Account(){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}

int Account::	getNbAccounts(){
	return (_nbAccounts);
}

int Account::	getTotalAmount(){
	return (_totalAmount);
}

int Account::	getNbDeposits(){
	return (_totalNbDeposits);
}

int Account::	getNbWithdrawals(){
	return (_totalNbWithdrawals);
}

int Account::	checkAmount()const{
	return (_amount);
}

void Account::	displayAccountsInfos(){
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

void Account::	makeDeposit(int deposit){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	_amount += deposit;
	++_nbDeposits;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
	++_totalNbDeposits;
	_totalAmount += deposit;
}

bool Account::	makeWithdrawal(int withdrawal){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (_amount < withdrawal){
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	++_nbWithdrawals;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	++_totalNbWithdrawals;
	_totalAmount -= withdrawal;
	return (true);
}

void Account::	displayStatus()const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;;
	std::cout << std::endl;
}
