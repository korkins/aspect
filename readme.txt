2020-05-03: aspect.exe

MAKE

-[optional] (in const_param.h) check/update paths:
    line 33: char const path_hitdb[path_len_max] = "./hitran/";
    line 51: char const path_TIPS[path_len_max] = "./hitran/TIPS/";
-run 'make' to install in the unzipped directory
-[optional] run 'make clean' to remove object files from 'src_c'
 ('obj' folder is not used with this option)

OR BUILD (if 'make' does not work)

-run .\build.lin  (make shure it is executable)
-run .\aspect.exe (make shure it is executable)

AND TEST

-check O2.txt vs test-O2.txt: diff O2.txt test-O2.txt
