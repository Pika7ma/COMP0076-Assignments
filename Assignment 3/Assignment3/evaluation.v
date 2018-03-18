#############################################################################
#                         A C A D E M I C   C O P Y
# 
# This file was produced by an ACADEMIC COPY of Parser Generator. It is for
# use in non-commercial software only. An ACADEMIC COPY of Parser Generator
# can only be used by a student, or a member of an academic community. If
# however you want to use Parser Generator for commercial purposes then you
# will need to purchase a license. For more information see the online help or
# go to the Bumble-Bee Software homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# evaluation.v
# YACC verbose file generated from evaluation.y.
# 
# Date: 10/29/17
# Time: 18:11:03
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : lines $end

    1  lines : lines expr '\n'
    2        | lines '\n'
    3        |

    4  expr : expr PLUS expr
    5       | expr MINUS expr
    6       | expr MUL expr
    7       | expr DIV expr
    8       | '(' expr ')'
    9       | MINUS expr
   10       | NUMBER


##############################################################################
# States
##############################################################################

state 0
	$accept : . lines $end
	lines : .  (3)

	.  reduce 3

	lines  goto 1


state 1
	lines : lines . expr '\n'
	lines : lines . '\n'
	$accept : lines . $end  (0)

	$end  accept
	'\n'  shift 2
	'('  shift 3
	NUMBER  shift 4
	MINUS  shift 5

	expr  goto 6


state 2
	lines : lines '\n' .  (2)

	.  reduce 2


state 3
	expr : '(' . expr ')'

	'('  shift 3
	NUMBER  shift 4
	MINUS  shift 5

	expr  goto 7


state 4
	expr : NUMBER .  (10)

	.  reduce 10


state 5
	expr : MINUS . expr

	'('  shift 3
	NUMBER  shift 4
	MINUS  shift 5

	expr  goto 8


state 6
	lines : lines expr . '\n'
	expr : expr . PLUS expr
	expr : expr . MINUS expr
	expr : expr . MUL expr
	expr : expr . DIV expr

	'\n'  shift 9
	PLUS  shift 10
	MINUS  shift 11
	MUL  shift 12
	DIV  shift 13


state 7
	expr : expr . PLUS expr
	expr : expr . MINUS expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : '(' expr . ')'

	')'  shift 14
	PLUS  shift 10
	MINUS  shift 11
	MUL  shift 12
	DIV  shift 13


state 8
	expr : expr . PLUS expr
	expr : expr . MINUS expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : MINUS expr .  (9)

	.  reduce 9


state 9
	lines : lines expr '\n' .  (1)

	.  reduce 1


state 10
	expr : expr PLUS . expr

	'('  shift 3
	NUMBER  shift 4
	MINUS  shift 5

	expr  goto 15


state 11
	expr : expr MINUS . expr

	'('  shift 3
	NUMBER  shift 4
	MINUS  shift 5

	expr  goto 16


state 12
	expr : expr MUL . expr

	'('  shift 3
	NUMBER  shift 4
	MINUS  shift 5

	expr  goto 17


state 13
	expr : expr DIV . expr

	'('  shift 3
	NUMBER  shift 4
	MINUS  shift 5

	expr  goto 18


state 14
	expr : '(' expr ')' .  (8)

	.  reduce 8


state 15
	expr : expr PLUS expr .  (4)
	expr : expr . PLUS expr
	expr : expr . MINUS expr
	expr : expr . MUL expr
	expr : expr . DIV expr

	MUL  shift 12
	DIV  shift 13
	.  reduce 4


state 16
	expr : expr . PLUS expr
	expr : expr MINUS expr .  (5)
	expr : expr . MINUS expr
	expr : expr . MUL expr
	expr : expr . DIV expr

	MUL  shift 12
	DIV  shift 13
	.  reduce 5


state 17
	expr : expr . PLUS expr
	expr : expr . MINUS expr
	expr : expr MUL expr .  (6)
	expr : expr . MUL expr
	expr : expr . DIV expr

	.  reduce 6


state 18
	expr : expr . PLUS expr
	expr : expr . MINUS expr
	expr : expr . MUL expr
	expr : expr DIV expr .  (7)
	expr : expr . DIV expr

	.  reduce 7


##############################################################################
# Summary
##############################################################################

11 token(s), 3 nonterminal(s)
11 grammar rule(s), 19 state(s)


##############################################################################
# End of File
##############################################################################
