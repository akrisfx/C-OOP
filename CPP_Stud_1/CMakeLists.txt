# CMakeList.txt: проект CMake для CPP_Stud_1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.


set (BOOST_ROOT "C:/boost_1_81_0/") # Путь к библиотеке Boost
 
set (CMAKE_CXX_STANDARD 20) 
set (Boost_NO_SYSTEM_PATHS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_STATIC_RUNTIME OFF)
set (BOOST_ALL_DYN_LINK OFF)
  
# Подключаем необходимые модули. Для примера подключим program_options
find_package (Boost REQUIRED) 

add_executable (CPP_Stud_1 "CPP_Stud_1.cpp" "CPP_Stud_1.h" "LC.h") # Создаем исполняемый файл для нашего проекта
# Если библиотека найдена, то
if (Boost_FOUND)
    include_directories (SYSTEM ${Boost_INCLUDE_DIR}) # подключаем заголовочные файлы
    
    target_link_libraries (CPP_Stud_1 ${Boost_LIBRARIES}) # подключаем библиотеку
endif ()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CPP_Stud_1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
