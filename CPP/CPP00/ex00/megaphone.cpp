// Gives us std::cout (standard output stream) and std::endl (newline + flush)
#include <iostream>
// Gives us std::toupper, which uppercases one character at a time
#include <cctype>

// Program entry point. It receives the command-line arguments:
// - argc = argument count (always >= 1, because argv[0] is the program name)
// - argv = argument values: argv[0] = "./megaphone", argv[1] = first user word...
int	main(int argc, char **argv)
{
	// No argument was given (only the program name) -> print the noise line
	if (argc == 1)
	{
		// std::endl writes a '\n' AND flushes the output buffer
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		// return 0 = the program finished successfully
		return (0);
	}
	// Loop over every argument, starting at 1 to skip the program name
	for (int i = 1; i < argc; ++i)
	{
		// Loop over every character of argv[i].
		// argv[i] is a C-string (char*), so it ends at the '\0' character.
		for (int j = 0; argv[i][j] != '\0'; ++j)
			// Uppercase the character and print it:
			// 1. cast to unsigned char first (std::toupper must never receive
			//    a negative char value -> that would be undefined behavior)
			// 2. std::toupper returns the uppercase version (or same char)
			// 3. cast back to char so cout prints a character, not a number
			std::cout << static_cast<char>(
				std::toupper(static_cast<unsigned char>(argv[i][j])));
		// No separator printed between arguments: the subject's example
		// shows them joined together with the spaces they contain
	}
	// One final newline after all arguments have been shouted
	std::cout << std::endl;
	// Success
	return (0);
}
