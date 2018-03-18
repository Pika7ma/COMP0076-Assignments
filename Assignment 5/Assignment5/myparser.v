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
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 01/03/18
# Time: 10:26:52
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : translation_unit $end

    1  primary_expression : IDENTIFIER
    2                     | CHAR_VAL
    3                     | INT_VAL
    4                     | ROUND_LEFT expression ROUND_RIGHT

    5  postfix_expression : primary_expression
    6                     | postfix_expression INC_OP
    7                     | postfix_expression DEC_OP

    8  unary_expression : postfix_expression
    9                   | INC_OP unary_expression
   10                   | DEC_OP unary_expression
   11                   | unary_operator unary_expression

   12  unary_operator : ADD_OP
   13                 | SUB_OP
   14                 | BIT_NOT_OP
   15                 | NOT_OP

   16  multiplicative_expression : unary_expression
   17                            | multiplicative_expression MUL_OP unary_expression
   18                            | multiplicative_expression DIV_OP unary_expression
   19                            | multiplicative_expression MOD_OP unary_expression

   20  additive_expression : multiplicative_expression
   21                      | additive_expression ADD_OP multiplicative_expression
   22                      | additive_expression SUB_OP multiplicative_expression

   23  shift_expression : additive_expression
   24                   | shift_expression BIT_LS_OP additive_expression
   25                   | shift_expression BIT_RS_OP additive_expression

   26  relational_expression : shift_expression
   27                        | relational_expression LESS_OP shift_expression
   28                        | relational_expression GREATER_OP shift_expression
   29                        | relational_expression LE_OP shift_expression
   30                        | relational_expression GE_OP shift_expression

   31  equality_expression : relational_expression
   32                      | equality_expression EQ_OP relational_expression
   33                      | equality_expression NE_OP relational_expression

   34  and_expression : equality_expression
   35                 | and_expression BIT_AND_OP equality_expression

   36  exclusive_or_expression : and_expression
   37                          | exclusive_or_expression BIT_XOR_OP and_expression

   38  inclusive_or_expression : exclusive_or_expression
   39                          | inclusive_or_expression BIT_OR_OP exclusive_or_expression

   40  logical_and_expression : inclusive_or_expression
   41                         | logical_and_expression AND_OP inclusive_or_expression

   42  logical_or_expression : logical_and_expression
   43                        | logical_or_expression OR_OP logical_and_expression

   44  assignment_expression : logical_or_expression
   45                        | unary_expression assignment_operator assignment_expression

   46  assignment_operator : EQ_ASGN
   47                      | MUL_ASGN
   48                      | DIV_ASGN
   49                      | MOD_ASGN
   50                      | ADD_ASGN
   51                      | SUB_ASGN
   52                      | LS_ASGN
   53                      | RS_ASGN
   54                      | AND_ASGN
   55                      | XOR_ASGN
   56                      | OR_ASGN

   57  expression : assignment_expression
   58             | expression COMMA assignment_expression

   59  declaration : type_specifier init_declarator_list SEMICOLON

   60  init_declarator_list : direct_declarator
   61                       | init_declarator_list COMMA direct_declarator

   62  type_specifier : CHAR
   63                 | INT

   64  direct_declarator : IDENTIFIER

   65  statement : compound_statement
   66            | expression_statement
   67            | selection_statement
   68            | iteration_statement
   69            | jump_statement
   70            | input_statement
   71            | print_statement

   72  input_statement : INPUT ROUND_LEFT IDENTIFIER ROUND_RIGHT SEMICOLON

   73  print_statement : PRINT ROUND_LEFT expression ROUND_RIGHT SEMICOLON

   74  $$1 :

   75  compound_statement : CURLY_LEFT $$1 CURLY_RIGHT

   76  $$2 :

   77  compound_statement : CURLY_LEFT $$2 declaration_statement_list CURLY_RIGHT

   78  declaration_statement_list : declaration_statement_list declaration
   79                             | declaration_statement_list statement
   80                             | declaration
   81                             | statement

   82  expression_statement : SEMICOLON
   83                       | expression SEMICOLON

   84  selection_statement : IF ROUND_LEFT expression ROUND_RIGHT statement
   85                      | IF ROUND_LEFT expression ROUND_RIGHT statement ELSE statement

   86  iteration_statement : WHILE ROUND_LEFT expression ROUND_RIGHT statement
   87                      | DO statement WHILE ROUND_LEFT expression ROUND_RIGHT SEMICOLON
   88                      | FOR ROUND_LEFT expression_statement expression_statement ROUND_RIGHT statement
   89                      | FOR ROUND_LEFT expression_statement expression_statement expression ROUND_RIGHT statement

   90  jump_statement : CONTINUE SEMICOLON
   91                 | BREAK SEMICOLON

   92  translation_unit : external_declaration
   93                   | translation_unit external_declaration

   94  external_declaration : function_definition
   95                       | declaration

   96  function_definition : MAIN ROUND_LEFT ROUND_RIGHT compound_statement
   97                      | type_specifier MAIN ROUND_LEFT ROUND_RIGHT compound_statement


