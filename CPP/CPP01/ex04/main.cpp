/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by kelle             #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>   // std::cout, std::cerr and std::endl for messages and errors
#include <fstream>    // std::ifstream (read a file) and std::ofstream (write a file), C++ streams
#include <string>     // std::string and all its member functions (except replace, which is forbidden)

// replaceAll: returns 'content' with every occurrence of s1 replaced by s2.
// std::string::replace is FORBIDDEN by the subject, so we rebuild the result manually:
// we walk through the string with find() and append the unchanged parts + the replacement.
static std::string replaceAll(std::string content, const std::string &s1, const std::string &s2)
{
	size_t pos = 0;                 // Current search position in the content string
	size_t s1Len = s1.length();     // Length of the pattern, used to jump past each match

	// Special case: an empty s1 has no defined "occurrences"; to avoid an infinite loop
	// of empty matches we treat it as "nothing to replace".
	if (s1Len == 0)
		return (content);

	// Loop until find() can no longer locate s1 starting from 'pos'.
	while ((pos = content.find(s1, pos)) != std::string::npos) // npos means "not found"
	{
		content.erase(pos, s1Len);      // Remove the matched s1 at position 'pos'
		content.insert(pos, s2);        // Insert s2 in its place, so s1 becomes s2
		pos += s2.length();             // Move past the inserted s2 so we never re-match inside it
	}
	return (content); // Return the fully rewritten string
}

int main(int argc, char **argv)
{
	// The program takes EXACTLY three parameters: filename, s1, s2 (plus argv[0] = program name).
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1); // Non-zero exit code tells the shell that an error occurred
	}

	std::string filename = argv[1]; // First parameter: the file to read
	std::string s1 = argv[2];       // Second parameter: the pattern to search for
	std::string s2 = argv[3];       // Third parameter: what every s1 must become

	// Open the input file in read mode (text mode). C FILE* functions are forbidden, streams only.
	std::ifstream input(filename.c_str()); // c_str(): C++98 ifstream does not take a std::string directly
	if (!input.is_open())                  // The file may not exist or may not be readable
	{
		std::cerr << "Error: cannot open file " << filename << std::endl;
		return (1);
	}

	// Read the whole file with getline(): each call fetches one line until the stream fails.
	// We append '\n' to each line because getline strips the newline character that ended it.
	std::string content;    // Accumulator for the entire file content
	std::string line;       // Buffer holding the line currently read
	while (std::getline(input, line))
	{
		content += line;    // Add the line's characters to the accumulator
		content += '\n';    // Restore the newline that getline consumed
	}
	input.close();          // Done reading: close the input stream cleanly

	// Rewrite the content: replace every occurrence of s1 by s2.
	std::string result = replaceAll(content, s1, s2);

	// Create the output file "<filename>.replace" in write mode
	// (weird chars in the name are handled the same way for both streams).
	std::string outName = filename + ".replace"; // The subject names the new file this way
	std::ofstream output(outName.c_str());       // Created (or truncated) if the open succeeds
	if (!output.is_open())
	{
		std::cerr << "Error: cannot create file " << outName << std::endl;
		return (1);
	}

	output << result;    // Write the fully replaced content into the new file
	output.close();      // Done writing: flush and close the output stream
	return (0);          // Everything went fine: success exit code
}
