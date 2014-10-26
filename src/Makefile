CXX = g++
# CXXFLAGS = -g -I. -Wall
CXXFLAGS = -g -I.

SRCS = 2011-03-13_Two_Sum.cpp \
       2011-05-15_Longest_Substring_Without_Repeating_Characters.cpp \
       2011-11-01_Add_Two_Numbers.cpp \
       2011-11-11_Longest_Palindromic_Substring.cpp \
       2011-12-05_ZigZag_Conversion.cpp \
       2011-12-25_Reverse_Integer.cpp \
       2011-12-26_String_to_Integer.cpp \
       2012-01-04_Palindrome_Number.cpp \
       2012-01-08_Regular_Expression_Matching.cpp \
       2012-01-08_Container_With_Most_Water.cpp \
       2012-01-27_Remove_Nth_Node_From_End_of_List.cpp \
       2012-01-30_Valid_Parentheses.cpp \
       2012-02-12_Generate_Parentheses.cpp \
       2012-02-14_Swap_Nodes_in_Pairs.cpp \
       2012-02-16_Remove_Duplicates_from_Sorted_Array.cpp \
       2012-02-16_Remove_Element.cpp \
       2012-02-18_Implement_strStr.cpp \
       2012-02-23_Substring_with_Concatenation_of_All_Words.cpp

OBJECTS = $(SRCS:%.cpp=%.o)
TARGETS = $(SRCS:%.cpp=%)  
all : $(TARGETS)
	for target in $(TARGETS); do \
		$(CXX) $(CXXFLAGS) -o $$target $$target.cpp; \
		done  

clean:
	-rm -f $(TARGETS) $(OBJECTS)  

.PHONY: all clean