##############################################################################
# States
##############################################################################

state 0
	$accept : . translation_unit $end

	MAIN  shift 1
	CHAR  shift 2
	INT  shift 3

	declaration  goto 4
	type_specifier  goto 5
	translation_unit  goto 6
	external_declaration  goto 7
	function_definition  goto 8


state 1
	function_definition : MAIN . ROUND_LEFT ROUND_RIGHT compound_statement

	ROUND_LEFT  shift 9


state 2
	type_specifier : CHAR .  (62)

	.  reduce 62


state 3
	type_specifier : INT .  (63)

	.  reduce 63


state 4
	external_declaration : declaration .  (95)

	.  reduce 95


state 5
	declaration : type_specifier . init_declarator_list SEMICOLON
	function_definition : type_specifier . MAIN ROUND_LEFT ROUND_RIGHT compound_statement

	MAIN  shift 10
	IDENTIFIER  shift 11

	init_declarator_list  goto 12
	direct_declarator  goto 13


state 6
	$accept : translation_unit . $end  (0)
	translation_unit : translation_unit . external_declaration

	$end  accept
	MAIN  shift 1
	CHAR  shift 2
	INT  shift 3

	declaration  goto 4
	type_specifier  goto 5
	external_declaration  goto 14
	function_definition  goto 8


state 7
	translation_unit : external_declaration .  (92)

	.  reduce 92


state 8
	external_declaration : function_definition .  (94)

	.  reduce 94


state 9
	function_definition : MAIN ROUND_LEFT . ROUND_RIGHT compound_statement

	ROUND_RIGHT  shift 15


state 10
	function_definition : type_specifier MAIN . ROUND_LEFT ROUND_RIGHT compound_statement

	ROUND_LEFT  shift 16


state 11
	direct_declarator : IDENTIFIER .  (64)

	.  reduce 64


state 12
	declaration : type_specifier init_declarator_list . SEMICOLON
	init_declarator_list : init_declarator_list . COMMA direct_declarator

	SEMICOLON  shift 17
	COMMA  shift 18


state 13
	init_declarator_list : direct_declarator .  (60)

	.  reduce 60


state 14
	translation_unit : translation_unit external_declaration .  (93)

	.  reduce 93


state 15
	function_definition : MAIN ROUND_LEFT ROUND_RIGHT . compound_statement

	CURLY_LEFT  shift 19

	compound_statement  goto 20


state 16
	function_definition : type_specifier MAIN ROUND_LEFT . ROUND_RIGHT compound_statement

	ROUND_RIGHT  shift 21


state 17
	declaration : type_specifier init_declarator_list SEMICOLON .  (59)

	.  reduce 59


state 18
	init_declarator_list : init_declarator_list COMMA . direct_declarator

	IDENTIFIER  shift 11

	direct_declarator  goto 22


state 19
	compound_statement : CURLY_LEFT . $$1 CURLY_RIGHT
	compound_statement : CURLY_LEFT . $$2 declaration_statement_list CURLY_RIGHT
	$$2 : .  (76)
	$$1 : .  (74)

	CURLY_RIGHT  reduce 74
	.  reduce 76

	$$1  goto 23
	$$2  goto 24


state 20
	function_definition : MAIN ROUND_LEFT ROUND_RIGHT compound_statement .  (96)

	.  reduce 96


state 21
	function_definition : type_specifier MAIN ROUND_LEFT ROUND_RIGHT . compound_statement

	CURLY_LEFT  shift 19

	compound_statement  goto 25


state 22
	init_declarator_list : init_declarator_list COMMA direct_declarator .  (61)

	.  reduce 61


state 23
	compound_statement : CURLY_LEFT $$1 . CURLY_RIGHT

	CURLY_RIGHT  shift 26


state 24
	compound_statement : CURLY_LEFT $$2 . declaration_statement_list CURLY_RIGHT

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	SEMICOLON  shift 33
	INPUT  shift 34
	PRINT  shift 35
	ROUND_LEFT  shift 36
	CURLY_LEFT  shift 19
	CHAR  shift 2
	INT  shift 3
	IF  shift 37
	WHILE  shift 38
	DO  shift 39
	FOR  shift 40
	CONTINUE  shift 41
	BREAK  shift 42
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	declaration  goto 46
	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 50
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	type_specifier  goto 58
	expression  goto 59
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63
	print_statement  goto 64
	declaration_statement_list  goto 65
	input_statement  goto 66
	iteration_statement  goto 67
	jump_statement  goto 68
	compound_statement  goto 69
	expression_statement  goto 70
	selection_statement  goto 71
	statement  goto 72


state 25
	function_definition : type_specifier MAIN ROUND_LEFT ROUND_RIGHT compound_statement .  (97)

	.  reduce 97


state 26
	compound_statement : CURLY_LEFT $$1 CURLY_RIGHT .  (75)

	.  reduce 75


state 27
	unary_operator : BIT_NOT_OP .  (14)

	.  reduce 14


