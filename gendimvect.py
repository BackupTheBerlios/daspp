#!/usr/bin/env python
"""
This script produces a C++ header file for yse with DAS++ from a list of 
dimentions.

It readsa list of dimentions seperted by white space on a single line

the first line of the genrated file will be a comment explaining the file.
eth second line will be define a Boost Preprocessor metaprogramming list
named EdK_DAS_BASIS If the imput contains the names 'mass', 'time' 
& 'distance'
this line wil apear as followes:

#define EdK_DAS_BASIS (time, (mass, (distance, BOOST_PP_NIL ) ) )

There will then be one line for each input in the form as follows:

#define EdK_DAS_UID_time 1
#define EdK_DAS_UID_mass 2
#define EdK_DAS_UID_distance 3


Copyright (c) 2010 Ed Keith

Free use of this software is granted without restrictions.
"""
__docformat__ = "restructuredtext en"

# Version numbering scheme:
#     
#     the third digit changes with each release but the specification 
#         changes two releases that differ only in the third number should 
#         be functional equivalent. An 'A' indicates and Alpha version, A 'B'
#         indicates a beta version.
#
#     the second number changes when the specification changed, but system 
#         should be backward compatible. It should always be possible to drop 
#         in version with a hight second version number without breading any 
#         thing.
#
#     the first number changes if the new version is not backward compatible 
#         with the previous version.
#    

import sys

__version__ 	= "1.0.0B1a"
__author__ 	= "Ed Keith"
__copyright__ 	= "Copyright 2010, Ed Keith"
__license__ 	= "GPL"
__email__ 	= "edk@users.berlios.de"
__status__ 	= "Alpha"
__date__ 	= "17 June 2010"



def read_names():
    """
    reads names from standard input. names are seperated by white space. 
    Stops reading when it encountes an empty line, or an eof.
    """
    return raw_input().split() # for now all must be on a single line

def write_header(names):
	"""
	write out a file based on the passed in names
	"""
	# Print the first Line
	print "// Dimention Vercor for use by DAS++"
	# print second line
	print "#define EdK_DAS_BASIS ",
	for n in names:
		print "(" + n + ", ",

	print "BOOST_PP_NIL",

	for n in names:
		print ")",

	print "\n"

	# print the numbers
	i = 1
	for n in names:
		print "#define EdK_DAS_UID_" + n + " " + str(i)
		i += 1

if __name__ == "__main__":
    write_header(read_names())


