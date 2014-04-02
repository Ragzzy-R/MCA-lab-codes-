CPP      = g++
verbose  = -v
debug    = -g
warnings = -Wall
output   = -o
P_3      = 3_swap.cpp
O_3      = 3_swap

P_5      = 5_F_overload.cpp
O_5      = 5_F_overload

P_6      = 6_add_overload.cpp
O_6      = 6_add_overload

P_8      = 8_overloadcomplex.cpp
O_8      = 8_overloadcomplex

P_17     = 17_find_in_array.cpp
O_17     = 17_find_in_array

P_18     = 18_array_add.cpp
O_18     = 18_array_add

P_21     = 21_single_public.cpp
O_21     = 21_single_public

P_22     = 22_single_private.cpp
O_22     = 22_single_private

binPath  = Linux_x64_bin/
target:
	clear
	$(CPP)  $(debug) $(warnings) $(P_3) $(output) $(binPath)$(O_3)
	$(CPP)  $(debug) $(warnings) $(P_5) $(output) $(binPath)$(O_5)
	$(CPP)  $(debug) $(warnings) $(P_6) $(output) $(binPath)$(O_6)
	$(CPP)  $(debug) $(warnings) $(P_8) $(output) $(binPath)$(O_8)
	$(CPP)  $(debug) $(warnings) $(P_17) $(output) $(binPath)$(O_17)
	$(CPP)  $(debug) $(warnings) $(P_18) $(output) $(binPath)$(O_18)
	$(CPP)  $(debug) $(warnings) $(P_21) $(output) $(binPath)$(O_21)
	$(CPP)  $(debug) $(warnings) $(P_22) $(output) $(binPath)$(O_22)

	echo "All done :)"