state 28
	unary_expression : INC_OP . unary_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	unary_expression  goto 73
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 29
	unary_expression : DEC_OP . unary_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	unary_expression  goto 74
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 30
	unary_operator : ADD_OP .  (12)

	.  reduce 12


state 31
	unary_operator : SUB_OP .  (13)

	.  reduce 13


state 32
	unary_operator : NOT_OP .  (15)

	.  reduce 15


state 33
	expression_statement : SEMICOLON .  (82)

	.  reduce 82


state 34
	input_statement : INPUT . ROUND_LEFT IDENTIFIER ROUND_RIGHT SEMICOLON

	ROUND_LEFT  shift 75


state 35
	print_statement : PRINT . ROUND_LEFT expression ROUND_RIGHT SEMICOLON

	ROUND_LEFT  shift 76


state 36
	primary_expression : ROUND_LEFT . expression ROUND_RIGHT

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 50
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	expression  goto 77
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 37
	selection_statement : IF . ROUND_LEFT expression ROUND_RIGHT statement
	selection_statement : IF . ROUND_LEFT expression ROUND_RIGHT statement ELSE statement

	ROUND_LEFT  shift 78


state 38
	iteration_statement : WHILE . ROUND_LEFT expression ROUND_RIGHT statement

	ROUND_LEFT  shift 79


state 39
	iteration_statement : DO . statement WHILE ROUND_LEFT expression ROUND_RIGHT SEMICOLON

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	SEMICOLON  shift 33
	INPUT  shift 34
	PRINT  shift 35
	ROUND_LEFT  shift 36
	CURLY_LEFT  shift 19
	IF  shift 37
	WHILE  shift 38
	DO  shift 39
	FOR  shift 40
	CONTINUE  shift 41
	BREAK  shift 42
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 50
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	expression  goto 59
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63
	print_statement  goto 64
	input_statement  goto 66
	iteration_statement  goto 67
	jump_statement  goto 68
	compound_statement  goto 69
	expression_statement  goto 70
	selection_statement  goto 71
	statement  goto 80


state 40
	iteration_statement : FOR . ROUND_LEFT expression_statement expression_statement ROUND_RIGHT statement
	iteration_statement : FOR . ROUND_LEFT expression_statement expression_statement expression ROUND_RIGHT statement

	ROUND_LEFT  shift 81


state 41
	jump_statement : CONTINUE . SEMICOLON

	SEMICOLON  shift 82


state 42
	jump_statement : BREAK . SEMICOLON

	SEMICOLON  shift 83


state 43
	primary_expression : IDENTIFIER .  (1)

	.  reduce 1


state 44
	primary_expression : CHAR_VAL .  (2)

	.  reduce 2


state 45
	primary_expression : INT_VAL .  (3)

	.  reduce 3


state 46
	declaration_statement_list : declaration .  (80)

	.  reduce 80


state 47
	additive_expression : multiplicative_expression .  (20)
	multiplicative_expression : multiplicative_expression . DIV_OP unary_expression
	multiplicative_expression : multiplicative_expression . MUL_OP unary_expression
	multiplicative_expression : multiplicative_expression . MOD_OP unary_expression

	MUL_OP  shift 84
	DIV_OP  shift 85
	MOD_OP  shift 86
	.  reduce 20


state 48
	exclusive_or_expression : exclusive_or_expression . BIT_XOR_OP and_expression
	inclusive_or_expression : exclusive_or_expression .  (38)

	BIT_XOR_OP  shift 87
	.  reduce 38


state 49
	logical_and_expression : logical_and_expression . AND_OP inclusive_or_expression
	logical_or_expression : logical_and_expression .  (42)

	AND_OP  shift 88
	.  reduce 42


state 50
	expression : assignment_expression .  (57)

	.  reduce 57


state 51
	shift_expression : shift_expression . BIT_RS_OP additive_expression
	relational_expression : shift_expression .  (26)
	shift_expression : shift_expression . BIT_LS_OP additive_expression

	BIT_RS_OP  shift 89
	BIT_LS_OP  shift 90
	.  reduce 26


state 52
	and_expression : and_expression . BIT_AND_OP equality_expression
	exclusive_or_expression : and_expression .  (36)

	BIT_AND_OP  shift 91
	.  reduce 36


state 53
	assignment_expression : logical_or_expression .  (44)
	logical_or_expression : logical_or_expression . OR_OP logical_and_expression

	OR_OP  shift 92
	.  reduce 44


state 54
	equality_expression : equality_expression . NE_OP relational_expression
	equality_expression : equality_expression . EQ_OP relational_expression
	and_expression : equality_expression .  (34)

	EQ_OP  shift 93
	NE_OP  shift 94
	.  reduce 34


state 55
	inclusive_or_expression : inclusive_or_expression . BIT_OR_OP exclusive_or_expression
	logical_and_expression : inclusive_or_expression .  (40)

	BIT_OR_OP  shift 95
	.  reduce 40


