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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 01/03/18
# Time: 10:26:52
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  '([^\n\\]|(\\.)|(\\[0-7]{1,3})|(\\[xX][0-9a-fA-F]{1,2}))'

    2  [0-9]|[1-9][0-9]+|(0)([0-7]+)|(0)[xX]([0-9a-fA-F]+)

    3  "//".*

    4  "/*"([^\*\/]|"*"[^\/])*"*/"

    5  "break"

    6  "char"

    7  "continue"

    8  "do"

    9  "else"

   10  "float"

   11  "for"

   12  "goto"

   13  "if"

   14  "int"

   15  "return"

   16  "struct"

   17  "union"

   18  "void"

   19  "while"

   20  "input"

   21  "print"

   22  "main"

   23  "="

   24  "+="

   25  "-="

   26  "*="

   27  "/="

   28  "%="

   29  ">>="

   30  "<<="

   31  "&="

   32  "^="

   33  "|="

   34  "~"

   35  "^"

   36  "&"

   37  "|"

   38  ">>"

   39  "<<"

   40  "++"

   41  "--"

   42  "->"

   43  "."

   44  "<"

   45  ">"

   46  "<="

   47  ">="

   48  "=="

   49  "!="

   50  ";"

   51  ","

   52  "?"

   53  ":"

   54  "("

   55  ")"

   56  "["

   57  "]"

   58  "{"

   59  "}"

   60  "!"

   61  "&&"

   62  "||"

   63  "-"

   64  "+"

   65  "*"

   66  "/"

   67  "%"

   68  [_A-Za-z]([_A-Za-z]|[0-9])*

   69  [\n]

   70  [\t]+

   71  [ \f\v]+

   72  .


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x00 - 0x08 (9)    goto 3
	0x09               goto 4
	0x0a               goto 5
	0x0b - 0x0c (2)    goto 6
	0x0d - 0x1f (19)   goto 3
	0x20               goto 6
	0x21               goto 7
	0x22 - 0x24 (3)    goto 3
	0x25               goto 8
	0x26               goto 9
	0x27               goto 10
	0x28               goto 11
	0x29               goto 12
	0x2a               goto 13
	0x2b               goto 14
	0x2c               goto 15
	0x2d               goto 16
	0x2e               goto 17
	0x2f               goto 18
	0x30               goto 19
	0x31 - 0x39 (9)    goto 20
	0x3a               goto 21
	0x3b               goto 22
	0x3c               goto 23
	0x3d               goto 24
	0x3e               goto 25
	0x3f               goto 26
	0x40               goto 3
	0x41 - 0x5a (26)   goto 27
	0x5b               goto 28
	0x5c               goto 3
	0x5d               goto 29
	0x5e               goto 30
	0x5f               goto 27
	0x60               goto 3
	0x61               goto 27
	0x62               goto 31
	0x63               goto 32
	0x64               goto 33
	0x65               goto 34
	0x66               goto 35
	0x67               goto 36
	0x68               goto 27
	0x69               goto 37
	0x6a - 0x6c (3)    goto 27
	0x6d               goto 38
	0x6e - 0x6f (2)    goto 27
	0x70               goto 39
	0x71               goto 27
	0x72               goto 40
	0x73               goto 41
	0x74               goto 27
	0x75               goto 42
	0x76               goto 43
	0x77               goto 44
	0x78 - 0x7a (3)    goto 27
	0x7b               goto 45
	0x7c               goto 46
	0x7d               goto 47
	0x7e               goto 48
	0x7f - 0xff (129)  goto 3


