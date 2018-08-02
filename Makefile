#explain
objects=main.o Spin.o Update.o RNG.o
main:$(objects)
	g++ $(objects) -o main
Spin.o:Spin.cpp
	g++ -c Spin.cpp -o Spin.o
Update.o:Update.cpp
	g++ -c Update.cpp -o Update.o
RNG.o:RNG.cpp
	g++ -c RNG.cpp -o RNG.o
.PHONY:clean
clean:
	-rm main $(objects)

