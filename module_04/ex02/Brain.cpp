/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:17:57 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 18:54:02 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <cstdlib>
#include "Brain.hpp"

# define V_BLUE			"\e[0;38;5;27m"

std::string Brain::_rawIdeas[100] = {
	"A dog is the only thing on earth that loves you more than you love yourself.",
	"Animals are such agreeable friends—they ask no questions; they pass no criticisms.",
	"If having a soul means being able to feel love and loyalty and gratitude, then animals are better off than a lot of humans.",
	"There are two means of refuge from the miseries of life: music and cats.",
	"I used to love dogs until I discovered cats.",
	"One cat just leads to another.",
	"The smallest feline is a masterpiece.",
	"A cat will be your friend, but never your slave.",
	"As every cat owner knows, nobody owns a cat.",
	"If cats could talk, they wouldn’t.",
	"let's play!",
	"let's sleep!",
	"feed me, human",
	"What if I was human?",
	"You cannot look at a sleeping cat and feel tense.",
	"Time spent with cats is never wasted.",
	"There is no psychiatrist in the world like a puppy licking your face.",
	"You know, a dog can snap you out of any kind of bad mood that you’re in faster than you can think of.",
	"Pets understand humans better than humans do.",
	"Pets reflect you like mirrors. When you are happy, you can see your dog smiling and when you are sad, your cat cries.",
	"Those who love dogs, know something about God.",
	"You do not own a dog. You have a dog. And the dog has you.",
	"In ancient times cats were worshipped as gods; they have not forgotten this.",
	"Dogs and angels are not very far apart.",
	"Dogs motivate humans to play, be affectionate, seek adventure, and be loyal.",
	"If your dog doesn’t like someone, you probably shouldn’t either.",
	"Dog is God spelled backward.",
	"Home is where the dog runs to greet you.",
	"Cats are inquisitive but hate to admit it.",
	"Cats have it all – admiration, an endless sleep, and company only when they want it.",
	"A dog desires affection more than its dinner. Well—almost.",
	"A dog is the only thing on earth that loves you more than you love yourself.",
	"Animals are such agreeable friends—they ask no questions; they pass no criticisms.",
	"If having a soul means being able to feel love and loyalty and gratitude, then animals are better off than a lot of humans.",
	"There are two means of refuge from the miseries of life: music and cats.",
	"I used to love dogs until I discovered cats.",
	"One cat just leads to another.",
	"The smallest feline is a masterpiece.",
	"A cat will be your friend, but never your slave.",
	"As every cat owner knows, nobody owns a cat.",
	"If cats could talk, they wouldn’t.",
	"let's play!",
	"let's sleep!",
	"feed me, human",
	"What if I was human?",
	"You cannot look at a sleeping cat and feel tense.",
	"Time spent with cats is never wasted.",
	"There is no psychiatrist in the world like a puppy licking your face.",
	"You know, a dog can snap you out of any kind of bad mood that you’re in faster than you can think of.",
	"Pets understand humans better than humans do.",
	"Pets reflect you like mirrors. When you are happy, you can see your dog smiling and when you are sad, your cat cries.",
	"Those who love dogs, know something about God.",
	"You do not own a dog. You have a dog. And the dog has you.",
	"In ancient times cats were worshipped as gods; they have not forgotten this.",
	"Dogs and angels are not very far apart.",
	"Dogs motivate humans to play, be affectionate, seek adventure, and be loyal.",
	"If your dog doesn’t like someone, you probably shouldn’t either.",
	"Dog is God spelled backward.",
	"Home is where the dog runs to greet you.",
	"Cats are inquisitive but hate to admit it.",
	"Cats have it all – admiration, an endless sleep, and company only when they want it.",
	"A dog desires affection more than its dinner. Well—almost.",
	"A dog is the only thing on earth that loves you more than you love yourself.",
	"Animals are such agreeable friends—they ask no questions; they pass no criticisms.",
	"If having a soul means being able to feel love and loyalty and gratitude, then animals are better off than a lot of humans.",
	"There are two means of refuge from the miseries of life: music and cats.",
	"I used to love dogs until I discovered cats.",
	"One cat just leads to another.",
	"The smallest feline is a masterpiece.",
	"A cat will be your friend, but never your slave.",
	"As every cat owner knows, nobody owns a cat.",
	"If cats could talk, they wouldn’t.",
	"let's play!",
	"let's sleep!",
	"feed me, human",
	"What if I was human?",
	"You cannot look at a sleeping cat and feel tense.",
	"Time spent with cats is never wasted.",
	"There is no psychiatrist in the world like a puppy licking your face.",
	"You know, a dog can snap you out of any kind of bad mood that you’re in faster than you can think of.",
	"Pets understand humans better than humans do.",
	"Pets reflect you like mirrors. When you are happy, you can see your dog smiling and when you are sad, your cat cries.",
	"Those who love dogs, know something about God.",
	"You do not own a dog. You have a dog. And the dog has you.",
	"In ancient times cats were worshipped as gods; they have not forgotten this.",
	"Dogs and angels are not very far apart.",
	"Dogs motivate humans to play, be affectionate, seek adventure, and be loyal.",
	"If your dog doesn’t like someone, you probably shouldn’t either.",
	"Dog is God spelled backward.",
	"Home is where the dog runs to greet you.",
	"Cats are inquisitive but hate to admit it.",
	"Cats have it all – admiration, an endless sleep, and company only when they want it.",
	"A dog desires affection more than its dinner. Well—almost.",
	"As every cat owner knows, nobody owns a cat.",
	"If cats could talk, they wouldn’t.",
	"let's play!",
	"let's sleep!",
	"feed me, human",
	"What if I was human?",
	"You cannot look at a sleeping cat and feel tense.",
};

Brain::Brain(void)
{
	std::srand((unsigned int)time(NULL));
	for(int i = 0; i < 100; i++)
		this->ideas[i] = Brain::_rawIdeas[rand() % 100];
	std::cout << V_BLUE << "New brain is here, ready to fill you with the greatest ideas!" << std::endl;
	return;
}

Brain::Brain(Brain const& instance)
{
	*this = instance;
	std::cout << V_BLUE << "New brain duplicated with the greatest ideas!" << std::endl;
	return ;
}

Brain::~Brain(void)
{
	std::cout << V_BLUE << "Is the end of this brain, my friends" << std::endl;
	return;
}

void Brain::operator=(Brain const &right_hand_side)
{
	for(int i = 0; i < 100; i++)
		this->ideas[i] = right_hand_side.ideas[i];
	return ;
}
