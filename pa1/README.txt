FILE STRUCTURE
    pa1
        1.1_doubly_linked
            include
                DoublyLinked_impl.hpp
                DoublyLinked.hpp
            src
                main.cpp
        1.2_stack
            include
                stack_impl.hpp
                stack.hpp
            src
                main.cpp
        1.3_circular_queue
            include
                circular_queue_impl.hpp
                circular_queue.hpp
            src
                main.cpp
        1.4_parenthesis_check_stack
            include
                stack_impl.hpp  (copy from 1.2)
                stack.hpp       (copy from 1.2)
            src
                main.cpp

            
COMPILATION INSTRUCTIONS
    
    - All 'main.cpp' source files assume include files will be found in the "../include" folder.
    
    - Compile   ->  g++ -std=c++11 -o main main.cpp

EXECUTION INSTRUCTIONS

    - Execute   ->  ./main
    - Enter relative path and name of test dataset when prompted for file name.