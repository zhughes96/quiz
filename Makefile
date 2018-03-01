DEP = college.h node.h course.h tarray.h
OBJ = college.cc collegemain.cc course.cc

all:build doczip doc

build:myexe

myexe: college.o collegemain.o course.o
	g++ -o $@ $^

college.o: college.cc $(DEP)
	g++ -c college.cc

collegemain.o: collegemain.cc $(DEP)
	g++ -c collegemain.cc

course.o: course.cc $(DEP)
	g++ -c course.cc

clean:
	rm -f -r *.o core *.core myexe college.tar.gz configfile latex html

doczip: $(DEP) $(OBJ) makefile
	tar -cf college.tar.gz $^

doc:
	doxygen -g configfile
	doxygen configfile