state 56
	equality_expression : relational_expression .  (31)
	relational_expression : relational_expression . LESS_OP shift_expression
	relational_expression : relational_expression . LE_OP shift_expression
	relational_expression : relational_expression . GREATER_OP shift_expression
	relational_expression : relational_expression . GE_OP shift_expression

	LESS_OP  shift 96
	GREATER_OP  shift 97
	LE_OP  shift 98
	GE_OP  shift 99
	.  reduce 31


state 57
	shift_expression : additive_expression .  (23)
	additive_expression : additive_expression . ADD_OP multiplicative_expression
	additive_expression : additive_expression . SUB_OP multiplicative_expression

	ADD_OP  shift 100
	SUB_OP  shift 101
	.  reduce 23


state 58
	declaration : type_specifier . init_declarator_list SEMICOLON

	IDENTIFIER  shift 11

	init_declarator_list  goto 12
	direct_declarator  goto 13


state 59
	expression : expression . COMMA assignment_expression
	expression_statement : expression . SEMICOLON

	SEMICOLON  shift 102
	COMMA  shift 103


state 60
	multiplicative_expression : unary_expression .  (16)
	assignment_expression : unary_expression . assignment_operator assignment_expression

	EQ_ASGN  shift 104
	SUB_ASGN  shift 105
	LS_ASGN  shift 106
	RS_ASGN  shift 107
	AND_ASGN  shift 108
	XOR_ASGN  shift 109
	OR_ASGN  shift 110
	MUL_ASGN  shift 111
	DIV_ASGN  shift 112
	MOD_ASGN  shift 113
	ADD_ASGN  shift 114
	.  reduce 16

	assignment_operator  goto 115


state 61
	postfix_expression : primary_expression .  (5)

	.  reduce 5


state 62
	unary_expression : unary_operator . unary_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	unary_expression  goto 116
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 63
	postfix_expression : postfix_expression . INC_OP
	postfix_expression : postfix_expression . DEC_OP
	unary_expression : postfix_expression .  (8)

	INC_OP  shift 117
	DEC_OP  shift 118
	.  reduce 8


state 64
	statement : print_statement .  (71)

	.  reduce 71


state 65
	declaration_statement_list : declaration_statement_list . statement
	compound_statement : CURLY_LEFT $$2 declaration_statement_list . CURLY_RIGHT
	declaration_statement_list : declaration_statement_list . declaration

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	SEMICOLON  shift 33
	INPUT  shift 34
	PRINT  shift 35
	ROUND_LEFT  shift 36
	CURLY_LEFT  shift 19
	CURLY_RIGHT  shift 119
	CHAR  shift 2
	INT  shift 3
	IF  shift 37
	WHILE  shift 38
	DO  shift 39
	FOR  shift 40
	CONTINUE  shift 41
	BREAK  shift 42
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	declaration  goto 120
	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 50
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	type_specifier  goto 58
	expression  goto 59
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63
	print_statement  goto 64
	input_statement  goto 66
	iteration_statement  goto 67
	jump_statement  goto 68
	compound_statement  goto 69
	expression_statement  goto 70
	selection_statement  goto 71
	statement  goto 121


state 66
	statement : input_statement .  (70)

	.  reduce 70


state 67
	statement : iteration_statement .  (68)

	.  reduce 68


state 68
	statement : jump_statement .  (69)

	.  reduce 69


state 69
	statement : compound_statement .  (65)

	.  reduce 65


state 70
	statement : expression_statement .  (66)

	.  reduce 66


state 71
	statement : selection_statement .  (67)

	.  reduce 67


state 72
	declaration_statement_list : statement .  (81)

	.  reduce 81


state 73
	unary_expression : INC_OP unary_expression .  (9)

	.  reduce 9


state 74
	unary_expression : DEC_OP unary_expression .  (10)

	.  reduce 10


state 75
	input_statement : INPUT ROUND_LEFT . IDENTIFIER ROUND_RIGHT SEMICOLON

	IDENTIFIER  shift 122


state 76
	print_statement : PRINT ROUND_LEFT . expression ROUND_RIGHT SEMICOLON

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 50
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	expression  goto 123
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 77
	primary_expression : ROUND_LEFT expression . ROUND_RIGHT
	expression : expression . COMMA assignment_expression

	COMMA  shift 103
	ROUND_RIGHT  shift 124


state 78
	selection_statement : IF ROUND_LEFT . expression ROUND_RIGHT statement
	selection_statement : IF ROUND_LEFT . expression ROUND_RIGHT statement ELSE statement

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 50
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	expression  goto 125
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 79
	iteration_statement : WHILE ROUND_LEFT . expression ROUND_RIGHT statement

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 50
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	expression  goto 126
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 80
	iteration_statement : DO statement . WHILE ROUND_LEFT expression ROUND_RIGHT SEMICOLON

	WHILE  shift 127


state 81
	iteration_statement : FOR ROUND_LEFT . expression_statement expression_statement ROUND_RIGHT statement
	iteration_statement : FOR ROUND_LEFT . expression_statement expression_statement expression ROUND_RIGHT statement

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	SEMICOLON  shift 33
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 50
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	expression  goto 59
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63
	expression_statement  goto 128


