/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:25:16 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/16 19:01:03 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>

char	*readFile(long *size, std::ifstream *inputFile);
void	writeFile(char **argv, std::ofstream *outputFile, char *buffer, long size);

#endif
