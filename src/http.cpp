/**
 * KOZRUM PACKAGE INSTALLER
 *
 * @version		1.0.0
 * @copyright	2017, Kozrum
 * @license		MIT
 */

#include "http.h"
#include "utils.h"
#include <iostream>
#include <string>

namespace kozrum
{
    HTTP::HTTP(std::string t_url)
        : m_url(t_url)
    {
        m_curl = curl_easy_init();
    }

    HTTP::~HTTP()
    {
        curl_easy_cleanup(m_curl);
    }

    bool HTTP::connect()
    {
        curl_easy_setopt(m_curl, CURLOPT_URL, m_url.c_str());
        curl_easy_setopt(m_curl, CURLOPT_VERBOSE, 0L);
        curl_easy_setopt(m_curl, CURLOPT_FAILONERROR, true);
        curl_easy_setopt(m_curl, CURLOPT_FOLLOWLOCATION, true);
        curl_easy_setopt(m_curl, CURLOPT_NOBODY, true);

        long response_code;
    	curl_easy_perform(m_curl);
    	curl_easy_getinfo(m_curl, CURLINFO_RESPONSE_CODE, &response_code);

        return response_code != 404;
    }
}