state 82
	jump_statement : CONTINUE SEMICOLON .  (90)

	.  reduce 90


state 83
	jump_statement : BREAK SEMICOLON .  (91)

	.  reduce 91


state 84
	multiplicative_expression : multiplicative_expression MUL_OP . unary_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	unary_expression  goto 129
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 85
	multiplicative_expression : multiplicative_expression DIV_OP . unary_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	unary_expression  goto 130
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 86
	multiplicative_expression : multiplicative_expression MOD_OP . unary_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	unary_expression  goto 131
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 87
	exclusive_or_expression : exclusive_or_expression BIT_XOR_OP . and_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	shift_expression  goto 51
	and_expression  goto 132
	equality_expression  goto 54
	relational_expression  goto 56
	additive_expression  goto 57
	unary_expression  goto 133
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 88
	logical_and_expression : logical_and_expression AND_OP . inclusive_or_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	shift_expression  goto 51
	and_expression  goto 52
	equality_expression  goto 54
	inclusive_or_expression  goto 134
	relational_expression  goto 56
	additive_expression  goto 57
	unary_expression  goto 133
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 89
	shift_expression : shift_expression BIT_RS_OP . additive_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	additive_expression  goto 135
	unary_expression  goto 133
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 90
	shift_expression : shift_expression BIT_LS_OP . additive_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	additive_expression  goto 136
	unary_expression  goto 133
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 91
	and_expression : and_expression BIT_AND_OP . equality_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	shift_expression  goto 51
	equality_expression  goto 137
	relational_expression  goto 56
	additive_expression  goto 57
	unary_expression  goto 133
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 92
	logical_or_expression : logical_or_expression OR_OP . logical_and_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 138
	shift_expression  goto 51
	and_expression  goto 52
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	unary_expression  goto 133
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 93
	equality_expression : equality_expression EQ_OP . relational_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	shift_expression  goto 51
	relational_expression  goto 139
	additive_expression  goto 57
	unary_expression  goto 133
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 94
	equality_expression : equality_expression NE_OP . relational_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	shift_expression  goto 51
	relational_expression  goto 140
	additive_expression  goto 57
	unary_expression  goto 133
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 95
	inclusive_or_expression : inclusive_or_expression BIT_OR_OP . exclusive_or_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 141
	shift_expression  goto 51
	and_expression  goto 52
	equality_expression  goto 54
	relational_expression  goto 56
	additive_expression  goto 57
	unary_expression  goto 133
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 96
	relational_expression : relational_expression LESS_OP . shift_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	shift_expression  goto 142
	additive_expression  goto 57
	unary_expression  goto 133
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 97
	relational_expression : relational_expression GREATER_OP . shift_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	shift_expression  goto 143
	additive_expression  goto 57
	unary_expression  goto 133
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 98
	relational_expression : relational_expression LE_OP . shift_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	shift_expression  goto 144
	additive_expression  goto 57
	unary_expression  goto 133
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 99
	relational_expression : relational_expression GE_OP . shift_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	shift_expression  goto 145
	additive_expression  goto 57
	unary_expression  goto 133
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 100
	additive_expression : additive_expression ADD_OP . multiplicative_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 146
	unary_expression  goto 133
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 101
	additive_expression : additive_expression SUB_OP . multiplicative_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 147
	unary_expression  goto 133
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 102
	expression_statement : expression SEMICOLON .  (83)

	.  reduce 83


state 103
	expression : expression COMMA . assignment_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 148
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 104
	assignment_operator : EQ_ASGN .  (46)

	.  reduce 46


state 105
	assignment_operator : SUB_ASGN .  (51)

	.  reduce 51


state 106
	assignment_operator : LS_ASGN .  (52)

	.  reduce 52


state 107
	assignment_operator : RS_ASGN .  (53)

	.  reduce 53


state 108
	assignment_operator : AND_ASGN .  (54)

	.  reduce 54


state 109
	assignment_operator : XOR_ASGN .  (55)

	.  reduce 55


state 110
	assignment_operator : OR_ASGN .  (56)

	.  reduce 56


state 111
	assignment_operator : MUL_ASGN .  (47)

	.  reduce 47


state 112
	assignment_operator : DIV_ASGN .  (48)

	.  reduce 48


state 113
	assignment_operator : MOD_ASGN .  (49)

	.  reduce 49


state 114
	assignment_operator : ADD_ASGN .  (50)

	.  reduce 50


state 115
	assignment_expression : unary_expression assignment_operator . assignment_expression

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 149
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 116
	unary_expression : unary_operator unary_expression .  (11)

	.  reduce 11


state 117
	postfix_expression : postfix_expression INC_OP .  (6)

	.  reduce 6


state 118
	postfix_expression : postfix_expression DEC_OP .  (7)

	.  reduce 7


