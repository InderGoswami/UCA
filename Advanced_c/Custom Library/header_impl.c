int add(int a,int b){
    return a+b;
}
//compile this implementation file and store the precompiled code of this file into another file
//gcc -c header_impl -o addition_output 
//addition_output is file to store compiled code of this file
//create library using rcs
/*
ar rcs lib_mylib.a addition_output
this step will group multiple object fils in one static library .
output will be a static library.
ar is archiver , a unix utility maintains group of files as single archive
file


rcs
r->if library already exists ,replace old files with new files
c-> means create library if not exist
s->means sort library , so that it will be indexed and access functions more fastly

*/