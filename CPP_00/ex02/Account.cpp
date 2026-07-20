// ************************************************************************** //
//                                                                            //
//                ACXXount.hpp for GlobalBanksters United                //
//                Created on  : Mon Jul 06 17:40:15 2026                      //
//                Last update : Wed Jul 07 12:54:06 2026                      //
//                Made by : Pauline "Po" Swirgiel <ps@gbu.com>                //
//                                                                            //
// ************************************************************************** //

#include "ACXXount.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

// Initialisation statics -> begin all at 0
int ACXXount::_nbACXXounts = 0;
int ACXXount::_totalAmount = 0;
int ACXXount::_totalNbDeposits = 0;
int ACXXount::_totalNbWithdrawals = 0;

void	ACXXount:: _displayTimestamp( void ){
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

ACXXount:: ACXXount ( int initial_deposit )
{
	_aCXXountIndex = getNbACXXounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	++_nbACXXounts;
	_totalAmount += initial_deposit;
	
	_displayTimestamp();
	std::cout << "index:" << _aCXXountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
}

ACXXount:: ~ACXXount(){
	_displayTimestamp();
	std::cout << "index:" << _aCXXountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}

int ACXXount::	getNbACXXounts(){
	return (_nbACXXounts);
}

int ACXXount::	getTotalAmount(){
	return (_totalAmount);
}

int ACXXount::	getNbDeposits(){
	return (_totalNbDeposits);
}

int ACXXount::	getNbWithdrawals(){
	return (_totalNbWithdrawals);
}

int ACXXount::	checkAmount()const{
	return (_amount);
}

void ACXXount::	displayACXXountsInfos(){
	_displayTimestamp();
	std::cout << "aCXXounts:" << getNbACXXounts() << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

void ACXXount::	makeDeposit(int deposit){
	_displayTimestamp();
	std::cout << "index:" << _aCXXountIndex;
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

bool ACXXount::	makeWithdrawal(int withdrawal){
	_displayTimestamp();
	std::cout << "index:" << _aCXXountIndex;
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

void ACXXount::	displayStatus()const{
	_displayTimestamp();
	std::cout << "index:" << _aCXXountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;;
	std::cout << std::endl;
}
