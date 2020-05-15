2020-05-15: aspect.exe

MAKE

-[optional] (in const_param.h) check/update paths:
    line 33: char const path_hitdb[path_len_max] = "./hitran/";
    line 51: char const path_TIPS[path_len_max] = "./hitran/TIPS/";
-run 'make' to install in the current directory
-[optional] run 'make clean' to remove object files from 'src_c'
 ('obj' folder is not used with this option)


OR BUILD (if 'make' does not work)

-run ./build.lin  (make shure it is executable)
-run ./aspect.exe (make shure it is executable)


AND TEST

-run diff O2.txt test-O2.txt


HOW TO TRY DIFFERENT HITRAN

-rename ./hitran/07_hitran.db -> 07_hitran_2016.db
-rename ./hitran/07_hitran_2012.db -> 07_hitran.db
-run ./aspect.exe