state 2
	^INITIAL

	0x00 - 0x08 (9)    goto 3
	0x09               goto 4
	0x0a               goto 5
	0x0b - 0x0c (2)    goto 6
	0x0d - 0x1f (19)   goto 3
	0x20               goto 6
	0x21               goto 7
	0x22 - 0x24 (3)    goto 3
	0x25               goto 8
	0x26               goto 9
	0x27               goto 10
	0x28               goto 11
	0x29               goto 12
	0x2a               goto 13
	0x2b               goto 14
	0x2c               goto 15
	0x2d               goto 16
	0x2e               goto 17
	0x2f               goto 18
	0x30               goto 19
	0x31 - 0x39 (9)    goto 20
	0x3a               goto 21
	0x3b               goto 22
	0x3c               goto 23
	0x3d               goto 24
	0x3e               goto 25
	0x3f               goto 26
	0x40               goto 3
	0x41 - 0x5a (26)   goto 27
	0x5b               goto 28
	0x5c               goto 3
	0x5d               goto 29
	0x5e               goto 30
	0x5f               goto 27
	0x60               goto 3
	0x61               goto 27
	0x62               goto 31
	0x63               goto 32
	0x64               goto 33
	0x65               goto 34
	0x66               goto 35
	0x67               goto 36
	0x68               goto 27
	0x69               goto 37
	0x6a - 0x6c (3)    goto 27
	0x6d               goto 38
	0x6e - 0x6f (2)    goto 27
	0x70               goto 39
	0x71               goto 27
	0x72               goto 40
	0x73               goto 41
	0x74               goto 27
	0x75               goto 42
	0x76               goto 43
	0x77               goto 44
	0x78 - 0x7a (3)    goto 27
	0x7b               goto 45
	0x7c               goto 46
	0x7d               goto 47
	0x7e               goto 48
	0x7f - 0xff (129)  goto 3


state 3
	match 72


state 4
	0x09               goto 4

	match 70


state 5
	match 69


state 6
	0x0b - 0x0c (2)    goto 6
	0x20               goto 6

	match 71


state 7
	0x3d               goto 49

	match 60


state 8
	0x3d               goto 50

	match 67


state 9
	0x26               goto 51
	0x3d               goto 52

	match 36


state 10
	0x00 - 0x09 (10)   goto 53
	0x0b - 0x5b (81)   goto 53
	0x5c               goto 54
	0x5d - 0xff (163)  goto 53

	match 72


state 11
	match 54


state 12
	match 55


state 13
	0x3d               goto 55

	match 65


state 14
	0x2b               goto 56
	0x3d               goto 57

	match 64


state 15
	match 51


state 16
	0x2d               goto 58
	0x3d               goto 59
	0x3e               goto 60

	match 63


state 17
	match 43


state 18
	0x2a               goto 61
	0x2f               goto 62
	0x3d               goto 63

	match 66


state 19
	0x30 - 0x37 (8)    goto 20
	0x58               goto 64
	0x78               goto 64

	match 2


state 20
	0x30 - 0x39 (10)   goto 20

	match 2


state 21
	match 53


state 22
	match 50


state 23
	0x3c               goto 65
	0x3d               goto 66

	match 44


state 24
	0x3d               goto 67

	match 23


state 25
	0x3d               goto 68
	0x3e               goto 69

	match 45


state 26
	match 52


state 27
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 68


state 28
	match 56


state 29
	match 57


state 30
	0x3d               goto 70

	match 35


state 31
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x71 (17)   goto 27
	0x72               goto 71
	0x73 - 0x7a (8)    goto 27

	match 68


state 32
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x67 (7)    goto 27
	0x68               goto 72
	0x69 - 0x6e (6)    goto 27
	0x6f               goto 73
	0x70 - 0x7a (11)   goto 27

	match 68


state 33
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6e (14)   goto 27
	0x6f               goto 74
	0x70 - 0x7a (11)   goto 27

	match 68


state 34
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6b (11)   goto 27
	0x6c               goto 75
	0x6d - 0x7a (14)   goto 27

	match 68


state 35
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6b (11)   goto 27
	0x6c               goto 76
	0x6d - 0x6e (2)    goto 27
	0x6f               goto 77
	0x70 - 0x7a (11)   goto 27

	match 68


state 36
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6e (14)   goto 27
	0x6f               goto 78
	0x70 - 0x7a (11)   goto 27

	match 68


state 37
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x65 (5)    goto 27
	0x66               goto 79
	0x67 - 0x6d (7)    goto 27
	0x6e               goto 80
	0x6f - 0x7a (12)   goto 27

	match 68


state 38
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61               goto 81
	0x62 - 0x7a (25)   goto 27

	match 68


state 39
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x71 (17)   goto 27
	0x72               goto 82
	0x73 - 0x7a (8)    goto 27

	match 68


state 40
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x64 (4)    goto 27
	0x65               goto 83
	0x66 - 0x7a (21)   goto 27

	match 68


state 41
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x73 (19)   goto 27
	0x74               goto 84
	0x75 - 0x7a (6)    goto 27

	match 68


state 42
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6d (13)   goto 27
	0x6e               goto 85
	0x6f - 0x7a (12)   goto 27

	match 68


state 43
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6e (14)   goto 27
	0x6f               goto 86
	0x70 - 0x7a (11)   goto 27

	match 68


