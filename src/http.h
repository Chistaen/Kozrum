/**
 * KOZRUM PACKAGE INSTALLER
 *
 * @version		1.0.0
 * @copyright	2017, Kozrum
 * @license		MIT
 */

#ifndef KOZ_HTTP_H
#define KOZ_HTTP_H

#include <curl/curl.h>
#include <string>

namespace kozrum
{
	class HTTP
	{
	public:
	    HTTP(std::string t_url);
	    ~HTTP();
	    bool connect();

	private:
	    CURL* m_curl;
	    std::string m_url;
	};
}

#endif
