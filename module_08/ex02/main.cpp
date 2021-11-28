/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:16:47 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/28 16:17:19 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>
#include <stack>
#include <list>
#include <vector>

# define RESET			"\e[0m"
# define CYAN			"\e[0;36m"
# define PURPLE			"\e[0;38;5;93m"
# define LILAC			"\e[0;38;5;13m"

static void charListTest(void)
{
	std::cout << PURPLE << "\nCreating mstack" << RESET << std::endl;
	MutantStack<char, std::list<char> > mstack;
	if (mstack.empty())
		std::cout << PURPLE << "\nstack is empty\n" << RESET << std::endl;
	else
		std::cout << PURPLE << "stack is not empty" << RESET << std::endl;
	std::cout << LILAC << "pushing 'a' and 'b' to mutant stack\n" << RESET << std::endl;
	mstack.push('a');
	mstack.push('b');
	if (mstack.empty())
		std::cout << PURPLE << "\nstack is empty\n" << RESET << std::endl;
	else
		std::cout << PURPLE << "stack is not empty" << RESET << std::endl;
	std::cout << PURPLE << "\nTop element:" << RESET << std::endl;
	std::cout << mstack.top() << std::endl;
	std::cout << PURPLE << "\nStack size:" << RESET << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << LILAC << "\nPoping the stack" << RESET << std::endl;
	mstack.pop();
	std::cout << PURPLE << "\nStack size:" << RESET << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << LILAC << "\nPushing 'c', 'd', 'e' and '*' to the stack\n" << RESET << std::endl;
	mstack.push('c');
	mstack.push('d');
	mstack.push('e');
	mstack.push('*');
	MutantStack<char, std::list<char> >::iterator it = mstack.begin();
	MutantStack<char, std::list<char> >::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << PURPLE << "\nStack:" << RESET << std::endl;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::cout << LILAC << "\nPoping the stack" << RESET << std::endl;
	mstack.pop();
	std::cout << PURPLE << "\nStack:" << RESET << std::endl;
	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::cout << LILAC << "\nCopying the stack\n" << RESET << std::endl;
	MutantStack<char, std::list<char> > mstackCopy(mstack);
	MutantStack<char, std::list<char> >::iterator itCopy = mstackCopy.begin();
	MutantStack<char, std::list<char> >::iterator iteCopy = mstackCopy.end();
	++itCopy;
	--itCopy;
	std::cout << PURPLE << "\nCopyed stack:\n" << RESET << std::endl;
	while (itCopy != iteCopy)
	{
	std::cout << *itCopy << std::endl;
	++itCopy;
	}
	std::cout << LILAC << "\nPushing '!' to the original stack\n" << RESET << std::endl;
	mstack.push('!');
	it = mstack.begin();
	ite = mstack.end();
	std::cout << PURPLE << "\nOriginal stack:\n" << RESET << std::endl;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	itCopy = mstackCopy.begin();
	iteCopy = mstackCopy.end();
	std::cout << PURPLE << "\nCopy stack:\n" << RESET << std::endl;
	while (itCopy != iteCopy)
	{
	std::cout << *itCopy << std::endl;
	++itCopy;
	}
	std::cout << LILAC << "\nReverse iterators" << RESET << std::endl;
	MutantStack<char, std::list<char> >::reverse_iterator itCopyR = mstackCopy.rbegin();
	MutantStack<char, std::list<char> >::reverse_iterator iteCopyR = mstackCopy.rend();
	std::cout << PURPLE << "\nCopyed stack reverse:\n" << RESET << std::endl;
	while (itCopyR != iteCopyR)
	{
	std::cout << *itCopyR << std::endl;
	++itCopyR;
	}
}

