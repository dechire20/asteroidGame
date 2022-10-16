output: a
	g++ *.o -o mors -lsfml-graphics -lsfml-window -lsfml-system;
	rm -rf *.o

a: src/**/*.cpp
	g++ -c src/**/*.cpp src/*.cpp

clean:
	rm -rf *.o
