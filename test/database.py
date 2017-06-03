#
# KOZRUM PACKAGE INSTALLER
#
# @version		1.0.0
# @copyright	2017, Kozrum
# @license		MIT
#

import sys
sys.path.append('..')
from lib.database import *

files = scan_for_sql_files('../../')

for file in files:
	print (file)