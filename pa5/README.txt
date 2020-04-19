FILE STRUCTURE
    pa5
        5.1_merge_sort
            include
                constants.hpp
		key_value.hpp
		merge_sort.hpp
		stack.hpp
            src
                test_merge_sort.cpp
	5.2_bucket_sort
	    include
		bucket_sort.hpp
		constants.hpp
		key_value.hpp
		stack.hpp
	    src
		test_bucket_sort.cpp
	5.3_plots
	    include
		bucket_sort.hpp
		merge_sort.hpp
		constants.hpp
		key_value.hpp
		stack.hpp
	    src
		plot.hpp

    - .tar files have been included to preserve original organization
            
COMPILATION INSTRUCTIONS
    
    - All 'test*.cpp' source files assume include files will be found in the "../include" folder.
    
    - Compile 5.1_merge_sort  ->  g++ -std=c++11 -o main test_merge_sort.cpp


EXECUTION INSTRUCTIONS

    - Execute   ->  ./main
    - Enter relative path and name of test dataset when prompted for file name.
