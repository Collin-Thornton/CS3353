FILE STRUCTURE
    pa3
        3.1_chained_hash_table
            include
                chained_hash_table.hpp
                DoublyLinked.hpp
                DoublyLinked_impl.hpp
            src
                chained_hash_table.cpp
                main1.cpp
        3.2_linear_hash_table
            include
                linear_hash_table.hpp
            src
                linear_hash_table.cpp
                main2.cpp
        3.3_double_hash_table
            include
                double_hash_table.hpp
            src
                double_hash_table.cpp
                main3.cpp

    - .tar files have been included to preserve original organization
            
COMPILATION INSTRUCTIONS
    
    - All 'main.cpp' source files assume include files will be found in the "../include" folder.
    
    - Compile 3.1_chained_hash_table ->  g++ -std=c++11 -o main chained_hash_table.cpp main1.cpp
    - Compile 3.2_linear_hash_table  ->  g++ -std=c++11 -o main linear_hash_table.cpp main2.cpp
    - Compile 3.3_double_hash_table  ->  g++ -std=c++11 -o main double_hash_table.cpp main3.cpp

EXECUTION INSTRUCTIONS

    - Execute   ->  ./main
    - Enter relative path and name of test dataset when prompted for file name.
