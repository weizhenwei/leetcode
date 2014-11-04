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
	   2012-01-17_3Sum.cpp \
	   2012-01-17_Longest_Common_Prefix.cpp \
	   2012-01-18_3Sum_Closest.cpp \
	   2012-01-26_4Sum.cpp \
       2012-01-27_Remove_Nth_Node_From_End_of_List.cpp \
       2012-01-30_Valid_Parentheses.cpp \
       2012-02-13_Merge_k_Sorted_Lists.cpp \
       2012-02-14_Swap_Nodes_in_Pairs.cpp \
       2012-02-15_Reverse_Nodes_in_k-Group.cpp \
       2012-02-16_Remove_Duplicates_from_Sorted_Array.cpp \
       2012-02-16_Remove_Element.cpp \
       2012-02-18_Divide_Two_Integers.cpp \
       2012-02-18_Implement_strStr.cpp \
       2012-02-23_Substring_with_Concatenation_of_All_Words.cpp \
	   2012-03-02_Search_for_a_Range.cpp \
	   2012-03-03_Search_Insert_Position.cpp \
	   2012-03-08_First_Missing_Positive.cpp \
	   2012-03-12_Multiply_Strings.cpp \
       2012-03-02_Search_in_Rotated_Sorted_Array.cpp \
	   2012-03-05_Count_and_Say.cpp \
       2012-03-27_Length_of_Last_Word.cpp \
       2012-03-27_Rotate_list.cpp \
       2012-03-30_Merge_Two_Sorted_Lists.cpp \
	   2012-04-02_Add_Binary.cpp \
	   2012-04-02_Valid_Number.cpp \
       2012-04-02_Plus_One.cpp \
	   2012-04-03_Climbing_Stairs.cpp \
	   2012-04-19_Remove_Duplicates_from_Sorted_Array_II.cpp \
       2012-04-19_Search_in_Rotated_Sorted_Array_II.cpp \
       2012-04-22_Remove_Duplicates_from_Sorted_List.cpp \
       2012-04-22_Remove_Duplicates_from_Sorted_List_II.cpp \
       2012-06-27_Reverse_Linked_List_II.cpp \
       2013-10-28_Linked_List_Cycle.cpp \
       2013-10-30_Linked_List_Cycle_II.cpp

OBJECTS = $(SRCS:%.cpp=%.o)
TARGETS = $(SRCS:%.cpp=%)  
all : $(TARGETS)
	for target in $(TARGETS); do \
		$(CXX) $(CXXFLAGS) -o $$target $$target.cpp; \
		done  

clean:
	-rm -f $(TARGETS) $(OBJECTS)  

.PHONY: all clean
