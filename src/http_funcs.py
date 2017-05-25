#
# KOZRUM PACKAGE INSTALLER
#
# @version		1.0.0
# @copyright	2017, Kozrum
# @license		MIT
#

from urllib.request import urlopen

def remote_repo_exists(url):
    try:
        connection = urlopen(url)
        response = connection.getcode()

    except Exception as e:
        return False

    return True
