/**
 * KOZRUM PACKAGE INSTALLER
 *
 * @version		1.0.0
 * @copyright	2017, Kozrum
 * @license		MIT
 */

#include "argumentparser.h"
#include "utils.h"

#include <iostream>
#include <exception>
#include <cstdlib>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>

namespace kozrum
{
	ArgumentParser* ArgumentParser::s_instance = nullptr;
	boost::program_options::variables_map m_variable_map;

	ArgumentParser::ArgumentParser(int t_argc, char* t_argv[])
		: m_argc(t_argc),
		m_argv(t_argv)
	{
		try
		{
			boost::program_options::options_description m_options("*** KOZRUM PACKAGE INSTALLER ***");

			m_options.add_options()
			    ("help,h", "Display help page.")
			    ("about,o", "Display software information")
			    ("install,ir", "Install package from repository");

			boost::program_options::store(boost::program_options::command_line_parser(m_argc, m_argv).options(m_options).run(), m_variable_map);
		    boost::program_options::notify(m_variable_map);
		}

		catch (std::exception &e)
		{
			kozrum::report_error("Could not initialize command parser");
			exit(0);
		}
	}

	ArgumentParser* ArgumentParser::instantiate(int t_argc, char* t_argv[])
	{
		if (s_instance == nullptr)
		{
			ArgumentParser::s_instance = new ArgumentParser(t_argc, t_argv);
		}

		return s_instance;
	}

	boost::program_options::variables_map ArgumentParser::get_map()
	{
		return m_variable_map;
	}
}