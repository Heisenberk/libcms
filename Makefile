# Makefile de la librairie libcms

cmsint: bin
	gcc -c -I include/ -fPIC -o bin/uint8_fct.o src/int/uint8_fct.c
	gcc -c -I include/ -fPIC -o bin/uint32_fct.o src/int/uint32_fct.c
	gcc -c -I include/ -fPIC -o bin/uint64_fct.o src/int/uint64_fct.c
	gcc -fPIC -shared -Wl,-soname,libcmsint.so.1 -o lib/libcmsint.so.1.0 bin/uint8_fct.o bin/uint32_fct.o bin/uint64_fct.o
	cd lib/ && ln -sf libcmsint.so.1.0 libcmsint.so
	cd lib/ && /sbin/ldconfig -n .

test-cmsint: cmsint
	gcc -I ./include/ -L ./lib/ -o ./bin/cmsint ./test/cmsint.c -lcmsint
	./bin/cmsint
	
bin : 
	mkdir -p bin/ 

doxygen : 
	doxygen doc/Doxyfile
	firefox doc/html/files.html

clean : 
	rm -rf build/
	rm -f lib/libcmsint*