state 119
	compound_statement : CURLY_LEFT $$2 declaration_statement_list CURLY_RIGHT .  (77)

	.  reduce 77


state 120
	declaration_statement_list : declaration_statement_list declaration .  (78)

	.  reduce 78


state 121
	declaration_statement_list : declaration_statement_list statement .  (79)

	.  reduce 79


state 122
	input_statement : INPUT ROUND_LEFT IDENTIFIER . ROUND_RIGHT SEMICOLON

	ROUND_RIGHT  shift 150


state 123
	expression : expression . COMMA assignment_expression
	print_statement : PRINT ROUND_LEFT expression . ROUND_RIGHT SEMICOLON

	COMMA  shift 103
	ROUND_RIGHT  shift 151


state 124
	primary_expression : ROUND_LEFT expression ROUND_RIGHT .  (4)

	.  reduce 4


state 125
	expression : expression . COMMA assignment_expression
	selection_statement : IF ROUND_LEFT expression . ROUND_RIGHT statement
	selection_statement : IF ROUND_LEFT expression . ROUND_RIGHT statement ELSE statement

	COMMA  shift 103
	ROUND_RIGHT  shift 152


state 126
	expression : expression . COMMA assignment_expression
	iteration_statement : WHILE ROUND_LEFT expression . ROUND_RIGHT statement

	COMMA  shift 103
	ROUND_RIGHT  shift 153


state 127
	iteration_statement : DO statement WHILE . ROUND_LEFT expression ROUND_RIGHT SEMICOLON

	ROUND_LEFT  shift 154


state 128
	iteration_statement : FOR ROUND_LEFT expression_statement . expression_statement ROUND_RIGHT statement
	iteration_statement : FOR ROUND_LEFT expression_statement . expression_statement expression ROUND_RIGHT statement

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	SEMICOLON  shift 33
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 50
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	expression  goto 59
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63
	expression_statement  goto 155


state 129
	multiplicative_expression : multiplicative_expression MUL_OP unary_expression .  (17)

	.  reduce 17


state 130
	multiplicative_expression : multiplicative_expression DIV_OP unary_expression .  (18)

	.  reduce 18


state 131
	multiplicative_expression : multiplicative_expression MOD_OP unary_expression .  (19)

	.  reduce 19


state 132
	and_expression : and_expression . BIT_AND_OP equality_expression
	exclusive_or_expression : exclusive_or_expression BIT_XOR_OP and_expression .  (37)

	BIT_AND_OP  shift 91
	.  reduce 37


state 133
	multiplicative_expression : unary_expression .  (16)

	.  reduce 16


state 134
	inclusive_or_expression : inclusive_or_expression . BIT_OR_OP exclusive_or_expression
	logical_and_expression : logical_and_expression AND_OP inclusive_or_expression .  (41)

	BIT_OR_OP  shift 95
	.  reduce 41


state 135
	shift_expression : shift_expression BIT_RS_OP additive_expression .  (25)
	additive_expression : additive_expression . ADD_OP multiplicative_expression
	additive_expression : additive_expression . SUB_OP multiplicative_expression

	ADD_OP  shift 100
	SUB_OP  shift 101
	.  reduce 25


state 136
	additive_expression : additive_expression . ADD_OP multiplicative_expression
	shift_expression : shift_expression BIT_LS_OP additive_expression .  (24)
	additive_expression : additive_expression . SUB_OP multiplicative_expression

	ADD_OP  shift 100
	SUB_OP  shift 101
	.  reduce 24


state 137
	equality_expression : equality_expression . NE_OP relational_expression
	equality_expression : equality_expression . EQ_OP relational_expression
	and_expression : and_expression BIT_AND_OP equality_expression .  (35)

	EQ_OP  shift 93
	NE_OP  shift 94
	.  reduce 35


state 138
	logical_and_expression : logical_and_expression . AND_OP inclusive_or_expression
	logical_or_expression : logical_or_expression OR_OP logical_and_expression .  (43)

	AND_OP  shift 88
	.  reduce 43


state 139
	relational_expression : relational_expression . LESS_OP shift_expression
	relational_expression : relational_expression . LE_OP shift_expression
	relational_expression : relational_expression . GREATER_OP shift_expression
	relational_expression : relational_expression . GE_OP shift_expression
	equality_expression : equality_expression EQ_OP relational_expression .  (32)

	LESS_OP  shift 96
	GREATER_OP  shift 97
	LE_OP  shift 98
	GE_OP  shift 99
	.  reduce 32


state 140
	equality_expression : equality_expression NE_OP relational_expression .  (33)
	relational_expression : relational_expression . LESS_OP shift_expression
	relational_expression : relational_expression . LE_OP shift_expression
	relational_expression : relational_expression . GREATER_OP shift_expression
	relational_expression : relational_expression . GE_OP shift_expression

	LESS_OP  shift 96
	GREATER_OP  shift 97
	LE_OP  shift 98
	GE_OP  shift 99
	.  reduce 33


