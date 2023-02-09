all: exe
	./exe

exe: 
	g++ -std=c++2a *.cpp -o exe

clean: exe
	rm -rf exe