FILE STRUCTURE
    pa2
        2.1_max_heap
            include
                heap_impl.hpp
                heap.hpp
            src
                main.cpp
        2.2_sim
            include
                heap_impl.hpp
                heap.hpp
                job.hpp
            src
                job.cpp
                main.cpp

    - .tar files have been included to preserve original organization
            
COMPILATION INSTRUCTIONS
    
    - All 'main.cpp' source files assume include files will be found in the "../include" folder.
    
    - Compile 2.1_max_heap  ->  g++ -std=c++11 -o main main.cpp
    - Compile 2.2_sim       ->  g++ -std=c++11 -o main job.cpp main.cpp

EXECUTION INSTRUCTIONS

    - Execute   ->  ./main
    - Enter relative path and name of test dataset when prompted for file name.