state 141
	inclusive_or_expression : inclusive_or_expression BIT_OR_OP exclusive_or_expression .  (39)
	exclusive_or_expression : exclusive_or_expression . BIT_XOR_OP and_expression

	BIT_XOR_OP  shift 87
	.  reduce 39


state 142
	shift_expression : shift_expression . BIT_RS_OP additive_expression
	relational_expression : relational_expression LESS_OP shift_expression .  (27)
	shift_expression : shift_expression . BIT_LS_OP additive_expression

	BIT_RS_OP  shift 89
	BIT_LS_OP  shift 90
	.  reduce 27


state 143
	shift_expression : shift_expression . BIT_RS_OP additive_expression
	shift_expression : shift_expression . BIT_LS_OP additive_expression
	relational_expression : relational_expression GREATER_OP shift_expression .  (28)

	BIT_RS_OP  shift 89
	BIT_LS_OP  shift 90
	.  reduce 28


state 144
	shift_expression : shift_expression . BIT_RS_OP additive_expression
	relational_expression : relational_expression LE_OP shift_expression .  (29)
	shift_expression : shift_expression . BIT_LS_OP additive_expression

	BIT_RS_OP  shift 89
	BIT_LS_OP  shift 90
	.  reduce 29


state 145
	shift_expression : shift_expression . BIT_RS_OP additive_expression
	shift_expression : shift_expression . BIT_LS_OP additive_expression
	relational_expression : relational_expression GE_OP shift_expression .  (30)

	BIT_RS_OP  shift 89
	BIT_LS_OP  shift 90
	.  reduce 30


state 146
	additive_expression : additive_expression ADD_OP multiplicative_expression .  (21)
	multiplicative_expression : multiplicative_expression . DIV_OP unary_expression
	multiplicative_expression : multiplicative_expression . MUL_OP unary_expression
	multiplicative_expression : multiplicative_expression . MOD_OP unary_expression

	MUL_OP  shift 84
	DIV_OP  shift 85
	MOD_OP  shift 86
	.  reduce 21


state 147
	multiplicative_expression : multiplicative_expression . DIV_OP unary_expression
	multiplicative_expression : multiplicative_expression . MUL_OP unary_expression
	multiplicative_expression : multiplicative_expression . MOD_OP unary_expression
	additive_expression : additive_expression SUB_OP multiplicative_expression .  (22)

	MUL_OP  shift 84
	DIV_OP  shift 85
	MOD_OP  shift 86
	.  reduce 22


state 148
	expression : expression COMMA assignment_expression .  (58)

	.  reduce 58


state 149
	assignment_expression : unary_expression assignment_operator assignment_expression .  (45)

	.  reduce 45


state 150
	input_statement : INPUT ROUND_LEFT IDENTIFIER ROUND_RIGHT . SEMICOLON

	SEMICOLON  shift 156


state 151
	print_statement : PRINT ROUND_LEFT expression ROUND_RIGHT . SEMICOLON

	SEMICOLON  shift 157


state 152
	selection_statement : IF ROUND_LEFT expression ROUND_RIGHT . statement
	selection_statement : IF ROUND_LEFT expression ROUND_RIGHT . statement ELSE statement

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	SEMICOLON  shift 33
	INPUT  shift 34
	PRINT  shift 35
	ROUND_LEFT  shift 36
	CURLY_LEFT  shift 19
	IF  shift 37
	WHILE  shift 38
	DO  shift 39
	FOR  shift 40
	CONTINUE  shift 41
	BREAK  shift 42
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 50
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	expression  goto 59
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63
	print_statement  goto 64
	input_statement  goto 66
	iteration_statement  goto 67
	jump_statement  goto 68
	compound_statement  goto 69
	expression_statement  goto 70
	selection_statement  goto 71
	statement  goto 158


state 153
	iteration_statement : WHILE ROUND_LEFT expression ROUND_RIGHT . statement

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	SEMICOLON  shift 33
	INPUT  shift 34
	PRINT  shift 35
	ROUND_LEFT  shift 36
	CURLY_LEFT  shift 19
	IF  shift 37
	WHILE  shift 38
	DO  shift 39
	FOR  shift 40
	CONTINUE  shift 41
	BREAK  shift 42
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 50
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	expression  goto 59
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63
	print_statement  goto 64
	input_statement  goto 66
	iteration_statement  goto 67
	jump_statement  goto 68
	compound_statement  goto 69
	expression_statement  goto 70
	selection_statement  goto 71
	statement  goto 159


state 154
	iteration_statement : DO statement WHILE ROUND_LEFT . expression ROUND_RIGHT SEMICOLON

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 50
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	expression  goto 160
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 155
	iteration_statement : FOR ROUND_LEFT expression_statement expression_statement . ROUND_RIGHT statement
	iteration_statement : FOR ROUND_LEFT expression_statement expression_statement . expression ROUND_RIGHT statement

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	ROUND_LEFT  shift 36
	ROUND_RIGHT  shift 161
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 50
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	expression  goto 162
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63


state 156
	input_statement : INPUT ROUND_LEFT IDENTIFIER ROUND_RIGHT SEMICOLON .  (72)

	.  reduce 72


