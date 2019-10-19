#include "..\headers\generic_utilities.h"
#include <iostream>

void lower_string( string& str )
{
	for ( int i = 0; str[i] != '\0'; i++ )
	{
		if ( str[i] >= 'A' && str[i] <= 'Z' )    //checking for uppercase characters
			str[i] = str[i] + 32;         //converting uppercase to lowercase
	}
}

void ask_for_input( string question, string& value )
{
	std::cout << question;
	getline( std::cin, value );
	lower_string( value );
}

void ask_for_input_no_lowercasing( string question, string& value )
{
	std::cout << question;
	getline( std::cin, value );
}

void ask_for_input( string question, int& value )
{
	std::cout << question;
	string temp;
	getline( std::cin, temp );
	value = stoi( temp );
}

void print()
{
	std::cout << "\n" << std::endl;
}

void print( string input )
{
	std::cout << input << std::endl;
}

void print( int input )
{
	std::cout << std::to_string( input ) << std::endl;
}

void print( string input, string input2 )
{
	std::cout << input << input2 << std::endl;
}

void print( string input, int input2 )
{
	std::cout << input << std::to_string( input2 ) << std::endl;
}

void print( string input, string input2, int input3 )
{
	std::cout << input << input2 << std::to_string( input3 ) << std::endl;
}

void print( string input, string input2, string input3 )
{
	std::cout << input << input2 << input3 << std::endl;
}

void print( string input, string input2, string input3, string input4 )
{
	std::cout << input << input2 << input3 << input4 << std::endl;
}

void print( string input, string input2, int input3, string input4 )
{
	std::cout << input << input2 << std::to_string( input3 ) << input4 << std::endl;
}