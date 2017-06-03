#
# KOZRUM PACKAGE INSTALLER
#
# @version      1.0.0
# @copyright    2017, Kozrum
# @license      MIT
#

import os

def scan_for_sql_files(directory):
    sql_files = []

    for root, subdirs, files in os.walk(directory):
        for file in files:
            if file.endswith('.sql'): 
                sql_files.append(os.path.join(root, file))
                continue
            else:
                continue

    return sql_files