state 157
	print_statement : PRINT ROUND_LEFT expression ROUND_RIGHT SEMICOLON .  (73)

	.  reduce 73


state 158
	selection_statement : IF ROUND_LEFT expression ROUND_RIGHT statement .  (84)
	selection_statement : IF ROUND_LEFT expression ROUND_RIGHT statement . ELSE statement

	ELSE  shift 163
	.  reduce 84


state 159
	iteration_statement : WHILE ROUND_LEFT expression ROUND_RIGHT statement .  (86)

	.  reduce 86


state 160
	expression : expression . COMMA assignment_expression
	iteration_statement : DO statement WHILE ROUND_LEFT expression . ROUND_RIGHT SEMICOLON

	COMMA  shift 103
	ROUND_RIGHT  shift 164


state 161
	iteration_statement : FOR ROUND_LEFT expression_statement expression_statement ROUND_RIGHT . statement

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	SEMICOLON  shift 33
	INPUT  shift 34
	PRINT  shift 35
	ROUND_LEFT  shift 36
	CURLY_LEFT  shift 19
	IF  shift 37
	WHILE  shift 38
	DO  shift 39
	FOR  shift 40
	CONTINUE  shift 41
	BREAK  shift 42
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 50
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	expression  goto 59
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63
	print_statement  goto 64
	input_statement  goto 66
	iteration_statement  goto 67
	jump_statement  goto 68
	compound_statement  goto 69
	expression_statement  goto 70
	selection_statement  goto 71
	statement  goto 165


state 162
	expression : expression . COMMA assignment_expression
	iteration_statement : FOR ROUND_LEFT expression_statement expression_statement expression . ROUND_RIGHT statement

	COMMA  shift 103
	ROUND_RIGHT  shift 166


state 163
	selection_statement : IF ROUND_LEFT expression ROUND_RIGHT statement ELSE . statement

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	SEMICOLON  shift 33
	INPUT  shift 34
	PRINT  shift 35
	ROUND_LEFT  shift 36
	CURLY_LEFT  shift 19
	IF  shift 37
	WHILE  shift 38
	DO  shift 39
	FOR  shift 40
	CONTINUE  shift 41
	BREAK  shift 42
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 50
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	expression  goto 59
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63
	print_statement  goto 64
	input_statement  goto 66
	iteration_statement  goto 67
	jump_statement  goto 68
	compound_statement  goto 69
	expression_statement  goto 70
	selection_statement  goto 71
	statement  goto 167


state 164
	iteration_statement : DO statement WHILE ROUND_LEFT expression ROUND_RIGHT . SEMICOLON

	SEMICOLON  shift 168


state 165
	iteration_statement : FOR ROUND_LEFT expression_statement expression_statement ROUND_RIGHT statement .  (88)

	.  reduce 88


state 166
	iteration_statement : FOR ROUND_LEFT expression_statement expression_statement expression ROUND_RIGHT . statement

	BIT_NOT_OP  shift 27
	INC_OP  shift 28
	DEC_OP  shift 29
	ADD_OP  shift 30
	SUB_OP  shift 31
	NOT_OP  shift 32
	SEMICOLON  shift 33
	INPUT  shift 34
	PRINT  shift 35
	ROUND_LEFT  shift 36
	CURLY_LEFT  shift 19
	IF  shift 37
	WHILE  shift 38
	DO  shift 39
	FOR  shift 40
	CONTINUE  shift 41
	BREAK  shift 42
	IDENTIFIER  shift 43
	CHAR_VAL  shift 44
	INT_VAL  shift 45

	multiplicative_expression  goto 47
	exclusive_or_expression  goto 48
	logical_and_expression  goto 49
	assignment_expression  goto 50
	shift_expression  goto 51
	and_expression  goto 52
	logical_or_expression  goto 53
	equality_expression  goto 54
	inclusive_or_expression  goto 55
	relational_expression  goto 56
	additive_expression  goto 57
	expression  goto 59
	unary_expression  goto 60
	primary_expression  goto 61
	unary_operator  goto 62
	postfix_expression  goto 63
	print_statement  goto 64
	input_statement  goto 66
	iteration_statement  goto 67
	jump_statement  goto 68
	compound_statement  goto 69
	expression_statement  goto 70
	selection_statement  goto 71
	statement  goto 169


state 167
	selection_statement : IF ROUND_LEFT expression ROUND_RIGHT statement ELSE statement .  (85)

	.  reduce 85


state 168
	iteration_statement : DO statement WHILE ROUND_LEFT expression ROUND_RIGHT SEMICOLON .  (87)

	.  reduce 87


state 169
	iteration_statement : FOR ROUND_LEFT expression_statement expression_statement expression ROUND_RIGHT statement .  (89)

	.  reduce 89


##############################################################################
# Summary
##############################################################################

57 token(s), 36 nonterminal(s)
98 grammar rule(s), 170 state(s)


##############################################################################
# End of File
##############################################################################
