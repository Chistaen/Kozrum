/**
 * KOZRUM PACKAGE INSTALLER
 *
 * @version		1.0.0
 * @copyright	2017, Kozrum
 * @license		MIT
 */

#ifndef koz_argumentparser_h
#define koz_argumentparser_h

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>

namespace kozrum
{
	class ArgumentParser
	{
	public:
		static ArgumentParser* instantiate(int t_argc, char* t_argv[]);
		boost::program_options::variables_map get_map();

	private:
		static ArgumentParser* s_instance;
		ArgumentParser(int t_argc, char* t_argv[]);
		int m_argc;
		char **m_argv;

		boost::program_options::variables_map m_variable_map;
	};
}

#endif