state 44
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x67 (7)    goto 27
	0x68               goto 87
	0x69 - 0x7a (18)   goto 27

	match 68


state 45
	match 58


state 46
	0x3d               goto 88
	0x7c               goto 89

	match 37


state 47
	match 59


state 48
	match 34


state 49
	match 49


state 50
	match 28


state 51
	match 61


state 52
	match 31


state 53
	0x27               goto 90


state 54
	0x00 - 0x09 (10)   goto 53
	0x0b - 0x2f (37)   goto 53
	0x30 - 0x37 (8)    goto 91
	0x38 - 0x57 (32)   goto 53
	0x58               goto 92
	0x59 - 0x77 (31)   goto 53
	0x78               goto 92
	0x79 - 0xff (135)  goto 53


state 55
	match 26


state 56
	match 40


state 57
	match 24


state 58
	match 41


state 59
	match 25


state 60
	match 42


state 61
	0x00 - 0x29 (42)   goto 61
	0x2a               goto 93
	0x2b - 0x2e (4)    goto 61
	0x30 - 0xff (208)  goto 61


state 62
	0x00 - 0x09 (10)   goto 62
	0x0b - 0xff (245)  goto 62

	match 3


state 63
	match 27


state 64
	0x30 - 0x39 (10)   goto 94
	0x41 - 0x46 (6)    goto 94
	0x61 - 0x66 (6)    goto 94


state 65
	0x3d               goto 95

	match 39


state 66
	match 46


state 67
	match 48


state 68
	match 47


state 69
	0x3d               goto 96

	match 38


state 70
	match 32


state 71
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x64 (4)    goto 27
	0x65               goto 97
	0x66 - 0x7a (21)   goto 27

	match 68


state 72
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61               goto 98
	0x62 - 0x7a (25)   goto 27

	match 68


state 73
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6d (13)   goto 27
	0x6e               goto 99
	0x6f - 0x7a (12)   goto 27

	match 68


state 74
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 8


state 75
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x72 (18)   goto 27
	0x73               goto 100
	0x74 - 0x7a (7)    goto 27

	match 68


state 76
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6e (14)   goto 27
	0x6f               goto 101
	0x70 - 0x7a (11)   goto 27

	match 68


state 77
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x71 (17)   goto 27
	0x72               goto 102
	0x73 - 0x7a (8)    goto 27

	match 68


state 78
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x73 (19)   goto 27
	0x74               goto 103
	0x75 - 0x7a (6)    goto 27

	match 68


state 79
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 13


state 80
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6f (15)   goto 27
	0x70               goto 104
	0x71 - 0x73 (3)    goto 27
	0x74               goto 105
	0x75 - 0x7a (6)    goto 27

	match 68


state 81
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x68 (8)    goto 27
	0x69               goto 106
	0x6a - 0x7a (17)   goto 27

	match 68


state 82
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x68 (8)    goto 27
	0x69               goto 107
	0x6a - 0x7a (17)   goto 27

	match 68


state 83
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x73 (19)   goto 27
	0x74               goto 108
	0x75 - 0x7a (6)    goto 27

	match 68


state 84
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x71 (17)   goto 27
	0x72               goto 109
	0x73 - 0x7a (8)    goto 27

	match 68


state 85
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x68 (8)    goto 27
	0x69               goto 110
	0x6a - 0x7a (17)   goto 27

	match 68


state 86
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x68 (8)    goto 27
	0x69               goto 111
	0x6a - 0x7a (17)   goto 27

	match 68


state 87
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x68 (8)    goto 27
	0x69               goto 112
	0x6a - 0x7a (17)   goto 27

	match 68


state 88
	match 33


state 89
	match 62


state 90
	match 1


state 91
	0x27               goto 90
	0x30 - 0x37 (8)    goto 113


state 92
	0x27               goto 90
	0x30 - 0x39 (10)   goto 114
	0x41 - 0x46 (6)    goto 114
	0x61 - 0x66 (6)    goto 114


state 93
	0x00 - 0x2e (47)   goto 61
	0x2f               goto 115
	0x30 - 0xff (208)  goto 61


state 94
	0x30 - 0x39 (10)   goto 94
	0x41 - 0x46 (6)    goto 94
	0x61 - 0x66 (6)    goto 94

	match 2


state 95
	match 30


state 96
	match 29


state 97
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61               goto 116
	0x62 - 0x7a (25)   goto 27

	match 68


