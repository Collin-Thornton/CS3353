FILE STRUCTURE
    pa6
        6.1_bfs
            include
				circular_queue.hpp
                constants.hpp
            src
                bfs.cpp
		6.2_dfs
	    	include
				circular_queue.hpp
				constants.hpp
				stack.hpp
	    	src
				dfs.cpp

    - .tar files have been included to preserve original organization
            
COMPILATION INSTRUCTIONS
    
    - All '*.cpp' source files assume include files will be found in the "../include" folder.
    
    - Compile 6.1_bfs.cpp  ->  g++ -std=c++11 -o main bfs.cpp
	- Complie 6.2_dfs.cpp  ->  g++ -std=c++11 -o main dfs.cpp


EXECUTION INSTRUCTIONS

    - Execute   ->  ./main
    - Enter relative path and name of test dataset when prompted for file name.

NOTES
	- Parts 3 & 4 of PA6 have been included in dfs.cpp
		- Instructions mentioned to use output of DFS as input for topological sort and SCC