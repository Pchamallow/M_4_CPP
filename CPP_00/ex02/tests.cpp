// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"
#include <iostream>


// int	main()
// {
	
// 	Account::displayAccountsInfos(); 
// }

int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;
	// = typedef std::vector<Account> accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );

	//Phase 1 : print creation
// utilise le vector Account -> amounts = begin, amounts + amounts_size (end + 1, exclus le end + 1)
// creer un array d amount avec chacun les valeurs données par amounts[]
	std::cout << "Phase 1" << std::endl;
	accounts_t				accounts( amounts, amounts + amounts_size );

	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	(void)accounts;

	// Phase 2 :
	std::cout << "Phase 2" << std::endl;
	Account::displayAccountsInfos();

	// // Phase 3 : amount, nb de deposit, nb withdrawals
	std::cout << "Phase 3" << std::endl;
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// // Phase 4 : amount avant deposit, montant deposit, 
	std::cout << "Phase 4" << std::endl;
	// // amount post deposit, nb deposit
	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	// // Phase 5 :
	std::cout << "Phase 5" << std::endl;
	Account::displayAccountsInfos();

	// // Phase 6 : amount, nb de deposit, nb withdrawals
	std::cout << "Phase 6" << std::endl;
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// // Phase 7 : amount avant withdrawal, montant withdrawal, 
	// // refused ou amount post withdrawal, nb withdrawal
	std::cout << "Phase 7" << std::endl;
	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	// // Phase 8 : total account, total amount de tous les accounts,
	// // total nb deposits, total nb withdrawals
	std::cout << "Phase 8" << std::endl;
	Account::displayAccountsInfos();

	// // Phase 9 : amount, nb de deposit, nb withdrawals
	std::cout << "Phase 9" << std::endl;
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// // Phase 10 : destructeur qui print
	std::cout << "Phase 10" << std::endl;
	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
