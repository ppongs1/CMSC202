CXX = g++
CXXFLAGS = -Wall

proj4: Grid.o Computer.o Player.o User.o main.cpp 
	$(CXX) $(CXXFLAGS) Grid.o Computer.o Player.o User.o main.cpp -o proj4

Grid.o: Grid.cpp Grid.h 
	$(CXX) $(CXXFLAGS) -c Grid.cpp

Player.o: Player.cpp Player.h Grid.h
	$(CXX) $(CXXFLAGS) -c Player.cpp

User.o: User.cpp User.h Player.o
	$(CXX) $(CXXFLAGS) -c User.cpp

Computer.o: Computer.cpp Computer.h Player.o
	$(CXX) $(CXXFLAGS) -c Computer.cpp

clean:

	rm *.o*
	rm *~

run:

	./proj4

run1:
	./proj4 p4_comp1.txt p4_user1.txt


run2:
	./proj4 p4_comp2.txt p4_user2.txt


run3:

	./proj4 p4_comp3.txt p4_user3.txt