state 98
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x71 (17)   goto 27
	0x72               goto 117
	0x73 - 0x7a (8)    goto 27

	match 68


state 99
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x73 (19)   goto 27
	0x74               goto 118
	0x75 - 0x7a (6)    goto 27

	match 68


state 100
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x64 (4)    goto 27
	0x65               goto 119
	0x66 - 0x7a (21)   goto 27

	match 68


state 101
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61               goto 120
	0x62 - 0x7a (25)   goto 27

	match 68


state 102
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 11


state 103
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6e (14)   goto 27
	0x6f               goto 121
	0x70 - 0x7a (11)   goto 27

	match 68


state 104
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x74 (20)   goto 27
	0x75               goto 122
	0x76 - 0x7a (5)    goto 27

	match 68


state 105
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 14


state 106
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6d (13)   goto 27
	0x6e               goto 123
	0x6f - 0x7a (12)   goto 27

	match 68


state 107
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6d (13)   goto 27
	0x6e               goto 124
	0x6f - 0x7a (12)   goto 27

	match 68


state 108
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x74 (20)   goto 27
	0x75               goto 125
	0x76 - 0x7a (5)    goto 27

	match 68


state 109
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x74 (20)   goto 27
	0x75               goto 126
	0x76 - 0x7a (5)    goto 27

	match 68


state 110
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6e (14)   goto 27
	0x6f               goto 127
	0x70 - 0x7a (11)   goto 27

	match 68


state 111
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x63 (3)    goto 27
	0x64               goto 128
	0x65 - 0x7a (22)   goto 27

	match 68


state 112
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6b (11)   goto 27
	0x6c               goto 129
	0x6d - 0x7a (14)   goto 27

	match 68


state 113
	0x27               goto 90
	0x30 - 0x37 (8)    goto 53


state 114
	0x27               goto 90
	0x30 - 0x39 (10)   goto 53
	0x41 - 0x46 (6)    goto 53
	0x61 - 0x66 (6)    goto 53


state 115
	match 4


state 116
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6a (10)   goto 27
	0x6b               goto 130
	0x6c - 0x7a (15)   goto 27

	match 68


state 117
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 6


state 118
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x68 (8)    goto 27
	0x69               goto 131
	0x6a - 0x7a (17)   goto 27

	match 68


state 119
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 9


state 120
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x73 (19)   goto 27
	0x74               goto 132
	0x75 - 0x7a (6)    goto 27

	match 68


state 121
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 12


state 122
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x73 (19)   goto 27
	0x74               goto 133
	0x75 - 0x7a (6)    goto 27

	match 68


state 123
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 22


state 124
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x73 (19)   goto 27
	0x74               goto 134
	0x75 - 0x7a (6)    goto 27

	match 68


state 125
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x71 (17)   goto 27
	0x72               goto 135
	0x73 - 0x7a (8)    goto 27

	match 68


state 126
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x62 (2)    goto 27
	0x63               goto 136
	0x64 - 0x7a (23)   goto 27

	match 68


state 127
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6d (13)   goto 27
	0x6e               goto 137
	0x6f - 0x7a (12)   goto 27

	match 68


state 128
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 18


state 129
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x64 (4)    goto 27
	0x65               goto 138
	0x66 - 0x7a (21)   goto 27

	match 68


state 130
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 5


state 131
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6d (13)   goto 27
	0x6e               goto 139
	0x6f - 0x7a (12)   goto 27

	match 68


state 132
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 10


state 133
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 20


state 134
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 21


state 135
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x6d (13)   goto 27
	0x6e               goto 140
	0x6f - 0x7a (12)   goto 27

	match 68


state 136
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x73 (19)   goto 27
	0x74               goto 141
	0x75 - 0x7a (6)    goto 27

	match 68


state 137
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 17


state 138
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 19


state 139
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x74 (20)   goto 27
	0x75               goto 142
	0x76 - 0x7a (5)    goto 27

	match 68


state 140
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 15


state 141
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 16


state 142
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x64 (4)    goto 27
	0x65               goto 143
	0x66 - 0x7a (21)   goto 27

	match 68


state 143
	0x30 - 0x39 (10)   goto 27
	0x41 - 0x5a (26)   goto 27
	0x5f               goto 27
	0x61 - 0x7a (26)   goto 27

	match 7


#############################################################################
# Summary
#############################################################################

1 start state(s)
72 expression(s), 143 state(s)


#############################################################################
# End of File
#############################################################################