static void floatVectorTest(void)
{
	std::cout << PURPLE << "\nCreating mstack" << RESET << std::endl;
	MutantStack<float, std::vector<float> > mstack;
	if (mstack.empty())
		std::cout << PURPLE << "\nstack is empty\n" << RESET << std::endl;
	else
		std::cout << PURPLE << "stack is not empty" << RESET << std::endl;
	std::cout << LILAC << "pushing 5.5 and 13.7 to mutant stack\n" << RESET << std::endl;
	mstack.push(5.5);
	mstack.push(13.7);
	if (mstack.empty())
		std::cout << PURPLE << "\nstack is empty\n" << RESET << std::endl;
	else
		std::cout << PURPLE << "stack is not empty" << RESET << std::endl;
	std::cout << PURPLE << "\nTop number:" << RESET << std::endl;
	std::cout << mstack.top() << std::endl;
	std::cout << PURPLE << "\nStack size:" << RESET << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << LILAC << "\nPoping the stack" << RESET << std::endl;
	mstack.pop();
	std::cout << PURPLE << "\nStack size:" << RESET << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << LILAC << "\nPushing 3.1, 5.2, 737.3 and 0.4 to the stack\n" << RESET << std::endl;
	mstack.push(3.1);
	mstack.push(5.2);
	mstack.push(737.3);
	mstack.push(0.4);
	MutantStack<float, std::vector<float> >::iterator it = mstack.begin();
	MutantStack<float, std::vector<float> >::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << PURPLE << "\nStack:" << RESET << std::endl;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::cout << LILAC << "\nPoping the stack" << RESET << std::endl;
	mstack.pop();
	std::cout << PURPLE << "\nStack:" << RESET << std::endl;
	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::cout << LILAC << "\nCopying the stack\n" << RESET << std::endl;
	MutantStack<float, std::vector<float> > mstackCopy(mstack);
	MutantStack<float, std::vector<float> >::iterator itCopy = mstackCopy.begin();
	MutantStack<float, std::vector<float> >::iterator iteCopy = mstackCopy.end();
	++itCopy;
	--itCopy;
	std::cout << PURPLE << "\nCopyed stack:\n" << RESET << std::endl;
	while (itCopy != iteCopy)
	{
	std::cout << *itCopy << std::endl;
	++itCopy;
	}
	std::cout << LILAC << "\nPushing 424242 to the original stack\n" << RESET << std::endl;
	mstack.push(424242);
	it = mstack.begin();
	ite = mstack.end();
	std::cout << PURPLE << "\nOriginal stack:\n" << RESET << std::endl;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	itCopy = mstackCopy.begin();
	iteCopy = mstackCopy.end();
	std::cout << PURPLE << "\nCopy stack:\n" << RESET << std::endl;
	while (itCopy != iteCopy)
	{
	std::cout << *itCopy << std::endl;
	++itCopy;
	}
	std::cout << LILAC << "\nReverse iterators" << RESET << std::endl;
	MutantStack<float, std::vector<float> >::reverse_iterator itCopyR = mstackCopy.rbegin();
	MutantStack<float, std::vector<float> >::reverse_iterator iteCopyR = mstackCopy.rend();
	std::cout << PURPLE << "\nCopyed stack reverse:\n" << RESET << std::endl;
	while (itCopyR != iteCopyR)
	{
	std::cout << *itCopyR << std::endl;
	++itCopyR;
	}
}

static void mainTests(void)
{
	std::cout << PURPLE << "\nCreating mstack" << RESET << std::endl;
	MutantStack<int> mstack;
	if (mstack.empty())
		std::cout << PURPLE << "\nstack is empty\n" << RESET << std::endl;
	else
		std::cout << PURPLE << "stack is not empty" << RESET << std::endl;
	std::cout << LILAC << "pushing 5 and 13 to mutant stack\n" << RESET << std::endl;
	mstack.push(5);
	mstack.push(13);
	if (mstack.empty())
		std::cout << PURPLE << "\nstack is empty\n" << RESET << std::endl;
	else
		std::cout << PURPLE << "stack is not empty" << RESET << std::endl;
	std::cout << PURPLE << "\nTop number:" << RESET << std::endl;
	std::cout << mstack.top() << std::endl;
	std::cout << PURPLE << "\nStack size:" << RESET << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << LILAC << "\nPoping the stack" << RESET << std::endl;
	mstack.pop();
	std::cout << PURPLE << "\nStack size:" << RESET << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << LILAC << "\nPushing 3, 5, 737 and 0 to the stack\n" << RESET << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << PURPLE << "\nStack:" << RESET << std::endl;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::cout << LILAC << "\nPoping the stack" << RESET << std::endl;
	mstack.pop();
	std::cout << PURPLE << "\nStack:" << RESET << std::endl;
	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::cout << LILAC << "\nCopying the stack\n" << RESET << std::endl;
	MutantStack<int> mstackCopy(mstack);
	MutantStack<int>::iterator itCopy = mstackCopy.begin();
	MutantStack<int>::iterator iteCopy = mstackCopy.end();
	++itCopy;
	--itCopy;
	std::cout << PURPLE << "\nCopyed stack:\n" << RESET << std::endl;
	while (itCopy != iteCopy)
	{
	std::cout << *itCopy << std::endl;
	++itCopy;
	}
	std::cout << LILAC << "\nPushing 424242 to the original stack\n" << RESET << std::endl;
	mstack.push(424242);
	it = mstack.begin();
	ite = mstack.end();
	std::cout << PURPLE << "\nOriginal stack:\n" << RESET << std::endl;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	itCopy = mstackCopy.begin();
	iteCopy = mstackCopy.end();
	std::cout << PURPLE << "\nCopy stack:\n" << RESET << std::endl;
	while (itCopy != iteCopy)
	{
	std::cout << *itCopy << std::endl;
	++itCopy;
	}
	std::cout << LILAC << "\nReverse iterators" << RESET << std::endl;
	MutantStack<int>::reverse_iterator itCopyR = mstackCopy.rbegin();
	MutantStack<int>::reverse_iterator iteCopyR = mstackCopy.rend();
	std::cout << PURPLE << "\nCopyed stack reverse:\n" << RESET << std::endl;
	while (itCopyR != iteCopyR)
	{
	std::cout << *itCopyR << std::endl;
	++itCopyR;
	}
	
}

int main()
{
	std::cout << CYAN << "\n----------INT DEFAULT(DEQUE) TEST----------\n" << RESET << std::endl;
	mainTests();
	std::cout << CYAN << "\n----------CHAR LIST TEST----------\n" << RESET << std::endl;
	charListTest();
	std::cout << CYAN << "\n----------FLOAT VECTOR TEST----------\n" << RESET << std::endl;
	floatVectorTest();
	return 0;
}
